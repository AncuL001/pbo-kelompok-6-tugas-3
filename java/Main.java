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
            System.out.println("5. Ubah data nilai");
            if(course.empty()) System.out.println("6. Tambah data dummy");
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
                    course.deleteFirst();
                    break;
                case 6:
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
