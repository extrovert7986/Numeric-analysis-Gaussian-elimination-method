#pragma once

double** allocate_square_matrix(int N);
void free_matrix(int N, double** mtx);
void print_matrix(int N, double** mtx, double* x, double* b);
