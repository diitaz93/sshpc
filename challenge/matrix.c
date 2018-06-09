#include "defs.h"
#include "arrays.h"
#include "timer.h"
#include "randn.h"

#define seed 7

void SetMatrixZero(my_prec **A,unsigned int rows, unsigned int cols){
	int j,k;
	for( j = 0; j < rows; j++ )
		for( k = 0; k < cols; k++ )
			A[j][k] = 0;
};

void SetMatrixRandom(my_prec **A,unsigned int rows, unsigned int cols){
	int j,k;
	for( j = 0; j < rows; j++ )
		for( k = 0; k < cols; k++ )
			A[j][k] = normal_rand();
};

// Matrix Transpose Code
// Calculates the transpose of A in T
void MatrixTranspose(my_prec **A, my_prec **T, unsigned int rows, unsigned int cols)
{
	// Temporal matrix T to store values during transposition
	CopyMatrix(A,T,rows,cols);
	int j,k;
	for( j=0; j<rows; j++)
	{
		for( k=0; k<cols; k++)
		{
			T[k][j] = A[j][k];
		}
	}
}
// Matrix Multiply Code

void MatrixMultiplication(my_prec **A, my_prec **B, my_prec **C, unsigned int r_A, unsigned int c_B, unsigned int rc)
{
	int i,j,k;
	for( i=0; i<r_A; i++)
	{
		for(j=0; j<c_B; j++)
		{
			for(k=0; k<rc; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
}
/* Matrix Inversion Code
 * Calculates the inverse matrix of M in I 
 * using Gauss Jordan elimination
*/

void MatrixInversion(my_prec **M, my_prec **I, unsigned int dim)
{
	int i,j;
	my_prec **A = CREATE_MATRIX(dim,2*dim);
	CopyMatrix(M,A,dim,dim);
	for(i = 0; i < dim; i++)
	{
		for(j = dim; j < 2*dim; j++)
		{
			if(i==(j-dim))
			{
				A[i][j] = 1.0;
			}
			else
			{
				A[i][j] = 0.0;
			}
		}
	}

	gaussRed(A,dim,2*dim);
	gaussJordan(A,dim,2*dim);
}

// Perform Linear Regression or find the optimizatino problem


// Collect R^2
// Compute p values
// Compute T test and F test


/*

	Python Friendly functions

*/
my_prec **treatMatrix(unsigned int samples, unsigned int size_X, unsigned int size_data){
	static int iter = 0;
	static SimpleTimer_t t;
	static my_prec **m;
	if(iter == 0)
	    srand(seed);
	if(iter % 2 == 0){
		m = CREATE_MATRIX(size_data,size_X);
		SimpleTimer_start( &t );
		SetMatrixRandom(m,size_data,size_X);
		// Collect stop time
		SimpleTimer_stop( &t );
		// Print duration
		printf("Create Matrix for Sample: %d -> ",iter/2+1);
		SimpleTimer_print( &t );

		iter++;
		return m;
	}
	printf("Destroying Matrix of Sample: %d\n",iter/2+1);
	iter++;
	free(m[0]);
	free(m), m = NULL;
	return NULL;
};
/*

	End of Python Friendly functions

*/
