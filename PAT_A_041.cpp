#include <iostream>
#include <set>
#include <vector>

using namespace std;
int pool[10000];
bool need_loop = true;
vector<int> values;
int times = 0;

int check(vector<int> values, int *pool, bool need_loop){
    times++;
    need_loop = false;
    vector<int> results;
    for(auto value : values){
        if(pool[value] < times){
            pool[value] ++;
            results.push_back(value);
        }else{
            pool[value] ++;
            need_loop = true;
        }
    }
    if(need_loop){
        return check(results,pool,need_loop);
    }else{
        return results.size() == 0 ? -1 : results[0];
    }
}
int main(){
    int num = 0;
    cin >> num;
    for(int i = 0;i < num;++i){
        int value;
        cin >> value;
        values.push_back(value);  
    }
    int out = check(values,pool,need_loop);
    if(out == -1){
        cout << "None" << endl;
    }else{
        cout << out << endl;
    }
}