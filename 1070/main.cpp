#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int N, D;

struct MoonCake
{
    double amount, price, avg;
};

MoonCake* mks[MAX_N];

bool cmp(MoonCake* m1, MoonCake* m2)
{
    return m1->avg > m2->avg;
}

int main()
{
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++)
    {
        MoonCake* m = new MoonCake;
        mks[i] = m;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &mks[i]->amount);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &mks[i]->price);
        mks[i]->avg = mks[i]->price / mks[i]->amount;
    }

    sort(mks, mks + N, cmp);

    double p = 0;

    for (int i = 0; i < N; i++)
    {
        if (mks[i]->amount >= D)
        {
            p += (D * mks[i]->avg);
            break;
        } else
        {
            p += mks[i]->price;
            D -= mks[i]->amount;
        }
    }

    printf("%.2f", p);

    return 0;
}
