#include<iostream>

using namespace std;

class Student
{
    char* name;
    int age;

public:
    Student() : name(nullptr), age(0)
    {
        cout << "Constructor by default\n";
    }

    Student(const char* Name, int Age) : age(Age)
    {
        cout << "Constructor with parameters\n";
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }

    void SetName(const char* Name)
    {
        if (name != nullptr)
            delete[] name;
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }

    void SetAge(int Age)
    {
        age = Age;
    }

    void Input()
    {
        char buffer[100];
        cout << "Enter name: ";
        cin.getline(buffer, sizeof(buffer));
        SetName(buffer);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }

    void Output() const
    {
        if (name == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        cout << "Name: " << name << endl
            << "Age: " << age << endl << endl;
    }

    ~Student()
    {
        if (name != nullptr)
        {
            cout << "Destructor\n";
            delete[] name;
        }
    }
};

void AddStudent(Student* array, int& size)
{
    char buffer[100];
    cout << "Enter name: ";
    cin.getline(buffer, sizeof(buffer));
    int age;
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();

    array[size].SetName(buffer);
    array[size].SetAge(age);
    size++;
}

void PrintStudents(const Student* array, int size)
{
    cout << "Array of students:\n";
    for (int i = 0; i < size; i++)
    {
        array[i].Output();
    }
}

int main()
{
    const int maxStudents = 2;
    Student students[maxStudents];
    int numStudents = 0;

    for (int i = 0; i < maxStudents; i++)
    {
        char buffer[100];
        int age;
        cout << "Enter name: ";
        cin.getline(buffer, sizeof(buffer));
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();

        students[i].SetName(buffer);
        students[i].SetAge(age);
        numStudents++;
    }

    PrintStudents(students, numStudents);

    AddStudent(students, numStudents);

    PrintStudents(students, numStudents);

    return 0;
}

