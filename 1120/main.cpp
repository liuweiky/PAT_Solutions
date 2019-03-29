#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

set<int> ans;
int N;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char buf[32];
        scanf("%s", buf);
        int len = strlen(buf);
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += buf[i] - '0';
        ans.insert(sum);
    }

    printf("%d\n", ans.size());

    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        if (it != ans.begin())
            printf(" ");
        printf("%d", *it);
    }

    return 0;
}
