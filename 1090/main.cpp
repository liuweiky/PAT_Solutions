#include <cstdio>
#include <vector>
#include <cmath>

#define MAX_N 102400

using namespace std;

int N;
double P, r;
int root;

vector<int> tree[MAX_N];

double max_price = -1;
int max_cnt = 0;

void dfs(int root, int level)
{
    if (tree[root].size() == 0)
    {
        double price = P * pow((1 + r / 100), level);
        if (price > max_price)
        {
            max_price = price;
            max_cnt = 1;
        }
        else if (price == max_price)
            max_cnt++;
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
        int t;
        scanf("%d", &t);
        if (t == -1)
            root = i;
        else
            tree[t].push_back(i);
    }

    dfs(root, 0);

    printf("%.2f %d", max_price, max_cnt);

    return 0;
}
