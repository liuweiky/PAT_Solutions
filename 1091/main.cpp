#include <cstdio>
#include <queue>
#include <algorithm>

#define MAX_M 1300
#define MAX_N 130
#define MAX_L 64

using namespace std;

int M, N, L, T;

int cubic[MAX_L][MAX_M][MAX_N];
bool visit[MAX_L][MAX_M][MAX_N];

struct xyz
{
    int x, y, z;
};

int bfs(int i, int j, int k)
{
    queue<xyz> q;
    xyz p;
    p.x = i; p.y = j; p.z = k;

    q.push(p);

    int core = 0;

    while (!q.empty())
    {
        xyz pt = q.front();
        q.pop();
        if (!visit[pt.x][pt.y][pt.z])
        {
            visit[pt.x][pt.y][pt.z] = true;
            core++;
            xyz new_pt;
            if (pt.x + 1 < L && !visit[pt.x + 1][pt.y][pt.z] && cubic[pt.x + 1][pt.y][pt.z])
            {
                new_pt.x = pt.x + 1; new_pt.y = pt.y; new_pt.z = pt.z;
                q.push(new_pt);
            }
            if (pt.x - 1 >= 0 && !visit[pt.x - 1][pt.y][pt.z] && cubic[pt.x - 1][pt.y][pt.z])
            {
                new_pt.x = pt.x - 1; new_pt.y = pt.y; new_pt.z = pt.z;
                q.push(new_pt);
            }
            if (pt.y + 1 < M && !visit[pt.x][pt.y + 1][pt.z] && cubic[pt.x][pt.y + 1][pt.z])
            {
                new_pt.x = pt.x; new_pt.y = pt.y + 1; new_pt.z = pt.z;
                q.push(new_pt);
            }
            if (pt.y - 1 >= 0 && !visit[pt.x][pt.y - 1][pt.z] && cubic[pt.x][pt.y - 1][pt.z])
            {
                new_pt.x = pt.x; new_pt.y = pt.y - 1; new_pt.z = pt.z;
                q.push(new_pt);
            }
            if (pt.z + 1 < N && !visit[pt.x][pt.y][pt.z + 1] && cubic[pt.x][pt.y][pt.z + 1])
            {
                new_pt.x = pt.x; new_pt.y = pt.y; new_pt.z = pt.z + 1;
                q.push(new_pt);
            }
            if (pt.z - 1 >= 0 && !visit[pt.x][pt.y][pt.z - 1] && cubic[pt.x][pt.y][pt.z - 1])
            {
                new_pt.x = pt.x; new_pt.y = pt.y; new_pt.z = pt.z - 1;
                q.push(new_pt);
            }
        }
    }
    if (core >= T)
        return core;
    return 0;
}

int main()
{
    fill_n(&visit[0][0][0], MAX_L * MAX_M * MAX_N, false);
    scanf("%d %d %d %d", &M, &N, &L, &T);

    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &cubic[i][j][k]);

    int vol = 0;

    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                if (!visit[i][j][k] && cubic[i][j][k])
                    vol += bfs(i, j, k);

    printf("%d", vol);

    return 0;
}
