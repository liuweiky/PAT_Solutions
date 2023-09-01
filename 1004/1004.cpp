#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 128

using namespace std;

int N, M;

vector<int> tree[MAX_N];
int counter[MAX_N];
int max_depth = 0;

void dfs(int id, int level)
{
    max_depth = max(max_depth, level);
    if (tree[id].size() == 0)
    {
        counter[level]++;
    }

    for (int i = 0; i < tree[id].size(); i++)
    {
        dfs(tree[id][i], level + 1);
    }
}

int main()
{
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

    dfs(1, 0);

    for (int i = 0; i <= max_depth; i++)
    {
        if (i != 0)
        {
            printf(" ");
        }
        printf("%d", counter[i]);
    }

    return 0;
}
