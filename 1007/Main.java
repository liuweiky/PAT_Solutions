import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int K = scanner.nextInt();
		int[] f = new int[K];
		int[] dp = new int[K];
		for (int i = 0; i < K; i++) {
			f[i] = scanner.nextInt();
		}
		dp[K-1] = f[K-1];
		for (int i = K-2; i >= 0; i--) {
			// dp: 从 i 出发的最大值
			// f: 第 i 个值
			// 动态规划，递推关系式，向前处理
			// 状态转移方程: dp[i] = max(f[i], f[i] + dp[i + 1])
			dp[i] = Math.max(f[i], f[i] + dp[i + 1]);
		}
		int maxIndex = 0;
		for (int i = 0; i < K; i++) {
			if (dp[maxIndex] < dp[i])
				maxIndex = i;
		}
		int sum = 0;
		int endIndex = maxIndex;
		for (int i = maxIndex; ; i++) {
			sum += f[i];
			if (sum == dp[maxIndex]) {
				endIndex = i;
				break;
			}
		}
		
		System.out.print(dp[maxIndex] + " " + f[maxIndex] + " " + f[endIndex]);
	}
}
