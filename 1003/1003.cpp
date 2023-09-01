#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 512

using namespace std;

struct edge
{
    int s, t, d;
    edge(int _s, int _t, int _d): s(_s), t(_t), d(_d) {}
};

struct prio_node
{
    int u, d;
    prio_node(int _u, int _d): u(_u), d(_d) {}
    bool operator < (const prio_node& n) const
    {
        return d > n.d;
    }
};

int N, M, C1, C2;
int teams[MAX_N];
vector<edge> edges;
vector<int> graph[MAX_N];
vector<int> path[MAX_N];
int dis[MAX_N];
bool vis[MAX_N];

int path_num = 0;
int max_team = 0;

void add_edge(int s, int t, int d)
{
    edge e(s, t, d);
    edges.push_back(e);
    graph[s].push_back(edges.size() - 1);
}

void dijkstra()
{
    priority_queue<prio_node> q;
    q.push(prio_node(C1, 0));

    dis[C1] = 0;

    while (!q.empty())
    {
        prio_node n = q.top();
        q.pop();

        if (vis[n.u])
        {
            continue;
        }

        vis[n.u] = true;

        for (int i = 0; i < graph[n.u].size(); i++)
        {
            edge& e = edges[graph[n.u][i]];
            if (dis[e.t] > dis[n.u] + e.d)
            {
                dis[e.t] = dis[n.u] + e.d;
                path[e.t].clear();
                path[e.t].push_back(n.u);
                q.push(prio_node(e.t, dis[e.t]));
            }
            else if (dis[e.t] == dis[n.u] + e.d)
            {
                path[e.t].push_back(n.u);
            }
        }
    }
}

void dfs(int k, int t)
{
    t += teams[k];
    if (k == C1)
    {
        path_num++;
        max_team = max(max_team, t);
        return;
    }

    for (int i = 0; i < path[k].size(); i++)
    {
        dfs(path[k][i], t);
    }
}

int main()
{
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(vis, MAX_N, false);
    scanf("%d %d %d %d", &N, &M, &C1, &C2);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &teams[i]);
    }

    for (int i = 0; i < M; i++)
    {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        add_edge(s, t, d);
        add_edge(t, s, d);
    }

    dijkstra();
    dfs(C2, 0);

    printf("%d %d", path_num, max_team);
    return 0;
}
