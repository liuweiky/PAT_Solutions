#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 256

using namespace std;

bool graph[MAX_N][MAX_N];
bool in_cli[MAX_N];
int Nv, Ne, M, K;

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, false);

    scanf("%d %d", &Nv, &Ne);

    for (int i = 0; i < Ne; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][t] = graph[t][s] = true;
    }

    scanf("%d", &M);

    while (M--)
    {
        fill_n(in_cli, MAX_N, false);
        scanf("%d", &K);

        vector<int> vs;
        for (int i = 0; i < K; i++)
        {
            int t;
            scanf("%d", &t);
            vs.push_back(t);
            in_cli[t] = true;
        }

        bool is_clique = true;

        for (int i = 0; i < K && is_clique; i++)
        {
            for (int j = i + 1; j < K && is_clique; j++)
            {
                int s = vs[i];
                int t = vs[j];
                if (!graph[s][t])
                    is_clique = false;
            }
        }

        if (!is_clique)
        {
            printf("Not a Clique\n");
            continue;
        }
        else
        {
            bool is_max = true;

            for (int i = 1; i <= Nv && is_max; i++)
            {
                if (!in_cli[i])
                {
                    bool all = true;
                    for (int j = 0; j < K && all; j++)
                    {
                        if (!graph[i][vs[j]])
                            all = false;
                    }
                    if (all)
                        is_max = false;
                }
            }
            if (is_max)
                printf("Yes\n");
            else
                printf("Not Maximal\n");
        }
    }

    return 0;
}
