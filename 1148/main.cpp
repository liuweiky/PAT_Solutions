#include <cstdio>

#define MAX_N 128

using namespace std;

int statement[MAX_N];
int N;

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &statement[i]);

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int liars = 0;
            int wolf_liars = 0;

            for (int k = 1; k <= N; k++)
            {
                int s = statement[k];
                if (s > 0)
                {
                    if (s == i || s == j)
                    {
                        liars++;
                        if (k == i || k == j)
                            wolf_liars++;
                    }
                }
                else
                {
                    s = -s;
                    if (s != i && s != j)
                    {
                        liars++;
                        if (k == i || k == j)
                            wolf_liars++;
                    }
                }
            }

            if (wolf_liars == 1 && liars == 2)
            {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("No Solution");

    return 0;
}
