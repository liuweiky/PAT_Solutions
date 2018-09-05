import java.util.Scanner;

public class Main {
	static int red, green, blue;
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		red = scanner.nextInt();
		green = scanner.nextInt();
		blue = scanner.nextInt();
		String r13 = Integer.toString(red, 13);
		String g13 = Integer.toString(green, 13);
		String b13 = Integer.toString(blue, 13);
		if (r13.length() < 2)
			r13 = "0" + r13;
		if (g13.length() < 2)
			g13 = "0" + g13;
		if (b13.length() < 2)
			b13 = "0" + b13;
		System.out.println("#" + r13.toUpperCase() + g13.toUpperCase() + b13.toUpperCase());
	}
}
