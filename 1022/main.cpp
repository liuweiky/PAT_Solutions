#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Book
{
    int ID;
    string title;
    string author;
    vector<string> keywords;
    string publisher;
    string year;
    Book() {}
    Book (int id, string t, string a, string k, string p, string y):
        ID(id), title(t), author(a), publisher(p), year(y)
    {
        int str_begin = 0;
        for (int i = 0; i < k.length(); i++)
        {
            if (k[i] == ' ')
            {
                keywords.push_back(k.substr(str_begin, i - str_begin));
                //cout << k.substr(str_begin, i - str_begin) << endl;
                str_begin = i + 1;
            } else if (i == k.length() - 1)
            {
                keywords.push_back(k.substr(str_begin, i + 1 - str_begin));
                //cout << k.substr(str_begin, i + 1 - str_begin) << endl;
                //str_begin = i + 1;
            }
        }
    }
};

vector<Book*> books;
vector<string> queries;
int N;
int M;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int id;
        string title, author, keywords, publisher, year;
        cin >> id;
        // getline 之前注意使用 cin.ignore() 清空缓冲区内的\n
        cin.ignore();
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        getline(cin, year);
        Book* b = new Book(id, title, author, keywords, publisher, year);
        books.push_back(b);
    }

    cin >> M;
    cin.ignore();

    for (int i = 0; i < M; i++)
    {
        // 不要过多地 ignore，一般在 cin 之后加一个即可
        string query;
        getline(cin, query);
        queries.push_back(query);
    }

    for (int i = 0; i < M; i++)
    {
        vector<int> results;
        string q = queries[i];

        int type;

        // str2int 包含在 sstream 头文件下
        stringstream ss;
        ss << q.substr(0, 1);
        ss >> type;

        for (int j = 0; j < N; j++)
        {
            Book* b = books[j];
            int pos = q.find(":");
            string s = q.substr(pos + 2, q.length() - (pos + 2));

            switch(type)
            {
            case 1:
                if (b->title == s)
                    results.push_back(b->ID);
                break;
            case 2:
                if (b->author == s)
                    results.push_back(b->ID);
                break;
            case 3:
                for (int k = 0; k < b->keywords.size(); k++)
                {
                    if ((b->keywords)[k] == s)
                    {
                        results.push_back(b->ID);
                        break;
                    }
                }
                break;
            case 4:
                if (b->publisher == s)
                    results.push_back(b->ID);
                break;
            case 5:
                if (b->year == s)
                    results.push_back(b->ID);
                break;
            }
        }
        cout << q <<endl;
        if (results.size() == 0)
        {
            cout << "Not Found" << endl;
            continue;
        }
        sort(results.begin(), results.end());
        for (vector<int>::iterator it = results.begin(); it != results.end(); it++)
            cout << (*it) << endl;
    }
    return 0;
}
