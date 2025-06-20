#include "hashset.h"


HashSet::HashSet(){
    hashTable = new HashNode*[17](); // use a prime;
    mySize = 0;
    capacity = 10;
}

int HashSet::hashCode(int value) const {
    return abs(value) % capacity;
}

void HashSet::rehash() {
    int oldCapacity = capacity;
    HashNode** oldTable = hashTable;

    capacity *= 2;
    hashTable = new HashNode*[capacity]();
    for (int i = 0; i < oldCapacity; i++) {
        HashNode* current = oldTable[i], temp = nullptr;
        while (current != nullptr) {
            temp = current;
            current = current -> next;
            int hash = hashCode(current -> data);
            current -> next = hashTable[hash];
            hashTable[hash] = current;
        }
    }

    delete []oldTable;
}

void HashSet::add(int value) {
     int hash = hashCode(value);

     // prevent duplicates:
     if (contains(value)) {
         return ;
     }

     // insert at the front of the list:
     HashNode new_node = new HashNode(value);
     new_node -> next = hashTable[hash];
     hashTable[hash] = new_node;
     size++;

     // rehash if need to:
     if (loadFactor() > MAX_LOAD_FACTOR) {
         rehash();
     }
}

bool HashSet::contains(int value) const {
    int hash = hashCode(value);
    HashNode* current = hashTable[hash];
    while (current != nullptr) {
        if (current -> date == value) {
            return true;
        }
        current = current -> next;
    }
    return false;
}

double HashSet::loadFactor() const {
    return mySize / capacity;
}

void HashSet::remove(int value) {
    int hash = hashCode(value);

}

int HashSet::size() const {
    return mySize;
}
