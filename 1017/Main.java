import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Main {
	static int BEGIN = 8 * 60 *60;
	static int END = 17 * 60 * 60 + 1;
	public static void main(String[] args) throws Exception {
		List<Customer> customers = new LinkedList<Customer>();
		List<Window> windows = new LinkedList<Window>();
		int N, K;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inLine = br.readLine();
		N = Integer.parseInt(inLine.split(" ")[0]);
		K = Integer.parseInt(inLine.split(" ")[1]);
		for (int i = 0; i < K; i++) {
			windows.add(new Window());
		}
		for (int i = 0; i < N; i++) {
			inLine = br.readLine();
			customers.add(new Customer(inLine.split(" ")[0], Integer.parseInt(inLine.split(" ")[1])));
		}
		Collections.sort(customers);
		int totalWaitTime = 0;
		int servedNum = 0;
		for (Customer c : customers) {
			if (c.arrivingTimeTag >= END)
				break;
			servedNum++;
			if (c.arrivingTimeTag <= BEGIN) {
				totalWaitTime += (BEGIN - c.arrivingTimeTag);
				c.arrivingTimeTag = BEGIN;
			}
			int firstFree = 0;
			int firstFreeTime = windows.get(0).currentCustomer == null ?
								BEGIN :
								windows.get(0).currentCustomer.processingTime * 60 + windows.get(0).lastFinishTime;
			for (int j = 1; j < K; j++) {
				int tmpTime = windows.get(j).currentCustomer == null ? 
							BEGIN :
							windows.get(j).currentCustomer.processingTime * 60 + windows.get(j).lastFinishTime;
				if (tmpTime < firstFreeTime) {
					firstFreeTime = tmpTime;
					firstFree = j;
				}
			}
			if (firstFreeTime < c.arrivingTimeTag) {
				windows.get(firstFree).lastFinishTime = c.arrivingTimeTag;
			} else {
				windows.get(firstFree).lastFinishTime = firstFreeTime;
				totalWaitTime += (firstFreeTime - c.arrivingTimeTag);
			}
			windows.get(firstFree).currentCustomer = c;
		}
		System.out.printf("%.1f", (double)totalWaitTime / (double)servedNum / 60.0);
	}
}

class Customer implements Comparable<Customer> {
	int arrivingTimeTag;
	int processingTime;
	public Customer(String aTime, int pTime) {
		processingTime = pTime;
		String[] times = aTime.split(":");
		arrivingTimeTag = 
				Integer.parseInt(times[0]) * 60 * 60
				+ Integer.parseInt(times[1]) * 60
				+ Integer.parseInt(times[2]);
	}
	@Override
	public int compareTo(Customer arg0) {
		// TODO Auto-generated method stub
		return arrivingTimeTag - arg0.arrivingTimeTag;
	}
}

class Window {
	Customer currentCustomer = null;
	int lastFinishTime = Main.BEGIN;
}