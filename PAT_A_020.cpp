#include <iostream>
#include <vector>

using namespace std;

int length;
int *postorder,*inorder;
vector<int> *result;

void get(pair<int,int> round,int level){
    level++;
    if(round.first == round.second){
        return;
    }
    if(round.second - round.first == 1){
        result[level].push_back(inorder[round.first]);
    }else{
        int mid = -1;
        int max = -1;
        for(int i = round.first;i < round.second;i++){
            for(int j = 0;j < length;j ++){
                if(inorder[i] == postorder[j] && max < j){
                    max = j;
                    mid = i;
                    break;
                }
            }
        }
        result[level].push_back(inorder[mid]);
        get({round.first,mid},level);
        get({mid + 1, round.second},level);
    }
}

int main(){
    
    cin >> length;
    postorder = new int[length];
    inorder = new int[length];
    result = new vector<int>[length];
    for(int i = 0;i < length;i++){
        cin >> postorder[i];
    }
    for(int i = 0;i < length;i++){
        cin >> inorder[i];
    }
    get({0,length},-1);
    int index  = 0;
    for(int i = 0;i < length;++i){
        for(auto a : result[i]){
            if(index == length){
                return 0;
            }
            if(index != 0){
                cout << " " << a;
            }else{
                cout << a ;
            }
            index ++;
        }
    }
}