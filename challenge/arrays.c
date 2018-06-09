#include "defs.h"

my_prec *CREATE_ARRAY(const unsigned int a){
	// Creates a pointer v of aelements of size/precision my_prec
	// defined in defs.h
	my_prec *v = (my_prec*) malloc( a * sizeof(my_prec) );
	// If it cannot be allocated then return NULL. Remember NULL
	// is the default initialized value for a pointer.
	if (!v) return NULL;
	// Print some help to free memory adequately
	printf("\n\nARRAYS:: To free memory please use free(ArrayVar)\n\n\n");
	return v;
};

my_prec **CREATE_MATRIX(const unsigned int a,const unsigned int b){
	// We create a "pointer" of pointers to my_prec* with the 
	// number of rows. i.e. an array of pointers to the "first" element
	// in each row of the matrix
	my_prec **v = (my_prec**) malloc(a * sizeof(my_prec*));

	// Creates a pointer v of a*b elements of size/precision my_prec
	// defined in defs.h that represents the total number of items in
	// the matrix.
	v[0] = (my_prec*) malloc(a * b * sizeof(my_prec));
	// What are we doing? To create a contiguous memory matrix
	// it is often a good idea to first create an array with all 
	// the elements and then "convert" it to a matrix. So we need
	// the pointer of the first element to point to the array
	// of all ements!

	// This may present memory leaks!!

	// If they cannot be allocated then return NULL. Remember NULL
	// is the default initialized value for a pointer.
	if (!v) return NULL;

	// Now we assign accordingly pointers to each element
	// look at v[j-1]+b! Any questions?
	for( int j = 1; j < a; j++ )
		v[j] = v[j-1] + b;
	// Print some help to free memory adequately
	printf("\n\nARRAYS:: To avoid memory leaks, free memory via a 2-step proc:\n");
	printf("\tfree(ArrayVar[0]);\n\tfree(ArrayVar), dataMatrix = NULL;\n\n\n");
	return v;
};

/* Copy Matrix Code
 * Copy all elements from matrix A to B
*/
void CopyMatrix(my_prec **A, my_prec **B, unsigned int rows, unsigned int cols)
{
        int j,k;
        for( j=0; j<rows; j++)
        {
                for( k=0; k<cols; k++)
                {
                        B[j][k] = A[j][k];
                }
        }
}

void gaussRed(my_prec **outMat, unsigned int m, unsigned int n)
{
	double t;
	int i,j,k,h,l;
	for(h=0;h<m;h++)
	{
		for (i=h;i<m;i++)
		{
			t=outMat[i][h];
			for (j=0;j<n;j++)
			{
				outMat[i][j]/=t;/* Paso 1*/
			}
		}
			for(k=h+1;k<m;k++)
			{
				for(l=h;l<n;l++)
				{
					outMat[k][l]-=outMat[h][l];
				}
			}
	}
}

void gaussJordan(my_prec **mat, unsigned int m, unsigned int n)
{
    gaussRed(mat,m,n);

    double t;
    int h,i,j;
    for(h=m-1;h>=0;h--)
    {
        for(i=h;i>=0;i--)
        {
            t=mat[i-1][h];
            for(j=0;j<n;j++)
            {
                mat[i-1][j]+=(-t)*mat[h][j];
            }
        }
    }
}


// Q: Can you draw a map of how the memory is allocated in memory?
