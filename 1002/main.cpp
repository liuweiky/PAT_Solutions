#include <cstdio>
#include <algorithm>

#define MAX_N 10240

using namespace std;

double poly[MAX_N];
int max_e = 0;

int K;

int main()
{
    fill(poly, poly + MAX_N, 0.0);

    for (int j = 0; j < 2; j++)
    {
        scanf("%d", &K);

        for (int i = 0; i < K; i++)
        {
            int e;
            double c;
            scanf("%d %lf", &e, &c);
            poly[e] += c;
            max_e = max(e, max_e);
        }
    }

    int non_zero_max_e = 0;
    int non_zero_cnt = 0;

    for (int e = 0; e <= max_e; e++)
    {
        if (poly[e] != 0)
        {
            non_zero_cnt++;
            non_zero_max_e = e;
        }
    }

    printf("%d", non_zero_cnt);

    for (int i = non_zero_max_e; i >= 0; i--)
    {
        if (poly[i] != 0)
            printf(" %d %.1f", i, poly[i]);
    }

    return 0;
}
