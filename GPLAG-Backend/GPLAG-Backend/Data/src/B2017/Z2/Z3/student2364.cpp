/*
   B16/17 (Tutorijal 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <new>
#include <string>
#include <algorithm>
#include <vector>



#define TestirajIzuzetak(izuzetak, tijelo) \
  try tijelo catch(izuzetak e) { std::cout << e.what() << std::endl; }


class ApstraktniStudent
{
	std::string ime, prezime;
	int brojindeksa;
	int brojpolozenihispita;
	double prosjek;
public:
	ApstraktniStudent(std::string name, std::string surname, int indexnumber) : ime(name),prezime(surname),brojindeksa(indexnumber),prosjek(5),brojpolozenihispita(0) {}
	std::string DajIme() const {
		return ime;
	}
	std::string DajPrezime() const {
		return prezime;
	}
	int DajBrojIndeksa() const {
		return brojindeksa;
	}
	int DajBrojPolozenih() const {
		return brojpolozenihispita;
	}
	double DajProsjek() const {
		return prosjek;
	}
	void RegistrirajIspit(int ocjena);
	void PonistiOcjene() {
		prosjek=5;
		brojpolozenihispita=0;
	}
	virtual void IspisiPodatke() const = 0;
	virtual ApstraktniStudent* DajKopiju() const = 0;
	virtual ~ApstraktniStudent() {}
};
class StudentBachelor : public ApstraktniStudent
{
public:
	StudentBachelor(std::string name, std::string surname, int indexnumber) : ApstraktniStudent(name,surname,indexnumber) {}
	void IspisiPodatke() const override {
		std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl;
	}
	ApstraktniStudent* DajKopiju() const override {
		return new StudentBachelor(*this);
	}
};
class StudentMaster : public ApstraktniStudent
{
	int godinazavrsetka;
public:
	StudentMaster(std::string name, std::string surname, int indexnumber, int yearofgrad) : ApstraktniStudent(name,surname,indexnumber), godinazavrsetka(yearofgrad) {}
	void IspisiPodatke() const override {
		std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "<<godinazavrsetka<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
	}
	ApstraktniStudent* DajKopiju() const override {
		return new StudentMaster(*this);
	}
};
class Fakultet
{
	std::vector<ApstraktniStudent*> studenti;
	bool DaLiPostojiIndeks(int indexnumber) const;
public:
	Fakultet() {}
	~Fakultet() {
		for (auto student : studenti) delete student;
		studenti.resize(0);
	}
	Fakultet(const Fakultet &f);
	Fakultet &operator =(const Fakultet &f);
	Fakultet(Fakultet &&f);
	Fakultet &operator =(Fakultet &&f);
	void UpisiStudenta(std::string name, std::string surname, int indexnumber);
	void UpisiStudenta(std::string name, std::string surname, int indexnumber, int yearofgrad);
	void ObrisiStudenta(int indexnumber);
	ApstraktniStudent& operator [](int indexnumber);
	ApstraktniStudent& operator [](int indexnumber) const;
	void IspisiSveStudente() const;
};
int main ()
{
	Fakultet f1;
	f1.UpisiStudenta("Meho", "Mehic", 3412);
	f1.UpisiStudenta("Ibro", "Ibric", 3124, 2015);
	f1.ObrisiStudenta(3412);
	f1.IspisiSveStudente();
	TestirajIzuzetak(std::logic_error, { f1.ObrisiStudenta(6789); });
	return 0;
}
bool Fakultet::DaLiPostojiIndeks(int indexnumber) const {
		for (auto student : studenti) {
			if (student->DajBrojIndeksa()==indexnumber) return true;
		}
		return false;
}

Fakultet::Fakultet(const Fakultet &f)
{
	for (auto student : f.studenti)
		studenti.push_back(student->DajKopiju());
}
Fakultet::Fakultet(Fakultet &&f)
{
	studenti=std::move(f.studenti);
}
Fakultet& Fakultet::operator =(const Fakultet &f)
{
	if (&f!=this) {
		for (auto student : studenti) delete student;
		studenti.resize(0);
		for (auto student : f.studenti)
			studenti.push_back(student->DajKopiju());
	}
	return *this;
}
Fakultet& Fakultet::operator =(Fakultet &&f)
{
	if (&f!=this) {
		for (auto student : studenti) delete student;
		studenti=std::move(f.studenti);
	}
	return *this;
}
void Fakultet::UpisiStudenta(std::string name, std::string surname, int indexnumber)
{
	if (DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	auto p=new StudentBachelor(name,surname,indexnumber);
	studenti.push_back(p);
}
void Fakultet::UpisiStudenta(std::string name, std::string surname, int indexnumber, int yearofgrad)
{
	if (DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	auto p=new StudentMaster(name,surname,indexnumber,yearofgrad);
	studenti.push_back(p);
}
void Fakultet::ObrisiStudenta(int indexnumber)
{
	if (!DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	auto pok=std::find_if(studenti.begin(),studenti.end(),[indexnumber](ApstraktniStudent* pok) {
		return pok->DajBrojIndeksa()==indexnumber;
	});
	delete *pok;
	studenti.erase(pok);
}
ApstraktniStudent& Fakultet::operator [](int indexnumber)
{
	if (!DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	return **std::find_if(studenti.begin(),studenti.end(),[indexnumber](ApstraktniStudent* pok) {
		return pok->DajBrojIndeksa()==indexnumber;
	});
}
ApstraktniStudent& Fakultet::operator [](int indexnumber) const
{
	if (!DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	return **std::find_if(studenti.begin(),studenti.end(),[indexnumber](ApstraktniStudent* pok) {
		return pok->DajBrojIndeksa()==indexnumber;
	});
}
void Fakultet::IspisiSveStudente() const
{
	std::vector<ApstraktniStudent*> v(studenti);
	std::sort(v.begin(),v.end(),[](ApstraktniStudent *p1, ApstraktniStudent *p2) {
		double prosjek1(p1->DajProsjek()), prosjek2(p2->DajProsjek());
		if(prosjek1 != prosjek2) return prosjek1 > prosjek2;
		else return p1->DajBrojIndeksa() < p2->DajBrojIndeksa();
	});
	for(auto p : v) p->IspisiPodatke();
}
void ApstraktniStudent::RegistrirajIspit(int ocjena)
{
	if (ocjena<5 || ocjena>10) throw std::domain_error("Neispravna ocjena");
	if (ocjena==5) return;
	brojpolozenihispita++;
	prosjek=(prosjek*(brojpolozenihispita-1)+ocjena)/brojpolozenihispita;
}
// 2-2