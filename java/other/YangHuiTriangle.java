package other;

public class YangHuiTriangle {
	public static final int ROW = 10;
	public static void main(String[] args) {
		int[][] array = new int[ROW][];
		for (int i = 0; i < ROW; i++) 
			array[i] = new int[i+1];
		
		array[0][0] = 1;
		for (int i = 1; i < ROW; i++){
			array[i][0] = 1; 		// first value in every row
			for (int j=1; j < i; j++)
				array[i][j]=array[i-1][j-1]+array[i-1][j];		//
			array[i][i] = 1;		// last value in every row
		}
		print(array);
	}
	static void print(int[][] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++)
				System.out.printf("%4d", arr[i][j]);
			System.out.println();
		}
	}
}
