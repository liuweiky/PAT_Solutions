#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX_K 1024
#define MAX_N 32
#define MAX_M 16
#define MAX_Q 1024

#define BEGIN_TIME 480
#define END_TIME 1020

using namespace std;

int N, M, K, Q;

int cust[MAX_K][2]; // cust[i][0]: proc_time, cust[i][1]: need query?
int fin_time[MAX_K];
int query[MAX_Q];

vector<int> window_cust[MAX_N];
vector<int> window_time[MAX_N];

int main()
{
    fill_n(fin_time, MAX_K, 0);
    scanf("%d %d %d %d", &N, &M, &K, &Q);

    for (int i = 1; i <= K; i++)
    {
        scanf("%d", &cust[i][0]);
        cust[i][1] = 0;
    }

    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &query[i]);
        cust[query[i]][1] = 1;
    }

    int p_cust = 1, p_window = 1;

    while (p_cust <= K && p_cust <= M * N)
    {
        window_cust[p_window].push_back(p_cust);
        window_time[p_window].push_back(cust[p_cust][0]);
        p_window++;
        if (p_window > N)
            p_window = 1;
        p_cust++;
    }

    int cur_time = BEGIN_TIME;

    bool has_cust = true;

    while (has_cust)
    {
        int min_time = INT_MAX, min_wind = 0;
        for (int i = 1; i <= N; i++)
        {
            if (window_time[i].size() > 0 && min_time > window_time[i][0])
            {
                min_time = window_time[i][0];
                min_wind = i;
            }
        }
        int c = window_cust[min_wind][0];
        for (int i = 1; i <= N; i++)
            if (window_time[i].size() > 0)
                window_time[i][0] -= min_time;
        window_cust[min_wind].erase(window_cust[min_wind].begin());
        window_time[min_wind].erase(window_time[min_wind].begin());
        cur_time += min_time;
        if (cust[c][1])
        {
            if (cur_time - cust[c][0] >= END_TIME)
                fin_time[c] = -1;
            else fin_time[c] = cur_time;
        }
        if (p_cust <= K)
        {
            window_cust[min_wind].push_back(p_cust);
            window_time[min_wind].push_back(cust[p_cust][0]);
            p_cust++;
        }
        has_cust = false;
        for (int i = 1; i <= N; i++)
            if (window_time[i].size() > 0)
                has_cust = true;
    }

    for (int i = 0; i < Q; i++)
    {
        int j = query[i];
        if (fin_time[j] == -1)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", fin_time[j] / 60, fin_time[j] % 60);
    }

    return 0;
}
