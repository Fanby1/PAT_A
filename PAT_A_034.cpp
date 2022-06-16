#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

#define CAPABILITY 2010
int table[CAPABILITY][CAPABILITY];
bool visited[CAPABILITY];

using namespace std;
map<string,int> n_t;
map<int,string> i_t;


void find(set<int> &all, int index){   
    for(int j = 0;j < CAPABILITY;++j){
        if(!visited[j] && table[index][j] != 0){
            visited[j] = true;
            all.insert(j);
            find(all,j);
        }
    }
}

int getIndex(string name){
    if(n_t.find(name) == n_t.end()){
        n_t.insert({name,n_t.size()});
        i_t.insert({n_t.size() - 1,name});
        return n_t.size() - 1;
    }
    else{
        return (*n_t.find(name)).second;
    }
}

string getName(int index){
    return (*i_t.find(index)).second;
}


int main(){
    int n,k;
    cin >> n >>k;
    
    int time[CAPABILITY];
    for(int i = 0;i < CAPABILITY;++i){
        visited[i] = true;
        time[i] = 0;
        for(int j = 0;j < CAPABILITY;++j){
            table[i][j] = 0;
        }
    }
    for(int i = 0;i < n;i++){
        string a,b;
        cin >> a >> b;
        int value;
        cin >> value;
        int i_a = getIndex(a);
        int i_b = getIndex(b);
        table[i_a][i_b] += value;
        table[i_b][i_a] += value;
        visited[i_b] = false;
        visited[i_a] = false;
    }
    map<string,int> result;

    for(int i = 0;i < CAPABILITY;++i){
        for(int j = 0;j < CAPABILITY;++j){
            time[i] += table[i][j]; 
        }
    }
    
    for(int i = 0;i < CAPABILITY;++i){       
        if(!visited[i]){
            int count = 0;
            set<int> all;
            all.insert(i);
            visited[i] = true;
            find(all,i);
            vector<int> bundl;
            bundl.resize(all.size());
            bundl.assign(all.begin(),all.end());
            for(int j = 0;j < bundl.size();++j){
                for(auto k = j + 1; k < bundl.size();k++){
                    count += table[bundl[j]][bundl[k]];
                }
            }
            
            
            if(count > k && bundl.size() > 2){
                sort(bundl.begin(),bundl.end(),[time](int a,int b){
                    if(time[a] > time[b]){
                        return true;
                    }else{
                        return false;
                    }
                });
                string name = getName(bundl[0]);
                result.insert({name,bundl.size()});
            }
        }
    }

    cout << result.size() << endl;
    for(auto a : result){
        cout << a.first << " " << a.second << endl;
    }
    
}