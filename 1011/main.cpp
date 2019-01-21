#include <cstdio>

using namespace std;

int main()
{
    double ans = 1;

    for (int i = 0; i < 3; i++)
    {
        int max_j = 0;
        double max_k = 0;
        for (int j = 0; j < 3; j++)
        {
            double k;
            scanf("%lf", &k);
            if (k > max_k)
            {
                max_k = k;
                max_j = j;
            }
        }
        ans *= max_k;
        switch (max_j)
        {
        case 0:
            printf("W ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("L ");
            break;
        }
    }

    printf("%.2f", (ans * 0.65 - 1) * 2);

    return 0;
}
