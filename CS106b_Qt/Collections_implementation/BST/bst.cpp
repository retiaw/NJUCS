#include "BST.h"
#include <iostream>
using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    free();
    root = nullptr;
}

void BST::print() const
{
    print_helper(root);
}

void BST::print_helper(Node *node) const
{
    if (node) {
        cout << node -> data << endl;

        print_helper(node -> left);
        print_helper(node -> right);
    }
}

int BST::size() const
{
    return size_helper(root);
}

int BST::size_helper(Node *node) const
{
    if (node == nullptr) {
        return 0;
    } else {
        return 1 + size_helper(node -> left) + size_helper(node -> right);
    }
}

bool BST::contain(int data) const
{
    return contain_helper(root, data);
}

bool BST::contain_helper(Node *node, int data) const
{
    if (node == nullptr) {
        return false;
    } else {
        if (node -> data == data) {
            return true;
        } else if (node -> data > data) {
            return contain_helper(node -> left, data);
        } else {
            return contain_helper(node -> right, data);
        }
    }
}

int BST::findMin() const
{
    return findMin_helper(root);
}

int BST::findMin_helper(Node *node) const
{
    if (node -> left == nullptr) {
        return node -> data;
    } else {
        return findMin_helper(node -> left);
    }
}

int BST::findMax() const
{
    return findMax_helper(root);
}

int BST::findMax_helper(Node *node) const
{
    if (node -> right == nullptr) {
        return node -> data;
    } else {
        return findMax_helper(node -> right);
    }
}

void BST::add(int value)
{
    add_helper(value, root);
}

void BST::add_helper(int value, Node *&node)
{
    if (node == nullptr) {
        node = new Node(nullptr, nullptr, value);
    } else {
        if (value > node -> data) {
            add_helper(value, node -> right);
        } else if (value < node -> data) {
            add_helper(value, node -> left);
        } else {
            return ;
        }
    }
}

void BST::free()
{
    free_helper(root);
}

void BST::free_helper(Node *node)
{
    if (node) {
        free_helper(node -> left);
        free_helper(node -> right);

        delete node;
    }
}

void BST::remove(int value)
{
    remove_helper(value, root);
}

/*
 * Firstly, you pass "root" to the function,
 * if   -> "root" is the target, it sould be deleted properly;
 * else -> the recursive function will pass in "parent -> child" pattern;
 * This method has two advantages:
 * 1. The node you want tp delete is "child", so you can make
 *    "parent -> child = parent -> child -> child".
 *    This method is able to delete the node as well as maintain the structure of the BST;
 * 2. "Node *&" can make you directly modify the parameter;
 *
 */

void BST::remove_helper(int value, Node*& node)
{
    if (node == nullptr) {
        throw std::runtime_error("value not found");
    } else {
        if (node -> data < value) {
            remove_helper(value, node -> right);
        } else if (node -> data > value) {
            remove_helper(value, node->left);
        } else {
            if (node -> isLeaf()) {
                delete node;
                node = nullptr;
            } else if (node -> left == nullptr) {
                Node *temp = node;
                node = node -> right;
                delete temp;
            } else if (node -> right == nullptr) {
                Node *temp = node;
                node = node -> left;
                delete temp;
            } else {
                Node* min_node = remove_findMin(node);
                node -> data = min_node -> data;
                remove_helper(min_node -> data, node -> right);
            }
        }
    }
}

BST::Node* BST::remove_findMin(Node *node) const
{
    if (node == nullptr) {
        return nullptr;
    } else {
        while (node -> left) {
            node = node -> left;
        }
        return node;
    }
}




