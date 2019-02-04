#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> strs;
int N;

bool cmp(string s1, string s2)
{
    string sa = s1 + s2;
    string sb = s2 + s1;
    long long a, b;
    sscanf(sa.c_str(), "%lld", &a);
    sscanf(sb.c_str(), "%lld", &b);
    return a < b;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    sort(strs.begin(), strs.end(), cmp);
    string st = "";
    for (int i = 0; i < N; i++)
        st += strs[i];
    int k = 0;
    while (k < st.size() && st[k] == '0')
        k++;
    st = st.substr(k, st.size() - k);
    if (st.size() == 0)
        st = "0";
    cout << st;
    return 0;
}
