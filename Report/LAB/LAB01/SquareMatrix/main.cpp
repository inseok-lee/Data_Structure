#include <iostream>
#include "SquareMatrix.hpp"

using namespace std;

int main()
{
    SquareMatrix matA;
    SquareMatrix matB;
    SquareMatrix matC;
    
    matA.MakeEmpty(3);
    matB.MakeEmpty(3);
    matC.MakeEmpty(3);
    matB.StoreValue(1, 1, 1);
    
    cout << "----- matA----" << endl;
    matA.print();
    
    cout << "-----matB-----" << endl;
    matB.print();
    
    cout << "------matC-----" << endl;
    matC.print();
    
    cout << "----- ADD -----" << endl;
    (matC.Add(matA, matB)).print();
    
    cout << "----- SUB -----" << endl;
    (matC.Subtract(matA, matB)).print();
    
    cout << "----- Copy -----" << endl;
    (matC.Copy(matB)).print();
    
    
    
    return 0;
}
