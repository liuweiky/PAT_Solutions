#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

bool face_val_used[512];
int coins[MAX_N];
int N, M;

int main()
{
    fill_n(face_val_used, 512, 0);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &coins[i]);

    sort(coins, coins + N);

    int tag = 1;

    for (int i = 0; i < N && tag; i++)
        if (!face_val_used[coins[i]])
        {
            face_val_used[coins[i]] = 1;
            for (int j = N - 1; j > i && tag; j--)
            {
                if (coins[i] + coins[j] == M)
                {
                    printf("%d %d", coins[i], coins[j]);
                    tag = 0;
                }
            }
        }

    if (tag)
        printf("No Solution");

    return 0;
}
