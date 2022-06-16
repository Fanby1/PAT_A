#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num,base;
    cin >> num >> base;
    vector<int> vessel;
    while (true)
    {
        int digit = num % base;
        vessel.push_back(digit);
        num /= base;
        if (num == 0){
            break;
        }
    }

    bool flag = true;
    for(int i = 0;i < vessel.size(); ++i){
        if(vessel[i] != vessel[vessel.size() - i - 1]){
            flag = false;
        }
    }

    if(!flag){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    flag = false;
    for(auto a = vessel.end() - 1;a >= vessel.begin();--a){
        if(!flag){
            cout << *a ;
            flag = true;
        }else{
            cout << " " << *a;
        }
    }
    
}