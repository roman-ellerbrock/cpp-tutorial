//
// Created by Roman Ellerbrock on 12/9/21.
//

#include "tutorial-1.h"
#include <cstdlib>
#include "Matrix.h"
#include "cMatrix.h"
#include "reference.h"

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

void matrixCPPDemo() {

	Matrix A = aRange(5, 10);
	Matrix B = aRange(10, 3);
	cout << "A:\n";
	cout << A << endl;
	cout << "B:\n";
	cout << B << endl;
	Matrix C = A * B;

	cout << "C:\n";
	cout << C << endl;
}

void runTutorial1() {
	referenceDemo();
	matrixCDemo();
	matrixCPPDemo();
}