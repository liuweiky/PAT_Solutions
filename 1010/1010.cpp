#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 16

char N1[MAX_N];
char N2[MAX_N];
int tag;
unsigned long long radix;

int main()
{
    scanf("%s %s %d %llu", N1, N2, &tag, &radix);
    char* origin;
    char* target;

    if (tag == 1)
    {
        target = N1;
        origin = N2;
    }
    else
    {
        target = N2;
        origin = N1;
    }

    unsigned long long target_10 = 0;
    int target_len = strlen(target), origin_len = strlen(origin);
    reverse(target, target + target_len);
    reverse(origin, origin + origin_len);

    unsigned long long base = 1;
    for (int i = 0; i < target_len; i++)
    {
        if (target[i] >= '0' && target[i] <= '9')
        {
            target_10 += base * (target[i] - '0');
        }
        else
        {
            target_10 += base * (target[i] - 'a' + 10);
        }

        base *= radix;
    }

    int min_radix = 0;

    for (int i = 0; i < origin_len; i++)
    {
        if (origin[i] >= '0' && origin[i] <= '9')
        {
            min_radix = max(min_radix, origin[i] - '0');
        }
        else
        {
            min_radix = max(min_radix, origin[i] - 'a' + 10);
        }
    }
    min_radix++;

    unsigned long long max_radix = max((unsigned long long) min_radix, target_10 + 1);

    unsigned long long low = min_radix, high = max_radix;

    while (low <= high)
    {
        unsigned long long mid = (low + high) / 2;
        unsigned long long origin_10 = 0;
        base = 1;
        for (int i = 0; i < origin_len; i++)
        {
            if (origin[i] >= '0' && origin[i] <= '9')
            {
                origin_10 += base * (origin[i] - '0');
            }
            else
            {
                origin_10 += base * (origin[i] - 'a' + 10);
            }
            base *= mid;
        }
        if (target_10 == origin_10)
        {
            printf("%d", mid);
            return 0;
        }
        else if (target_10 > origin_10)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Impossible");

    return 0;
}
