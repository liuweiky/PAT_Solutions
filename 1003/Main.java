import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Graph graph = new Graph();
		graph.dijkstra();
	}
}

class Edge {
	int verAdj;
	int cost;
	Edge link = null;

	public Edge(int verAdj, int cost) {
		super();
		this.verAdj = verAdj;
		this.cost = cost;
	}
}

class Vertex {
	int verName;
	Edge adjacent = null;
	int teams;

	public Vertex(int verName, int teams) {
		super();
		this.verName = verName;
		this.teams = teams;
	}
}

class Graph {
	Vertex[] head;
	int v_num, e_num;
	int from, to;

	public Graph() {
		Scanner scanner = new Scanner(System.in);
		v_num = scanner.nextInt();
		e_num = scanner.nextInt();
		from = scanner.nextInt();
		to = scanner.nextInt();

		head = new Vertex[v_num];

		for (int i = 0; i < v_num; i++) {
			head[i] = new Vertex(i, scanner.nextInt());
		}

		for (int i = 0; i < e_num; i++) {
			int f = scanner.nextInt();
			int t = scanner.nextInt();
			int c = scanner.nextInt();
			Edge edge = new Edge(t, c);
			edge.link = head[f].adjacent;
			head[f].adjacent = edge;

			int tmp = f;
			f = t;
			t = tmp;
			edge = new Edge(t, c);
			edge.link = head[f].adjacent;
			head[f].adjacent = edge;
		}
	}

	public void dijkstra() {
		int[] visited = new int[v_num];
		int[] dis = new int[v_num];
		int[] path = new int[v_num];
		
		for (int i = 0; i < v_num; i++) {
			visited[i] = 0;
			dis[i] = Integer.MAX_VALUE;
			path[i] = -1;
		}
		
		dis[from] = 0;
		
		int u = from;
		
		for (int i = 0; i < v_num - 1; i++) {
			visited[u] = 1;
			Edge p = head[u].adjacent;
			while (p != null) {
				int j = p.verAdj;
				if (visited[j] == 0 &&
					dis[j] > dis[u] + p.cost) {
					dis[j] = dis[u] + p.cost;
					path[j] = u;
				}
				p = p.link;
			}
			
			int tmp_min = Integer.MAX_VALUE;
			
			for (int j = 0; j < v_num; j++) {
				if (visited[j] == 0 &&
					dis[j] < tmp_min) {
					tmp_min = dis[j];
					u = j;
				}
			}
			
		}
		
		List<Integer> list = new ArrayList<Integer>();
//		System.out.println(dis[to]);
//		for (int i = 0; i < v_num; i++) {
//			System.out.print(dis[i] + "\t");
//			System.out.print(path[i] + "\t");
//			System.out.println(visited[i]);
//		}
		generatePath(dis, dis[to], to, head[to].teams, list);
		int max_team = 0;
		for (int l : list)
			max_team = l > max_team ? l : max_team;
		System.out.println(list.size() + " " + max_team);
	}
	
	// 回溯
	// d: 最短路长度; t: 到达的终点; team: 路上的team数
	private void generatePath(int[] dis, int d, int t, int team, List<Integer> list) {
		if (t == from) {
			list.add(team);
			return;
		}
		
		Edge p = head[t].adjacent;
		
		while (p != null) {
			if (dis[p.verAdj] + p.cost == d) {
				generatePath(dis, d - p.cost, p.verAdj, team + head[p.verAdj].teams, list);
			}
			p = p.link;
		}
	}
}