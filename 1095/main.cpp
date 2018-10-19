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

struct valid_rec
{
    record* rf;
    record* rt;
};

vector<record*> recs;
vector<valid_rec*> valrecs;

map<string, int> mp;

bool cmp(record* r1, record* r2)
{
    if (strcmp(r1->pnum, r2->pnum) != 0)
        return strcmp(r1->pnum, r2->pnum) < 0;
    return (r1->time_tag < r2->time_tag);
}

bool cmp1(valid_rec* v1, valid_rec* v2)
{
    return v1->rt->time_tag < v2->rt->time_tag;
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
    for (int i = 0; i < N; i++)
    {
        if (recs[i]->type == IN)
        {
            if (i != N - 1 && recs[i + 1]->type == OUT && strcmp(recs[i]->pnum, recs[i + 1]->pnum) == 0)
            {
                valid_rec* v = new valid_rec;
                v->rf = recs[i];
                v->rt = recs[i + 1];
                valrecs.push_back(v);
                i++;
            }
        }
    }

    for (int i = 0; i < valrecs.size(); i++)
    {
        int time;
        time = valrecs[i]->rt->time_tag - valrecs[i]->rf->time_tag;

        if (mp[valrecs[i]->rf->pnum] == NULL)
            mp[valrecs[i]->rf->pnum] = time;
        else
            mp[valrecs[i]->rf->pnum] += time;
    }

    int max_time = -1;
    vector<string> pns;

    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > max_time)
        {
            max_time = it->second;
            pns.clear();
            pns.push_back(it->first);
        } else if (it->second == max_time)
        {
            pns.push_back(it->first);
        }
    }

    int start = 0;
    sort(valrecs.begin(), valrecs.end(), cmp1);

    for (int i = 0; i < K; i++)
    {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);

        int t = h * 3600 + m * 60 + s;

        int cnt = 0;

        for (int j = start; j < valrecs.size(); j++)
        {
            if (valrecs[j]->rf->time_tag <= t && valrecs[j]->rt->time_tag > t)
                cnt++;
            else
            {
                if (valrecs[j]->rt->time_tag < t)
                {
                    start = j;
                }
            }
        }
        printf("%d\n", cnt);
    }

    for (int i = 0; i < pns.size(); i++)
        printf("%s ", pns[i].c_str());

    int h = max_time / 3600;
    int m = (max_time / 60) % 60;
    int s = max_time % 60;

    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}
