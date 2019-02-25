#include <cstdio>
#include <algorithm>

#define MAX_ADDR 102400

using namespace std;

struct node
{
    char data;
    int next;
};

node link[MAX_ADDR];
bool addr_tag[MAX_ADDR];

int S1_HEAD, S2_HEAD, N;

int main()
{
    fill_n(addr_tag, MAX_ADDR, false);
    scanf("%d %d %d", &S1_HEAD, &S2_HEAD, &N);

    for (int i = 0; i < N; i++)
    {
        int addr, next;
        char c;
        scanf("%d %c %d", &addr, &c, &next);
        link[addr].data = c;
        link[addr].next = next;
    }

    int p = S1_HEAD;

    while (p != -1)
    {
        addr_tag[p] = true;
        p = link[p].next;
    }

    p = S2_HEAD;

    while (p != -1)
    {
        if (addr_tag[p])
        {
            printf("%05d", p);
            return 0;
        }
        p = link[p].next;
    }

    printf("-1");

    return 0;
}
