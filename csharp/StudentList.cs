/*
  Nama File : StudentList.cs
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 17 November 2021
  Deskripsi : Implementasi kasus linked list nilai sidang menggunakan C#, class StudentList
*********************************************/
using System;

namespace csharp
{
    public class StudentList
    {
        protected Student head;

        public StudentList() {
            this.head = null;
        }

        public bool empty(){
            return head == null;
        }

        public bool isNpmUnique(Student data) {
            Student current = head;
            while (current != null) {
                if (current.getNpm() == data.getNpm()) {
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

        public bool insertFirst(Student node){
            if(!this.isNpmUnique(node)){
                Console.WriteLine("NPM sudah ada");
                return false;
            }
            node.next = head;
            head = node;
            return true;
        }

        public bool insertLast(Student node){
            if(!this.isNpmUnique(node)){
                Console.WriteLine("NPM sudah ada");
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

        public bool insertOn(int position, Student node){
            if(!this.isNpmUnique(node)){
                Console.WriteLine("NPM sudah ada");
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
                if(current.getNpm() == npm){
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
            //%-15s %-5s %-5s %-10s   %-10s      %-10s     %-10s     %-10s    %-10s
            //Nama Umur NPM Penguji1 Penguji2 Pembimbing NilaiAkhir NilaiMutu Status
            Console.Write($"{"Nama",-15} {"Umur",-5} {"NPM",-5} {"Penguji1",-10} {"Penguji2",-10} {"Pembimbing",-10} {"NilaiAkhir",-10} {"NilaiMutu",-10} {"Status",-10}\n");
            for(Student temp = head; temp != null; temp = temp.next){
                Console.Write($"{temp.getName(),-15} {temp.getAge(),-5} {temp.getNpm(),-5} {temp.getNilaiPenguji1(),-10} {temp.getNilaiPenguji2(),-10} {temp.getNilaiPembimbing(),-10} {temp.getNilaiAkhir(),-10} {temp.getHurufMutu(),-10} {temp.getStatus(),-10}\n");
            }
        }

        public void printFilteredTable(int sel, float nilai){
            Console.Write($"{"Nama",-15} {"Umur",-5} {"NPM",-5} {"Penguji1",-10} {"Penguji2",-10} {"Pembimbing",-10} {"NilaiAkhir",-10} {"NilaiMutu",-10} {"Status",-10}\n");
            if(sel == 1){
                for(Student temp = head; temp != null; temp = temp.next){
                    if(temp.getNilaiAkhir() > nilai){
                        Console.Write($"{temp.getName(),-15} {temp.getAge(),-5} {temp.getNpm(),-5} {temp.getNilaiPenguji1(),-10} {temp.getNilaiPenguji2(),-10} {temp.getNilaiPembimbing(),-10} {temp.getNilaiAkhir(),-10} {temp.getHurufMutu(),-10} {temp.getStatus(),-10}\n");
                    }
                }
            }else{
                for(Student temp = head; temp != null; temp = temp.next){
                    if(temp.getNilaiAkhir() < nilai){
                        Console.Write($"{temp.getName(),-15} {temp.getAge(),-5} {temp.getNpm(),-5} {temp.getNilaiPenguji1(),-10} {temp.getNilaiPenguji2(),-10} {temp.getNilaiPembimbing(),-10} {temp.getNilaiAkhir(),-10} {temp.getHurufMutu(),-10} {temp.getStatus(),-10}\n");
                    }
                }
            }
        }
    }
}
