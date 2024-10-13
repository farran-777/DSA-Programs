#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(const string& studentName) : name(studentName) {}

    void setGrade(double newGrade) {
        if (newGrade >= 0 && newGrade <= 100) {
            grade = newGrade;
        } else {
            cout << "Grade must be between 0 and 100." << endl;
        }
    }

    double getGrade() const {
        return grade;
    }

    string getName() const {
        return name;
    }

private:
    string name;
    double grade = 0;
};

int main() {
    Student student1("Alice");

    student1.setGrade(85.0);
    cout << student1.getName() << "'s grade: " << student1.getGrade() << endl;

    student1.setGrade(110.0);
    return 0;
}
