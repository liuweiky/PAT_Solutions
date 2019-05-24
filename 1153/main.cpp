#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MAX_N 10240

using namespace std;

struct testee
{
    string cnumber;
    int score;
};

struct site_info
{
    string site_id;
    int Nt;
};

vector<testee> ts;
int N, M;

bool cmp1(testee& t1, testee& t2)
{
    if (t1.score != t2.score)
        return t1.score > t2.score;
    return t1.cnumber < t2.cnumber;
}

bool cmp3(site_info& s1, site_info& s2)
{
    if (s1.Nt != s2.Nt)
        return s1.Nt > s2.Nt;
    return s1.site_id < s2.site_id;
}

void filter1(char level)
{
    vector<testee> tmp;
    for (int i = 0; i < N; i++)
        if (ts[i].cnumber[0] == level)
            tmp.push_back(ts[i]);
    if (tmp.size() == 0)
    {
        printf("NA\n");
        return;
    }
    sort(tmp.begin(), tmp.end(), cmp1);
    for (int i = 0; i < tmp.size(); i++)
        printf("%s %d\n", tmp[i].cnumber.c_str(), tmp[i].score);
}

void filter2(string site)
{
    int Nt = 0, Ns = 0;
    for (int i = 0; i < N; i++)
    {
        string st = ts[i].cnumber.substr(1, 3);
        if (site == st)
        {
            Nt++;
            Ns += ts[i].score;
        }
    }
    if (Nt == 0)
        printf("NA\n");
    else
        printf("%d %d\n", Nt, Ns);
}

void filter3(string date)
{
    unordered_map<string, int> mp;
    vector<site_info> si;
    for (int i = 0; i < N; i++)
    {
        string dt = ts[i].cnumber.substr(4, 6);
        if (date == dt)
        {
            string site = ts[i].cnumber.substr(1, 3);
            if (mp.find(site) == mp.end())
                mp[site] = 1;
            else
                mp[site]++;
        }
    }
    for (unordered_map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        site_info s;
        s.site_id = it->first;
        s.Nt = it->second;
        si.push_back(s);
    }
    if (si.size() == 0)
    {
        printf("NA\n");
        return;
    }
    sort(si.begin(), si.end(), cmp3);
    for (int i = 0; i < si.size(); i++)
        printf("%s %d\n", si[i].site_id.c_str(), si[i].Nt);
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        testee t;
        char buf[32];
        scanf("%s %d", buf, &t.score);
        t.cnumber = buf;
        ts.push_back(t);
    }

    for (int i = 1; i <= M; i++)
    {
        int type;
        string term;
        char buf[32];
        scanf("%d %s", &type, buf);
        term = buf;
        printf("Case %d: %d %s\n", i, type, buf);
        if (type == 1)
            filter1(term[0]);
        else if (type == 2)
            filter2(term);
        else
            filter3(term);
    }


    return 0;
}
