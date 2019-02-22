#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

map<string, int> mps;
string text;

int main()
{
    getline(cin, text);

    int len = text.size();

    for (int i = 0; i < len; i++)
        text[i] = tolower(text[i]);

    int p = 0;

    while (p < len)
    {

        while (p < len && !isalpha(text[p]) && !isdigit(text[p]))
            p++;
        int start = p, local_len = 0;
        while (p < len && (isalpha(text[p]) || isdigit(text[p])))
        {
            p++; local_len++;
        }
        if (local_len != 0)
        {
            string s = text.substr(start, local_len);
            if (mps.find(s) == mps.end())
                mps[s] = 1;
            else mps[s]++;
        }
    }

    int max_cnt = -1;
    string max_string = "";

    for (map<string, int>::iterator it = mps.begin(); it != mps.end(); it++)
    {
        if (it->second > max_cnt)
        {
            max_cnt = it->second;
            max_string = it->first;
        }
        else if (it->second == max_cnt && it->first < max_string)
            max_string = it->first;
    }

    cout << max_string << " " << max_cnt;

    return 0;
}
