#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 128

using namespace std;

int orignum[MAX_N];
int tempnum[MAX_N];
int destnum[MAX_N];
int N;

bool check()
{
    for (int i = 1 ; i <= N; i++)
        if (destnum[i] != tempnum[i])
            return false;
    return true;
}

bool insertion()
{
    for (int i = 2; i <= N; i++)
    {
        sort(tempnum + 1, tempnum  + 1 + i);
        if (check())
        {
            sort(tempnum + 1, tempnum  + 1 + i + 1);
            return true;
        }
    }
    return false;
}

void down_adjust(int s, int n)
{
    int i = s, j = 2 * i;
    while (j <= n)
    {
        if (j + 1 <= n && tempnum[j] < tempnum[j + 1])
            j++;
        swap(tempnum[i], tempnum[j]);
        i = j;
        j = 2 * i;
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &orignum[i]);

    for (int i = 1; i <= N; i++)
        scanf("%d", &destnum[i]);

    memcpy(tempnum, orignum, MAX_N * sizeof(int));

    if (insertion())
    {
        printf("Insertion Sort\n");
        for (int i = 1; i <= N; i++)
        {
            if (i != 1)
                printf(" ");
            printf("%d", tempnum[i]);
        }
        return 0;
    }

    memcpy(tempnum, destnum, MAX_N * sizeof(int));

    for (int j = N; j >= 1; j--)
    {
        if (tempnum[j] < tempnum[1])
        {
            swap(tempnum[j], tempnum[1]);
            down_adjust(1, j - 1);
            break;
        }
    }

    printf("Heap Sort\n");
    for (int i = 1; i <= N; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", tempnum[i]);
    }

    return 0;
}
