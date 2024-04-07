#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}
    
    std::string getName() const {
        return name;
    }
};

class Student : virtual public Person {
private:
    int studentID;

public:
    Student(const std::string& n, int id) : Person(n), studentID(id) {}

    int getStudentID() const {
        return studentID;
    }
};

class Teacher : virtual public Person {
private:
    int teacherID;

public:
    Teacher(const std::string& n, int id) : Person(n), teacherID(id) {}

    int getTeacherID() const {
        return teacherID;
    }
};

class TeachingAssistant : public Student, public Teacher {
private:
    std::string course;

public:
    TeachingAssistant(const std::string& n, int studentID, int teacherID, const std::string& c)
        : Person(n), Student(n, studentID), Teacher(n, teacherID), course(c) {}

    std::string getCourse() const {
        return course;
    }
};

int main() {
    Student student("Alice", 1234);
    Teacher teacher("Bob", 5678);
    TeachingAssistant ta("Charlie", 9876, 5432, "Computer Science");

    std::cout << "Student: " << student.getName() << ", Student ID: " << student.getStudentID() << std::endl;
    std::cout << "Teacher: " << teacher.getName() << ", Teacher ID: " << teacher.getTeacherID() << std::endl;
    std::cout << "Teaching Assistant: " << ta.getName() << ", Student ID: " << ta.getStudentID()
              << ", Teacher ID: " << ta.getTeacherID() << ", Course: " << ta.getCourse() << std::endl;

    return 0;
}
