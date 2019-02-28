#include <cstdio>
#include <algorithm>
#include <climits>
#include <cctype>

#define MAX_GRAPH_SIZE 1024

using namespace std;

int graph[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
int N, M, K, DS;

int dis[MAX_GRAPH_SIZE];
bool visit[MAX_GRAPH_SIZE];

void dijkstra(int u)
{
    fill_n(dis, MAX_GRAPH_SIZE, INT_MAX);
    fill_n(visit, MAX_GRAPH_SIZE, false);

    dis[u] = 0;

    for (int i = 0; i < N + M - 1; i++)
    {
        visit[u] = true;
        for (int j = 1; j <= N + M; j++)
        {
            if (!visit[j] && graph[u][j] > 0 && dis[j] > dis[u] + graph[u][j])
                dis[j] = dis[u] + graph[u][j];
        }
        int min_dis = INT_MAX;
        int v = -1;
        for (int j = 1; j <= N + M; j++)
        {
            if (!visit[j] && dis[j] < min_dis)
            {
                v = j;
                min_dis = dis[j];
            }
        }
        if (v == -1)
            return;
        u = v;
    }
}

int main()
{
    scanf("%d %d %d %d", &N, &M, &K, &DS);

    for (int i = 0; i < K; i++)
    {
        char sbuf[8], tbuf[8];
        int s, t, d;
        scanf("%s %s %d", sbuf, tbuf, &d);

        if (isalpha(sbuf[0]))
        {
            sscanf(sbuf + 1, "%d", &s);
            s += N;
        }
        else
            sscanf(sbuf, "%d", &s);

        if (isalpha(tbuf[0]))
        {
            sscanf(tbuf + 1, "%d", &t);
            t += N;
        }
        else
            sscanf(tbuf, "%d", &t);

        graph[s][t] = graph[t][s] = d;
    }

    int best_station = -1;
    int max_min_dis = INT_MIN;
    int min_avg_dis = INT_MAX;

    for (int i = N + 1; i <= N + M; i++)
    {
        dijkstra(i);
        bool feasible = true;
        int min_dis = INT_MAX;
        int avg_dis = 0;
        for (int j = 1; j <= N; j++)
        {
            if (dis[j] > DS)
            {
                feasible = false;
                break;
            }
            avg_dis += dis[j];
            min_dis = min(min_dis, dis[j]);
        }
        if (feasible)
        {
            if (max_min_dis < min_dis)
            {
                max_min_dis = min_dis;
                min_avg_dis = avg_dis;
                best_station = i;
            }
            else if (max_min_dis == min_dis && min_avg_dis > avg_dis)
            {
                min_avg_dis = avg_dis;
                best_station = i;
            }
        }
    }

    if (best_station == -1)
        printf("No Solution");
    else
    {
        printf("G%d\n%.1f %.1f", best_station - N, (double) max_min_dis, (double) min_avg_dis / N);
    }

    return 0;
}
