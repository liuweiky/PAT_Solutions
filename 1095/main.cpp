#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

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

struct mtime
{
    int time;
    char pnum[16];
};

vector<record*> recs;
vector<valid_rec*> valrecs;
vector<mtime*> ms;

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

    for (int i = 0; i < valrecs.size(); )
    {
        mtime* m = new mtime;
        m->time = valrecs[i]->rt->time_tag - valrecs[i]->rf->time_tag;
        strcpy(m->pnum, valrecs[i]->rf->pnum);

        int j;

        for (j = i + 1; j < valrecs.size();j++)
        {
            if (strcmp(valrecs[j]->rf->pnum, valrecs[i]->rf->pnum) == 0)
            {
                m->time += valrecs[j]->rt->time_tag - valrecs[j]->rf->time_tag;
            } else
                break;
        }
        ms.push_back(m);
        i = j;
    }

    int max_time = -1;
    vector<int> idxs;

    for (int i = 0; i < ms.size(); i++)
    {
        if (max_time < ms[i]->time)
        {
            max_time = ms[i]->time;
            idxs.clear();
            idxs.push_back(i);
        } else if (max_time == ms[i]->time)
            idxs.push_back(i);
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

    for (int i = 0; i < idxs.size(); i++)
        printf("%s ", ms[idxs[i]]->pnum);

    int h = max_time / 3600;
    int m = (max_time / 60) % 60;
    int s = max_time % 60;

    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}
