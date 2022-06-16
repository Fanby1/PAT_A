#include <iostream>

using namespace std;

int main(){
    int floor = 0, next_floor = 0, count = 0, orders = 0, input;
    cin >> input;
    orders = input;
    for(int i = 0;i < orders;i++)
    {
        cin >> input;
        next_floor = input;
        int temp = next_floor - floor;
        if(temp > 0 ){
            count += temp * 6 + 5;
        }
        else{
            count -= temp * 4 - 5;
        }
        floor = next_floor;
        next_floor = 0;
    }
    cout << count << endl;
}