#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX_ADDR 102400

using namespace std;

struct node
{
    int addr, key, next;
};

int N, HEAD;

node link[MAX_ADDR];
vector<pair<int, int> > ps;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    scanf("%d %d", &N, &HEAD);

    for (int i = 0; i < N; i++)
    {
        node n;
        scanf("%d %d %d", &n.addr, &n.key, &n.next);
        link[n.addr] = n;
    }

    if (HEAD == -1)
    {
        printf("0 -1");
        return 0;
    }

    int p = HEAD;

    while (p != -1)
    {
        node n = link[p];
        pair<int, int> pa;
        pa.first = n.addr;
        pa.second = n.key;
        ps.push_back(pa);
        p = n.next;
    }

    sort(ps.begin(), ps.end(), cmp);

    printf("%d %05d\n", ps.size(), ps[0].first);

    for (int i = 0; i < ps.size(); i++)
    {
        if (i != ps.size() - 1)
            printf("%05d %d %05d\n", ps[i].first, ps[i].second, ps[i + 1].first);
        else
            printf("%05d %d -1\n", ps[i].first, ps[i].second);
    }

    return 0;
}
