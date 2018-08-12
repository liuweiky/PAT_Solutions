import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		List<Record> records = new ArrayList<Record>();
		Scanner scanner = new Scanner(System.in);
		int M = scanner.nextInt();
		for (int i = 0; i < M; i++) {
			Record record = new Record(scanner.next(), scanner.next(), scanner.next());
			records.add(record);
		}
		
		Record unlock, lock;
		unlock = records.get(0);
		lock = records.get(0);
		for (Record r : records) {
			if (unlock.signInTime > r.signInTime)
				unlock = r;
			if (lock.signOutTime < r.signOutTime) {
				lock = r;
			}
		}
		
		System.out.println(unlock.id + " " + lock.id);
	}
}

class Record {
	String id;
	int signInTime = 0;
	int signOutTime = 0;
	public Record(String id, String signInStr, String signOutStr) {
		this.id = id;

		String[] in = signInStr.split(":");
		for (int i = 0; i < in.length; i++) {
			signInTime += Integer.parseInt(in[in.length - 1 - i]) * Math.pow(60, i);
		}
		
		String[] out = signOutStr.split(":");
		for (int i = 0; i < out.length; i++) {
			signOutTime += Integer.parseInt(out[out.length - 1 - i]) * Math.pow(60, i);
		}
	}
}