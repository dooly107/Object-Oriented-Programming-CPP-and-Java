public class Main {
	public static void main(String[] args) {
		Matrix mymatrix = new Matrix(10000);
		mymatrix.fill(10000);
		long starttime = System.nanoTime();
		try{
			MatrixMultiplication Thread1 = new MatrixMultiplication(20,1,0);
			Thread1.start();
			Thread1.join();
		}catch(Exception e){};
		long diff = System.nanoTime() - starttime;
		System.out.format("Execution time for one thread is %d ns.\n",diff);

		
		starttime = System.nanoTime();
		try{
			MatrixMultiplication Thread2 = new MatrixMultiplication(20,2,0);
			MatrixMultiplication Thread3 = new MatrixMultiplication(20,2,1);
			Thread2.start();
			Thread3.start();
			Thread2.join();
			Thread3.join();
		}catch(Exception e){};
		diff = System.nanoTime() - starttime;
		System.out.format("Execution time for two threads is %d ns.\n",diff);

		
		starttime = System.nanoTime();
		try{
			MatrixMultiplication Thread4 = new MatrixMultiplication(20,4,0);
			MatrixMultiplication Thread5 = new MatrixMultiplication(20,4,1);
			MatrixMultiplication Thread6 = new MatrixMultiplication(20,4,2);
			MatrixMultiplication Thread7 = new MatrixMultiplication(20,4,3);
			Thread4.start();
			Thread5.start();
			Thread6.start();
			Thread7.start();
			Thread4.join();
			Thread5.join();
			Thread6.join();
			Thread7.join();
		}catch(Exception e){};
		diff = System.nanoTime() - starttime;
		System.out.format("Execution time for four threads is %d ns.\n",diff);

	}
}
