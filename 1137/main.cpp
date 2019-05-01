#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct student
{
    string id;
    int gp, gmid, gfinal, g;
    student() {gp = gmid = gfinal = g = -1;}
};

map<string, student> mp;
vector<student> stus;
int P, M, N;

bool cmp(student& s1, student& s2)
{
    if (s1.g != s2.g)
        return s1.g > s2.g;
    return s1.id < s2.id;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> P >> M >> N;

    for (int i = 0; i < P; i++)
    {
        string id;
        int score;
        cin >> id >> score;
        student stu;
        stu.id = id;
        stu.gp = score;
        mp[id] = stu;
    }

    for (int i = 0; i < M; i++)
    {
        string id;
        int score;
        cin >> id >> score;

        if (mp.find(id) == mp.end())
        {
            student stu;
            stu.id = id;
            mp[id] = stu;
        }

        mp[id].gmid = score;
    }

    for (int i = 0; i < N; i++)
    {
        string id;
        int score;
        cin >> id >> score;

        if (mp.find(id) == mp.end())
        {
            student stu;
            stu.id = id;
            mp[id] = stu;
        }

        mp[id].gfinal = score;
    }

    for (map<string, student>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if (max(it->second.gmid, 0) > max(it->second.gfinal, 0))
            it->second.g = round((double)max(it->second.gmid, 0) * 0.4 + max(it->second.gfinal, 0) * 0.6);
        else
            it->second.g = max(it->second.gfinal, 0);
        if (it->second.gp >= 200 && it->second.g >= 60)
            stus.push_back(it->second);
    }

    sort(stus.begin(), stus.end(), cmp);

    for (int i = 0; i < stus.size(); i++)
    {
        if (i != 0)
            cout << endl;
        cout << stus[i].id << ' ' << stus[i].gp << ' ' << stus[i].gmid << ' ' << stus[i].gfinal << ' ' << stus[i].g;
    }

    return 0;
}
