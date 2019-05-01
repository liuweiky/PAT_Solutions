#include <cstdio>

#define MAX_N 51200

using namespace std;

int preorder[MAX_N];
int inorder[MAX_N];
int N;

bool flag = false;

struct node
{
    int data;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

node* root = NULL;

node* rebuild(int pl, int pr, int il, int ir)
{
    if (pl > pr || il > ir)
        return NULL;

    node* n = new node;
    n->data = preorder[pl];

    int k;

    for (int i = il; i <= ir; i++)
    {
        if (n->data == inorder[i])
        {
            k = i;
            break;
        }
    }

    n->lc = rebuild(pl + 1, pl + k - il, il, k - 1);
    n->rc = rebuild(pl + k - il + 1, pr, k + 1, ir);
    return n;
}

void post(node* r)
{
    if (r == NULL || flag)
        return;
    post(r->lc);
    post(r->rc);
    if (!flag)
        printf("%d", r->data);
    flag = true;
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &preorder[i]);

    for (int i = 1; i <= N; i++)
        scanf("%d", &inorder[i]);

    root = rebuild(1, N, 1, N);
    post(root);

    return 0;
}
