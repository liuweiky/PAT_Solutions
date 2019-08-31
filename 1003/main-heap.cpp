#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 512

using namespace std;

struct edge
{
	int s, t, d;
	edge(int _s, int _t, int _d) : s(_s), t(_t), d(_d) {}
};

struct prio_node
{
	int s, d;
	bool operator < (const prio_node& rhs) const
	{
		return d > rhs.d;
	}
};

int N, M, C1, C2;
int team[MAX_N];
vector<edge> edges;
vector<int> graph[MAX_N];
int dis[MAX_N];
vector<int> path[MAX_N];
bool vis[MAX_N];

int max_t = 0;
int pcnt = 0;

void add_edge(int s, int t, int d)
{
	edge e1(s, t, d);
	edges.push_back(e1);
	graph[s].push_back(edges.size() - 1);

	edge e2(t, s, d);
	edges.push_back(e2);
	graph[t].push_back(edges.size() - 1);
}

void dijkstra(int u)
{
	fill_n(vis, MAX_N, false);
	fill_n(dis, MAX_N, INT_MAX);

	dis[u] = 0;

	priority_queue<prio_node> q;
	prio_node n;
	n.s = u;
	n.d = 0;
	q.push(n);

	while (!q.empty())
	{
		prio_node p = q.top();
		q.pop();

		if (vis[p.s])
			continue;

		vis[p.s] = true;

		for (int i = 0; i < graph[p.s].size(); i++)
		{
			edge e = edges[graph[p.s][i]];
			if (dis[e.t] > dis[e.s] + e.d)
			{
				dis[e.t] = dis[e.s] + e.d;
				path[e.t].clear();
				path[e.t].push_back(e.s);

				prio_node t;
				t.d = dis[e.t];
				t.s = e.t;
				q.push(t);
			}
			else if (dis[e.t] == dis[e.s] + e.d)
				path[e.t].push_back(e.s);
		}
	}
}

void dfs(int s, int ts)
{
	ts += team[s];
	if (s == C1)
	{
		pcnt++;
		max_t = max(max_t, ts);
		return;
	}

	for (int i = 0; i < path[s].size(); i++)
		dfs(path[s][i], ts);
}

int main()
{
	scanf("%d %d %d %d", &N, &M, &C1, &C2);

	for (int i = 0; i < N; i++)
		scanf("%d", &team[i]);

	for (int i = 0; i < M; i++)
	{
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		add_edge(s, t, d);
	}

	dijkstra(C1);

	dfs(C2, 0);

	printf("%d %d", pcnt, max_t);
	
	return 0;
}
