#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int N, M, C1, C2;
int graph[MAX_N][MAX_N];
int res[MAX_N];
vector<int> path[MAX_N];

int max_team = 0;
int path_cnt = 0;

void dijkstra(int v)
{
    int visit[MAX_N];
    int dis[MAX_N];

    fill_n(visit, MAX_N, 0);
    fill_n(dis, MAX_N, INT_MAX);
    dis[v] = 0;
    visit[v] = 1;

    int u = v;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[j] == 0 && graph[u][j] > 0 && dis[j] > dis[u] + graph[u][j])
            {
                path[j].clear();
                path[j].push_back(u);
                dis[j] = dis[u] + graph[u][j];
            } else if (visit[j] == 0 && graph[u][j] > 0 && dis[j] == dis[u] + graph[u][j])
            {
                path[j].push_back(u);
            }
        }

        int min_dis = INT_MAX;
        for (int j = 0; j < N; j++)
        {
            if (visit[j] == 0 && dis[j] < min_dis)
            {
                min_dis = dis[j];
                u = j;
            }
        }
        visit[u] = 1;
    }
}

void backtrack(int u, int team)
{
    team += res[u];
    if (u == C1)
    {
        if (team > max_team)
            max_team = team;
        path_cnt++;
        return;
    }
    for (int i = 0; i < path[u].size(); i++)
    {
        backtrack(path[u][i], team);
    }
}

int main()
{
    scanf("%d %d %d %d", &N, &M, &C1, &C2);

    for (int i = 0; i < N; i++)
        scanf("%d", &res[i]);

    fill_n(&graph[0][0], MAX_N * MAX_N, -1);

    for (int i = 0; i < M; i++)
    {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        graph[s][t] = d;
        graph[t][s] = d;
    }

    dijkstra(C1);

    backtrack(C2, 0);

    printf("%d %d", path_cnt, max_team);

    return 0;
}
