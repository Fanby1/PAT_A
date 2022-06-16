#include "tree.hpp"

Tree::Tree(/* args */)
{
}

Tree::~Tree()
{
}

void Tree::setRight(Node *node,Node *right){
    if(node->getRight() == nullptr){
        size++;
    }
    node->setRight(right);
    node->getRight()->setFather(node);
    
}
void Tree::setLeft(Node *node,Node *left){
    if(node->getLeft() == nullptr){
        
        size++;
    }
    node->setLeft(left);
    node->getLeft()->setFather(node);
}

void Tree::setValue(int value){
    Node *temp = &root;
    if(size == 0){
        root = Node(value);
        size++;
        return;
    }
    while (true)
    {
        if(temp->get() > value){
            Node *left = temp->getLeft();
            if(left == nullptr){
                Node new_node(value);
                this->setLeft(temp,&new_node);
                break;
            }
            else{
                temp = left;
            } 
        }
        else{
            Node *right = temp->getRight();
            if(right == nullptr){
                Node new_node(value);
                this->setRight(temp,&new_node);
                break;
            }
            else{
                temp = right;
            } 
        }
    } 
}
