/*
  Nama File : main.cpp
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 17 November 2021
  Deskripsi : Implementasi kasus linked list nilai sidang menggunakan C++, bagian main
*********************************************/

#include "studentList.cpp"

void addDummyData(StudentList& list){
  list.insertLast(new Student("Fauzan", 19, "0001", 80, 82, 90));
  list.insertLast(new Student("Attila", 29, "0001", 100, 100, 100));
  list.insertLast(new Student("Andaru", 20, "0003", 85, 87, 92));
  list.insertLast(new Student("Irfan", 19, "0004", 60, 80, 100));
}

void filterMenu(StudentList list){
  std::cout << "1. Lebih besar dari\n"
            << "2. Lebih kecil dari\n"
            << "Pilihan: ";
  int sel;
  std::cin >> sel;

  std::cout << "Nilai: ";  
  float nilai;
  std::cin >> nilai;

  list.printFilteredTable(sel, nilai);
}

void addMahasiswaMenu(StudentList& list){
  std::string name, npm;
  int age;
  float nilaiPenguji1, nilaiPenguji2, nilaiPembimbing;

  std::cout << "Nama mahasiswa: ";
  std::cin >> name;
  std::cout << "Umur mahasiswa: ";
  std::cin >> age;
  std::cout << "NPM mahasiswa: ";
  std::cin >> npm;
  std::cout << "Nilai penguji 1: ";
  std::cin >> nilaiPenguji1;
  std::cout << "Nilai penguji 2: ";
  std::cin >> nilaiPenguji2;
  std::cout << "Nilai pembimbing: ";
  std::cin >> nilaiPembimbing;

  if (!list.insertLast(new Student(name, age, npm, nilaiPenguji1, nilaiPenguji2, nilaiPembimbing)))
    std::cout << "NPM tersebut sudah ada di daftar!\n";
}

void removeMahasiswaMenu(StudentList& list){
  std::string npm;

  std::cout << "NPM mahasiswa yang ingin dihapus: ";
  std::cin >> npm;

  Student* delStudent = list.deleteByNpm(npm);

  if (delStudent == nullptr) std::cout << "NPM tersebut tidak ada di daftar! Tidak ada yang dilakukan.\n";
  else delete delStudent;
}

int main() {
  StudentList list;

  while (true) {
    std::cout << "1. Lihat tabel student\n"
              << "2. Lihat tabel terfilter berdasarkan nilai\n"
              << "3. Tambah mahasiswa\n"
              << "4. Hapus mahasiswa\n";
    if (list.empty()) std::cout << "5. Tambah data dummy\n";
    std::cout << "0. Keluar\n";

    std::cout << "Pilihan: ";
    int sel;
    std::cin >> sel;

    switch (sel) {
    case 1:
      list.printTable();
      break;

    case 2:
      filterMenu(list);
      break;

    case 3:
      addMahasiswaMenu(list);
      break;

    case 4:
      removeMahasiswaMenu(list);
      break;

    case 5:
      if (list.empty()) addDummyData(list);
      break;

    case 0:
      return 0;

    default:
      break;
    }
  }
}