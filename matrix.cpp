//
// Created by Kevin Aguilar on 5/6/20.
// used to control the matrix used to keep track of the similarity
// between documents in this program
//
#include "matrix.h"

Matrix::Matrix() {

    int rows = 3; //creates a standard matrix
    int cols = 3;
    mat = new int* [rows]();

    for(int i = 0; i<rows; i++){

        mat[i] = new int [cols]();

    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){

            mat[i][j] = 0;

        }

    }

}

Matrix::Matrix(int numOfFiles) {

    int rows = numOfFiles;
    int cols = numOfFiles;//same code as above but actually makes the matrix for the correct dimensions
    mat = new int* [rows]();//creates the rows

    for(int i = 0; i<rows; i++){

        mat[i] = new int [cols]();//goes through each row and allocates enough memory for the columns

    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){

            mat[i][j] = 0; //seting every value to 0

        }

    }

}


Matrix::~Matrix() {

    for(int i = 0; i < row; i++){

        delete [] mat[i];

    }

    delete [] mat;

}

void Matrix::incramentVal(int row, int col) {


    if(col > row){

        mat[row][col] += 1; //set the top half of the matrix to increment on a given coordinate

    }

}

int Matrix::getval(int row, int col) {

    int val;

    if(col > row){

        val = mat[row][col]; //retrieves the value at a certain location to see if it is above the threshold

    }

    return val;

}

