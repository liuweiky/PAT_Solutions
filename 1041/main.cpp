#include <cstdio>
#include <cstring>

#define MAX_N 102400

using namespace std;

int N;

int bets_map[MAX_N];
int people_bets[MAX_N];

int main()
{
    scanf("%d", &N);

    memset(bets_map, 0, MAX_N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &people_bets[i]);
        bets_map[people_bets[i]]++;
    }

    int tag = 1;

    for (int i = 0; i < N; i++)
        if (bets_map[people_bets[i]] == 1)
        {
            printf("%d", people_bets[i]);
            tag = 0;
            break;
        }

    if (tag)
        printf("None");

    return 0;
}
