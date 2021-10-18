/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
#include <new>
#include <vector>
#include <stdexcept>
#include <memory>
using namespace std;


class Spremnik{
    protected:
        double tezina;
        string naziv;
    public:
        Spremnik(double tezina, string naziv): tezina(tezina),naziv(naziv){}
        virtual~Spremnik() {}
        double DajTezinu() {return this->tezina;}
        virtual double DajUkupnuTezinu() const =0;
        virtual void Ispisi() const=0;
        virtual Spremnik* Kopija() const=0;
        
        
};  


class Sanduk: public Spremnik{
    vector<double> tezine;
    public:
        Sanduk(double tezina, string naziv, vector<double> tezine): Spremnik(tezina,naziv), tezine(tezine) {}
        double DajUkupnuTezinu() const override;
        void Ispisi() const override;
        Sanduk* Kopija() const override{
            return new Sanduk(*this);
        }
    
};
double Sanduk::DajUkupnuTezinu() const{
    double s(0);
    for(double x:tezine) s+=x;
    return this->tezina+s;
}
void Sanduk::Ispisi() const  {
    cout<<"Vrsta spremnika: Sanduk"<<endl<<"Sadrzaj: "<<this->naziv<<endl<<"Tezine predmeta: ";
    for(auto x:tezine) cout<<x<<" ";
    cout<<"(kg)"<<endl<<"Vlastita tezina: "<<this->tezina<<" (kg)"<<endl<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<endl;
}


class Vreca: public Spremnik{
    double tezina_praska;
    public:
        Vreca(double tezina, string naziv, double tezina_praska ): Spremnik(tezina,naziv),tezina_praska(tezina_praska) {}
        double DajUkupnuTezinu() const override {return tezina_praska+this->tezina;}
        void Ispisi() const override;
        Vreca* Kopija() const override{
            return new Vreca(*this);
        }
};
void Vreca::Ispisi() const{
    cout<<"Vrsta spremnika: Vreca"<<endl<<"Sadrzaj: "<<this->naziv<<endl<<"Vlastita tezina: "<<this->tezina<<" (kg)";
    cout<<endl<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<endl;
}


class Bure: public Spremnik{
    double gustina,zapremina;
    public:
        Bure(double tezina, string naziv, double gustina, double zapremina): Spremnik(tezina,naziv), gustina(gustina), zapremina(zapremina) {}
        double DajUkupnuTezinu() const override;
        void Ispisi() const override;
        Bure* Kopija() const override {
            return new Bure(*this);
        }
};
double Bure::DajUkupnuTezinu() const{
    double m(this->gustina * (this->zapremina)*1/1000);
    return this->tezina+m;
}
void Bure::Ispisi() const{
    cout<<"Vrsta spremnika: Bure"<<endl<<"Sadrzaj: "<<this->naziv<<endl<<"Vlastita tezina: "<<this->tezina<<" (kg)";
    cout<<endl<<"Specificna tezina tecnosti: "<<gustina<<"(kg/m^3)"<<endl<<"Zapremina tecnosti: "<<zapremina<<" (l)";
    cout<<endl<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<endl;
}



class Skladiste{
    vector<shared_ptr<Spremnik>> v;
    public:
        Skladiste(){}
        ~Skladiste() {
            for(int i=0;i<v.size();i++) v[i]=nullptr;
        };
        Skladiste(const Skladiste &s);
        Skladiste &operator=(const Skladiste &s);
        Spremnik* DodajSanduk(double tezina, string naziv, vector<double> tezine) { 
            auto a(new Sanduk(tezina,naziv,tezine));    v.push_back((shared_ptr<Spremnik>)a);  return a;
        }
        Spremnik* DodajVrecu(double tezina, string naziv, double tezina_praska ) {
            auto a(new Vreca(tezina,naziv,tezina_praska)); v.push_back((shared_ptr<Spremnik>)a);    return a;
        }
        Spremnik* DodajBure(double tezina, string naziv, double gustina, double zapremina){
            auto a(new Bure(tezina,naziv,gustina,zapremina)); v.push_back((shared_ptr<Spremnik>)a); return a;
        }
        Spremnik* DodajSpremnik(Spremnik* p, bool predaja);
        void BrisiSpremnik(Spremnik* p);
        Spremnik& DajNajlaksi() const;
        Spremnik& DajNajtezi() const;
        int BrojPreteskih(double max) const;
        void IzlistajSkladiste() const;
      //  void UcitajIzDatoteke(string datoteka);
      
};
Skladiste::Skladiste(const Skladiste &s) {
    for(int i=0;i<s.v.size();i++) {
        auto p(s.v[i]->Kopija());
        v.push_back((shared_ptr<Spremnik>)p);
    }
}
Skladiste &Skladiste::operator=(const Skladiste &s) {
    if(this==&s) return *this;
    v.resize(0);
    for(int i=0;i<s.v.size();i++) {
        auto p(s.v[i]->Kopija());
        v.push_back((shared_ptr<Spremnik>)p);
    }
    return *this;
}

