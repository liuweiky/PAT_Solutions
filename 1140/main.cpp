#include <iostream>

using namespace std;

int N;
string s1, s2;

int main()
{
    cin >> s1 >> N;
    N--;
    while (N--)
    {
        int sz = s1.size();
        int ptr = 0, prev_ptr = 0;
        s2 = "";
        while (ptr < sz)
        {
            if (ptr >= 1)
            {
                if (s1[ptr] == s1[ptr - 1])
                    ptr++;
                else
                {
                    s2 += s1[prev_ptr];
                    s2 += (ptr - prev_ptr) + '0';
                    prev_ptr = ptr;
                    ptr++;
                }
            }
            else
                ptr++;
        }
        s2 += s1[prev_ptr];
        s2 += (sz - prev_ptr) + '0';
        s1 = s2;
    }

    cout << s1;

    return 0;
}
