#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 102400

using namespace std;

int couple[MAX_N];
bool come_in[MAX_N];
vector<int> ids;
int N, M;

int main()
{
    fill_n(couple, MAX_N, -1);
    fill_n(come_in, MAX_N, false);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        couple[s] = t;
        couple[t] = s;
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int id;
        scanf("%d", &id);
        ids.push_back(id);
        come_in[id] = true;
    }

    vector<int> ans;

    for (int i = 0; i < M; i++)
    {
        int id = ids[i];
        if (couple[id] == -1 || !come_in[couple[id]])
            ans.push_back(id);
    }

    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%05d", ans[i]);
    }

    return 0;
}
