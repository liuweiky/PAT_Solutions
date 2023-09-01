#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
    int exp;
    double coeff;
};

bool cmp(item& i1, item& i2)
{
    return i1.exp < i2.exp;
}

int main()
{
    int K1, K2;
    vector<item> poly1;
    vector<item> poly2;

    int max_exp = 0;

    scanf("%d", &K1);

    for (int i = 0; i < K1; i++)
    {
        item it;
        scanf("%d %lf", &it.exp, &it.coeff);
        poly1.push_back(it);
        max_exp = max(max_exp, it.exp);
    }

    scanf("%d", &K2);

    for (int i = 0; i < K2; i++)
    {
        item it;
        scanf("%d %lf", &it.exp, &it.coeff);
        poly2.push_back(it);
        max_exp = max(max_exp, it.exp);
    }

    sort(poly1.begin(), poly1.end(), cmp);
    sort(poly2.begin(), poly2.end(), cmp);

    vector<item> result;

    for (int i = 0, j = 0; i < poly1.size() || j < poly2.size(); )
    {
        if (i >= poly1.size())
        {
            result.push_back(poly2[j]);
            j++;
        }
        else if (j >= poly2.size())
        {
            result.push_back(poly1[i]);
            i++;
        }
        else if (poly1[i].exp == poly2[j].exp)
        {
            item it;
            it.exp = poly1[i].exp;
            it.coeff = poly1[i].coeff + poly2[j].coeff;
            if (it.coeff != 0)
            {
                result.push_back(it);
            }
            i++;
            j++;
        }
        else if (poly1[i].exp < poly2[j].exp)
        {
            result.push_back(poly1[i]);
            i++;
        }
        else
        {
            result.push_back(poly2[j]);
            j++;
        }
    }

    printf("%d", result.size());

    for (int i = result.size() - 1; i >= 0; i--)
    {
        printf(" %d %.1f", result[i].exp, result[i].coeff);
    }

    return 0;
}
