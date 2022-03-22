//
// Created by Roman Ellerbrock on 12/10/21.
//

#include "Matrix.h"

void product(Matrix& C, const Matrix& A, const Matrix& B) {
	product(C.ptr(), C.nrow_, C.ncol_, A.ptr(), A.nrow_, A.ncol_, B.ptr(), B.nrow_, B.ncol_);
}

Matrix product(const Matrix& A, const Matrix& B) {
	Matrix C(A.nrow_, B.ncol_);
	product(C, A, B);
	return C;
}

Matrix operator*(const Matrix& A, const Matrix& B) {
	return product(A, B);
}
