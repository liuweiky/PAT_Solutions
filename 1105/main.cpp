#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX_N 10240

using namespace std;

int N, n, m;
int numbers[MAX_N];
int matrix[1000][1000];

int main()
{
    fill_n(&matrix[0][0], 1000 * 1000, -1);

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &numbers[i]);

    sort(numbers, numbers + N);

    n = sqrt(N);
    while (N % n != 0)
        n--;
    m = N / n;

    int ptr = N - 1;

    int i = 0, j = 0;

    int dir = 1;

    while (ptr >= 0)
    {
        matrix[i][j] = numbers[ptr--];
        if (dir == 1)   //right
        {
            if (j + 1 >= n || matrix[i][j + 1] != -1)
            {
                dir = 2;
                i++;
            }
            else
                j++;
        }
        else if (dir == 2)  //down
        {
            if (i + 1 >= m || matrix[i + 1][j] != -1)
            {
                dir = 3;
                j--;
            }
            else
                i++;
        }
        else if (dir == 3)  // left
        {
            if (j - 1 < 0 || matrix[i][j - 1] != -1)
            {
                dir = 4;
                i--;
            }
            else
                j--;
        }
        else if (dir == 4)  //up
        {
            if (i - 1 < 0 || matrix[i - 1][j] != -1)
            {
                dir = 1;
                j++;
            }
            else
                i--;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (i != 0)
            printf("\n");
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", matrix[i][j]);
        }
    }

    return 0;
}
