//
// Created by Roman Ellerbrock on 12/10/21.
//

#ifndef CMATRIX_H
#define CMATRIX_H
#include <stdio.h>
#include <stdlib.h>

void aRange(double* A, size_t n);

void product(double *C, size_t nRowC, size_t nColC,
	const double *A, size_t nRowA, size_t nColA,
	const double *B, size_t nRowB, size_t nColB);

#endif //CMATRIX_H
