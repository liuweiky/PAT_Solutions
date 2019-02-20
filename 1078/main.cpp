#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAX_N 10240

using namespace std;

int M, N;

int pos[MAX_N];
bool table[MAX_N];

bool is_prime(int k)
{
    if (k < 2)
        return false;
    int ksqrt = sqrt(k);
    for (int i = 2; i <= ksqrt; i++)
        if (k % i == 0)
            return false;
    return true;
}

int main()
{
    fill_n(table, MAX_N, false);
    scanf("%d", &M);
    while (!is_prime(M))
        M++;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        int p;
        int d = 0;
        while (d < M)
        {
            p = (t % M + d * d) % M;
            if (!table[p])
                break;
            d++;
        }
        if (d < M)
        {
            pos[i] = p;
            table[p] = true;
        } else
            pos[i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(" ");
        if (pos[i] == -1)
            printf("-");
        else
            printf("%d", pos[i]);
    }
    return 0;
}
