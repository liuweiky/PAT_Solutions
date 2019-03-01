#include <cstdio>
#include <climits>
#include <vector>
#include <cmath>

#define MAX_N 102400

using namespace std;

vector<int> tree[MAX_N];
double min_price = INT_MAX;
int min_num = 0;

int N;
double P, r;

void dfs(int id, int lev)
{
    if (tree[id].size() == 0)
    {
        double tmpprice = P * pow((1 + r / 100), lev);
        if (tmpprice < min_price)
        {
            min_price = tmpprice;
            min_num = 1;
        }
        else if (tmpprice == min_price)
            min_num++;
        return;
    }

    for (int i = 0; i < tree[id].size(); i++)
        dfs(tree[id][i], lev + 1);
}

int main()
{
    scanf("%d %lf %lf", &N, &P, &r);

    for (int i = 0; i < N; i++)
    {
        int ki;
        scanf("%d", &ki);
        for (int j = 0; j < ki; j++)
        {
            int t;
            scanf("%d", &t);
            tree[i].push_back(t);
        }
    }

    dfs(0, 0);

    printf("%.4f %d", min_price, min_num);

    return 0;
}
