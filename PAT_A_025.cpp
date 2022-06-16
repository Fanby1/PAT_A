#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    string ID;
    int local_rank,rank,location,score;
};

bool cmp(student* a, student* b){
    if(a->score > b->score){
        return true;
    }else if(a->score == b->score && a->ID < b->ID){
        return true;
    }
    return false;
}

int main(){
    int location,count = 0;
    vector<student*>all;
    cin >> location;
    for(int i = 0;i < location;++i){
        int num = 0;
        cin >> num;
        count += num;
        vector<student*> locate;
        for(int j = 0;j < num;++j){
            student *a = new student();
            cin >> a->ID >> a->score;
            a->location = i + 1;
            all.push_back(a);
            locate.push_back(a);
        } 
        sort(locate.begin(),locate.end(),cmp);
        int max = locate[0]->score;
        int index = 1;
        for(int j = 0;j < num;++j){
            if(locate[j]->score < max){
                locate[j]->local_rank = j + 1;
                max = locate[j]->score;
                index = j + 1;
            }else{
                locate[j]->local_rank = index;
            }
        }
    }
    
    sort(all.begin(),all.end(),cmp);
    int max = all[0]->score;
    int index = 1;
    for(int i = 0;i < count;++i){
        if(max > all[i]->score){
            all[i]->rank = i + 1;
            max = all[i]->score;
            index = i + 1;
        }else{
            all[i]->rank = index;
        }     
    }
    cout << count << endl;
    for(auto a : all){
        cout << a->ID << " " << a->rank << " " << a->location << " " << a->local_rank << endl;
    }
}