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
        list.insertLast(new Student("Attila", 29, "0001", 100f, 100f, 100f));
        list.insertLast(new Student("Andaru", 20, "0003", 85f, 87f, 92f));
        list.insertLast(new Student("Irfan", 19, "0004", 60f, 80f, 100f));
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
