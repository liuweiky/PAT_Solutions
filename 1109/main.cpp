#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 16000
#define MAX_K 12

using namespace std;

struct people
{
    string name;
    int height;
};

int N, K;

vector<people> ps;

people matrix[MAX_K][MAX_N / MAX_K];
people tmp[MAX_K][MAX_N / MAX_K];
people endline[MAX_N];
people tmpendline[MAX_N];

bool cmp(people& p1, people& p2)
{
    if (p1.height != p2.height)
        return p1.height < p2.height;
    return p1.name > p2.name;
}

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        char buf[32];
        int h;
        scanf("%s %d", buf, &h);
        people p;
        p.height = h;
        p.name = buf;
        ps.push_back(p);
    }

    sort(ps.begin(), ps.end(), cmp);

    int ptr = 0;

    for (int i = 0; i < K - 1; i++)
        for (int j = 0; j < N / K; j++)
            tmp[i][j] = ps[ptr++];

    int t = 0;

    while (ptr < N)
        tmpendline[t++] = ps[ptr++];

    for (int i = 0; i < K - 1; i++)
    {
        int dir = -1, off = 1, mid = N / K / 2;
        for (int j = N / K - 1; j >= 0; j--)
        {
            if (j == N / K - 1)
                matrix[i][mid] = tmp[i][j];
            else
            {
                matrix[i][mid + dir * off] = tmp[i][j];
                if (dir == 1)
                    off++;
                dir = -dir;
            }
        }
    }

    int dir = -1, off = 1, mid = t / 2;

    for (int i = t - 1; i >= 0; i--)
    {
        if (i == t - 1)
            endline[mid] = tmpendline[i];
        else
        {
            endline[mid + dir * off] = tmpendline[i];
            if (dir == 1)
                off++;
            dir = -dir;
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%s", endline[i].name.c_str());
    }

    for (int i = K - 2; i >= 0; i--)
    {
        printf("\n");
        for (int j = 0; j < N / K; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%s", matrix[i][j].name.c_str());
        }
    }


    return 0;
}
