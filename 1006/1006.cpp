#include <cstdio>
#include <climits>
#include <cstring>

struct record
{
    char id[32];
    int in_time;
    int out_time;
};

int M;

int main()
{
    scanf("%d", &M);

    int min_in_time = INT_MAX, max_out_time = INT_MIN;
    char min_in_id[32], max_in_id[32];

    for (int i = 0; i < M; i++)
    {
        record r;
        int h, m, s;
        scanf("%s", r.id);
        scanf("%d:%d:%d", &h, &m, &s);
        r.in_time = h * 60 * 60 + m * 60 + s;
        scanf("%d:%d:%d", &h, &m, &s);
        r.out_time = h * 60 * 60 + m * 60 + s;

        if (min_in_time > r.in_time)
        {
            min_in_time = r.in_time;
            strcpy(min_in_id, r.id);
        }

        if (max_out_time < r.out_time)
        {
            max_out_time = r.out_time;
            strcpy(max_in_id, r.id);
        }
    }

    printf("%s %s", min_in_id, max_in_id);

    return 0;
}
