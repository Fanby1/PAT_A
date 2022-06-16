//非AC代码，因为是模拟题所以不想做了，已经知道问题出现在哪里了，主要是当多个桌子同时空余时的处理，非vip与vip可能做错桌子。

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Time{
    private:
    int hour,min,sec;
    public:
    Time(){};
    Time(int h, int m, int s):hour(h),min(m),sec(s){};
    Time(string t){
        int vessel[3];
        int index = 0;
        int temp = 0;
        for(auto a : t){
            if(a != ':'){
                temp *= 10;
                temp += a - '0';
            }else{
                vessel[index] = temp;
                temp = 0;
                index++;
            }
        }
        hour = vessel[0];
        min = vessel[1];
        sec = temp;
    }

    
    bool operator<(Time time){
        if(hour < time.hour){
            return true;
        }else if(hour == time.hour){
            if(min < time.min){
                return true;
            }else if (min == time.min){
                if(sec < time.sec){
                    return true;
                }
            }
        }
        return false;
    }

    bool operator>(Time time){
        if(hour > time.hour){
            return true;
        }else if(hour == time.hour){
            if(min > time.min){
                return true;
            }else if (min == time.min){
                if(sec > time.sec){
                    return true;
                }
            }
        }
        return false;
    }

    Time operator+(int len){
        return Time(hour + (min + len) / 60, ( min + len ) % 60,sec);
    }

    Time operator-(int len){
        return Time(hour + (min - len) / 60, (min - len) % 60 > 0 ? min - len : - (min - len) % 60,sec);
    }

    int operator-(Time time){
        return (((hour - time.hour) * 60 + min - time.min) * 60 + sec - time.sec + 30) / 60;
    }

    string to_string(){
        string h = std::to_string(hour);
        if(h.size() != 2){
            h = '0' + h;
        }
        string m = std::to_string(min);
        if(m.size() != 2){
            m = '0' + m;
        }
        string s = std::to_string(sec);
        if(s.size() != 2){
            s = '0' + s;
        }
        return h + ':' + m + ':' + s;
    }
};

istream& operator>>(istream &is, Time& a){
    string input;
    cin >> input;
    a = Time(input);
    return is;
}

ostream& operator<<(ostream &os, Time& a){
    cout << a.to_string();
    return os;
}

struct cilent
{
    Time time,begin;
    int len,wait;
    bool isVIP;

    bool operator<(cilent another){
        if(time < another.time){
            return true;
        }
        return false;
    }
};

void pop(queue<cilent*> &wait, int last, Time time, int *count, Time *end){
    if(wait.front()->len <= 120){
        end[last] = wait.front()->time + wait.front()->len;
    }else{
        end[last] = wait.front()->time + 120;
    }
    count[last]++;
    wait.front()->begin = time;
    wait.pop();
}

bool cmp(cilent a,cilent b){
    if(a.begin < b.begin){
        return true;
    }
    return false;
}

int main(){
    int num;
    cin >> num;
    vector<cilent> all;
    for(int i = 0;i < num;++i){
        cilent n;
        cin >> n.time >> n.len >> n.isVIP;
        all.push_back(n);
    }
    sort(all.begin(),all.end());
    int tables,v_tabels;
    cin >> tables >> v_tabels;
    set<int> v_number;
    for(int i = 0;i < v_tabels;++i){
        int input;
        cin >> input;
        v_number.insert(input);
    }
    queue<cilent*> wait;
    queue<cilent*> v_wait;
    int count[tables] = {0};
    Time end[tables];
    int last = -1;
    Time time = Time("21:00:00");
    if(num > tables){
        int index = 0;
        for(;index != tables;++index){
            Time c = all[index].time + all[index].len;
            if(time > c){
                time = c;
                last = index;
            }
            all[index].begin = all[index].time;
            count[index]++;
            end[index] = c;
        }
        for(;index < num;++index){
            bool flag = true;
            while(all[index].time > time){
                flag = false;
                if(v_number.find(last + 1) != v_number.end()){
                    if(v_wait.empty()){
                        if(wait.empty()){
                            time = all[index].time;
                            for(int i = 0;i < tables;++i){
                                if(end[i] < time){
                                    last = i;
                                    break;
                                }
                            }
                            count[last]++;
                            end[last] = all[index].time + all[index].len;
                            
                            all[index].begin = time;
                            break;
                        }else{
                            pop(wait,last,time,count,end);
                        }
                    }else{
                        pop(v_wait,last,time,count,end);
                    }
                }else if(v_wait.empty()){
                    if(wait.empty()){
                        time = all[index].time;
                        for(int i = 0;i < tables;++i){
                                if(end[i] < time){
                                    last = i;
                                    break;
                                }
                            }
                        count[last]++;
                        if(all[index].len <= 120){
                            end[last] = all[index].time + all[index].len;
                        }else{
                            end[last] = all[index].time + 120;
                        }
                        
                        all[index].begin = time;
                        break;
                    }else{
                        pop(wait,last,time,count,end);
                    }
                }else{
                    if(wait.empty()){
                        pop(v_wait,last,time,count,end);
                    }else{
                        cilent c1 = *wait.front(),c2 = *v_wait.front();
                        if(c1 < c2){
                            pop(wait,last,time,count,end);
                        }else{
                            pop(v_wait,last,time,count,end);
                        }
                    }
                }
                Time max = Time("21:00:00");
                int m;
                for(int a = 0;a < tables;++a){
                    if(max > end[a]){
                        max = end[a];
                        m = a;
                    }
                }
                time = max;
                last = m;
            }
            if(flag){
                if(all[index].isVIP){
                    v_wait.push(&all[index]);
                }else{
                    wait.push(&all[index]);
                }
            }else{
                Time max = Time("21:00:00");
                int m;
                for(int a = 0;a < tables;++a){
                    if(max > end[a]){
                        max = end[a];
                        m = a;
                    }
                }
                time = max;
                last = m;
            }
            if(time > Time("21:00:00")){
                break;
            }
        }
    }else{
        int index = 0;
        for(;index != num;++index){
            count[index]++;
            all[index].begin = all[index].time;
        }
    }

    sort(all.begin(),all.end(),cmp);

    for(auto a : all){
        if(a.begin < Time("21:00:00")){
            cout << a.time << " " << a.begin << " " << a.begin - a.time << endl;
        }else{
            break;
        }
    }

    for(int i = 0;i < tables;i++){
        if(i){
            cout << " " << count[i];
        }else{
            cout << count[i];
        }
    }
}