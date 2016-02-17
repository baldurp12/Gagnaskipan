#include "Matrix.h"
using namespace std;

Matrix::Matrix(int a, int b)
{
    sizeX_ = a;
    sizeY_ = b;

    for(int i = 0; i < sizeX_; i++){ //init of matrix
        for(int j = 0; j < sizeY_; j++){
            arr[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    //destructor
}

ostream& operator << (ostream& out, const Matrix& outMat){
    for(int i = 0; i < outMat.sizeX_; i++){
            out << endl;
        for(int j = 0; j < outMat.sizeY_; j++){
            out << outMat.arr[i][j] << "\t";
        }
    }
    return out;
}

istream& operator >> (istream& in, Matrix& inMat){
    for(int i = 0; i < inMat.sizeX_; i++){
        for(int j = 0; j < inMat.sizeY_; j++){
            in >> inMat.arr[i][j];
        }
    }
    return in;
}

Matrix operator +(const Matrix& matPlus1, const Matrix& matPlus2){

    Matrix tempMat(matPlus1.sizeX_, matPlus1.sizeY_);

    for(int i = 0; i < tempMat.sizeX_; i++){
        for(int j = 0; j < tempMat.sizeY_; j++){
            tempMat.arr[i][j] = matPlus1.arr[i][j] + matPlus2.arr[i][j];
        }
    }

    return tempMat;
}

Matrix operator *(const Matrix& matX1, const Matrix& matX2){

    Matrix tempMat(matX1.sizeX_, matX2.sizeY_);

    for(int i = 0; i < tempMat.sizeX_; i++){
        for(int j = 0; j < tempMat.sizeY_; j++){
            for(int k = 0; k < tempMat.sizeY_; k++){
                tempMat.arr[i][j] +=  matX1.arr[i][k] * matX2.arr[k][j];
            }

        }


    }
    return tempMat;

}

Matrix Matrix::transpose(){

    Matrix tempMat(sizeY_, sizeX_);

    for(int i = 0; i < tempMat.sizeX_; i++){
        for(int j = 0; j < tempMat.sizeY_; j++){
            tempMat.arr[i][j] = arr[j][i];
        }
    }


    return tempMat;
}








