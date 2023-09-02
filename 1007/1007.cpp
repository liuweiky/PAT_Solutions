#include <cstdio>
#include <utility>

#define MAX_N 10240

using namespace std;

int K;
int seq[MAX_N];
pair<int, int> dp[MAX_N];

int main()
{
    scanf("%d", &K);
    bool all_neg = true;

    for (int i = 0; i < K; i++)
    {
        scanf("%d", &seq[i]);
        dp[i].first = i;
        dp[i].second = seq[i];
        if (seq[i] >= 0)
        {
            all_neg = false;
        }
    }

    if (all_neg)
    {
        printf("0 %d %d", seq[0], seq[K - 1]);
        return 0;
    }

    for (int i = 1; i < K; i++)
    {
        int sum = seq[i];
        int max_sum = sum;
        int max_index = i;
        for (int j = i - 1; j >= dp[i - 1].first; j--)
        {
            sum += seq[j];
            if (sum > max_sum)
            {
                max_sum = sum;
                max_index = j;
            }
        }
        dp[i].first = max_index;
        dp[i].second = max_sum;
    }

    int maxx = dp[0].second;
    int maxx_idx = 0;

    for (int i = 1; i < K; i++)
    {
        if (maxx < dp[i].second)
        {
            maxx = dp[i].second;
            maxx_idx = i;
        }
    }

    printf("%d %d %d", dp[maxx_idx].second, seq[dp[maxx_idx].first], seq[maxx_idx]);

    return 0;
}
