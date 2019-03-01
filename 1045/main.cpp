#include <cstdio>
#include <algorithm>
#include <climits>

#define MAX_COLOR_TYPE 256
#define MAX_STRIPE_LEN 10240

using namespace std;

int is_favourite[MAX_COLOR_TYPE];
int color_order[MAX_COLOR_TYPE];
int stripe[MAX_STRIPE_LEN];
int dp[MAX_STRIPE_LEN];

int N, M, L;
int VL;

bool ge(int color1, int color2)
{
    return color_order[color1] >= color_order[color2];
}

int main()
{
    fill_n(is_favourite, MAX_COLOR_TYPE, false);
    fill_n(color_order, MAX_COLOR_TYPE, INT_MAX);

    scanf("%d", &N);

    scanf("%d", &M);
    for (int i = 1; i <= M; i++)
    {
        int t;
        scanf("%d", &t);
        color_order[t] = i;
        is_favourite[t] = true;
    }

    scanf("%d", &L);

    VL = 0;

    for (int i = 0; i < L; i++)
    {
        int c;
        scanf("%d", &c);
        if (is_favourite[c])
            stripe[VL++] = c;
    }

    dp[0] = 1;

    for (int i = 1; i < VL; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (ge(stripe[i], stripe[j]))
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int max_len = 0;
    for (int i = 0; i < VL; i++)
        max_len = max(dp[i], max_len);

    printf("%d", max_len);

    return 0;
}
