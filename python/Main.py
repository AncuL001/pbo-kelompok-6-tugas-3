# /*
#   Nama File : Main.py
#   Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
#   NPM       : 140810200020, 140810200030, 140810200032, 140810200048
#   Kelas     : B
#   Tanggal   : 17 November 2021
#   Deskripsi : Implementasi kasus linked list nilai sidang menggunakan C++, class Main
# *********************************************/

from Student import Student
from StudentList import StudentList

def addDummyData(list):
    list.insertLast(Student("Fauzan", 19, "0001", 80, 82, 90))
    list.insertLast(Student("Attila", 29, "0002", 100, 100, 100))
    list.insertLast(Student("Andaru", 20, "0003", 85, 87, 92))
    list.insertLast(Student("Irfan", 19, "0004", 60, 80, 100))
    return list

def filterMenu(list):
    print("1. Lebih besar dari")
    print("2. Lebih kecil dari")
    sel = input("Pilihan: ")
    nilai = input("Nilai: ")
    nilai = int(nilai)

    list.printFilteredTable(sel, nilai)

def addMahasiswaMenu(list):
    name = input("Nama mahasiswa: ")
    age = input("Umur mahasiswa: ")
    npm = input("NPM mahasiswa: ")
    nilaiPenguji1 = input("Nilai penguji 1: ")
    nilaiPenguji2 = input("Nilai penguji 2: ")
    nilaiPembimbing = input("Nilai pembimbing: ")
    age = int(age)
    nilaiPenguji1 = float(nilaiPenguji1)
    nilaiPenguji2 = float(nilaiPenguji2)
    nilaiPembimbing = float(nilaiPembimbing)
    if list.insertLast(Student(name, age, npm, nilaiPenguji1, nilaiPenguji2, nilaiPembimbing)) is False:
        print("NPM sudah terdaftar!\n")
    else:
        list.insertLast(Student(name, age, npm, nilaiPenguji1, nilaiPenguji2, nilaiPembimbing))
    return list

def removeMahasiswaMenu(list):
    npm = input("NPM mahasiswa yang ingin dihapus: ")
    temp = list.deleteByNpm(npm)
    if temp is None :
        print("NPM tidak terdaftar!")
    else:
        del(temp)
    return list

if __name__ == "__main__":
    list = StudentList()
    confirm = True

    while confirm == True:
        print("1. Lhat tabel mahasiswa")
        print("2. Lihat tabel terfilter mahasiswa")
        print("3. Tambah mahasiswa")
        print("4. Hapus mahasiswa")
        if list.empty() == True:
            print("5. Tambah data dummy")
        print("0. Keluar\n")
        sel = input('Pilihan: ')

        if sel == '1':
            list.printTable()
        elif sel == '2':
            filterMenu(list)
        elif sel == '3':
            list = addMahasiswaMenu(list)
        elif sel == '4':
            list = removeMahasiswaMenu(list)
        elif sel == '5':
            if list.empty() == True:
                list = addDummyData(list)
        elif sel == '0':
            confirm = False