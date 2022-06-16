/*后序遍历
    对于当前结点，先输出它的左孩子，然后输出它的右孩子，最后输出该结点。
*/
#include "tree.hpp"
#include <stack>
#include <iostream>

using namespace std;

void Tree::postorder_sequence(){
    
    stack<Node*> vessel;
    Node* temp = &root;
    Node* flag = nullptr;
    while (!vessel.empty() || temp != nullptr)
    {
        if(temp){
            vessel.push(temp);
            temp = temp->getLeft();
        }
        else{
            temp = vessel.top();
            if(temp->getRight() && temp->getRight() != flag){
                temp = temp->getRight();
                vessel.push(temp);
                temp = temp->getLeft();
            }
            else{
                temp = vessel.top();
                vessel.pop();
                flag = temp;
                cout << temp->get() << " ";
                temp = nullptr;
            }
        }
    }
}