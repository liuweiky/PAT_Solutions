#include <iostream>
#include <string>
#include <vector>
#include <set>

#define MAX_M 1024

using namespace std;

int M, N, S;

string nicks[MAX_M];
vector<string> winners;
set<string> sts;

int main()
{
    cin >> M >> N >> S;

    for (int i = 1; i <= M; i++)
        cin >> nicks[i];

    for (int i = 1 + S - 1; i <= M; i += N)
    {
        while (i <= M && sts.find(nicks[i]) != sts.end())
            i++;
        if (i <= M)
        {
            winners.push_back(nicks[i]);
            sts.insert(nicks[i]);
        }
    }

    if (winners.size() == 0)
        cout << "Keep going...";
    else
    {
        for (int i = 0; i < winners.size(); i++)
            cout << winners[i] << endl;
    }

    return 0;
}
