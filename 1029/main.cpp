#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> S;

int main()
{
    int N1, N2;

    scanf("%d", &N1);

    for (int i = 0; i < N1; i++)
    {
        int t;
        scanf("%d", &t);
        S.push_back(t);
    }

    scanf("%d", &N2);

    for (int i = 0; i < N2; i++)
    {
        int t;
        scanf("%d", &t);
        S.push_back(t);
    }

    sort(S.begin(), S.end());

    printf("%d", S[(N1 + N2 - 1)/2]);

    return 0;
}
