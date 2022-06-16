/* test tree
        4
    1       6
      3   5   7
    2
*/

#include "tree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream file = ifstream("C:\\Users\\cookie\\Desktop\\PAT\\my_algorithm\\tree\\tree_file.txt", ios::binary);
    int num;
    Tree tree = Tree();
    file >> num;
    for(int i = 0;i < num;++i){
        int input;
        file >> input;
        tree.setValue(input);
    }
    tree.inorder_sequence();
    cout << endl;
    tree.postorder_sequence();
    cout << endl;
    tree.preorder_sequence();
}