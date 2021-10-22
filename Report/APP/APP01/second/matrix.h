#pragma once
using namespace std;

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


	Matrix(const Matrix& m) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				this->matrix[i][j] = m.matrix[i][j];
			}
		}
	}

	Matrix operator+(const Matrix& m){
		Matrix newMat;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				newMat.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
			}
		}
		return newMat;
	}
	
	Matrix operator-(const Matrix& m){
		Matrix newMat;
		for(int i= 0; i < 2; i++){
			for(int j = 0; j < 2;j++){
				newMat.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
			}
		}
		return newMat;
	}

	Matrix operator*(int num){
		Matrix newMat;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				newMat.matrix[i][j] = this->matrix[i][j] * num;
			}
		}
		return newMat;
	}

	Matrix operator=(const Matrix& m){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				this->matrix[i][j] = m.matrix[i][j];
			}
		}
		return (*this);
	}

	int sum(){
		int res = 0;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				res += this->matrix[i][j];
			}
		}
		return res;
	}

	friend ostream& operator<<(ostream& cout, const Matrix& m);
	

private:
	int matrix[2][2];
};

ostream& operator<<(ostream& cout, const Matrix& m){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			cout << "\t" << m.matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return cout;
}
