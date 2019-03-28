#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 512

using namespace std;

int graphd[MAX_N][MAX_N];
int grapht[MAX_N][MAX_N];
int disd[MAX_N];
int dist[MAX_N];
bool vis[MAX_N];

int pathd[MAX_N];
vector<int> patht[MAX_N];

vector<int> ansd;
vector<int> anst;
int ans_dis, ans_tim;

int N, M, SRC, DEST;

void dijkstra_dis()
{
    fill_n(disd, MAX_N, INT_MAX);
    fill_n(dist, MAX_N, INT_MAX);
    fill_n(vis, MAX_N, false);
    fill_n(pathd, MAX_N, -1);
    int u = SRC;
    disd[u] = dist[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        vis[u] = true;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && graphd[u][j] > 0 && disd[j] > disd[u] + graphd[u][j])
            {
                disd[j] = disd[u] + graphd[u][j];
                pathd[j] = u;
                dist[j] = dist[u] + grapht[u][j];
            }
            else if (!vis[j] && graphd[u][j] > 0 && disd[j] == disd[u] + graphd[u][j] && dist[j] > dist[u] + grapht[u][j])
            {
                pathd[j] = u;
                dist[j] = dist[u] + grapht[u][j];
            }
        }

        int min_dis = INT_MAX;
        int v = -1;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && disd[j] < min_dis)
            {
                min_dis = disd[j];
                v = j;
            }
        }
        if (v == -1)
            return;
        u = v;
    }
}

void dijkstra_time()
{
    fill_n(dist, MAX_N, INT_MAX);
    fill_n(vis, MAX_N, false);
    int u = SRC;
    dist[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        vis[u] = true;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && grapht[u][j] > 0 && dist[j] > dist[u] + grapht[u][j])
            {
                dist[j] = dist[u] + grapht[u][j];
                patht[j].clear();
                patht[j].push_back(u);
            }
            else if (!vis[j] && grapht[u][j] > 0 && dist[j] == dist[u] + grapht[u][j])
                patht[j].push_back(u);
        }

        int min_dis = INT_MAX;
        int v = -1;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && dist[j] < min_dis)
            {
                min_dis = dist[j];
                v = j;
            }
        }
        if (v == -1)
            return;
        u = v;
    }
}

void dfs(int p, vector<int>& pt)
{
    if (p == SRC)
    {
        if (anst.size() == 0 || pt.size() < anst.size())
            anst = pt;
        return;
    }

    for (int i = 0; i < patht[p].size(); i++)
    {
        int v = patht[p][i];
        pt.push_back(v);
        dfs(v, pt);
        pt.pop_back();
    }
}

bool check()
{
    if (ansd.size() != anst.size())
        return false;
    for (int i = 0; i < ansd.size(); i++)
        if (ansd[i] != anst[i])
            return false;
    return true;
}

int main()
{
    fill_n(&graphd[0][0], MAX_N * MAX_N, -1);
    fill_n(&grapht[0][0], MAX_N * MAX_N, -1);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int v1, v2, one, len, tm;
        scanf("%d %d %d %d %d", &v1, &v2, &one, &len, &tm);
        graphd[v1][v2] = len;
        grapht[v1][v2] = tm;
        if (one != 1)
        {
            graphd[v2][v1] = graphd[v1][v2];
            grapht[v2][v1] = grapht[v1][v2];
        }
    }

    scanf("%d %d", &SRC, &DEST);

    dijkstra_dis();

    ans_dis = disd[DEST];

    int p = DEST;

    while (p != -1)
    {
        ansd.push_back(p);
        p = pathd[p];
    }

    dijkstra_time();
    ans_tim = dist[DEST];
    vector<int> tmp;
    tmp.push_back(DEST);
    dfs(DEST, tmp);

    if (check())
    {
        printf("Distance = %d; Time = %d: ", ans_dis, ans_tim);
        for (int i = ansd.size() - 1; i >= 0; i--)
        {
            if (i != ansd.size() - 1)
                printf(" -> ");
            printf("%d", ansd[i]);
        }
    }
    else
    {
        printf("Distance = %d: ", ans_dis);
        for (int i = ansd.size() - 1; i >= 0; i--)
        {
            if (i != ansd.size() - 1)
                printf(" -> ");
            printf("%d", ansd[i]);
        }
        printf("\n");
        printf("Time = %d: ", ans_tim);
        for (int i = anst.size() - 1; i >= 0; i--)
        {
            if (i != anst.size() - 1)
                printf(" -> ");
            printf("%d", anst[i]);
        }
    }

    return 0;
}
