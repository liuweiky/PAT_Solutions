#include <cstdio>
#include <algorithm>

#define MAX_N 10240

using namespace std;

double poly[MAX_N];
double tmp_poly[MAX_N];

int main()
{
    fill_n(poly, MAX_N, 0);
    int k;
    int max_e = -1;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int e;
        double c;
        scanf("%d %lf", &e, &c);
        max_e = max(max_e, e);
        tmp_poly[e] = c;
    }
    scanf("%d", &k);
    int new_max_e = max_e;
    for (int i = 0; i < k; i++)
    {
        int e;
        double c;
        scanf("%d %lf", &e, &c);
        for (int j = 0; j <= max_e; j++)
        {
            double new_c = c * tmp_poly[j];
            poly[j + e] += new_c;
            new_max_e = max(new_max_e, j + e);
        }
    }

    while (poly[new_max_e] == 0)
        new_max_e--;

    int non_zero_cnt = 0;

    for (int i = new_max_e; i >= 0; i--)
        if (poly[i] != 0)
            non_zero_cnt++;
    printf("%d", non_zero_cnt);

    for (int i = new_max_e; i >= 0; i--)
        if (poly[i] != 0)
            printf(" %d %.1f", i, poly[i]);

    return 0;
}
