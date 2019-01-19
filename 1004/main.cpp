#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int N, M;
vector<int> tree[MAX_N];
int level_nodes[MAX_N];
int max_level = 1;

void dfs(int r, int level)
{
    max_level = max(level, max_level);

    if (tree[r].size() == 0)
    {
        level_nodes[level]++;
        return;
    }

    for (int i = 0; i < tree[r].size(); i++)
    {
        dfs(tree[r][i], level + 1);
    }
}

int main()
{
    fill_n(level_nodes, MAX_N, 0);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int id, k;
        scanf("%d %d", &id, &k);

        for (int j = 0; j < k; j++)
        {
            int c;
            scanf("%d", &c);
            tree[id].push_back(c);
        }
    }

    dfs(1, 1);

    for (int i = 1; i <= max_level; i++)
    {
        printf("%d", level_nodes[i]);
        if (i != max_level)
            printf(" ");
    }

    return 0;
}
