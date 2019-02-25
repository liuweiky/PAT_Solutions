#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 16

using namespace std;

struct node
{
    int l, r;
    node() {l = r = -1;}
};

node tree[MAX_N];
int N;
vector<int> ans;
bool root_tag[MAX_N];

void level_order(int r)
{
    queue<int> q;
    q.push(r);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        ans.push_back(n);
        if (tree[n].r != -1)
            q.push(tree[n].r);
        if (tree[n].l != -1)
            q.push(tree[n].l);
    }
}

void in_order(int r)
{
    if (r == -1)
        return;
    in_order(tree[r].r);
    ans.push_back(r);
    in_order(tree[r].l);
}

void print_ans()
{
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
}

int main()
{
    fill_n(root_tag, MAX_N, true);
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        char cl, cr;
        scanf("%c %c", &cl, &cr);
        int l = cl == '-' ? -1 : cl - '0';
        int r = cr == '-' ? -1 : cr - '0';
        if (l != -1)
        {
            tree[i].l = l;
            root_tag[l] = false;
        }
        if (r != -1)
        {
            tree[i].r = r;
            root_tag[r] = false;
        }
        getchar();
    }

    int root;

    for (int i = 0; i < N; i++)
        if (root_tag[i])
        {
            root = i;
            break;
        }

    level_order(root);
    print_ans();
    printf("\n");
    ans.clear();
    in_order(root);
    print_ans();

    return 0;
}
