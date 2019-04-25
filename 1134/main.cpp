#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <set>

#define MAX_N 10240

using namespace std;

int N, M, K;

map<pair<int, int> , int> edge_id;
vector<int> adj[MAX_N];

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        edge_id[make_pair(s, t)] = edge_id[make_pair(t, s)] = i;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    scanf("%d", &K);

    while (K--)
    {
        set<int> edges;
        int nv, v;
        scanf("%d", &nv);
        while (nv--)
        {
            scanf("%d", &v);
            for (int i = 0; i < adj[v].size(); i++)
            {
                int e = edge_id[make_pair(v, adj[v][i])];
                edges.insert(e);
            }
        }
        if (edges.size() == M)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
