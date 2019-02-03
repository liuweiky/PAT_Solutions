#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 102400
#define MAX_M 256
#define MAX_K 16

using namespace std;

int N, M, K;

struct appl
{
    int ge, gi, id;
    int cho[MAX_K];
};

bool cmp(appl* a1, appl* a2)
{
    if (a1->ge + a1->gi != a2->ge + a2->gi)
        return a1->ge + a1->gi > a2->ge + a2->gi;
    return a1->ge > a2->ge;
}

vector<appl*> apps;
int school_quota[MAX_M];
vector<int> adm_list[MAX_M];
bool can_adm[MAX_M];

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++)
        scanf("%d", &school_quota[i]);
    for (int i = 0; i < N; i++)
    {
        appl* a = new appl;
        scanf("%d %d", &a->ge, &a->gi);
        a->id = i;
        for (int j = 0; j < K; j++)
            scanf("%d", &a->cho[j]);
        apps.push_back(a);
    }
    sort(apps.begin(), apps.end(), cmp);
    for (int i = 0; i < N;)
    {
        int j = i + 1;
        while (j < N && apps[i]->ge == apps[j]->ge && apps[i]->gi == apps[j]->gi)
            j++;
        fill_n(can_adm, MAX_M, false);
        for (int k = i; k < j; k++)
        {
            appl* a = apps[k];
            if (j != i + 1)
            {
                for (int c = 0; c < K; c++)
                {
                    if (adm_list[a->cho[c]].size() < school_quota[a->cho[c]] || can_adm[a->cho[c]])
                    {
                        adm_list[a->cho[c]].push_back(a->id);
                        can_adm[a->cho[c]] = true;
                        break;
                    }
                }

            } else
            {
                for (int c = 0; c < K; c++)
                {
                    if (adm_list[a->cho[c]].size() < school_quota[a->cho[c]])
                    {
                        adm_list[a->cho[c]].push_back(a->id);
                        break;
                    }
                }
            }
        }
        i = j;
    }
    for (int i = 0; i < M; i++)
    {
        sort(adm_list[i].begin(), adm_list[i].end());
        for (int j = 0; j < adm_list[i].size(); j++)
        {
            printf("%d",adm_list[i][j]);
            if (j != adm_list[i].size() - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
