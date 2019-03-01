#include <cstdio>
#include <vector>
#include <climits>
#include <string>
#include <map>
#include <algorithm>

#define MAX_N 256

using namespace std;

int graph[MAX_N][MAX_N];
int city_happiness[MAX_N];

int N, K;
int start_city;

map<string, int> str2hash;
map<int, string> hash2str;

vector<int> path[MAX_N];
bool visit[MAX_N];
int dis[MAX_N];

int hap = 0;
double avg_hap = 0;
vector<int> bestpath;
int l_cost_num = 0;

void dijkstra()
{
    fill_n(visit, MAX_N, false);
    fill_n(dis, MAX_N, INT_MAX);
    int u = 0;
    dis[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        visit[u] = true;
        for (int j = 1; j < N; j++)
        {
            if (!visit[j] && graph[u][j] > 0 && dis[j] > dis[u] + graph[u][j])
            {
                dis[j] = dis[u] + graph[u][j];
                path[j].clear();
                path[j].push_back(u);
            }
            else if (!visit[j] && graph[u][j] > 0 && dis[j] == dis[u] + graph[u][j])
                path[j].push_back(u);
        }

        int min_dis = INT_MAX;
        int v = -1;

        for (int j = 1; j < N; j++)
        {
            if (!visit[j] && dis[j] < min_dis)
            {
                min_dis = dis[j];
                v = j;
            }
        }

        if (v == -1)
            return;

        u = v;
    }
}

void dfs(int h, vector<int> p)
{
    if (h == 0)
    {
        int local_hap = 0;
        double local_avg_hap = 0;
        for (int i = 0; i < p.size(); i++)
            local_hap += city_happiness[p[i]];
        l_cost_num++;
        local_avg_hap = local_hap / (p.size() - 1);
        if (local_hap > hap)
        {
            hap = local_hap;
            avg_hap = local_avg_hap;
            bestpath = p;
        }
        else if (local_hap == hap && local_avg_hap > avg_hap)
        {
            avg_hap = local_avg_hap;
            bestpath = p;
        }
        return;
    }
    int sz = path[h].size();
    for (int i = 0; i < sz; i++)
    {
        p.push_back(path[h][i]);
        dfs(path[h][i], p);
        p.pop_back();
    }
}

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, -1);
    int tmphash = 0;
    char sbuf[16];
    scanf("%d %d %s", &N, &K, sbuf);
    string st = sbuf;
    str2hash[st] = tmphash;
    hash2str[tmphash++] = st;
    city_happiness[0] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int h;
        scanf("%s %d", sbuf, &h);
        st = sbuf;
        city_happiness[tmphash] = h;
        str2hash[st] = tmphash;
        hash2str[tmphash++] = st;
    }

    for (int i = 0; i < K; i++)
    {
        char tbuf[16];
        int s, t, d;
        scanf("%s %s %d", sbuf, tbuf, &d);
        s = str2hash[sbuf];
        t = str2hash[tbuf];
        graph[s][t] = graph[t][s] = d;
    }

    dijkstra();

    int rome = str2hash["ROM"];

    vector<int> tmpv;
    tmpv.push_back(rome);
    dfs(rome, tmpv);

    printf("%d %d %d %d\n", l_cost_num, dis[rome], hap, (int) avg_hap);
    for (int i = bestpath.size() - 1; i >= 0; i--)
    {
        printf("%s", hash2str[bestpath[i]].c_str());
        if (i != 0)
            printf("->");
    }

    return 0;
}
