#include <cstdio>

#define MAX_N 1024

using namespace std;

struct node
{
    int data;
    node* l;
    node* r;
    node() {l = r = NULL;}
};

int N;

int origin_order[MAX_N];
int pre_order[MAX_N];
int pre_mirror_order[MAX_N];
int post_order[MAX_N];
int post_mirror_order[MAX_N];

int pre_ptr = 0, pre_mir_ptr = 0, post_ptr = 0, post_mir_ptr = 0;

void bst_insert(node* &root, int d)
{
    if (root == NULL)
    {
        root = new node;
        root->data = d;
        return;
    }
    if (d < root->data)
        bst_insert(root->l, d);
    else
        bst_insert(root->r, d);
}

void preorder(node* r)
{
    if (r == NULL)
        return;
    pre_order[pre_ptr++] = r->data;
    preorder(r->l);
    preorder(r->r);
}

void premirorder(node* r)
{
    if (r == NULL)
        return;
    pre_mirror_order[pre_mir_ptr++] = r->data;
    premirorder(r->r);
    premirorder(r->l);
}

bool check_pre()
{
    for (int i = 0; i < N; i++)
        if (pre_order[i] != origin_order[i])
            return false;
    return true;
}

bool check_pre_mir()
{
    for (int i = 0; i < N; i++)
        if (pre_mirror_order[i] != origin_order[i])
            return false;
    return true;
}

void postorder(node* r)
{
    if (r == NULL)
        return;
    postorder(r->l);
    postorder(r->r);
    post_order[post_ptr++] = r->data;
}

void postmirorder(node* r)
{
    if (r == NULL)
        return;
    postmirorder(r->r);
    postmirorder(r->l);
    post_mirror_order[post_mir_ptr++] = r->data;
}

int main()
{
    scanf("%d", &N);
    node* root = NULL;
    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        origin_order[i] = t;
        bst_insert(root, t);
    }
    preorder(root);
    if (check_pre())
    {
        printf("YES\n");
        postorder(root);
        for (int i = 0; i < N; i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", post_order[i]);
        }
        return 0;
    }

    premirorder(root);
    if (check_pre_mir())
    {
        printf("YES\n");
        postmirorder(root);
        for (int i = 0; i < N; i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", post_mirror_order[i]);
        }
        return 0;
    }

    printf("NO");

    return 0;
}
