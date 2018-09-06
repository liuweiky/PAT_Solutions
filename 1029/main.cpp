#include <cstdio>
#include <algorithm>

using namespace std;

int S[320000];

int main()
{
    int N1, N2;

    scanf("%d", &N1);

    for (int i = 0; i < N1; i++)
    {
        int t;
        scanf("%d", &t);
        S[i] = t;
    }

    scanf("%d", &N2);

    for (int i = 0; i < N2; i++)
    {
        int t;
        scanf("%d", &t);
        S[N1 + i] = t;
    }

    sort(S, S + N1 + N2);

    printf("%d", S[(N1 + N2 - 1)/2]);

    return 0;
}
