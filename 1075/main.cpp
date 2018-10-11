#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 10240
#define MAX_K 8

using namespace std;

int N, K, M;

int full_scores[MAX_K];

struct user
{
    int id;
    int scores[MAX_K];
    int rnk;

    int get_pnum()
    {
        int num = 0;
        for (int i = 1; i <= K; i++)
        {
            if (scores[i] == full_scores[i])
                num++;
        }

        return num;
    }

    int get_ttsocre()
    {
        int s = 0;
        for (int i = 1; i <= K; i++)
        {
            s += scores[i] == -1 || scores[i] == -2 ? 0 : scores[i];
        }

        return s;
    }

    bool compile_err()
    {
        for (int i = 1; i <= K; i++)
            if (scores[i] != -1 && scores[i] != -2)
                return false;
        return true;
    }
};

user users[MAX_N];

bool cmp(user u1, user u2)
{
    if (u1.get_ttsocre() != u2.get_ttsocre())
        return u1.get_ttsocre() > u2.get_ttsocre();
    if (u1.get_pnum() != u2.get_pnum())
        return u1.get_pnum() > u2.get_pnum();
    return u1.id < u2.id;
}

int main()
{
    scanf("%d %d %d", &N, &K, &M);

    for (int i = 1; i <= N; i++)
    {
        users[i].id = i;
        for (int j = 1; j <= K; j++)
            users[i].scores[j] = -2;
    }


    for (int i = 1; i <= K; i++)
        scanf("%d", &full_scores[i]);

    for (int i = 0; i < M; i++)
    {
        int id, q, s;
        scanf("%d %d %d", &id, &q, &s);
        users[id].scores[q] = max(s, users[id].scores[q]);
    }

    sort(users + 1, users + N + 1, cmp);

    users[1].rnk = 1;

    for (int i = 2; i <= N; i++)
    {
        if (users[i].get_ttsocre() == users[i - 1].get_ttsocre())
            users[i].rnk = users[i - 1].rnk;
        else
            users[i].rnk = i;
    }

    for (int i = 1; i <= N; i++)
    {

        if (users[i].compile_err())
            break;

        printf("%d %05d %d", users[i].rnk, users[i].id, users[i].get_ttsocre());
        for (int j = 1; j <= K; j++)
        {
            if (users[i].scores[j] == -2)
                printf(" -");
            else if (users[i].scores[j] == -1)
                printf(" 0");
            else
                printf(" %d", users[i].scores[j]);
        }

        printf("\n");
    }

    return 0;
}
