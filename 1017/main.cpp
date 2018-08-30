#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int BEGIN_TIME = 8 * 60 * 60;
int END_TIME = 17 * 60 * 60 + 1;

struct Customer
{
    int arriving_time;
    int processing_time;
    Customer(){}
    Customer(int a, int p): arriving_time(a), processing_time(p) {}
};

struct Window
{
    Customer* current_customer;
    int last_finish_time;
    Window() {current_customer = NULL; last_finish_time = BEGIN_TIME;}
};

vector<Customer*> customers;
vector<Window> windows;

bool cmp(Customer* c1, Customer* c2);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++)
        windows.push_back(Window());

    for (int i = 0; i < n; i++)
    {
        int h, m, s, p;
        scanf("%d:%d:%d", &h, &m, &s);
        scanf("%d", &p);
        // printf("%d-%d-%d %d\n", h, m, s, p);
        customers.push_back(new Customer(h * 60 * 60 + m * 60 + s, p));
    }
    sort(customers.begin(), customers.end(), cmp);

    int total_time =0, served_count = 0;

    for (int i = 0; i < customers.size(); i++)
    {
        Customer* c = customers[i];
        // printf("%d %d\n", c->arriving_time, c->processing_time);
        if (c->arriving_time >= END_TIME)
            break;
        served_count++;
        if (c->arriving_time <= BEGIN_TIME)
        {
            total_time += (BEGIN_TIME - c->arriving_time);
            c->arriving_time = BEGIN_TIME;
        }
        int first_free_index = 0;
        int first_free_time = windows[0].current_customer == NULL ?
                                BEGIN_TIME :
                                windows[0].last_finish_time + windows[0].current_customer->processing_time * 60;
        for (int j = 1; j < windows.size(); j++)
        {
            int tmp_time = windows[j].current_customer == NULL ?
                            BEGIN_TIME :
                            windows[j].last_finish_time + windows[j].current_customer->processing_time * 60;
            if (tmp_time < first_free_time)
            {
                first_free_index = j;
                first_free_time = tmp_time;
            }
        }

        if (c->arriving_time > first_free_time)
        {
            windows[first_free_index].last_finish_time = c->arriving_time;
        }
        else
        {
            windows[first_free_index].last_finish_time = first_free_time;
            total_time += (first_free_time - c->arriving_time);
        }
        windows[first_free_index].current_customer = c;
    }

    // printf("%d %d\n", total_time, served_count);
    printf("%.1lf", total_time / (served_count * 60.0));

    return 0;
}

bool cmp(Customer* c1, Customer* c2)
{
    return c1->arriving_time < c2->arriving_time;
}
