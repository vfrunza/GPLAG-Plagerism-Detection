prvi

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
using std::cout;
using std::cin;
class Lik{
	public:
	virtual void IspisiSpecificnosti(){};
	virtual double DajObim(){};
	virtual double DajPovrsinu(){};
	virtual void Ispisi(){
		IspisiSpecificnosti();
		cout << "Obim: " << DajObim() << " Povrsina: "<< DajPovrsinu() << std::endl;
	}
	virtual ~Lik(){};
};
class Krug : public Lik{
	double r;
	public:
	Krug(double rad){
		if(rad<=0) throw std::domain_error("Neispravni parametri");
		r=rad;
	};
	void IspisiSpecificnosti(){
		std::cout<< "Krug poluprecnika " << r<< std::endl; 
	}
	double DajObim(){ return 2*4*atan(1)*r;}
	double DajPovrsinu(){ return r*r*4*atan(1);}
	~Krug(){};
};
class Pravougaonik: public Lik{
	double a,b;
	public:
	Pravougaonik(double aa, double bb){
		if(aa<=0 or bb<=0) throw std::domain_error("Neispravni parametri");
		a=aa; b=bb;
	};
	void IspisiSpecificnosti(){
		std::cout<< "Pravougaonik sa stranicama duzine " << a <<" i " <<b << std::endl; 
	}
	double DajObim(){ return 2*a+2*b;}
	double DajPovrsinu(){ return a*b;}
	~Pravougaonik(){};
};
class Trougao : public Lik{
	double a, b, c;
	public:
	Trougao(double aa, double bb, double cc){
		if(aa<=0 or bb<=0 or cc<=0 or aa+bb<=cc or aa+cc<=bb or bb+cc<=aa) throw std::domain_error("Neispravni parametri");
		a=aa; b=bb; c=cc;
	};
	void IspisiSpecificnosti(){
		std::cout<< "Trougao sa stranicama duzine " << a <<", "<< b <<" i " <<c<< std::endl; 
	}
	double DajObim(){ return a+b+c;}
	double DajPovrsinu(){ double s=(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c));};
	~Trougao(){};
};

int main ()
{
	cout << "Koliko zelite likova: ";
	int n;
	std::vector<std::shared_ptr<Lik>> v;
	cin >> n;
	for(int i=0; i<n; i++){
		cout << "Lik "<<i+1<<": ";
		char znak;
		cin >> znak;
		if(znak!='T' and znak!='P' and znak!='K'){
			i--;
			cin.ignore(1000, '\n');
			cout << "Pogresni podaci, ponovite unos!\n";
			continue;
		}
		if(znak=='K'){
			double x;
			cin >> x;
			std::string s;
			std::getline(cin, s);
			if(!cin or s.size()!=0){
				cin.clear();
				i--;
				cout << "Pogresni podaci, ponovite unos!\n";
				continue;
			}
			try{
				v.push_back(std::make_shared<Krug>(x));
			} catch(std::domain_error e){
				cout << "Pogresni podaci, ponovite unos!\n";
				i--;
			}
		}
		else if(znak=='P'){
			double a, b;
			char z;
			cin >> a >> z >> b;
			std::string s;
			std::getline(cin, s);
			if(!cin or s.size()!=0){
				cin.clear();
				i--;
				cout << "Pogresni podaci, ponovite unos!\n";
				continue;
			}
			try{
				v.push_back(std::make_shared<Pravougaonik>(a,b));
			} catch(std::domain_error e){
				cout << "Pogresni podaci, ponovite unos!\n";
				i--;
			}
		}
		else if(znak=='T'){
			double a, b, c;
			char z;
			cin >> a >> z >> b >> z >> c;
			std::string s;
			std::getline(cin, s);
			if(!cin or s.size()!=0){
				cin.clear();
                cin.ignore(10000, '\n');
				i--;
				cout << "Pogresni podaci, ponovite unos!\n";
				continue;
			}
			try{
				v.push_back(std::make_shared<Trougao>(a,b,c));
			} catch(std::domain_error e){
				cout << "Pogresni podaci, ponovite unos!\n";
				i--;
			}
		}
	}
	cout << std::endl;
	for(int i=0; i<v.size(); i++){
		v[i]->Ispisi();
	}
	return 0;
}




drugi

