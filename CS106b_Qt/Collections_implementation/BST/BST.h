#ifndef BST_H
#define BST_H

class BST
{
public:

    BST();
    ~BST();

    void print() const;
    int size() const;
    bool contain(int data) const;
    int findMin() const;
    int findMax() const;
    void add(int value);
    void free();
    void remove(int value);

private:

    struct Node {
        Node *left;
        Node *right;
        int data;

        Node(Node *left, Node *right, int data)
        {
            this -> left = left;
            this -> right = right;
            this -> data = data;
        }

        bool isLeaf()
        {
            return (this -> left == nullptr && this -> right == nullptr);
        }
    };

    Node *root;

    void print_helper(Node *node) const;
    int size_helper(Node *node) const;
    bool contain_helper(Node *node, int data) const;
    int findMin_helper(Node *node) const;
    int findMax_helper(Node *node) const;
    void add_helper(int value, Node *&node);
    void free_helper(Node *node);
    void remove_helper(int value, Node *&node);
    Node* remove_findMin(Node *node) const;
};

#endif // BST_H

