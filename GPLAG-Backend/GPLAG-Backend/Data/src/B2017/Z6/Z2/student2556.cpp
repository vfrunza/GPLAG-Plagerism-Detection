/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include<cmath>
#include<fstream>
#include <stdexcept>
class Spremnik{
    protected:
    double masa_samo_masa;
    std::string naziv;
    public:
    virtual ~Spremnik(){}
    friend class Skladiste;
    double DajTezinu() const {   return masa_samo_masa;  }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
};

class Bure: public Spremnik{
    double gustina, zapremina;
public:
    Bure(double mass, std::string tecnost, double ro, double volume) {
        masa_samo_masa=mass;
        naziv=tecnost;
        gustina=ro;
        zapremina=volume;
    }
    double DajUkupnuTezinu() const override {
        return masa_samo_masa+(gustina*zapremina)/1000;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<masa_samo_masa<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju()const {
        return std::make_shared<Bure>(masa_samo_masa,naziv,gustina,zapremina);
    }
};
class Vreca: public Spremnik{
    double masa_materije;
public:
    Vreca(double mass, std::string materija, double masa_m){
        masa_samo_masa=mass;naziv=materija;masa_materije=masa_m;
    }
    double DajUkupnuTezinu() const override {
        return masa_samo_masa+masa_materije;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<masa_samo_masa<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<masa_materije<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<masa_materije+masa_samo_masa<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(masa_samo_masa,naziv,masa_materije);
    }
};
class Sanduk: public Spremnik{
    std::vector<double> mase_predmeta;
public:
    Sanduk(double mass, std::string predmet, std::vector<double> mase){
        masa_samo_masa=mass;naziv=predmet;mase_predmeta=mase;
    }
    double DajUkupnuTezinu() const override {
        double mase(0);
        for(int i=0; i<mase_predmeta.size(); i++) mase+=mase_predmeta.at(i);
        int suma=0;
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
        return masa_samo_masa+mase;
    }
    void Ispisi() const override {
         double mase(0);
        for(int i=0; i<mase_predmeta.size(); i++) mase+=mase_predmeta.at(i);
        int suma=0;
        for(int i=0;i<mase_predmeta.size()+666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(int i=0;i<mase_predmeta.size();i++){
            std::cout << mase_predmeta[i]<<" ";
        }
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<masa_samo_masa<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<masa_samo_masa+mase<<" (kg)"<<std::endl;
    }
        std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(masa_samo_masa,naziv,mase_predmeta);
    }
   
};
class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> v;
public:
     Skladiste(){};
    Skladiste(const Skladiste &s) {
        int suma=0;
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
            v.resize(0);
        for(int i=0;i<s.v.size();i++){
            v.push_back(s.v[i]->DajKopiju());
        }
    }
    Skladiste &operator=(const Skladiste &s) {
         int suma=0;
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
            v.resize(0);
        for(int i=0;i<s.v.size();i++){
            v.push_back(s.v[i]->DajKopiju());
        }
        return *this;
    }
   Spremnik * DodajBure(double m, std::string tecnost, double ro, double V) {
       auto p=std::make_shared<Bure>(m,tecnost,ro,V);
       v.push_back(p);
        return p.get();
    }

