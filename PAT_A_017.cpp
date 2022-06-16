#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int getTime(string t){
    int count = 0;
    int temp = 0;
    for(auto a : t){
        if(a == ':'){
            count *= 60;
            count += temp; 
            temp = 0;
            continue;
        }
        temp *= 10;
        temp += a - '0';
    }

    return count * 60 + temp;
}

int getMin(int* windows,int k){
    int min = 17 * 60 * 60 + 1;
    int index;
    for(int i = 0;i < k;i++){
        if(min > windows[i]){
            min = windows[i];
            index = i;
        }
    }
    return index;
}

int main(){
    map<int,int> line;
    int n,k;
    cin >> n >> k;
    int windows[10010];
    for(int i = 0;i < k;i++){
        windows[i] = 8 * 60 * 60;
    }

    int count = 0,all_time = 0;
    for(int i = 0;i < n;i++){
        string input;
        cin >> input;
        int time = getTime(input);
        int c_time;
        cin >> c_time;
        c_time *= 60;
        if(time < 17 * 60 * 60){
            line.insert(pair<int,int>(time,c_time));
        }
    }

    for(auto a : line){
        int index = getMin(windows,k);
        if(a.first > 8 * 60 * 60){
            if(a.first >= windows[index]){
                windows[index] = a.first + a.second;
                count++;
            }
            else{
                all_time += windows[index] - a.first;
                windows[index] = windows[index] + a.second;
                count++;
            }
        }
        else{
            all_time += 8 * 60 * 60 - a.first;
            windows[index] += a.second;
            count++;
        }
    }

    if(all_time == 0){
        printf("0.0");
    }
    else{
        printf("%.1f",all_time * 1.0f / count / 60);
    }

}