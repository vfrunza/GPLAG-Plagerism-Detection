/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>
#include <vector>
#include <new>
#include <stdexcept>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <typeinfo>

constexpr double EPSILON(0.001);

template <typename IspisiviTip>
std::string PretvoriUString(const IspisiviTip &nesto)
{
    std::ostringstream tok;
    tok << nesto;
    return tok.str();
}
template <typename NekiTip>
NekiTip PretvoriIzStringa(std::string s)
{
    std::istringstream tok(s);
    NekiTip nesto;
    tok >> nesto;
    if(!tok || tok.peek() != EOF)
        return (9918273.1234);
    return nesto;
}

class Spremnik
{
protected:
    double tezina;
    std::string naziv;
public:
    Spremnik(double t, std::string n): tezina(t), naziv(n) {}
    virtual ~ Spremnik() {}
    double DajTezinu()  {
        return tezina;
    }
    std::string DajNaziv() const { return naziv; }
    virtual double DajGustinu() const =0;
    virtual double DajZapreminu() const =0;
    virtual std::vector<double> DajTezineElemenata() const =0;
    virtual Spremnik* DajKopiju() const =0;
    virtual double DajUkupnuTezinu() const =0;
    virtual  void Ispisi() const =0;
};


class Sanduk : public Spremnik
{
    std::vector<double> tezine_elemenata;
public:
    Sanduk(double t_s,std::string n, std::vector<double> t_e) : Spremnik(t_s,n), tezine_elemenata(t_e) {}
    double DajUkupnuTezinu() const {
        double ukupna(tezina);
        for(int i(0); i<tezine_elemenata.size(); i++)
            ukupna+=tezine_elemenata[i];
        return ukupna;
    }
    Spremnik* DajKopiju() const override {
        return new Sanduk(*this);
    }
    std::vector<double> DajTezineElemenata() const { return tezine_elemenata; }
    double DajGustinu() const { return 0; }
    double DajZapreminu() const { return 0; }
    std::string DajNaziv() const { return naziv; }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta:";
        for(int i(0); i<tezine_elemenata.size(); i++)
            std::cout<<" "<<tezine_elemenata[i];
        std::cout<<" (kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Vreca : public Spremnik
{
    double tezina_materije;
public:
    Vreca(double t_v, std::string n, double t_m) : Spremnik(t_v,n), tezina_materije(t_m) {}
    double DajUkupnuTezinu() const {
        return (tezina+tezina_materije);
    }
    Spremnik* DajKopiju() const override {
        return new Vreca(*this);
    }
    std::vector<double> DajTezineElemenata() const  { std::vector<double> neki_vektor(0); return neki_vektor; }
    double DajGustinu() const { return 0; }
    double DajZapreminu() const { return 0; }
     std::string DajNaziv() const { return naziv; }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Bure : public Spremnik
{
    double gustina,zapremina;
public:
    Bure(double t_b, std::string n, double g, double z) : Spremnik(t_b,n), gustina(g), zapremina(z) {}
    double DajUkupnuTezinu() const {
        return (gustina*zapremina*0.001+tezina);
    }
    Spremnik* DajKopiju() const override {
        return new Bure(*this);
    }
    std::vector<double> DajTezineElemenata() const  { std::vector<double> neki_vektor(0); return neki_vektor; }
    double DajGustinu() const {return gustina;}
    double DajZapreminu() const {return zapremina;}
     std::string DajNaziv() const  { return naziv; }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> v;
    std::vector<Spremnik*> adrese;
public:
    Skladiste() : v(0), adrese(0) {}
    Skladiste &operator= (const Skladiste &neko_skladiste) {
        int velicina(v.size());
        for(int i(0); i<velicina; i++)
            v.erase(v.begin()+0);
        for(int i(0); i<velicina; i++)
            adrese.erase(adrese.begin()+0);
        for(int i(0); i<neko_skladiste.adrese.size(); i++)
            adrese.push_back(neko_skladiste.adrese[i]);
        for(int i(0); i<neko_skladiste.v.size(); i++) {
            v.push_back(std::shared_ptr<Spremnik>(neko_skladiste.v[i]->DajKopiju()));
        }
        return *this;
    }
    Spremnik* DodajSpremnik(Spremnik* s, bool tacno) {
        adrese.push_back(s);
        if(tacno) {
            v.push_back(std::shared_ptr<Spremnik>(s));
            return s;
        }
        v.push_back(std::shared_ptr<Spremnik>(s->DajKopiju()));
        return s;
    }
    Spremnik* DodajSanduk(double t_s,std::string n, std::vector<double> t_e) {
        auto neki_sanduk(new Sanduk(t_s,n,t_e));
        return(DodajSpremnik(neki_sanduk,true));
    }
    Spremnik* DodajVrecu(double t_v, std::string n, double t_m) {
        auto neka_vreca(new Vreca(t_v,n,t_m));
        return(DodajSpremnik(neka_vreca,true));
    }
    Spremnik* DodajBure(double t_b, std::string n, double g, double z) {
        auto neko_bure(new Bure(t_b,n,g,z));
        return(DodajSpremnik(neko_bure,true));
    }
    void BrisiSpremnik(Spremnik *s) {
        int i(0);
        for(; i<adrese.size(); i++)
            if(s==adrese[i]) break;
        v.erase(v.begin()+i);
    }
    Spremnik &DajNajlaksi() {
        if(v.size()==0) throw std::range_error("Skladiste je prazno");
        auto najlaksi(v[0]);
        for(int i(0); i<v.size(); i++)
            if(v[i]->DajTezinu()<najlaksi->DajTezinu()) najlaksi=v[i];
        return *najlaksi;
    }
    Spremnik &DajNajtezi() {
        if(v.size()==0) throw std::range_error("Skladiste je prazno");
        auto najtezi(v[0]);
        for(int i(0); i<v.size(); i++)
            if(v[i]->DajTezinu()>najtezi->DajTezinu()) najtezi=v[i];
        return *najtezi;
    }
    int BrojPreteskih(int neka_tezina) {
        if(v.size()==0) throw std::range_error("Skladiste je prazno");
        int brojac(0);
        for(int i(0); i<v.size(); i++)
            if(v[i]->DajUkupnuTezinu()>neka_tezina) brojac++;
        return brojac;
    }
    void IzlistajSkladiste() const {
        if(v.size()==0) throw std::range_error("Skladiste je prazno");
        std::vector<std::shared_ptr<Spremnik>> kopija(v);
        std::sort(kopija.begin(),kopija.end(), [] (std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) {
            return(p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu());
        });
        for(int i(0); i<kopija.size(); i++)
            kopija[i]->Ispisi();
    }
    void UcitajIzDatoteke(const char NazivDatoteke[]) {
        std::fstream dat(NazivDatoteke);
        if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
        while(!dat.eof()) {

            std::string s;
            dat>>s;
            if(s=="S") {
                std::getline(dat,s);
                s.erase(s.begin()+0);
                std::string ime(s);
                dat>>s;
                double t(PretvoriIzStringa<double>(s));
                std::vector<double> t1;
                dat>>s;
                while(!dat.eof()) {
                    if(fabs(PretvoriIzStringa<double>(s)-9918273.1234)<EPSILON) {
                        dat.seekg(-1,std::ios::cur);
                        break;
                    }
                    t1.push_back(PretvoriIzStringa<double>(s));
                    dat>>s;
                }
                int brojac(0);
                int indeks(-1);
                int i(0);
                std::for_each(v.begin(),v.end(), [&brojac,t,ime,t1,&i,&indeks] (std::shared_ptr<Spremnik> p) {
                    bool T(false),tacno(false); i++;
                    if(typeid(*p) == typeid(Sanduk) && fabs(p->DajKopiju()->DajTezinu()-t)<EPSILON &&
                            (p->DajKopiju()->DajNaziv()==ime)) tacno=true;
                    if(tacno) {
                        if(p->DajKopiju()->DajTezineElemenata().size()!=t1.size()) T=false;
                        else {
                            int i(0);
                            for(; i<p->DajKopiju()->DajTezineElemenata().size(); i++)
                                if(fabs(p->DajKopiju()->DajTezineElemenata()[i]-t1[i])>EPSILON) break;
                            if(i==p->DajKopiju()->DajTezineElemenata().size()-1) { T=true; indeks=i; }
                            else T=false;
                        }
                    }
                    if(T) brojac++;
                });
                if(brojac==0)
                this->DodajSanduk(t,ime,t1);
                else {
                    v.erase(v.begin()+indeks);
                    adrese.erase(adrese.begin()+indeks);
                    this->DodajSanduk(t,ime,t1);
                }
            } else if(s=="V") {
                std::getline(dat,s);
                s.erase(s.begin()+0);
                std::string ime(s);
                dat>>s;
                double t(PretvoriIzStringa<double>(s));
                dat>>s;
                double t1(PretvoriIzStringa<double>(s));
                int brojac(0);
                int i(0), indeks(-1);
                std::for_each(v.begin(),v.end(), [&brojac,t,ime,t1,&i,&indeks] (std::shared_ptr<Spremnik> p) {
                    bool T(false); i++;
                    if(typeid(*p) == typeid(Vreca) && fabs(p->DajKopiju()->DajTezinu()-t)<EPSILON &&
                            (p->DajKopiju()->DajNaziv()==ime) && fabs(p->DajKopiju()->DajUkupnuTezinu()-p->DajKopiju()->DajTezinu()-t+t1)<EPSILON) T=true;
                    if(T) { brojac++; indeks=i; }
                });
                if(brojac==0)
                this->DodajVrecu(t,ime,t1);
                else {
                    v.erase(v.begin()+indeks);
                    adrese.erase(adrese.begin()+indeks);
                    this->DodajVrecu(t,ime,t1);
                }

            } else if(s=="B") {
                std::getline(dat,s);
                s.erase(s.begin()+0);
                std::string ime(s);
                dat>>s;
                double t(PretvoriIzStringa<double>(s));
                dat>>s;
                double rho(PretvoriIzStringa<double>(s));
                dat>>s;
                double V(PretvoriIzStringa<double>(s));
                int brojac(0);
                int i(0), indeks(-1);
                std::for_each(v.begin(),v.end(), [&brojac,t,ime,rho,V,&i,&indeks] (std::shared_ptr<Spremnik> p) {
                    bool T(false); i++;
                    if(typeid(*p) == typeid(Bure) && fabs(p->DajKopiju()->DajTezinu()-t)<EPSILON &&
                            (p->DajKopiju()->DajNaziv()==ime) && (p->DajKopiju()->DajGustinu()-rho)<EPSILON && (p->DajKopiju()->DajZapreminu()-V)<EPSILON) T=true;
                    if(T) { brojac++; indeks=i; }
                });
                if(brojac==0)
                this->DodajBure(t,ime,rho,V);
                else {
                    v.erase(v.begin()+indeks);
                    adrese.erase(adrese.begin()+indeks);
                    DodajBure(t,ime,rho,V);
                }

            }
        }
         if(dat.eof()) std::logic_error("Problemi pri citanju datoteke");
else if(dat.bad()) std::logic_error("Datoteka sadrzi besmislene podatke");
else throw std::logic_error("Datoteka sadrzi besmislene podatke");

        dat.close();
    }
};

int main ()
{
    Skladiste ETF;
    ETF.UcitajIzDatoteke("ROBA.TXT");
    ETF.IzlistajSkladiste();
    return 0;
}
