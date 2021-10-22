#pragma once
#include <iostream>
using namespace std;

//SquareMatrix ADT Specification
//
//구조: N행과 N열을 가진 2차원 배열로 표현되는 정사각행렬
//연산:
//MakeEmpty(n)
//기능: Matrix의 n행, 열 내부를 0으로 초기화
//조건: N의 최대 크기는 50
//결과: N안의 행, 열은 0으로 초기화
//
//StoreValue(i, j, value)
//기능: value를 i번째행, j번째 열의 위치에 저장
//조건: i번째행, j번째열의 값은 초기화 되어있어야 한다
//결과: i번째행, j번째열에 value값 저장.
//
//Add
//기능: 두 행렬을 함께 더한다.
//조건: 두 행렬은 크기가 같아야 하며, 초기화 되어있어야 한다.
//결과: 두 행렬의 같은 행, 같은 열에 있는 값을 더한다.
//
//Subtract
//기능: 한 행렬을 다른 행렬로부터 뺀다.
//조건: 두 행렬은 크기가 같아야 하며, 초기화 되어있어야 한다.
//결과: 두 행렬의 같은 행, 같은 열에 있는 값을 뺀다.
//
//Copy
//기능: 한 행렬을 다른 행렬로 복사한다.
//조건: 두 행렬은 크기가 같아야 하며, 초기화 되어있어야 한다.
//결과: 같은 행, 같은 열에 있는 값을 다른 행렬로 복사

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

class SquareMatrix{
private:
    int matrix[MAX_ROWS][MAX_COLS];
    int size;
public:
    void MakeEmpty(int);
    void StoreValue(int, int, int);
    SquareMatrix Add(SquareMatrix, SquareMatrix);
    SquareMatrix Subtract(SquareMatrix, SquareMatrix);
    SquareMatrix Copy(SquareMatrix);
    void print();
};
