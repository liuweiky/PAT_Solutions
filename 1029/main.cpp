#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int N1, N2;

    scanf("%d", &N1);

    for (int i = 0; i < N1; i++)
    {
        int t;
        scanf("%d", &t);
        q.push(t);
    }

    scanf("%d", &N2);

    int poped_cnt = 0;
    int med_pos = (N1 + N2 + 1) / 2;

    for (int i = 0; i < N2; i++)
    {
        int t;
        scanf("%d", &t);
        if (q.empty())
        {
            q.push(t);
            continue;
        }

        while (!q.empty() && q.top() < t)
        {
            poped_cnt++;
            if (med_pos == poped_cnt)
            {
                printf("%d", q.top());
                return 0;
            }
            q.pop();
        }
        q.push(t);
    }

    int median;

    while (poped_cnt < med_pos)
    {
        median = q.top();
        q.pop();
        poped_cnt++;
    }

    printf("%d", median);

    return 0;
}
