#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_ADDR 102400

using namespace std;

int link[MAX_ADDR][2];
int N, K;
int HEAD;

int main()
{
    scanf("%d %d %d", &HEAD, &N, &K);

    for (int i = 0; i < N; i++)
    {
        int addr, data, next;
        scanf("%d %d %d", &addr, &data, &next);
        link[addr][0] = data;
        link[addr][1] = next;
    }

    int p = HEAD, prev_seg_tail;
    bool first = true;
    vector<int> tmpaddr;

    while (p != -1)
    {
        tmpaddr.push_back(p);
        p = link[p][1];

        if (tmpaddr.size() == K)
        {
            link[tmpaddr[0]][1] = p;
            for (int i = K - 1; i >= 1; i--)
                link[tmpaddr[i]][1] = tmpaddr[i - 1];
            if (first)
            {
                HEAD = tmpaddr[K - 1];
                first = false;
                prev_seg_tail = tmpaddr[0];
            }
            else
            {
                link[prev_seg_tail][1] = tmpaddr[K - 1];
                prev_seg_tail = tmpaddr[0];
            }
            tmpaddr.clear();
        }

    }

    p = HEAD;

    while (p != -1)
    {
        if (link[p][1] != -1)
            printf("%05d %d %05d\n", p, link[p][0], link[p][1]);
        else
            printf("%05d %d %d\n", p, link[p][0], link[p][1]);
        p = link[p][1];
    }

    return 0;
}
