/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
using namespace std;
class Datum {
 int dan, mjesec, godina;
public:
 Datum(int d, int m, int g);
 void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};
class Ucenik {
 static const int BrojPredmeta = 10; // Pri testiranju smanjite
 char ime[20], prezime[20]; // broj predmeta...
 Datum datum_rodjenja;
 int ocjene[BrojPredmeta];
 double prosjek;
 bool prolaz;
public:
 Ucenik(const char ime[], const char prezime[], int d, int m, int g);
 void PostaviOcjenu(int predmet, int ocjena);
 static int DajBrojPredmeta() { return BrojPredmeta; }
 double DajProsjek() const { return prosjek; }
 bool DaLiJeProsao() const { return prolaz; }
 void Ispisi() const;
};
class Razred {
 const int kapacitet;
 int broj_evidentiranih;
 Ucenik **ucenici;
 static bool BoljiProsjek(const Ucenik *u1, const Ucenik *u2) {
 return u1->DajProsjek() > u2->DajProsjek();
 }
public:
 explicit Razred(int broj_ucenika) : kapacitet(broj_ucenika),
 broj_evidentiranih(0), ucenici(new Ucenik*[broj_ucenika]{}) {}
 
 ~Razred();
/* Razred(const Razred &r) = delete; // Zabrana kopiranja
 Razred &operator =(const Razred &r) = delete; // Zabrana dodjele
 */
 Razred(const Razred &r) : ucenici(new Ucenik*[r.kapacitet]{}),
 kapacitet(r.kapacitet), broj evidentiranih(r.broj_evidentiranih) {
 try {
 for(int i = 0; i < r.broj_evidentiranih; i++)
ucenici[i] = new Ucenik(*r.ucenici[i]);
 }
 catch(...) {
 for(int i = 0; i < r.broj_evidentiranih; i++) delete ucenici[i];
 delete[] ucenici; throw;
 }
}
Razred::Razred(Razred &&r) : ucenici(r.ucenici), kapacitet(r.kapacitet),
 broj_evidentiranih(r.broj_evidentiranih) {
 r.ucenici = nullptr; r.broj_evidentiranih = 0;
}
 &Razred::operator =(Razred r) {
 if(r.kapacitet != kapacitet)
 throw std::logic_error("Razredi nesaglasnih kapaciteta!");
 std::swap(broj_evidentiranih, r.broj_evidentiranih);
 std::swap(ucenici, r.ucenici);
 return *this;
}
Razred &Razred::operator =(Razred &&r) {
 if(r.kapacitet != kapacitet)
 throw std::logic_error("Razredi nesaglasnih kapaciteta!");
 std::swap(broj_evidentiranih, r.broj_evidentiranih);
 std::swap(ucenici, r.ucenici);
 return *this;
}


 void EvidentirajUcenika(Ucenik *ucenik);
 void UnesiNovogUcenika();
 void IspisiIzvjestaj() const;
 void SortirajUcenike() {
 std::sort(ucenici, ucenici + broj_evidentiranih, BoljiProsjek);
 }
};

Datum::Datum(int d, int m, int g) {
 int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
 if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
 throw std::domain_error("Neispravan datum!");
 dan = d; mjesec = m; godina = g;
}
Ucenik::Ucenik(const char ime[], const char prezime[], int d, int m, int g) :
 datum_rodjenja(d, m, g), prosjek(1), prolaz(false) {
 if(std::strlen(ime) > 19 || std::strlen(prezime) > 19)
 throw std::domain_error("Predugacko ime ili prezime!");
 std::strcpy(Ucenik::ime, ime);
 std::strcpy(Ucenik::prezime, prezime);
 for(int &ocjena : ocjene) ocjena = 1;
}
void Ucenik::PostaviOcjenu(int predmet, int ocjena) {
 if(ocjena < 1 || ocjena > 5)
 throw std::domain_error("Pogresna ocjena!");
 if(predmet < 1 || predmet > BrojPredmeta)
 throw std::domain_error("Pogresna sifra predmeta!");
 ocjene[predmet - 1] = ocjena;
 prosjek = 1; prolaz= false;
 double suma_ocjena(0);
 for(int ocjena : ocjene) {
 if(ocjena == 1) return;
 suma_ocjena += ocjena;
 }
 prosjek = suma_ocjena / BrojPredmeta; prolaz = true;
}
void Ucenik::Ispisi() const {
 std::cout << "Ucenik " << ime << " " << prezime << " rodjen ";
 datum_rodjenja.Ispisi();
 if(DaLiJeProsao())
 std::cout << " ima prosjek "
 << std::setprecision(3) << DajProsjek() << std::endl;
 else
 std::cout << " mora ponavljati razred\n";
}
Razred::~Razred() {
 for(int i = 0; i < broj_evidentiranih; i++) delete ucenici[i];
 delete[] ucenici;
}
void Razred::EvidentirajUcenika(Ucenik *ucenik) {
 if(broj_evidentiranih >= kapacitet)
 throw std::range_error("Previse ucenika!");
 ucenici[broj_evidentiranih++] = ucenik;
}
void Razred::UnesiNovogUcenika() {
 bool pogresan_unos(true);
 while(pogresan_unos) {
 Ucenik *ucenik(nullptr);
 try {
 char ime[20], prezime[20];
 int d, m, g;
 char znak1, znak2;
 std::cout << " Ime: "; std::cin >> std::setw(20) >> ime;
 std::cout << " Prezime: "; std::cin >> std::setw(20) >> prezime;
 std::cout << " Datum rodjenja (D/M/G): ";
 std::cin >> d >> znak1 >> m >> znak2 >> g;
 if(!std::cin || znak1 != '/' || znak2 != '/')
 throw std::domain_error("Pogresan datum!");
 ucenik = new Ucenik(ime, prezime, d, m, g);
 for(int predmet = 1; predmet <= Ucenik::DajBrojPredmeta(); predmet++) {
 int ocjena;
 std::cout << " Ocjena iz " << predmet << ". predmeta: ";
 std::cin >> ocjena;
 if(!std::cin) throw std::domain_error("Pogresna ocjena!");
 ucenik->PostaviOcjenu(predmet, ocjena);
 }
 EvidentirajUcenika(ucenik);
 pogresan_unos = false;
 }
 catch(std::domain_error greska) {
 cout << "Greska: " << greska.what() << "\nMolimo, ponovite unos!\n";
 std::cin.clear();std::cin.ignore(10000, '\n');
 delete ucenik; ucenik = nullptr;
 }
 }
}
void Razred::IspisiIzvjestaj() const {
 std::cout << std::endl;
 for(int i = 0; i < broj_evidentiranih; i++) ucenici[i]->Ispisi();
}

int main() {
 try {
 int broj_ucenika;
 std::cout << "Koliko ima ucenika: ";
 std::cin >> broj_ucenika;
 if(!std::cin) throw ""; // Ovdje je nebitno šta bacamo...
 Razred razred(broj_ucenika);
 for(int i = 1; i <= broj_ucenika; i++) {
 std::cout << "Unesi podatke za " << i << ". ucenika:\n";
 razred.UnesiNovogUcenika();
 }
 razred.SortirajUcenike();
 razred.IspisiIzvjestaj();
 }
 catch(...) {
 std::cout << "Problemi sa memorijom!\n";
 }
 return 0;
}