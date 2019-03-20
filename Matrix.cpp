#include<stdlib.h>
#include<stdio.h>
double** allocate_square_matrix(int N) {
	double** mtx = (double**)calloc(N, sizeof(double*));
	for (int i = 0; i < N; i++) {
		mtx[i] = (double*)calloc(N, sizeof(double));
	}
	return mtx;
}

void free_matrix(int N, double** mtx) {
	for (int row = 0; row < N; row++) {
		free(mtx[row]);
	}
	free(mtx);
}

void print_matrix(int N, double** mtx, double* x, double* b) {
	printf("Ax = b\n");
	for (int row = 0; row < N; row++) {
		if (row == N / 2) {
			//print each row of A
			printf("[");
			for (int col = 0; col < N; col++) {
				if (col == N - 1)printf("% .2lf", mtx[row][col]);
				else printf("% .2lf ", mtx[row][col]);
			}
			printf(" ]");
			//print element in x at row
			printf("[% .2lf ]", x[row]);
			printf(" = ");
			//print element in b at row
			printf("[% .2lf ]", b[row]);
		}
		else {
			printf(" ");
			for (int col = 0; col < N; col++) {
				printf("% .2lf ", mtx[row][col]);
			}
			//print element in x at row
			printf("  % .2lf ", x[row]);
			printf("    ");
			//print element in b at row
			printf(" % .2lf ", b[row]);
		}
		printf("\n");
	}
}