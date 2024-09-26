#include "student.h"
#include <iostream>
#include <random>

namespace homework{

  std::tuple<std::string, int, double> generateStudentInfo() {
    static std::vector<std::string> names = {"Alice", "Bob", "Charlie", "David", "Eva"};
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> name_dist(0, names.size() - 1);
    std::uniform_int_distribution<> age_dist(18, 25);
    std::uniform_real_distribution<> grade_dist(0.0, 10.0);

    return std::make_tuple(
			   names[name_dist(gen)],
			   age_dist(gen),
			   std::round(grade_dist(gen) * 10.0) / 10.0  // Round to one decimal place
			   );
  }

  int Student::totalStudents = 0;

  Student::Course::Course(const std::string& name, int y) : courseName(name), year(y) {}

  Student::Student(const std::string& n, int a, double g) : name(n) {
    setAge(a);
    setGrade(g);
    totalStudents++;
  }

  std::string Student::getName() const { return name; }

  int Student::getAge() const {
    ageAccessed = true;
    return age;
  }

  double Student::getGrade() const { return grade; }

  void Student::setName(const std::string& newName) {
    if (!newName.empty()) {
      name = newName;
    } else {
      std::cerr << "Error: Name cannot be empty." << std::endl;
    }
  }

  void Student::setAge(int newAge) {
    if (newAge >= 0 && newAge <= 120) {
      age = newAge;
    } else {
      std::cerr << "Error: Age must be between 0 and 120." << std::endl;
    }
  }

  void Student::setGrade(double newGrade) {
    if (newGrade >= 0.0 && newGrade <= 10.0) {
      grade = newGrade;
    } else {
      std::cerr << "Error: Grade must be between 0.0 and 10.0." << std::endl;
    }
  }

  void Student::printInfo() const {
    std::cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << std::endl;
    std::cout << "Age accessed: " << (ageAccessed ? "Yes" : "No") << std::endl;
  }

  int Student::getTotalStudents() { return totalStudents; }

  bool compareGrade(const Student& a, const Student& b) {
    return a.grade > b.grade;
  }

  void Student::enroll(const Course& course) {
    courses.push_back(course);
  }

  void Student::printCourses() const {
    std::cout << "Enrolled courses:" << std::endl;
    for (const auto& course : courses) {
      std::cout << "  " << course.courseName << " (Year: " << course.year << ")" << std::endl;
    }
  }
}
