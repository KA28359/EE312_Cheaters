//
// Created by Kevin Aguilar on 5/6/20.
//

#ifndef CHEATERS_MATRIX_H
#define CHEATERS_MATRIX_H



class Matrix{

private:

    int row;
    int col;
    int **mat;

public:

    Matrix();

    Matrix(int numOfFiles);

    ~Matrix();

    void incramentVal(int row, int col);

    int getval(int row, int col);

};

#endif //CHEATERS_MATRIX_H
