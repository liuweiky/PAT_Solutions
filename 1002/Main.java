import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Poli poli = new Poli();
		Scanner scanner = new Scanner(System.in);
		int ak = scanner.nextInt();
		for (int i = 0; i < ak; i++) {
			int e = scanner.nextInt();
			double c = scanner.nextDouble();
			poli.addItem(c, e);
		}
		int bk = scanner.nextInt();
		for (int i = 0; i < bk; i++) {
			int e = scanner.nextInt();
			double c = scanner.nextDouble();
			poli.addItem(c, e);
		}
		
		poli.show();
	}
}

class PoliItem implements Comparable<PoliItem>{
	double coefficient;
	int exponent;
	
	public PoliItem(double coefficient, int exponent) {
		super();
		this.coefficient = coefficient;
		this.exponent = exponent;
	}

	@Override
	public int compareTo(PoliItem arg0) {
		// TODO Auto-generated method stub
		return arg0.exponent - this.exponent;
	}
	
	
}

class Poli {
	List<PoliItem> items = new ArrayList<PoliItem>();
	public void addItem(double c, int e) {
		int k = -1;
		
		for (int i = 0; i < items.size(); i++) {
			if (items.get(i).exponent == e) {
				k = i;
				items.get(i).coefficient += c;
				if (items.get(i).coefficient == 0) {
					items.remove(i);
				}
			}
		}
		
		if (k == -1) {
			PoliItem p = new PoliItem(c, e);
			items.add(p);
		}
	}
	
	public void show() {
		System.out.print(items.size());
		Collections.sort(items);
		for (PoliItem item : items) {
			System.out.print(" " + item.exponent);
			System.out.print(" " + item.coefficient);
		}
	}
}
