#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
#include <string>
#include <iostream>


const int maxCol = 5;
const int maxRow = 5;


class Matrix {

    public:
        Matrix(int a, int b);
        ~Matrix();


        Matrix transpose();


        friend ostream& operator << (ostream& out, const Matrix& outMat);
        friend istream& operator >> (istream& in, Matrix& inMat);
        friend Matrix operator +(const Matrix& mat1, const Matrix& mat2);
        friend Matrix operator *(const Matrix& mat, const Matrix& mat2);


    private:
        int arr[maxRow][maxCol];
        int sizeX_;
        int sizeY_;

};

#endif
