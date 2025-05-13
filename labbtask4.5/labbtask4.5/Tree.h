#pragma once
#include<iostream>
template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;

        Node(T value, Node* p = nullptr) : data(value), left(nullptr), right(nullptr), parent(p) {}
    };

    Node* root;

    void insert(Node*& node, T value, Node* parent) {
        if (!node) {
            node = new Node(value, parent);
        }
        else if (value < node->data) {
            insert(node->left, value, node);
        }
        else {
            insert(node->right, value, node);
        }
    }

    Node* find(Node* node, T value) {
        if (!node || node->data == value) return node;
        if (value < node->data) return find(node->left, value);
        return find(node->right, value);
    }

    void print(Node* node) {
        if (!node) return;
        print(node->left);
        std::cout << node->data << " ";
        print(node->right);
        //std::cout << std::endl;
    }

    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    Node* copyTree(Node* node, Node* parent) {
        if (!node) return nullptr;
        Node* newNode = new Node(node->data, parent);
        newNode->left = copyTree(node->left, newNode);
        newNode->right = copyTree(node->right, newNode);
        return newNode;
    }

    void findMaxInnerNode(Node* node, Node*& maxNode) {
        if (!node) return;
        if ((node->left || node->right) && (!maxNode || node->data > maxNode->data)) {
            maxNode = node;
        }
        findMaxInnerNode(node->left, maxNode);
        findMaxInnerNode(node->right, maxNode);
    }

    void replaceParentLink(Node* node, Node* newNode) {
        if (!node->parent) {
            root = newNode;
        }
        else if (node->parent->left == node) {
            node->parent->left = newNode;
        }
        else {
            node->parent->right = newNode;
        }
        if (newNode) {
            newNode->parent = node->parent;
        }
    }

    void deleteNode(Node* node) {
        if (!node) return;

        if (node->left && node->right) {
            Node* successor = node->right;
            while (successor->left) successor = successor->left;
            node->data = successor->data;
            deleteNode(successor);
        }
        else if (node->left || node->right) {
            Node* child = node->left ? node->left : node->right;
            replaceParentLink(node, child);
            delete node;
        }
        else {
            replaceParentLink(node, nullptr);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    BinaryTree(const BinaryTree& other) {
        root = copyTree(other.root, nullptr);
    }

    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            destroyTree(root);
            root = copyTree(other.root, nullptr);
        }
        return *this;
    }

    BinaryTree(BinaryTree&& other) noexcept : root(other.root) {
        other.root = nullptr;
    }

    BinaryTree& operator=(BinaryTree&& other) noexcept {
        if (this != &other) {
            destroyTree(root);
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    ~BinaryTree() { destroyTree(root); }

    void insert(T value) { insert(root, value, nullptr); }

    Node* find(T value) { return find(root, value); }

    void print() { print(root); std::cout << std::endl; }

    void removeMaxNodeWithLeaf() {
        Node* maxInner = nullptr;
        findMaxInnerNode(root, maxInner);
        if (maxInner) {
            std::cout << "Deleting max value node: " << maxInner->data << std::endl;
            deleteNode(maxInner);
        }
        else {
            std::cout << "Nodes with 'kids' not found.\n";
        }
    }


    int countNodesAtLevel(Node* root, int level) {
        if (root == nullptr) {
            return 0;
        }
        if (level == 0) {
            return 1;
        }
        else {
            return countNodesAtLevel(root->left, level - 1) +
                countNodesAtLevel(root->right, level - 1);
        }
    }

};
