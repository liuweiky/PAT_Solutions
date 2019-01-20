#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    int last_floor = 0;
    int time = 0;

    for (int i = 0; i < N; i++)
    {
        int next_floor;
        scanf("%d", &next_floor);
        if (next_floor > last_floor)
            time += (next_floor - last_floor) * 6;
        else
            time += (last_floor - next_floor) * 4;
        time += 5;
        last_floor = next_floor;
    }

    printf("%d", time);

    return 0;
}
