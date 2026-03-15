// Open header guard
#ifndef STUDENT_H
#define STUDENT_H

// String dependency
#include <string>

// Struct to group data variables
struct EnrollmentDate {
  int day;
  int month;
  int year;
};

// "Student" class declaration
// Defines custom data type
class Student {

  // Public access specifier
  public:

  // Constructor with no parameters
  Student();

  // Test member function
  void ping();
};

// Close header guard
#endif
