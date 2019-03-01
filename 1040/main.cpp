#include <cstdio>

#define MAX_LEN 1024

using namespace std;

char str[MAX_LEN];
bool dp[MAX_LEN][MAX_LEN];
int len = 0;

int main()
{
    while (scanf("%c", &str[len++]) != EOF);

    int max_len = 1;

    for (int i = 0; i < len; i++)
    {
        dp[i][i] = true;
        if (i != len - 1 && str[i] == str[i + 1])
        {
            dp[i][i + 1] = true;
            max_len = 2;
        }
    }


    for (int i = 2; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            int s = j, t = j + i;
            if (dp[s + 1][t - 1] && str[s] == str[t])
            {
                dp[s][t] = true;
                max_len = i + 1;
            }
            else
                dp[s][t] = false;
        }
    }

    printf("%d", max_len);
    return 0;
}
