#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 128

using namespace std;

vector<int> tree[MAX_N];
int level[MAX_N];

int N, M;

void dfs(int id, int lev)
{
    level[lev]++;
    for (int i = 0; i < tree[id].size(); i++)
        dfs(tree[id][i], lev + 1);
}

int main()
{
    fill_n(level, MAX_N, 0);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int id, k;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            int t;
            scanf("%d", &t);
            tree[id].push_back(t);
        }
    }

    dfs(1, 1);

    int max_gen = 1;
    int max_num = 1;

    for (int i = 1; i <= N; i++)
    {
        if (max_num < level[i])
        {
            max_num = level[i];
            max_gen = i;
        }
    }

    printf("%d %d", max_num, max_gen);

    return 0;
}
