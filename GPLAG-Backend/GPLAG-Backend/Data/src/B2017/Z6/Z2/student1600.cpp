/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <new>
#include <stdexcept>

class Spremnik
{
protected:
    double tezina;
    std::string vrsta;
public:
    Spremnik(double tez, std::string vrs):tezina(tez) {
        vrsta=vrs;
    }
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual Spremnik* DajKopiju() const=0;
    virtual ~ Spremnik() {}
};

class Sanduk:public Spremnik
{
private:
    std::vector<double> vektezine;
public:
    Sanduk(double tez, std::string vrs, std::vector<double> vektez): Spremnik(tez, vrs) {
        vektezine=vektez;
    }
    double DajUkupnuTezinu() const override {
        double pom(tezina);
        for(int i=0; i<vektezine.size(); i++)
            pom+=vektezine[i];
        return pom;
    }
    void Ispisi() const override;
    Spremnik* DajKopiju() const override {
        return (new Sanduk(*this));
    }
};

void Sanduk::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
    std::cout<<"Sadrzaj: "<<vrsta<<std::endl;
    std::cout<<"Tezine predmeta: ";
    for(int i=0; i<vektezine.size(); i++)
        std::cout<<vektezine[i]<<" ";
    std::cout<<"(kg)"<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<Sanduk::DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Vreca: public Spremnik
{
private:
    double tezinamat;
public:
    Vreca(double tez, std::string vrs, double tezmat): Spremnik(tez, vrs), tezinamat(tezmat) {}
    double DajUkupnuTezinu() const override {
        double pom(tezina);
        pom+=tezinamat;
        return pom;
    }
    void Ispisi() const override;
    Spremnik* DajKopiju() const override {
        return (new Vreca(*this));
    }
};

void Vreca::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
    std::cout<<"Sadrzaj: "<<vrsta<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
    std::cout<<"Tezina pohranjene materije: "<<tezinamat<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<Vreca::DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class Bure:public Spremnik
{
private:
    double gustina;
    double zapremina;
public:
    Bure(double tez, std::string vrs, double gust, double zapr):Spremnik(tez, vrs), gustina(gust), zapremina(zapr) {}
    double DajUkupnuTezinu() const override {
        double pom(tezina);
        pom+=(gustina*0.001*zapremina);
        return pom;
    }
    void Ispisi() const override;
    Spremnik* DajKopiju() const override {
        return (new Bure(*this));
    }
};

void Bure::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Bure"<<std::endl;
    std::cout<<"Sadrzaj: "<<vrsta<<std::endl;
    std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
    std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
    std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<Bure::DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

class PolimorfniSpremnik
{
private:
    Spremnik *pok;
    void Test() const {
        if(pok==nullptr) throw std::logic_error("Nespecificiran spremnik");
    }
public:
    PolimorfniSpremnik():pok(nullptr) {}
    ~PolimorfniSpremnik() {
        delete pok;
    }
    PolimorfniSpremnik(const Spremnik &spremnik);
    PolimorfniSpremnik(const PolimorfniSpremnik &polspremnik);
    PolimorfniSpremnik(PolimorfniSpremnik &&polspremnik);
    PolimorfniSpremnik &operator=(const PolimorfniSpremnik &polspremnik);
    PolimorfniSpremnik &operator=(PolimorfniSpremnik &&polspremnik);
    double DajTezinu() const;
    double DajUkupnuTezinu() const;
    void Ispisi() const;
};

PolimorfniSpremnik::PolimorfniSpremnik(const Spremnik &spremnik):pok(spremnik.DajKopiju()) {}
PolimorfniSpremnik::PolimorfniSpremnik(const PolimorfniSpremnik &polspremnik)
{
    if(polspremnik.pok==nullptr)
        pok=nullptr;
    else pok=(polspremnik.pok)->DajKopiju();
}
PolimorfniSpremnik::PolimorfniSpremnik(PolimorfniSpremnik &&polspremnik)
{
    pok=polspremnik.pok;
    polspremnik.pok=nullptr;
}
PolimorfniSpremnik &PolimorfniSpremnik::operator=(const PolimorfniSpremnik &polspremnik)
{
    Spremnik* novi(nullptr);
    if(polspremnik.pok!=nullptr)
        novi=(polspremnik.pok)->DajKopiju();
    delete pok;
    pok=novi;
    return *this;
}
PolimorfniSpremnik &PolimorfniSpremnik::operator =(PolimorfniSpremnik &&polspremnik)
{
    std::swap(pok, polspremnik.pok);
    return *this;
}

double PolimorfniSpremnik::DajTezinu() const
{
    Test();
    return pok->DajTezinu();
}

double PolimorfniSpremnik::DajUkupnuTezinu() const
{
    Test();
    return pok->DajUkupnuTezinu();
}
void PolimorfniSpremnik::Ispisi() const
{
    Test();
    pok->Ispisi();
}

int main ()
{
    return 0;
}
