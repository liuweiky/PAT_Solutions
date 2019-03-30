#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N;

struct node
{
    int data, height;
    node* lc;
    node* rc;
    node() {lc = rc = NULL; height = 1;}
};

node* root = NULL;

int get_height(node* n)
{
    return n == NULL ? 0 : n->height;
}

void update_height(node* n)
{
    n->height = max(get_height(n->lc), get_height(n->rc)) + 1;
}

int get_balance_factor(node* n)
{
    return get_height(n->lc) - get_height(n->rc);
}

void L(node* &n)
{
    node* temp = n->rc;
    n->rc = temp->lc;
    temp->lc = n;
    update_height(n);
    update_height(temp);
    n = temp;
}

void R(node* &n)
{
    node* temp = n->lc;
    n->lc = temp->rc;
    temp->rc = n;
    update_height(n);
    update_height(temp);
    n = temp;
}

void insert_avl(node* & n, int data)
{
    if (n == NULL)
    {
        n = new node;
        n->data = data;
        return;
    }
    if (data < n->data)
    {
        insert_avl(n->lc, data);
        update_height(n);
        if (get_balance_factor(n) == 2)
        {
            if (get_balance_factor(n->lc) == 1)
                R(n);
            else if (get_balance_factor(n->lc) == -1)
            {
                L(n->lc);
                R(n);
            }
        }
    }
    else
    {
        insert_avl(n->rc, data);
        update_height(n);
        if (get_balance_factor(n) == -2)
        {
            if (get_balance_factor(n->rc) == -1)
                L(n);
            else if (get_balance_factor(n->rc) == 1)
            {
                R(n->rc);
                L(n);
            }
        }
    }
}

bool bfs()
{
    queue<node*> q;
    q.push(root);
    bool no_child = false;
    bool is_cbt = true;
    bool flag = false;

    while (!q.empty())
    {
        node* n = q.front();
        q.pop();

        if (flag)
            printf(" ");
        flag = true;
        printf("%d", n->data);
        if (n->lc != NULL)
        {
            if (no_child)
                is_cbt = false;
            q.push(n->lc);
        }
        else
            no_child = true;
        if (n->rc != NULL)
        {
            if (no_child)
                is_cbt = false;
            q.push(n->rc);
        }
        else
            no_child = true;
    }
    return is_cbt;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int d;
        scanf("%d", &d);
        insert_avl(root, d);
    }

    if (bfs())
        printf("\nYES");
    else
        printf("\nNO");

    return 0;
}
