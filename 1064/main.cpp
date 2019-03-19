#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int CBT[MAX_N];
int ptr = 1;
int inorder[MAX_N];

int N;

void in_order(int r)
{
    if (r > N)
        return;
    in_order(2 * r);
    CBT[r] = inorder[ptr++];
    in_order(2 * r + 1);
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &inorder[i]);

    sort(inorder + 1, inorder + 1 + N);

    in_order(1);

    for (int i = 1; i <= N; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", CBT[i]);
    }

    return 0;
}
