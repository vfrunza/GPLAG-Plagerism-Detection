/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <stdexcept>

using std::string;
using std::vector;
using std::shared_ptr;

//Da li atributi smiju biti protected?
//Zasto se ne moze u init_listi inicijalizirati protected attr bazne klase?
//Da li DajKopiju treba da vraca raw pointer ili smart pointer?
//Da li trebaju pomijerajuci konstr. i operator dodjele?

//Note: zato sto nisi deklarisao virutalni desktruktor u baznoj klasi "Spremnik", nije se pozvao odg destruktor
//      u klasi "Sanduk", koji je trebao pozvati destruktor vektora "tezine" koji je trebao dealocirati double-ove,
//      zato je postojalo curenje memorije

class Spremnik{
protected:
    double tezina;
    string sadrzaj;
public:
    //Abstract methods
    double DajTezinu() const { return tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
    virtual ~Spremnik(){};
};

class Sanduk : public Spremnik{
    vector<double> tezine_predmeta;
public:
    Sanduk(double tezina, string predmet, const vector<double> &tezine);
    double DajUkupnuTezinu() const;
    void Ispisi() const;
    Spremnik* DajKopiju() const { return new Sanduk(tezina, sadrzaj, tezine_predmeta); }
};

class Vreca : public Spremnik{
    double tezina_materije;
public:
    Vreca(double tezina, string materija, double tezina_materije);
    double DajUkupnuTezinu() const;
    void Ispisi() const;
    Spremnik* DajKopiju() const { return new Vreca(tezina, sadrzaj, tezina_materije); }
};

class Bure : public Spremnik{
    double gustina_tecnosti;
    double zapremina_tecnosti;
    double DajTezinuTecnosti() const;
public:
    Bure(double tezina, string tecnost, double gustoca, double zapremina);
    double DajUkupnuTezinu() const;
    void Ispisi() const;
    Spremnik* DajKopiju() const { return new Bure(tezina, sadrzaj, gustina_tecnosti, zapremina_tecnosti); }
};

class PolimorfniSpremnik{
    Spremnik* spremnik;
    void CheckObject() const {
        if(!spremnik)
            throw std::logic_error("Nespecificiran spremnik");
    }
public:
    PolimorfniSpremnik() : spremnik(nullptr) {}
    PolimorfniSpremnik(const Spremnik &s);
    PolimorfniSpremnik(const PolimorfniSpremnik &s);
    PolimorfniSpremnik(PolimorfniSpremnik &&s);
    ~PolimorfniSpremnik() { delete spremnik; }
    
    PolimorfniSpremnik& operator =(const PolimorfniSpremnik &s);
    PolimorfniSpremnik& operator =(PolimorfniSpremnik &&s);
    
    double DajTezinu() const;
    double DajUkupnuTezinu() const;
    void Ispisi() const;
};

int main (){
    std::cout << "Oke";
	return 0;
}

//***Implentation of class Sanduk***
Sanduk::Sanduk(double tezina, string predmet, const vector<double> &tezine) : tezine_predmeta(tezine){
    Spremnik::tezina = tezina;
    Spremnik::sadrzaj = predmet;
}

double Sanduk::DajUkupnuTezinu() const{
    double t = 0;
    for(double d : tezine_predmeta)
        t += d;
    return Spremnik::tezina + t;
}

void Sanduk::Ispisi() const{
    std::cout << "Vrsta spremnika: Sanduk" << std::endl
            << "Sadrzaj: " << sadrzaj << std::endl
            << "Tezine predmeta: ";
    
    for(double d : tezine_predmeta)
        std::cout << d << " ";
    
    std::cout << "(kg)" << std::endl
            << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl
            << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

//***Implentation of class Vreca***
Vreca::Vreca(double tezina, string materija, double tezina_materije){
    Spremnik::tezina = tezina;
    Spremnik::sadrzaj = materija;
    Vreca::tezina_materije = tezina_materije;
}

double Vreca::DajUkupnuTezinu() const{
    return Spremnik::tezina + tezina_materije;
}

void Vreca::Ispisi() const{
    std::cout << "Vrsta spremnika: Vreca" << std::endl
            << "Sadrzaj: " << sadrzaj << std::endl
            << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl
            << "Tezina pohranjene materije: " << tezina_materije << " (kg)" << std::endl
            << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

//***Implentation of class Bure***
Bure::Bure(double tezina, string tecnost, double gustoca, double zapremina){
    Spremnik::tezina = tezina;
    Spremnik::sadrzaj = tecnost;
    gustina_tecnosti = gustoca;
    zapremina_tecnosti = zapremina;
}

double Bure::DajUkupnuTezinu() const{
    return Spremnik::tezina + DajTezinuTecnosti();
}

void Bure::Ispisi() const{
    std::cout << "Vrsta spremnika: Bure" << std::endl
            << "Sadrzaj: " << sadrzaj << std::endl
            << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl
            << "Specificna tezina tecnosti: " << gustina_tecnosti << " (kg/m^3)" << std::endl
            << "Zapremina tecnosti: " << zapremina_tecnosti << " (l)" << std::endl
            << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}

double Bure::DajTezinuTecnosti() const {
    return gustina_tecnosti * zapremina_tecnosti / 1000;
}

//***Implentation of class PolimorfniSpremnik***
PolimorfniSpremnik::PolimorfniSpremnik(const Spremnik &s) : spremnik(s.DajKopiju()) {}

PolimorfniSpremnik::PolimorfniSpremnik(const PolimorfniSpremnik &s) : spremnik(nullptr) {
    if(s.spremnik)
        spremnik = s.spremnik->DajKopiju();
}

PolimorfniSpremnik::PolimorfniSpremnik(PolimorfniSpremnik &&s){
    spremnik = s.spremnik;
    s.spremnik = nullptr;
}

PolimorfniSpremnik& PolimorfniSpremnik::operator =(const PolimorfniSpremnik &s){
    if(&s == this) return *this;
    
    delete spremnik;
    spremnik = nullptr;
    if(s.spremnik) spremnik = s.spremnik->DajKopiju();
    
    return *this;
}

PolimorfniSpremnik& PolimorfniSpremnik::operator =(PolimorfniSpremnik &&s){
    if(&s == this) return *this;
    
    spremnik = s.spremnik;
    s.spremnik = nullptr;
    
    return *this;
}

double PolimorfniSpremnik::DajTezinu() const {
    CheckObject(); 
    return spremnik->DajTezinu();
}

double PolimorfniSpremnik::DajUkupnuTezinu() const {
    CheckObject();
    return spremnik->DajUkupnuTezinu();
}

void PolimorfniSpremnik::Ispisi() const {
    CheckObject();
    spremnik->Ispisi();
}
