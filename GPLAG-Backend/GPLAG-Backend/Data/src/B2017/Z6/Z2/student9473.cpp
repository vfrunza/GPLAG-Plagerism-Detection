/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>
#include <algorithm>

//Kopiran zadatak 1 na samom pocetku

class Spremnik {
    protected:
    double tezina;
    std::string ime;
    public:
    Spremnik(double tez, std::string naziv) {
        ime=naziv;
        tezina=tez;
    }
    virtual ~Spremnik() {}
    double DajTezinu() const { return tezina;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual Spremnik* DajKopiju() const=0;
};



class Sanduk: public Spremnik {
    std::vector<double> sanduk;
    public:
    Sanduk(double tez, std::string naziv, std::vector<double> v): Spremnik(tez,naziv) {
        sanduk=v;
    }
    ~Sanduk() {}
    Spremnik* DajKopiju() const override {
        return new Sanduk(*this);
    }
    double DajUkupnuTezinu() const override {
        double s=0;
        for (int i=0; i<sanduk.size(); i++) {
            s+=sanduk[i];
        }
        return s+tezina;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for (int i=0; i<sanduk.size(); i++) {
            std::cout<<sanduk[i]<<" ";
            if (i==sanduk.size()-1) std::cout<<"(kg)"<<std::endl;
        }
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};  


class Vreca: public Spremnik {
    double vreca;
    public:
    Vreca(double tez, std::string naziv, double v): Spremnik(tez,naziv) {
        vreca=v;
    }
    ~Vreca() {}
    Spremnik* DajKopiju() const override {
        return new Vreca(*this);
    }
    double DajUkupnuTezinu() const override { return vreca+tezina;}
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<vreca<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
}; 

class Bure: public Spremnik {
    double ro, v;
    public:
    Bure(double tez, std::string naziv, double gustina, double zapremina): Spremnik(tez,naziv) {
        ro=gustina;
        v=zapremina;
    }
    ~Bure() {}
    Spremnik* DajKopiju() const override {
        return new Bure(*this);
    }
    double DajUkupnuTezinu() const override {
        return tezina+ro*v*0.001; 
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<ro<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<v<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
}; 

class PolimorfniSpremnik {
    Spremnik *polimorfni_spremnik;
    public: 
    PolimorfniSpremnik() {
        polimorfni_spremnik=nullptr;
    }
    PolimorfniSpremnik(const Spremnik &sprem): polimorfni_spremnik(sprem.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &p_s) {
        if (!p_s.polimorfni_spremnik) polimorfni_spremnik=nullptr;
        else polimorfni_spremnik=p_s.polimorfni_spremnik->DajKopiju();
    }
    ~PolimorfniSpremnik() {
        delete polimorfni_spremnik;
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&p_s) {
        polimorfni_spremnik=p_s.polimorfni_spremnik;
        p_s.polimorfni_spremnik=nullptr;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&p_s) {
        std::swap(polimorfni_spremnik, p_s.polimorfni_spremnik);
        return *this;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &p_s) {
        Spremnik *s(nullptr);
        if (p_s.polimorfni_spremnik!=nullptr) s=p_s.polimorfni_spremnik->DajKopiju();
        delete polimorfni_spremnik;
        polimorfni_spremnik=s;
        return *this;
    }
    
    double DajTezinu() const {
        if (!polimorfni_spremnik) throw std::logic_error ("Nespecificiran spremnik");
        return polimorfni_spremnik->DajTezinu();
    }
    
    double DajUkupnuTezinu() const {
        if (!polimorfni_spremnik) throw std::logic_error ("Nespecificiran spremnik");
        return polimorfni_spremnik->DajUkupnuTezinu();
    }
    
    void Ispisi() const {
        if (!polimorfni_spremnik) throw std::logic_error ("Nespecificiran spremnik");
        polimorfni_spremnik->Ispisi();
    }
};
    


int main ()
{
    try {
        PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70));
        PolimorfniSpremnik s2, s3, s4;
        s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});
        s3 = Vreca(0.1, "Patak", 15.5);
        std::cout << s1.DajTezinu() << std::endl;
        std::cout << s2.DajUkupnuTezinu() << std::endl;
        s3.Ispisi();
        s1 = s2;
        s1.Ispisi();
        s4.DajTezinu();
    }
    catch(std::logic_error le)
    {
        std::cout << le.what();
    }
	return 0;
}
