#include <cstdio>
#include <algorithm>
#include <climits>

#define MAX_N 102400

using namespace std;

long long N, p;
long long seq[MAX_N];

int main()
{
    scanf("%lld %lld", &N, &p);

    for (int i = 0; i < N; i++)
        scanf("%lld", &seq[i]);

    sort(seq, seq + N);

    int max_len = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        int last_best = -1;
        int low = i, high = N - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (seq[mid] > seq[i] * p)
                high = mid - 1;
            else
            {
                low = mid + 1;
                last_best = max(last_best, mid);
            }
        }
        if (last_best != -1)
            max_len = max(max_len, last_best - i + 1);
    }

    printf("%d", max_len);

    return 0;
}
