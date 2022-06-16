#include <iostream>

using namespace std;

int main(){
    string input;
    int len = 0;
    getline(cin,input);
    for(float i = 0;i < input.size();i += 0.5){
        if(i - int(i) != 0){
            int first = int(i);
            int second = first +1;
            if(input[first] != input[second]){
                continue;
            }else{
                int j = 0;
                while(first - j >= 0 && second + j < input.size()){
                    if(input[first - j] == input[second + j]){
                        j++;
                    }else{
                        break;
                    }
                }
                if(j * 2 > len){
                    len = j * 2;
                }
            }
        }else{
            int j = 0;
            while(i - j >= 0 && i + j < input.size()){
                if(input[i - j] == input[i + j]){
                    j++;
                }else{
                    break;
                }
            }
            if(j * 2 - 1> len){
                len = j * 2 - 1;
            }
        }
    }
    cout << len << endl;
}