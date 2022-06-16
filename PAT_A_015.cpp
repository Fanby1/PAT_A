#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long int turn(int a,int radix);
bool is_prime(int value);

int main(){
    int input, radix;
    while (true)
    {
        cin >> input;
        if(input <= 0){
            break;
        }

        cin >> radix;
        if(!is_prime(input)){
            cout << "No" << endl;
            continue;
        }
        int resrve = turn(input,radix);
        if(is_prime(resrve)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

}

long long int turn(int a,int radix){
    long long count = 0;
    while (true)
    {
        if(a == 0){
            break;
        }
        int b;
        count *= radix;
        count += a % radix;
        a = a / radix;
    }
    return count; 
}

bool is_prime(int value){
    if(value == 1){
        return false;
    }
    int limit = pow(value,0.5) + 1;
    for(int index = 2;index < limit;index++){
        if(value % index == 0){
            return false;
        }
    }
    return true;
}