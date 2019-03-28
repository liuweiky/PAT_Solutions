#include <cstdio>
#include <algorithm>
#include <queue>

#define MAX_N 32

using namespace std;

struct node
{
    int lc, rc;
    int pos;
    node() {lc = rc = pos = -1;}
};

bool is_root[MAX_N];
node tree[MAX_N];
int N, root;
int pos_nodeid[MAX_N];

void bfs()
{
    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        pos_nodeid[tree[n].pos] = n;
        if (tree[n].lc != -1)
        {
            if (tree[n].pos * 2 >= MAX_N)
                return;
            tree[tree[n].lc].pos = tree[n].pos * 2;
            q.push(tree[n].lc);
        }
        if (tree[n].rc != -1)
        {
            if (tree[n].pos * 2 + 1>= MAX_N)
                return;
            tree[tree[n].rc].pos = tree[n].pos * 2 + 1;
            q.push(tree[n].rc);
        }
    }
}

int main()
{
    fill_n(is_root, MAX_N, true);
    fill_n(pos_nodeid, MAX_N, -1);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char buf[5];
        int id;
        scanf("%s", buf);
        if (buf[0] != '-')
        {
            sscanf(buf, "%d", &id);
            tree[i].lc = id;
            is_root[id] = false;
        }
        scanf("%s", buf);
        if (buf[0] != '-')
        {
            sscanf(buf, "%d", &id);
            tree[i].rc = id;
            is_root[id] = false;
        }
    }

    for (int i = 0; i < N; i++)
        if (is_root[i])
        {
            root = i;
            break;
        }

    tree[root].pos = 1;

    bfs();

    bool is_cbt = true;

    for (int i = 1; i <= N; i++)
    {
        if (pos_nodeid[i] == -1)
        {
            is_cbt = false;
            break;
        }
    }

    if (!is_cbt)
        printf("NO %d", root);
    else
        printf("YES %d", pos_nodeid[N]);

    return 0;
}
