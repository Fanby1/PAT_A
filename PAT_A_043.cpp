#include <iostream>
#include <vector>
#include <stack>

/*
                8
            6       8
                5
*/
using namespace std;

struct node
{
    int value;
    node *parent = nullptr, *left_son = nullptr, *right_son = nullptr;
    bool is_arrive = false;
};

bool increas_node(node &parent, node &new_node, bool is_reverse){
    if(is_reverse){
        if(new_node.value < parent.value){
            if(parent.right_son != nullptr){
                return increas_node(*parent.right_son,new_node,is_reverse);
            }else{
                parent.right_son = &new_node;
                new_node.parent = &parent;
            }
        }else{
            if(parent.right_son != nullptr){
                return false;
            }
            if(parent.left_son != nullptr){
                return increas_node(*parent.left_son,new_node,is_reverse);
            }else{
                parent.left_son = &new_node;
                new_node.parent = &parent;
            }
        }
    }
    else{
        if(new_node.value < parent.value){
            if(parent.right_son != nullptr){
                return false;
            }
            if(parent.left_son != nullptr){
                return increas_node(*parent.left_son,new_node,is_reverse);
            }else{
                parent.left_son = &new_node;
                new_node.parent = &parent;
            }
        }else{
            if(parent.right_son != nullptr){
                return increas_node(*parent.right_son,new_node,is_reverse);
            }else{
                parent.right_son = &new_node;
                new_node.parent = &parent;
            }
        }
    }
    return true;
}

int main(){
    int num ;
    cin >> num;
    vector<node> pool;
    pool.resize(num);
    for(int i = 0;i < num;++i){
        cin >> pool[i].value;
    }
    bool is_reverse = pool[0].value <= pool[1].value;
    for(int i = 1;i < num;++i){
        if(!increas_node(pool[0],pool[i],is_reverse)){
            cout << "NO" << endl;
            return 0;
        };
    }
    cout << "YES" << endl;
    stack<node*> s;
    s.push(&pool[0]);
    while (!s.empty())
    {
        if(s.top()->left_son != nullptr && !s.top()->left_son->is_arrive){
            s.push(s.top()->left_son);
        }else if(s.top()->right_son != nullptr && !s.top()->right_son->is_arrive){
            s.push(s.top()->right_son);
        }else{
            if(s.top()->parent == nullptr){
                cout << s.top()->value << endl;
            }else{
                cout << s.top()->value << " ";
            }
            s.top()->is_arrive = true;
            s.pop();
        }
    }
    
}
