#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

char str[MAX_N];
int left_p_cnt[MAX_N];

int main()
{
    fill_n(str, MAX_N, '\0');
    fill_n(left_p_cnt, MAX_N, 0);

    char ch;
    int len = 0, pcnt = 0;

    while ((ch = getchar()) != EOF)
    {
        str[len] = ch;
        if (ch == 'P')
            pcnt++;
        left_p_cnt[len++] = pcnt;
    }

    int tcnt = 0;
    long long pat_cnt = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == 'T')
            tcnt++;
        else if (str[i] == 'A')
            pat_cnt += left_p_cnt[i] * tcnt;
    }

    printf("%lld", pat_cnt % 1000000007);

    return 0;
}
