//
// Created by Roman Ellerbrock on 12/10/21.
//

#include "cMatrix.h"


/// Pure C functions

void aRange(double* A, size_t n) {
	for (size_t i = 0; i < n; ++i) {
		A[i] = (double) i;
	}
}

void product(double *C, size_t nRowC, size_t nColC,
	const double *A, size_t nRowA, size_t nColA,
	const double *B, size_t nRowB, size_t nColB) {
	if (nColA != nRowB) {
		printf("Matrix product error: nColA != nRowB\n");
		exit(1);
	}

	if (nColC != nColB) {
		printf("Matrix product error: nColC != nColB\n");
		exit(1);
	}

	if (nRowC != nRowA) {
		printf("Matrix product error: nRowC != nRowA\n");
		exit(1);
	}

	/// replace this by dgemm for efficient code
	for (size_t i = 0; i < nRowC; ++i) {
		for (size_t j = 0; j < nColC; ++j) {
			C[i * nColC + j] = 0.;
			for (size_t k = 0; k < nColA; ++k) {
				// C(i, j) += A(i, k) * B(k, j);
				C[i * nColC + j] += A[k * nColA + i] * B[j * nColB + k];
			}
		}
	}
}