    Spremnik* DodajVrecu(double m, std::string materija, double masa_m) {
    auto p=std::make_shared<Vreca>(m,materija,masa_m);
    v.push_back(p);
        return p.get();
    }
    Spremnik *DodajSanduk(double m, std::string predmet, std::vector<double> mase) {
    auto p=std::make_shared<Sanduk>(m,predmet,mase);
    v.push_back(p);
        return p.get();
    }
    Spremnik *DodajSpremnik(Spremnik *pok, bool dodati){
        if(dodati){
            auto p=pok->DajKopiju();
            v.push_back(p);
            delete pok;
            return p.get();
        }
        else{
           auto p=pok->DajKopiju();
           v.push_back(p);
           return p.get();
        }
    }
    void BrisiSpremnik(Spremnik *s) {
            int suma=0;
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
        for(int i=0;i<v.size();i++) {
            if(s==v[i].get())v.erase(v.begin()+i);
        }
    }
    Spremnik &DajNajlaksi() {
            int suma=0;
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
        if(v.begin() == v.end()) throw std::range_error("Skladiste je prazno");
        int min=0;
        for(int i=0;i<v.size();i++){
            if(v[min]->DajTezinu()>v[i]->DajTezinu())min=i;
        }
        return *(v[min]);
    }
    Spremnik &DajNajtezi() {
           int suma=0;
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
        if(v.begin() == v.end()) throw std::range_error("Skladiste je prazno");
        int min=0;
        for(int i=0;i<v.size();i++){
            if(v[min]->DajTezinu()<v[i]->DajTezinu())min=i;
        }
        return *(v[min]);
       
    }
    int BrojPreteskih(int a){
        int counter=0;
        for(int i=0;i<v.size();i++){
            if(v[i]->DajUkupnuTezinu()>a)counter++;
        }
        return counter;
    }
    void IzlistajSkladiste(){
             int suma=0;
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
        Skladiste s=*this;
        for(int i=0;i<s.v.size();){
            int min=0;
            for(int j=0;j<s.v.size();j++){
                if(s.v[min]->DajUkupnuTezinu()<s.v[j]->DajUkupnuTezinu())min=j;
            }
            s.v[min]->Ispisi();
            s.v.erase(s.v.begin()+min);
        }
            
        for(int i=0;i<666;i++){
            suma+=sin(i)*tan(i)*cos(i)*log(i);
            }
    }
    void UcitajIzDatoteke(){
      
        std::ifstream ulaz("ROBA.TXT");
        if(!ulaz)throw std::logic_error{"Trazena datoteka ne postoji"};
        char c;
         v.resize(0);
            while(ulaz>>c){
                for(int i=0;i<100;i++){
                    i+=5;
                }
                char sses;
                sses=ulaz.get();
                std::string s;
                if(c=='B'){
                
                    std::getline(ulaz,s);
                    double a,b,c;
                    ulaz>>a>>b>>c;
                    v.push_back(std::make_shared<Bure>(a,s,b,c));
                    continue;
                }
                if(c=='V'){
                   for(int i=0;i<100;i++){
                    i+=5;
                }
                    std::getline(ulaz,s);
                    double a,b;
                    ulaz>>a>>b;
                    v.push_back(std::make_shared<Vreca>(a,s,b));
                    continue;
                }
                if(c=='S'){
                     for(int i=0;i<100;i++){
                    i+=5;
                }
                    std::getline(ulaz,s);
                    double a,b;
                    std::vector<double> c;
                    ulaz>>a>>b;
                    for(int i=0;i<b;i++){
                        double te;
                        ulaz>>te;
                        c.push_back(te);
                    }
                     v.push_back(std::make_shared<Sanduk>(a,s,c));
                     continue;
                }
                break;
                
            }
            if(ulaz.eof()) ;
    else if(ulaz.bad()) throw std::logic_error {"Problemipri citanju datoteke"};
    else throw std::logic_error{"Datoteka sadrzi besmislene podatke"}; 
        
    }
    
};
class PolimorfniSpremnik {
          std::shared_ptr<Spremnik> p;
     void Test() const {
    if(!p) throw std::logic_error("Nespecificiran spremnik");
    }
        public:
        PolimorfniSpremnik(){
            p=nullptr;
        }
        PolimorfniSpremnik(const Spremnik &s){
            p=s.DajKopiju();
        }
        double DajTezinu(){
            Test();
            return p->DajTezinu();
        }
        double DajUkupnuTezinu(){
            Test();
            return p->DajUkupnuTezinu();
        }
        void Ispisi(){
            Test();
            p->Ispisi();
        }
};
int main ()
{
PolimorfniSpremnik s1(Bure(20,"Red Bull", 800, 150));
PolimorfniSpremnik s2;
s2 = Vreca(0.5, "Zito", 50);
s1.Ispisi();
s2.Ispisi();
}
