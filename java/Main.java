/*
  Nama File : Main.java
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 17 November 2021
  Deskripsi : Implementasi kasus linked list nilai sidang menggunakan Java, class Person dan Student
*********************************************/
import java.util.Scanner;
public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        StudentList course = new StudentList();
        while (true) {
            System.out.println("1. Lihat tabel mahasiswa");
            System.out.println("2. Lihat tabel terfilter berdasarkan nilai");
            System.out.println("3. Tambah mahasiswa");
            System.out.println("4. Hapus mahasiswa");
            if(course.empty()) System.out.println("5. Tambah data dummy");
            System.out.println("0. Keluar");
            System.out.print("Pilihan: ");
            int pilihan = Integer.parseInt(sc.nextLine());
    
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
                    break;
                default:
                    System.out.println("Dadah");
                    return;
            }   
        }
    }

    public static void addDummyData(StudentList list) {
        list.insertLast(new Student("Fauzan", 19, "0001", 80f, 82f, 90f));
        list.insertLast(new Student("Attila", 29, "0002", 100f, 100f, 100f));
        list.insertLast(new Student("Andaru", 20, "0003", 85f, 87f, 92f));
        list.insertLast(new Student("Irfan", 19, "0004", 60f, 80f, 100f));
    }

    public static void addMahasiswaMenu(StudentList list) {
        System.out.print("Nama Mahasiswa : ");
        String nama = sc.nextLine();
        System.out.print("Umur Mahasiswa : ");
        int umur = Integer.parseInt(sc.nextLine());
        System.out.print("NPM Mahasiswa : ");
        String nim = sc.nextLine();
        System.out.print("Nilai Penguji 1 : ");
        float tugas = Float.parseFloat(sc.nextLine());
        System.out.print("Nilai Penguji 2 : ");
        float uts = Float.parseFloat(sc.nextLine());
        System.out.print("Nilai Pembimbing : ");
        float uas = Float.parseFloat(sc.nextLine());
        Student s = new Student(nama, umur, nim, tugas, uts, uas);
        if(!list.insertLast(s)) System.out.println("NPM tersebut sudah ada di daftar!");
    }

    public static void removeMahasiswaMenu(StudentList list){
        System.out.print("NPM mahasiswa yang ingin dihapus : ");
        String nim = sc.nextLine();
        if(list.deleteByNpm(nim) == null) System.out.println("NPM tersebut tidak ada di daftar! Tidak ada yang dilakukan.");
    }

    public static void filterMenu(StudentList list){
        System.out.println("1. Lebih besar dari");
        System.out.println("2. Lebih kecil dari");
        System.out.print("Pilihan : ");
        int selection = Integer.parseInt(sc.nextLine());
        System.out.print("Nilai : ");
        float nilai = Float.parseFloat(sc.nextLine());
        list.printFilteredTable(selection, nilai);
    }
}
