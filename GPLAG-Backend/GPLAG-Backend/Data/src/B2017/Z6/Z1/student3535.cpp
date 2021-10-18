/B2017/2018: Zadaća 6, Zadatak 1
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
    Spremnik(double tezina, string ime):tezina(tezina),ime(ime) {}
    string DajNaziv() const {
        return ime;
    }
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual ~Spremnik() {}
    virtual shared_ptr<Spremnik> DajKopiju() const=0;
};
class Sanduk:public Spremnik
{
    vector<double> v;
public:
    Sanduk(double tezina, string ime, const vector<double> &v):Spremnik(tezina,ime),v(v) {}
    double DajUkupnuTezinu() const {
        double suma=0;
        for(int i=0; i<v.size(); i++) {
            suma+=v[i];
        }
        return suma+tezina;
    }
    void Ispisi() const {
        cout<<"Vrsta spremnika: Sanduk\n"
            <<"Sadrzaj: "<<ime<<"\n"
            <<"Tezina predmeta: ";
        for(int i=0; i<v.size(); i++) {
            cout<<v[i]<<" ";
        }
        cout<<"(kg)\n"
            <<"Vlastita tezina: "<<DajTezinu()<<" (kg)\n"
            <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
    }
    shared_ptr<Spremnik> DajKopiju() const {
        return make_shared<Sanduk>(*this);
    }
};
class Bure:public Spremnik
{
    double ro, zapremina;
public:
    Bure(double tezina, string ime, double ro, double zapremina):Spremnik(tezina, ime),ro(ro),zapremina(zapremina) {}
    double DajUkupnuTezinu() const {
        return tezina+(zapremina/1000)*ro;
    }
    void Ispisi() const{
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
class Vreca:public Spremnik{
    double tezina1;
public:
    Vreca(double tezina, string ime, double tezina1):Spremnik(tezina,ime),tezina1(tezina1){}
    double DajUkupnuTezinu() const{
        return tezina1+tezina;
    }
    void Ispisi() const{
               cout<<"Vrsta spremnika: Vreca\n"
            <<"Sadrzaj: "<<ime<<"\n"
            <<"Vlastita tezina: "<<tezina<<" (kg)\n"
            <<"Tezina pohranjene materije: "<<tezina1<<" (kg/m^3)\n"
            <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    shared_ptr<Spremnik> DajKopiju() const{
        return make_shared<Vreca>(*this);
    }
    
};
int main ()
{
    return 0;
}
