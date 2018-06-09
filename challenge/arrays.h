my_prec *CREATE_ARRAY(const unsigned int a);
my_prec **CREATE_MATRIX(const unsigned int a,const unsigned int b);
void CopyMatrix(my_prec **A, my_prec **B, unsigned int rows, unsigned int cols);
void gaussRed(my_prec **outMat, unsigned int m, unsigned int n);
void gaussJordan(my_prec **mat, unsigned int m, unsigned int n);
