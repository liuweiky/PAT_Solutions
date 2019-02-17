#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int S1[200001];
int S2[200001];

int main()
{
    fill_n(S1, 200001, INT_MAX);
    fill_n(S2, 200001, INT_MAX);
    int N1, N2;

    scanf("%d", &N1);

    for (int i = 0; i < N1; i++)
        scanf("%d", &S1[i]);

    scanf("%d", &N2);

    for (int i = 0; i < N2; i++)
        scanf("%d", &S2[i]);

    int mid_cnt = (N1 + N2 + 1) / 2;
    int cnt = 0;
    int median;
    int i = 0, j = 0;

    while (cnt != mid_cnt)
    {
        if (S1[i] < S2[j])
            median = S1[i++];
        else
            median = S2[j++];
        cnt++;
    }

    printf("%d", median);

    return 0;
}
