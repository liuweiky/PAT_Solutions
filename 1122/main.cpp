#include <cstdio>
#include <algorithm>
#include <set>

#define MAX_N 256

using namespace std;

int N, M, K;
bool graph[MAX_N][MAX_N];

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, false);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][t] = graph[t][s] = true;
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        int n, v, prev = -1, head;
        scanf("%d", &n);
        bool flag = true;
        if (n != N + 1)
            flag = false;
        set<int> st;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v);
            if (!flag)
                continue;
            if (j != n - 1 && st.find(v) != st.end())
                flag = false;
            st.insert(v);
            if (prev == -1)
            {
                prev = v;
                head = v;
                continue;
            }
            if (!graph[prev][v])
                flag = false;
            if (j == n - 1 && v != head)
                flag = false;
            prev = v;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
