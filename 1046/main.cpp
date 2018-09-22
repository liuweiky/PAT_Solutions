#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int dis[MAX_N];
int N;

int main()
{

    memset(dis, 0, MAX_N);
    scanf("%d", &N);

    int total_dis = 0;

    for (int i = 1; i <= N; i++)
    {
        int d;
        scanf("%d", &d);
        total_dis += d;
        dis[i] = total_dis;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        s--;
        t--;
        int dis1 = 0, dis2 = 0;
        if (s > t)
            swap(s, t);
        dis1 = dis[t] - dis[s];
        dis2 = total_dis - dis1;
        printf("%d\n", dis1 < dis2 ? dis1 : dis2);
    }

    return 0;
}
