#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

#define MAX_N 256

using namespace std;

int graph[MAX_N][MAX_N];
int N, M, K;

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, -1);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        graph[s][t] = graph[t][s] = d;
    }

    int sdis = INT_MAX;
    int idx = -1;

    scanf("%d", &K);

    for (int i = 1; i <= K; i++)
    {
        int n;
        scanf("%d", &n);
        vector<int> path;
        int dis = 0;
        bool is_simple_cycle = true;
        set<int> ps;
        for (int j = 0; j < n; j++)
        {
            int t;
            scanf("%d", &t);
            path.push_back(t);
            if (j != 0 && graph[path[j - 1]][path[j]] == -1)
                dis = -1;
            else if (j != 0 && dis != -1)
                dis += graph[path[j - 1]][path[j]];
            if (j != n - 1)
            {
                if (ps.find(t) != ps.end())
                    is_simple_cycle = false;
                else
                    ps.insert(t);
            }
        }

        if (dis == -1)
        {
            printf("Path %d: NA (Not a TS cycle)\n", i);
            continue;
        }



        if (path[0] != path[n - 1] || ps.size() != N)
            printf("Path %d: %d (Not a TS cycle)\n", i, dis);
        else if (!is_simple_cycle)
        {
            printf("Path %d: %d (TS cycle)\n", i, dis);
            if (dis < sdis)
            {
                sdis = dis;
                idx = i;
            }
        }
        else
        {
            if (dis < sdis)
            {
                sdis = dis;
                idx = i;
            }
            printf("Path %d: %d (TS simple cycle)\n", i, dis);
        }
    }

    printf("Shortest Dist(%d) = %d", idx, sdis);

    return 0;
}
