#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

/*
class ApstraktniStudent
{
	std::string ime, prezime;
	int brindeksa, brpolozenih;
	double prosjecna;

public:
	ApstraktniStudent(std::string ime, std::string prezime, int brindeksa): ime(ime), prezime(prezime), brindeksa(brindeksa), brpolozenih(0), prosjecna(5) {};
	std::string DajIme() const
	{
		return ime;
	}
	std::string DajPrezime() const
	{
		return prezime;
	}
	int DajBrojIndeksa() const
	{
		return brindeksa;
	}
	
	int DajBrojPolozenih() const
	{
		return brpolozenih;
	}
	
	double DajProsjek() const
	{
		return prosjecna;
	}
	void RegistrirajIspit( int oc)
	{
		if(oc<5 || oc>10) throw

			std::domain_error("Neispravna ocjena");
		if(oc!=5) {
			prosjecna=(prosjecna*brpolozenih+oc)/(brpolozenih+1);
			brpolozenih++;
		}
	}

	void PonistiOcjene()
	{
		brpolozenih=0;
		prosjecna=5;
	}

	virtual void  IspisiPodatke() const=0;
	virtual ApstraktniStudent *DajKopiju() const=0;
	virtual ~ApstraktniStudent() {};
};

class StudentBachelor: public ApstraktniStudent
{
public:
	StudentBachelor(std::string ime, std::string prezime, int brindeksa): ApstraktniStudent(ime, prezime, brindeksa) {};
	void IspisiPodatke() const override
	{
		std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl;
	}

	ApstraktniStudent *DajKopiju() const override
	{
		return new StudentBachelor(*this);
	}
};

class StudentMaster: public ApstraktniStudent
{
	int godina;
public:
	StudentMaster(std::string ime, std::string prezime, int brindeksa, int godina): ApstraktniStudent(ime, prezime, brindeksa), godina(godina) {};
	void IspisiPodatke() const override
	{
		std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "<<godina<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
	}

	ApstraktniStudent *DajKopiju () const override
	{
		return new StudentMaster(*this);
	}
};



class Fakultet
{
	std::vector<ApstraktniStudent*> v;
	public:
	
	explicit Fakultet(): v(0){};
	~Fakultet();
	Fakultet(const Fakultet &f);
	Fakultet &operator=(const Fakultet &f);
	Fakultet(Fakultet &&f);
	Fakultet &operator=(Fakultet &&f);
	void UpisiStudenta(std::string ime, std::string prezime, int brindeksa);
void UpisiStudenta(std::string ime, std::string prezime, int brindeksa, int godina);

void ObrisiStudenta(int indeks):
ApstraktniStudent &operator [](int brindeksa);
ApstraktniStudent const &operator[](int brindeksa) const;

void IspisiSveStudente() const;
};

void Fakultet::IspisiSveStudente() const
{
	auto v(this->v)
	std::sort(v.begin(), v.end(), [](ApstraktniStudent*s1, ApstraktniStudent*s2){
		if(s1->DajProsjek()==s2->DajProsjek())
		return s1->DajBrojIndeksa()<s2->DajProsjek();});
		for(auto x:v) x->IspisiPodatke();
}
ApstraktniStudent &Fakultet::operator[](int brindeksa)
{
	bool ima(false);
	for(int i=0; i < v.size(); i++){
		if(v[i]->DajBrojIndeksa()==brindeksa){
			ima=true;
			return *v[i];
		}
	}
	if(!ima) throw std::logic_error("Student sa zadatim brojem indeksa ne postoje");
	return *v[0];
}

ApstraktniStudent const &Fakultet::operator[](int brindeksa) const

{
	bool ima(false);
	for(i=0; i < v.size();i++){
		if(v[i]->DajBrojIndeksa()==brindeksa{
			ima=true;
			
			return *v[i];
		}
	}
	if(!ima) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	return *v[0];
}

void Fakultet:: UpisiStudenta(std::string ime, std::string prezime, int brindeksa)
{
	for(auto x: v) if(x -> DajBrojIndeksa()==brindeksa)
	throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	v.push_back(new StudentBachelor( ime, prezime, brindeksa));
}

void Fakultet:: UpisiStudenta(std::string ime, std::string prezime, int brindeksa)
{
	for(auto x: v) if(x -> DajBrojIndeksa()==brindeksa)
	throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
	v.push_back(new StudentBachelor( ime, prezime, brindeksa, int godina));
}

void Fakultet::ObrisiStudenta(int indeks)
{
	bool ima(false);
	for(int i =0; i< v.size(); i++){
		if(v[i]->DajBrojIndeksa()==indeks){
			ima=true;
			delete v[i];
			v.erase(v.begin+i);
			break;
		}
		
		if(!ima) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	
	Fakultet::~Fakultet()
	{
		for(int i=0; i < v.size(); i++) delete v[i];
	}
	
	
	Fakultet::Fakultet(const Fakultet &f)
	{
		for(int i = 0; i < v.size(); i++) delete v[i];
		
		v.resize(0);
		try{
			for(auto x: f.v) v.push_back(x->DajKopiju());
		} catch(...){
			for(auto x: v) delete x;
		}
		return *this;
	}
	
	Fakultet &Fakultet::operator ==(Fakultet &&f)
	{
		for(int i = 0; i < v.size(); i++) delete v[i];
		v=std::move(f.v);
		return *this;
	}


*/
	
	
	#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
 
