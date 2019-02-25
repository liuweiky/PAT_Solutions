#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX_ADDR 102400
#define MAX_KEY 10240

using namespace std;

int link_list[MAX_ADDR][2]; // 0 is the key, 1 is the next node addr
int d_link_list[MAX_ADDR][2];
bool key_map[MAX_KEY];

int HEAD, N, D_HEAD = -1, D_TAIL = -1;

int main()
{
    fill_n(key_map, MAX_KEY, false);
    scanf("%d %d", &HEAD, &N);

    for (int i = 0; i < N; i++)
    {
        int addr, key, next;
        scanf("%d %d %d", &addr, &key, &next);
        link_list[addr][0] = key;
        link_list[addr][1] = next;
    }

    int p = HEAD, p_prev = -1;

    while (p != -1)
    {
        int k = abs(link_list[p][0]);
        int next = link_list[p][1];
        if (key_map[k])
        {
            link_list[p_prev][1] = next;
            if (D_HEAD == -1)
                D_HEAD = p;
            else if (D_TAIL != -1)
                d_link_list[D_TAIL][1] = p;
            d_link_list[p][0] = link_list[p][0];
            d_link_list[p][1] = -1;
            D_TAIL = p;
        }
        else
        {
            key_map[k] = true;
            p_prev = p;
        }
        p = next;
    }

    p = HEAD;
    while (p != -1)
    {
        if (link_list[p][1] != -1)
            printf("%05d %d %05d\n", p, link_list[p][0], link_list[p][1]);
        else
            printf("%05d %d %d\n", p, link_list[p][0], link_list[p][1]);
        p = link_list[p][1];
    }

    p = D_HEAD;
    while (p != -1)
    {
        if (d_link_list[p][1] != -1)
            printf("%05d %d %05d\n", p, d_link_list[p][0], d_link_list[p][1]);
        else
            printf("%05d %d %d\n", p, d_link_list[p][0], d_link_list[p][1]);
        p = d_link_list[p][1];
    }

    return 0;
}
