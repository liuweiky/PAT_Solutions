import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int N, M, K, Q;
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		K = scanner.nextInt();
		Q = scanner.nextInt();
		
		List<Customer> customers = new ArrayList<Customer>();
		for (int i = 0; i < K; i++)
			customers.add(new Customer(scanner.nextInt()));
		
		List<Integer> query = new ArrayList<Integer>();
		for (int i = 0; i < Q; i++)
			query.add(scanner.nextInt());
		
		Map<Integer, String> queryMap = new HashMap<Integer, String> ();
		
		Queue<Customer>[] qs = new LinkedList[M];
		for (int i = 0; i < M; i++)
			qs[i] = new LinkedList<Customer>();
		
		int[] endTime = new int[M];
		for (int i = 0; i < K; i++) {
			Customer customer = customers.get(i);
			int minQIndex = 0;
			for (int j = 1; j < M; j++) {
				if (qs[minQIndex].size() > qs[j].size())
					minQIndex = j;
			}
			if (qs[minQIndex].size() == N) {
				int minEndIndex = 0;
				for (int j = 1; j < M; j++) {
					if (endTime[minEndIndex] + qs[minEndIndex].peek().processingTime > endTime[j] + qs[j].peek().processingTime)
						minEndIndex = j;
				}
				endTime[minEndIndex] += qs[minEndIndex].peek().processingTime;
				qs[minEndIndex].poll();
				minQIndex = minEndIndex;
			}
			
			qs[minQIndex].add(customer);
			
			if (query.contains(i + 1)) {
				int realTime = 8 * 60 + endTime[minQIndex];
				for (Customer c : qs[minQIndex])
					realTime += c.processingTime;
				if (realTime > 17 * 60)
					queryMap.put(i + 1, "Sorry");
				else {
					int hour = realTime / 60;
					String hs = hour < 10 ? "0" + hour : "" + hour;
					int minute = realTime % 60;
					String ms = minute < 10 ? "0" + minute : "" + minute;
					queryMap.put(i + 1, hs + ":" + ms);
				}
			}
		}
		
		for (Integer i : query) {
			System.out.println(queryMap.get(i));
		}
	}
	
}

class Customer {
	int processingTime;
	public Customer(int t) {
		processingTime = t;
	}
}