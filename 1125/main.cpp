#include <cstdio>
#include <algorithm>

#define MAX_N 10240

using namespace std;

int arr[MAX_N];
int N;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + N);
    int ans = arr[0] / 2 + arr[1] / 2;

    for (int i = 2; i < N; i++)
        ans = (ans + arr[i]) / 2;

    printf("%d", ans);

    return 0;
}
