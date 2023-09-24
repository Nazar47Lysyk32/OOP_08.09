#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // Додавання ноди до дерева
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            insertRecursive(root, value);
        }
    }

    // Вивід всіх нод
    void display() {
        displayRecursive(root);
        cout << endl;
    }

private:
    TreeNode* root;

    // Рекурсивна функція для додавання ноди
    void insertRecursive(TreeNode* node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            }
            else {
                insertRecursive(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            }
            else {
                insertRecursive(node->right, value);
            }
        }
    }

    // Рекурсивна функція для виводу всіх нод
    void displayRecursive(TreeNode* node) {
        if (node != nullptr) {
            displayRecursive(node->left);
            cout << node->data << " ";
            displayRecursive(node->right);
        }
    }
};

int main() {
    BinarySearchTree bst;

    // Додавання елементів до дерева
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    
    cout << "All nodes in the binary search tree:" << endl;
    bst.display();

    return 0;
}
