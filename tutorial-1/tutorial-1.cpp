//
// Created by Roman Ellerbrock on 12/9/21.
//

#include "tutorial-1.h"
#include <cstdlib>
#include "cMatrix.h"
#include <iostream>
#include "Matrix.h"

using namespace std;

void matrixCDemo() {
	size_t nrowA = 5;
	size_t ncolA = 10;
	double* A = (double*) malloc(nrowA * ncolA * sizeof(double));

	size_t nrowB = 10;
	size_t ncolB = 20;
	double* B = (double*) malloc(nrowB * ncolB * sizeof(double));

	size_t nrowC = 5;
	size_t ncolC = 20;
	double* C = (double*) malloc(nrowB * ncolB * sizeof(double));

	product(C, nrowC, ncolC, A, nrowA, ncolA, B, nrowB, ncolB);

	free(A);
	free(B);
	free(C);
}

void doMyTask(Matrix& C, const Matrix& A, const Matrix& B) {
	product(C, A, B);
	/// ...
}

void matrixCPPDemo() {
	Matrix A(5, 10);
	Matrix B(10, 20);
	Matrix C(5, 20);

	doMyTask(C, A, B);

	Matrix D = product(A, B);
	Matrix E = A * B;
}

void ruleOfThree() {
	Matrix A(5, 10);

	/// 1.) Default constructor
	Matrix B;

	/// 2.) Copy constructor
	Matrix C(A);

	/// 3.) Copy assignment operator
	Matrix D = A;

	C.ptr()[0] = 1;
	D.ptr()[0] = 1;
}

Matrix generator() {
	Matrix m(10, 10);
	for (size_t r = 0; r < m.nrow_; ++r) {
		for (size_t c = 0; c < m.ncol_; ++c) {
			m(r, c) = (double) (r * c);
		}
	}
	return m;
}

void ruleOfFive() {
	Matrix A(10, 10);

	/// Constructs C from temporary object
	Matrix C(generator());

	/// Creates B from temporary object via operator=
	Matrix B = generator();

	/// Writes on existing object from temporary
	A = generator();

	C.ptr()[0] = 1;
	B.ptr()[0] = 1;
	A.ptr()[0] = 1;
}

void liveDemo() {

}

void runTutorial1() {
	matrixCPPDemo();
	ruleOfThree();
	ruleOfFive();
	liveDemo();
}
