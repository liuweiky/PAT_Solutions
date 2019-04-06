#include <cstdio>
#include <algorithm>

#define MAX_N 512

using namespace std;

int degree[MAX_N];
bool graph[MAX_N][MAX_N];
int N, M;
bool vis[MAX_N];

void dfs(int u)
{
    vis[u] = true;
    for (int i = 1; i <= N; i++)
        if (!vis[i] && graph[u][i])
            dfs(i);
}

int main()
{
    fill_n(degree, MAX_N, 0);
    fill_n(vis, MAX_N, false);
    fill_n(&graph[0][0], MAX_N * MAX_N, false);

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        degree[s]++;
        degree[t]++;
        graph[s][t] = graph[t][s] = true;
    }

    int odd = 0, even = 0;
    bool all_vis = true;
    dfs(1);
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
            all_vis = false;
        degree[i] % 2 == 0 ? even++ : odd++;
        printf("%d", degree[i]);
        if (i != N)
            printf(" ");
        else
            printf("\n");
    }

    if (!all_vis)
        printf("Non-Eulerian");
    else if (odd == 0)
        printf("Eulerian");
    else if (odd == 2)
        printf("Semi-Eulerian");
    else
        printf("Non-Eulerian");

    return 0;
}
