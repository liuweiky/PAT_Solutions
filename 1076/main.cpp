#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

#define MAX_N 1024

using namespace std;

int graph[MAX_N][MAX_N];
bool visit[MAX_N];
int forward_cnt;

int N, L, K;

void bfs(int u)
{
    queue<pair<int, int> > q;
    q.push(pair<int, int>(u, 0));
    visit[u] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int v = p.first;
        int level = p.second;
        if (level >= L)
            return;
        for (int i = 1; i <= N; i++)
        {
            if (!visit[i] && graph[v][i])
            {
                visit[i] = true;
                if (level >= 0 && level <= L - 1)
                    forward_cnt++;
                q.push(pair<int, int>(i, level + 1));
            }
        }
    }
}

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, 0);

    scanf("%d %d", &N, &L);

    for (int i = 1; i <= N; i++)
    {
        int mi;
        scanf("%d", &mi);

        for (int j = 0; j < mi; j++)
        {
            int p;
            scanf("%d", &p);
            graph[p][i] = 1;
        }
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        fill_n(visit, MAX_N, false);
        forward_cnt = 0;
        int p;
        scanf("%d", &p);
        bfs(p);
        printf("%d\n", forward_cnt);
    }

    return 0;
}
