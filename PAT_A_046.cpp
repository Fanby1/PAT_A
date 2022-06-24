#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int num,sum = 0;
    cin >> num;
    vector<int> cities;
    cities.resize(num);
    for(int i = 0; i < num; ++i){
        int in;
        cin >> in;
        cities[i] = sum;
        sum += in;
    }

    int questions;
    cin >> questions;
    for(int i = 0;i < questions;++i){
        int begin,end;
        cin >> begin >> end;
        if(begin > end){
            begin = end + begin;
            end = begin - end;
            begin -= end;
        }
        begin--;
        end --;
        int len = 0;
        len = cities[end] - cities[begin];
        if(len > sum - len){
            len = sum - len;
        }
        cout << len << endl;
    }
}