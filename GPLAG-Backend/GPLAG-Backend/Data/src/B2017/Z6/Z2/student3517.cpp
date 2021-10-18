/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>


class Spremnik {
    protected:
    double tezina;
    std::string naziv;
    public:
    friend class Skladiste;
    friend class PolimorfniSpremnik;
    virtual void Ispisi()const=0;
    virtual double DajTezinu() { return tezina; }
    virtual double DajUkupnuTezinu()const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju()const=0;
    virtual Spremnik* DajKopiju(int)const=0;
};




class Sanduk: public Spremnik{
    std::vector<double> tezina_stvari;
    public:
    
    Sanduk(double tez, std::string naz, std::vector<double> tezt) {
        tezina=tez;
        naziv=naz;
        tezina_stvari=tezt;
    }
    
    double DajUkupnuTezinu() const override {
        double suma=0;
        for(int i=0; i<tezina_stvari.size(); i++) {
            suma+=tezina_stvari[i];
        }
        return suma+tezina;
    }
    
    std::shared_ptr<Spremnik> DajKopiju()const  {
        return std::make_shared<Sanduk>(this-> tezina, this-> naziv, this-> tezina_stvari);
    }
    
    Spremnik* DajKopiju(int) const {
        return new Sanduk(this-> tezina, this-> naziv, this-> tezina_stvari);
    }
    
    void Ispisi() const override {
        int suma=0;
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        std::cout << "Sadrzaj: "<<naziv << std::endl;
        std::cout << "Tezine predmeta: ";
        for(int i=0;i<tezina_stvari.size();i++) std::cout << tezina_stvari[i]<<" ";
        std::cout << "(kg)" << std::endl;
        std::cout << "Vlastita tezina: "<<tezina <<" (kg)"<< std::endl;
        std::cout << "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)" << std::endl;
    }
};



class Vreca: public Spremnik {
    double tezina_materije;
    public:
    Vreca(double tez, std::string naz, double tezt) {
        tezina=tez;
        naziv=naz;
        tezina_materije=tezt;
    }
    
    double DajUkupnuTezinu() const override {
        return tezina_materije+tezina;
    }
    
    std::shared_ptr<Spremnik> DajKopiju() const {
        return std::make_shared<Vreca> (this-> tezina, this-> naziv, this-> tezina_materije);
    }
    
    Spremnik* DajKopiju(int) const {
        return new Vreca(this-> tezina, this-> naziv, this-> tezina_materije);
    }
    
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: " <<naziv<< std::endl;
        std::cout << "Vlastita tezina: "<<tezina<<" (kg)" << std::endl;
        std::cout << "Tezina pohranjene materije: "<<tezina_materije<<" (kg)" << std::endl;
        std::cout << "Ukupna tezina: "<<tezina+tezina_materije<<" (kg)" << std::endl;
    }
};


class Bure: public Spremnik {
    double specificna_gustina;
    double zapremina_tecnosti;
    public:
    Bure(double tez, std::string naz, double gustoca, double zapr) {
        tezina=tez;
        naziv=naz;
        specificna_gustina=gustoca;
        zapremina_tecnosti=zapr;
    }
    
    double DajUkupnuTezinu() const override {
        return tezina+(specificna_gustina*zapremina_tecnosti/1000);
    }
    
    std::shared_ptr<Spremnik> DajKopiju() const  {
        return std::make_shared<Bure> (this-> tezina, this-> naziv, this-> specificna_gustina, this-> zapremina_tecnosti);
    }
    
    Spremnik* DajKopiju(int) const {
        return new Bure(this-> tezina, this-> naziv, this-> specificna_gustina, this-> zapremina_tecnosti);
    }
    
    void Ispisi() const override {
        double t(specificna_gustina*zapremina_tecnosti/1000);
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: "<<naziv << std::endl;
        std::cout << "Vlastita tezina: "<<tezina<<" (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: "<<specificna_gustina<<" (kg/m^3)" << std::endl;
        std::cout << "Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)" << std::endl;
        std::cout << "Ukupna tezina: "<<tezina+t<<" (kg)" << std::endl;
    }
};



class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> v;
    public:
    Skladiste() {}
    Skladiste(const Skladiste &s) {
        for(int i=0;i<s.v.size();i++) {
            v.push_back(s.v[i]-> DajKopiju());
        }
}
void operator=(const Skladiste &s) {
    for(int i=0; i<s.v.size();i++) {
        v.push_back(s.v[i]-> DajKopiju());
    }
}

