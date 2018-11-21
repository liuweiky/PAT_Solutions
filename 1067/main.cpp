#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 102400

using namespace std;

int N;
int numbers[MAX_N];
int number_pos[MAX_N];
int min_not_in_pos; // 记忆上次搜到的最小不在其位置上的数

int check()
{
    for (int i = min_not_in_pos; i < N; i++)
        if (numbers[i] != i)
        {
            min_not_in_pos = i;
            return i;
        }
    return -1;
}

int find_num(int n)
{
    for (int i = 0; i < N; i++)
        if (numbers[i] == n)
            return i;
    return 0;
}

void print_arr()
{
    for (int i = 0; i < N; i++)
        printf("%d\t", numbers[i]);
    printf("\n");
}

int main()
{
    int zero_pos;
    min_not_in_pos = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
        number_pos[numbers[i]] = i;
        if (numbers[i] == 0)
            zero_pos = i;
    }

    int cnt = 0;
    while (true)
    {
        while (zero_pos != 0)
        {
            //print_arr();
            int n = zero_pos;
            int idx = number_pos[n];
            swap(numbers[zero_pos], numbers[idx]);
            number_pos[n] = n;
            cnt++;
            zero_pos = idx;
        }
        int c = check();
        if (c == -1)
            break;
        else
        {
            number_pos[numbers[c]] = 0;
            swap(numbers[zero_pos], numbers[c]);
            cnt++;
            zero_pos = c;
        }
    }

    printf("%d", cnt);
    return 0;
}
