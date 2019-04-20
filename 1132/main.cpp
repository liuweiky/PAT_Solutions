#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        char buf[32];
        scanf("%s", buf);
        int len = strlen(buf);

        long long num;
        sscanf(buf, "%lld", &num);

        long long p = pow(10, len / 2);

        long long a = num / p;
        long long b = num % p;

        a == 0 || b == 0 || num % (a * b) != 0 ? printf("No\n") : printf("Yes\n");
    }

    return 0;
}