/*Spremnik* Skladiste::DodajSpremnik(Spremnik*p ,bool predaja) {
    if(predaja) {
        v.push_back((shared_ptr<Spremnik>)p);
        return p;
    }
    if(!predaja) {
        Spremnik* pok=new Spremnik(*p);
        v.push_back ((shared_ptr<Spremnik>)pok);
        return pok;
    }
}
void Skladiste::BrisiSpremnik(Spremnik* p){
    
    v.erase(*p);
}

Spremnik &Skladiste::DajNajlaksi() const {
    if(v.size()==0) throw range_error("Skladiste je prazno");
    return *min_element(v.begin(), v.end(),[](Spremnik &a,Spremnik &b) {
        return a.DajTezinu()<b.DajTezinu();
    }
    );
}
Spremnik& Skladiste::DajNajtezi() const {
    if(v.size()==0) throw range_error("Skladiste je prazno");
    
}
*/
int Skladiste::BrojPreteskih(double max) const {
    int br(0);
    for(int i=0;i<v.size();i++) {
        if(v[i]->DajUkupnuTezinu()>max) br++;
    }
    return br;
}
void Skladiste::IzlistajSkladiste() const {
    /* auto v1(v);
    sort(v1.begin(),v1.end(),greater<Spremnik*>());
    for(auto x: v1) x->Ispisi(); */
}
/*void Skladiste::UcitajIzDatoteke(string Ime_dat) {
    ifstream dat(Ime_dat);
    if(!dat) throw logic_error("Trazena datoteka ne postoji");
    else {
        //if(v.size()!=0) obiris podatke?
        while(1) {
            string Znak, naziv;
            dat>>Znak>>naziv;
            if(dat.fail()) break;
            //Spremnik *S=nullptr;
            if(Znak=="S") {
                vector<double> tezine;
                double tezina, n(tezine.size());
                dat>>tezina>>n;
                for(int i=0; i<n;i++)
                    dat>>tezine[i];
                this->DodajSanduk(tezina,naziv,tezine);
            }
            else if (Znak=="V") {
                double tezina, tez_m;
                dat>>tezina>>tez_m;
                this->DodajVrecu(tezina,naziv,tez_m);
            }
            else if (Znak=="B") {
                double tezina, gustina, zapremina;
                dat>>tezina>>gustina>>zapremina;
                this->DodajBure(tezina,naziv,gustina,zapremina);
            }
        }
    }
    if(dat.bad()) throw logic_error("Problemi pri citanju datoteke");
    else if(dat.eof()==false) throw ("Datoteka sadrzi besmislene podatke");
}

*/
int main ()
{
    Skladiste s;
    try{
        Skladiste ETF;
        ETF.DodajSanduk(50, "Voce", {1,3,5,6});
        ETF.DodajVrecu(0.1, "Brasno", 25.5);
        ETF.DodajBure(5, "Krv", 1300, 150);
        Bure *b = new Bure(15, "Voda", 1000, 200);
        delete b;
        ETF.IzlistajSkladiste(); 
    }
    
    catch(range_error x) {
        cout<<x.what();
    }
    catch(logic_error x){
        cout<<x.what();
    }
    
	return 0;
}
