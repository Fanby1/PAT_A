#include <iostream>

using namespace std;

int getTime(string time);
int main(){
    int n;
    cin >> n;
    string first, last;
    int t_first = 24 * 60 * 60 + 1, t_last = -1;
    for(int i = 0;i < n;i++){
        string temp, name;
        cin >> name;
        cin >> temp;
        int in_time,out_time;
        in_time = getTime(temp);
        cin >> temp;
        out_time = getTime(temp);

        if(in_time < t_first){
            first = name;
            t_first = in_time;
        }
        if(out_time > t_last){
            last = name;
            t_last = out_time;
        }
    }

    cout << first << " " << last << endl;
}

int getTime(string time){
    int times = 0;
    int result[3] = {0};
    for(auto a : time){
        if(a != ':'){
            result[times] *= 10;
            result[times] += a - 48;
        }else{
            times ++;
        }
    }

    return (result[0] * 60 + result[1]) * 60 + result[2];
}