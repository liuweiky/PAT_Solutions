#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define MAX_N 64

using namespace std;

struct node
{
    int data;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

int inorder[MAX_N];
int postorder[MAX_N];
int N;
node* root = NULL;
vector<int> level_node[MAX_N];

node* rebuild(int il, int ir, int pl, int pr)
{
    if (pl > pr || il > ir)
        return NULL;

    node* n = new node;
    n->data = postorder[pr];
    int k;

    for (int i = il; i <= ir; i++)
    {
        if (inorder[i] == postorder[pr])
        {
            k = i;
            break;
        }
    }

    n->lc = rebuild(il, k - 1, pl, pl + k - il - 1);
    n->rc = rebuild(k + 1, ir, pl + k - il, pr - 1);
    return n;
}

void bfs()
{
    queue<pair<node*, int> > q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node*, int> p = q.front();
        q.pop();
        level_node[p.second].push_back(p.first->data);
        if (p.first->lc != NULL)
            q.push(make_pair(p.first->lc, p.second + 1));
        if (p.first->rc != NULL)
            q.push(make_pair(p.first->rc, p.second + 1));
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &inorder[i]);

    for (int i = 1; i <= N; i++)
        scanf("%d", &postorder[i]);

    root = rebuild(1, N, 1, N);
    bfs();

    int cnt = 0;

    for (int i = 0; i < MAX_N; i++)
    {
        if (level_node[i].size() == 0)
            break;
        if (i % 2 == 1)
        {
            for (int j = 0; j < level_node[i].size(); j++)
            {
                printf("%d", level_node[i][j]);
                cnt++;
                if (cnt != N)
                    printf(" ");
            }
        }
        else
        {
            for (int j = level_node[i].size() - 1; j >= 0; j--)
            {
                printf("%d", level_node[i][j]);
                cnt++;
                if (cnt != N)
                    printf(" ");
            }
        }
    }

    return 0;
}
