#include <iostream>
#include <cmath>

using namespace std;

float SqrRoot_recursion(float number, float approx, float tol);
float SqrRoot_non_recursion(float number, float approx, float tol);

int main()
{
    cout << SqrRoot_recursion(2, 1, 0.1) << endl;
    cout << SqrRoot_non_recursion(2, 1, 0.1) << endl;

    return 0;
}

float SqrRoot_recursion(float number, float approx, float tol){
    if(fabs(pow(approx, 2) - number) <= tol)
        return approx;
    else
        return SqrRoot_recursion(number, (pow(approx, 2) + number) / (2 * approx), tol);
}

float SqrRoot_non_recursion(float number, float approx, float tol){
    while(fabs(pow(approx, 2) - number) > tol){
        approx = (pow(approx, 2) + number) / (2 * approx);
    }
    return approx;
}