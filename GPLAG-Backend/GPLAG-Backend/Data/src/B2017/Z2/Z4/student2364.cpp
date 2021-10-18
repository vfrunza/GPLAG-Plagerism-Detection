/* 
   B16/17 (Tutorijal 13, Zadatak 4)
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
class ApstraktniStudent {
	std::string ime, prezime;
	int brojindeksa;
	int brojpolozenihispita;
	double prosjek;
public:
	virtual ~ApstraktniStudent() {}
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
};
class StudentBachelor : public ApstraktniStudent {
public:
	StudentBachelor(std::string name, std::string surname, int indexnumber) : ApstraktniStudent(name,surname,indexnumber) {}
	void IspisiPodatke() const override
	{ std::cout<<"Student bachelor studija "<<DajIme()<<" "
	<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()
	<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl; }
	ApstraktniStudent* DajKopiju() const override { return new StudentBachelor(*this); }
	
};
class StudentMaster : public ApstraktniStudent {
	int godinazavrsetka;
public:
	StudentMaster(std::string name, std::string surname, int indexnumber, int yearofgrad) : ApstraktniStudent(name,surname,indexnumber), godinazavrsetka(yearofgrad) {}
	void IspisiPodatke() const override 
	{ std::cout<<"Student master studija "<<DajIme()
	<<" "<<DajPrezime()<<", sa brojem indeksa "
	<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "
	<<godinazavrsetka<<",ima prosjek "<<DajProsjek()<<"."<<std::endl; }
	ApstraktniStudent* DajKopiju() const override { return new StudentMaster(*this); }
};
class Fakultet {
	std::vector<ApstraktniStudent*> studenti;
	bool DaLiPostojiIndeks(int indexnumber) const;
public: 
	Fakultet() {}
	~Fakultet() { for (auto student : studenti) delete student; studenti.resize(0);}
	Fakultet(const Fakultet &f);
	Fakultet &operator =(const Fakultet &f);
	Fakultet(Fakultet &&f);
	Fakultet &operator =(Fakultet &&f);
	void UpisiStudenta(std::string name, std::string surname, int indexnumber);
	void UpisiStudenta(std::string name, std::string surname, int indexnumber, int yearofgrad);
	void ObrisiStudenta(int indexnumber);
	ApstraktniStudent& operator [](int indexnumber);
	const ApstraktniStudent& operator [](int indexnumber) const;
	void IspisiSveStudente() const;
};
class Student {
	public:
	~Student() { delete student; }
	ApstraktniStudent* student;
	void Test() const { if (!student) throw std::logic_error("."); }
	Student() : student(nullptr) {}
	Student(const ApstraktniStudent &f) : student(f.DajKopiju()) {}
	Student(const Student &f) {
		if (!f.student) student=nullptr;
		else student=f.student->DajKopiju();
	}
	Student &operator =(const ApstraktniStudent &s){
		ApstraktniStudent *pomocni(nullptr);
		pomocni = s.DajKopiju();
		delete student;
		student = pomocni;
		return *this;
		
	}
	Student(Student &&f) : student(std::move(f.student)) { f.student=nullptr;}
	Student &operator =(const Student &f) {
		if (&f!=this) {
			delete student;
			student=f.student->DajKopiju();
		}
		return *this;
	}
	Student &operator =(Student &&f) {
		if (&f!=this) {
			delete student;
			student=std::move(f.student);
			f.student=nullptr;
		}
		return *this;
	}
	Student &operator =(ApstraktniStudent &&f) {
		delete student;
		student=f.DajKopiju();
		return *this;
	}
	Student(ApstraktniStudent &&f) : student(f.DajKopiju()) {}
	std::string DajIme() const { return student->DajIme(); }
	std::string DajPrezime() const { return student->DajPrezime(); }
	int DajBrojIndeksa() const { return student->DajBrojIndeksa(); }
	int DajBrojPolozenih() const { return student->DajBrojPolozenih(); }
	double DajProsjek() const { return student->DajProsjek(); }
	void RegistrirajIspit(int ocjena);
	void PonistiOcjene() { Test(); student->PonistiOcjene();}
	virtual void IspisiPodatke() const { student->IspisiPodatke(); }

};


int main ()
{
	StudentBachelor sb("Dusko", "Dugousko", 1234);
  StudentMaster sm("Paja", "Patak", 4312, 2015);
  Student s1(sb); 
  Student s2(sm);
  Student s3(sb), s4(sm), s5(s1), s6(std::move(s2));   // Test konstruktora
  s3.IspisiPodatke(); s4.IspisiPodatke();
  s5.IspisiPodatke(); s6.IspisiPodatke();
	return 0;
}



bool Fakultet::DaLiPostojiIndeks(int indexnumber) const { 
	for (auto student : studenti) {
		if (student->DajBrojIndeksa()==indexnumber) return true;
	}
	return false;
}
Fakultet::Fakultet(const Fakultet &f) {
	for (auto student : f.studenti)
		studenti.push_back(student->DajKopiju());
}
Fakultet::Fakultet(Fakultet &&f) {
	studenti=f.studenti;
	f.studenti.resize(0);
}
Fakultet& Fakultet::operator =(const Fakultet &f) {
	if (&f!=this) {
		for (auto student : studenti) delete student;
		studenti.resize(0);
		for (auto student : f.studenti)
			studenti.push_back(student->DajKopiju());
	}
	return *this;
}
Fakultet& Fakultet::operator =(Fakultet &&f) {
	if (&f!=this) {
		for (auto student : studenti) delete student;
		studenti=f.studenti;
		f.studenti.resize(0);
	}
	return *this;
}
void Fakultet::UpisiStudenta(std::string name, std::string surname, int indexnumber) {
	if (DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	auto p=new StudentBachelor(name,surname,indexnumber);
    studenti.push_back(p);
}
void Fakultet::UpisiStudenta(std::string name, std::string surname, int indexnumber, int yearofgrad) {
	if (DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	auto p=new StudentMaster(name,surname,indexnumber,yearofgrad);
    studenti.push_back(p);
}
void Fakultet::ObrisiStudenta(int indexnumber) {
	if (!DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	auto pok=std::find_if(studenti.begin(),studenti.end(),[indexnumber](ApstraktniStudent* pok) { return pok->DajBrojIndeksa()==indexnumber;});
	delete *pok;
	studenti.erase(pok);
}
ApstraktniStudent& Fakultet::operator [](int indexnumber) {
	if (!DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	return **std::find_if(studenti.begin(),studenti.end(),[indexnumber](ApstraktniStudent* pok) { return pok->DajBrojIndeksa()==indexnumber;});
}
const ApstraktniStudent& Fakultet::operator [](int indexnumber) const {
	if (!DaLiPostojiIndeks(indexnumber)) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	return **std::find_if(studenti.begin(),studenti.end(),[indexnumber](ApstraktniStudent* pok) { return pok->DajBrojIndeksa()==indexnumber;});
}
void Fakultet::IspisiSveStudente() const {
	std::vector<ApstraktniStudent*> v(studenti);
    std::sort(v.begin(),v.end(),[](ApstraktniStudent *p1, ApstraktniStudent *p2) {
        double prosjek1(p1->DajProsjek()), prosjek2(p2->DajProsjek());
        if(prosjek1 != prosjek2) return prosjek1 > prosjek2;
        else return p1->DajBrojIndeksa() < p2->DajBrojIndeksa();
    });
    for(auto p : v) p->IspisiPodatke();
}
void ApstraktniStudent::RegistrirajIspit(int ocjena) {
	if (ocjena<5 || ocjena>10) throw std::domain_error("Neispravna ocjena");
	if (ocjena==5) return;
	brojpolozenihispita++;
	prosjek=(prosjek*(brojpolozenihispita-1)+ocjena)/brojpolozenihispita;
}
void Student::RegistrirajIspit(int ocjena) {
	student->RegistrirajIspit(ocjena);
} 