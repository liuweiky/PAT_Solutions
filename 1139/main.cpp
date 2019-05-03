#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>

#define MAX_ID 10240

#define MALE 1
#define FEMALE -1

using namespace std;

int gender[MAX_ID];
vector<int> friends[MAX_ID];
int N, M, K;

vector<pair<int, int> > ans;

void MF(int s, int t)
{
    //printf("%d\n", id);
    queue<vector<int> > q;
    vector<int> vec;
    vec.push_back(s);
    q.push(vec);

    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        int sz = v.size();
        int id = v[sz - 1];
        if (sz == 4)
        {
            set<int> st;
            st.insert(v[0]); st.insert(v[1]); st.insert(v[2]); st.insert(v[3]);
            if (st.size() == 4)
                ans.push_back(make_pair(v[1], v[2]));
            continue;
        }
        for (int i = 0; i < friends[id].size(); i++)
        {
            int f = friends[id][i];
            if (sz == 3)
            {
                if (f != t)
                    continue;
            }
            else if (sz == 2)
            {
                if (gender[f] != FEMALE)
                    continue;
            }
            else if (sz == 1)
            {
                if (gender[f] != MALE)
                    continue;
            }
            v.push_back(f);
            q.push(v);
            v.pop_back();
        }
    }
}

void FM(int s, int t)
{
    //printf("%d\n", id);
    queue<vector<int> > q;
    vector<int> vec;
    vec.push_back(s);
    q.push(vec);

    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        int sz = v.size();
        int id = v[sz - 1];
        if (sz == 4)
        {
            set<int> st;
            st.insert(v[0]); st.insert(v[1]); st.insert(v[2]); st.insert(v[3]);
            if (st.size() == 4)
                ans.push_back(make_pair(v[1], v[2]));
            continue;
        }
        for (int i = 0; i < friends[id].size(); i++)
        {
            int f = friends[id][i];
            if (sz == 3)
            {
                if (f != t)
                    continue;
            }
            else if (sz == 2)
            {
                if (gender[f] != MALE)
                    continue;
            }
            else if (sz == 1)
            {
                if (gender[f] != FEMALE)
                    continue;
            }
            v.push_back(f);
            q.push(v);
            v.pop_back();
        }
    }
}

void MM(int s, int t)
{
    //printf("%d\n", id);
    queue<vector<int> > q;
    vector<int> vec;
    vec.push_back(s);
    q.push(vec);

    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        int sz = v.size();
        int id = v[sz - 1];
        if (sz == 4)
        {
            set<int> st;
            st.insert(v[0]); st.insert(v[1]); st.insert(v[2]); st.insert(v[3]);
            if (st.size() == 4)
                ans.push_back(make_pair(v[1], v[2]));
            continue;
        }
        for (int i = 0; i < friends[id].size(); i++)
        {
            int f = friends[id][i];
            if (sz == 3)
            {
                if (f != t)
                    continue;
            }
            else if (gender[f] != MALE)
                    continue;
            v.push_back(f);
            q.push(v);
            v.pop_back();
        }
    }
}

void FF(int s, int t)
{
    queue<vector<int> > q;
    vector<int> vec;
    vec.push_back(s);
    q.push(vec);

    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        int sz = v.size();
        int id = v[sz - 1];
        if (sz == 4)
        {
            set<int> st;
            st.insert(v[0]); st.insert(v[1]); st.insert(v[2]); st.insert(v[3]);
            if (st.size() == 4)
                ans.push_back(make_pair(v[1], v[2]));
            continue;
        }
        for (int i = 0; i < friends[id].size(); i++)
        {
            int f = friends[id][i];
            if (sz == 3)
            {
                if (f != t)
                    continue;
            }
            else if (gender[f] != FEMALE)
                    continue;
            v.push_back(f);
            q.push(v);
            v.pop_back();
        }
    }
}

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        char sbuf[10], tbuf[10];
        int s, t;
        scanf("%s %s", sbuf, tbuf);

        if (sbuf[0] == '-')
        {
            sscanf(sbuf + 1, "%d", &s);
            gender[s] = FEMALE;
        }
        else
        {
            sscanf(sbuf, "%d", &s);
            gender[s] = MALE;
        }

        if (tbuf[0] == '-')
        {
            sscanf(tbuf + 1, "%d", &t);
            gender[t] = FEMALE;
        }
        else
        {
            sscanf(tbuf, "%d", &t);
            gender[t] = MALE;
        }

        friends[s].push_back(t);
        friends[t].push_back(s);
    }

    scanf("%d", &K);

    while (K--)
    {
        ans.clear();
        int s, t;
        scanf("%d %d", &s, &t);

        s = abs(s);
        t = abs(t);

        if (gender[s] == MALE)
        {
            if (gender[t] == MALE)
                MM(s, t);
            else
                MF(s, t);
        }
        else
        {
            if (gender[t] == MALE)
                FM(s, t);
            else
                FF(s, t);
        }

        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%04d %04d\n", ans[i].first, ans[i].second);
        }
    }

    return 0;
}
