//
// Created by Roman Ellerbrock on 12/9/21.
//

#include "Matrix.h"
#include "cMatrix.h"

/// C++ API

void product(Matrix& C, const Matrix& A, const Matrix& B) {
	product(C.ptr_, C.nrow_, C.ncol_, A.ptr_, A.nrow_, A.ncol_, B.ptr_, B.nrow_, B.ncol_);
}

Matrix operator*(const Matrix& A, const Matrix& B) {
	Matrix C(A.nrow_, B.ncol_);
	product(C, A, B);
	return C;
}

Matrix aRange(size_t nrow, size_t ncol) {
	Matrix A(nrow, ncol);
	aRange(A.ptr_, nrow * ncol);
	return A;
}

ostream& operator<<(ostream& os, const Matrix& A) {
	for (size_t i = 0; i < A.ncol_; ++i) {
		for (size_t j = 0; j < A.nrow_; ++j) {
			os << A(j, i) << " ";
		}
		cout << endl;
	}
	return os;
}
