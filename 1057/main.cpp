#include <cstdio>
#include <vector>

using namespace std;

vector<int> stk;
vector<int> ordered;

int N;

void insert_stack(int t)
{
    stk.push_back(t);
    int low = 0, high = ordered.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (ordered[mid] > t)
            high = mid - 1;
        else if (ordered[mid] < t)
            low = mid + 1;
        else
        {
            ordered.insert(ordered.begin() + mid, t);
            return;
        }
    }
    ordered.insert(ordered.begin() + low, t);
}

void delete_stack()
{
    int t = stk[stk.size() - 1];
    stk.pop_back();
    int low = 0, high = ordered.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (ordered[mid] > t)
            high = mid - 1;
        else if (ordered[mid] < t)
            low = mid + 1;
        else
        {
            ordered.erase(ordered.begin() + mid);
            return;
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char buf[16];
        scanf("%s", buf);

        if (buf[1] == 'u')
        {
            int t;
            scanf("%d", &t);
            insert_stack(t);
        }
        else if (buf[1] == 'o')
        {
            if (stk.size() == 0)
            {
                printf("Invalid\n");
                continue;
            }
            printf("%d\n", stk[stk.size() - 1]);
            delete_stack();
        }
        else
        {
            if (stk.size() == 0)
            {
                printf("Invalid\n");
                continue;
            }
            if (stk.size() % 2 == 0)
                printf("%d\n", ordered[stk.size() / 2 - 1]);
            else
                printf("%d\n", ordered[(stk.size() + 1) / 2 - 1]);
        }
    }

    return 0;
}
