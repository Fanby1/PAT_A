#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,float> a, pair<int,float> b){
    if(a.first < b.first){
        return true;
    }else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
    }
    return false;
}


int main(){
    vector<pair<int,float>> gass;
    int c,d,n;
    float a;
    cin >> c >> d >> a >> n;
    for(int i = 0;i < n;++i){
        pair<int,float> input;
        cin >> input.second >> input.first;
        if(input.first < d){
            gass.push_back(input);
        }
    }
    sort(gass.begin(),gass.end(),cmp);
    auto index = gass.begin();
    if(index->first != 0){
        cout << "The maximum travel distance = " << 0 << endl;
        return 0;
    }
    float cost = 0;
    float distance = 0;
    float capability = 0;
    for(;index < gass.end();++index){
        auto next = index + 1;
        if(next != gass.end()){
            if(next->second < index->second){
                if(capability * a < next->first - index->first){
                    cost += ((next->first - index->first) / a - capability) * index->second;
                    distance += next->first - index->first;
                    capability = 0;
                }else{
                    distance += next->first - index->first;
                    capability -= ((next->first - index->first) / a);
                }
            }else{
                cost += (c - capability) * index->second;
                capability = c - ((next->first - index->first) / a);
                distance += next->first - index->first;
            }
            if(capability * a + distance > d){
                cost -= (capability * a - distance) / a * index->second;
                distance = d;
                cout << cost << endl;
                return 0;
            }
        }
    }
    if(index == gass.end()){
        index--;
    }
    if(capability * a + distance == d){
        cost -= (capability * a - distance) / a * index->second;
        cout << cost << endl;
    }else{
        cost += (d - capability * a - distance) / a * index->second;
        cout << cost << endl;
    }
}