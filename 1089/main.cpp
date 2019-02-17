#include <cstdio>
#include <algorithm>
#include <climits>

#define MAX_N 128
#define INSERTION_SORT 0
#define MERGE_SORT 1

using namespace std;

int N;
int ins_seq[MAX_N];
int merge_seq[MAX_N];
int ps_seq[MAX_N];

int type = -1;

void insertion_it(int step)
{
    if (step > N)
        return;
    int t = ins_seq[step];
    int p = step - 1;
    while (p >= 0 && t < ins_seq[p])
    {
        ins_seq[p + 1] = ins_seq[p];
        p--;
    }
    ins_seq[p + 1] = t;
}

void merge_it(int step)
{
    if (step > N)
        return;
    for (int i = 0; i < N; i += step)
    {
        sort(merge_seq + i, merge_seq + i + step);
    }
}

void get_type()
{
    bool mer = true, ins = true;
    for (int i = 0; (mer || ins) && i < N; i++)
    {
        if (ins && ins_seq[i] != ps_seq[i])
            ins = false;
        if (mer && merge_seq[i] != ps_seq[i])
            mer = false;
    }
    if (mer)
        type = MERGE_SORT;
    if (ins)
        type = INSERTION_SORT;
}

int main()
{
    fill_n(ins_seq, MAX_N, INT_MAX);
    fill_n(merge_seq, MAX_N, INT_MAX);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &ins_seq[i]);
        merge_seq[i] = ins_seq[i];
    }

    for (int i = 0; i < N; i++)
        scanf("%d", &ps_seq[i]);

    int ins_step = 1;
    int mer_step = 2;

    while (true)
    {
        insertion_it(ins_step);
        merge_it(mer_step);
        get_type();
        if (type == INSERTION_SORT)
        {
            insertion_it(ins_step + 1);
            printf("Insertion Sort\n");
            for (int i = 0; i < N; i++)
            {
                printf("%d", ins_seq[i]);
                if (i != N - 1)
                    printf(" ");
            }
            return 0;
        }
        if (type == MERGE_SORT)
        {
            merge_it(mer_step * 2);
            printf("Merge Sort\n");
            for (int i = 0; i < N; i++)
            {
                printf("%d", merge_seq[i]);
                if (i != N - 1)
                    printf(" ");
            }
            return 0;
        }
        ins_step++;
        mer_step *= 2;
    }

    return 0;
}
