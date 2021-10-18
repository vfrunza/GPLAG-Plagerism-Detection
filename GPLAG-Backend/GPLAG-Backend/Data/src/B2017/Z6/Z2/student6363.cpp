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

class PolimorfniSpremnik {
    shared_ptr<Spremnik> s=nullptr;
    void Test() const {
        if(s==nullptr) throw std::logic_error("Nespecificiran spremnik");
    }
    public:
    PolimorfniSpremnik() {}
    PolimorfniSpremnik(const Spremnik &s1){
        s=s1.DajKopiju();
    }
    
    PolimorfniSpremnik(const PolimorfniSpremnik &s1) {
        if(!s1.s) s=nullptr;
        else s=s1.s->DajKopiju();
    }
    
    PolimorfniSpremnik(PolimorfniSpremnik &&s1) {
        s=s1.s;
        s1.s=nullptr;
    }
    
    PolimorfniSpremnik & operator = (const Spremnik &s1){
        s=s1.DajKopiju();
        return *this;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &s1) {
        if(this!=&s1){
        shared_ptr<Spremnik> s_novi(nullptr);
        if(s1.s!=nullptr) s_novi=s1.s->DajKopiju();
        s=s_novi;}
        return *this;
    }
    
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&s1) {
        if(this!=&s1){
        s=s1.s; 
        s1.s=nullptr;}
        return *this;
    }
    
    double DajTezinu() const {
        Test();
        return s->DajTezinu();
    }
    
    double DajUkupnuTezinu() const  {
        Test();
        return s->DajUkupnuTezinu();
    }
    
    void Ispisi() const {
        Test();
        s->Ispisi();
    }

    ~PolimorfniSpremnik(){
    }
};

int main ()
{
	return 0;
}