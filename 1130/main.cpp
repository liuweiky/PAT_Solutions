#include <iostream>
#include <algorithm>

#define MAX_N 32

using namespace std;

struct node
{
    string data;
    int lc, rc;
    node() {lc = rc = -1;}
};

int N;
node tree[MAX_N];
bool is_root[MAX_N];

void inorder(int r)
{
    int lc = tree[r].lc;
    int rc = tree[r].rc;

    bool lflag = false, rflag = false;
    if (lc != -1)
    {
        if (tree[lc].data.size() == 1 && !isalnum(tree[lc].data[0]))
            lflag = true;
        if (lflag)
            cout << '(';
        inorder(lc);
    }
    if (lflag)
        cout << ')';

    cout << tree[r].data;

    if (rc != -1)
    {
        if (tree[rc].data.size() == 1 && !isalnum(tree[rc].data[0]))
            rflag = true;
        if (rflag)
            cout << '(';
        inorder(rc);
    }
    if (rflag)
        cout << ')';
}

int main()
{
    fill_n(is_root, MAX_N, true);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> tree[i].data >> tree[i].lc >> tree[i].rc;
        if (tree[i].lc != -1)
            is_root[tree[i].lc] = false;
        if (tree[i].rc != -1)
            is_root[tree[i].rc] = false;
    }

    for (int i = 1; i <= N; i++)
    {
        if (is_root[i])
        {
            inorder(i);
            break;
        }
    }


    return 0;
}
