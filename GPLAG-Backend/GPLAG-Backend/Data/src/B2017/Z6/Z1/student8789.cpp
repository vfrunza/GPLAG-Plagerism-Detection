/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <fstream>

#define Ulaz "ROBA.TXT"

class Spremnik{
protected:
    double tezina;
    std::string naziv;
public:
    Spremnik(double tezina, std::string naziv) : tezina(tezina), naziv(naziv){}
    virtual ~Spremnik(){}
    double DajTezinu() const{ return tezina; }
    virtual double DajUkupnuTezinu() const{ return 0;};
    virtual void Ispisi() const{};
    virtual Spremnik* DajKopiju() const = 0;
};

class Bure : public Spremnik{
    double specificnatezina, zapreminapohranjenetecnosti;
public:
    Bure(double tezina, std::string naziv, double specificnatezina, double zapreminapohranjenetecnosti) : Spremnik(tezina, naziv), specificnatezina(specificnatezina), zapreminapohranjenetecnosti(zapreminapohranjenetecnosti){}
    double DajUkupnuTezinu() const override{ return ((*this).DajTezinu() + 0.001 * zapreminapohranjenetecnosti * specificnatezina); }
    Spremnik* DajKopiju() const override{ return new Bure(*this); }
    void Ispisi() const override{
        std::cout << "Vrsta spremnika: " << "Bure" << std::endl << "Sadrzaj: " << naziv << std::endl << "Vlastita tezina: " << tezina << " (kg)" << std::endl << "Specificna tezina tecnosti: " << specificnatezina << " (kg/m^3)" << std::endl << "Zapremina tecnosti: " << zapreminapohranjenetecnosti << " (l)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
};

class Vreca : public Spremnik{
    double tezinapohranjenematerije;
public:
    Vreca(double tezina, std::string naziv, double tezinapohranjenematerije) : Spremnik(tezina, naziv), tezinapohranjenematerije(tezinapohranjenematerije){}
    double DajUkupnuTezinu() const override{ return ((*this).DajTezinu() + tezinapohranjenematerije); }
    Spremnik* DajKopiju() const override{ return new Vreca(*this); }
    void Ispisi() const override{
        std::cout << "Vrsta spremnika: " << "Vreca" << std::endl << "Sadrzaj: " << naziv << std::endl << "Vlastita tezina: " << tezina << " (kg)" << std::endl << "Tezina pohranjene materije: " << tezinapohranjenematerije << " (kg)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    
    
    
    
};

class Sanduk : public Spremnik{
    std::vector<double> tezine;
public:
    Sanduk(double tezina, std::string naziv, std::vector<double> tezine) : Spremnik(tezina, naziv), tezine(tezine){}
    double DajUkupnuTezinu() const override{
        double x = 0;
        for(auto i : tezine) x += i;
        return ((*this).DajTezinu() + x);
    }
    Spremnik* DajKopiju() const override{ return new Sanduk(*this); }
    void Ispisi() const override{
        std::cout << "Vrsta spremnika: " << "Sanduk" << std::endl << "Sadrzaj: " << naziv << std::endl << "Tezine predmeta: ";
        for(auto i : tezine) std::cout << i << " ";
        std::cout << "(kg)" << std::endl << "Vlastita tezina: " << tezina << " (kg)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
};

//bool Testni(Spremnik* prvi, Spremnik* drugi) { return (prvi->DajUkupnuTezinu() < drugi->DajUkupnuTezinu()); }


class Skladiste{
    std::vector<Spremnik*> vektor;
public:
    Skladiste(){}
    ~Skladiste(){
        for(auto i : vektor) delete i;
    }
    Spremnik* DodajVrecu(double tezina, std::string naziv, double tezinapohranjenematerije){
        Spremnik* p(new Vreca(tezina, naziv, tezinapohranjenematerije));
        vektor.push_back(p);
        return p;
    }
    Spremnik* DodajSanduk(double tezina, std::string naziv, std::vector<double> tezine){
        Spremnik* p(new Sanduk(tezina, naziv, tezine));
        vektor.push_back(p);
        return p;
    }
    Spremnik* DodajBure(double tezina, std::string naziv, double specificnatezina, double zapreminapohranjenetecnosti){
        Spremnik* p(new Bure(tezina, naziv, specificnatezina, zapreminapohranjenetecnosti));
        vektor.push_back(p);
        return p;
    }
    Spremnik* DodajSpremnik(Spremnik* novi, bool tacno){
        if(tacno){
            vektor.push_back(novi);
            return novi;
        }
        else{
            Spremnik* p;
            p = novi->DajKopiju();
            vektor.push_back(p);
            return p;
        }
    }
    void BrisiSpremnik(Spremnik* novi){
        for(int i = 0; i < vektor.size(); i++) if(vektor[i] == novi){
            delete vektor[i];
            vektor.erase(vektor.begin() + i);
        }
    }
    Spremnik& DajNajlaksi(){
        if(vektor.size() == 0) throw std::range_error("Skladiste je prazno");
        int indeks;
        double najmanji(999999999);
        for(int i = 0; i < vektor.size(); i++)
            if(vektor[i]->DajTezinu() < najmanji){
                najmanji = vektor[i]->DajTezinu();
                indeks = i;
            }
        return *vektor[indeks];
    }
    Spremnik& DajNajtezi(){
        if(vektor.size() == 0) throw std::range_error("Skladiste je prazno");
        int indeks;
        double najmanji(-999999999);
        for(int i = 0; i < vektor.size(); i++)
            if(vektor[i]->DajTezinu() > najmanji){
                najmanji = vektor[i]->DajTezinu();
                indeks = i;
            }
        return *vektor[indeks];
    }
    int BrojPreteskih(double nesto){
        int brojac(0);
        for(auto i : vektor) if(i->DajUkupnuTezinu() > nesto) brojac++;
        return brojac;
    }
    void IzlistajSkladiste(){
        std::sort(vektor.begin(), vektor.end(), [](Spremnik* prvi, Spremnik* drugi)
        {
            return prvi->DajUkupnuTezinu()>drugi->DajUkupnuTezinu();
        });
        for(auto i : vektor){
            if(i){
                i->Ispisi();
            }
        }
    }
    
    void UcitajIzDatoteke(std::string ime){
        if(vektor.size() != 0){
            for(int i = 0; i < vektor.size(); i++){
                if(vektor[i] == nullptr)
                    vektor.erase(vektor.begin() + i);
                else{
                    delete vektor[i];
                    vektor.erase(vektor.begin() + i);
                }
            }
        }
        std::fstream ulaz(ime, std::ios::in);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        
    }
};



int main ()
{
    

    return 0;
}
