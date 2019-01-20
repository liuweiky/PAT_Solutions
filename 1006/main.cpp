#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

int M;

char unlock_id[32];
char lock_id[32];
int unlock_time = INT_MAX;
int lock_time INT_MIN;

int get_time_tag(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

int main()
{
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        char id[32];
        int h, m, s;
        int t;
        scanf("%s", id);
        scanf("%d:%d:%d", &h, &m, &s);
        t = get_time_tag(h, m, s);
        if (t < unlock_time)
        {
            unlock_time = t;
            strcpy(unlock_id, id);
        }
        scanf("%d:%d:%d", &h, &m, &s);
        t = get_time_tag(h, m, s);
        if (t > lock_time)
        {
            lock_time = t;
            strcpy(lock_id, id);
        }
    }

    printf("%s %s", unlock_id, lock_id);

    return 0;
}
