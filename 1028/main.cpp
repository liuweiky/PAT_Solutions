#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
    string id, name;
    int grade;
    Student(string i, string n, int g): id(i), name(n), grade(g) {}
};

vector<Student*> students;

bool cmp1(Student* s1, Student* s2)
{
    return s1->id < s2->id;
}

bool cmp2(Student* s1, Student* s2)
{
    return s1->name < s2->name;
}

bool cmp3(Student* s1, Student* s2)
{
    return s1->grade < s2->grade;
}

int main()
{
    // 加速 cin 、 cout， 不使用该语句会超时
    ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        string id, name;
        int grade;
        cin >> id >> name >> grade;
        students.push_back(new Student(id, name, grade));
    }

    sort(students.begin(), students.end(), cmp1);

    switch(C)
    {
    case 1:
        // sort(students.begin(), students.end(), cmp1);
        break;
    case 2:
        sort(students.begin(), students.end(), cmp2);
        break;
    case 3:
        sort(students.begin(), students.end(), cmp3);
        break;
    }

    for (vector<Student*>::iterator it = students.begin(); it != students.end(); it++)
        cout << (*it)->id << " " << (*it)->name << " " << (*it)->grade << endl;

    return 0;
}
