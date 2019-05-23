#include <cstdio>
#include <map>
#include <vector>
#include <set>

#define MAX_N 102400

using namespace std;

set<int> incompatible[MAX_N];
int N, M;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        incompatible[s].insert(t);
        incompatible[t].insert(s);
    }

    for (int i = 0; i < M; i++)
    {
        int k;
        scanf("%d", &k);
        vector<int> good;
        while (k--)
        {
            int t;
            scanf("%d", &t);
            good.push_back(t);
        }
        bool can = true;
        for (int j = 0; j < good.size() && can; j++)
        {
            for (int k = j + 1; k < good.size() && can; k++)
            {
                if (incompatible[good[j]].find(good[k]) != incompatible[good[j]].end())
                    can = false;
            }
        }
        if (can)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
