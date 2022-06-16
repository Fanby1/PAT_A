#include "iostream"

using namespace std;

inline string change(char a);

int main(){
    char input;
    int count = 0;
    cin.unsetf(ios::skipws);
    while (true)
    {
        cin >> input;
        if(input != '\n'){
            count += input - 48;
        }
        else{
            break;
        }
    }
    
    string result = to_string(count);
    string::iterator a = result.begin();

    for(;a < result.end();++a){
        if(a != result.end() - 1){
            cout << change(*a) << " ";
        }
        else{
            cout << change(*a) << endl;
        }
    }
}

inline string change(char a){
    switch (a)
    {
    case '0':
        return "zero";
    case '1':
        return "one";
    case '2':
        return "two";
    case '3':
        return "three";
    case '4':
        return "four";
    case '5':
        return "five";
    case '6':
        return "six";
    case '7':
        return "seven";
    case '8':
        return "eight";
    default:
        return "nine";
    }
}