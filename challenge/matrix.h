// PYTHON FRIENDLY HEADER DECLARATION
#include "defs.h"
#include "arrays.h"
#include "timer.h"
#include "randn.h"

#define seed 7

void SetMatrixZero(my_prec **A,unsigned int rows, unsigned int cols);
void SetMatrixRandom(my_prec **A,unsigned int rows, unsigned int cols);
my_prec **treatMatrix(unsigned int samples, unsigned int size_X, unsigned int size_data);
void MatrixTranspose(my_prec **A, my_prec **T, unsigned int rows, unsigned int cols);
void MatrixMultiplication(my_prec **A, my_prec **B, my_prec **C, unsigned int r_A, unsigned int c_B, unsigned int rc);
void MatrixInversion(my_prec **M, my_prec **I, unsigned int dim);
