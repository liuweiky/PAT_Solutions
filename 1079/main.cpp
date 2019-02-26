#include <cstdio>
#include <vector>
#include <cmath>

#define MAX_N 102400

using namespace std;

int N;
double P, r;

vector<int> tree[MAX_N];
int product_amount[MAX_N];

double total = 0;

void dfs(int root, int level)
{
    if (tree[root].size() == 0)
    {
        total += P * pow((1 + r / 100), level) * product_amount[root];
        return;
    }
    for (int i = 0; i < tree[root].size(); i++)
        dfs(tree[root][i], level + 1);
}


int main()
{
    scanf("%d %lf %lf", &N, &P, &r);

    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        if (k == 0)
            scanf("%d", &product_amount[i]);
        else
        {
            for (int j = 0; j < k; j++)
            {
                int t;
                scanf("%d", &t);
                tree[i].push_back(t);
            }
        }
    }

    dfs(0, 0);
    printf("%.1f", total);
    return 0;
}
