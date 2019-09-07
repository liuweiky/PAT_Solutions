import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		BigInteger A, B, C;
		
		for (int i = 1; i <= T; i++) {
			String tmp = scanner.next();
			A = new BigInteger(tmp);
			tmp = scanner.next();
			B = new BigInteger(tmp);
			tmp = scanner.next();
			C = new BigInteger(tmp);
			
			if (A.add(B).compareTo(C) == 1)
				System.out.println("Case #" + i + ": true");
			else
				System.out.println("Case #" + i + ": false");
		}
	}
}
