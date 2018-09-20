#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char N1[16];
char N2[16];

int tag;
unsigned long long radix;

unsigned long long to_deci(char number[16], unsigned long long radix)
{
    unsigned long long d = 0;
    unsigned long long power = 1;
    for (unsigned long long i = 0; i < strlen(number); i++)
    {
        unsigned long long k = number[i] >= 'a' ? number[i] - 'a' + 10 : number[i] - '0';
        d += k * power;
        power *= radix;
    }
    return d;
}

void revstr(char c[16])
{
    for (unsigned long long i = 0; i < strlen(c) / 2; i++)
    {
        unsigned long long ch = c[i];
        c[i] = c[strlen(c) - 1 - i];
        c[strlen(c) - 1 - i] = ch;
    }
}

unsigned long long get_minradix(char c[16])
{
    unsigned long long min_r = c[0] >= 'a' ? c[0] - 'a' + 10 : c[0] - '0';
    for (unsigned long long i = 1; i < strlen(c); i++)
    {
        unsigned long long t = c[i] >= 'a' ? c[i] - 'a' + 10 : c[i] - '0';
        min_r = t < min_r ? t : min_r;
    }
    return min_r + 1;
}

int main()
{
    scanf("%s %s %d %lld", N1, N2, &tag, &radix);
    revstr(N1);
    revstr(N2);
    if (tag != 1)
    {
        char tmpchar[16];
        strcpy(tmpchar, N1);
        strcpy(N1, N2);
        strcpy(N2, tmpchar);
    }

    unsigned long long k = to_deci(N1, radix);

    unsigned long long low = get_minradix(N2);
    unsigned long long high = max(k + 1, get_minradix(N2));
    unsigned long long mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        unsigned long long k0 = to_deci(N2, mid);
        if (k == k0)
        {
            printf("%llu", mid);
            return 0;
        } else if (k < k0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    /*for (long long i = get_minradix(N2); i <= max(k + 1, get_minradix(N2)); i++)
    {
        long long k0 = to_deci(N2, i);
        if (k == k0)
        {
            printf("%lld", i);
            return 0;
        }
    }*/

    printf("Impossible");

    return 0;
}
