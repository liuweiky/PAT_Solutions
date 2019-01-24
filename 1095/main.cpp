#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <string>

#define IN 1
#define OUT 0

using namespace std;

int N, K;

struct record
{
    char pnum[16];
    int h, m, s;
    int type;
    int time_tag;
};

vector<record*> recs;
vector<record*> valrecs;

map<string, int> mp;

bool cmp(record* r1, record* r2)
{
    if (strcmp(r1->pnum, r2->pnum) != 0)
        return strcmp(r1->pnum, r2->pnum) < 0;
    return (r1->time_tag < r2->time_tag);
}

bool cmp1(record* r1, record* r2)
{
    return r1->time_tag < r2->time_tag;
}

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        record* r = new record;
        char s[16];
        scanf("%s %d:%d:%d %s", r->pnum, &r->h, &r->m, &r->s, s);
        if (s[0] == 'i')
            r->type = IN;
        else
            r->type = OUT;
        r->time_tag = r->h * 3600 + r->m * 60 + r->s;
        recs.push_back(r);
    }

    sort(recs.begin(), recs.end(), cmp);
    int max_time = -1;
    for (int i = 0; i < N; i++)
    {
        if (recs[i]->type == IN)
        {
            if (i != N - 1 && recs[i + 1]->type == OUT && strcmp(recs[i]->pnum, recs[i + 1]->pnum) == 0)
            {
                valrecs.push_back(recs[i]);
                valrecs.push_back(recs[i + 1]);
                int time;
                time = recs[i + 1]->time_tag - recs[i]->time_tag;

                if (mp[recs[i]->pnum] == NULL)
                    mp[recs[i]->pnum] = time;
                else
                    mp[recs[i]->pnum] += time;
                if (mp[recs[i]->pnum] > max_time)
                    max_time = mp[recs[i]->pnum];
                i++;
            }
        }
    }

    int p = 0;
    int cnt = 0;
    sort(valrecs.begin(), valrecs.end(), cmp1);

    for (int i = 0; i < K; i++)
    {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int t = h * 3600 + m * 60 + s;
        while (p < valrecs.size() && valrecs[p]->time_tag <= t)
        {
            if (valrecs[p]->type == IN)
                cnt++;
            else cnt--;
            p++;
        }
        printf("%d\n", cnt);
    }

    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        if (it->second == max_time)
            printf("%s ", it->first.c_str());

    int h = max_time / 3600;
    int m = (max_time / 60) % 60;
    int s = max_time % 60;

    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}
