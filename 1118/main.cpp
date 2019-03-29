#include <cstdio>
#include <algorithm>

#define MAX_N 10240

using namespace std;

int father[MAX_N];
int max_bid = -1;
int N, Q;

int find_father(int a)
{
    int f = a;
    while (father[f] >= 0)
        f = father[f];
    while (a != f)
    {
        int x = father[a];
        father[a] = f;
        a = x;
    }
    return f;
}

void un(int i, int j)
{
    father[i] += father[j];
    father[j] = i;
}

int main()
{
    fill_n(father, MAX_N, -1);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int k, b, first = -1;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &b);
            max_bid = max(max_bid, b);
            if (first == -1)
            {
                first = b;
                continue;
            }
            int ff = find_father(first);
            int fb = find_father(b);
            if (ff != fb)
                un(ff, fb);
        }
    }

    int tree_num = 0;
    for (int i = 1; i <= max_bid; i++)
        if (father[i] < 0)
            tree_num++;

    printf("%d %d\n", tree_num, max_bid);

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        int fs = find_father(s);
        int ft = find_father(t);
        if (fs == ft)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
