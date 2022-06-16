#include <iostream>
#include <algorithm>

using namespace std;

struct student
{
    string name;
    int score[4];//A C M E
};

bool cmp(student &a, student &b);
bool cmpI(int &a,int &b);
bool pred(const student &a, const student &b);

int main(){
    int all,q_all;
    cin >> all;
    cin >> q_all;

    student vessel[all];
    int c[all] = {0};
    int m[all] = {0};
    int e[all] = {0};
    int a[all] = {0};

    for (size_t i = 0; i < all; i++)
    {
        cin >> vessel[i].name >> vessel[i].score[1] >> vessel[i].score[2] >> vessel[i].score[3];
        vessel[i].score[0] = vessel[i].score[1] + vessel[i].score[2] + vessel[i].score[3];
        vessel[i].score[0] = vessel[i].score[0] / 3.0 + 0.5;
        a[i] = vessel[i].score[0];
        c[i] = vessel[i].score[1];
        m[i] = vessel[i].score[2];
        e[i] = vessel[i].score[3];
    }
    
    sort(vessel,&vessel[all],cmp);

    sort(a,&a[all],cmpI);
    sort(c,&c[all],cmpI);
    sort(m,&m[all],cmpI);
    sort(e,&e[all],cmpI);

    for (size_t i = 0; i < q_all; i++)
    {
        student name;
        cin >> name.name;

        student *s = search(vessel,&vessel[all],&name,&name + 1,pred);

        if(s == &vessel[all]){
            cout << "N/A" << endl;
            continue;
        }
        char type = -1;
        int rank = all + 1;
        
        int c_index = search(a,&a[all],&s->score[0],&s->score[0] + 1) - a + 1;
        if(c_index < rank){
            type = 'A';
            rank = c_index;
        }

        c_index = search(c,&c[all],&s->score[1], &s->score[1] + 1) - c + 1;
        if(c_index < rank){
            type = 'C';
            rank = c_index;
        }

        c_index = search(m,&m[all],&s->score[2], &s->score[2] + 1) - m + 1;
        if(c_index < rank){
            type = 'M';
            rank = c_index;
        }

        c_index = search(e,&e[all],&s->score[3], &s->score[3] + 1) - e + 1;
        if(c_index < rank){
            type = 'E';
            rank = c_index;
        }

        cout << rank << " " << type << endl;
    }
    
}


bool cmp(student &a, student &b){
    if(a.name < b.name){
        return false;
    }
    return true;
}

bool pred(const student &a, const student &b){
    if(a.name == b.name){
        return true;
    }
    return false;
}

bool cmpI(int &a,int &b){
    if(a < b){
        return false;
    }
    return true;
}
