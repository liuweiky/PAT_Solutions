#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int height, data;
    node* lc;
    node* rc;
    node() {lc = rc = NULL; height = 1;}
};

int N;
node* root = NULL;

int get_height(node* r)
{
    if (r == NULL)
        return 0;
    return r->height;
}

void update_height(node* r)
{
    r->height = max(get_height(r->lc), get_height(r->rc)) + 1;
}

int get_balance_factor(node* r)
{
    return get_height(r->lc) - get_height(r->rc);
}

void L(node* & r)
{
    node* temp = r->rc;
    r->rc = temp->lc;
    temp->lc = r;
    update_height(r);
    update_height(temp);
    r = temp;
}

void R(node* & r)
{
    node* temp = r->lc;
    r->lc = temp->rc;
    temp->rc = r;
    update_height(r);
    update_height(temp);
    r = temp;
}

void insert_avl(node* & r, int d)
{
    if (r == NULL)
    {
        r = new node;
        r->data = d;
        return;
    }

    if (d < r->data)
    {
        insert_avl(r->lc, d);
        update_height(r);
        if (get_balance_factor(r) == 2)
        {
            if (get_balance_factor(r->lc) == 1)
                R(r);
            else if (get_balance_factor(r->lc) == -1)
            {
                L(r->lc);
                R(r);
            }
        }
    }
    else
    {
        insert_avl(r->rc, d);
        update_height(r);
        if (get_balance_factor(r) == -2)
        {
            if (get_balance_factor(r->rc) == -1)
                L(r);
            else if (get_balance_factor(r->rc) == 1)
            {
                R(r->rc);
                L(r);
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        insert_avl(root, t);
    }

    printf("%d", root->data);

    return 0;
}
