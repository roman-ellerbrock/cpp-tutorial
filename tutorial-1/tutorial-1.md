# A Matrix class (part 1)

We are given a C implementation of a matrix-matrix
product in [cMatrix.cpp](cMatrix.cpp). Goal of this tutorial
is to write a simple matrix class that is wrapped around the C code.

# Exercise 1
Implement a matrix class in [Matrix.h](Matrix.h) that

1. has public integer members nrows_, ncols_ and private double* ptr_
2. can be constructed from number of rows and columns and has a destructor
3. provides an overloaded operator() that allows const and non-const access to matrix-elements
4. provides a print()const function that plots the matrix elements in a readable format
5. obeys the Rule of Three 

Test constructing matrices in [tutorial1.cpp](tutorial1.cpp) and print the matrices.
Make sure memory is deallocated correctly.

Test the copy constructor and copy assignment operator by adding print statements
and calling them via
```
   Matrix A(3, 4);
   
   // copy constructor
   Matrix B(A);
   
   // copy assignment operator
   B = A; // assign to existing Matrix
   Matrix C = A; // assign to new Matrix
   A = A; // assign to self
   
   // *modify A and print B to verify that B doesn't change*
```

Now wrap the product function in [cMatrix.cpp](cMatrix.cpp) by
writing a product function with the signature
```
// C = A * B
void product(Matrix& C, const Matrix& A, const Matrix& B);

// C = A * B
Matrix product(const Matrix& A, const Matrix& B);
```
Avoid replicating code in the two functions. Last overload
operator* and test if the matrix product works
```
// ...
Matrix C = A * B;
```

# Exercise 2 - Move Semantics

Write a function that samples square random matrices from the gaussian 
ensemble, i.e. where each element is drawn from a gaussian distribution.
Use the [Mersenne Twister random number generator](https://www.cplusplus.com/reference/random/mt19937/).
Here a simple example of it:
```
#include <random>

void foo() {
    mt19937 gen(42); // 42 is seed
    normal_distribution dist(1., 0.);
    double r = dist(gen); // draw a random number
}
```
The function signature should be
```
Matrix gaussianMatrix(size_t dim);
```
Run the following code and count the number of allocations, deallocationos and memory copies
```
    Matrix R = gaussianMatrix(100);
    Matrix A(R);
    Matrix B = A;
```
Now implement a move assignment operator and move constructor
and count again. Note that move semantics can help to write
simple, yet efficient copy constructors.

The matrix class now obeys the rule of five. Remember that implementing
the rule of five is only required if the class manually manages it's 
own memory.
This is one of the main reasons why only a few (ideally a single) base-classes
should manage memory directly. High-level routines can use classes like 
std::vector or rely on other library classes as wrappers for the pointers.

How would the Matrix class look like if it was built based on std::vector?
In which ways can Matrix be based on std::vector in C++? What are advantages
and disadvantes associated with the different implementations and with using
std::vector in general?