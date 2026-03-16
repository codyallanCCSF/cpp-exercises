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

  // Private access specifier
  std::string studentName;
  EnrollmentDate date;

  // Public access specifier
  public:

  // Constructor with no parameters
  Student();

  // Construtor with parameters
  Student(std::string studentName, int day, int month, int year);
  
  // Method to format and output student data
  void displayProfile();

};

// Close header guard
#endif
