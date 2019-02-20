#include <cstdio>
#include <cmath>

using namespace std;

long long N;

bool is_prime(long long N)
{
    if (N < 2)
        return false;
    long long nsqrt = sqrt(N);
    for (int i = 2; i <= nsqrt; i++)
        if (N % i == 0)
            return false;
    return true;
}

int main()
{
    scanf("%lld", &N);
    if (is_prime(N))
    {
        printf("1\n%lld", N);
        return 0;
    }
    long long nsqrt = sqrt(N);
    long long s = -1, t = -2;
    for (int i = 2; i <= nsqrt; i++)
    {
        long long m = i, k = i;
        while (N % m == 0)
        {
            k++;
            m *= k;
        }
        if (k - i > t - s)
        {
            s = i;
            t = k;
        }
    }
    if (s < 0)
        printf("1\n%lld", N);
    else
    {
        printf("%lld\n", t - s);
        for (int i = s; i < t; i++)
        {
            if (i != s)
                printf("*");
            printf("%d", i);
        }
    }
    return 0;
}
