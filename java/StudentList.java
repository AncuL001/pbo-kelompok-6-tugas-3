public class StudentList {
    protected Student head;

    StudentList() {
        this.head = null;
    }

    public boolean empty(){
        return head == null;
    }

    public boolean isNpmUnique(Student data) {
        Student current = head;
        while (current != null) {
            if (current.getNpm().equals(data.getNpm())) {
                return false;
            }
            current = current.next;
        }
        return true;
    }
    
    public int size(){
        int count = 0;
        Student current = head;
        while(current != null){
            count++;
            current = current.next;
        }
        return count;
    }

    public boolean insertFirst(Student node){
        if(!this.isNpmUnique(node)){
            System.out.println("NPM sudah ada");
            return false;
        }
        node.next = head;
        head = node;
        return true;
    }

    public boolean insertLast(Student node){
        if(!this.isNpmUnique(node)){
            System.out.println("NPM sudah ada");
            return false;
        }
        Student current = head;
        if(current == null){
            head = node;
            return true;
        }
        else{
            while(current.next != null){
                current = current.next;
            }
            current.next = node;
            return true;
        }
    }

    public boolean insertOn(Student node, int position){
        if(!this.isNpmUnique(node)){
            System.out.println("NPM sudah ada");
            return false;
        }
        if(position < 0 || position > this.size()){
            return false;
        }
        if(position == 0){
            insertFirst(node);
            return true;
        }
        if(position == this.size()-1){
            insertLast(node);
            return true;
        }
        Student current = head;
        for(int i = 0; i < position - 1; i++){
            current = current.next;
        }
        node.next = current.next;
        current.next = node;
        return true;
    }

    public Student deleteFirst(){
        if(empty()){
            return null;
        }
        Student temp = head;
        head = head.next;
        return temp;
    }

    public Student deleteLast(){
        if(empty()){
            return null;
        }
        Student current = head;
        Student previous = null;
        while(current.next != null){
            previous = current;
            current = current.next;
        }
        previous.next = null;
        return current;
    }

    public Student deleteOn(int position){
        if(position < 0 || position > this.size()){
            return null;
        }
        if(position == 0){
            return deleteFirst();
        }
        if(position == this.size()-1){
            return deleteLast();
        }
        Student current = head;
        for(int i = 0; i < position - 1; i++){
            current = current.next;
        }
        Student temp = current.next;
        current.next = current.next.next;
        return temp;
    }

    public Student deleteByNpm(String npm){
        Student current = head;
        Student previous = null;
        while(current != null){
            if(current.getNpm().equals(npm)){
                if(previous == null){
                    head = head.next;
                }
                else{
                    previous.next = current.next;
                }
                return current;
            }
            previous = current;
            current = current.next;
        }
        return null;
    }

    public void printTable(){
        System.out.printf("%-15s %-5s %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
        "Nama", "Umur", "NPM", "Penguji1", "Penguji2", "Pembimbing", "NilaiAkhir", "NilaiMutu", "Status");
        for(Student temp = head; temp != null; temp = temp.next){
            System.out.printf("%-15s %-5d %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", temp.getName(), temp.getAge(), temp.getNpm(), temp.getNilaiPenguji1(), temp.getNilaiPenguji2(), temp.getNilaiPembimbing(), temp.getNilaiAkhir(), temp.getHurufMutu(), temp.getStatus());
        }
    }

    public void printFilteredTable(int sel, float nilai){
        System.out.printf("%-15s %-5s %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
        "Nama", "Umur", "NPM", "Penguji1", "Penguji2", "Pembimbing", "NilaiAkhir", "NilaiMutu", "Status");
        if(sel == 1){
            for(Student temp = head; temp != null; temp = temp.next){
                if(temp.getNilaiAkhir() > nilai){
                    System.out.printf("%-15s %-5d %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", temp.getName(), temp.getAge(), temp.getNpm(), temp.getNilaiPenguji1(), temp.getNilaiPenguji2(), temp.getNilaiPembimbing(), temp.getNilaiAkhir(), temp.getHurufMutu(), temp.getStatus());
                }
            }
        }else{
            for(Student temp = head; temp != null; temp = temp.next){
                if(temp.getNilaiAkhir() < nilai){
                    System.out.printf("%-15s %-5d %-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", temp.getName(), temp.getAge(), temp.getNpm(), temp.getNilaiPenguji1(), temp.getNilaiPenguji2(), temp.getNilaiPembimbing(), temp.getNilaiAkhir(), temp.getHurufMutu(), temp.getStatus());
                }
            }
        }
    }
}
