// Preprocessor Directive
#include "Student.h"

// Library for input/output
#include <iostream>

// Default constructor
// In main: Student testObject
Student::Student() {
  studentName = "Unknown";
  date.day = 1;
  date.month = 1;
  date.year = 2026;
}

// Parameterized constructor
// In main: Student myStudent("Joe", 16, 3, 2026)
Student::Student(std::string name, int day, int month, int year) {
  studentName = name;
  date.day = day;
  date.month = month;
  date.year = year;
}

// Display method
void Student::displayProfile() {

  std::cout 
    << "Student: " 
    << studentName
    << std::endl;

  std::cout 
    << "Enrolled: "
    << date.month
    << "/"
    << date.day
    << "/"
    << date.year
    << std::endl;

}

// Method definition
void Student::ping() {
  std::cout << "Object instantiated" << std::endl;
}

