#pragma once
#include "student.cpp"

class StudentList {
  protected:
    Student* head;

  public:
    StudentList() {
      head = nullptr;
    }

    bool empty() {
      return head == nullptr;
    }

    int size() {
      if (empty()) return 0;

      int i = 0;
      for (Student* temp = head; temp != nullptr; temp = temp->next) i++;
      return i;
    }

    void insertFirst(Student* newStudent) {
      if (empty()){
        head = newStudent;
      }
      else { 
        newStudent->next = head;
        head = newStudent;
      }
    }

    void insertLast(Student* newStudent) {
      if (empty()){
        head = newStudent;
      }
      else {
        Student* temp = head;
        while (temp->hasNext()) temp = temp->next;
        temp->next = newStudent;
      }
    }

    // mengembalikan false jika gagal (array indeks out of bound)
    bool insertOn(int index, Student* newStudent) {
      int size = this->size();
      if (index < 0 || index >= size) return false;

      if (index == 0) {
        insertFirst(newStudent);
        return true;
      }

      if (index == size - 1) {
        insertLast(newStudent);
        return true;
      }

      Student* temp = head;
      for (int i = 0; i < index - 1; temp = temp->next);

      temp->next->next = newStudent->next;
      temp->next = newStudent;
      return true;
    }

    // mengembalikan nullptr jika list kosong. jangan lupa agar objek yang dikembalikan di-delete
    Student* deleteFirst() {
      if (empty()) return nullptr;

      if (!head->hasNext()) {
        Student* delStudent = head;
        head = nullptr;
        return delStudent;
      }

      Student* delStudent = head;
      head = head->next;
      delStudent->next = nullptr;
      return delStudent;
    }

    // mengembalikan nullptr jika list kosong. jangan lupa agar objek yang dikembalikan di-delete
    Student* deleteLast() {
      if (empty()) return nullptr;

      if (!head->hasNext()) {
        Student* delStudent = head;
        head = nullptr;
        return delStudent;
      }

      Student* temp = head;
      while (temp->next->hasNext()) temp = temp->next;

      Student* delStudent = temp->next;
      temp->next = nullptr;
      return delStudent;
    }

    // mengembalikan nullptr jika array indeks out of bound atau list kosong. jangan lupa agar objek yang dikembalikan di-delete
    Student* deleteOn(int index) {
      int size = this->size();
      if (index < 0 || index >= size) return nullptr;
      if (index == 0) return deleteFirst();
      if (index == size - 1) return deleteLast();

      Student* temp = head;
      for (int i = 0; i < index - 1; temp = temp->next);

      Student* delStudent = temp->next;
      temp->next = delStudent->next;
      delStudent->next = nullptr;
      return delStudent;
    }
};
