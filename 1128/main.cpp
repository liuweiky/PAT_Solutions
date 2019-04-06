#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int pos[MAX_N];
int K, N;

int main()
{
    scanf("%d", &K);

L1:
    while (K--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &pos[i]);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;
                if (pos[i] == pos[j] || abs(i - j) == abs(pos[i] - pos[j]))
                {
                    printf("NO\n");
                    goto L1;
                }
            }
        }
        printf("YES\n");
    }

    return 0;
}
