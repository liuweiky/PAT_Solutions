#include <cstdio>
#include <vector>

using namespace std;

long long N, b;
vector<long long> base_num;

void decimal2base()
{
    while(N)
    {
        base_num.push_back(N % b);
        N /= b;
    }
}

int main()
{
    scanf("%lld %lld", &N, &b);
    decimal2base();

    bool flag = true;

    for (long long i = 0; i <= base_num.size() / 2; i++)
        if (base_num[i] != base_num[base_num.size() - 1 - i])
        {
            flag = false;
            break;
        }

    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    for (long long i = base_num.size() - 1; i >= 0; i--)
    {
        printf("%lld", base_num[i]);
        if (i != 0)
            printf(" ");
    }
    return 0;
}
