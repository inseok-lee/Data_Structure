#pragma once
using namespace std;  // ostream¿ª ¿ß«ÿº≠ Ω·æﬂ«‘


class Matrix {

public:

    Matrix() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                matrix[i][j] = 0;
            }
        }

    }

    Matrix(int ff, int fs, int sf, int ss) {
        matrix[0][0] = ff;
        matrix[0][1] = fs;
        matrix[1][0] = sf;
        matrix[1][1] = ss;
    }
    
    
    
    // 행렬의 덧셈
    Matrix add(Matrix X, Matrix Y){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.matrix[i][j] = X.matrix[i][j] + Y.matrix[i][j];
            }
        }
        return res;
    }
    
    // 행렬의 뺄셈
    Matrix sub(Matrix X, Matrix Y){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                matrix[i][j] = X.matrix[i][j] - Y.matrix[i][j];
            }
        }
        return res;
    }
    
    // 행렬의 스칼라곱
    void scala(int x){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                matrix[i][j] *= x;
            }
        }
    }
    
    // sum 멤버함수 추가
    int sum() const {
        int res = matrix[0][0] + matrix[0][1]
        + matrix[1][0] + matrix[1][1];
        return res;
    }
    

private:
    int matrix[2][2];

};
