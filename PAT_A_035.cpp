#include <iostream>
#include <vector>

using namespace std;

int main(){
    int lines;
    cin >> lines;
    vector<pair<string,string>> result;
    for(int i = 0;i < lines;++i){
        string ID,password;
        cin >> ID >> password;
        bool flag = false;
        for(auto a = password.begin();a != password.end();++a){
            switch (*a)
            {
            case '1':
                (*a) = '@';
                flag = true;
                break;
            case 'l':
                (*a) = 'L';
                flag = true;
                break;
            case '0':
                (*a) = '%';
                flag = true;
                break;
            case 'O':
                (*a) = 'o';
                flag = true;
            
            default: 
                break;
            }
        }
        if(flag){
            result.push_back({ID,password});
        }
    }
    if(result.size() != 0){
        cout << result.size() << endl;
        for(auto a : result){
            cout << a.first << ' ' << a.second << endl;
        }
    }else if (lines > 1){
        cout << "There are " << lines << " accounts and no account is modified" << endl;
    }else{
        cout << "There is " << lines << " account and no account is modified" << endl;    
    }
}