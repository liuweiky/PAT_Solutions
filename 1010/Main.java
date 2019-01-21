import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// 任意进制转十进制
		// Integer.parseInt(String number, radix)
		// System.out.println(Integer.parseInt("AB", 16));
		// BigInteger 处理大数
		// new BigInteger(String number. radix)
		// System.out.println(toDecimal("ab", 16));
		Scanner scanner = new Scanner(System.in);
		String astr = scanner.next();
		String bstr = scanner.next();
		int tag = scanner.nextInt();
		long radix = scanner.nextInt();
		long a;
		if (tag == 2) {
			String c = astr;
			astr = bstr;
			bstr = c;
		}
		a = toDecimal(astr, radix);
		long low = getMinRadix(bstr);
		long high = Math.max(a + 1, low);
		while (low <= high) {
			long mid = (low + high) / 2;
			if (a == toDecimal(bstr, mid))
			{
				System.out.print(mid);
				return ;
			} else if (a < toDecimal(bstr, mid)){
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		System.out.print("Impossible");
	}
	
	public static long toDecimal(String num, long radix) {
		long a = 0;
		for (int i = 0; i < num.length(); i++) {
			char c = num.charAt(num.length() - 1 - i);
			if (c >= '0' && c <= '9') {
				a += (c - '0') * Math.pow(radix, i);
			} else {
				a += (c - 'a' + 10) * Math.pow(radix, i);
			}
		}
		return a;
	}
	
	// 参考 https://blog.csdn.net/baidu_25107219/article/details/46700669
	// 需要考虑特殊情况，如 12 c 1 10
	// 进制至少要比出现的最大 digit 大 1
	public static long getMinRadix(String num) {
		int minRadix = 1;
		for (int i = 0; i < num.length(); i++) {
			char c = num.charAt(i);
			if (c >= '0' && c <= '9') {
				int r = c - '0';
				if (minRadix < r)
					minRadix = r;
			} else {
				int r = c - 'a' + 10;
				if (minRadix < r)
					minRadix = r;
			}
		}
		return minRadix + 1;
	}
}
