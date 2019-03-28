#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int level_cnt[MAX_N];
int max_lev = -1;
int N;

struct node
{
    int data;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

node* root = NULL;

void insert_bst(node* & n, int d)
{
    if (n == NULL)
    {
        n = new node;
        n->data = d;
        return;
    }
    if (d <= n->data)
        insert_bst(n->lc, d);
    else
        insert_bst(n->rc, d);
}

void dfs(node* n, int lev)
{
    if (n == NULL)
        return;
    max_lev = max(max_lev, lev);
    level_cnt[lev]++;
    dfs(n->lc, lev + 1);
    dfs(n->rc, lev + 1);
}

int main()
{
    fill_n(level_cnt, MAX_N, 0);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int d;
        scanf("%d", &d);
        insert_bst(root, d);
    }

    dfs(root, 1);

    printf("%d + %d = %d", level_cnt[max_lev], level_cnt[max_lev - 1], level_cnt[max_lev] + level_cnt[max_lev - 1]);

    return 0;
}
