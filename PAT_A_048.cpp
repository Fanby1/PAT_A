#include <iostream>
#include <vector>

using namespace std;

int pool[510] = {0};

int main(){
    int num,target;
    cin >> num >> target;
    for(int i = 0;i < num; ++i){
        int input = 0;
        cin >> input;
        pool[input] += 1;
    }
    for(int i = 0;i < target / 2 + 2;++i){
        if(target - i < 510 && ( pool[i] && pool[target - i] && i * 2 != target || (i * 2 == target && pool[i] >= 2))){
            cout << i << " " << target - i << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
}