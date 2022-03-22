//
// Created by Roman Ellerbrock on 12/10/21.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <cstring>
#include "cMatrix.h"

class Matrix {
public:
	/// Default Constructor
	Matrix()
		: Matrix(1, 1) {}

	/// Copy Constructor
	Matrix(const Matrix& A)
		: Matrix(A.nrow_, A.ncol_) {
		memcpy(ptr_, A.ptr_, nrow_ * ncol_ * sizeof(double));
	}

	/// Copy Assignment Operator
	Matrix& operator=(const Matrix& A) {
		if (this == &A) {
			return *this;
		} else if (A.nrow_ == nrow_ && A.ncol_ == ncol_) {
			memcpy(ptr_, A.ptr_, nrow_ * ncol_ * sizeof(double));
		} else {
			free(ptr_);
			nrow_ = A.nrow_;
			ncol_ = A.ncol_;
			ptr_ = (double *) malloc(nrow_ * ncol_ * sizeof(double));
			memcpy(ptr_, A.ptr_, nrow_ * ncol_ * sizeof(double));
		}
		return *this;
	}

	Matrix(int nrow, int ncol)
		: nrow_(nrow), ncol_(ncol),
		  ptr_((double *) malloc(nrow_ * ncol_ * sizeof(double))) {
	}

	~Matrix() {
		free(ptr_);
	}

	int nrow_;
	int ncol_;

	[[nodiscard]] double *ptr() {
		return ptr_;
	}

	[[nodiscard]] const double *ptr() const {
		return ptr_;
	}

private:
	double *ptr_;
};

void product(Matrix& C, const Matrix& A, const Matrix& B);

Matrix product(const Matrix& A, const Matrix& B);

Matrix operator*(const Matrix& A, const Matrix& B);

#endif //MATRIX_H
