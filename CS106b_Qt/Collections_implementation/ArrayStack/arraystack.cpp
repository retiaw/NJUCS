#include "arraystack.h"
#include <iostream>
using namespace std;

ArrayStack::ArrayStack()
{
    array = new int[10]();
    size = 0;
    capacity = 10;
}

ArrayStack::~ArrayStack()
{
    delete[] array;
    size = 0;
    capacity = 0;
}

void ArrayStack::push(int n)
{
    if (size >= capacity) {
        int *temp = new int[capacity * 2]();
        std::memcpy(temp, array, capacity * sizeof(int));
        delete[] array;
        array = temp;
        capacity *= 2;
    }
    array[size++] = n;
}

int ArrayStack::pop()
{
    if (size == 0) {
        throw std::runtime_error("Stack is empty");
    } else {
        size--;
        return array[size];
    }
}

int ArrayStack::peek() const
{
    if (size == 0) {
        throw std::runtime_error("Stack is empty");
    } else {
        return array[size - 1];
    }
}

bool ArrayStack::isEmpty() const
{
    return (size == 0);
}

ostream& operator <<(ostream& out, const ArrayStack &stack)
{
    out << "{";

    for (int i = 0; i < stack.size; i++) {
        out << stack.array[i];
        if (i != stack.size - 1) {
            out << ", ";
        }
    }

    out << "}";

    return out;
}



