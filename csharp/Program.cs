/*
  Nama File : Program.cs
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 17 November 2021
  Deskripsi : Implementasi kasus linked list nilai sidang menggunakan C#, Main Program 
*********************************************/
using System;

namespace csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            StudentList course = new StudentList();
            while (true) {
                Console.WriteLine("1. Lihat tabel mahasiswa");
                Console.WriteLine("2. Lihat tabel terfilter berdasarkan nilai");
                Console.WriteLine("3. Tambah mahasiswa");
                Console.WriteLine("4. Hapus mahasiswa");
                if(course.empty()) Console.WriteLine("5. Tambah data dummy");
                Console.WriteLine("0. Keluar");
                Console.Write("Pilihan: ");
                int pilihan = int.Parse(Console.ReadLine());

                switch (pilihan) {
                    case 1:
                        course.printTable();
                        break;
                    case 2:
                        filterMenu(course);
                        break;
                    case 3:
                        addMahasiswaMenu(course);
                        break;
                    case 4:
                        removeMahasiswaMenu(course);
                        break;
                    case 5:
                        addDummyData(course);
                        Console.WriteLine("Data dummy berhasil ditambahkan");
                        break;
                    default:
                        Console.WriteLine("Dadah");
                        return;
                }   
            }
        }

        public static void addDummyData(StudentList list) {
            list.insertLast(new Student("Fauzan", 19, "0001", 80, 82, 90));
            list.insertFirst(new Student("Attila", 29, "0006", 100, 100, 100));
            list.insertLast(new Student("Andaru", 20, "0003", 85, 87, 92));
            list.insertLast(new Student("Irfan", 19, "0004", 60, 80, 100));
            list.insertOn(1, new Student("Intan", 19, "0002", 80, 75, 90));
        }

        public static void addMahasiswaMenu(StudentList list) {
            Console.Write("Nama Mahasiswa : ");
            String nama = Console.ReadLine();
            Console.Write("Umur Mahasiswa : ");
            int umur = int.Parse(Console.ReadLine());
            Console.Write("NPM Mahasiswa : ");
            String nim = Console.ReadLine();
            Console.Write("Nilai Penguji 1 : ");
            float tugas = float.Parse(Console.ReadLine());
            Console.Write("Nilai Penguji 2 : ");
            float uts = float.Parse(Console.ReadLine());
            Console.Write("Nilai Pembimbing : ");
            float uas = float.Parse(Console.ReadLine());
            Student s = new Student(nama, umur, nim, tugas, uts, uas);
            if(!list.insertLast(s)) Console.WriteLine("NPM tersebut sudah ada di daftar!");
        }

        public static void removeMahasiswaMenu(StudentList list){
            Console.Write("NPM mahasiswa yang ingin dihapus : ");
            String nim = Console.ReadLine();
            if(list.deleteByNpm(nim) == null) Console.WriteLine("NPM tersebut tidak ada di daftar! Tidak ada yang dilakukan.");
        }

        public static void filterMenu(StudentList list){
            Console.WriteLine("1. Lebih besar dari");
            Console.WriteLine("2. Lebih kecil dari");
            Console.WriteLine("Pilihan : ");
            int selection = int.Parse(Console.ReadLine());
            Console.WriteLine("Nilai : ");
            float nilai = float.Parse(Console.ReadLine());
            list.printFilteredTable(selection, nilai);
        }
    }
}
