#include <cstdio>
#include <cstring>
#include <vector>

#define MAX_N 10240

using namespace std;

int K;
int numbers[MAX_N];
int sum[MAX_N];
int from[MAX_N];

int main()
{
    scanf("%d", &K);
    bool all_neg = true;
    for (int i = 1; i <= K; i++)
    {
        scanf("%d", &numbers[i]);
        from[i] = sum[i] = numbers[i];
        if (numbers[i] >= 0)
            all_neg = false;
    }
    if (all_neg)
    {
        printf("%d %d %d", 0, numbers[1], numbers[K]);
        return 0;
    }

    int max_sum = numbers[1];
    int max_idx = 1;

    for (int i = 2; i <= K; i++)
    {
        if (numbers[i] + sum[i - 1] > numbers[i])
        {
           sum[i] = numbers[i] + sum[i - 1];
           from[i] = from[i - 1];

        }
        if (max_sum < sum[i])
        {
            max_sum = sum[i];
            max_idx = i;
        }

    }

    printf("%d %d %d", max_sum, from[max_idx], numbers[max_idx]);

    return 0;
}
