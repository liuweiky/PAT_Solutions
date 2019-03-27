#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1024
#define MAX_HOB 1024

using namespace std;

int father[MAX_N];
vector<int> hob_people[MAX_HOB];
int N;

int find_father(int a)
{
    int f = a;
    while (father[f] > 0)
        f = father[f];

    while (a != f)
    {
        int x = father[a];
        father[a] = f;
        a = x;
    }
    return f;
}

void un(int i, int j)
{
    father[i] += father[j];
    father[j] = i;
}

int main()
{
    fill_n(father, MAX_N, -1);
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int k, h;
        scanf("%d:", &k);

        for (int j = 0; j < k; j++)
        {
            scanf("%d", &h);
            if (hob_people[h].size() > 0)
            {
                int p = hob_people[h][0];
                int fp = find_father(p);
                int fi = find_father(i);
                if (fp != fi)
                    un(fp, fi);
            }
            hob_people[h].push_back(i);
        }
    }

    vector<int> ans;

    for (int i = 1; i <= N; i++)
        if (father[i] < 0)
            ans.push_back(father[i]);

    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", -ans[i]);
    }

    return 0;
}
