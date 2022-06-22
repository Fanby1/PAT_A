#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int target_l,input_l;
    int o;
    cin >> o;
    cin >> target_l;
    map<int,int> pool;
    for(int i = 0;i < target_l;++i){
        int in;
        cin >> in;
        pool.insert({in,pool.size()});
    }
    cin >> input_l;
    vector<int> input;

    for(int i = 0;i < input_l;++i){
        int in;
        cin >> in;
        auto a = pool.find(in);
        if(a != pool.end()){
            input.push_back(a->second);
        }
    }
    int result[input.size()];
    fill(result,result + input_l, 1);

    for(int i = 0;i < input.size();++i){
        for(int j = 0; j < i; ++j){
            if(input[j] <= input[i]){
                result[i] = result[j] + 1 > result[i] ? result[j] + 1 : result[i];
            }
        }
    }

    int max = 0;
    for(auto a : result){
        if(a > max){
            max = a;
        }
    }
    cout << max;
}