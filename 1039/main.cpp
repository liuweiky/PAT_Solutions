#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define MAX_N 40960
#define MAX_K 4096

using namespace std;

int N, K;

map<string, vector<int> > mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int no, stu_num;
        cin >> no >> stu_num;

        for (int j = 0; j < stu_num; j++)
        {
            string name;
            cin >> name;
            if (mp.find(name) == mp.end())
            {
                vector<int> v;
                mp[name] = v;
            }
            mp[name].push_back(no);
        }
    }

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        cout << name << " ";
        vector<int> v = mp[name];
        int sz = v.size();
        cout << sz;
        sort(v.begin(), v.end());
        for (int j = 0; j < sz; j++)
            cout << " " << v[j];
        cout <<endl;
    }

    return 0;
}
