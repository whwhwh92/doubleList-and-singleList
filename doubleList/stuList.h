#include<string>
#ifndef STULIST_H
#define STULIST_H
class studentList
{
public:
   string ID;
   string name;
   float math;
   studentList* prio;
   studentList* next;
public:
  void studentList();
  studentList add_student__to_studentList();
  studentList find_student_in_studentList();
  void delete_student_in_studentList();
};
#endif