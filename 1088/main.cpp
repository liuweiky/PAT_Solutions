#include <cstdio>
#include <cmath>

using namespace std;

struct frac
{
    long long up, down;
};

frac lhs, rhs, ans;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

frac reduction(frac f)  // 分数分子分母化简
{
    if (f.down < 0)
    {
        f.up = -f.up;
        f.down = -f.down;
    }

    if (f.up == 0)
        f.down = 1;
    else
    {
        long long g = gcd(abs(f.up), f.down);
        f.up /= g;
        f.down /= g;
    }
    return f;
}

void print_frac(frac f)
{
    f = reduction(f);

    if (f.up == 0)
    {
        printf("0");
        return;
    } else if (f.down == 0)
    {
        printf("Inf");
        return;
    }

    bool neg = f.up < 0;

    if (neg)
        printf("(");

    if (f.down == 1)
        printf("%lld", f.up);
    else
    {
        if (abs(f.up) > f.down)
        {
            printf("%lld ", f.up / f.down);
            f.up = abs(f.up);
            f.up %= f.down;
        }
        printf("%lld/%lld", f.up, f.down);
    }
    if (neg)
        printf(")");
}

frac add(frac lhs, frac rhs)
{
    frac res;
    res.up = lhs.up * rhs.down + rhs.up * lhs.down;
    res.down = lhs.down * rhs.down;
    //res = reduction(res);
    return res;
}

frac sub(frac lhs, frac rhs)
{
    frac neg_rhs = rhs;
    neg_rhs.up = -neg_rhs.up;

    return add(lhs, neg_rhs);
}

frac mul(frac lhs, frac rhs)
{
    frac res;
    res.up = lhs.up * rhs.up;
    res.down = lhs.down * rhs.down;
    //res = reduction(res);
    return res;
}

frac div(frac lhs, frac rhs)
{
    frac new_rhs;
    new_rhs.up = rhs.down;
    new_rhs.down = rhs.up;
    return mul(lhs, new_rhs);
}

int main()
{
    scanf("%lld/%lld %lld/%lld", &lhs.up, &lhs.down, &rhs.up, &rhs.down);

    print_frac(lhs);
    printf(" + ");
    print_frac(rhs);
    printf(" = ");
    print_frac(add(lhs, rhs));
    printf("\n");

    print_frac(lhs);
    printf(" - ");
    print_frac(rhs);
    printf(" = ");
    print_frac(sub(lhs, rhs));
    printf("\n");

    print_frac(lhs);
    printf(" * ");
    print_frac(rhs);
    printf(" = ");
    print_frac(mul(lhs, rhs));
    printf("\n");

    print_frac(lhs);
    printf(" / ");
    print_frac(rhs);
    printf(" = ");
    print_frac(div(lhs, rhs));

    return 0;
}
