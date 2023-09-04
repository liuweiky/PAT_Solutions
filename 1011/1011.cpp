#include <cstdio>

using namespace std;

int main()
{
    double W, T, L;
    double result = 1;

    for (int i = 0; i < 3; i++)
    {
        scanf("%lf %lf %lf", &W, &T, &L);
        if (W > T && W > L)
        {
            result *= W;
            printf("W ");
        }
        else if (T > W && T > L)
        {
            result *= T;
            printf("T ");
        }
        else
        {
            result *= L;
            printf("L ");
        }
    }

    printf("%.2f", ((result * 0.65) - 1) * 2);

    return 0;
}
