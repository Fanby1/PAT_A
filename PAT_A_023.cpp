#include <iostream>

using namespace std;

int main(){
    string value,result;
    int v_count[10] = {0},r_count[10] = {0};
    cin >> value;
    int len = value.length();
    int before = 0;
    for(auto a : value){
        v_count[a - '0']++;
    }
    for(int i = len - 1;i != -1;--i ){
        int temp = before + (value[i] - '0') * 2;
        result = to_string(temp % 10) + result;
        before = temp / 10;
    }
    if(before){
        cout << "No" << endl;
        result = to_string(before) + result;
    }
    else{
        for(auto a : result){
            r_count[a - '0']++;
        }
        bool flag = true;
        for(int i = 0;i < 10;++i){
            if(v_count[i] != r_count[i]){
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    cout << result << endl;

}