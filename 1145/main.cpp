#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

#define MAX_M 20000

using namespace std;

int MSize, N, M;
int table[MAX_M];
set<int> connot_inst;

bool is_prime(int p)
{
    if (p < 2)
        return false;
    int sqrtp = sqrt(p);

    for (int i = 2; i <= sqrtp; i++)
        if (p % i == 0)
            return false;

    return true;
}

int find_int(int t)
{
    int k = 0;

    while (k <= MSize && table[((t % MSize) + k * k) % MSize] != t && table[((t % MSize) + k * k) % MSize] != -1)
        k++;
    return k == MSize + 1 ? k : k + 1;
}

int main()
{
    scanf("%d %d %d", &MSize, &N, &M);

    while (!is_prime(MSize))
        MSize++;

    fill_n(table, MSize, -1);

    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        int k = 0;
        while (k <= MSize - 1)
        {
            int d = ((t % MSize) + k * k) % MSize;
            if (table[d] == -1)
            {
                table[d] = t;
                break;
            }
            k++;
        }
        if (k == MSize)
        {
            printf("%d cannot be inserted.\n", t);
            connot_inst.insert(t);
        }
    }

    int cnt = 0;
    int m = M;
    while (m--)
    {
        int t;
        scanf("%d", &t);
        cnt += find_int(t);
        //printf("%d\n", cnt);
    }

    printf("%.1f", (double)cnt / M);

    return 0;
}
