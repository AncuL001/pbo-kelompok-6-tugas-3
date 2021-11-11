#include "studentList.cpp"

int main() {
  StudentList list;
  list.insertLast(new Student("A", 1, "1", 100, 100, 100));
  list.insertLast(new Student("B", 2, "2", 100, 100, 100));
  list.insertLast(new Student("C", 3, "3", 100, 100, 100));
  list.insertLast(new Student("D", 4, "4", 100, 100, 100));

  list.insertOn(1, new Student("DD", 333, "3", 100, 100, 100));

  Student* temp = list.deleteOn(1);
  std::cout << temp->str();
  delete temp;
}