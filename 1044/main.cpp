#include <cstdio>
#include <utility>
#include <vector>
#include <climits>

#define MAX_N 102400

using namespace std;

int N, M;
long long chain_sum[MAX_N];

vector<pair<int, int> > ans;

int main()
{
    scanf("%d %d", &N, &M);

    chain_sum[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        int t;
        scanf("%d", &t);
        chain_sum[i] = t + chain_sum[i - 1];
    }

    int min_cost = INT_MAX;

    for (int i = 1; i <= N; i++)
    {
        int low = i, high = N, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (chain_sum[mid] - chain_sum[i - 1] == M)
            {
                if (min_cost != M)
                    ans.clear();
                min_cost = M;
                ans.push_back(pair<int, int>(i, mid));
                break;
            } else if (chain_sum[mid] - chain_sum[i - 1] > M)
            {
                if (min_cost > chain_sum[mid] - chain_sum[i - 1])
                {
                    min_cost = chain_sum[mid] - chain_sum[i - 1];
                    ans.clear();
                    ans.push_back(pair<int, int>(i, mid));
                } else if (min_cost == chain_sum[mid] - chain_sum[i - 1])
                    ans.push_back(pair<int, int>(i, mid));
                high = mid - 1;
            } else
            {
                low = mid + 1;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
        printf("%d-%d\n", ans[i].first, ans[i].second);

    return 0;
}