#include <iostream>
#include <string>
#include <stdexcept>
using std::string;
class ApstraktniStudent{
	string ime, prezime;
	int indeks, broj_polozenih;
	double prosjek;
	public:
	ApstraktniStudent(string ime, string prezime, int indeks, int broj_polozenih=0, double prosjek=5):ime(ime), prezime(prezime), indeks(indeks), broj_polozenih(broj_polozenih),
		prosjek(prosjek){};
	string DajIme(){ return ime;}
	string DajPrezime(){ return prezime;}
	int DajBrojIndeksa(){ return indeks;}
	int DajBrojPolozenih(){ return broj_polozenih;}
	double DajProsjek(){ return prosjek;}
	void RegistrirajIspit(int ocjena){
		if(ocjena<5 or ocjena>10) throw std::domain_error("Neispravna ocjena");
		else if(ocjena!=5){
			prosjek=((prosjek*broj_polozenih)+ocjena)/(broj_polozenih+1);
			broj_polozenih++;
		}
	}
	void PonistiOcjene(){ prosjek=5; broj_polozenih=0;}
	virtual void IspisiPodatke(){};
	virtual ApstraktniStudent* DajKopiju(){};
	virtual ~ApstraktniStudent(){};
};
class StudentBachelor: public ApstraktniStudent{
	public:
	StudentBachelor(string ime, string prezime, int indeks, int broj=0, double avg=5): ApstraktniStudent(ime, prezime, indeks, broj, avg){};
	void IspisiPodatke(){
		std::cout << "Student bachelor studija "<<DajIme()<< " "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<",\nima prosjek "<<DajProsjek()<<".\n";
	}
	StudentBachelor* DajKopiju(){
		return new StudentBachelor(DajIme(), DajPrezime(),DajBrojIndeksa(), DajBrojPolozenih(), DajProsjek());
	}
	~StudentBachelor(){};
};
class StudentMaster: public ApstraktniStudent{
	int godina;
	public:
	StudentMaster(string ime, string prezime, int indeks, int godina, int broj=0, double avg=5): ApstraktniStudent(ime, prezime, indeks, broj, avg), godina(godina){};
	void IspisiPodatke(){
		std::cout << "Student master studija "<<DajIme()<< " "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<",\nzavrsio bachelor studij godine "<< godina <<",ima prosjek "<<DajProsjek()<<".\n";
	}
	StudentMaster* DajKopiju(){
		return new StudentMaster(DajIme(), DajPrezime(),DajBrojIndeksa(), DajBrojPolozenih(), DajProsjek(), godina);
	}
	~StudentMaster(){};
};
using std::cin;
using std::cout;
int main ()
{
	 std::cout << "Koliko zelite unijeti bachelor studenata?";
	int n;
	std::cin >>n;
	cin.ignore(10000, '\n');
	for(int i=0; i<n; i++){
		cout << "Student " << i+1 << ":";
		string ime, prezime;
		int brind;
		std::getline(cin, ime);
		cin.ignore(10000, '\n');
		std::getline(cin, prezime);
		cin >> brind;
		cin.ignore(10000, '\n');
		StudentBachelor s1(ime, prezime, brind);
		s1.IspisiPodatke();
	}
	std::cout << "Koliko zelite unijeti master studenata?";
	std::cin >>n;
	cin.ignore(10000, '\n');
	for(int i=0; i<n; i++){
		cout << "Student " << i+1 << ":";
		string ime, prezime;
		int brind, god;
		std::getline(cin, ime);
		cin.ignore(10000, '\n');
		std::getline(cin, prezime);
		cin.ignore(10000, '\n');
		cin>> brind >> god;
		StudentMaster s2(ime, prezime, brind, god);
		s2.IspisiPodatke();
	}
	return 0;
}




