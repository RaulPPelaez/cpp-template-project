#pragma once

#include <string>
#include <vector>

namespace homework {
namespace student {
/**
 * @brief Generates random student information
 * @return A tuple containing a random name, age, and grade
 */
std::tuple<std::string, int, double> generateStudentInfo();

/**
 * @class Student
 * @brief Represents a student with associated information and courses
 */
class Student {
public:
  /**
   * @class Course
   * @brief Represents a course that a student can enroll in
   */
  class Course {
  public:
    std::string courseName; ///< The name of the course
    int year;               ///< The year the course is offered

    /**
     * @brief Construct a new Course object
     * @param name The name of the course
     * @param y The year the course is offered
     */
    Course(const std::string &name, int y);
  };

private:
  std::string name;
  int age;
  double grade;
  mutable bool ageAccessed = false;
  static int totalStudents;
  std::vector<Course> courses;

public:
  /**
   * @brief Construct a new Student object
   * @param n The student's name
   * @param a The student's age
   * @param g The student's grade
   */
  Student(const std::string &n, int a, double g);

  /**
   * @brief Get the student's name
   * @return The student's name
   */
  std::string getName() const;

  int getAge() const; ///< Get the student's age

  /**
   * @brief Get the student's grade
   * @return The student's grade
   */
  double getGrade() const;

  /**
   * @brief Set the student's name
   * @param newName The new name to set
   */
  void setName(const std::string &newName);

  /**
   * @brief Set the student's age
   * @param newAge The new age to set
   */
  void setAge(int newAge);

  /**
   * @brief Set the student's grade
   * @param newGrade The new grade to set
   */
  void setGrade(double newGrade);

  /**
   * @brief Print the student's information
   */
  void printInfo() const;

  /**
   * @brief Get the total number of students created
   * @return The total number of students
   */
  static int getTotalStudents();

  /**
   * @brief Compare grades between two students
   * @param a The first student
   * @param b The second student
   * @return true if a's grade is higher than b's, false otherwise
   */
  friend bool compareGrade(const Student &a, const Student &b);

  /**
   * @brief Enroll the student in a course
   * @param course The course to enroll in
   */
  void enroll(const Course &course);

  /**
   * @brief Print the courses the student is enrolled in
   */
  void printCourses() const;
};
} // namespace student
} // namespace homework
