#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define VIP 1
#define NONVIP 0

using namespace std;

const int OPEN_TIME = 8 * 60 * 60;
const int CLOSE_TIME = 21 * 60 * 60;

struct PPair
{
    int h, m, s, arriving_time_tag, playing_time, isvip, has_served;
    PPair(){}
    PPair(int hour, int minute, int sec, int p, int v): h(hour), m(minute), s(sec), isvip(v), has_served(0)
    {
        arriving_time_tag = hour * 60 * 60 + minute * 60 + sec;
        playing_time = p > 120 ? 120 : p;
    }
};

struct Table
{
    PPair* p;
    int last_finish_time, isvip, serve_count;
    Table() {last_finish_time = OPEN_TIME; p = NULL; isvip = NONVIP; serve_count = 0;}
};

int N, K, M;
Table tables[128];
vector<PPair*> players;
vector<PPair*> vip_players;
vector<int> vip_table_num;

bool cmp(PPair* p1, PPair* p2)
{
    return p1->arriving_time_tag < p2->arriving_time_tag;
}


char* get_str_time(int time_tag)
{
    char* c = new char[9];
    c[2] = c[5] = ':';
    c[8] = '\0';
    int h = time_tag / 3600;
    int m = (time_tag / 60) % 60;
    int s = time_tag % 60;
    c[0] = h / 10 + '0';
    c[1] = h % 10 + '0';
    c[3] = m / 10 + '0';
    c[4] = m % 10 + '0';
    c[6] = s / 10 + '0';
    c[7] = s % 10 + '0';
    return c;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int h, m, s, p_time, isvip;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &p_time, &isvip);
        PPair* p = new PPair(h, m, s, p_time, isvip);
        players.push_back(p);
        if (isvip)
            vip_players.push_back(p);
    }
    scanf("%d %d", &K, &M);
    for (int i = 0; i < M; i++)
    {
        int v;
        scanf("%d", &v);
        tables[v].isvip = VIP;
        vip_table_num.push_back(v);
    }

    sort(players.begin(), players.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        //printf("vip_players: %d\t", vip_players.size());
        if (players[i]->has_served)
            continue;
        int earliest_finish_table = 1;
        int earliest_finish_time = tables[1].p == NULL ? tables[1].last_finish_time : tables[1].p->playing_time * 60 + tables[1].last_finish_time;
        for (int j = 1; j <= K; j++)
        {
            if (earliest_finish_time < players[i]->arriving_time_tag)
                break;
            int t = tables[j].p == NULL ? tables[j].last_finish_time : tables[j].p->playing_time * 60 + tables[j].last_finish_time;
            if (t < earliest_finish_time || (vip_players.size() > 0 && vip_players[0]->arriving_time_tag <= earliest_finish_time && !tables[earliest_finish_table].isvip && t == earliest_finish_time && tables[j].isvip))
            {
                earliest_finish_time = t;
                earliest_finish_table = j;
            }
        }

        // printf("%d: %s ", earliest_finish_table, get_str_time(earliest_finish_time));

        if (earliest_finish_time >= CLOSE_TIME)
            break;

        tables[earliest_finish_table].last_finish_time = earliest_finish_time;
        tables[earliest_finish_table].p = NULL;

        if (tables[earliest_finish_table].isvip && vip_players.size() > 0 && vip_players[0]->arriving_time_tag <= earliest_finish_time)
        {
            tables[earliest_finish_table].p = vip_players[0];
            vip_players[0]->has_served = 1;
            printf("%s %s %d\n",
                   get_str_time(tables[earliest_finish_table].p->arriving_time_tag),
                   get_str_time(earliest_finish_time),
                   (int)round((earliest_finish_time - tables[earliest_finish_table].p->arriving_time_tag) / 60.0));
            vip_players.erase(vip_players.begin());
            i--;
            tables[earliest_finish_table].serve_count++;
            // printf("%s %d\n", get_str_time(tables[earliest_finish_table].p->arriving_time_tag), tables[earliest_finish_table].p->playing_time);
            continue;
        }



        if (players[i]->arriving_time_tag <= earliest_finish_time)
        {
            tables[earliest_finish_table].p = players[i];
            tables[earliest_finish_table].serve_count++;
            players[i]->has_served = 1;
            printf("%s %s %d\n",
                   get_str_time(tables[earliest_finish_table].p->arriving_time_tag),
                   get_str_time(earliest_finish_time),
                   (int)round((earliest_finish_time - tables[earliest_finish_table].p->arriving_time_tag) / 60.0));
            // printf("%s %d\n", get_str_time(tables[earliest_finish_table].p->arriving_time_tag), tables[earliest_finish_table].p->playing_time);
        } else {
            earliest_finish_time = players[i]->arriving_time_tag;
            tables[earliest_finish_table].last_finish_time = players[i]->arriving_time_tag;
            tables[earliest_finish_table].p = players[i];
            tables[earliest_finish_table].serve_count++;
            players[i]->has_served = 1;
            printf("%s %s %d\n",
                   get_str_time(tables[earliest_finish_table].p->arriving_time_tag),
                   get_str_time(earliest_finish_time),
                   (int)round((earliest_finish_time - tables[earliest_finish_table].p->arriving_time_tag) / 60.0));
            // printf("%s %d\n", get_str_time(tables[earliest_finish_table].p->arriving_time_tag), tables[earliest_finish_table].p->playing_time);
        }

        if (vip_players.size() > 0 && vip_players[0]->has_served)
            vip_players.erase(vip_players.begin());
    }

    for (int i = 1; i <= K; i++)
    {
        printf("%d", tables[i].serve_count);
        if (i != K)
            printf(" ");
    }

    return 0;
}