treci

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::string;
class ApstraktniStudent{
	string ime, prezime;
	int indeks, broj_polozenih;
	double prosjek;
	public:
	ApstraktniStudent(string ime, string prezime, int indeks, int broj_polozenih=0, double prosjek=5):ime(ime), prezime(prezime), indeks(indeks), broj_polozenih(broj_polozenih),
		prosjek(prosjek){};
	string DajIme(){ return ime;}
	string DajPrezime(){ return prezime;}
	int DajBrojIndeksa(){ return indeks;}
	int DajBrojPolozenih(){ return broj_polozenih;}
	double DajProsjek(){ return prosjek;}
	void RegistrirajIspit(int ocjena){
		if(ocjena<5 or ocjena>10) throw std::domain_error("Neispravna ocjena");
		else if(ocjena!=5){
			double a(((DajProsjek()*DajBrojPolozenih())+ocjena)/(DajBrojPolozenih()+1));
			broj_polozenih++;
			prosjek=a;
		}
	}
	void PonistiOcjene(){ prosjek=5; broj_polozenih=0;}
	virtual void IspisiPodatke(){};
	virtual ApstraktniStudent* DajKopiju(){};
	virtual ~ApstraktniStudent(){};
};
class StudentBachelor: public ApstraktniStudent{
	public:
	StudentBachelor(string ime, string prezime, int indeks, int broj=0, double avg=5): ApstraktniStudent(ime, prezime, indeks, broj, avg){};
	void IspisiPodatke(){
		std::cout << "Student bachelor studija "<<DajIme()<< " "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<",\nima prosjek "<<DajProsjek()<<".\n";
	}
	StudentBachelor* DajKopiju(){
		return new StudentBachelor(DajIme(), DajPrezime(),DajBrojIndeksa(), DajBrojPolozenih(), DajProsjek());
	}
	~StudentBachelor(){};
};
class StudentMaster: public ApstraktniStudent{
	int godina;
	public:
	StudentMaster(string ime, string prezime, int indeks, int godina, int broj=0, double avg=5): ApstraktniStudent(ime, prezime, indeks, broj, avg), godina(godina){};
	void IspisiPodatke(){
		std::cout << "Student master studija "<<DajIme()<< " "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<",\nzavrsio bachelor studij godine "<< godina <<",ima prosjek "<<DajProsjek()<<".\n";
	}
	StudentMaster* DajKopiju(){
		return new StudentMaster(DajIme(), DajPrezime(),DajBrojIndeksa(),godina, DajBrojPolozenih(), DajProsjek());
	}
	~StudentMaster(){};
};
class Fakultet{
	std::vector<ApstraktniStudent*> v;
	public:
	Fakultet(){}
	~Fakultet(){
		for(int i=0; i<v.size(); i++){
			delete v[i];
		}
	}
	Fakultet(const Fakultet& f);
	Fakultet &operator = (const Fakultet& f);
	Fakultet( Fakultet&& f);
	Fakultet &operator 😞 Fakultet&& f);
	void UpisiStudenta(string ime, string prezime, int brind, int god);
	void UpisiStudenta(string ime, string prezime, int brind);
	void ObrisiStudenta(int brind);
	ApstraktniStudent& operator [](int brind) const;
	ApstraktniStudent& operator [](int brind);
	void IspisiSveStudente()const ;
};
Fakultet::Fakultet(const Fakultet& f){
	for(int i=0; i<f.v.size(); i++){
		v.push_back(f.v[i]->DajKopiju());
	}
}
Fakultet &Fakultet::operator = (const Fakultet& f){
	for(int i=0; i<v.size(); i++){
			delete v[i];
		}
	v.clear();
	for(int i=0; i<f.v.size(); i++){
		v.push_back(f.v[i]->DajKopiju());
	}
	return *this;
}
Fakultet::Fakultet(Fakultet&& f){
	v=f.v;
	f.v.clear();
}
Fakultet &Fakultet::operator 😞 Fakultet&& f){
	for(int i=0; i<v.size(); i++){
			delete v[i];
	}
	v.clear();
	v=f.v;
	f.v.clear();
	return*this;
}
void Fakultet::UpisiStudenta(string ime, string prezime, int brind){
	for(int i=0; i<v.size(); i++){
		if(v[i]->DajBrojIndeksa()==brind) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	}
	v.push_back(new StudentBachelor(ime, prezime, brind));
}
void Fakultet::UpisiStudenta(string ime, string prezime, int brind, int god){
	for(int i=0; i<v.size(); i++){
		if(v[i]->DajBrojIndeksa()==brind) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	}
	v.push_back(new StudentMaster(ime, prezime, brind, god));
}
void Fakultet::ObrisiStudenta(int brind){
	int i;
	for(i=0; i<v.size(); i++){
		if(v[i]->DajBrojIndeksa()==brind){
			delete v[i];
			v.erase(v.begin()+i);
			break;
		}
	}
	if(i==v.size()) throw std::logic_error ("Student sa zadanim brojem indeksa ne postoji");
}
ApstraktniStudent& Fakultet::operator [](int brind){
	int i;
	for(i=0; i<v.size(); i++){
		if(v[i]->DajBrojIndeksa()==brind) break;
	}
	if(i==v.size()) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	return *v[i];
} 
ApstraktniStudent& Fakultet::operator [](int brind) const{
	for(int i=0; i<v.size(); i++){
		if(v[i]->DajBrojIndeksa()==brind) return *(v[i]);
	};
} 
void Fakultet::IspisiSveStudente() const{
	Fakultet f(*this);
	std::sort(f.v.begin(), f.v.end(), [](ApstraktniStudent* s1, ApstraktniStudent* s2){
		if(s1->DajProsjek()==s2->DajProsjek()){
			return s1->DajBrojIndeksa()<s2->DajBrojIndeksa();
		}
		return s1->DajProsjek()>s2->DajProsjek();
	});
	for(int i=0; i<f.v.size(); i++){
		f.v[i]->IspisiPodatke();
	}
}
using std::cin;
using std::cout;
int main ()
{
	Fakultet f1;
	std::cout << "Koliko zelite unijeti bachelor studenata?";
	int n;
	std::cin >>n;
	cin.ignore(10000, '\n');
	for(int i=0; i<n; i++){
		cout << "Student " << i+1 << ":";
		string ime, prezime;
		int brind;
		std::getline(cin, ime);
		cin.ignore(10000, '\n');
		std::getline(cin, prezime);
		cin >> brind;
		cin.ignore(10000, '\n');
		f1.UpisiStudenta(ime, prezime, brind);
	}
	std::cout << "Koliko zelite unijeti master studenata?";
	std::cin >>n;
	cin.ignore(10000, '\n');
	for(int i=0; i<n; i++){
		cout << "Student " << i+1 << ":";
		string ime, prezime;
		int brind, god;
		std::getline(cin, ime);
		cin.ignore(10000, '\n');
		std::getline(cin, prezime);
		cin.ignore(10000, '\n');
		cin>> brind >> god;
		f1.UpisiStudenta(ime, prezime, brind, god);
	}
	f1.IspisiSveStudente();
	return 0;
}


