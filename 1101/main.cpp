#include <cstdio>
#include <climits>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int N;
int numbers[MAX_N];
int left_max[MAX_N];
int right_min[MAX_N];

int ans[MAX_N];

int main()
{
    scanf("%d", &N);

    int lmax = 0, rmin = INT_MAX, ans_cnt = 0;

    for (int i = 0; i < N; i++)
    {
        left_max[i] = lmax;
        scanf("%d", &numbers[i]);
        lmax = max(lmax, numbers[i]);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        right_min[i] = rmin;
        rmin = min(rmin, numbers[i]);
    }

    for (int i = 0; i < N; i++)
        if (left_max[i] <= numbers[i] && right_min[i] >= numbers[i])
            ans[ans_cnt++] = numbers[i];

    sort(ans, ans + ans_cnt);

    printf("%d\n", ans_cnt);

    for (int i = 0; i < ans_cnt; i++)
    {
        printf("%d", ans[i]);
        if (i != ans_cnt - 1)
            printf(" ");
    }

    printf("\n");   // it's necessary
    return 0;
}
