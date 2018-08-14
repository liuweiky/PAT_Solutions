import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// 任意进制转十进制
		// Integer.parseInt(String number, radix)
		// System.out.println(Integer.parseInt("AB", 16));
		// BigInteger 处理大数
		// new BigInteger(String number. radix)
		Scanner scanner = new Scanner(System.in);
		String astr = scanner.next();
		String bstr = scanner.next();
		int tag = scanner.nextInt();
		int radix = scanner.nextInt();
		BigInteger a, b;
		boolean possible = false;
		if (tag == 1) {
			a = new BigInteger(astr, radix);
			int i = 2;
			for (; i <= 36; i++) {
				try {
					if (a.equals(new BigInteger(bstr, i))) {
						possible = true;
						break;
					}
				} catch (Exception e) {
					// TODO: handle exception
				}
			}
			if (possible)
				System.out.print(i);
			else 
				System.out.print("Impossible");
		} else {
			b = new BigInteger(bstr, radix);
			int i = 2;
			for (; i <= 36; i++) {
				try {
					if (b.equals(new BigInteger(astr, i))) {
						possible = true;
						break;
					}
				} catch (Exception e) {
					// TODO: handle exception
				}
			}
			if (possible)
				System.out.print(i);
			else 
				System.out.print("Impossible");
		}
	}
}
