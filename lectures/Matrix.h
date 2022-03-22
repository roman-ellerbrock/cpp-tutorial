//
// Created by Roman Ellerbrock on 12/10/21.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <cstring>
#include <utility>
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
			*this = Matrix(A);
		}
		return *this;
	}

	Matrix(Matrix&& A) noexcept
	: nrow_(A.nrow_), ncol_(A.ncol_), ptr_(A.ptr_) {
		A.ptr_ = nullptr;
	}

	Matrix& operator=(Matrix&& A) noexcept {
		if (this == &A) {
			return *this;
		}
		delete[] ptr_;
		ncol_ = A.ncol_;
		nrow_ = A.nrow_;
		ptr_ = A.ptr_;
		A.ptr_ = nullptr;
		return *this;
	}

	Matrix(int nrow, int ncol)
		: nrow_(nrow), ncol_(ncol),
		  ptr_((double *) malloc(nrow_ * ncol_ * sizeof(double))) {
	}

	~Matrix() {
		free(ptr_);
	}

	inline double operator()(size_t r, size_t c) const {
		return ptr_[r * ncol_ + c];
	}

	inline double& operator()(size_t r, size_t c) {
		return ptr_[r * ncol_ + c];
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
