#include"Matrix.h"
#include"Vector.h"
#include"HillbertMatrix.h"
#include"DirectedMethod.h"
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

void print_matrix(int N, double** mtx, double* x, double* b);

void main() {
	double** hillbertMtx = allocate_square_matrix(SIZE);
	double* b = allocate_vector(SIZE);
	double* x = allocate_vector(SIZE);
	create_hillbert_matrix(SIZE, hillbertMtx, b);
	print_matrix(SIZE, hillbertMtx, x, b);
	printf("-----------------------------------\n");
	Gaussisan_elimination(SIZE, hillbertMtx, b, x);
	print_matrix(SIZE, hillbertMtx, x, b);

	free_matrix(SIZE,hillbertMtx);
	free(x);
	free(b);
	system("pause");
}

