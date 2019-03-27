#include <cstdio>
#include <algorithm>
#include <queue>

#define MAX_N 128

using namespace std;

struct node
{
    int data;
    int lc, rc;
    node() {lc = rc = -1;}
};

node tree[MAX_N];
int inorder[MAX_N];
int N;
int ptr = 0;

void in_order(int r)
{
    if (r == -1)
        return;
    in_order(tree[r].lc);
    tree[r].data = inorder[ptr++];
    in_order(tree[r].rc);
}

void bfs()
{
    queue<int> q;
    q.push(0);

    bool flag = false;

    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        if (flag)
            printf(" ");
        flag = true;
        printf("%d", tree[r].data);
        if (tree[r].lc != -1)
            q.push(tree[r].lc);
        if (tree[r].rc != -1)
            q.push(tree[r].rc);
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &tree[i].lc, &tree[i].rc);

    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    sort(inorder, inorder + N);

    in_order(0);

    bfs();

    return 0;
}
