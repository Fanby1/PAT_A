#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
    float vessel[3][3] = {0};
    int result[3][3] = {0};
    float count = 1;

    for(int i = 0;i < 3;i++){
        int max = -1;
        int max_index = 0;
        for(int j = 0;j < 3;j++){
            cin >> vessel[i][j];
            if(vessel[i][j] > max){
                max = vessel[i][j];
                max_index = j;
            }           
        }
        result[i][max_index] = 1;
        count *= vessel[i][max_index];
    }

    count = (count * 0.65 - 1) * 2;
    string out = "";

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(result[i][j] == 1){
                switch (j)
                {
                case 0:
                    out += "W ";
                    break;
                case 1:
                    out += "T ";
                    break;
                default:
                    out += "L ";
                    break;
                }
            }
        }
    }

    char *buf = new char[100];
    sprintf(buf,"%.2f",count);
    out += buf;

    cout << out;
}