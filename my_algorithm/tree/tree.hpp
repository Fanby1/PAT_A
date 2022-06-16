/*树数据结构
*/

#pragma once

class Node
{
private:
    int value;
    Node *left_son = nullptr, *right_son = nullptr,*father = nullptr;
public:
    Node(){};
    Node(int value){
        this->value = value;
    }
    Node(int value,Node *left_son,Node *right_son){
        this->value = value;
        this->left_son = left_son;
        this->right_son = right_son;
    }

    int get(){
        return value;
    }
    Node* getLeft(){
        return left_son;
    }
    Node* getRight(){
        return right_son;
    }
    Node* getFather(){
        return father;
    }

    void set(int v){
        value = v;
    }
    void setLeft(Node* left){
        left_son = new Node();
        left_son->set(left->get());
    }
    void setRight(Node* right){
        right_son = new Node(); 
        right_son->set(right->get());
    }
    void setFather(Node* f){
        father = f;
    }
};

class Tree
{
private:
    Node root;
    int size = 0;
    void setRight(Node *node,Node *right);
    void setLeft(Node *node,Node *left);
public:
    Tree(/* args */);
    Tree(Node *root);
    ~Tree();

    Node getRoot(){
        return root;
    }

    Node getLeft(Node node){
        return *node.getLeft();
    }
    Node getRight(Node node){
        return *node.getRight();
    } 

    void setValue(int value);
    Node* find(int value){
        return nullptr;
    }
    void inorder_sequence();
    void postorder_sequence();
    void preorder_sequence();
};