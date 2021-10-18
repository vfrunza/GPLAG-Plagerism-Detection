/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>

int main ()
{
    Datum *niz_datuma[10]{}; // Svi pokazivači se inicijaliziraju na nullptr...
std::cout << "Unesi 10 datuma:\n"; 
try {
 for(int i = 0; i < 10; i++) {
 int dan, mjesec, godina;
 std::cout << "Datum " << i + 1 << ":" << std::endl;
 std::cout << " Dan: "; std::cin >> dan;
 std::cout << " Mjesec: "; std::cin >> mjesec;
 std::cout << " Godina: "; std::cin >> godina;
 try {
 niz_datuma[i] = new Datum(dan, mjesec, godina); // Konstruktor može  baciti izuzetak!
 }  
 
 catch(std::domain_error izuzetak) {
 std::cout << izuzetak.what() << std::endl;
 i--; // Ponovi unos!
 }
 }
 std::cout << "Unijeli ste datume:\n";
 for(int i = 0; i < 10; i++) {
 niz_datuma[i]->Ispisi();
 std::cout << std::endl;
 }
}
catch(std::bad_alloc) {
 std::cout << "Problemi sa memorijom!\n";
}
for(int i = 0; i < 10; i++) delete niz _atuma[i]; // Obriši zauzeto...
	return 0;
}



class Student {
 char ime i prezime[50];
 int indeks;
 Datum datum rodjenja;
public:
 Student(const char i_i_p[], int indeks, int d, int m, int g) :
 datum rodjenja(d, m, g) {
 std::strcpy(ime_i_prezime, i_i_p); Student::indeks = indeks;
 }
 … // Ovdje bi trebalo definirati ostatak interfejsa klase
};