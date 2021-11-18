public class StudentStack {
    protected Student top;


    StudentStack() {
        this.top = null;
    }

    public boolean empty() {
        return top == null;
    }

    public void push(Student data) {
        data.next = top;
        top = data;
    }

    public void pop(){
        if(!empty()){
            top = top.next;
        }
    }

    public Student peek() {
        return top;
    }

    public void traversal() {
        System.out.printf("%-15s %-5s %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
        "Nama", "Umur", "NPM", "Penguji1", "Penguji2", "Pembimbing", "NilaiAkhir", "NilaiMutu", "Status");
        for(Student temp = top; temp != null; temp = temp.next) {
            System.out.printf("%-15s %-5d %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", temp.getName(), temp.getAge(), temp.getNpm(), temp.getNilaiPenguji1(), temp.getNilaiPenguji2(), temp.getNilaiPembimbing(), temp.getNilaiAkhir(), temp.getHurufMutu(), temp.getStatus());
        }
    }
    public void printFilteredTable(int sel, float nilai){
        System.out.printf("%-15s %-5s %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
        "Nama", "Umur", "NPM", "Penguji1", "Penguji2", "Pembimbing", "NilaiAkhir", "NilaiMutu", "Status");
        if(sel == 1){
            for(Student temp = top; temp != null; temp = temp.next){
                if(temp.getNilaiAkhir() > nilai){
                    System.out.printf("%-15s %-5d %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", temp.getName(), temp.getAge(), temp.getNpm(), temp.getNilaiPenguji1(), temp.getNilaiPenguji2(), temp.getNilaiPembimbing(), temp.getNilaiAkhir(), temp.getHurufMutu(), temp.getStatus());
                }
            }
        }else{
            for(Student temp = top; temp != null; temp = temp.next){
                if(temp.getNilaiAkhir() < nilai){
                    System.out.printf("%-15s %-5d %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", temp.getName(), temp.getAge(), temp.getNpm(), temp.getNilaiPenguji1(), temp.getNilaiPenguji2(), temp.getNilaiPembimbing(), temp.getNilaiAkhir(), temp.getHurufMutu(), temp.getStatus());
                }
            }
        }
    }

}
