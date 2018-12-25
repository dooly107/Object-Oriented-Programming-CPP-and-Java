import java.util.Scanner;
import java.util.Arrays;

public class Matrix extends Exception {
	public static int[][] A;
	public static int[][] B;
	public static int[][] C;
	public int D;

	public Matrix(int j) {
		D = j;
		A = new int[D][D];
		B = new int[D][D];
		C = new int[D][D];
	}
	
	public void fill(int N) {
		try {
			remainder(N);
			for (int i = 0; i < D; i++) {
				for (int j = 0; j < D; j++){
					B[i][j] = N;
					C[i][j] = N;
				}
			}
		}
		catch (Exception e){
			System.out.println("The integer given is not divisible by 2.");
			Scanner reader = new Scanner(System.in);
			System.out.println("Please re-enter the valid integer that is divisible by 2.");
			int j = reader.nextInt();
			fill(j);
		}
	}
	
	public static void remainder(int N) throws Exception {
		int rem = N % 2;
		if (rem == 1) throw new Exception();
	}
}