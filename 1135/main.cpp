#include <cstdio>
//#include <cstdlib>

#define MAX_N 64

#define RED -1
#define BLACK 1

using namespace std;

struct node
{
    int type, data;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

int K, N;
node* root = NULL;

int black_cnt = -1;
bool is_rbtree = true;

void insert_bst(int data, node* & r, int type)
{
    if (r == NULL)
    {
        r = new node;
        r->data = data;
        r->type = type;
        return;
    }

    if (data < r->data)
        insert_bst(data, r->lc, type);
    else
        insert_bst(data, r->rc, type);
}

int dfs(node* r)
{
    if (!is_rbtree)
        return -1;

    if (r == NULL)
    {
        return 1;
    }

    /*system("pause");
    printf("%d\n", r->data);*/

    if (r->type == RED)
    {
        if ((r->lc != NULL && r->lc->type == RED) || (r->rc != NULL && r->rc->type == RED))
        {
            is_rbtree = false;
            return -1;
        }
    }

    int lcnt = dfs(r->lc);
    int rcnt = dfs(r->rc);

    if (lcnt != rcnt)
        is_rbtree = false;
    return r->type == BLACK ? lcnt + 1 : lcnt;
}

void pre(node* r)
{
    if (r == NULL)
        return;
    printf("%d ", r->data);
    pre(r->lc);
    pre(r->rc);
}

int main()
{
    scanf("%d", &K);
    while (K--)
    {
        root = NULL;
        black_cnt = -1;
        is_rbtree = true;

        scanf("%d", &N);

        for (int i = 0; i < N; i++)
        {
            int t;
            scanf("%d", &t);
            if (t < 0)
                insert_bst(-t, root, RED);
            else
                insert_bst(t, root, BLACK);
        }

        if (root->type == RED)
        {
            printf("No\n");
            continue;
        }

        //pre(root);

        dfs(root);
        if (is_rbtree)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
