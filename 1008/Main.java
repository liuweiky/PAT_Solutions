import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		List<Integer> list = new LinkedList<Integer>();
		int n = scanner.nextInt();
		for(int i = 0; i < n; i++)
			list.add(scanner.nextInt());
		int time = 0;
		int lastFloor = 0;
		for (Integer i : list) {
			if (lastFloor > i) {
				time += Math.abs(lastFloor - i) * 4;
			} else {
				time += Math.abs(lastFloor - i) * 6;
			}
			time += 5;
			lastFloor = i;
		}
		
		System.out.print(time);
	}
}
