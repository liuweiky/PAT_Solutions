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
			if (!isPrime(N)) {
				answer.add("No");
				continue;
			}
			String NS = Integer.toString(N, D);
			NS = new StringBuilder(NS).reverse().toString();
			int NR = Integer.parseInt(NS, D);
			answer.add(isPrime(NR) ? "Yes" : "No");
		}
		for (String a : answer)
			System.out.println(a);
	}
	
	public static boolean isPrime(int n) {
		if (n < 2)
			return false;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
}
