import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int K = scanner.nextInt();
		int[][] graph = new int[N+1][N+1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				graph[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++) {
			int s = scanner.nextInt();
			int t = scanner.nextInt();
			graph[s][t] = 1;
			graph[t][s] = 1;
		}
		int[] concern = new int[K];
		for (int i = 0; i < K; i++) {
			concern[i] = scanner.nextInt();
		}
		for (int c : concern) {
			int[][] g = new int[N+1][N+1];
			for (int i = 0; i <= N; i++) {
				for (int j = 0; j <= N; j++) {
					g[i][j] = graph[i][j];
				}
			}
			for (int i = 0; i <= N; i++) {
				g[c][i] = 0;
				g[i][c] = 0;
			}
			int count = 0;
			for (int i = 0; i <= N; i++) {
				for (int j = 0; j <= N; j++) {
					if (g[i][j] == 1)
						count++;
				}
			}
			int d = N - 2 - count / 2;
			if (d < 0)
				System.out.println(0);
			else
				System.out.println(d);
		}
	}
}
