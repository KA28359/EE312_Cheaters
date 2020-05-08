//
// Created by Kevin Aguilar on 5/3/20.
//

#ifndef CHEATERS_HASHTABLE_H
#define CHEATERS_HASHTABLE_H

#include <string>
#include <iostream>
#include "matrix.h"

using namespace std;

class HashTable {

private:

    static const int sizeOfHashTable = 5000000;
    struct node{

        int fileNum;
        node* next;
    };

public:

    node **table;

    HashTable();

    ~HashTable();

    int HashFunction(string key);

    void TableCollisions(Matrix &matrix);

    void InsertNode(int fileNum, int hashVal);

};



#endif //CHEATERS_HASHTABLE_H

