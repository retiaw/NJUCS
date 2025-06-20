#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ArrayList
{
public:
    // constructor(to initialize)
    ArrayList();

    // destructor:
    ~ArrayList();

    // member functions (methods):
    void add(int value);
    void clear();
    int get(int index) const;
    void insert(int index, int value);
    bool isEmpty() const;
    void remove(int index);
    void set(int index, int value);
    int size() const;
    void debug() const;

private:
    // member variables (fields):
    int *myElements;
    int mySize;
    int myCapacity;

    // member function:
    void checkResize();
};

ostream& operator <<(ostream &out, ArrayList &list)
{
    out << "{";

    for (int i = 0; i < list.size(); i++) {
        out << " " << list.get(i);
        if (i != list.size() - 1) {
            out << ",";
        }
    }

    out << "}";
    return out;
}

#endif // ARRAYLIST_H
