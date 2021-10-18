/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>

class Spremnik {
    protected:
    double tezina;
    std::string sadrzaj;
    public:
    double DajTezinu() const {return tezina;}
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    Spremnik(double tezina, std::string sadrzaj) : tezina(tezina), sadrzaj(sadrzaj) {}
    virtual Spremnik *DajKopiju() const = 0;
};

class Sanduk : public Spremnik {
    std::vector<double> predmeti;
    public:
    Sanduk(double tezina, std::string sadrzaj, std::vector<double> v) : 
    Spremnik(tezina,sadrzaj) {predmeti=v;}
    double DajUkupnuTezinu() const override {
        double ukupno(0);
        for(int i=0; i<predmeti.size(); i++) ukupno+=predmeti[i];
        return ukupno+DajTezinu();
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<sadrzaj<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(int i=0; i<predmeti.size(); i++) std::cout<<predmeti[i]<<" ";
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Spremnik *DajKopiju() const override { return new Sanduk(*this); }
};
class Vreca : public Spremnik {
    double tezina_materije;
    public:
    Vreca(double tezina, std::string sadrzaj, double tezina_materije) : 
    Spremnik(tezina, sadrzaj), tezina_materije(tezina_materije) {}
    double DajUkupnuTezinu() const override {return tezina_materije+DajTezinu();}
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<sadrzaj<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Spremnik *DajKopiju() const override { return new Vreca(*this);}
};
class Bure : public Spremnik {
    double gustina;
    double zapremina;
    public:
    Bure(double tezina, std::string sadrzaj, double gustina, double zapremina) :
    Spremnik(tezina, sadrzaj), gustina(gustina), zapremina(zapremina) {}
    double DajUkupnuTezinu() const override {return gustina*zapremina*0.001 + DajTezinu();}
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<sadrzaj<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Spremnik *DajKopiju() const override { return new Bure(*this);}
};


class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> proizvodi;
    public:
    Skladiste() {}
    Skladiste(const Skladiste &s) {
        proizvodi.resize(s.proizvodi.size());
        try {
            for(int i=0; i<s.proizvodi.size(); i++)
            proizvodi[i]=std::shared_ptr<Spremnik>(s.proizvodi[i]->DajKopiju());
        }
        catch(...) {
            proizvodi.resize(0);
            throw;
        }
    }
    Skladiste &operator = (const Skladiste &s) {
        for(int i=0; i<proizvodi.size(); i++) proizvodi[i]=nullptr;
        proizvodi.resize(s.proizvodi.size());
        try {
            for(int i=0; i<proizvodi.size(); i++)
            proizvodi[i]=std::shared_ptr<Spremnik>(s.proizvodi[i]->DajKopiju());
        }
        catch(...) {
            proizvodi.resize(0);
            throw;
        }
        return *this;
    }
    Skladiste(Skladiste &&s) {
        proizvodi=s.proizvodi;
        for(int i=0; i<s.proizvodi.size(); i++)
        s.proizvodi[i]=nullptr;
        s.proizvodi.resize(0);
    }
    Skladiste &operator =(Skladiste &&s) {
        std::swap(proizvodi, s.proizvodi);
        return *this;
    }
    Spremnik *DodajSanduk(double tezina, std::string sadrzaj, std::vector<double> v) {
        Spremnik *p = new Sanduk(tezina,sadrzaj,v);
        proizvodi.push_back(std::shared_ptr<Spremnik>(p));
        return p;
    }
    Spremnik *DodajVrecu(double tezina, std::string sadrzaj, double tezina_materije) {
        Spremnik *p = new Vreca(tezina,sadrzaj,tezina_materije);
        proizvodi.push_back(std::shared_ptr<Spremnik>(p));
        return p;
    }
    Spremnik *DodajBure(double tezina, std::string sadrzaj, double gustina, double zapremina) {
        Spremnik *p = new Bure(tezina,sadrzaj,gustina,zapremina);
        proizvodi.push_back(std::shared_ptr<Spremnik>(p));
        return p;
    }
   Spremnik *DodajSpremnik(Spremnik *p, bool vlasnik) {
        if(vlasnik) {
            proizvodi.push_back(std::make_shared<Spremnik>(*p));
            return p;
        }
        else {
            Spremnik *novi = p->DajKopiju();
            proizvodi.push_back(std::shared_ptr<Spremnik>(novi));
            return novi;
        }
    }
    void BrisiSpremnik(Spremnik *s) {
        for(auto it(proizvodi.begin()); it!=proizvodi.end(); it++) {
            if(std::shared_ptr<Spremnik>(s)==*it) proizvodi.erase(it);
        }
    }
    Spremnik &DajNajlaksi() {
        if(proizvodi.size()==0) throw std::range_error("Skladiste je prazno");
        double min(0);
        for(int i=0; i<proizvodi.size(); i++) {
            if(proizvodi[i]->DajTezinu()<min) min=proizvodi[i]->DajTezinu();
        }
        for(int i=0; i<proizvodi.size(); i++) {
            if(min==proizvodi[i]->DajTezinu()) return *(proizvodi[i]);
        }
    }
    Spremnik &DajNajtezi() {
        if(proizvodi.size()==0) throw std::range_error("Skladiste je prazno");
        double max(0);
        for(int i=0; i<proizvodi.size(); i++) {
            if(proizvodi[i]->DajTezinu()>max) max=proizvodi[i]->DajTezinu();
        }
        for(int i=0; i<proizvodi.size(); i++) {
            if(max==proizvodi[i]->DajTezinu()) return *(proizvodi[i]);
        }
    }
    int BrojPreteskih(int max) const {
        int brojac(0);
        for(int i=0; i<proizvodi.size(); i++) {
            if(proizvodi[i]->DajUkupnuTezinu()>max) brojac++;
        }
        return brojac;
        }
    int BrojPreteskih(int max) {
        int brojac(0); 
        for(int i=0; i<proizvodi.size(); i++) {
            if(proizvodi[i]->DajUkupnuTezinu()>max) brojac++;
        }
        return brojac;
    }
    void IzlistajSkladiste() const {
        //std::sort(proizvodi.begin(), proizvodi.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
        //    return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
        //});
        for(int i=0; i<proizvodi.size(); i++) proizvodi[i]->Ispisi();
    }
    void IzlistajSkladiste() {
        std::sort(proizvodi.begin(), proizvodi.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
            return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
        });
        for(int i=0; i<proizvodi.size(); i++) proizvodi[i]->Ispisi();
    }
    void UcitajIzDatoteke(const char ime_datoteke[]) {
        if(proizvodi.size()!=0) proizvodi.resize(0);
        std::ifstream ulazni_tok(ime_datoteke);
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        else {
            while(!ulazni_tok.eof()) {
            char slovo, znak;
            std::string s;
            while(ulazni_tok>>slovo>>znak>>s) {
                if(slovo=='S') {
                    double broj_1, broj_2;
                    std::vector<double> v;
                    while(ulazni_tok>>broj_1>>broj_2) {
                        v.resize(broj_2);
                        for(int i=0; i<broj_2; i++) {
                            ulazni_tok>>v[i];
                            if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
                            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
                        }
                    }
                    if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
                    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    proizvodi.push_back(std::shared_ptr<Spremnik>(new Sanduk(broj_1,s,v)));
                }
                else if(slovo=='V') {
                    double broj_1, broj_2;
                    while(ulazni_tok>>broj_1>>broj_2 && ulazni_tok.peek()=='\n') {
                        proizvodi.push_back(std::shared_ptr<Spremnik>(new Vreca(broj_1,s,broj_2)));
                    }
                    if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
                    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                else if(slovo=='B') {
                    double broj_1,broj_2,broj_3;
                    while(ulazni_tok>>broj_1>>broj_2>>broj_3 && ulazni_tok.peek()!='\n') {
                        proizvodi.push_back(std::shared_ptr<Spremnik>(new Bure(broj_1,s,broj_2,broj_3)));
                    }
                    if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
                    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                else throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        }
    }
};

int main ()
{
    /*Skladiste s;
    try {
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }
    catch(std::logic_error poruka) {
        std::cout<<poruka.what();
    }
    catch(...){
        return 0;
    }*/
    try
    {

        Skladiste ETF;
        ETF.DodajSanduk(50, "Voce", {1,3,5,6});
        ETF.DodajVrecu(0.1, "Brasno", 25.5);
        ETF.DodajBure(5, "Krv", 1300, 150);
        ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        Bure *b = new Bure(15, "Voda", 1000, 200);
        ETF.DodajSpremnik(b, false);
        delete b;
        ETF.DajNajlaksi().Ispisi();
        std::cout << ETF.BrojPreteskih(40) << std::endl;
        ETF.DajNajtezi().Ispisi();
    }
    catch(std::range_error re)
    {
        std::cout << re.what();
    }

    
    
	return 0;
}
