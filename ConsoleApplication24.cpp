#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    // Додавання ноди до дерева
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
            insertRecursive(root, value);
        }
    }

    // Пошук елемента зі значенням k
    bool search(int k) {
        return searchRecursive(root, k);
    }

private:
    Node* root;

    // Рекурсивна функція для додавання ноди
    void insertRecursive(Node* node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            }
            else {
                insertRecursive(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new Node(value);
            }
            else {
                insertRecursive(node->right, value);
            }
        }
    }

    // Рекурсивна функція для пошуку елемента зі значенням k
    bool searchRecursive(Node* node, int k) {
        if (node == nullptr) {
            return false; 
        }

        if (k == node->data) {
            return true; 
        }
        else if (k < node->data) {
            return searchRecursive(node->left, k);
        }
        else {
            return searchRecursive(node->right, k);
        }
    }
};

int main() {
    BinaryTree bst;

    // Додавання елементів до дерева
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    int k = 40;

    
    if (bst.search(k)) {
        cout << k << " found in tree." << endl;
    }
    else {
        cout << k << " not found in tree." << endl;
    }

    return 0;
}
