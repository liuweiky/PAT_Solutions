#include <cstdio>
#include <climits>
#include <vector>
#include <set>

#define MAX_N 10240

using namespace std;

struct node
{
    node() {lc = rc = NULL;}
    int key;
    node* lc;
    node* rc;
};

int M, N;
node* root = NULL;
set<int> st;
bool fin = false;
int order[MAX_N];

void insert_bst(node* & r, int key)
{
    if (r == NULL)
    {
        r = new node;
        r->key = key;
        return;
    }

    if (key < r->key)
        insert_bst(r->lc, key);
    else
        insert_bst(r->rc, key);
}

void dfs(node* r, int s, int t)
{
    if (r == NULL || fin)
        return;
    if (r->key == s)
    {
        printf("%d is an ancestor of %d.\n", s, t);
        fin = true;
        return;
    }
    else if (r->key == t)
    {
        printf("%d is an ancestor of %d.\n", t, s);
        fin = true;
        return;
    }
    else if ((s < r->key && t > r->key) || (s > r->key && t < r->key))
    {
        printf("LCA of %d and %d is %d.\n", s, t, r->key);
        fin = true;
        return;
    }
    dfs(r->lc, s, t);
    dfs(r->rc, s, t);
}

int main()
{
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        //insert_bst(root, k);
        st.insert(k);
        order[i] = k;
    }

    while (M--)
    {
        fin = false;
        int s, t;
        scanf("%d %d", &s, &t);

        if (st.find(s) == st.end())
        {
            if (st.find(t) == st.end())
                printf("ERROR: %d and %d are not found.\n", s, t);
            else
                printf("ERROR: %d is not found.\n", s);
            continue;
        }
        else if (st.find(t) == st.end())
        {
            printf("ERROR: %d is not found.\n", t);
            continue;
        }

        //dfs(root, s, t);
        for (int i = 0; i < N; i++)
        {
            if (order[i] == s)
            {
                printf("%d is an ancestor of %d.\n", s, t);
                break;
            }
            else if (order[i] == t)
            {
                printf("%d is an ancestor of %d.\n", t, s);
                break;
            }
            else if ((s < order[i] && t > order[i]) || (s > order[i] && t < order[i]))
            {
                printf("LCA of %d and %d is %d.\n", s, t, order[i]);
                break;
            }
        }
    }

    return 0;
}
