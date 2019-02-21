#include <cstdio>
#include <algorithm>
#include <set>

#define MAX_N 128

using namespace std;

int N, K;
set<int> sts[MAX_N];

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            int n;
            scanf("%d", &n);
            sts[i].insert(n);
        }
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        int s1, s2;
        scanf("%d %d", &s1, &s2);
        int common_cnt = 0, total_num;
        set<int> st1, st2;

        st1 = sts[s1];
        st2 = sts[s2];

        total_num = st2.size();

        for (set<int>::iterator it = st1.begin(); it != st1.end(); it++)
        {
            if (st2.find(*it) != st2.end())
                common_cnt++;
            else
                total_num++;
        }

        double r = (double) common_cnt / total_num;
        printf("%.1f%%\n", r * 100);
    }

    return 0;
}
