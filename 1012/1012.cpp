#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;

struct student
{
    char id[16];
    double C, M, E, A;
    char best_rank_course;
    int best_rank, tmp_rank;
};

bool cmpc(student& s1, student& s2)
{
    return s1.C > s2.C;
}

bool cmpm(student& s1, student& s2)
{
    return s1.M > s2.M;
}

bool cmpe(student& s1, student& s2)
{
    return s1.E > s2.E;
}

bool cmpa(student& s1, student& s2)
{
    return s1.A > s2.A;
}

int main()
{
    scanf("%d %d", &N, &M);
    vector<student> vecs;

    for (int i = 0; i < N; i++)
    {
        student s;
        scanf("%s %lf %lf %lf", s.id, &s.C, &s.M, &s.E);
        s.A = (s.C + s.M + s.E) / 3;
        vecs.push_back(s);
    }


    sort(vecs.begin(), vecs.end(), cmpa);
    vecs[0].best_rank = 1;
    vecs[0].best_rank_course = 'A';

    for (int i = 1; i < N; i++)
    {
        if (vecs[i].A == vecs[i - 1].A)
        {
            vecs[i].best_rank = vecs[i - 1].best_rank;
            vecs[i].best_rank_course = 'A';
        }
        else
        {
            vecs[i].best_rank = i + 1;
            vecs[i].best_rank_course = 'A';
        }
    }

    sort(vecs.begin(), vecs.end(), cmpc);
    vecs[0].tmp_rank = 1;

    if (vecs[0].tmp_rank < vecs[0].best_rank)
    {
        vecs[0].best_rank = vecs[0].tmp_rank;
        vecs[0].best_rank_course = 'C';
    }

    for (int i = 1; i < N; i++)
    {
        if (vecs[i].C == vecs[i - 1].C)
        {
            vecs[i].tmp_rank = vecs[i - 1].tmp_rank;
        }
        else
        {
            vecs[i].tmp_rank = i + 1;
        }

        if (vecs[i].tmp_rank < vecs[i].best_rank)
        {
            vecs[i].best_rank = vecs[i].tmp_rank;
            vecs[i].best_rank_course = 'C';
        }
    }

    sort(vecs.begin(), vecs.end(), cmpm);
    vecs[0].tmp_rank = 1;

    if (vecs[0].tmp_rank < vecs[0].best_rank)
    {
        vecs[0].best_rank = vecs[0].tmp_rank;
        vecs[0].best_rank_course = 'M';
    }

    for (int i = 1; i < N; i++)
    {
        if (vecs[i].M == vecs[i - 1].M)
        {
            vecs[i].tmp_rank = vecs[i - 1].tmp_rank;
        }
        else
        {
            vecs[i].tmp_rank = i + 1;
        }

        if (vecs[i].tmp_rank < vecs[i].best_rank)
        {
            vecs[i].best_rank = vecs[i].tmp_rank;
            vecs[i].best_rank_course = 'M';
        }
    }

    sort(vecs.begin(), vecs.end(), cmpe);
    vecs[0].tmp_rank = 1;

    if (vecs[0].tmp_rank < vecs[0].best_rank)
    {
        vecs[0].best_rank = vecs[0].tmp_rank;
        vecs[0].best_rank_course = 'E';
    }

    for (int i = 1; i < N; i++)
    {
        if (vecs[i].E == vecs[i - 1].E)
        {
            vecs[i].tmp_rank = vecs[i - 1].tmp_rank;
        }
        else
        {
            vecs[i].tmp_rank = i + 1;
        }

        if (vecs[i].tmp_rank < vecs[i].best_rank)
        {
            vecs[i].best_rank = vecs[i].tmp_rank;
            vecs[i].best_rank_course = 'E';
        }
    }

    char check[16];

    for (int i = 0; i < M; i++)
    {
        scanf("%s", check);
        int j;
        for (j = 0; j < N; j++)
        {
            if (strcmp(check, vecs[j].id) == 0)
            {
                printf("%d %c\n", vecs[j].best_rank, vecs[j].best_rank_course);
                break;
            }
        }
        if (j == N)
        {
            printf("N/A\n");
        }
    }

    return 0;
}
