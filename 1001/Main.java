import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int a, b;
		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		b = scanner.nextInt();
		int c = a + b;
		StringBuilder cs = new StringBuilder(String.valueOf(c));
		for (int i = cs.length() - 3; i >= 0; i-=3) {
			if (!((i == 0) || cs.charAt(0) == '-' && i == 1)) {
				cs.insert(i, ',');
			}
		}
		System.out.println(cs);
	}
}
