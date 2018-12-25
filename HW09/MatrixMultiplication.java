public class MatrixMultiplication extends Thread {
	public int sizetot;
	public int lowb1;
	public int upb1;
	public int lowb2;
	public int upb2;
	
	public MatrixMultiplication(int size, int numThread, int index){
		sizetot = size;
		if (numThread == 1){
			lowb1 = 0;
			upb1 = size;
			lowb2 = 0;
			upb2 = size;
		}
		
		if (numThread == 2){
			if (index == 0) {
				lowb1 = 0;
				upb1 = size/2;
				lowb2 = 0;
				upb2 = size;
			}
			if (index == 1){
				lowb1 = size/2;
				upb1 = size;
				lowb2 = 0;
				upb2 = size;
			}
		}
		
		if (numThread == 4){
			if (index == 0) {
				lowb1 = 0;
				upb1 = size/2;
				lowb2 = 0;
				upb2 = size/2;
			}
			if (index == 1) {
				lowb1 = 0;
				upb1 = size/2;
				lowb2 = size/2;
				upb2 = size;
			}
			if (index == 2) {
				lowb1 = size/2;
				upb1 = size;
				lowb2 = 0;
				upb2 = size/2;
			}
			if (index == 3) {
				lowb1 = size/2;
				upb1 = size;
				lowb2 = size/2;
				upb2 = size;
			}
		}
	}
	
	public void run() {
		for (int a = lowb1; a < upb1; a++) {
			for (int b = lowb2; b < upb2; b++) {
				for (int c = 0; c < sizetot; c++) {
					Matrix.A[a][b] = Matrix.B[a][c] * Matrix.C[c][b];
				}
			}
		}
	}
}