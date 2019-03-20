
void back_substitution(int N, double** mtx, double* x, double* b) {
	for (int row = N - 1; row >= 0; row--) {
		double subTerm = 0;
		for (int column = row + 1; column <N; column++) {
			subTerm += (mtx[row][column] * x[column]);
		}
		x[row] = (b[row] - subTerm) / mtx[row][row];
	}
}

void Gaussisan_elimination(int N, double** mtx, double* b,double* x) {
	
	for (int row = 0; row < N-1; row++) {
		int column,pivotRow;
		column = pivotRow = row;
		//find out pivot row
		double max = mtx[row][column];
		for (int curRow = row; curRow < N; curRow++) {
			if (max < mtx[curRow][column]) {
				pivotRow = curRow;
				max = mtx[curRow][column];
			}
		}
		//pivoting 2 row (including matrix A and vector b)
		if (pivotRow != row) {
			double* tempRow;
			tempRow = mtx[row];
			mtx[row] = mtx[pivotRow];
			mtx[pivotRow] = tempRow;

			double tempb = b[row];
			b[row] = b[pivotRow];
			b[pivotRow] = tempb;
		}

		//elimination
		for (int curRow = row + 1; curRow < N; curRow++) {
			double ratio = mtx[curRow][column] / max;
			mtx[curRow][column] = 0.0;
			for (int curColumn = column + 1; curColumn < N;curColumn++) {
				mtx[curRow][curColumn] -= ratio*mtx[row][curColumn];
			}
			b[curRow] -= ratio*b[row];
			
		}
	}
	back_substitution(N, mtx, x, b);
}
