#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct prog
{
    int w, level, rnk;
};

int NP, NG;

vector<prog> progs;
queue<int> q;

int main()
{
    scanf("%d %d", &NP, &NG);

    for (int i = 0; i < NP; i++)
    {
        prog p;
        scanf("%d", &p.w);
        p.level = 1;
        progs.push_back(p);
    }

    for (int i = 0; i < NP; i++)
    {
        int t;
        scanf("%d", &t);
        q.push(t);
    }

    int lv = 1;

    while (q.size() != 1)
    {
        int cnt = 0, max_w = INT_MIN;
        int max_prog = 0;
        int grps = q.size() / NG;
        if (q.size() % NG != 0)
            grps++;
        while (!q.empty() && progs[q.front()].level == lv)
        {
            if (progs[q.front()].w > max_w)
            {
                max_w = progs[q.front()].w;
                max_prog = q.front();
            }
            cnt++;
            progs[q.front()].rnk = grps + 1;
            q.pop();
            if (cnt == NG)
            {
                cnt = 0;
                progs[max_prog].level++;
                q.push(max_prog);
                max_w = INT_MIN;
            }
        }
        if (cnt != 0)
        {
            progs[max_prog].level++;
            q.push(max_prog);
        }
        lv++;
    }

    progs[q.front()].rnk = 1;

    for (int i = 0; i < NP; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", progs[i].rnk);
    }

    return 0;
}
