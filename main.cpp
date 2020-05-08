#include <vector>
#include <string>
#include <iostream>
#include <dirent.h>
#include <fstream>
#include "hashtable.h"
#include "matrix.h"
#include <cstdlib>
#include <errno.h>
#include <algorithm>



using namespace std;

int getdir (string dir, vector<string> &files); //code to get files from directory from class

string utol(string word); //prototype for converting upper case to lowercase


struct cellVals { //keeps track of how every file compares with each other

    int similarity;
    int rowNum;
    int colNum;

};

bool comparator(const cellVals& lhs, const cellVals& rhs);


int main(int argc, char* argv[]) {

    string dir = argv[1];
    int chunckNum = atoi(argv[2]); //gets values from command line
    int similarValues = atoi(argv[3]);
    vector<string> files = vector<string>();
    HashTable * hashTable = new HashTable();
    getdir(dir,files);
    files.erase(files.begin());
    files.erase(files.begin()); //gets rid of the . and ..


    vector<string> stringOfWords;
    for(int counter = 0; counter < files.size(); counter++) { //for every file present in the directory open it and get the word segments
        ifstream inFile;
        string fileName = files[counter];
        string name = dir + "/" + fileName.c_str(); //constructing the directory
        inFile.open(name.c_str());
        string s;
        inFile >> s;
        if (inFile.is_open()) {
            while (!inFile.eof()) {
                while ((stringOfWords.size() < chunckNum) && (!inFile.eof())) { //putting word chunks in a vector

                    stringOfWords.push_back(s);
                    inFile >> s;

                }
                string wordsCombined;
                for (int i = 0; i < chunckNum; i++) { //making the word chunks into one long string for the hash function

                    wordsCombined += stringOfWords[i];

                }
                wordsCombined = utol(wordsCombined);
                int value = hashTable->HashFunction(wordsCombined);
                hashTable->InsertNode(counter,value);
                stringOfWords.erase(stringOfWords.begin()); //gets rid of first word to make room for next word

            }

        }

        else{

            cout<< "The File:"<<fileName<<"Was Not Found"<<endl; //case if a file doesnt exist
            return 0;

        }

    }

    Matrix * matrix = new Matrix(files.size());//creates matrix to keep track of similarity
    hashTable->TableCollisions(*matrix);


    vector<cellVals> tracker;

    for(int j = 0; j < files.size()-1; j++){      //puts all the values from the matrix into a vector
        for(int k = j+1; k < files.size(); k++){  //which is of type cellVals to hold the two files and their similarity

            int value = matrix->getval(j,k);
            cellVals data;
            data.rowNum = j;
            data.colNum = k;
            data.similarity = value;
            tracker.push_back(data);


        }

    }

    sort(tracker.begin(),tracker.end(),&comparator);
    for (int i = 0; i <= tracker.size(); i++){
        if(tracker[i].similarity > similarValues) { //prints the hgihest similar files above a given threshold
            cout << tracker[i].similarity << ": " << files.at(tracker[i].rowNum) << " " << files.at(tracker[i].colNum) << endl;
        }
    }

    return 0;
}

int getdir (string dir, vector<string> &files){ //code from class to retrieve the files in the directory


    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

string utol(string word){ //converts the words from uppercase to lowercase

    const int A_ASCII_UPPERCASE = 65;
    const int Z_ASCII_UPPERCASE = 90;
    const int CHANGER = 32;

    for(int i = 0; i < word.length(); i++){

        if((word[i] >= A_ASCII_UPPERCASE) && (word[i]<=Z_ASCII_UPPERCASE)){

            word[i] = word[i] + CHANGER; //adding 32 keeps the same letter but changes case

        }


    }

    return word;
}


bool comparator(const cellVals& lhs, const cellVals& rhs) { //overriding the comparator
    return lhs.similarity > rhs.similarity;
}