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

class Skladiste{
    vector<shared_ptr<Spremnik>> spremnici;
    
    void JelRazmak(std::ifstream &file);
public:
    Skladiste() {};
    Skladiste(const Skladiste &s);
    Skladiste& operator =(const Skladiste &s);
    
    Spremnik* DodajSanduk(double tezina, string predmet, const vector<double> &tezine);
    Spremnik* DodajVrecu(double tezina, string materija, double tezina_materije);
    Spremnik* DodajBure(double tezina, string tecnost, double gustoca, double zapremina);
    Spremnik* DodajSpremnik(Spremnik* novi, bool dinamicki);
    void BrisiSpremnik(Spremnik* toDel);
    Spremnik& DajNajlaksi();
    Spremnik& DajNajtezi();
    int BrojPreteskih(int tezina) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(string filename);
};

int main (){
    try{
        Skladiste etf;
        etf.UcitajIzDatoteke("ROBA.TXT");
        etf.IzlistajSkladiste();
    }
    catch(std::exception &err){
        std::cout << err.what();
    }
    
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

//***Implentation of class Skladiste***
Skladiste::Skladiste(const Skladiste &s){
    spremnici.resize(s.spremnici.size(), nullptr);
    for(int i = 0; i < spremnici.size(); i++)
        spremnici[i] = shared_ptr<Spremnik>(s.spremnici[i]->DajKopiju());
}

Skladiste& Skladiste::operator =(const Skladiste &s){
    if(&s == this) return *this;
    
    spremnici.clear();
    spremnici.resize(s.spremnici.size(), nullptr);
    for(int i = 0; i < spremnici.size(); i++)
        spremnici[i] = shared_ptr<Spremnik>(s.spremnici[i]->DajKopiju());
    
    return *this;
}

Spremnik* Skladiste::DodajSanduk(double tezina, string predmet, const vector<double> &tezine){
    Spremnik* spr = new Sanduk(tezina, predmet, tezine);
    spremnici.emplace_back(spr);
    return spr;
}

Spremnik* Skladiste::DodajVrecu(double tezina, string materija, double tezina_materije){
    Spremnik* spr = new Vreca(tezina, materija, tezina_materije);
    spremnici.emplace_back(spr);
    return spr;
}

Spremnik* Skladiste::DodajBure(double tezina, string tecnost, double gustoca, double zapremina){
    Spremnik* spr = new Bure(tezina, tecnost, gustoca, zapremina);
    spremnici.emplace_back(spr);
    return spr;
}

Spremnik* Skladiste::DodajSpremnik(Spremnik* novi, bool dinamicki){
    Spremnik* spr = nullptr;
    if(dinamicki)
        spr = novi;
    else
        spr = novi->DajKopiju();
    
    spremnici.emplace_back(spr);
    return spr;
}

void Skladiste::BrisiSpremnik(Spremnik* toDel){
    for(int i = 0; i < spremnici.size(); i++)
        if(spremnici[i].get() == toDel){
            spremnici.erase(spremnici.begin()+i);
            break;
        }
}

Spremnik& Skladiste::DajNajlaksi(){
    if(spremnici.empty())
        throw std::range_error("Skladiste je prazno");
    
    return **std::min_element(spremnici.begin(), spremnici.end(), [](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2){
        return s1->DajTezinu() < s2->DajTezinu();
    });
}

Spremnik& Skladiste::DajNajtezi(){
    if(spremnici.empty()) 
        throw std::range_error("Skladiste je prazno");
    
    return **std::max_element(spremnici.begin(), spremnici.end(), [](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2){
        return s1->DajTezinu() < s2->DajTezinu();
    });
}

int Skladiste::BrojPreteskih(int tezina) const {
    return std::count_if(spremnici.begin(), spremnici.end(), [&tezina](shared_ptr<Spremnik> s){
        return s->DajUkupnuTezinu() > tezina;
    });
}

void Skladiste::IzlistajSkladiste() const {
    vector<shared_ptr<Spremnik>> temp = spremnici;
    
    std::sort(temp.begin(), temp.end(), [](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2){
        return s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu();
    });
    
    for(shared_ptr<Spremnik> s : temp)
        s->Ispisi();
}

void Skladiste::JelRazmak(std::ifstream &file){
    //Jedan razmak
    char znak = file.get();
    if(znak != ' ' || (znak == ' ' && file.peek() == ' ')) file.setstate(std::ios::failbit);
}

void Skladiste::UcitajIzDatoteke(string filename){
    std::ifstream file(filename);
    if(!file)
        throw std::logic_error("Trazena datoteka ne postoji");
    
    //Postoji datoteka, cisti skladiste
    spremnici.clear();
    
    //temp vars
    char tip, znak;
    
    while(file >> tip){
        if(tip != 'S' && tip != 'V' && tip != 'B'){
            file.setstate(std::ios::failbit);
            break;
        }
        
        //Jedan razmak
        JelRazmak(file);
        
        //Common vars
        string sadrzaj;
        double tezina;
        
        //Ucitaj naziv do '\n', '\n' se brise
        getline(file, sadrzaj);
        
        //Mora biti broj
        znak = file.peek();
        if(znak < '0' || znak > '9') file.setstate(std::ios::failbit);
        
        //Unosi se tezina
        file >> tezina;
        
        //Jedan razmak
        JelRazmak(file);
        
        if(!file) break;
        
        //U slucaju sanduka
        if(tip == 'S'){
            int size, i;
            vector<double> vec;
            
            //Velicina niza
            file >> size;
            vec.resize(size);
            
            //Unos tezina
            i = 0;
            while(file && i < size){
                //Jedan razmak
                JelRazmak(file);
                
                //Jedna od tezina
                file >> vec[i];
                
                i++;
            }
            
            //Ako je file u ispravnom stanju, znaci da je unos do sada prosao, stvori novi sanduk
            if(file)
                DodajSanduk(tezina, sadrzaj, vec);
            
        }else if(tip == 'V'){
            //Tezina materije
            double tezina_materije;
            file >> tezina_materije;
            
            if(file)
                DodajVrecu(tezina, sadrzaj, tezina_materije);
        }else if(tip == 'B'){
            //Tezina materije
            double gustoca, zapremina;
            file >> gustoca;
            JelRazmak(file);
            file >> zapremina;
            
            if(file)
                DodajBure(tezina, sadrzaj, gustoca, zapremina);
        }
        
        //Ako znak nije novi red, format nije valjan. Svaki drugi element u novom redu...
        znak = file.peek();
        if(znak != '\n') file.setstate(std::ios::failbit);
        znak = file.get();
    }
    
    file.close();
    
    if(file.eof()){
        //kraj datoteke
    }
    else if(file.bad()){
        throw std::logic_error("Problemi pri citanju iz datoteke");
    }
    else if(!file){
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
}