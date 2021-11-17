/*
  Nama File : studentList.cpp
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 17 November 2021
  Deskripsi : Implementasi kasus linked list nilai sidang menggunakan C++, class StudentList
*********************************************/

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

    bool isNpmUnique(Student* data) {
      Student* current = head;
      while (current != nullptr) {
        if (current->getNpm() == data->getNpm()) {
          return false;
        }
        current = current->next;
      }
      return true;
    }

    int size() {
      if (empty()) return 0;

      int i = 0;
      for (Student* temp = head; temp != nullptr; temp = temp->next) i++;
      return i;
    }

    bool insertFirst(Student* newStudent) {
      if(!this->isNpmUnique(newStudent)){
        return false;
      }

      if (empty()){
        head = newStudent;
      }
      else { 
        newStudent->next = head;
        head = newStudent;
      }
      return true;
    }

    bool insertLast(Student* newStudent) {
      if(!this->isNpmUnique(newStudent)){
        return false;
      }

      if (empty()){
        head = newStudent;
      }
      else {
        Student* temp = head;
        while (temp->hasNext()) temp = temp->next;
        temp->next = newStudent;
      }
      return true;
    }

    // mengembalikan false jika gagal (array indeks out of bound)
    bool insertOn(int index, Student* newStudent) {
      int size = this->size();
      if (index < 0 || index >= size) return false;

      if(!this->isNpmUnique(newStudent)){
        return false;
      }

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

      newStudent->next = temp->next;
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
      for (int i = 0; i < index - 1; i++) temp = temp->next;

      Student* delStudent = temp->next;
      temp->next = delStudent->next;
      delStudent->next = nullptr;
      return delStudent;
    }

    template <typename F>
    void forEach(F func) const {
      for (auto temp = head; temp; temp = temp->next){
        func(temp);
      }
    }

    Student* deleteByNpm(std::string npm) {
      Student* current = head;
      Student* previous = nullptr;

      while (current != nullptr){
        if (current->getNpm() == npm) {
          if (previous == nullptr) head = head->next;
          else previous->next = current->next;

          return current;
        }
        previous = current;
        current = current->next;
      }

      return nullptr;
    }

    void printTable() {
      printf("%-15s %-5s %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
             "Nama", "Umur", "NPM", "Penguji1", "Penguji2", "Pembimbing", "NilaiAkhir", "NilaiMutu", "Status");
      for (auto s = head; s; s = s->next){
        printf("%-15s %-5d %-5s %-10.2f %-10.2f %-10.2f %-10.2f %-10c %-10s\n", 
                s->getName().c_str(), s->getAge(), s->getNpm().c_str(), s->getNilaiPenguji1(), s->getNilaiPenguji2(), s->getNilaiPembimbing(), s->getNilaiAkhir(), s->getHurufMutu(), s->getStatus().c_str());
      };
    }

    void printFilteredTable(char sel, float nilai) {
      printf("%-15s %-5s %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
              "Nama", "Umur", "NPM", "Penguji1", "Penguji2", "Pembimbing", "NilaiAkhir", "NilaiMutu", "Status");
      
      if (sel == 1){
        for (auto s = head; s; s = s->next){
          if (s->getNilaiAkhir() > nilai)
            printf("%-15s %-5d %-5s %-10.2f %-10.2f %-10.2f %-10.2f %-10c %-10s\n", 
                    s->getName().c_str(), s->getAge(), s->getNpm().c_str(), s->getNilaiPenguji1(), s->getNilaiPenguji2(), s->getNilaiPembimbing(), s->getNilaiAkhir(), s->getHurufMutu(), s->getStatus().c_str());
        };
      }

      else {
        for (auto s = head; s; s = s->next){
          if (s->getNilaiAkhir() < nilai)
            printf("%-15s %-5d %-5s %-10.2f %-10.2f %-10.2f %-10.2f %-10c %-10s\n", 
                    s->getName().c_str(), s->getAge(), s->getNpm().c_str(), s->getNilaiPenguji1(), s->getNilaiPenguji2(), s->getNilaiPembimbing(), s->getNilaiAkhir(), s->getHurufMutu(), s->getStatus().c_str());
        };
      }
    }
};
