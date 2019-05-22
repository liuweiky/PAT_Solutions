#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define MAX_N 1024

using namespace std;

int N, M, K;
vector<int> graph[MAX_N];
int in_degree[MAX_N];
int degree[MAX_N];

int main()
{
    fill_n(in_degree, MAX_N, 0);
    scanf("%d %d", &N, &M);

    while (M--)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        in_degree[t]++;
        graph[s].push_back(t);
    }

    scanf("%d", &K);

    vector<int> ans;

    for (int i = 0; i < K; i++)
    {
        memcpy(degree, in_degree, sizeof(in_degree));
        for (int j = 0; j < N; j++)
        {
            int v;
            scanf("%d", &v);
            if (degree[v] != 0)
            {
                ans.push_back(i);
                while (j < N - 1)
                {
                    scanf("%d", &v);
                    j++;
                }
            }
            else
            {
                for (int k = 0; k < graph[v].size(); k++)
                    degree[graph[v][k]]--;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}
