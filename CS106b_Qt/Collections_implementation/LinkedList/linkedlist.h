#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;

    ListNode(int d = 0, ListNode *n = NULL) {   // construct;
        data = d;
        next = n;
    }
};

class LinkedList
{
public:
    LinkedList();   // constructor;
    ~LinkedList();  // destructor;

    // member functions:
    void add(int value);
    void clear();
    int get(int index) const;
    void insert(int index, int value);
    bool isEmpty() const;
    void remove(int index);
    void set(int index, int value);
    int size() const;
    void Sort();

    friend ostream &operator <<(ostream &out, LinkedList &list);

private:
    ListNode *head;
    ListNode *tail;
};

#endif // LINKEDLIST_H
