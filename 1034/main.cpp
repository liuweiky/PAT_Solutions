#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

#define MAX_N 2048

using namespace std;

int graph[MAX_N][MAX_N];
int person_weight[MAX_N];

int N, K;

bool visit_vertex[MAX_N];
bool visit_edge[MAX_N][MAX_N];

int region_weight = 0;
int region_gang = 0;
int max_weight = INT_MIN;
int region_num = 0;

map<string, int> str2hash;
map<int, string> hash2str;

map<string, int> ans;

void dfs(int v)
{
    if (person_weight[v] > max_weight)
    {
        max_weight = person_weight[v];
        region_gang = v;
    }
    region_num++;
    visit_vertex[v] = true;
    for (map<string, int>::iterator it = str2hash.begin(); it != str2hash.end(); it++)
    {
        int u = it->second;
        if (!visit_vertex[u] && graph[v][u] > 0)
        {
            region_weight += graph[v][u];
            visit_edge[v][u] = visit_edge[u][v] = true;
            dfs(u);
        }
        else if (visit_vertex[u] && !visit_edge[v][u] && graph[v][u] > 0)
        {
            region_weight += graph[v][u];
            visit_edge[v][u] = visit_edge[u][v] = true;
        }
    }
}

int main()
{
    fill_n(visit_vertex, MAX_N, false);
    fill_n(&visit_edge[0][0], MAX_N * MAX_N, false);
    fill_n(person_weight, MAX_N, 0);
    fill_n(&graph[0][0], MAX_N * MAX_N, 0);
    scanf("%d %d", &N, &K);

    int tmp_hash = 0;

    for (int i = 0; i < N; i++)
    {
        char buf1[4];
        char buf2[4];
        int w;
        scanf("%s %s %d", buf1, buf2, &w);
        string s1 = buf1, s2 = buf2;
        if (str2hash.find(s1) == str2hash.end())
        {
            str2hash[s1] = tmp_hash;
            hash2str[tmp_hash++] = s1;
        }
        if (str2hash.find(s2) == str2hash.end())
        {
            str2hash[s2] = tmp_hash;
            hash2str[tmp_hash++] = s2;
        }
        int h1 = str2hash[s1], h2 = str2hash[s2];
        graph[h1][h2] += w;
        graph[h2][h1] = graph[h1][h2];
        person_weight[h1] += w;
        person_weight[h2] += w;
    }

    for (map<string, int>::iterator it = str2hash.begin(); it != str2hash.end(); it++)
    {
        region_weight = 0;
        region_gang = 0;
        max_weight = INT_MIN;
        region_num = 0;
        if (!visit_vertex[it->second])
        {
            dfs(it->second);
            if (region_weight > K && region_num > 2)
                ans[hash2str[region_gang]] = region_num;
        }
    }

    printf("%d\n", ans.size());

    for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++)
        printf("%s %d\n", it->first.c_str(), it->second);
    return 0;
}
