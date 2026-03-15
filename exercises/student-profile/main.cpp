// Link header file
#include "Student.h"

// Library for input/output
#include <iostream>

int main() {
  checkLink();
  
  // Testing EnrollmentDate struct
  EnrollmentDate today;
  today.day = 15;
  today.month = 3;
  today.year = 2026;

  std::cout << "Struct test: "
    << today.month
    << "/"
    << today.day
    << "/"
    << today.year
    << std::endl;

  
  return 0;
}
