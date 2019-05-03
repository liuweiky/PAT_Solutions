#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct testee
{
    string id;
    int score;
    string icode;
};

struct institution
{
    int rnk;
    string icode;
    int Ns;
    double TWS;
};

map<string, vector<testee> > mp;
vector<institution> insts;
int N;

bool cmp(institution& inst1, institution& inst2)
{
    if ((int)inst1.TWS != (int) inst2.TWS)
        return (int)inst1.TWS > (int)inst2.TWS;
    if (inst1.Ns != inst2.Ns)
        return inst1.Ns < inst2.Ns;
    return inst1.icode < inst2.icode;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        testee t;
        cin >> t.id >> t.score >> t.icode;
        transform(t.icode.begin(), t.icode.end(), t.icode.begin(), ::tolower);
        if (mp.find(t.icode) == mp.end())
            mp[t.icode] = vector<testee> ();
        mp[t.icode].push_back(t);
    }

    for (map<string, vector<testee> >::iterator it = mp.begin(); it != mp.end(); it++)
    {
        institution inst;
        inst.Ns = it->second.size();
        inst.icode = it->first;
        inst.TWS = 0;
        for (int i = 0; i < it->second.size(); i++)
        {
            testee& t = it->second[i];
            if (t.id[0] == 'A')
                inst.TWS += t.score;
            else if (t.id[0] == 'B')
                inst.TWS += t.score / 1.5;
            else
                inst.TWS += t.score * 1.5;
        }
        insts.push_back(inst);
    }

    sort(insts.begin(), insts.end(), cmp);
    insts[0].rnk = 1;
    cout << insts.size();
    cout << endl << insts[0].rnk << ' ' << insts[0].icode << ' ' << (int)insts[0].TWS << ' ' << insts[0].Ns;
    for (int i = 1; i < insts.size(); i++)
    {
        if ((int)insts[i].TWS == (int)insts[i - 1].TWS)
            insts[i].rnk = insts[i - 1].rnk;
        else
            insts[i].rnk = i + 1;
        cout << endl << insts[i].rnk << ' ' << insts[i].icode << ' ' << (int)insts[i].TWS << ' ' << insts[i].Ns;
    }


    return 0;
}
