/*
  Nama File : student.cpp
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 17 November 2021
  Deskripsi : Implementasi kasus linked list nilai sidang menggunakan C++, class Person dan Student
*********************************************/

#pragma once
#include <string>
#include <iostream>

class Person {
  protected:
    std::string name;
    int age;

  public:
    Person(std::string name, int age) {
      this->name = name;
      this->age = age;
    }

    std::string getName() {
      return name;
    }

    int getAge() {
      return age;
    }

    void setName(std::string name) {
      this->name = name;
    }

    void setAge(int age) {
      this->age = age;
    }
};

class Student : public Person {
  private:
    float nilaiPenguji1;
    float nilaiPenguji2;
    float nilaiPembimbing;
    std::string npm;

  public:
    Student* next;

    bool hasNext(){
      return next != nullptr;
    }

    Student(std::string name, 
            int age, 
            std::string npm, 
            float nilaiPenguji1 = 0, 
            float nilaiPenguji2 = 0, 
            float nilaiPembimbing = 0) : Person(name, age){
      this->npm = npm;
      this->nilaiPenguji1 = nilaiPenguji1;
      this->nilaiPenguji2 = nilaiPenguji2;
      this->nilaiPembimbing = nilaiPembimbing;

      this->next = nullptr;
    }

    void setNpm(std::string npm){
      this->npm = npm;
    }

    void setNilaiPenguji1(float nilaiPenguji1){
      this->nilaiPenguji1 = nilaiPenguji1;
    }

    void setNilaiPenguji2(float nilaiPenguji2){
      this->nilaiPenguji2 = nilaiPenguji2;
    }

    void setNilaiPembimbing(float nilaiPembimbing){
      this->nilaiPembimbing = nilaiPembimbing;
    }

    std::string getNpm() {
      return this->npm;
    }

    float getNilaiPenguji1(){
      return this->nilaiPenguji1;
    }

    float getNilaiPenguji2(){
      return this->nilaiPenguji2;
    }

    float getNilaiPembimbing(){
      return this->nilaiPembimbing;
    }

    float getNilaiAkhir(){
      return this->nilaiPenguji1*0.3f + this->nilaiPenguji2*0.3f + this->nilaiPembimbing*0.4f;
    }

    char getHurufMutu(){
      float nilaiAkhir = this->getNilaiAkhir();

      if(nilaiAkhir > 0 && nilaiAkhir <= 60){
        return 'T';
      } else if(nilaiAkhir > 60 && nilaiAkhir <= 70){
        return 'C';
      } else if(nilaiAkhir > 70 && nilaiAkhir <= 80){
        return 'B';
      } else if(nilaiAkhir > 80 && nilaiAkhir <= 100){
        return 'A';
      }

      return 'T';
    }

    std::string getStatus(){
      char hurufMutu = this->getHurufMutu();

      if(hurufMutu == 'T'){
        return "Tidak Lulus !!";
      }

      return "Lulus !!";
    }

    std::string str(){
      return "Nama : " + this->getName() + "\n" +
             "Umur : " + std::to_string(this->getAge()) + "\n" +
             "NPM : " + this->getNpm() + "\n" +
             "Nilai Penguji 1 : " + std::to_string(this->getNilaiPenguji1()) + "\n" +
             "Nilai Penguji 2 : " + std::to_string(this->getNilaiPenguji2()) + "\n" +
             "Nilai Pembimbing : " + std::to_string(this->getNilaiPembimbing()) + "\n" +
             "Nilai Akhir : " + std::to_string(this->getNilaiAkhir()) + "\n" +
             "Status : " + this->getStatus() + "\n" +
             "Huruf Mutu : " + this->getHurufMutu();
    }
};