//
// Created by Roman Ellerbrock on 12/9/21.
//

#include "reference.h"
#include <iostream>

using namespace std;

void increment(int *x) {
	/// correct code
	(*x)++;

	/// possible causes for bugs:
	//x++; // does nothing
	//*x++; // still does nothing
	//x = x + 1;
	// x = malloc(...);
	// free(x);

	/// modifications after a first wrong one might cause seg-faults.
	/// Even if the next ones are correct.

	// cout << "x = " << *x << " | address: " << x << endl;
}

void increment(int& x) {
	x++;
}

void referenceDemo() {
/*	int i = 0;
	cout << "i = " << i << " | address: " << &i << endl;
	increment(&i);
	cout << "i = " << i << " | address: " << &i << endl;
	increment(i);
	cout << "i = " << i << " | address: " << &i << endl;

	int a = 5;
	int b = 3;
	int& ref = b;
	ref = a; // references are only assigned to memory upon initialization
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;*/

	{
		int i = 5;
		int *iPtr = &i;
		int &iRef = i;


		cout << *iPtr << iRef;
	}
}
