/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Spremnik {
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(double tezina, std::string naziv) : tezina(tezina), naziv(naziv) { }
    Spremnik &operator =(const Spremnik &s) {
        tezina=s.tezina;
        naziv=s.naziv;
        return *this;
    }
    virtual ~Spremnik() { }
    double DajTezinu() const { return tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik *DajKopiju() const = 0;
};

class Sanduk : public Spremnik {
    std::vector<double> t_predmeta;
    public:
    Sanduk(double tezina, std::string naziv, std::vector<double> t_predmeta) :
            Spremnik::Spremnik(tezina, naziv), t_predmeta(t_predmeta) { }
    double DajUkupnuTezinu() const {
        double ukupna(0);
        for(int i=0; i<t_predmeta.size(); i++)
            ukupna+=t_predmeta[i];
        return ukupna+tezina;
    }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl
                 <<"Sadrzaj: "<<naziv<<std::endl
                 <<"Tezine predmeta: ";
                 for(int i=0; i<t_predmeta.size(); i++) 
                    std::cout<<t_predmeta[i]<<" ";
        std::cout<<"(kg)"<<std::endl
                 <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
                 <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Spremnik *DajKopiju() const { return new Sanduk(*this); }
};

class Vreca : public Spremnik {
    double tezina_praha;
    public:
    Vreca(double tezina, std::string naziv, double tezina_praha) :
          Spremnik::Spremnik(tezina, naziv), tezina_praha(tezina_praha) { }
    double DajUkupnuTezinu() const { return tezina+tezina_praha; }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl
                 <<"Sadrzaj: "<<naziv<<std::endl
                 <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
                 <<"Tezina pohranjene materije: "<<tezina_praha<<" (kg)"<<std::endl
                 <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Spremnik *DajKopiju() const { return new Vreca(*this); }
};

class Bure : public Spremnik {
    double RO, V_tecnosti;
    public:
    Bure(double tezina, std::string naziv, double RO, double V_tecnosti) : 
         Spremnik::Spremnik(tezina, naziv), RO(RO), V_tecnosti(V_tecnosti) { }
    double DajUkupnuTezinu() const {
        return tezina + (RO * (V_tecnosti/1000));
    }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl
                 <<"Sadrzaj: "<<naziv<<std::endl
                 <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
                 <<"Specificna tezina tecnosti: "<<RO<<" (kg/m^3)"<<std::endl
                 <<"Zapremina tecnosti: "<<V_tecnosti<<" (l)"<<std::endl
                 <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Spremnik *DajKopiju() const { return new Bure(*this); }
};

class PolimorfniSpremnik {
    Spremnik *pok;
    void Test() const {
        if(!pok) throw std::logic_error ("Nespecificiran spremnik");
    }
    public:
    PolimorfniSpremnik() : pok(nullptr) { }
    ~PolimorfniSpremnik() { delete pok; }
    PolimorfniSpremnik(const Spremnik &spremnik) : pok(spremnik.DajKopiju()) { }
    PolimorfniSpremnik(const PolimorfniSpremnik &spremnik) {
        if(!spremnik.pok) pok=nullptr;
        else pok=spremnik.pok->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&spremnik) {
        pok=spremnik.pok;
        spremnik.pok=nullptr;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &spremnik) {
        Spremnik *novi_pok(nullptr);
        if(spremnik.pok!=nullptr)
            novi_pok=spremnik.pok->DajKopiju();
        delete pok;
        pok=novi_pok;
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&spremnik) {
        std::swap(pok, spremnik.pok);
        return *this;
    }
    double DajTezinu() const {
        Test();
        return pok->DajTezinu();
    }
    double DajUkupnuTezinu() const {
        Test();
        return pok->DajUkupnuTezinu();
    }
    void Ispisi() const {
        Test();
        pok->Ispisi();
    }
};

int main ()
{
    PolimorfniSpremnik s1(Bure(5, "Benzin", 930, 70));
    PolimorfniSpremnik s2, s3;
    s2=Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});
    s3= Vreca(0.4, "Brasno", 30);
    std::cout<<s1.DajTezinu()<<std::endl;
    std::cout<<s2.DajUkupnuTezinu()<<std::endl;
    s3.Ispisi();
    s1=s2;
    s1.Ispisi();
    
    PolimorfniSpremnik s4(Bure(20,"Red Bull", 800, 150));
    PolimorfniSpremnik s5(s4);
    PolimorfniSpremnik s6;
    s6=s5;
    s6.Ispisi();
	return 0;
}
