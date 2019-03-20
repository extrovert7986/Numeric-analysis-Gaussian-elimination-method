
void create_hillbert_matrix(int N, double** mtx,double *b) {
	for (int row = 0; row < N; row++) {
		b[row] = 0.0;
		for (int col = 0; col < N; col++) {
			mtx[row][col] = 1.0 / (row + col + 1);
			b[row] += mtx[row][col];
		}
	}
}