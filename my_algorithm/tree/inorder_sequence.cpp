/*树的中序遍历
    对于当前结点，先输出它的左孩子，然后输出该结点，最后输出它的右孩子。
*/

#include "tree.hpp"
#include <iostream>
#include <stack>


using namespace std;
void Tree::inorder_sequence(){
    Node* temp = NULL;
    stack<Node*> vessel;
    vessel.push(&root);
    while (!vessel.empty())
    {
        while ((temp = vessel.top()) && temp)
        {
            vessel.push(temp->getLeft());
        }
        vessel.pop();

        if(!vessel.empty()){
            temp = vessel.top();
            vessel.pop();
            cout << temp->get() << " ";
            vessel.push(temp->getRight());
        }
    }
}