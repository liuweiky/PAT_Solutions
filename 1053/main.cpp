#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 128

using namespace std;

int node_weight[MAX_N];

vector<int> tree[MAX_N];

int N, M;
long long S;

bool cmp(int id1, int id2)
{
    return node_weight[id1] > node_weight[id2];
}

void dfs(int id, vector<int> p)
{
    if (tree[id].size() == 0)
    {
        long long weight = 0;
        for (int i = 0; i < p.size(); i++)
            weight += node_weight[p[i]];
        if (weight == S)
        {
            for (int i = 0; i < p.size(); i++)
            {
                if (i != 0)
                    printf(" ");
                printf("%d", node_weight[p[i]]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 0; i < tree[id].size(); i++)
    {
        p.push_back(tree[id][i]);
        dfs(tree[id][i], p);
        p.pop_back();
    }
}

int main()
{
    scanf("%d %d %lld", &N, &M, &S);

    for (int i = 0; i < N; i++)
        scanf("%d", &node_weight[i]);

    for (int i = 0; i < M; i++)
    {
        int id, k, t;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &t);
            tree[id].push_back(t);
        }
        sort(tree[id].begin(), tree[id].end(), cmp);
    }

    vector<int> tmp_path;
    tmp_path.push_back(0);
    dfs(0, tmp_path);

    return 0;
}
