#include "arraylist.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ArrayList::ArrayList()
{
    myElements = new int[10]();
    mySize = 0;
    myCapacity = 10;
}

ArrayList::~ArrayList()
{
    cout << "destructor called" << endl;
    delete[] myElements;
}

void ArrayList::add(int value)
{
    checkResize();
    myElements[mySize] = value;
    mySize++;
}

void ArrayList::clear()
{
    int *smaller = new int[10]();
    delete[] myElements;
    myElements = smaller;
    mySize = 0;
    myCapacity = 10;
}

int ArrayList::get(int index) const
{
    if (index >= mySize) {
        throw "invalid index";
    } else {
        return myElements[index];
    }
}

void ArrayList::insert(int index, int value)
{
    if (index >= mySize) {
        throw "invalid index";
    } else {
        checkResize();
        for (int i = mySize; i > index; i--) {
            myElements[i] = myElements[i - 1];
        }
        myElements[index] = value;
        mySize++;
    }

}

bool ArrayList::isEmpty() const
{
    return (mySize == 0);
}

void ArrayList::remove(int index)
{
    if (index >= mySize) {
        throw "invalid index";
    } else {
        for (int i = index; i < mySize; i++) {
            myElements[i] = myElements[i + 1];
        }
    }
}

void ArrayList::set(int index, int value)
{
    if (index >= mySize) {
        throw "invalid index";
    }
    myElements[index] = value;
}

int ArrayList::size() const
{
    return mySize;
}

void ArrayList::debug() const
{

}

void ArrayList::checkResize()
{
    if (mySize >= myCapacity) {
        int *bigger = new int[2 * myCapacity];
        for (int i = 0; i < mySize; i++) {
            bigger[i] = myElements[i];
        }
        delete[] myElements;
        myElements = bigger;
    }
}



