#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    string ID,name;
    int score;
};

bool cmpI(node a,node b){
    if(a.ID < b.ID){
        return true;
    }else{
        return false;
    }
}

bool cmpN(node a, node b){
    if(a.name < b.name){
        return true;
    }else if(a.name == b.name){
        if(a.ID < b.ID){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

bool cmpS(node a, node b){
    if(a.score < b.score){
        return true;
    }else if(a.name == b.name){
        if(a.ID < b.ID){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

int main(){
    int len,row;
    cin >> len >> row;
    node vessel[len];
    for(int i = 0;i < len;++i){
        cin >> vessel[i].ID >> vessel[i].name >> vessel[i].score;
    }
    switch (row)
    {
    case 1:
        sort(vessel,vessel + len,cmpI);
        break;
    case 2:
        sort(vessel,vessel + len,cmpN);
        break;
    case 3:
        sort(vessel,vessel + len,cmpS);
        break;
    
    default:
        break;
    }
    for(auto a : vessel){
        cout << a.ID << " " << a.name << " " << a.score << endl;
    }
}