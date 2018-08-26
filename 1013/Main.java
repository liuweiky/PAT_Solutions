import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] strings = br.readLine().split(" ");
		int N = Integer.parseInt(strings[0]);
		int M = Integer.parseInt(strings[1]);
		int K = Integer.parseInt(strings[2]);
		int[][] graph = new int[N+1][N+1];
		for (int i = 0; i < M; i++) {
			strings = br.readLine().split(" ");
			int s = Integer.parseInt(strings[0]);
			int t = Integer.parseInt(strings[1]);
			graph[s][t] = 1;
			graph[t][s] = 1;
		}
		int[] concern = new int[K];
		strings = br.readLine().split(" ");
		for (int i = 0; i < K; i++) {
			concern[i] = Integer.parseInt(strings[i]);
		}
		for (int c : concern) {
			int[] visit = new int[N+1];
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
