#include <cstdio>
#include <vector>

#define MAX_ADDR 102400

using namespace std;

struct node
{
    int data, addr, next;
    node() {next = addr = data = -1;}
};

node llist[MAX_ADDR];
int head, N, K;

vector<node> neg, lt, other, sorted;

int main()
{
    scanf("%d %d %d", &head, &N, &K);

    for (int i = 0; i < N; i++)
    {
        node n;
        scanf("%d %d %d", &n.addr, &n.data, &n.next);
        llist[n.addr].data = n.data;
        llist[n.addr].next = n.next;
        llist[n.addr].addr = n.addr;
    }

    int p = head;

    while (p != -1)
    {
        if (llist[p].data < 0)
            neg.push_back(llist[p]);
        else if (llist[p].data <= K)
            lt.push_back(llist[p]);
        else
            other.push_back(llist[p]);
        p = llist[p].next;
    }

    sorted.insert(sorted.end(), neg.begin(), neg.end());
    sorted.insert(sorted.end(), lt.begin(), lt.end());
    sorted.insert(sorted.end(), other.begin(), other.end());

    head = sorted[0].addr;

    for (int i = 1; i < sorted.size(); i++)
        llist[sorted[i - 1].addr].next = sorted[i].addr;

    llist[sorted[sorted.size() - 1].addr].next = -1;

    p = head;

    while (p != -1)
    {
        if (llist[p].next == -1)
            printf("%05d %d -1\n", llist[p].addr, llist[p].data);
        else
            printf("%05d %d %05d\n", llist[p].addr, llist[p].data, llist[p].next);
        p = llist[p].next;
    }

    return 0;
}
