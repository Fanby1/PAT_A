#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node
{
    string ad,n_ad;
    int value;
};

bool cmp(node &a, node &b){
    if(a.value > b.value){
        return false;
    }
    return true;
}
map<string,node> vessel;
vector<node> list;
int main(){
    int num;
    string ad;
    cin >> num >> ad;
    
    for (int i = 0;i < num;++i){
        node a;
        cin >> a.ad >> a.value >> a.n_ad;
        vessel.insert({a.ad, a});
    }
    while (true)
    {
        auto i = vessel.find(ad);
        if(i == vessel.end()){
            break;
        }
        list.push_back(i->second);
        ad = i->second.n_ad;
        if(i->second.n_ad == "-1"){
            break;
        }
    }
    
    if(vessel.size() == 0){
        cout << 0 << " " << ad << endl;
        return 0;
    }
    sort(list.begin(),list.end(),cmp);
    for (auto a = list.begin(); a != list.end() - 1; ++ a){
        auto i =  a + 1;
        if(i != list.end()){
            a->n_ad = i->ad;
        }
    }
    list[list.size() - 1].n_ad = "-1";
    cout << list.size() << " " << list[0].ad << endl;

    for(auto a : list){
        cout << a.ad << " " << a.value << " " << a.n_ad << endl;
    }
}
