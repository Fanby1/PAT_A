#include <iostream>

using namespace std;

void check(int& b, int& e, int& max, int* vessel);

int main(){
    int n;
    cin >> n;
    int vessel[n] = {0};
    bool flag = false;
    int count = 0;
    for(int i = 0;i < n; ++i){
        cin >> vessel[i];
        count += vessel[i];
        if(vessel[i] > 0){
            flag = true;
        }
    }

    if(!flag){
        cout << 0 << " " << vessel[0] << " " << vessel[n - 1] << endl;
        return 0;
    }

    int b = 0;
    int e = n - 1;
    int max = count;
    check(b,e,max,vessel);
    cout << max << " " << vessel[b] << " " << vessel[e] << endl; 
}

void check(int& b, int& e, int& max, int* vessel){
    int c_max = max,c_b = b,c_e = e,times = e;
    for(int i = 0;i < times;i++){
        if(vessel[c_b] < vessel[c_e]){
            c_max -= vessel[c_b];
            c_b++;
        }
        else{
            c_max -= vessel[c_e]; 
            c_e--;
        }

        if(max < c_max){
            max = c_max;
            b = c_b;
            e = c_e;
        }
    }
}