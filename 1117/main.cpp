#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int more_than[MAX_N];
int N;

int main()
{
    fill_n(more_than, MAX_N, 0);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &more_than[i]);

    sort(more_than, more_than + N);

    int E = 0;

    for (int i = N; i > 0; i--)
    {
        if (more_than[N - i] >= i + 1)
        {
            E = i;
            break;
        }
    }

    printf("%d", E);

    return 0;
}
