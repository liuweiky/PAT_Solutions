import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		List<BetItem> list = new ArrayList<BetItem>();
		for (int i = 0; i < 3; i++) {
			list.add(new BetItem(scanner.nextDouble(), scanner.nextDouble(), scanner.nextDouble()));
		}
		double maxProfit = 1;
		for (int i = 0; i < 3; i++) {
			maxProfit *= list.get(i).getMaxProfit();
			System.out.print(list.get(i).getBestBet() + " ");
		}
		System.out.print(String.format("%.2f", (maxProfit*0.65 - 1) * 2));
	}
}

class BetItem {
	double W, T, L;

	public BetItem(double w, double t, double l) {
		super();
		W = w;
		T = t;
		L = l;
	}
	
	public String getBestBet() {
		double max = W;
		if (T > max)
			max = T;
		if (L > max)
			max = L;
		if (max == W)
			return "W";
		if (max == T)
			return "T";
		return "L";
	}
	
	public double getMaxProfit() {
		double max = W;
		if (T > max)
			max = T;
		if (L > max)
			max = L;
		return max;
	}
}