#include <iostream>
#include "List.h"
using namespace std;


int main() {
    Tree myTree;

    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(70);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(60);
    myTree.insert(80);

    myTree.print();

    int searchValue = 40;
    TreeNode* searchResult = myTree.search(searchValue);
    if (searchResult != nullptr) {
        cout << "Node with value " << searchValue << " found in the tree." << endl;
    }
    else {
        cout << "Node with value " << searchValue << " not found in the tree." << endl;
    }

    return 0;
}