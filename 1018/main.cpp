#include <cstdio>
#include <string.h>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int C_MAX, N, Sp, M;

int graph[512][512];
int bikes[512];
int visit[512];
int path[512];
int dis[512];

vector<vector<int> > paths;

void dijkstra(int v)
{
    dis[v] = 0;

    for (int i = 0; i < N; i++)
    {
        visit[v] = 1;

        for (int j = 0; j <= N; j++)
            if (visit [j] == 0 && graph[v][j] > 0 && dis[j] > dis[v] + graph[v][j])
            {
                dis[j] = dis[v] + graph[v][j];
                path[j] = v;
            }


        int min_dis = INT_MAX;
        for (int j = 0; j <= N; j++)
            if (visit[j] == 0 && dis[j] < min_dis)
            {
                v = j;
                min_dis = dis[j];
            }
    }
}

void GeneratePath(int v, int target, vector<int> p)
{
    if (v == target)
        paths.push_back(p);
    for (int i = 0; i <= N; i++)
        if (dis[v] == dis[i] + graph[i][v])
        {
            p.push_back(i);
            GeneratePath(i, target, p);
            p.erase(p.end() - 1);
        }
}

int main()
{
    scanf("%d %d %d %d", &C_MAX, &N, &Sp, &M);
    memset(graph, -1, 512 * 512);
    memset(bikes, 0, 512);
    memset(visit, 0, 512);
    memset(path, -1, 512);
    fill_n(dis, 512, INT_MAX);
    for (int i = 1; i <= N; i++)
        scanf("%d", &bikes[i]);
    for (int i = 0; i < M; i++)
    {
        int s, t, j;
        scanf("%d %d %d", &s, &t, &j);
        graph[s][t] = graph[t][s] = j;
    }

    dijkstra(0);
    vector<int> v1;
    v1.push_back(Sp);
    GeneratePath(Sp, 0, v1);
    /*for (int i = 0; i <= N; i++)
        printf("%d ", path[i]);
    for (int i = 0; i < paths.size(); i++)
    {
        vector<int> p = paths[i];
        for (int j = p.size() - 1; j >= 0; j--)
        {
            printf("%d ", p[j]);
        }
        printf("\n");
    }*/

    int min_sent = INT_MAX;
    int min_back = INT_MAX;
    int index = 0;

    for (int i = 0; i < paths.size(); i++)
    {
        int sent = 0;
        int tmp_take = 0;
        int opt_bike_num = C_MAX / 2;
        vector<int> p = paths[i];
        for (int j = p.size() - 2; j >= 0; j--)
        {
            //printf("%-d-\n", p[j]);
            int kk = p[j];
            if (bikes[kk] > opt_bike_num)
                tmp_take += (bikes[kk] - opt_bike_num);
            else if (bikes[kk] < opt_bike_num)
            {
                if (tmp_take >=  opt_bike_num - bikes[kk])
                    tmp_take -= (opt_bike_num - bikes[kk]);
                else
                {
                    //printf("%d\n", tmp_take);
                    sent += (opt_bike_num - bikes[kk] - tmp_take);
                    tmp_take = 0;
                }
            }
        }
        if (min_sent > sent)
        {
            min_sent = sent;
            min_back = tmp_take;
            index = i;
        } else if (min_sent == sent){
            if (min_back > tmp_take)
            {
                min_back = tmp_take;
                index = i;
            }
        }
    }

    vector<int> best_p = paths[index];

    printf("%d ", min_sent);
    for (int i = best_p.size() - 1; i >= 0; i--)
    {
        printf("%d", best_p[i]);
        if (i != 0)
            printf("->");
    }
    printf(" %d", min_back);
    return 0;
}

