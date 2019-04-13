#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

#define MAX_ID 10240

using namespace std;

struct edge
{
    int s, t;
    int get_hash() {return s * MAX_ID + t;}
};

struct hnode
{
    int v, d;
    bool operator < (const hnode& rhs) const
    {
        return d > rhs.d;
    }
};

int N, K;
vector<edge> edges;
vector<int> graph[MAX_ID];
map<int, int> mp;

bool vis[MAX_ID];
int dis[MAX_ID];
vector<int> path[MAX_ID];
vector<int> ans;
int ans_trans = -1;

void add_edge(int s, int t, int line)
{
    edge e1, e2;
    e1.s = e2.t = s;
    e1.t = e2.s = t;
    edges.push_back(e1);
    graph[s].push_back(edges.size() - 1);
    edges.push_back(e2);
    graph[t].push_back(edges.size() - 1);
    mp[e1.get_hash()] = mp[e2.get_hash()] = line;
}

void dijkstra(int s)
{

    for (int i = 0; i < MAX_ID; i++)
    {
        vis[i] = false;
        path[i].clear();
        dis[i] = INT_MAX;
    }

    priority_queue<hnode> q;
    hnode n;
    n.v = s;
    n.d = 0;
    q.push(n);
    dis[s] = 0;

    while (!q.empty())
    {
        n = q.top();
        q.pop();

        if (vis[n.v])
            continue;
        vis[n.v] = true;

        for (int i = 0; i < graph[n.v].size(); i++)
        {
            edge e = edges[graph[n.v][i]];
            if (!vis[e.t] && dis[e.t] > n.d + 1)
            {
                path[e.t].clear();
                path[e.t].push_back(n.v);
                dis[e.t] = n.d + 1;

                hnode nn;

                nn.v = e.t;
                nn.d = dis[e.t];
                q.push(nn);
            }
            else if (!vis[e.t] && dis[e.t] == n.d + 1)
                path[e.t].push_back(n.v);
        }
    }
}

void dfs(int u, int s, vector<int>& ps, int trans)
{
    if (u == s)
    {
        if (ans.size() == 0 || trans < ans_trans)
        {
            ans = ps;
            ans_trans = trans;
            return;
        }
    }

    for (int i = 0; i < path[u].size(); i++)
    {
        int v = path[u][i];
        ps.push_back(v);
        if (ps.size() >= 3)
        {
            int sz = ps.size();
            edge e1, e2;
            e1.s = ps[sz - 3];
            e1.t = ps[sz - 2];
            e2.s = ps[sz - 2];
            e2.t = ps[sz - 1];
            if (mp[e1.get_hash()] != mp[e2.get_hash()])
                dfs(v, s, ps, trans + 1);
            else
                dfs(v, s, ps, trans);
        }
        else
            dfs(v, s, ps, trans);
        ps.pop_back();
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int m;
        scanf("%d", &m);
        int prev = -1;
        while (m--)
        {
            int t;
            scanf("%d", &t);
            if (prev == -1)
            {
                prev = t;
                continue;
            }
            add_edge(prev, t, i);
            prev = t;
        }
    }

    scanf("%d", &K);

    while (K--)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        dijkstra(s);
        vector<int> tmp;
        tmp.push_back(t);
        ans.clear();
        dfs(t, s, tmp, 0);
        printf("%d\n", ans.size() - 1);

        reverse(ans.begin(), ans.end());

        edge e;
        int startp = ans[0], endp = ans[1];
        e.s = startp;
        e.t = endp;
        int last_line = mp[e.get_hash()];

        for (int i = 2; i < ans.size(); i++)
        {
            e.s = ans[i - 1];
            e.t = ans[i];

            if (mp[e.get_hash()] != last_line)
            {
                printf("Take Line#%d from %04d to %04d.\n", last_line, startp, endp);
                startp = ans[i - 1];
                endp = ans[i];
                last_line = mp[e.get_hash()];
            }
            else
                endp = ans[i];
        }
        printf("Take Line#%d from %04d to %04d.\n", last_line, startp, endp);
    }

    return 0;
}
