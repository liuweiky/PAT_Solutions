import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		List<Student> list = new ArrayList<Student>();
		String[] courses = {"A", "C", "M", "E"};
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		for (int i = 0; i < n; i++) {
			list.add(new Student(scanner.next(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt()));
		}
		String[] query = new String[m];
		for (int i = 0; i < m; i++) {
			query[i] = scanner.next();
		}
		List<Student> copyListA = new ArrayList<Student>();
		copyListA.addAll(list);
		Collections.sort(copyListA, new AComparator());
		
		List<Student> copyListC = new ArrayList<Student>();
		copyListC.addAll(list);
		Collections.sort(copyListC, new CComparator());
		
		List<Student> copyListM = new ArrayList<Student>();
		copyListM.addAll(list);
		Collections.sort(copyListM, new MComparator());
		
		List<Student> copyListE = new ArrayList<Student>();
		copyListE.addAll(list);
		Collections.sort(copyListE, new EComparator());
		
		for (String q : query) {
			boolean contain = false;
			for (Student s : list) {
				if (s.id.equals(q)) {
					contain = true;
					int[] order = new int[4];
					for (int i = 0; i < n; i++) {
						if (copyListA.get(i).id.equals(q)) {
							order[0] = i + 1;
							break;
						}
					}
					for (int i = 0; i < n; i++) {
						if (copyListC.get(i).id.equals(q)) {
							order[1] = i + 1;
							break;
						}
					}
					for (int i = 0; i < n; i++) {
						if (copyListM.get(i).id.equals(q)) {
							order[2] = i + 1;
							break;
						}
					}
					for (int i = 0; i < n; i++) {
						if (copyListE.get(i).id.equals(q)) {
							order[3] = i + 1;
							break;
						}
					}
					int min = order[0];
					int minIndex = 0;
					for (int i = 1; i < 4; i++) {
						if (order[i] < min) {
							min = order[i];
							minIndex = i;
						}
					}
					System.out.println(min + " " + courses[minIndex]);
					break;
				}
			}
			if (!contain)
				System.out.println("N/A");
		}
	}
}

class Student {
	
	String id;
	int A, C, M, E;
	public Student(String id, int c, int m, int e) {
		super();
		this.id = id;
		C = c;
		M = m;
		E = e;
		A = (C + M + E) / 3;
	}
	
}

class AComparator implements Comparator<Student> {

	@Override
	public int compare(Student arg0, Student arg1) {
		// TODO Auto-generated method stub
		return arg1.A - arg0.A;
	}
	
}

class CComparator implements Comparator<Student> {

	@Override
	public int compare(Student arg0, Student arg1) {
		// TODO Auto-generated method stub
		return arg1.C - arg0.C;
	}
	
}

class MComparator implements Comparator<Student> {

	@Override
	public int compare(Student arg0, Student arg1) {
		// TODO Auto-generated method stub
		return arg1.M - arg0.M;
	}
	
}

class EComparator implements Comparator<Student> {

	@Override
	public int compare(Student arg0, Student arg1) {
		// TODO Auto-generated method stub
		return arg1.E - arg0.E;
	}
	
}