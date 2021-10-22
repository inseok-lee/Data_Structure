#include <iostream>
#include "matrix.h"
using namespace std;

Matrix compute(Matrix& A, Matrix& B, Matrix& C)
{
    Matrix result;
    result = (A * 3) + (B * 2) - (C * 5);

    return result;
}

int main()
{
    int a,b,c,d;
    int e,f,g,h;
    int i,j,k,l;
    
    cout << "A : ";
    cin >> a >> b >> c >> d;
    cout << "B : ";
    cin >> e >> f >> g >> h;
    cout << "C : ";
    cin >> i >> j >> k >> l;
    
    Matrix A(a, b, c, d);
    Matrix B(e, f, g, h);
    Matrix C(i, j, k, l);
    
    Matrix D;
    D = compute(A, B, C);
    
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    cout << D << endl;

    int result = D.sum();
    
    cout << result;
    

    return 0;

}
