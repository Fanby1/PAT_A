#include <iostream>
#include <vector>

using namespace std;

char get13(int value){
    if(value < 10){
        return value + '0';
    }else{
        return value + 'A' - 10;
    }
}

string transform(int value){
    vector<char> vessel;
    while(value != 0){
        vessel.push_back( get13(value % 13));
        value /= 13;
    }
    string result;
    for(auto a : vessel){
        result = a + result;
    }
    return result.size() == 2 ? result : result.size() == 1 ? "0" + result : "00";
}

int main(){
    int value[3];
    string result = "#";
    for(auto a : value){
        cin >> a;
        result += transform(a);
    }
    cout << result << endl;
}