#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

#define MAX_N 512

using namespace std;

int factors[MAX_N];
int ans[MAX_N];

int N, K, P;
int sum_factors = INT_MIN;

bool flag = false;

void dfs(int max_f, int fac_sum, int sum, int j)
{
    if (j > K)
    {
        if (sum == N)
        {
            flag = true;
            if (fac_sum > sum_factors)
            {
                sum_factors = fac_sum;
                memcpy(ans, factors, (K + 1) * sizeof(int));
            }
        }
        return;
    }

    for (int i = max_f; i >= 1; i--)
    {
        int s = sum + pow(i, P);
        if (s <= N)
        {
            factors[j] = i;
            dfs(i, fac_sum + i, s, j + 1);
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &K, &P);

    int max_f = 1;

    while (pow(max_f, P) <= N - K + 1)
        max_f++;

    max_f--;

    dfs(max_f, 0, 0, 1);

    if (flag)
    {
        printf("%d =", N);
        for (int i = 1; i <= K; i++)
        {
            if (i != 1)
                printf(" +");
            printf(" %d^%d", ans[i], P);
        }
    }
    else
        printf("Impossible");

    return 0;
}
