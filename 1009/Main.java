import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Poli a = new Poli();
		Poli b = new Poli();
		Poli c = new Poli();
		Scanner scanner = new Scanner(System.in);
		int k = scanner.nextInt();
		for (int i = 0; i < k; i++) {
			PoliItem item = new PoliItem(scanner.nextInt(), scanner.nextDouble());
			a.add(item);
		}
		int l = scanner.nextInt();
		for (int i = 0; i < l; i++) {
			PoliItem item = new PoliItem(scanner.nextInt(), scanner.nextDouble());
			b.add(item);
		}
		for (int i = 0; i < a.items.size(); i++) {
			for (int j = 0; j < b.items.size(); j++) {
				PoliItem item = PoliItem.mult(a.items.get(i), b.items.get(j));
				c.add(item);
			}
		}
		c.show();
	}
}

class Poli{
	List<PoliItem> items = new LinkedList<PoliItem>();
	
	public void add(PoliItem item) {
		int k = -1;
		for (int i = 0; i < items.size(); i++) {
			if (items.get(i).exponent == item.exponent) {
				k = i;
				items.get(i).coefficient += item.coefficient;
				if (items.get(i).coefficient == 0)
					items.remove(i);
			}
		}
		if (k == -1)
			items.add(new PoliItem(item.exponent, item.coefficient));
	}
	
	public void show() {
		Collections.sort(items);
		System.out.print(items.size());
		for (PoliItem i : items) {
			System.out.print(" " + i.exponent);
			System.out.print(" " + String.format("%.1f", i.coefficient));
		}
	}
}

class PoliItem implements Comparable<PoliItem>{
	
	public static PoliItem mult(PoliItem a, PoliItem b) {
		return new PoliItem(a.exponent + b.exponent, a.coefficient * b.coefficient);
	}
	
	int exponent;
	double coefficient;
	public PoliItem(int exponent, double coefficient) {
		super();
		this.exponent = exponent;
		this.coefficient = coefficient;
	}
	
	@Override
	public int compareTo(PoliItem arg0) {
		// TODO Auto-generated method stub
		return arg0.exponent - this.exponent;
	}
	
	
}