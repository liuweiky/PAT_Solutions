#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define ONLINE 1
#define OFFLINE 0

using namespace std;

int cost[24];

int N;
int MON;

struct base_rec
{
    int d, h, m;
    int type;
    char name[128];
};

struct valid_rec
{
    base_rec* from;
    base_rec* to;
};

bool cmp(base_rec* b1, base_rec* b2)
{
    if (strcmp(b1->name, b2->name) != 0)
        return strcmp(b1->name, b2->name) < 0;
    if (b1->d != b2->d)
        return b1->d < b2->d;
    if (b1->h != b2->h)
        return b1->h < b2->h;
    if (b1->m != b2->m)
        return b1->m < b2->m;
}

vector<base_rec*> recs;
vector<valid_rec*> vrecs;

void rec_print()
{
    for (int i = 0; i < recs.size(); i++)
        printf("%s %d:%d:%d %d\n", recs[i]->name, recs[i]->d, recs[i]->h, recs[i]->m, recs[i]->type);
}

void vrec_print()
{
    for (int i = 0; i < vrecs.size(); i++)
        printf("%s %d:%d:%d %d \t %s %d:%d:%d %d\n",
               vrecs[i]->from->name, vrecs[i]->from->d, vrecs[i]->from->h, vrecs[i]->from->m, vrecs[i]->from->type,
               vrecs[i]->to->name, vrecs[i]->to->d, vrecs[i]->to->h, vrecs[i]->to->m, vrecs[i]->to->type);
}

int main()
{

    for (int i = 0; i < 24; i++)
        scanf("%d", &cost[i]);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        base_rec* b = new base_rec;
        char s[16];
        scanf("%s %d:%d:%d:%d %s", b->name, &MON, &b->d, &b->h, &b->m, s);
        b->type = strcmp(s, "on-line") == 0 ? ONLINE : OFFLINE;
        recs.push_back(b);
    }

    sort(recs.begin(), recs.end(), cmp);

    //rec_print();

    for (int i = 0; i < recs.size(); i++)
    {
        base_rec* b = recs[i];
        if (i != N - 1 && strcmp(b->name, recs[i + 1]->name) == 0 && b->type == ONLINE && recs[i + 1]->type == OFFLINE)
        {
            valid_rec* v = new valid_rec;
            v->from = b;
            v->to = recs[i + 1];
            vrecs.push_back(v);
            i += 1;
        }
    }

    //vrec_print();

    char tmps[128] = "";
    int tt_amount = 0;

    for (int i = 0; i < vrecs.size(); i++)
    {
        valid_rec* v = vrecs[i];
        if (strcmp(tmps, v->from->name) != 0)
        {
            if (i != 0)
            {
                printf("\n");
                printf("Total amount: $%.2f\n", tt_amount / 100.0);
            }
            printf("%s %02d", v->from->name, MON);
            strcpy(tmps, v->from->name);
            tt_amount = 0;
        }

        int tmp_amount = 0;
        int mins = 0;

        printf("\n%02d:%02d:%02d %02d:%02d:%02d ", v->from->d, v->from->h, v->from->m, v->to->d, v->to->h, v->to->m);

        int d = v->from->d, h = v->from->h, m = v->from->m;
        while(!(d == v->to->d && h == v->to->h && m == v->to->m))
        {
            mins++;
            tmp_amount += cost[h];
            m++;
            if (m == 60)
            {
                h++;
                m = 0;
                if (h == 24)
                {
                    d++;
                    h = 0;
                }
            }
        }

        tt_amount += tmp_amount;

        printf("%d $%.2f", mins, tmp_amount / 100.0);
    }

    printf("\nTotal amount: $%.2f", tt_amount / 100.0);

    return 0;
}
