#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    long long power = 10, cnt = 0;

    bool has_zero = false;

    while (!has_zero)
    {
        has_zero = (N / power == 0);
        cnt += (N / power) * (power / 10);
        if ((N / (power / 10)) % 10 == 0);
            //cnt += (N / power) * (power / 10);
        else if ((N / (power / 10)) % 10 == 1)
            //cnt += (N / power) * (power / 10);
            cnt += N % power - (power / 10 - 1);
        else
            //cnt += (N / power) * (power / 10);
            cnt += power / 10;
        power *= 10;
    }

    printf("%lld", cnt);

    return 0;
}
