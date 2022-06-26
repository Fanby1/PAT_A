#include <iostream>
#include <list>

using namespace std;

bool pool[256] = {false};

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(auto n : b){
        pool[int(n)] = true;
    }
    list<char> input = list(a.begin(),a.end());
    auto index = input.begin();
    for(;index != input.end();){
        if(pool[int(*index)]){
            auto next = index++;
            input.erase(next);
        }else{
            index++;
        }
    }
    string output = string(input.begin(),input.end());
    cout << output << endl;
}