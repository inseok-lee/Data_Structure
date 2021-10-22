#define MAX_ROWS 100
#define MAX_COLS 100
#include <iostream>

using namespace std;

int mat[MAX_ROWS][MAX_COLS];
int NumPaths_A(int row, int col, int n);
int NumPaths_B(int row,int col,int n);

int main()
{
    cout << NumPaths_A(1, 1, 10) << endl;

    for(int row = 0; row < MAX_ROWS; row++){
        for(int col = 0; col < MAX_COLS; col++){
            mat[row][col] = -1;
        }
    }

    cout << NumPaths_B(1, 1, 10) << endl;

    return 0;
}

int NumPaths_A(int row, int col, int n){
    if((row == n) || (col == n)){
        return 1;
    }
    else
        return NumPaths_A(row + 1, col, n) + NumPaths_A(row, col + 1, n);
}

int NumPaths_B(int row,int col,int n){
    if(mat[row][col] == -1) {
        if((row == n) || (col == n))
            mat[row][col] = 1;
        else
            mat[row][col] = NumPaths_B(row + 1, col, n) + NumPaths_B(row, col + 1, n);
    }
    return mat[row][col];
}