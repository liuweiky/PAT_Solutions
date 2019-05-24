#include <cstdio>
#include <vector>

#define MAX_N 1024

using namespace std;

int heap[MAX_N];
int N;

void dfs(int r, vector<int> path)
{
    path.push_back(heap[r]);
    if (r * 2 > N)
    {
        for (int i = 0; i < path.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
        return;
    }
    if (r * 2 + 1 <= N)
        dfs(r * 2 + 1, path);
    dfs(r * 2, path);
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &heap[i]);

    dfs(1, vector<int>());

    bool maxx = true;
    for (int i = 1; i <= N / 2 && maxx; i++)
    {
        if (heap[i] < heap[i * 2])
            maxx = false;
        else if (i * 2 + 1 <= N && heap[i] < heap[i * 2 + 1])
            maxx = false;
    }

    if (maxx)
    {
        printf("Max Heap");
        return 0;
    }

    bool minn = true;

    for (int i = 1; i <= N / 2 && minn; i++)
    {
        if (heap[i] > heap[i * 2])
            minn = false;
        else if (i * 2 + 1 <= N && heap[i] > heap[i * 2 + 1])
            minn = false;
    }

    if (minn)
        printf("Min Heap");
    else
        printf("Not Heap");

    return 0;
}
