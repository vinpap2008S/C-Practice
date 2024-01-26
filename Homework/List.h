#include <iostream>
using namespace std;


class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
private:
    TreeNode* root;

public:
    Tree() {
        root = nullptr;
    }

    void insert(int value) {
        insertHelper(root, value);
    }

    void insertHelper(TreeNode*& node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
        }
        else if (value < node->data) {
            insertHelper(node->left, value);
        }
        else {
            insertHelper(node->right, value);
        }
    }

    TreeNode* search(int value) {
        return searchHelper(root, value);
    }

    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* currentNode, int value) {
        if (currentNode == nullptr) {
            return nullptr;
        }

        if (value < currentNode->data) {
            currentNode->left = deleteNode(currentNode->left, value);
        }
        else if (value > currentNode->data) {
            currentNode->right = deleteNode(currentNode->right, value);
        }
        else {
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                return nullptr;
            }
            else if (currentNode->left == nullptr) {
                TreeNode* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                TreeNode* temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            else {
                TreeNode* minNode = findMinNode(currentNode->right);
                currentNode->data = minNode->data;
                currentNode->right = deleteNode(currentNode->right, minNode->data);
            }
        }

        return currentNode;
    }

    TreeNode* searchHelper(TreeNode* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        else if (value < node->data) {
            return searchHelper(node->left, value);
        }
        else {
            return searchHelper(node->right, value);
        }
    }

    void printTree(TreeNode* node) {
        if (node != nullptr) {
            printTree(node->left);
            cout << node->data << " ";
            printTree(node->right);
        }
    }

    void print() {
        printTree(root);
        cout << endl;
    }
};