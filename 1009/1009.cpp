#include <cstdio>
#include <algorithm>

#define MAX_N 2048

using namespace std;

double A[MAX_N];
double B[MAX_N];
double C[MAX_N];

int main()
{
    fill_n(C, MAX_N, 0);
    int K, max_nonzero_a = 0, max_nonzero_b = 0, max_nonzero_c = 0;

    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int exp;
        double coeff;
        scanf("%d %lf", &exp, &coeff);
        A[exp] = coeff;
        max_nonzero_a = max(max_nonzero_a, exp);
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int exp;
        double coeff;
        scanf("%d %lf", &exp, &coeff);
        B[exp] = coeff;
        max_nonzero_b = max(max_nonzero_b, exp);
    }

    for (int i = 0; i <= max_nonzero_a; i++)
    {
        for (int j = 0; j <= max_nonzero_b; j++)
        {
            double coeff = A[i] * B[j];
            int exp = i + j;
            C[exp] += coeff;
        }
    }

    int non_zero_k = 0;

    for (int i = 0; i < MAX_N; i++)
    {
        if (C[i] != 0)
        {
            non_zero_k++;
        }
    }

    printf("%d", non_zero_k);

    for (int i = MAX_N - 1; i >= 0; i--)
    {
        if (C[i] != 0)
        {
            printf(" %d %.1f", i, C[i]);
        }
    }

    return 0;
}
