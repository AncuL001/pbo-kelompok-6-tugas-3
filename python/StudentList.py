# /*
#   Nama File : StudentList.py
#   Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
#   NPM       : 140810200020, 140810200030, 140810200032, 140810200048
#   Kelas     : B
#   Tanggal   : 17 November 2021
#   Deskripsi : Implementasi kasus linked list nilai sidang menggunakan C++, class StudentList
# *********************************************/

from Student import Student
class StudentList(Student):
    def __init__(self):
        self.first = None

    def empty(self):
        if self.first is None:
            return True
        else: 
            return False
    
    def isNpmUnique(self, node):
        current = self.first
        while current is not None:
            if current.getNpm() == node.getNpm():
                return False
            current = current.next
        return True

    def size(self):
        count = 0
        current = self.first
        while current is not None:
            count += 1
            current = current.next
        return count

    def insertFirst(self, node):
        if self.isNpmUnique(node) == False:
            return False
        node.next = self.first
        self.first = node
        return True
    
    def insertLast(self, node):
        if self.isNpmUnique(node) == False:
            return False
        current = self.first
        if current is None:
            self.first = node
            return True
        else:
            while current.next is not None:
                current = current.next
            current.next = node
            return True

    def insertOn(self, node, position):
        if self.isNpmUnique(node) == False:
            return False
        if position < 0 or position > self.size():
            return False
        if position == 0:
            self.insertFirst(node)
            return True
        if position == self.size():
            self.insertLast(node)
            return True
        current = self.first
        for i in range (0, position-1):
            current = current.next
        node.next = current.next
        current.next = node
        return True
    
    def deleteFirst(self):
        if self.empty() :
            return None
        temp = self.first
        self.first = self.first.next
        return temp

    def deleteLast(self):
        if self.empty():
            return None
        current = self.first
        previous = None
        while current.next is not None:
            previous = current
            current = current.next
        previous.next = None
        return current
    
    def deleteOn(self, position):
        if position < 0 or position > self.size():
            return None
        if position == 0:
            return self.deleteFirst
        if position == self.size():
            return self.deleteLast
        current = self.first
        for i in range(0, position-1):
            current = current.next
        temp = current.next
        current.next = temp.next
        return temp

    def deleteByNpm(self, npm):
        current = self.first
        previous = None
        while current is not None:
            if current.getNpm() == npm:
                if previous is None :
                    self.first = self.first.next
                else:
                    previous.next = current.next
                return current
            previous = current
            current = current.next
        return None
    
    def printTable(self):
        print("Nama\tUmur\tNPM\tPenguji1\tPenguji2\tPembimbing\tNilaiAkhir\tNilaiMutu\tStatus")
        temp = self.first
        while temp is not None:
            print(temp.getName() + "\t" + str(temp.getAge()) + "\t" + str(temp.getNpm()) + "\t" + str(temp.getNilaiPenguji1()) + "\t\t" + str(temp.getNilaiPenguji2()) + "\t\t" + str(temp.getNilaiPembimbing()) + "\t\t" + str(temp.getNilaiAkhir()) + "\t\t" + temp.getHurufMutu() + "\t\t" + temp.getStatus())
            temp = temp.next
    
    def printFilteredTable(self, sel, nilai):
        print("Nama\tUmur\tNPM\tPenguji1\tPenguji2\tPembimbing\tNilaiAkhir\tNilaiMutu\tStatus")
        if sel == '1':
            temp = self.first
            while temp is not None:
                if temp.getNilaiAkhir() > nilai:
                    print(temp.getName() + "\t" + str(temp.getAge()) + "\t" + str(temp.getNpm()) + "\t" + str(temp.getNilaiPenguji1()) + "\t\t" + str(temp.getNilaiPenguji2()) + "\t\t" + str(temp.getNilaiPembimbing()) + "\t\t" + str(temp.getNilaiAkhir()) + "\t\t" + temp.getHurufMutu() + "\t\t" + temp.getStatus())
                temp = temp.next
        else:
            temp = self.first
            while temp is not None:
                if temp.getNilaiAkhir() < nilai:
                    print(temp.getName() + "\t" + str(temp.getAge()) + "\t" + str(temp.getNpm()) + "\t" + str(temp.getNilaiPenguji1()) + "\t\t" + str(temp.getNilaiPenguji2()) + "\t\t" + str(temp.getNilaiPembimbing()) + "\t\t" + str(temp.getNilaiAkhir()) + "\t\t" + temp.getHurufMutu() + "\t\t" + temp.getStatus())
                temp = temp.next