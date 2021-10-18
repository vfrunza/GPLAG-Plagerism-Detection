/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <stdexcept>
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::cout;
using std::cin;


class Spremnik
{
protected:
    double tezina;
    string ime;

public:
    Spremnik(double tezina,string ime):tezina(tezina),ime(ime) {};
    string DajNaziv() const {
        return ime;
    }
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual ~Spremnik() {};
    virtual shared_ptr<Spremnik> DajKopiju() const=0;
};

class Sanduk:public Spremnik
{
    vector<double> v;
public:
    Sanduk(double tezina, string ime, const vector<double> &v):Spremnik(tezina,ime),v(v) {}

    double DajUkupnuTezinu() const {
        double suma=0;
        for(int i=0; i<v.size(); i++){
            suma+=v[i];
        }
        return suma+tezina;
    }
    void Ispisi() const override {
        cout<<"Vrsta spremnika: Sanduk\n"
                <<"Sadrzaj: "<<ime<<"\n"
                <<"Tezine predmeta: ";
                for(int i=0; i<v.size(); i++)
                    cout<<v[i]<<" ";
        cout<<"(kg)"<<"\n"
            <<"Vlastita tezina: "<<tezina<<" (kg)"<<"\n"
            <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<"\n";
    }
    shared_ptr<Spremnik> DajKopiju() const override {
        return make_shared<Sanduk>(*this);
    }
};
class Vreca:public Spremnik
{
    double tezina1;
public:
    Vreca(double tezina, string ime, double tezina_1): Spremnik(tezina, ime),tezina1(tezina_1) {}
    double DajUkupnuTezinu() const {
        return tezina1+tezina;
    }
    void Ispisi() const {
        cout<<"Vrsta spremnika: Vreca\n"
            <<"Sadrzaj: "<<ime<<"\n"
            <<"Vlastita tezina: "<<tezina<<" (kg)\n"
            <<"Tezina pohranjene materije: "<<tezina1
            <<" (kg)\n"<<"Ukupna tezina: "
            <<DajUkupnuTezinu()<<" (kg)\n";
    }

    shared_ptr<Spremnik> DajKopiju() const override {
        return make_shared<Vreca>(*this);
    }
};
class Bure:public Spremnik
{
    double ro;
    double zapremina;
public:
    Bure(double tezina, string ime, double ro, double zapremina): Spremnik(tezina,ime),ro(ro),zapremina(zapremina) {}
    double DajUkupnuTezinu() const {

        return tezina+(zapremina/1000)*ro;
    }
    void Ispisi() const override {
        cout<<"Vrsta spremnika: Bure\n"
            <<"Sadrzaj: "<<ime<<"\n"
            <<"Vlastita tezina: "<<tezina<<" (kg)\n"
            <<"Specificna tezina tecnosti: "<<ro<<" (kg/m^3)\n"
            <<"Zapremina tecnosti: "<<zapremina<<" (l)\n"
            <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    shared_ptr<Spremnik> DajKopiju() const {
        return make_shared<Bure>(*this);
    }
};
/*class Skladiste{
    vector<shared_ptr<Spremnik>> skladiste;
public:
    Skladiste(){}
    Skladiste(const Skladiste &s);
    Skladiste &operator =(const Skladiste &s);
    Spremnik *DodajSanduk(double tezina, string ime, vector<double> t1){
        Sanduk s(tezina, ime, t1);
        skladiste.push_back(s.DajKopiju());
        return skladiste[skladiste.size()-1].get();
    }
};
*/
class PolimorfniSpremnik
{
    shared_ptr<Spremnik> pok;
public:
    PolimorfniSpremnik():pok(nullptr) {}
    ~PolimorfniSpremnik() {
        pok=nullptr;
    }
    PolimorfniSpremnik (const Spremnik &s):pok(s.DajKopiju()) {}
    PolimorfniSpremnik(PolimorfniSpremnik &p):pok(p.pok->DajKopiju()) {}
    PolimorfniSpremnik(PolimorfniSpremnik &&p): pok(p.pok) {
        p.pok=nullptr;
    }
    PolimorfniSpremnik &operator=(PolimorfniSpremnik &&p) {
        pok=p.pok->DajKopiju();
        p.pok=nullptr;
        return *this;
    }
    PolimorfniSpremnik &operator=(PolimorfniSpremnik &p) {
        pok=p.pok->DajKopiju();
        return *this;
    }
    double DajTezinu() const {
        if(!pok) {
            throw std::logic_error("Nespecificiran spremnik");
        }
        return pok->DajTezinu();
    }
    string DajNaziv() const {
        if(!pok) {
            throw std::logic_error("Nespecificiran spremnik");
        }
        return pok->DajNaziv();
    }
    double DajUkupnuTezinu() const {
        if(!pok) {
            throw std::logic_error("Nespecificiran spremnik");
        }
        return pok->DajUkupnuTezinu();
    }
    void Ispisi() const{
        if(!pok){
            throw std::logic_error("Nespecificiran spremnik");
        }
        pok->Ispisi();
    }
};
int main ()
{

    return 0;
}
