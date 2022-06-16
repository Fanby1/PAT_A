#include <iostream>

using namespace std;

string add(string value){
    string result;
    int before = 0;
    for(int i = value.length() - 1;i != -1;--i){
        int temp = before + value[i] - '0' + value[value.length() - i - 1] - '0';
        result = to_string(temp % 10) + result;
        before = temp / 10;
    }
    if(before != 0){
        return to_string(before) + result;
    }else{
        return result;
    }
}

bool isPalindromic(string value){
    bool flag = true;
    for(int i = 0;i < value.length();i++){
        if(value[i] != value[value.length() - i - 1]){
            flag = false;
            return flag;
        }
    }
    return flag;
}

int main(){
    string value;
    int steps,currunt = 0;
    cin >> value >> steps;
    for(int i = 0;i < steps;++i){
        if(!isPalindromic(value)){
            value = add(value);
        }else{
            cout << value << endl << i << endl;
            return 0;
        }
    }
    cout << value << endl << steps << endl;
}