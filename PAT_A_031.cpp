#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string value;
    cin >> value;
    int len = value.size();
    int n_2 = (len + 2) % 3 == 0 ? ( len + 2 ) / 3 : (len + 2) % 3 == 1 ? ( len + 2 ) / 3 + 1 : (len + 2) / 3 + 2;
    int n_1 = ( len - n_2 ) / 2;
    for(int i = 0;i < n_1;++i){
        string result = string(n_2,' ');
        result[0] = value[i];
        result[n_2 - 1] = value[len - i - 1];
        cout << result << endl;
    }
    string result = string(n_2,' ');
    copy(value.begin() + n_1,value.end() - n_1,result.begin());
    cout << result << endl;
}