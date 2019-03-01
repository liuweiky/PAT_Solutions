#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 10240
#define MAX_M 128

using namespace std;

int dp[MAX_M];
int dp01[MAX_N][MAX_M];

int N, M;
int coins[MAX_N];

vector<int> ans;

bool cmp(int k1, int k2)
{
    return k1 > k2;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &coins[i]);

    sort(coins + 1, coins + N + 1, cmp);

    for (int i = 1; i <= N; i++)
    {
        for(int m = M; m >= coins[i]; m--)
        {
            if (dp[m] <= dp[m - coins[i]] + coins[i])
            {
                dp[m] = dp[m - coins[i]] + coins[i];
                dp01[i][m] = true;
            }
        }
    }

    if (dp[M] != M)
    {
        printf("No Solution");
        return 0;
    }

    int tm = M, ti = N;

    while (tm > 0)
    {
        if (dp01[ti][tm])
        {
            ans.push_back(coins[ti]);
            tm -= coins[ti];
            ti--;
        }
        else
            ti--;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}
