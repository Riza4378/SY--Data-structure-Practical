#include <iostream>
using namespace std;

struct Student
{
    char name[20];
    int roll;
    char college[30];
    char course[20];
    int marks;
    int age;
};

void input(Student s[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;

        cout << "Name: ";
        cin >> s[i].name;

        cout << "Roll No: ";
        cin >> s[i].roll;

        cout << "College Name: ";
        cin >> s[i].college;

        cout << "Course: ";
        cin >> s[i].course;

        cout << "Marks: ";
        cin >> s[i].marks;

        cout << "Age: ";
        cin >> s[i].age;
    }
}


void display(Student *s, int n)
{
    cout << "\nStudent Details\n";

    for(int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << (s + i)->name << endl;
        cout << "Roll No: " << (s + i)->roll << endl;
        cout << "College: " << (s + i)->college << endl;
        cout << "Course: " << (s + i)->course << endl;
        cout << "Marks: " << (s + i)->marks << endl;
        cout << "Age: " << (s + i)->age << endl;
    }
}


int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student s[n];

    input(s, n);
    display(s, n);

    return 0;
}


