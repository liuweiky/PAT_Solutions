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
			int[] visit = new int[N+1];
			for (int i = 0; i <= N; i++) {
				visit[i] = 0;
			}
			visit[c] = 1;
			int component = 0;	// 连通分量数目
			for (int i = 1; i <= N; i++) {
				if (visit[i] == 0) {
					component++;
					dfs(i, graph, visit, N);
				}
			}
			System.out.println(component - 1);	// 需要加入的边 = 连通分量数目 - 1
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
}
