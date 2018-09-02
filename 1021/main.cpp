#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int ver_adj;
    Edge* link;
    Edge(int a): ver_adj(a) {link = NULL;}
};

struct Vertex
{
    int ver_name;
    Edge* adjacent;
    Vertex(){}
    Vertex(int n): ver_name(n) {adjacent = NULL;}
};

Vertex head[10240];
int N;
int visit[10240];

int local_depth = -1;
int max_depth = -1;

vector<int> vs;

void dfs(int v, int depth)
{
    visit[v] = 1;
    if (depth > local_depth)
        local_depth = depth;
    Edge* e = head[v].adjacent;
    while (e != NULL)
    {
        if (visit[e->ver_adj] != 1)
            dfs(e->ver_adj, depth + 1);
        e = e->link;
    }
}

int main()
{
    memset(visit, 0, 10240);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        head[i].ver_name = i;
    }
    for (int i = 0; i < N - 1; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        Edge* e = new Edge(t);
        e->link = head[s].adjacent;
        head[s].adjacent = e;

        e = new Edge(s);
        e->link = head[t].adjacent;
        head[t].adjacent = e;
    }

    int dfs_count = 0;

    for (int i = 1; i <= N; i++)
    {
        if (visit[i] != 1)
        {
            dfs_count++;
            dfs(i, 1);
        }
    }

    if (dfs_count > 1)
    {
        printf("Error: %d components", dfs_count);
        return 0;
    }

    for (int i = 1; i <= N; i++)
    {
        local_depth = -1;
        memset(visit, 0, 10240);
        dfs(i, 1);
        if (local_depth > max_depth)
        {
            vs.clear();
            vs.push_back(i);
            max_depth = local_depth;
        } else if (local_depth == max_depth)
        {
            vs.push_back(i);
        }
    }

    sort(vs.begin(), vs.end());

    for (vector<int>::iterator it = vs.begin(); it != vs.end(); it++)
    {
        printf("%d", (*it));
        if (it != vs.end() - 1)
            printf("\n");
    }

    return 0;
}
