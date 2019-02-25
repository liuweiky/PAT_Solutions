#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

stack<int> stk;
int N;
vector<int> post;

struct node
{
    int data;
    node* r;
    node* l;
    node() {r = l = NULL;}
};

node* create()
{
    if (N == 0)
        return NULL;
    char buf[8];
    scanf("%s", buf);
    N--;
    if (buf[1] == 'u')
    {
        node* n = new node;
        int d;
        scanf("%d", &d);
        stk.push(d);
        n->l = create();
        n->data = stk.top();
        stk.pop();
        n->r = create();
        return n;
    }
    else
        return NULL;
}

void post_order(node* r)
{
    if (r == NULL)
        return;
    post_order(r->l);
    post_order(r->r);
    post.push_back(r->data);
}

int main()
{
    scanf("%d", &N);
    N *= 2;
    node* root = create();
    post_order(root);
    for (int i = 0; i < post.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", post[i]);
    }
    return 0;
}
