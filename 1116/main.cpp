#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>

#define MAX_N 10240

using namespace std;

int rnk[MAX_N];
int N, K;
set<int> checked;

bool is_prime(int p)
{
    int sqrtp = sqrt(p);

    for (int i = 2; i <= sqrtp; i++)
        if (p % i == 0)
            return false;
    return true;
}

int main()
{
    fill_n(rnk, MAX_N, -1);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int id;
        scanf("%d", &id);
        rnk[id] = i;
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        int id;
        scanf("%d", &id);
        if (checked.find(id) != checked.end())
            printf("%04d: Checked\n", id);
        else if (rnk[id] == -1)
            printf("%04d: Are you kidding?\n", id);
        else
        {
            if (rnk[id] == 1)
                printf("%04d: Mystery Award\n", id);
            else if (is_prime(rnk[id]))
                printf("%04d: Minion\n", id);
            else
                printf("%04d: Chocolate\n", id);
            checked.insert(id);
        }
    }

    return 0;
}
