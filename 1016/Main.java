import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
	static int[] toll = new int[24];
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		for (int i = 0; i < 24; i++)
			toll[i] = scanner.nextInt();
		int N = scanner.nextInt();
		List<Record> records = new ArrayList<Record>();
		scanner.nextLine();
		for (int i = 0; i < N; i++)
			records.add(new Record(scanner.nextLine()));
		Collections.sort(records);
//		for (Record record : records) {
//			System.out.println(record.userName + " " + record.date + " " + record.hour + ":" + record.minute + " " +record.timeTagFromDay1);
//		}
		int[] paired = new int[N];
		List<ValidCall> validCalls = new ArrayList<ValidCall>();
		List<MinDisObj> minDisObjs = new ArrayList<MinDisObj>();
		for (int i = 0; i < N; i++) {
			Record record = records.get(i);
			Record targetRecord = null;
			int from = i, to = -1;
			if (record.state == Record.ONLINE) {
				int minDis = Integer.MAX_VALUE;
				for (int j = i + 1; j < N; j++) {
					Record record2 = records.get(j);
					if (record2.state == Record.OFFLINE && record2.userName.equals(record.userName)) {
						int dis = record2.timeTagFromDay1 - record.timeTagFromDay1;
						if (dis < minDis) {
							minDis = dis;
//							System.out.println(minDis);
							targetRecord = record2;
							to = j;
						}
					}
				}
				if (minDis != Integer.MAX_VALUE) {
					minDisObjs.add(new MinDisObj(minDis, from, to));
				}
			}
		}
		
		Collections.sort(minDisObjs);
		
		for (MinDisObj obj : minDisObjs) {
			if (paired[obj.from] == 0 && paired[obj.to] == 0) {
				paired[obj.from] = 1; paired[obj.to] = 1;
				validCalls.add(new ValidCall(records.get(obj.from), records.get(obj.to)));
			}
		}
		
//		for (ValidCall v : validCalls) {
//			System.out.print(v.from.userName + " " + v.from.date + " " + v.from.hour + ":" + v.from.minute + " - ");
//			System.out.println(v.to.userName + " " + v.to.date + " " + v.to.hour + ":" + v.to.minute);
//		}
		
		List<OutBill> outBills = new ArrayList<OutBill>();
		
		for (String name : Record.nameSet) {
			OutBill outBill = new OutBill(name);
			for (ValidCall validCall : validCalls) {
				if (name.equals(validCall.from.userName))
					outBill.validCalls.add(validCall);
			}
			outBills.add(outBill);
		}
		Collections.sort(outBills);
		for (OutBill outBill : outBills) {
			System.out.println(outBill.userName + " " + outBill.validCalls.get(0).from.month);
			int totalCharge = 0;
			Collections.sort(outBill.validCalls);
			for (ValidCall validCall : outBill.validCalls) {
				int charge = 0;
				int day = Integer.parseInt(validCall.from.date);
				int hour = Integer.parseInt(validCall.from.hour);
				int minute = Integer.parseInt(validCall.from.minute);
				for (int i = validCall.from.timeTagFromDay1 + 1; i <= validCall.to.timeTagFromDay1; i++) {
					charge += toll[hour];
					minute += 1;
					if (minute == 60) {
						minute = 0;
						hour += 1;
						if (hour == 24) {
							minute = 0;
							hour = 0;
							day +=1;
						}
					}
				}
				totalCharge += charge;
				System.out.println(validCall.from.date + ":" + validCall.from.hour + ":" + validCall.from.minute
						+ " " + validCall.to.date + ":" + validCall.to.hour + ":" + validCall.to.minute
						+ " " + (validCall.to.timeTagFromDay1 - validCall.from.timeTagFromDay1)
						+ " $" + String.format("%.2f", charge / 100.0));
			}
			System.out.println("Total amount: $" + String.format("%.2f", totalCharge / 100.0));
		}
	}
}

class Record implements Comparable<Record> {
	static Set<String> nameSet = new HashSet<String>();
	static final int ONLINE = 1;
	static final int OFFLINE = 0;
	String userName;
	int timeTagFromDay1;
	String month;
	String date;
	String hour;
	String minute;
	int state;
	public Record(String inString) {
		String[] sp = inString.split(" ");
		userName = sp[0];
		nameSet.add(userName);
		String[] timeString = sp[1].split(":");
		month = timeString[0];
		date = timeString[1];
		hour = timeString[2];
		minute = timeString[3];
		timeTagFromDay1 = Integer.parseInt(date) * 24 * 60 + Integer.parseInt(hour) * 60 + Integer.parseInt(minute);
		state = sp[2].equals("on-line") ? ONLINE : OFFLINE;
	}
	@Override
	public int compareTo(Record arg0) {
		// TODO Auto-generated method stub
		return timeTagFromDay1 - arg0.timeTagFromDay1;
	}
	
}

class ValidCall implements Comparable<ValidCall>{
	Record from, to;
	public ValidCall(Record f, Record t) {
		from = f; to = t;
	}
	@Override
	public int compareTo(ValidCall arg0) {
		// TODO Auto-generated method stub
		return from.timeTagFromDay1 - arg0.from.timeTagFromDay1;
	}
}

class MinDisObj implements Comparable<MinDisObj>{
	int timeDis;
	int from, to;
	public MinDisObj(int d, int f, int t) {
		timeDis = d; from = f; to = t;
	}
	@Override
	public int compareTo(MinDisObj arg0) {
		// TODO Auto-generated method stub
		return timeDis - arg0.timeDis;
	}
}

class OutBill implements Comparable<OutBill>{
	String userName;
	List<ValidCall> validCalls;
	public OutBill(String userName) {
		this.userName = userName;
		validCalls = new ArrayList<ValidCall>();
	}
	@Override
	public int compareTo(OutBill arg0) {
		// TODO Auto-generated method stub
		return userName.compareTo(arg0.userName);
	}
}