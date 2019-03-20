#include<stdlib.h>

double* allocate_vector(int N) {
	double* b = (double*)calloc(N, sizeof(double));
	return b;
}
