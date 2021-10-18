#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <algorithm>
#include <memory>
using namespace std;
class Spremnik
{
    double tezina;
    string naziv_sadrzaja;
public:
    Spremnik() {}
    virtual double DajTezinu() const =0;
    virtual double DajUkupnuTezinu() const =0;
    virtual void Ispisi() const =0;
    virtual shared_ptr<Spremnik> DajKopiju() const =0;
    virtual ~Spremnik() {}
    friend class Sanduk;
    friend class Vreca;
    friend class Bure;
};

class Sanduk : public Spremnik
{
    vector<double> tezine;
public:
    Sanduk(double kg, string c,vector<double> tp) {
        tezina=kg;
        naziv_sadrzaja=c;
        tezine=tp;
    }
    double DajTezinu() const override {
        return tezina;
    }
    double DajUkupnuTezinu() const override {
        double a = tezina;
        for(int i=0; i<tezine.size(); i++)
            a+=tezine.at(i);
        return a;
    }
    void Ispisi() const override {
        cout << "Vrsta spremnika: Sanduk" <<endl
             << "Sadrzaj: " << naziv_sadrzaja << endl
             << "Tezine predmeta: ";
        for(int i=0; i<tezine.size(); i++) cout << tezine.at(i) << " ";
        cout << "(kg)" << endl
             << "Vlastita tezina: " << DajTezinu() << " (kg)" << endl
             << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    shared_ptr<Spremnik> DajKopiju() const override {
        return make_shared<Sanduk>(*this);
    }
    ~Sanduk() {}
};

class Bure : public Spremnik
{
    double specificna;
    double zapremina;
public:
    Bure(double kg, string c, double t,double v) {
        tezina=kg;
        naziv_sadrzaja=c;
        specificna=t;
        zapremina=v;
    }

    double DajTezinu() const override {
        return tezina;
    }
    double DajUkupnuTezinu() const override {
        return tezina+((specificna*0.001)*zapremina);
    }
    void Ispisi() const override {
        cout << "Vrsta spremnika: Bure" <<endl
             << "Sadrzaj: " << naziv_sadrzaja << endl
             << "Vlastita tezina: " << DajTezinu() << " (kg)" << endl
             << "Specificna tezina tecnosti: " << specificna << " (kg/m^3)" << endl
             << "Zapremina tecnosti: " << zapremina << " (l)" << endl
             << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    shared_ptr<Spremnik> DajKopiju() const override {
        return make_shared<Bure>(*this);
    }
    ~Bure() {}
};

class Vreca : public Spremnik
{
    double tezina_praska;
public:
    Vreca(double t,string c,double tp) {
        tezina=t;
        naziv_sadrzaja=c;
        tezina_praska=tp;
    }
    double DajTezinu() const override {
        return tezina;
    }
    double DajUkupnuTezinu() const override {
        return tezina+tezina_praska;
    }
    void Ispisi() const override {
        cout << "Vrsta spremnika: Vreca" <<endl
             << "Sadrzaj: " << naziv_sadrzaja << endl
             << "Vlastita tezina: " << DajTezinu() << " (kg)" << endl
             << "Tezina pohranjene materije: " << tezina_praska << " (kg)"  << endl
             << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }

    shared_ptr<Spremnik> DajKopiju() const override {
        return make_shared<Vreca>(*this);
    }
    ~Vreca() {}
};

class Skladiste
{
    vector<shared_ptr<Spremnik>> s;

public:
    Skladiste() {}

    Skladiste(const Skladiste &s2) {
        s.resize(s2.s.size());
        for(int i=0; i<s2.s.size(); i++)
            s.at(i)=s2.s.at(i)->DajKopiju();
    }

    Skladiste(Skladiste &&s2) {
        s=std::move(s2.s);
    }

    Skladiste &operator=(const Skladiste &s2) {
        if(&s2!=this) {
            s.resize(0);
            s.resize(s2.s.size());
            for(int i=0; i<s2.s.size(); i++)
                s.at(i)=s2.s.at(i)->DajKopiju();
        }
        return *this;
    }

    Skladiste &operator=(Skladiste &&s2) {
        if(&s2!=this) {
            s.resize(0);
            s=std::move(s2.s);
        }
        return *this;
    }


    Spremnik* DodajBure(double kg, string c, double t,double v) {
        shared_ptr<Spremnik> a;
        s.push_back(a=make_shared<Bure>(kg,c,t,v));
        return a.get();
    }

