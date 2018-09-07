#include <cstdio>
#include <climits>
#include <algorithm>
#include <stack>

#define MAX_N 512

using namespace std;

int dis[MAX_N], cost[MAX_N], path[MAX_N], visit[MAX_N];
int N, M, S, D;
int graph[MAX_N][MAX_N][2];

void dijkstra(int v)
{
    cost[v] = 0;
    dis[v] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        visit[v] = 1;
        for (int j = 0; j < N; j++)
        {
            if (visit[j] == 0 && graph[v][j][0] > 0 && dis[j] > dis[v] + graph[v][j][0])
            {
                dis[j] = dis[v] + graph[v][j][0];
                cost[j] = cost[v] + graph[v][j][1];
                path[j] = v;
            } else if (visit[j] == 0 && graph[v][j][0] > 0 && dis[j] == dis[v] + graph[v][j][0] && cost[j] > cost[v] + graph[v][j][1])
            {
                cost[j] = cost[v] + graph[v][j][1];
                path[j] = v;
            }
        }

        int min_dis = INT_MAX;

        for (int j = 0; j < N; j++)
        {
            if (visit[j] == 0 && dis[j] < min_dis)
            {
                min_dis = dis[j];
                v = j;
            }
        }
    }
}

void PrintPath(int k)
{
    stack<int> p;
    while (path[k] != -1)
    {
        p.push(k);
        k = path[k];
    }
    printf("%d ", S);
    while (!p.empty())
    {
        printf("%d ", p.top());
        p.pop();
    }
}

int main()
{
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(cost, MAX_N, INT_MAX);
    fill_n(path, MAX_N, -1);
    fill_n(visit, MAX_N, 0);
    fill_n(&graph[0][0][0], MAX_N * MAX_N * 2, -1);
    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0; i < M; i++)
    {
        int s, t, d, c;
        scanf("%d %d %d %d", &s, &t, &d, &c);
        graph[s][t][0] = d;
        graph[s][t][1] = c;
        graph[t][s][0] = d;
        graph[t][s][1] = c;
    }
    dijkstra(S);
    PrintPath(D);
    printf("%d %d", dis[D], cost[D]);
    return 0;
}
