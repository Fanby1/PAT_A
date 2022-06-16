#include <iostream>

using namespace std;

int turn_to_ten(string num,int radix);
int find_max(string num);
bool check_radix(string num, int origin);

int main(){
    string first,second;
    int tag, radix;
    cin >> first >> second >> tag >> radix;

    int origin = 0;
    if(tag == 1){
        origin = turn_to_ten(first, radix);
        if(!check_radix(second,origin)){
            cout << "Impossible" << endl;
        }
    }else{
        origin = turn_to_ten(second, radix);
        if(!check_radix(first,origin)){
            cout << "Impossible" << endl;
        }
    }
}

int turn_to_ten(string num,int radix){
    int count = 0;
    for(auto a : num){
        if(a > 47 && a < 58){
            count *= radix;
            count += a - 48;
        }else{
            count *= radix;
            count += a - 'a' + 10;
        }
    }

    return count;
}

int find_max(string num){
    int count = 0;
    for(auto a : num){
        if(a > count){
            count = a;
        }
    }
    if(count < 58){
        return count - 47;
    }else{
        return count - 'a' + 11;
    }
}

bool check_radix(string num, int origin){
    int least_radix = find_max(num);

    for(;least_radix < origin;least_radix++){
        if(origin == turn_to_ten(num,least_radix)){
            cout << least_radix << endl;
            return true;
        }
    }

    return false;
}