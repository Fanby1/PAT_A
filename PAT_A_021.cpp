#include <iostream>
#include <algorithm>
#include <set>

#define INFINITY -10

using namespace std;

int main(){
    int length;
    cin >> length;

    int map[length][length];
    for(int i = 0;i < length;i++){
        for(int j = 0;j < length;++j){
            map[i][j] = INFINITY;
        }
    }

    for(int i = 0;i < length - 1;++i){
        int begin,end;
        cin >> begin >> end;
        begin--;
        end--;
        map[begin][end] = 1;
        map[end][begin] = 1;
    }

    set<int> result;

    int max_level = -1;

    for(int i = 0;i < length;i++){
        int levels[length];
        int pre[length];
        for(int j = 0;j < length;++j){
            pre[j] = -1;
        }
        set<int> vessel;
        vessel.insert(i);
        int c_level = 0;
        int count  = 1;
        for(int j = 0;j < length;++j){
            levels[j] = map[i][j];
            if(levels[j] != INFINITY){
                pre[j] = i;
                vessel.insert(j);
                count++;
            }
        }
        bool flag = true;
        while (flag)
        {
            c_level++;
            for(int j = 0;j < length;j++){
                if(levels[j] == c_level){
                    for(int k = 0;k < length;k++){
                        if(map[j][k] != INFINITY){
                            if(pre[j] != k && vessel.find(k) != vessel.end()){
                                cout << "Error: " << c_level + levels[k] - 1 << " components" << endl;
                                return 0;
                            }
                            if(k != i && vessel.find(k) == vessel.end()){
                                levels[k] = c_level + 1;
                                pre[k] = j;
                                vessel.insert(k);
                                count++;
                                if(count == length){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
            }
        } 
        c_level++; 
        if(c_level > max_level){
            result.clear();
            result.insert(i + 1);
            for(int j = 0;j < length;j++){
                if(levels[j] == c_level){
                    result.insert(j + 1);
                }
            } 
            max_level = c_level;
        }else if(c_level == max_level){
            for(int j = 0;j < length;j++){
                if(levels[j] == c_level){
                    result.insert(j + 1);
                }
            }
        }
    }

    for(auto a : result){
        cout << a << endl;
    }
}