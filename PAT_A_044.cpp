#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct result
{
    int begin,end,sum;
};


result check(result last, int target, vector<int> &chain){
    if(last.begin == last.end && last.end != chain.size()){
        last.end ++;
        last.sum += chain[last.end - 1];
        return last;
    }else if(last.end == chain.size()){
        if(last.begin == chain.size()){
            return last;
        }else{
            last.begin++;
            last.sum -= chain[last.begin - 1];
            return last;
        }
    }
    result r;
    if(target < last.sum && last.sum >= target + chain[last.begin]){
        r.sum = last.sum - chain[last.begin];
        r.begin = last.begin + 1;
        r.end = last.end;
    }else if(last.sum <= target){
        r = last;
        r.end++;
        r.sum += chain[last.end];
    }else if(target < last.sum && last.sum < target + chain[last.begin]){
        r.sum = last.sum + chain[last.end];
        r.end = last.end + 1;
        r.begin = last.begin;
    }
    return r;
}

int main(){
    int n,target;
    cin >> n >> target;
    vector<int> chain;
    chain.resize(n);
    for(int i = 0;i < chain.size(); ++i){
        cin >> chain[i];
    }
    vector<result> vessel;
    result min,last;
    min.begin = 0;
    min.end = 0;
    min.sum = 0;
    int index = 0;
    last = min;
    while (index != n)
    {
        result c = check(last,target,chain);
        if(c.sum < target){
            min = c;
        }else if(c.sum < min.sum){
            vessel.clear();
            min = c;
            vessel.push_back(c);
        }else if(c.sum == min.sum){
            vessel.push_back(c);
        }else if(vessel.size() == 0){
            min = c;
            vessel.push_back(c);
        }
        index = c.begin;
        last = c;
    }
    for(auto i : vessel){
        cout << i.begin + 1 << "-" << i.end << endl;
    }
}