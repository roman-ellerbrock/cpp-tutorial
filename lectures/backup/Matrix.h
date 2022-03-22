//
// Created by Roman Ellerbrock on 12/9/21.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cstddef>

using namespace std;

class Matrix {
public:
	Matrix(size_t nrow, size_t ncol)
	: nrow_(nrow), ncol_(ncol), ptr_(nullptr) {
		ptr_ = (double*) malloc(nrow_ * ncol_ * sizeof(double));
	}

	Matrix() : Matrix(0, 0) {}

	~Matrix() {
		free(ptr_);
	}

	inline double operator()(size_t row, size_t col) const {
		return ptr_[col * nrow_ + row];
	}

	size_t nrow_, ncol_;
	double* ptr_;
};

// new Matrix with A(i, j) = i + j * nrow
Matrix aRange(size_t nrow, size_t ncol);

void product(Matrix& C, const Matrix& A, const Matrix& B);

Matrix operator*(const Matrix& A, const Matrix& B);

ostream& operator<<(ostream& os, const Matrix& A);

#endif //MATRIX_H
