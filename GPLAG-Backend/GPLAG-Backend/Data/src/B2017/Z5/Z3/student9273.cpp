/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
class Student {
 std::string ime;
 int indeks;
public:
 Student(std::string ime, int ind) : ime(ime), indeks(ind) {}
 std::string DajIme() const { return ime; }
 int DajIndeks() const { return indeks; }
 void Ispisi() const {
 std::cout << "Student " << ime << " ima indeks " << indeks;
 }
};
class DiplomiraniStudent : public Student {
 int godina_diplomiranja;
public:
 DiplomiraniStudent(std::string ime, int ind, int god_dipl) :
 Student(ime, ind), godina_diplomiranja(god_dipl) {}
 int DajGodinuDiplomiranja() const { return godina_diplomiranja; }
};

int main ()
{
	return 0;
}
