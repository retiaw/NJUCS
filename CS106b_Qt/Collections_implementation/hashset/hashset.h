#ifndef HASHSET_H
#define HASHSET_H

#include <iostream>
#include <string>

struct HashNode {
    int data;
    HashNode *next;

    HashNode(int data = data, HashNode* next = NULL) {
        this -> data = data;
        this -> next = next;
    }
};

class HashSet {

public:
    HashSet();

    ~HashSet();

    void add(int value);

    void clear();

    bool contains(int value) const;

    // return the ratio of size to capacity.
    // Used to decide when to rehash.
    double loadFactor() const;

    void printStructure() const;

    void remove(int value);

    int size() const;

private:
    HashNode** hashTable;  //  an array that stores "HashNode*"
    int mySize;
    int capacity;

    // return an intrger index at which the given integer can be
    // stored in the hash set`s array.
    int hashCode(int value) const;

    void rehash();
};

#endif // HASHSET_H
