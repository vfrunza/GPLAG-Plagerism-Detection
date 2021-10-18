/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include<fstream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
#include<memory>

class Spremnik
{
protected:
    double tezina;
    std::string naziv;
public:
    double DajTezinu()const {
        return tezina;
    }
    virtual double DajUkupnuTezinu()const=0;
    virtual void Ispisi()const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju()const=0;
};
class Sanduk:public Spremnik
{
    std::vector<double> tezine_predmeta;
public:
    Sanduk(double tezina1,std::string naziv1,std::vector<double> tezine_predmeta1) {
        tezina=tezina1;
        naziv+=naziv1;
        tezine_predmeta=tezine_predmeta1;
    }

    std::shared_ptr<Spremnik> DajKopiju()const override {
        return std::make_shared<Sanduk>(*this);
    }
    double DajUkupnuTezinu()const override{
        double suma(0);
        for(auto x:tezine_predmeta) {
            suma+=x;
        }
        return tezina+suma;
    }
    void Ispisi()const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(auto x:tezine_predmeta) {
            std::cout<<x<<" ";
        }
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<(*this).DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
class Vreca:public Spremnik
{
    double tezina_materije;
public:
    Vreca(double tezina1,std::string naziv1,double tezina_materije1) {
        tezina=tezina1;
        naziv+=naziv1;
        tezina_materije=tezina_materije1;
    }
    double DajUkupnuTezinu()const override{
        return tezina+tezina_materije;
    }
    void Ispisi()const override{
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: "<<naziv<< std::endl;
        std::cout << "Vlastita tezina: " <<tezina<<" (kg)"<< std::endl;
        std::cout << "Tezina pohranjene materije: "<<tezina_materije <<" (kg)"<< std::endl;
        std::cout << "Ukupna tezina: " <<(*this).DajUkupnuTezinu()<<" (kg)"<< std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju()const override {
        return std::make_shared<Vreca>(*this);
    }
};

class Bure:public Spremnik
{
    double zapremina,gustoca;

public:
    Bure(double tezina1,std::string naziv1,double gustoca1,double zapremina1) {
        tezina=tezina1;
        zapremina=zapremina1;
        naziv+=naziv1;
        gustoca=gustoca1;
    }
    std::shared_ptr<Spremnik> DajKopiju()const override {
        return std::make_shared<Bure>(*this);
    }
    double DajUkupnuTezinu()const override{
        return tezina+(gustoca*zapremina*0.001);
    }

    void Ispisi()const override{
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: " <<naziv<< std::endl;
        std::cout << "Vlastita tezina: " <<tezina<<" (kg)"<< std::endl;
        std::cout << "Specificna tezina tecnosti: " <<gustoca <<" (kg/m^3)"<<std::endl;
        std::cout << "Zapremina tecnosti: " <<zapremina<<" (l)"<< std::endl;
        std::cout << "Ukupna tezina: " <<(*this).DajUkupnuTezinu()<<" (kg)"<< std::endl;
    }
};



class PolimorfniSpremnik
{
    std::shared_ptr<Spremnik> pok=nullptr;
   
public:
    PolimorfniSpremnik() {
        
    }
    PolimorfniSpremnik(Spremnik &s) {
        pok=s.DajKopiju();
    }
    PolimorfniSpremnik(Spremnik &&s) {
        pok=s.DajKopiju();
    }
    void operator=(Spremnik &s) {
        pok=s.DajKopiju();
    }
     void operator=(Spremnik &&s) {
        pok=s.DajKopiju();
    }
    double DajTezinu()const {
        if(pok==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return pok->DajTezinu();
    }
    double DajUkupnuTezinu()const {
        if(pok==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return pok->DajUkupnuTezinu();
    }
    void Ispisi()const {
        if(pok==nullptr) throw std::logic_error("Nespecificiran spremnik");
        pok->Ispisi();
    }
    std::shared_ptr<Spremnik> DajKopiju()const {
        if(pok==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return pok->DajKopiju();
    }

};



int main ()
{
PolimorfniSpremnik s1(Sanduk(3, "Svicevi :D", {5, 2, 3, 1, 7, 8}));
std::cout << s1.DajTezinu()  << std::endl << s1.DajUkupnuTezinu() << std::endl;
s1.Ispisi();
    return 0;
}
