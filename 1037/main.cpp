#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int NC, NP;
int cp = 0, cn = 0, pp = 0, pn = 0;

long long cpp[MAX_N];
long long cnn[MAX_N];
long long ppp[MAX_N];
long long pnn[MAX_N];

bool cmp(long long a, long long b)
{
    return a > b;
}

int main()
{
    scanf("%d", &NC);

    for (int i = 0; i < NC; i++)
    {
        long long l;
        scanf("%lld", &l);
        if (l > 0)
            cpp[cp++] = l;
        else if (l < 0)
            cnn[cn++] = l;
    }

    scanf("%d", &NP);

    for (int i = 0; i < NP; i++)
    {
        long long l;
        scanf("%lld", &l);
        if (l > 0)
            ppp[pp++] = l;
        else if (l < 0)
            pnn[pn++] = l;
    }

    sort(cpp, cpp + cp, cmp);
    sort(cnn, cnn + cn);

    sort(ppp, ppp + pp, cmp);
    sort(pnn, pnn + pn);

    long long opt = 0;

    for (int i = 0; i < cp && i < pp; i++)
        opt += cpp[i] * ppp[i];

    for (int i = 0; i < cn && i < pn; i++)
        opt += cnn[i] * pnn[i];

    printf("%lld", opt);

    return 0;
}
