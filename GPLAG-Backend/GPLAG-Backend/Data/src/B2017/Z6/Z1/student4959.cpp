/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>
class Spremnik {
    protected:
    double tezina;
    std::string naziv;
    
    public:
    Spremnik(double t, std::string s): tezina(t), naziv(s){}
    double DajTezinu() const { return tezina; }
    std::string DajNaziv() const { return naziv; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
};

class Sanduk : public Spremnik {
    std::vector<double> tezina_predmeta;
    public:
    Sanduk(double t, std::string s, std::vector<double> v): Spremnik(t,s), tezina_predmeta(v){}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
};
void Sanduk::Ispisi() const {
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
    std::cout<<"Sadrzaj: "<<naziv<<std::endl;
    std::cout<<"Tezine predmeta: ";
    for(auto x : tezina_predmeta)std::cout<<x<<" ";
    std::cout<<"(kg)"<<std::endl;
    std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}
double Sanduk::DajUkupnuTezinu() const {
    double suma(0);
    for(int i(0);i<tezina_predmeta.size();i++)
        suma+=tezina_predmeta.at(i);
    return suma + DajTezinu();    
}

class Vreca : public Spremnik {
    double tezina_materije;
    public:
    Vreca(double t, std::string s, double v): Spremnik(t,s), tezina_materije(v){}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;

};
double Vreca::DajUkupnuTezinu() const {
    return tezina_materije + tezina;
}
void Vreca::Ispisi() const {
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
    std::cout<<"Sadrzaj: "<<naziv<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
    std::cout<<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}


class Bure : public Spremnik {
    double ro;
    double V;
    public : 
    Bure(double t, std::string s, double r, double v): Spremnik(t,s), ro(r), V(v){}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
};
double Bure::DajUkupnuTezinu() const {
    return ro*V/1000 + tezina;
}
void Bure::Ispisi() const {
    std::cout<<"Vrsta spremnika: Bure"<<std::endl;
    std::cout<<"Sadrzaj: "<<naziv<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<std::endl;
    std::cout<<"Specificna tezina tecnosti: "<<ro<<" (kg/m^3)"<<std::endl;
    std::cout<<"Zapremina tecnosti: "<<V<<" (l)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<std::endl;
    
}

class Skladiste {
    
    std::vector<std::shared_ptr<Spremnik>> roba;
    
    public :
    
    Skladiste() {};
    Skladiste(const Skladiste &s);
    Skladiste(Skladiste &&s);
    Skladiste &operator = (const Skladiste &s);
    Skladiste &operator = (Skladiste &&s);
    
    Spremnik *DodajSanduk(double t, std::string s, std::vector<double> v);
    Spremnik *DodajVrecu(double t, std::string s, double v);
    Spremnik *DodajBure(double t,std::string, double r, double v);
    
};

Spremnik *Skladiste::DodajBure(double t, std::string s, double r, double v){
    roba.push_back(std::make_shared<Bure>(Bure(t,s,r,v)));
    return &*roba.at(roba.size()-1);
}
Spremnik *Skladiste::DodajVrecu(double t, std::string s, double v){
    roba.push_back(std::make_shared<Vreca>(Vreca(t,s,v)));
    return &*roba.at(roba.size()-1);
}
Spremnik *Skladiste::DodajSanduk(double t, std::string s, std::vector<double> v){
    roba.push_back(std::make_shared<Sanduk>(Sanduk(t,s,v)));
    return &*roba.at(roba.size()-1);
}
Skladiste::Skladiste(const Skladiste &s){
    
}
Skladiste::Skladiste(Skladiste &&s):roba(s.roba){}

Skladiste &Skladiste::operator = (const Skladiste &s){
    return *this;
} 
Skladiste &Skladiste::operator =(Skladiste &&s){
    return *this;
}


int main ()
{
    
	return 0;
}
