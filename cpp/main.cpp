#include "studentList.cpp"

void addDummyData(StudentList& list){
  list.insertLast(new Student("Fauzan", 19, "0001", 80, 82, 90));
  list.insertLast(new Student("Attila", 29, "0002", 100, 100, 100));
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

int main() {
  StudentList list;

  while (true) {
    std::cout << "1. Lihat tabel student\n"
              << "2. Lihat tabel terfilter berdasarkan nilai\n"
              << "3. Tambah mahasiswa\n"
              << "4. Hapus mahasiswa\n"
              << "5. Ubah data nilai\n";
    if (list.empty()) std::cout << "6. Tambah data dummy\n";
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

    case 6:
      addDummyData(list);
      break;

    case 0:
      return 0;

    default:
      break;
    }
  }
}