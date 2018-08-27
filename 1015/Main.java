import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		List<String> answer = new LinkedList<String>();
		Scanner scanner = new Scanner(System.in);
		int N, D;
		while ((N = scanner.nextInt()) > 0) {
			D = scanner.nextInt();
			boolean isPrime = true;
			for (int i = 2; i * i <= N; i++) {
				if (N % i == 0) {
					isPrime = false;
					break;
				}
			}
			if (!isPrime || N == 1) {
				answer.add("No");
				continue;
			}
			String NS = Integer.toString(N, D);
			NS = new StringBuilder(NS).reverse().toString();
			int NR = Integer.parseInt(NS, D);
			isPrime = true;
			for (int i = 2; i * i <= NR; i++) {
				if (NR % i == 0) {
					isPrime = false;
					break;
				}
			}
			answer.add(isPrime && N != 1 ? "Yes" : "No");
		}
		for (String a : answer)
			System.out.println(a);
	}
}
