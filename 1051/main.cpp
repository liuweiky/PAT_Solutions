#include <cstdio>
#include <stack>

#define MAX_N 1024

using namespace std;

int M, N, K;

int main()
{
    scanf("%d %d %d", &M, &N, &K);

    for (int i = 0; i < K; i++)
    {
        stack<int> stk;
        bool flag = true;
        int j = 0, t, pushed = 1;
        while (j++ < N)
        {
            scanf("%d", &t);
            while (stk.size() < M && t >= pushed)
                stk.push(pushed++);
            if (stk.size() == M && t >= pushed)
            {
                flag = false;
                break;
            }
            while (!stk.empty() && stk.top() != t)
                stk.pop();
            if (stk.empty())
            {
                flag = false;
                break;
            }
            else
                stk.pop();
        }
        if (flag)
            printf("YES\n");
        else
        {
            printf("NO\n");
            while (j++ < N)
                scanf("%d", &t);
        }
    }

    return 0;
}
