#ifndef STUDENT_H_
#define STUDENT_H_
#include <vector>
#include "pc.h"

class Student: public PC {
  public:
    Student( std::vector<int> pos );
    ~Student();
};

#endif

