#include <cstdio>

#define MAX_N 102400

using namespace std;

int N;
double numbers[MAX_N];

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%lf", &numbers[i]);

    double sum = 0;

    for (int i = 0; i < N; i++)
    {
        int s = i, t = N - i;
        sum += numbers[i] * (s + 1) * t;
        //sum += numbers[i] * t;
    }

    printf("%.2f", sum);
    return 0;
}
