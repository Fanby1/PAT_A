/*前序遍历
对于当前节点，先输出该节点，然后输出他的左孩子，最后输出他的右孩子
*/

#include "tree.hpp"
#include <iostream>
#include <stack>

using namespace std;

void Tree::preorder_sequence(){
    stack<Node*> vessel;
    Node* temp = &root;
    Node* flag = nullptr;
    while (!vessel.empty() || temp != nullptr)
    {
        if(temp){
            cout << temp->get() << " ";
            vessel.push(temp);
            temp = temp->getLeft();
        }
        else{
            temp = vessel.top();
            if(temp->getRight() && temp->getRight() != flag){
                temp = temp->getRight();
                cout << temp->get() << " ";
                vessel.push(temp);
                temp = temp->getLeft();
            }
            else{
                temp = vessel.top();
                vessel.pop();
                flag = temp;
                temp = nullptr;
            }
        }
    }
    return;
}