    Spremnik* DodajSanduk(double kg, string c, vector<double> tp) {
        shared_ptr<Spremnik> a;
        s.push_back(a=make_shared<Sanduk>(kg,c,tp));
        return a.get();
    }

    Spremnik* DodajVrecu(double t,string c,double tp) {
        shared_ptr<Spremnik> a;
        s.push_back(a=make_shared<Vreca>(t,c,tp));
        return a.get();
    }

    Spremnik* DodajSpremnik(Spremnik *s1,bool b) {
        if(!b) {
            shared_ptr<Spremnik> r(s1->DajKopiju());
            s.push_back(r);
            return r.get();
        } else s.push_back(static_cast<shared_ptr<Spremnik>>(s1));
        return s1;
    }

    void BrisiSpremnik(Spremnik *s1) {
        vector<shared_ptr<Spremnik>>::iterator it(s.begin());
        int i;
        for(i=0; i<s.size(); i++,it++)
            if(s.at(i).get()==s1) break;
        if(i!=s.size()) {
            *it=nullptr;
            s.erase(it);
        }
    }

    Spremnik& DajNajtezi() {
        if(s.empty()) throw std::range_error("Skladiste je prazno");
        return **std::max_element(s.begin(),s.end(),[](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2) {
            return s1->DajTezinu()<s2->DajTezinu();
        });
    }

    Spremnik& DajNajlaksi() {
        if(s.empty()) throw std::range_error("Skladiste je prazno");
        return **std::min_element(s.begin(),s.end(),[](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2) {
            return s1->DajTezinu()<s2->DajTezinu();
        });
    }


    int BrojPreteskih(double x) const {
        return std::count_if(s.begin(),s.end(),[x](shared_ptr<Spremnik> s) {
            return s->DajUkupnuTezinu() > x;
        });
    }

    void IzlistajSkladiste() const {
        vector<shared_ptr<Spremnik>> skladiste;
        for(int i=0; i<s.size(); i++)
            skladiste.push_back(s.at(i));
        std::sort(skladiste.begin(),skladiste.end(),[](shared_ptr<Spremnik> s1, shared_ptr<Spremnik> s2) {
            return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
        });
        std::for_each(skladiste.begin(),skladiste.end(),[](shared_ptr<Spremnik> s1) {
            s1->Ispisi();
        });
    }

    void UcitajIzDatoteke(const char *c) {
        std::ifstream roba(c);
        if(!roba) throw std::logic_error("Trazena datoteka ne postoji");
        string naziv;
        char vrsta, znak(0);
        string::iterator sIt;
        s.resize(0);
        for(;;) {
            roba >> std::ws;
            std::getline(roba,naziv);
            if(roba.bad()) throw std::logic_error("Problemi pri citanju datoteke");
            sIt=naziv.begin();
            while(sIt!=naziv.end() && *sIt==' ') sIt++;
            vrsta=*sIt;
            sIt++;
            if(!(vrsta=='S' ||vrsta=='B' ||vrsta=='V')) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            while(sIt!=naziv.end() && *sIt==' ') sIt++;
            naziv.erase(naziv.begin(),sIt);
            int broj;
            vector<double> vs;
            double x,y,z;
            if(vrsta=='S') {
                roba >> x>>broj;
                while(broj!=0) {
                    roba >>y;
                    znak=roba.get();
                    vs.push_back(y);
                    broj--;
                }
                if(!(znak==' ' || znak==EOF ||znak=='\n')) roba.setstate(std::ios::failbit);
            } else if(vrsta=='V') roba>>x>>y;
            else roba >> x>>y>>z;
            if(vrsta!='S') znak=roba.get();
            if(roba.fail() && !roba.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if(roba.bad()) throw std::logic_error("Problemi pri citanju datoteke");
            if(vrsta=='S') this->DodajSanduk(x,naziv,vs);
            else if(vrsta=='B') this->DodajBure(x,naziv,y,z);
            else this->DodajVrecu(x,naziv,y);
            if(roba.eof() || roba.peek()==EOF) break;
        }
        roba.close();
    }

    ~Skladiste() {
        for(int i=0; i<s.size(); i++)
            s.at(i)=nullptr;
        s.resize(0);
    }
};

int main () {
    Skladiste s;
    s.UcitajIzDatoteke("ROBA.TXT");
    s.IzlistajSkladiste();
    return 0;
}
