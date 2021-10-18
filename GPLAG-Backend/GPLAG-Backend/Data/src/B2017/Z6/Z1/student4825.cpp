/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class Spremnik {
protected: 
    double tezina;
    std::string materija;
public:
    virtual double DajTezinu() const=0;
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
};

class Sanduk : public Spremnik {
    std::vector<double> tezinapredmeta;
public:
    Sanduk(double tezina, std::string ime, std::vector<double> vektor) : tezinapredmeta(vektor) {
        Sanduk::tezina=tezina; Sanduk::materija=ime;
    }
    double DajTezinu() const override { return Sanduk::tezina; }
    double DajUkupnuTezinu() const override { double suma(0); for (double x : tezinapredmeta) suma+=x; return Sanduk::tezina+suma; }
    void Ispisi() const override { 
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<Sanduk::materija<<std::endl;
        std::cout<<"Tezine predmeta: "; for (double x:tezinapredmeta) std::cout<<x<<" "; std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
    }
};

class Vreca : public Spremnik {
    double tezinamaterije;
public:
    Vreca(double tezina, std::string ime, double tmat) :  tezinamaterije(tmat) {
        Vreca::tezina=tezina; Vreca::materija=ime;
    }
    double DajTezinu() const override { return Vreca::tezina; }
    double DajUkupnuTezinu() const override { return Vreca::tezina+tezinamaterije; }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<Vreca::materija<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Tezina pohranjene materije: "<<tezinamaterije<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
    }
};

class Bure : public Spremnik {
    double gustinatecnosti;
    double zapreminatecnosti;
public:
    Bure(double tezina, std::string ime, double ro, double V) : gustinatecnosti(ro), zapreminatecnosti(V) {
        Bure::tezina=tezina; Bure::materija=ime;
    }
    double DajTezinu() const override { return Bure::tezina; }
    double DajUkupnuTezinu() const override { return Bure::tezina+gustinatecnosti*zapreminatecnosti; }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<Bure::materija<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Specificna tezina tecnosti: "<<gustinatecnosti<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapreminatecnosti<<" (l)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
    }
};

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> vek_pok;
public:
    /*Skladiste(const Skladiste &s) : vek_pok(s.vek_pok.size, nullptr){
        std::copy(s.vek_pok, s.vek_pok+s.vek_pok.size(), vek_pok);
    }*/
    
};
int main ()
{
	return 0;
}
