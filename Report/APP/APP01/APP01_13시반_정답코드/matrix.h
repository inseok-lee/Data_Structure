#pragma once
using namespace std;  // ostream을 위해서 써야함


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

	int sum() {
		int result = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				result = result + this->matrix[i][j];
			}
		}
		return result;
	}

	Matrix operator + (Matrix m) {

		Matrix newMatrix;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				newMatrix.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
			}
		}

		return newMatrix;
	}

	Matrix operator * (int k) {

		Matrix newMatrix;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				newMatrix.matrix[i][j] = this->matrix[i][j]*k;
			}
		}

		return newMatrix;
	}

	Matrix operator - (Matrix m) {

		Matrix newMatrix;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				newMatrix.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
			}
		}

		return newMatrix;
	}

	friend ostream& operator<< (ostream& out, const Matrix& m);

private:
	int matrix[2][2];

};


ostream& operator<< (ostream& out, const Matrix& m) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			out << m.matrix[i][j] << " ";
		}
		out << std::endl;
	}

	return out;
}
