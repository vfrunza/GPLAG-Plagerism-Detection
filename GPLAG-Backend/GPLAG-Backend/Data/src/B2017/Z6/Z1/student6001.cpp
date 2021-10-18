/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <memory>

using namespace std;

class Spremnik {
    protected:
    
        double tezina_spremnika;
        string ime;
        
    public:
    
        Spremnik(double tezina_spremnika, string ime){
            Spremnik::tezina_spremnika=tezina_spremnika;
            Spremnik::ime=ime;
        }
        
        double DajTezinu() const{
            return tezina_spremnika;
        }
        virtual shared_ptr<Spremnik> DajKopiju() const = 0;
        virtual double DajUkupnuTezinu() const = 0;
        virtual void Ispisi() const = 0;
};

class Sanduk : public Spremnik {
    
    vector<double> tezina_predmeta;
    
public:

    Sanduk(double tezina_spremnika, string ime, vector<double> tezina_predmeta) : Spremnik(tezina_spremnika,ime){
        Sanduk::tezina_predmeta=tezina_predmeta;
    }
    
    double DajUkupnuTezinu() const override{
        double brojac(0);
        for(int i(0);i<tezina_predmeta.size();i++){
            brojac+=tezina_predmeta[i];
        }
        return tezina_spremnika+brojac;
    }
    
    shared_ptr<Spremnik> DajKopiju()const override{
        return make_shared<Sanduk>(*this);
    }
    
    void Ispisi() const override{
        cout<<"Vrsta spremnika: Sanduk"<<endl;
        cout<<"Sadrzaj: "<<ime<<endl;
        cout<<"Tezine predmeta: ";
        for(int i(0);i<tezina_predmeta.size();i++){
            cout<<tezina_predmeta[i]<<" ";
        }
        cout<<"(kg)"<<endl;
        cout<<"Vlastita tezina: "<<tezina_spremnika<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
};

class Vreca : public Spremnik{
    
    double tezina_materije;
    
public:

    Vreca(double tezina_spremnika, string ime, double tezina_materije) : Spremnik(tezina_spremnika, ime){
        Vreca::tezina_materije=tezina_materije;
    }
    
    double DajUkupnuTezinu() const override{
        return tezina_spremnika+tezina_materije;
    }
    
    shared_ptr <Spremnik> DajKopiju() const override{
        return  make_shared<Vreca>(*this);
    }
    
    void Ispisi() const override{
        cout<<"Vrsta spremnika: Vreca"<<endl;
        cout<<"Sadrzaj: "<<ime<<endl;
        cout<<"Vlastita tezina: "<<tezina_spremnika<<" (kg)"<<endl;
        cout<<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
};

class Bure : public Spremnik{
    
    double specificna_gustina, zapremina_tecnosti;
    
public:

    Bure(double tezina_spremnika, string ime, double specificna_gustina, double zapremina_tecnosti) : Spremnik(tezina_spremnika,ime){
        Bure::specificna_gustina=specificna_gustina;
        Bure::zapremina_tecnosti=zapremina_tecnosti;
    }

    double DajUkupnuTezinu() const override{
        return tezina_spremnika+(zapremina_tecnosti*0.001*specificna_gustina);
    }
    
    shared_ptr<Spremnik> DajKopiju() const override{
        return make_shared<Bure>(*this);
    }
    
    void Ispisi() const override{
        cout<<"Vrsta spremnika: Bure"<<endl;
        cout<<"Sadrzaj: "<<ime<<endl;
        cout<<"Vlastita tezina: "<<tezina_spremnika<<" (kg)"<<endl;
        cout<<"Specificna tezina tecnosti: "<<specificna_gustina<<" (kg/m^3)"<<endl;
        cout<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
    }
    
};

class Skladiste{
    
    vector<shared_ptr<Spremnik>> v;
    
public:

    Skladiste(){}
        
    Skladiste(const Skladiste &s){
        for ( int i(0);i<s.v.size();i++){
            v.push_back(s.v[i]->DajKopiju());
        }
    }
    
    Skladiste &operator=(const Skladiste &s){
        v.clear();
        for(int i(0);i<s.v.size();i++){
            v.push_back(s.v [i]->DajKopiju());
        }
        return *this;
    }
    
    ~Skladiste(){
        v.clear();
    }
    
    Spremnik *DodajSanduk(double tezinaa, string imee, vector<double> vv){
        Sanduk s(tezinaa, imee, vv);
        v.push_back(s.DajKopiju());
        return v[v.size()-1].get();
    }
    
    Spremnik *DodajVrecu(double tezinaa, string imee, double x){
        Vreca vv(tezinaa,imee,x);
        v.push_back(vv.DajKopiju());
        return v[v.size()-1].get();
    }
    
    Spremnik *DodajBure(double tezinaa, string imee, double gustina, double zapreminaa ){
        Bure b(tezinaa, imee, gustina, zapreminaa);
        v.push_back(b.DajKopiju());
        return v[v.size()-1].get();
    }
    
    Spremnik *DodajSpremnik(Spremnik *s,bool pom){
        if(pom==true){
            v.push_back(shared_ptr<Spremnik>(s));
            s=nullptr;
            return v[v.size()-1].get();
        }else{
            v.push_back(s->DajKopiju());
            return v[v.size()-1].get();
        }
    }
    
    void BrisiSpremnik(Spremnik *s){
        for(int i(0);i<v.size();i++){
            if(v[i].get()==s){
                v[i]=nullptr;
                v.erase(v.begin()+i);
                s=nullptr;
                break;
            }
        }
    }
    
    
    
};
int main ()
{
	return 0;
}
