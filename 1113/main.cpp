#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int N;
int numbers[MAX_N];

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &numbers[i]);

    sort(numbers + 1, numbers + 1 + N);
    numbers[0] = 0;
    for (int i = 1; i <= N; i++)
        numbers[i] = numbers[i] + numbers[i - 1];

    if (N % 2 == 0)
    {
        printf("0 ");
        printf("%d", numbers[N] - 2 * numbers[N / 2]);
    }
    else
    {
        printf("1 ");
        if (abs(numbers[N] - 2 * numbers[N / 2]) > abs(numbers[N] - 2 * numbers[N / 2 + 1]))
            printf("%d", abs(numbers[N] - 2 * numbers[N / 2]));
        else
            printf("%d", abs(numbers[N] - 2 * numbers[N / 2 + 1]));
    }

    return 0;
}