Spremnik* DodajSanduk(double tez, std::string naz, std::vector<double> tezt) {
    auto d=std::make_shared<Sanduk>(tez, naz, tezt);
    v.push_back(d);
    return d.get();
}


Spremnik* DodajVrecu(double tez, std::string naz, double tezt) {
    auto d=std::make_shared<Vreca>(tez, naz, tezt);
    v.push_back(d);
    return d.get();
}


Spremnik* DodajBure(double tez, std::string naz, double gustoca, double zapr) {
    auto d=std::make_shared<Bure>(tez, naz, gustoca, zapr);
    v.push_back(d);
    return d.get();
}


Spremnik* DodajSpremnik(Spremnik *p, bool a) {
    if(a) {
        auto d=p-> DajKopiju();
        v.push_back(d);
        delete p;
        return d.get();
    }
    
    else {
        auto d=p-> DajKopiju();
        v.push_back(d);
        return d.get();
    }
}


void BrisiSpremnik(Spremnik* p) {
    for(int i=0; i<v.size(); i++) {
        if(p==v[i].get()) {
            v.erase(v.begin()+i);
            break;
        }
    }
}


Spremnik &DajNajlaksi() {
    if(v.size()==0) throw std::range_error("Skladiste je prazno");
    int zapamti=0;
    for(int i=1; i<v.size();i++) {
        if(v[i]-> DajTezinu()< v[zapamti]-> DajTezinu()) zapamti=i;
    }
    return *(v[zapamti]);
}


Spremnik &DajNajtezi() {
    if(v.size()==0) throw std::range_error("Skladiste je prazno");
    int zapamti=0;
    for(int i=1; i<v.size();i++) {
        if(v[i]-> DajTezinu() > v[zapamti]-> DajTezinu()) zapamti=i;
    }
    return *(v[zapamti]);
}


int BrojPreteskih(int a) const {
    int zapamti=0;
    for(int i=0; i<v.size();i++) {
        if(v[i]-> DajTezinu() > a) zapamti+=1;
    }
    return zapamti;
}


void MeineFunction() {
    int min=0;
    for(int i=1; i<v.size(); i++) {
        if(v[i]-> DajUkupnuTezinu() > v[min]-> DajUkupnuTezinu()) min=i;
    }
    v[min]-> Ispisi();
    v.erase(v.begin()+min);
}

void IzlistajSkladiste() {
    Skladiste s2(*this);
    
    for(int i=0; i<s2.v.size();) {
        s2.MeineFunction(); 
    }
}


void UcitajIzDatoteke(std::string s) {
    v.resize(0);
    std::ifstream ulaz(s);
    if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
    char c;
    while(ulaz >> c) {
        char sses;
        sses=ulaz.get();
        std::string s;
        if(c=='B') {
            std::getline(ulaz, s);
            double a,b,c;
            ulaz >>a >>b>>c;
            
            v.push_back(std::make_shared<Bure>(a,s,b,c));
            continue;
        }
        
        if(c=='V') {
            std::getline(ulaz, s);
            double a,b;
            ulaz >>a >>b;
            v.push_back(std::make_shared<Vreca>(a,s,b));
            continue;
        }
        
        if(c=='S') {
            std::getline(ulaz, s);
            double a,b;
            std::vector<double> c;
            ulaz >>a >>b;
        for(int i=0; i<b ;i++) {
            double te;
            ulaz >> te;
            c.push_back(te);
        }
        v.push_back(std::make_shared<Sanduk>(a,s,c));
        continue;
        }
        break;
        
    }
    if(ulaz.eof()) std::cout << "";
    else if(ulaz.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
}
};

class PolimorfniSpremnik {
    std::shared_ptr<Spremnik> p;
    void Test() const {
        if(!p) throw std::logic_error("Nespecificiran spremnik");
    }
        public:
        
        PolimorfniSpremnik() { p=nullptr; }
        PolimorfniSpremnik(const Spremnik &s) {
            p=s.DajKopiju();
        
        }
        
        PolimorfniSpremnik &operator=(const PolimorfniSpremnik &s) {
            p=s.p->DajKopiju();
        }
        
        void Ispisi() {
            Test();
            p-> Ispisi();
        }
        
        double DajUkupnuTezinu() {
            Test();
            return p-> DajUkupnuTezinu();
        }
        
        double DajTezinu() {
            Test();
            return p->DajTezinu();
        }
    };

int main ()
{
    try
{

	PolimorfniSpremnik s1;
	std::cout << s1.DajTezinu() << std::endl;
}
catch(std::logic_error le)
{
	std::cout << le.what();
}
	return 0;
}
