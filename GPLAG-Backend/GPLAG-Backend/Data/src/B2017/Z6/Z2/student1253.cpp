/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <fstream>

class Spremnik
{
protected:
    double tezina;
    std::string naziv;
public:
    virtual ~Spremnik() {} //treba i kad su pametni pokazivaci
    Spremnik(double tezina, std::string naziv) : tezina(tezina), naziv(naziv) {}
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    std::vector<double> tezina_predmeta;
public:
    Sanduk(double t, std::string ime, std::vector<double> tp) : Spremnik(t, ime), tezina_predmeta(tp) {}
    double DajUkupnuTezinu() const override {
        double povratna(tezina);
        for(int i=0; i<tezina_predmeta.size(); i++) {
            povratna += tezina_predmeta[i];
        }
        return povratna;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk\n";
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(int i=0; i<tezina_predmeta.size(); i++) {
            std::cout<<tezina_predmeta[i]<<" ";
        }
        std::cout<<"(kg)\n";
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }
};

class Vreca : public Spremnik
{
    double tezina_praska;
public:
    Vreca(double t, std::string ime, double tp) : Spremnik(t, ime), tezina_praska(tp) {}
    double DajUkupnuTezinu() const override {
        return tezina + tezina_praska;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca\n";
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        std::cout<<"Tezina pohranjene materije: "<<tezina_praska<<" (kg)\n";
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }
};

class Bure : public Spremnik
{
    double R;
    double V;
public:
    Bure(double t, std::string ime, double R, double V) : Spremnik(t, ime), R(R), V(V) {}
    double DajUkupnuTezinu() const override {
        return tezina + R*V*0.001;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure\n";
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)\n";
        std::cout<<"Specificna tezina tecnosti: "<<R<<" (kg/m^3)\n";
        std::cout<<"Zapremina tecnosti: "<<V<<" (l)\n";
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(*this);
    }
};

//NOVO___________________________________________________________________________________________

class PolimorfniSpremnik
{
    std::shared_ptr<Spremnik> p;
    void Test() const {
        if(!p) throw std::logic_error("Nespecificiran spremnik\n");
    }
public:
    PolimorfniSpremnik() : p(nullptr) {}
    ~PolimorfniSpremnik() {}
    PolimorfniSpremnik(const PolimorfniSpremnik &s) {
        if(!s.p) p = nullptr;
        else p = s.p->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&s) {
        p = s.p;
        s.p = nullptr;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &s) {
        std::shared_ptr<Spremnik> novi;
        if(s.p != nullptr) novi = s.p->DajKopiju();
        p = nullptr;
        p = novi;
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&s) {
        std::swap(p, s.p);
        return *this;
    }
    PolimorfniSpremnik(const Spremnik &s) : p(s.DajKopiju()) {}

    double DajTezinu() const {
        Test();
        return p->DajTezinu();
    }
    double DajUkupnuTezinu() const {
        Test();
        return p->DajUkupnuTezinu();
    }
    void Ispisi() const {
        Test();
        p->Ispisi();
    }
};

int main ()
{
    try {

        PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70)); // s1 je bure
        PolimorfniSpremnik s2, s3; // s2 i s3 su nespecificirani
        s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5}); // s2 je sada sanduk
        s3 = Vreca(0.4, "Brasno", 30); // a s3 vreca
        std::cout << s1.DajTezinu() << std::endl;
        std::cout << s2.DajUkupnuTezinu() << std::endl;
        s3.Ispisi();
        s1 = s2; // sad je i s1 sanduk...
        s1.Ispisi();


    } catch(...) {
        std::cout << "Izuzetak.";
    }

    return 0;
}
