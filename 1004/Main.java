import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Node[] nodes = new Node[128];
		int[] levelNoChildNum = new int[128];
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		for (int i = 0; i < 128; i++) {
			nodes[i] = new Node(i);
			levelNoChildNum[i] = 0;
		}
		
		for (int i = 0; i < M; i++) {
			int id = scanner.nextInt();
			int k = scanner.nextInt();
			nodes[id].childNum = k;
			for (int j = 0; j < k; j++) {
				nodes[id].childs.add(scanner.nextInt());
			}
		}
		
		DFS(nodes, 1, 0, levelNoChildNum);
		for (int i = 0; i <= max_depth; i++) {
			System.out.print(levelNoChildNum[i]);
			if (i != max_depth)
				System.out.print(" ");
		}
	}
	
	public static int max_depth = 0;
	
	public static void DFS(Node[] nodes, int id, int level, int[] levelNoChildNum) {
		if (level > max_depth)
			max_depth = level;
		Node node = nodes[id];
		if (node.childNum == 0)
			levelNoChildNum[level] += 1;
		for (Integer i : node.childs ) {
			DFS(nodes, i, level + 1, levelNoChildNum);
		}
	}
}


class Node {
	int childNum = 0;
	List<Integer> childs = new ArrayList<Integer>();
	int id;
	public Node(int id) {
		super();
		this.id = id;
	}
}