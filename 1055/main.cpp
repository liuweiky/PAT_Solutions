#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K;

struct person
{
    char name[16];
    int age, net_worth;
};

bool cmp(person* p1, person* p2)
{
    if (p1->net_worth != p2->net_worth)
        return p1->net_worth > p2->net_worth;
    if (p1->age != p2->age)
        return p1->age < p2->age;
    return strcmp(p1->name, p2->name) < 0;
}

vector<person*> ps;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        person* p = new person;
        scanf("%s %d %d", p->name, &p->age, &p->net_worth);
        ps.push_back(p);
    }

    sort(ps.begin(), ps.end(), cmp);

    for (int i = 0; i < K; i++)
    {
        printf("Case #%d:\n", i + 1);
        int M, amin, amax;
        scanf("%d %d %d", &M, &amin, &amax);
        int cnt = 0;
        for (int j = 0; j < ps.size() && cnt != M; j++)
        {
            if (ps[j]->age >= amin && ps[j]->age <= amax)
            {
                printf("%s %d %d\n", ps[j]->name, ps[j]->age, ps[j]->net_worth);
                cnt++;
            }
        }
        if (cnt == 0)
            printf("None\n");
    }

    return 0;
}
