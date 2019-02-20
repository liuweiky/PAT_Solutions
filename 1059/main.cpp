#include <cstdio>
#include <cmath>
#include <vector>

#define MAX_LEN 102400

using namespace std;

struct factor
{
    long long p, k;
};

long long N;
vector<factor> facts;

bool is_prime(long long k)
{
    if (k < 2)
        return false;
    long long ksqrt = sqrt(k);
    for (int i = 2; i <= ksqrt; i++)
        if (k % i == 0)
            return false;
    return true;
}

int main()
{
    scanf("%lld", &N);
    printf("%lld", N);

    long long nsqrt = sqrt(N);

    if (is_prime(N) || N < 3)
        printf("=%lld", N);

    for (long long i = 2; i <= nsqrt && N != 1; i++)
    {
        if (is_prime(i) && N % i == 0)
        {
            factor f;
            f.p = i;
            f.k = 0;
            while (N % i == 0)
            {
                N /= i;
                f.k++;
            }
            facts.push_back(f);
        }
    }


    for (int i = 0; i < facts.size(); i++)
    {
        if (i == 0)
            printf("=");
        else
            printf("*");
        if (facts[i].k == 1)
            printf("%lld", facts[i].p);
        else
            printf("%lld^%lld", facts[i].p, facts[i].k);
    }

    return 0;
}
