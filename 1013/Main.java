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
			
			int[] visit = new int[N+1];
			for (int i = 0; i <= N; i++) {
				visit[i] = 0;
			}
			int component = 0;
			while (hasUnvisited(visit, N)) {
				for (int i = 1; i <= N; i++) {
					if (visit[i] == 0) {
						component++;
						dfs(i, g, visit, N);
						break;
					}
				}
			}
			System.out.println(component - 1 - 1);
		}
	}
	
	public static void dfs(int v, int[][] g, int[] visit, int N) {
		visit[v] = 1;
		for (int i = 1; i <= N; i++) {
			if (g[v][i] == 1 && visit[i] == 0) {
				dfs(i, g, visit, N);
			}
		}
	}
	
	public static boolean hasUnvisited(int[] visit, int N) {
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0)
				return true;
		}
		return false;
	}
}
