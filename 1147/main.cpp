#include <cstdio>

#define MAX_N 1024

using namespace std;

struct node
{
    int key;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

int heap[MAX_N];
int M, N;

node* root;
bool maxx = true, minn = true, flag = true;

void rebuild(node* & r, int idx)
{
    if (idx > N)
    {
        r = NULL;
        return;
    }

    r = new node;
    r->key = heap[idx];
    rebuild(r->lc, idx * 2);
    rebuild(r->rc, idx * 2 + 1);
}

void is_max(node* r)
{
    if (r == NULL || !maxx)
        return;
    if (r->lc != NULL)
    {
        if (r->rc != NULL)
        {
            if (!(r->key >= r->lc->key && r->key >= r->rc->key))
            {
                maxx = false;
                return;
            }
        }
        else if (!(r->key >= r->lc->key))
        {
            maxx = false;
            return;
        }
    }
    else
    {
        if (r->rc != NULL)
        {
            maxx = false;
            return;
        }
    }
    is_max(r->lc);
    is_max(r->rc);
}

void is_min(node* r)
{
    if (r == NULL || !minn)
        return;
    if (r->lc != NULL)
    {
        if (r->rc != NULL)
        {
            if (!(r->key <= r->lc->key && r->key <= r->rc->key))
            {
                minn = false;
                return;
            }
        }
        else if (!(r->key <= r->lc->key))
        {
            minn = false;
            return;
        }
    }
    else
    {
        if (r->rc != NULL)
        {
            minn = false;
            return;
        }
    }
    is_min(r->lc);
    is_min(r->rc);
}

void post_order(node* r)
{
    if (r == NULL)
        return;
    post_order(r->lc);
    post_order(r->rc);
    if (flag)
    {
        printf("%d", r->key);
        flag = false;
    }
    else
        printf(" %d", r->key);
}

int main()
{
    scanf("%d %d", &M, &N);

    while (M--)
    {
        for (int i = 1; i <= N; i++)
            scanf("%d", &heap[i]);
        root = NULL;
        rebuild(root, 1);
        maxx = true;
        minn = true;
        flag = true;
        is_max(root);
        if (maxx)
        {
            printf("Max Heap\n");
            post_order(root);
            printf("\n");
            continue;
        }
        is_min(root);
        if (minn)
        {
            printf("Min Heap\n");
            post_order(root);
            printf("\n");
            continue;
        }
        printf("Not Heap\n");
        post_order(root);
        printf("\n");
    }

    return 0;
}
