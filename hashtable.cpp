//
// Created by Kevin Aguilar on 5/3/20.
// used to create a hashtable and a hash function and an
// algorithm to populate the matrix used
//
#include "hashtable.h"
#include <vector>
#include "matrix.h"
#include <algorithm>

using namespace std;

HashTable::HashTable() {

    table = new node*[sizeOfHashTable]; //creates the hash table
    for(int i = 0; i < sizeOfHashTable; i++){

        table[i]=0; //sets every value of hashtable to zero

    }

}

int HashTable::HashFunction(string key) {

    int prime = 31;
    int hashValue = 0; //using a polynomial rolling hash function
    int exponent = 1;
    int lenOfString = key.length();
    for(int i = 0; i < lenOfString; i++){
        if((key[i]>=97) && (key[i]<=122)) { //if it is a valid letter do the has function
            hashValue = (hashValue + exponent * (1 + key[i] - 'a')) % sizeOfHashTable;
            exponent = (prime * exponent) % sizeOfHashTable;
        }

    }

    return hashValue;
}

void HashTable::TableCollisions(Matrix &matrix) {


    vector<int> fileVals;

    for(int i = 0; i < sizeOfHashTable; i++) {
        while (table[i] != NULL) {
        if(count(fileVals.begin(), fileVals.end(),table[i]->fileNum) == 0){

            fileVals.push_back(table[i]->fileNum);//putting all documents used in a certain row of the hash table into a vector

        }

        table[i]= table[i]->next;

        }
        if(fileVals.size() > 0) {
            for (int j = 0; j < fileVals.size() - 1; j++) {
                for (int k = j + 1; k < fileVals.size(); k++) {

                    matrix.incramentVal(fileVals[j], fileVals[k]); //populating the matrix with values from the vector

                }

            }
        }
        fileVals.erase(fileVals.begin(),fileVals.end()); //erase vector so when ran with next row of hash table it is clear
    }
}


void HashTable::InsertNode(int fileNum,int hashVal) {

    node* newInput = table[hashVal]; //creates a new node
    if(newInput == NULL){ //if the row of the hash table is empty
        newInput = new node;
        newInput->fileNum = fileNum;
        newInput->next = NULL;
        table[hashVal] = newInput;

    }

    else{ //if the row of the hash table is not empty

        while(newInput->next != NULL){  //goes to the end of the row and adds a new node
            newInput = newInput ->next;
        }
        node* temp = new node;
        temp->next = NULL;
        temp->fileNum = fileNum;
        newInput->next = temp;


    }

}

HashTable::~HashTable() {

    delete [] table;
}

