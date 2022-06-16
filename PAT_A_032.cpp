#include <iostream>
#include <map>
#include <set>

using namespace std;

struct node
{
    string address;
    string next_a;
    node *next;
    set<node*> before;
    char value;

    bool operator<(node b){
        if(address < b.address){
            return true;
        }else{
            return false;
        }
    }
};

struct word
{
    node* begin;
    node* end;
};

word getWord(string a,map<string,node*> &pool){
    node* temp = pool.find(a)->second;
    word result;
    result.begin = temp;
    result.end = temp;
    while (temp->next_a != "-1")
    {
        temp = pool.find(temp->next_a)->second;
        temp->before.insert(result.end);
        result.end->next = temp;
        result.end = temp;
    }
    return result;
}

string check(word a, word b){
    node* a_temp = a.end;
    node* b_temp = b.end;
    while(a_temp == b_temp){
        if(a_temp->before.size() != 1){
            return a_temp->address;
        }else if(a_temp->before.size() != 0){
            a_temp = *a_temp->before.begin();
            b_temp = *b_temp->before.begin();
        }else{
            return a_temp->address;
        }
    }
    return "-1";
}

int main(){
    map<string,node*> pool;
    string a,b;
    cin >> a >> b;
    if (a == "-1" || b == "-1"){
        cout << "-1" << endl;
        return 0;
    }
    int len;
    cin >> len;
    if(len == 0){
        cout << "-1" << endl;
        return 0;
    }
    for(int i = 0;i < len;++i){
        node* n = new node();
        cin >> n->address >> n->value >> n->next_a;
        pool.insert({n->address, n});
    }
    word a_ = getWord(a,pool);
    word b_ = getWord(b,pool);

    cout << check(a_,b_) << endl;
}

