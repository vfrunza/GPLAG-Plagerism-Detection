/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Spremnik {                                                                //apstraktna bazna klasa
    protected:
    double tezina;
    std::string sadrzaj;
    public:
    Spremnik (double tezina, std::string sadrzaj) : tezina(tezina),             //konstruktor
        sadrzaj(sadrzaj) {}
    virtual ~Spremnik() {}                                                      //virtual destruktor
    virtual double DajTezinu() const = 0;                                       //apstraktna metoda
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi () const = 0;
    virtual Spremnik *DajKopiju() const = 0;
};

class Sanduk : public Spremnik {
    std::vector<double> tezina_predmeta;
    public:
    Sanduk(double tezina, std::string sadrzaj, std::vector<double> tezina_predmeta) :
        Spremnik(tezina, sadrzaj), tezina_predmeta(tezina_predmeta) {}
    ~Sanduk () {}        
    double DajTezinu() const override { return tezina; }
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
    Spremnik *DajKopiju () const override { return new Sanduk(*this); }
};

double Sanduk::DajUkupnuTezinu() const {
    double rez(tezina);
    for(auto x: tezina_predmeta) rez+=x;
    return rez;
}

void Sanduk::Ispisi() const {
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl
        <<"Sadrzaj: "<<sadrzaj<<std::endl
        <<"Tezine predmeta: ";
    for(auto x: tezina_predmeta) std::cout<<x<<" ";
    std::cout<<"(kg)"<<std::endl
        <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
        <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Bure: public Spremnik {
    double gustina, zapremnina;
    public:
    Bure(double tezina, std::string sadrzaj, double gustina, double zapremnina) :
        Spremnik(tezina, sadrzaj), gustina(gustina), zapremnina(zapremnina) {}
    ~Bure () {}
    double DajTezinu() const override { return tezina; }
    double DajUkupnuTezinu() const override {
        return tezina+gustina*zapremnina/1000.;
    }
    Spremnik *DajKopiju() const override {
        return new Bure(*this);
    }
    void Ispisi() const;
};

void Bure::Ispisi() const {
    std::cout<<"Vrsta spremnika: Bure"<<std::endl
        <<"Sadrzaj: "<<sadrzaj<<std::endl
        <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
        <<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl
        <<"Zapremina tecnosti: "<<zapremnina<<" (l)"<<std::endl
        <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Vreca : public Spremnik {
    double tezina_materije;
    public:
    Vreca(double tezina, std::string sadrzaj, double tezina_materije) :
        Spremnik(tezina, sadrzaj), tezina_materije(tezina_materije) {}
    ~Vreca () {}
    double DajTezinu() const override { return tezina; }
    void Ispisi() const override;
    Spremnik *DajKopiju() const override { return new Vreca(*this); }
    double DajUkupnuTezinu() const override {
        return tezina+tezina_materije;
    }
};

void Vreca::Ispisi() const {
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl
        <<"Sadrzaj: "<<sadrzaj<<std::endl
        <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
        <<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<std::endl
        <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class PolimorfniSpremnik {                                                      //trazena surogatska klasa
    Spremnik *p_spremnik;
    void Test() const {
        if(!p_spremnik) throw std::logic_error("Nespecificiran spremnik");
    }
    public:
    PolimorfniSpremnik() : p_spremnik(nullptr) {}
    ~PolimorfniSpremnik() { delete p_spremnik; }
    PolimorfniSpremnik(const Spremnik &spremnik) :
        p_spremnik(spremnik.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &spremnik) {
        if(!spremnik.p_spremnik) p_spremnik=nullptr;
        else p_spremnik=spremnik.p_spremnik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&spremnik) {
        p_spremnik=spremnik.p_spremnik; spremnik.p_spremnik=nullptr;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &spremnik);
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&spremnik);
    double DajTezinu() const { 
        Test(); return p_spremnik->DajTezinu(); }
    double DajUkupnuTezinu() const {
        Test(); return p_spremnik->DajUkupnuTezinu();
    }
    void Ispisi() const { Test(); p_spremnik->Ispisi(); }
};

PolimorfniSpremnik &PolimorfniSpremnik::operator =(PolimorfniSpremnik &&spremnik) {
    std::swap(p_spremnik, spremnik.p_spremnik);
    return *this;
}

PolimorfniSpremnik &PolimorfniSpremnik::operator =(const PolimorfniSpremnik &spremnik) {
    Spremnik *p_novi(nullptr);
    if(spremnik.p_spremnik!=nullptr) p_novi=spremnik.p_spremnik->DajKopiju();
    delete p_spremnik;
    p_spremnik=p_novi;
    return *this;
}

int main ()
{
    try {
        //SANDUK
        std::cout<<"Unesite tezinu sanduka: ";
        int tezina_1;
        std::cin>>tezina_1;
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite sadrzaj sanduka: ";
        std::string sadrzaj;
        std::getline(std::cin, sadrzaj);
        std::cout<<"Unesite broj predmeta u sanduku: ";
        int broj_predmeta;
        std::cin>>broj_predmeta;
        std::vector<double> predmeti(broj_predmeta);
        for(int i=0; i<broj_predmeta; i++) {
            std::cout<<"Unesite tezinu "<<i+1<<". predmeta: ";
            std::cin>>predmeti[i];
        }
        PolimorfniSpremnik s(Sanduk(tezina_1, sadrzaj, predmeti));
        PolimorfniSpremnik s1, s2;
        s2=s;
        s2.Ispisi();
        //VRECA
        std::cout<<"Unesite tezinu vrece: ";
        std::cin>>tezina_1;
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite sadrzaj vrece (naziv praska): ";
        std::getline(std::cin, sadrzaj);
        int tezina_2;
        std::cout<<"Unesite tezinu praska: ";
        std::cin>>tezina_2;
        s=Vreca(tezina_1, sadrzaj, tezina_2);
        s.DajTezinu();
        std::cout<<" ";
        s.DajUkupnuTezinu();
        std::cout<<std::endl;
        s2=Bure(4, "Ulje", 3, 6.3);
        s2.Ispisi();
    } catch (std::logic_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}
