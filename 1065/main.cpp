#include <cstdio>

using namespace std;

long long a, b, c;

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);

        long long t = a + b;

        if (a > 0 && b > 0 && t < 0)
            printf("Case #%d: true\n", i + 1);
        else if (a < 0 && b < 0 && t >= 0)
            printf("Case #%d: false\n", i + 1);
        else if (t > c)
            printf("Case #%d: true\n", i + 1);
        else if (t <= c)
            printf("Case #%d: false\n", i + 1);
    }
    return 0;
}
