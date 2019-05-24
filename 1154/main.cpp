#include <cstdio>
#include <vector>
#include <set>

#define MAX_N 10240

using namespace std;

struct edge
{
    int s, t;
};

int color[MAX_N];
int N, M, K;
vector<edge> edges;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        edge e;
        scanf("%d %d", &e.s, &e.t);
        edges.push_back(e);
    }

    scanf("%d", &K);

    while (K--)
    {
        set<int> c;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &color[i]);
            c.insert(color[i]);
        }

        bool flag = true;

        for (int i = 0; i < M && flag; i++)
        {
            if (color[edges[i].s] == color[edges[i].t])
                flag = false;
        }

        if (!flag)
            printf("No\n");
        else
            printf("%d-coloring\n", c.size());
    }

    return 0;
}
