#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int orig_num_count[10] = {0};
int cur_num_count[10] = {0};

int number[32] = {0};
int d_number[32] = {0};
char char_number[32];

int num_len;

void DoubleNum()
{
    int carry = 0;
    for (int i = 0; i < num_len; i++)
    {
        int t = number[i] * 2  + carry;
        d_number[i] = t % 10;
        carry = t / 10;
    }
    d_number[num_len] = carry;
}

int main()
{
    string s;
    cin >> s;
    strcpy(char_number, s.c_str());
    // include cstdio 并使用 gets 报编译错误
    // gets(char_number);
    // 字符串倒序
    // 也可以使用 algorithm 下的 reverse()
    // include string.h 并使用 strrev(char_number); 编译错误
    // strrev(char_number);

    num_len = strlen(char_number);

    reverse(char_number, char_number + num_len);

    for (int i = 0; i < num_len; i++)
    {
        int k = char_number[i] - '0';
        number[i] = k;
        orig_num_count[k] += 1;
    }

    DoubleNum();

    for (int i = 0; i < num_len; i++)
        cur_num_count[d_number[i]] += 1;

    if (d_number[num_len])
    {
        cur_num_count[d_number[num_len]] += 1;
    }

    int flag = 1;

    for (int i = 0; i <= 9; i++)
        if (cur_num_count[i] != orig_num_count[i])
        {
            flag = 0;
            break;
        }

    if (flag)
    {
        cout << "Yes\n";
        for (int i = num_len - 1; i >= 0; i--)
            cout << d_number[i];
    }
    else
    {
        cout << "No\n";

        int i = d_number[num_len] ? num_len : num_len - 1;

        for (; i >= 0; i--)
            cout << d_number[i];
    }


    return 0;
}
