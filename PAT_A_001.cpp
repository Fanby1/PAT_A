#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main(){
    int input_1, input_2;
    cin >> input_1;
    cin >> input_2;
    int result = input_1 + input_2;
    string temp = to_string(result);
    vector<char> output;
    string::iterator b = temp.begin(), e = temp.end() - 1;
    if(*b == '-'){
        b++;
    }
    for(auto i = e;i >= b;--i){
        output.insert(output.end(),*i);
        if((e - i) % 3 == 2 && i != b){
            output.insert(output.end(),',');
        }
    }
    if(b != temp.begin()){
        output.insert(output.end(),'-');
    }
    vector<char>::iterator a = output.end() - 1;
    for(auto i = a;i >= output.begin();--i){
        cout << *i;
    }
    cout << endl;
}