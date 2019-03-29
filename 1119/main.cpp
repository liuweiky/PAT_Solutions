#include <cstdio>

#define MAX_N 32

using namespace std;

int preorder[MAX_N];
int postorder[MAX_N];

bool unknown = false;
bool flag = false;
int N;

struct node
{
    int data;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

node* root = NULL;

node* rebuild(int prl, int prr, int pol, int por)
{
    if (prl > prr || pol > por)
        return NULL;
    node* n = new node;
    n->data = preorder[prl];

    if (prl == prr)
        return n;

    int k;

    for (int i = pol; i <= por; i++)
    {
        if (preorder[prl + 1] == postorder[i])
        {
            k = i;
            break;
        }
    }

    if (prl + 1 + k - pol == prr)
        unknown = true;
    n->lc = rebuild(prl + 1, prl + 1 + k - pol, pol, k);
    /*if (unknown)
        return n;*/
    n->rc = rebuild(prl + 1 + k - pol + 1, prr, k + 1, por - 1);
    return n;
}

void in_order(node* r)
{
    if (r == NULL)
        return;
    in_order(r->lc);
    if (flag)
        printf(" ");
    flag = true;
    printf("%d", r->data);
    in_order(r->rc);
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &preorder[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &postorder[i]);
    root = rebuild(1, N, 1, N);

    if (unknown)
        printf("No\n");
    else
        printf("Yes\n");

    in_order(root);

    printf("\n");
    return 0;
}
