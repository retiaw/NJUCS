#include "linkedlist.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList()
{
    ListNode *p = NULL, *q = NULL;
    for (p = head; p; p = q) {
        q = p -> next;
        delete p;
    }
}

void LinkedList::add(int value)
{
    ListNode *new_node = new ListNode(value);

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail -> next = new_node;
        tail = new_node;
    }
}

void LinkedList::clear()
{

}

int LinkedList::get(int index) const
{
    ListNode *p = NULL;
    int j = 0;
    for (p = head, j = 0; j < index && p; j++, p = p -> next);
    if (p == NULL) {
        throw("no enough node!");
    } else {
        return p -> data;
    }
}

void LinkedList::insert(int index, int value)
{
    ListNode *new_node = new ListNode(value);
    ListNode *p = NULL, *pre = NULL;
    int j = 0;
    for (j = 0, p = head; j < index && p; j++, pre = p, p = p -> next);
    if (p == NULL) {
        throw("no enough node!");
    } else if (p == head) {
        new_node -> next = head;
        head = new_node;
    } else {
        pre -> next = new_node;
        new_node -> next = p;
    }
}

bool LinkedList::isEmpty() const
{
    return head == NULL;
}

void LinkedList::remove(int index)
{
    ListNode *p = NULL, *pre = NULL;
    int j = 0;
    for (j = 0, p = head; j < index && p; j++, pre = p, p = p -> next);
    if (p == NULL) {
        throw("no enough node!");
    } else if (p == head) {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            head = p -> next;
            delete p;
        }
    } else if (p == tail) {
        tail = pre;
        tail -> next = NULL;
        delete p;
    } else {
        pre -> next = p -> next;
        delete p;
    }
}

void LinkedList::set(int index, int value)
{
    ListNode *p = NULL;
    int j = 0;
    for (j = 0, p = head; j < index && p; j++, p = p -> next);
    if (p == NULL) {
        throw("no enough node!");
    } else {
        p -> data = value;
    }
}

int LinkedList::size() const
{
    int j = 0;
    ListNode *p = NULL;
    for (p = head, j = 0; p; j++, p = p -> next);

    return j;
}

void LinkedList::Sort()
{
    if (head == NULL || head -> next == NULL) {
        return ;
    } else {
        ListNode *current = head -> next;
        head -> next = NULL;
        tail = head;

        ListNode *temp = NULL;
        while (current) {
            temp = current;
            current = current -> next;

            if (temp -> data < head -> data) {
                temp -> next = head;
                head = temp;
            } else if (temp -> data > tail -> data) {
                tail -> next = temp;
                tail = temp;
                tail -> next = NULL;
            } else {
                ListNode *p = NULL, *pre = NULL;
                for (p = head; p && p -> next && p -> next -> data < temp -> data; pre = p, p = p -> next);
                pre -> next = temp;
                temp -> next = p;
            }
        }
    }
}

ostream &operator <<(ostream &out, LinkedList &list)
{
    out << "{";

    for (ListNode *p = list.head; p; p = p -> next) {
        out << p -> data << ", ";
    }

    out << "}";
    return out;
}
