/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <vector>
#include <stdexcept>
#include <string>

class Spremnik {
protected: 
    double tezina;
    std::string materija;
public:
    virtual std::string DajIme() const=0;
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
    std::string DajIme() const override { return Sanduk::materija; }
    double DajTezinu() const override { return Sanduk::tezina; }
    double DajUkupnuTezinu() const override { double suma(0); for (double x : tezinapredmeta) suma+=x; return Sanduk::tezina+suma; }
    void Ispisi() const override  { 
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
    std::string DajIme() const override { return Vreca::materija; }
    double DajTezinu() const override { return Vreca::tezina; }
    double DajUkupnuTezinu() const override { return Vreca::tezina+tezinamaterije; }
    void Ispisi() const override  {
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
    std::string DajIme() const override { return Bure::materija; }
    double DajTezinu() const override { return Bure::tezina; }
    double DajUkupnuTezinu() const override { return Bure::tezina+gustinatecnosti*zapreminatecnosti; }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<Bure::materija<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Specificna tezina tecnosti: "<<gustinatecnosti<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapreminatecnosti<<" (l)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
    }
};
class PolimorfniSpremnik : public Spremnik {
public:
    PolimorfniSpremnik() = default;
    PolimorfniSpremnik(const Sanduk &s){ PolimorfniSpremnik::tezina=s.DajTezinu(); PolimorfniSpremnik::materija=s.DajIme(); }
    PolimorfniSpremnik(const Vreca &v){ PolimorfniSpremnik::tezina=v.DajTezinu(); PolimorfniSpremnik::materija=v.DajIme(); }
    PolimorfniSpremnik(const Bure &b){ PolimorfniSpremnik::tezina=b.DajTezinu(); PolimorfniSpremnik::materija=b.DajIme(); }
    PolimorfniSpremnik &operator=(Sanduk s) { PolimorfniSpremnik p; p.tezina=s.DajTezinu();
        p.materija=s.DajIme(); return p; }
    PolimorfniSpremnik &operator=(Vreca v) { PolimorfniSpremnik::tezina=v.DajTezinu(); PolimorfniSpremnik::materija=v.DajIme(); }
    PolimorfniSpremnik &operator=(Bure b) { PolimorfniSpremnik::tezina=b.DajTezinu(); PolimorfniSpremnik::materija=b.DajIme(); }
    double DajTezinu() const { throw std::logic_error("Nespecificiran spremnik"); }
    double DajUkupnuTezinu() const { throw std::logic_error("Nespecificiran spremnik"); }
    void Ispisi() const { throw std::logic_error("Nespecificiran spremnik"); }
};

int main ()
{
    try{
        PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70));
        PolimorfniSpremnik s2, s3;
        s2=Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});
        s3=Vreca(0.4, "Brasno", 30);
        std::cout<<s1.DajTezinu()<<std::endl;
        std::cout<<s2.DajUkupnuTezinu()<<std::endl;
        s3.Ispisi();
        s1=s2;
        s1.Ispisi();
    }
    catch (std::logic_error e){
        std::cout<<e.what();
    }
	return 0;
}
