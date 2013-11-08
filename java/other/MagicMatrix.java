package other;

public class MagicMatrix {
	public static final int N = 5;
	public static void main(String[] args) {
		int[] matrix = new int[N*N];  //一维数组模拟二维坐标系
		int y, x, number;
		y = 0;
		x = N>>1;
		matrix[y*N + x] = 1;		//第一个数字放中间
		for (number = 2; number <= matrix.length; number++) {
			if (matrix[(((y-1+N)%N)*N + ((x+1)%N))] == 0) {
				//右上角位置没有放入数字
				y = (y-1+N)%N;
				x = (x+1)%N;
			} else
				//右上角已有数字则填充下面
				y = (y+1)%N;
			matrix[y*N + x] = number;
		}
		printMatrix(matrix);
	}	
	static void printMatrix(int[] arr) {
		for (int i = 0, len = arr.length; i < len; i++) {
			System.out.printf("%-4d  %s", arr[i], (i % N == N-1) ? "\n" : "");
		}
	}
}
