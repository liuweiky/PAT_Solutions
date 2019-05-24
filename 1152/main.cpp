#include <cstdio>
#include <cmath>

#define MAX_L 1024

using namespace std;

int L, K;
char digits[MAX_L];

bool is_prime(long long p)
{
    if (p < 2)
        return false;
    long long sqrtp = sqrt(p);

    for (int i = 2; i <= sqrtp; i++)
        if (p % i == 0)
            return false;
    return true;
}

long long get_at(int p)
{
    long long w = 1;
    long long res = 0;
    for (int i = p + K - 1; i >= p; i--)
    {
        res += (digits[i] - '0') * w;
        w *= 10;
    }
    return res;
}

int main()
{
    scanf("%d %d", &L, &K);
    scanf("%s", digits);

    for (int i = 0; i + K - 1 < L; i++)
    {
        long long res = get_at(i);
        if (is_prime(res))
        {
            for (int j = i; j - i < K; j++)
                putchar(digits[j]);
            return 0;
        }
    }

    printf("404");

    return 0;
}
