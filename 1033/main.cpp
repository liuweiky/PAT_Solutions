#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int Cmax, D, Davg, N;

struct Station
{
    double price;
    double dis;
};

vector<Station*> sts;

bool cmp(Station* s1, Station* s2)
{
    return s1->dis < s2->dis;
}

int main()
{
    scanf("%d %d %d %d", &Cmax, &D, &Davg, &N);

    for (int i = 0; i < N; i++)
    {
        Station* s = new Station;
        scanf("%lf %lf", &s->price, &s->dis);
        sts.push_back(s);
    }

    sort(sts.begin(), sts.end(), cmp);

    /*for (int i = 0; i < N; i++)
        printf("%f %f\n", sts[i]->dis, sts[i]->price);*/

    if (sts[0]->dis != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    double curd = 0, curg = 0;
    double price = 0;

    for (int i = 0; i < N;)
    {
        //printf("%d\t%f\t%f\n", i, curd, curg);

        double canreach = curd + Cmax * Davg;
        int j = i + 1;
        double min_price = 99999999999999.0;
        int min_idx = -1;
        int cheaper = -1;
        for (; j < N && sts[j]->dis <= canreach; j++)
        {
            if (sts[j]->price < sts[i]->price)
            {
                cheaper = j;
                break;
            }
            if (sts[j]->price < min_price)
            {
                min_price = sts[j]->price;
                min_idx = j;
            }
        }
        //printf("%d %d\n", cheaper, min_idx);
        if (canreach >= D && cheaper == -1)
        {
            double dd = D - curd;
            double g = dd / Davg;
            price += g > curg ? (g - curg) * sts[i]->price : 0;
            printf("%.2f", price);
            return 0;
        } else if (cheaper != -1)
        {
            double dd = sts[cheaper]->dis - curd;
            double g = dd / Davg;
            price += g > curg ? (g - curg) * sts[i]->price : 0;

            curg = g > curg ? 0 : curg - g;

            curd = sts[cheaper]->dis;
            i = cheaper;
        } else if (min_idx != -1)
        {
            double dd = sts[min_idx]->dis - curd;
            double g = dd / Davg;
            price += (Cmax - curg) * sts[i]->price;

            curg = Cmax - g;

            curd = sts[min_idx]->dis;
            i = min_idx;
        } else
        {
            printf("The maximum travel distance = %.2f", curd + Cmax * Davg);
            return 0;
        }

    }

    return 0;
}
