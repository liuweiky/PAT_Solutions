#include <cstdio>
#include <algorithm>

using namespace std;

int N;

struct frac
{
    long long up, down;
};

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

frac reduction(frac f)
{
    if (f.down < 0)
    {
        f.up = -f.up;
        f.down = -f.down;
    }
    if (f.up == 0)
    {
        f.down = 1;
        return f;
    }
    if (f.down == 0)
    {
        f.up = 1;
        return f;
    }

    long long g = gcd(abs(f.up), f.down);
    f.up /= g;
    f.down /= g;
    return f;
}

void print_frac(frac f)
{
    f = reduction(f);
    if (f.up == 0)
    {
        printf("0");
        return;
    }
    if (f.down == 1)
    {
        printf("%lld", f.up);
        return;
    }
    if (f.down == 0)
    {
        printf("Inf");
        return;
    }

    if (abs(f.up) > f.down)
    {
        printf("%lld ", f.up / f.down);
        f.up = abs(f.up) % f.down;
        printf("%lld/%lld", f.up, f.down);
    }
    else
        printf("%lld/%lld", f.up, f.down);
}

frac add(frac lhs, frac rhs)
{
    frac f;
    f.up = lhs.up * rhs.down + lhs.down * rhs.up;
    f.down = lhs.down * rhs.down;
    return f;
}

int main()
{
    frac f;
    f.up = 0;
    f.down = 1;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        frac ft;
        scanf("%lld/%lld", &ft.up, &ft.down);
        f = add(f, ft);
    }

    print_frac(f);

    return 0;
}
