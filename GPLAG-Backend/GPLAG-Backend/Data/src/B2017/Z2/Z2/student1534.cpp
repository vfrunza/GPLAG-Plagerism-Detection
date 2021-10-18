/* 
   B16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <new>
#include <string>
class ApstraktniStudent {
	std::string ime, prezime;
	int brojindeksa;
	int brojpolozenihispita;
	double prosjek;
public:
	ApstraktniStudent(std::string name, std::string surname, int indexnumber) : ime(name),prezime(surname),brojindeksa(indexnumber),prosjek(5),brojpolozenihispita(0) {}
	std::string DajIme() const { return ime; }
	std::string DajPrezime() const { return prezime; }
	int DajBrojIndeksa() const { return brojindeksa; }
	int DajBrojPolozenih() const { return brojpolozenihispita; }
	double DajProsjek() const { return prosjek; }
	void RegistrirajIspit(int ocjena);
	void PonistiOcjene() { prosjek=5; brojpolozenihispita=0; }
	virtual void IspisiPodatke() const = 0;
	virtual ApstraktniStudent* DajKopiju() const = 0;
	virtual ~ApstraktniStudent() {}
};
class StudentBachelor : public ApstraktniStudent {
public:
	StudentBachelor(std::string name, std::string surname, int indexnumber) : ApstraktniStudent(name,surname,indexnumber) {}
	void IspisiPodatke() const override { std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl; }
	ApstraktniStudent* DajKopiju() const override { return new StudentBachelor(*this); }
};
class StudentMaster : public ApstraktniStudent {
	int godinazavrsetka;
public:
	StudentMaster(std::string name, std::string surname, int indexnumber, int yearofgrad) : ApstraktniStudent(name,surname,indexnumber), godinazavrsetka(yearofgrad) {}
	void IspisiPodatke() const override { std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "<<godinazavrsetka<<",ima prosjek "<<DajProsjek()<<"."<<std::endl; }
	ApstraktniStudent* DajKopiju() const override { return new StudentMaster(*this); }
};
int main ()
{
	return 0;
}
void ApstraktniStudent::RegistrirajIspit(int ocjena) {
	if (ocjena<5 || ocjena>10) throw std::domain_error("Neispravna ocjena");
	if (ocjena==5) return;
	brojpolozenihispita++;
	prosjek=(prosjek*(brojpolozenihispita-1)+ocjena)/brojpolozenihispita;
}