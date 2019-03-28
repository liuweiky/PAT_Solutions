#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX_N 10240

using namespace std;

struct ans
{
    int id, m;
    double avgs, avga;
};

int N;

vector<int> graph[MAX_N];
set<int> ids;
bool vis[MAX_N];
int id_est[MAX_N];
int id_area[MAX_N];

int local_fam_num = 0;
int local_est = 0;
int local_area = 0;
int min_id = INT_MAX;

void dfs(int u)
{
    min_id = min(min_id, u);
    vis[u] = true;
    local_fam_num++;
    local_est += id_est[u];
    local_area += id_area[u];

    for (int i = 0; i < graph[u].size(); i++)
        if (!vis[graph[u][i]])
            dfs(graph[u][i]);
}

bool cmp(ans& a1, ans& a2)
{
    if (a1.avga != a2.avga)
        return a1.avga > a2.avga;
    return a1.id < a2.id;
}

int main()
{
    fill_n(vis, MAX_N,false);
    fill_n(id_est, MAX_N, 0);
    fill_n(id_area, MAX_N, 0);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int id, fa, mo, k, c, m, a;
        scanf("%d %d %d %d", &id, &fa, &mo, &k);
        ids.insert(id);
        if (fa != -1)
        {
            graph[fa].push_back(id);
            graph[id].push_back(fa);
            ids.insert(fa);
        }
        if (mo != -1)
        {
            graph[mo].push_back(id);
            graph[id].push_back(mo);
            ids.insert(mo);
        }
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &c);
            graph[c].push_back(id);
            graph[id].push_back(c);
            ids.insert(c);
        }
        scanf("%d %d", &m, &a);
        id_est[id] = m;
        id_area[id] = a;
    }

    vector<ans> anss;

    for (set<int>::iterator it = ids.begin(); it != ids.end(); it++)
    {
        if (!vis[*it])
        {
            local_fam_num = 0;
            local_est = 0;
            local_area = 0;
            min_id = INT_MAX;
            dfs(*it);
            ans a;
            a.id = min_id;
            a.m = local_fam_num;
            a.avgs = (double) local_est / local_fam_num;
            a.avga = (double) local_area / local_fam_num;
            anss.push_back(a);
        }
    }

    sort(anss.begin(), anss.end(), cmp);

    printf("%d", anss.size());

    for (int i = 0; i < anss.size(); i++)
        printf("\n%04d %d %.3f %.3f", anss[i].id, anss[i].m, anss[i].avgs, anss[i].avga);

    return 0;
}
