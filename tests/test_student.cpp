#include <gtest/gtest.h>
#include "student.h"
using namespace homework;

TEST(StudentTest, ConstructorAndGetters) {
    Student s("Alice", 20, 8.5);
    EXPECT_EQ(s.getName(), "Alice");
    EXPECT_EQ(s.getAge(), 20);
    EXPECT_DOUBLE_EQ(s.getGrade(), 8.5);
}

TEST(StudentTest, Setters) {
    Student s("Bob", 21, 7.0);
    s.setName("Robert");
    s.setAge(22);
    s.setGrade(8.0);
    EXPECT_EQ(s.getName(), "Robert");
    EXPECT_EQ(s.getAge(), 22);
    EXPECT_DOUBLE_EQ(s.getGrade(), 8.0);
}

TEST(StudentTest, InvalidInput) {
    Student s("Charlie", 19, 9.0);
    testing::internal::CaptureStderr();
    s.setAge(150);
    s.setGrade(11.0);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_TRUE(output.find("Error: Age must be between 0 and 120.") != std::string::npos);
    EXPECT_TRUE(output.find("Error: Grade must be between 0.0 and 10.0.") != std::string::npos);
}

TEST(StudentTest, StaticMembers) {
    int initialCount = Student::getTotalStudents();
    Student s1("David", 22, 7.5);
    Student s2("Eva", 20, 8.0);
    EXPECT_EQ(Student::getTotalStudents(), initialCount + 2);
}

TEST(StudentTest, CompareGrade) {
    Student s1("Frank", 21, 8.5);
    Student s2("Grace", 20, 9.0);
    EXPECT_TRUE(compareGrade(s2, s1));
    EXPECT_FALSE(compareGrade(s1, s2));
}

TEST(StudentTest, CourseEnrollment) {
    Student s("Henry", 19, 7.5);
    Student::Course math("Math", 2023);
    Student::Course physics("Physics", 2023);
    s.enroll(math);
    s.enroll(physics);
    testing::internal::CaptureStdout();
    s.printCourses();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Math") != std::string::npos);
    EXPECT_TRUE(output.find("Physics") != std::string::npos);
}