class ApstraktniStudent
{
    std::string ime,prezime;
    int brindeksa,brpolozenih;
    double prosjecna;
public:
    ApstraktniStudent(std::string ime,std::string prezime,int brindeksa): ime(ime),prezime(prezime),brindeksa(brindeksa),brpolozenih(0),prosjecna(5) {};
    std::string DajIme() const {
        return ime;
    }
    std::string DajPrezime() const {
        return prezime;
    }
    int DajBrojIndeksa() const {
        return brindeksa;
    }
    int DajBrojPolozenih() const {
        return brpolozenih;
    }
    double DajProsjek() const {
        return prosjecna;
    }
    void RegistrirajIspit(int oc) {
        if(oc<5 || oc>10) throw std::domain_error("Neispravna ocjena");
        if(oc!=5) {
            prosjecna=(prosjecna*brpolozenih+oc)/(brpolozenih+1);
            brpolozenih++;
        }
    }
    void PonistiOcjene() {
        brpolozenih=0;
        prosjecna=5;
    }
    virtual void IspisiPodatke() const=0;
    virtual ApstraktniStudent *DajKopiju() const=0;
    virtual ~ApstraktniStudent() {};
};
 
class StudentBachelor: public ApstraktniStudent
{
public:
    StudentBachelor(std::string ime,std::string prezime,int brindeksa): ApstraktniStudent(ime,prezime,brindeksa) {};
    void IspisiPodatke() const override {
        std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl;
    }
    ApstraktniStudent *DajKopiju() const override {
        return new StudentBachelor(*this);
    }
//  ~StudentBachelor(){ delete this;}
};
 
class StudentMaster: public ApstraktniStudent
{
    int godina;
public:
    StudentMaster(std::string ime,std::string prezime,int brindeksa,int godina): ApstraktniStudent(ime,prezime,brindeksa), godina(godina) {};
    void IspisiPodatke() const override {
        std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "<<godina<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
    }
    ApstraktniStudent *DajKopiju() const override {
        return new StudentMaster(*this);
    }
    //~StudentMaster(){ delete this;}
};
 
class Fakultet
{
    std::vector<ApstraktniStudent*> v;
public:
    explicit Fakultet() : v(0) {};
    ~Fakultet();
    Fakultet(const Fakultet &f);
    Fakultet &operator=(const Fakultet &f);
    Fakultet(Fakultet &&f);
    Fakultet &operator=(Fakultet &&f);
    void UpisiStudenta(std::string ime, std::string prezime,int brindeksa);
    void UpisiStudenta(std::string ime, std::string prezime,int brindeksa, int godina);
    void ObrisiStudenta(int indeks);
    ApstraktniStudent &operator [](int brindeksa);
    ApstraktniStudent const &operator [](int brindeksa) const;
    void IspisiSveStudente() const;
 
};
 
void Fakultet::IspisiSveStudente() const
{
 
    auto v(this->v);
   
        std::sort(v.begin(),v.end(),[](ApstraktniStudent*s1, ApstraktniStudent*s2){
            if(s1->DajProsjek()==s2->DajProsjek()) return s1->DajBrojIndeksa()<s2->DajBrojIndeksa();
            return s1->DajProsjek()>s2->DajProsjek();
        });
    for(auto x: v) x->IspisiPodatke();
   
}
 
ApstraktniStudent &Fakultet::operator [](int brindeksa) //->decltype(*(this->v[0]))
{
    bool ima(false);
    for(int i(0); i<v.size(); i++) {
        if(v[i]->DajBrojIndeksa()==brindeksa) {
            ima=true;
            return *v[i];
        }
    }
    if(!ima) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
    return *v[0];
}
 
ApstraktniStudent const &Fakultet::operator [](int brindeksa) const //->decltype(*(this->v[0]))
{
    bool ima(false);
    for(int i(0); i<v.size(); i++) {
        if(v[i]->DajBrojIndeksa()==brindeksa) {
            ima=true;
            return *v[i];
        }
    }
    if(!ima) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
    return *v[0];
}
 
void Fakultet:: UpisiStudenta(std::string ime, std::string prezime,int brindeksa)
{
    for(auto x : v) if(x->DajBrojIndeksa()==brindeksa) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
    v.push_back(new StudentBachelor(ime,prezime,brindeksa));
}
 
void Fakultet::UpisiStudenta(std::string ime, std::string prezime,int brindeksa,int godina)
{
    for(auto x : v) if(x->DajBrojIndeksa()==brindeksa) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
    v.push_back(new StudentMaster(ime,prezime,brindeksa,godina));
}
 
void Fakultet::ObrisiStudenta(int indeks)
{
    bool ima(false);
    for(int i(0); i<v.size(); i++) {
        if(v[i]->DajBrojIndeksa()==indeks) {
            ima=true;
            delete v[i];
            v.erase(v.begin()+i);
            break;
        }
    }
    if(!ima) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
}
 
Fakultet::~Fakultet()
{
    for(int i(0);i<v.size();i++) delete v[i];
}
 
Fakultet::Fakultet(const Fakultet &f)
{
    for(int i(0);i<v.size();i++) delete v[i];
    v.resize(0);
    try {
        for(auto x: f.v) v.push_back(x->DajKopiju());
    } catch(...) {
        for(auto x: v) delete x;
    }
}
 
Fakultet &Fakultet::operator=(const Fakultet &f)
{
    for(int i(0);i<v.size();i++) delete v[i];
    v.resize(0);
    try {
        for(auto x: f.v) v.push_back(x->DajKopiju());
    } catch(...) {
        for(auto x: v) delete x;
    }
    return *this;
}
 
Fakultet::Fakultet(Fakultet &&f)
{
    v=std::move(f.v);
}
 
Fakultet &Fakultet::operator=(Fakultet &&f)
{
    for(int i(0);i<v.size();i++) delete v[i];
    v=std::move(f.v);
    return *this;
}
 
 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


