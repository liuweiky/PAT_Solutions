#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int digit[512];
int rev_digit[512];

int N, D;

bool is_prime(int n)
{
    if (n == 1 || n == 0)
        return false;
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int rev_num()
{
    int p = 0;
    while (N != 0)
    {
        digit[p++] = N % D;
        N /= D;
    }
    memcpy(rev_digit, digit, p * sizeof(int));
    reverse(rev_digit, rev_digit + p);
    return p;
}

int get_num(int len)
{
    int power = 1;
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        num += power * rev_digit[i];
        power *= D;
    }
    return num;
}

int main()
{
    while (scanf("%d %d", &N, &D) == 2)
    {
        if (!is_prime(N))
        {
            printf("No\n");
            continue;
        }
        fill_n(digit, 512, -1);
        fill_n(rev_digit, 512, -1);
        int len = rev_num();
        if (is_prime(get_num(len)))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
