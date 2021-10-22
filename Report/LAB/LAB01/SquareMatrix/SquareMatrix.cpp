#include "SquareMatrix.hpp"

void SquareMatrix::MakeEmpty(int n){
    size = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }
}

void SquareMatrix::StoreValue(int i, int j, int value){
    matrix[i][j] = value;
}

SquareMatrix SquareMatrix::Add(SquareMatrix matA, SquareMatrix matB){
    SquareMatrix matC;
    matC.MakeEmpty(matA.size);
    for(int i = 0; i < (matC.size = matA.size); i++){
        for(int j = 0; j < matC.size ; j++){
            matC.matrix[i][j] = matA.matrix[i][j] + matB.matrix[i][j];
        }
    }
    return matC;
}

SquareMatrix SquareMatrix::Subtract(SquareMatrix matA, SquareMatrix matB){
    SquareMatrix matC;
    matC.MakeEmpty(matA.size);
    for(int i = 0; i < (matC.size = matA.size); i++){
        for(int j = 0; j < matC.size ; j++){
            matC.matrix[i][j] = matA.matrix[i][j] - matB.matrix[i][j];
        }
    }
    return matC;
}

SquareMatrix SquareMatrix::Copy(SquareMatrix matA){
    SquareMatrix matB;
    matB.MakeEmpty(matA.size);
    for(int i = 0; i < (matB.size = matA.size); i++){
        for(int j = 0; j < matB.size ; j++){
            matB.matrix[i][j] = matA.matrix[i][j];
        }
    }
    return matB;
}

void SquareMatrix::print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << '\t' << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}
