#include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);

    int t = 0, floor = 0;

    for (int i = 0; i < N; i++)
    {
        int req;
        scanf("%d", &req);

        if (req > floor)
        {
            t += (req - floor) * 6 + 5;
        }
        else
        {
            t += (floor - req) * 4 + 5;
        }
        floor = req;
    }

    printf("%d", t);

    return 0;
}
