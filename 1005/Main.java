import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Map<Character, String> map = new HashMap<Character, String>();
		map.put('0', "zero");
		map.put('1', "one");
		map.put('2', "two");
		map.put('3', "three");
		map.put('4', "four");
		map.put('5', "five");
		map.put('6', "six");
		map.put('7', "seven");
		map.put('8', "eight");
		map.put('9', "nine");
		
		Scanner scanner = new Scanner(System.in);
		String digits = scanner.nextLine();
		int sum = 0;
		for (int i = 0; i < digits.length(); i++) {
			Character character = digits.charAt(i);
			sum += Integer.parseInt(character.toString());
		}
		String sumstr = String.valueOf(sum);
		for (int i = 0; i < sumstr.length(); i++) {
			System.out.print(map.get(sumstr.charAt(i)));
			if (i != sumstr.length() - 1)
				System.out.print(" ");
		}
	}
}
