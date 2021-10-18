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
    
    std::shared_ptr<Spremnik> DajKopiju()const override{
        return std::make_shared<Sanduk>(*this);
    }
    double DajUkupnuTezinu()const {
        double suma(0);
        for(auto x:tezine_predmeta) {
            suma+=x;
        }
        return tezina+suma;
    }
    void Ispisi()const {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(auto x:tezine_predmeta){std::cout<<x<<" ";}
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
    double DajUkupnuTezinu()const {
        return tezina+tezina_materije;
    }
    void Ispisi()const {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: "<<naziv<< std::endl;
        std::cout << "Vlastita tezina: " <<tezina<<" (kg)"<< std::endl;
        std::cout << "Tezina pohranjene materije: "<<tezina_materije <<" (kg)"<< std::endl;
        std::cout << "Ukupna tezina: " <<(*this).DajUkupnuTezinu()<<" (kg)"<< std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju()const override{
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
    std::shared_ptr<Spremnik> DajKopiju()const override{
        return std::make_shared<Bure>(*this);
    }
    double DajUkupnuTezinu()const {
        return tezina+(gustoca*zapremina*0.001);
    }
   
    void Ispisi()const {
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: " <<naziv<< std::endl;
        std::cout << "Vlastita tezina: " <<tezina<<" (kg)"<< std::endl;
        std::cout << "Specificna tezina tecnosti: " <<gustoca <<" (kg/m^3)"<<std::endl;
        std::cout << "Zapremina tecnosti: " <<zapremina<<" (l)"<< std::endl;
        std::cout << "Ukupna tezina: " <<(*this).DajUkupnuTezinu()<<" (kg)"<< std::endl;
    }
};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> v;
public:
    Skladiste(){}
    Skladiste(const Skladiste& s){
        v.resize(s.v.size());
        for(int i=0;i<v.size();i++){
            v[i]=(s.v[i]->DajKopiju()); 
        }
    }
    Skladiste(Skladiste&& s){
        v=std::move(s.v);
    }
    void operator=(const Skladiste& s){
        v.resize(s.v.size());
        for(int i=0;i<v.size();i++){
            v[i]=(s.v[i]->DajKopiju()); 
        }
    }
    void operator=(Skladiste&& s){
        v=std::move(s.v);
    }
    Spremnik* DodajSpremnik(Spremnik* pok,bool l){
        if(l==false){
            v.push_back(pok->DajKopiju());
            return v[v.size()-1].get();
        }else{
            std::shared_ptr<Spremnik> pomoc(pok);
            v.push_back(pomoc);
            return v[v.size()-1].get();
        }
    }
    Spremnik* DodajSanduk(double tezina1,std::string naziv1,std::vector<double> tezine_predmeta1) {
        v.push_back(std::make_shared<Sanduk> (tezina1,naziv1,tezine_predmeta1));
        return v[v.size()-1].get();
    }
    Spremnik* DodajVrecu(double tezina1,std::string naziv1,double tezina_materije1) {
        v.push_back(std::make_shared<Vreca>(tezina1,naziv1,tezina_materije1));
        return v[v.size()-1].get();
    }
    Spremnik* DodajBure(double tezina1,std::string naziv1,double gustoca1,double zapremina1) {
        v.push_back(std::make_shared<Bure>(tezina1,naziv1,gustoca1,zapremina1));
        return v[v.size()-1].get();
    }
    void BrisiSpremnik(Spremnik* adresa) {
        int i=0;
        for(auto x: v) {
            i++;
            if(x.get()==adresa) break;
        }
        v.erase(v.begin()+i);
    }
    Spremnik& DajNajlaksi()const {
        if(v.size()==0) throw std::range_error("Skladiste je prazno");
        auto it= std::min_element(v.begin(),v.end(),[](std::shared_ptr<Spremnik> p,std::shared_ptr<Spremnik> p1) {
            return (*p).DajTezinu()<(*p1).DajTezinu();
        });
        return **it;

    }
    Spremnik& DajNajtezi()const {
        if(v.size()==0) throw std::range_error("Skladiste je prazno");
        auto it= std::max_element(v.begin(),v.end(),[](std::shared_ptr<Spremnik> p,std::shared_ptr<Spremnik> p1) {
            return (*p).DajTezinu()<(*p1).DajTezinu();
        });
        return **it;
    }
    int BrojPreteskih(int granica) {
        return std::count_if(v.begin(),v.end(),[granica](std::shared_ptr<Spremnik> a) {
            return (*a).DajUkupnuTezinu()>granica;
        });
    }
    void IzlistajSkladiste()const {
        std::vector<std::shared_ptr<Spremnik>> pomoc=v;
        std::sort(pomoc.begin(),pomoc.end(),[](std::shared_ptr<Spremnik> p,std::shared_ptr<Spremnik> p1) {
            return (*p).DajUkupnuTezinu()>(*p1).DajUkupnuTezinu();
        });
        for(auto x:pomoc) {
            (*x).Ispisi();
        }
    }
    void UcitajIzDatoteke(std::string s) {
        v.resize(0);
        std::ifstream citam_iz_dat(s);
        for(int i=0; ;i++){
        if(!citam_iz_dat) throw std::logic_error("Trazena datoteka ne postoji");
        char znak;
        citam_iz_dat>>znak;
        if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        std::string naziv;
        std::getline(citam_iz_dat,naziv);
        if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        naziv.erase(naziv.begin()); //ZBOG RAZMAKA
        double tezina;
        citam_iz_dat>>tezina;
        if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        /*dok se za slučaj bureta nalazi težina bureta, te specifična težina i zapremina tečnosti (npr. “5 1300 150”).*/
        switch(znak) {
        case 'S': {
            int broj_predmeta;
            citam_iz_dat>>broj_predmeta;
            if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            std::vector<double> tezine_predmeta(broj_predmeta);
            for(int i=0;i<broj_predmeta;i++){
                citam_iz_dat>>tezine_predmeta[i];
                if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            (*this).DodajSanduk(tezina,naziv,tezine_predmeta);
            break;
        }
        case 'V': {
            double tezina_materije;
            citam_iz_dat>>tezina_materije;
            if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            (*this).DodajVrecu(tezina,naziv,tezina_materije);
            
            break;
        }
        case 'B': {
            double gustoca,zapremina;
            citam_iz_dat>>gustoca;
            if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            citam_iz_dat>>zapremina;
            if(!citam_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            (*this).DodajBure(tezina,naziv,gustoca,zapremina);
            break;
        }
        }
        if(citam_iz_dat.eof()) break;
    }
    }

};


int main ()
{

try {
Skladiste s;
s.UcitajIzDatoteke("ROBA.TXT");
s.IzlistajSkladiste();
}
catch (std::exception &e) {
    std::cout << e.what() << std::endl;
}



    return 0;
}
