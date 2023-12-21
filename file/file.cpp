#include <iostream>
#include "Student.h"
#include <vector>

using namespace std;

const string path = "students.txt";

void display_student(Student& student) {
    cout << student.name << endl
        << student.age << endl
        << student.group << endl
        << "----------------\n\n";
}

void write_to_file(vector<Student>& students) {
    FILE* file;
    if (fopen_s(&file, path.c_str(), "w+") != NULL) return;

    for (auto& student : students) {
        fputs(student.to_string().c_str(), file);
        fputc('\n', file);
    }

    fclose(file);
}

vector<Student>& read_from_file() {
    vector<Student> students;
    // прочитать из файла в массив

    return students;
}

Student create_student(const string& name, int age, const string& group) {
    return Student{ name, age, group };
}

Student create_student() {
    string name;
    int age;
    string group;

    cout << "Enter name:" << endl;
    getline(cin, name);

    cout << "Enter age:" << endl;
    cin >> age;
    cin.ignore(INT16_MAX, '\n');

    cout << "Enter group" << endl;
    getline(cin, group);

    return create_student(name, age, group);
}

int main() {
    vector<Student> students;

    for (size_t i = 0; i < 3; i++) {
        string name = "student_";
        name.append(to_string(i));

        students.push_back(create_student(name, i * rand() % 60, "bf231"));
    }

    write_to_file(students);
    cout << "Wrote!" << endl;
    students.clear();

    students = read_from_file();

    for (auto& student : students)
        display_student(student);

    return 0;
}