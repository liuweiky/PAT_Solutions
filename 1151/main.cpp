#include <cstdio>
#include <set>

#define MAX_N 10240

using namespace std;

struct node
{
    int key;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

int inorder[MAX_N];
int preorder[MAX_N];
int M, N;
set<int> ids;

node* root = NULL;

node* rebuild(int il, int ir, int pl, int pr)
{
    if (il > ir || pl > pr)
        return NULL;
    int head = preorder[pl];
    node* n = new node;
    n->key = head;
    int k;
    for (int j = il; j <= ir; j++)
    {
        if (inorder[j] == head)
        {
            k = j;
            break;
        }
    }
    n->lc = rebuild(il, k - 1, pl + 1, pl + k - il);
    n->rc = rebuild(k + 1, ir, pl + k -il + 1, pr);
    return n;
}

node* lca(node* r, int u, int v)
{
    if (r == NULL)
        return NULL;
    if (r->key == u || r->key == v)
        return r;
    node* lc = lca(r->lc, u, v);
    node* rc = lca(r->rc, u, v);
    if (lc != NULL && rc != NULL)
        return r;
    else if (lc == NULL)
        return rc;
    else
        return lc;
}

int main()
{
    scanf("%d %d", &M, &N);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &inorder[i]);
        ids.insert(inorder[i]);
    }

    for (int i = 1; i <= N; i++)
        scanf("%d", &preorder[i]);

    root = rebuild(1, N, 1, N);

    while (M--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if (ids.find(u) == ids.end())
        {
            if (ids.find(v) == ids.end())
                printf("ERROR: %d and %d are not found.\n", u, v);
            else
                printf("ERROR: %d is not found.\n", u);
            continue;
        }
        else if (ids.find(v) == ids.end())
        {
            printf("ERROR: %d is not found.\n", v);
            continue;
        }

        node* f = lca(root, u, v);
        if (f->key == u)
            printf("%d is an ancestor of %d.\n", u, v);
        else if (f->key == v)
            printf("%d is an ancestor of %d.\n", v, u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, f->key);
    }

    return 0;
}
