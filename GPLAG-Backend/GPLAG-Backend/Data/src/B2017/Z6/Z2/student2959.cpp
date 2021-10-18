/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <memory>
#include <stdexcept>

class Spremnik
{
protected:
    std::string naziv;
    double vlastita_tezina;
public:
    Spremnik(double tezina, std::string ime): vlastita_tezina(tezina), naziv(ime) {};
    virtual ~Spremnik() {}
    virtual void Ispisi() const=0;
    double DajTezinu() const {
        return vlastita_tezina;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const =0;
};

class Sanduk: public Spremnik
{
    std::vector<double> tezine_predmeta;
public:
    Sanduk(double tezina, std::string ime, std::vector<double> v): Spremnik(tezina,ime),tezine_predmeta(v) {}
    double DajUkupnuTezinu() const override {
        double suma(vlastita_tezina);
        for(auto x:tezine_predmeta) suma+=x;
        return suma;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<
                 "Tezine predmeta: ";
        for(auto x:tezine_predmeta) std::cout<<x<<" ";
        std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<
                 "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk>(*this);
    }
};

class Vreca: public Spremnik
{
    double tezina_praska;
public:
    Vreca(double tezina, std::string ime, double tezina_materije): Spremnik(tezina,ime), tezina_praska(tezina_materije) {};
    double DajUkupnuTezinu() const override {
        return vlastita_tezina+tezina_praska;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<naziv<<
                 std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<
                 std::endl<<"Tezina pohranjene materije: "<<DajUkupnuTezinu()-DajTezinu()<<" (kg)"<<
                 std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca>(*this);
    }
};

class Bure: public Spremnik
{
    double gustina, zapremina;
public:
    Bure(double tezina, std::string ime, double sp_tezina, double V): Spremnik(tezina,ime), gustina(sp_tezina), zapremina(V) {}
    double DajUkupnuTezinu() const override {
        return vlastita_tezina+gustina*zapremina/1000;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<naziv<<
                 std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<
                 std::endl<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<
                 std::endl<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<
                 std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure>(*this);
    }
};

class PolimorfniSpremnik{
    std::shared_ptr<Spremnik> pok;
    void Test() const{
        if(!pok) throw std::logic_error("Nespecificiran spremnik");
    }
public:
	PolimorfniSpremnik():pok(nullptr){}
	~PolimorfniSpremnik(){}
	PolimorfniSpremnik(const Spremnik &s): pok(s.DajKopiju()){}
	PolimorfniSpremnik(const PolimorfniSpremnik &p){
	    if(!p.pok) pok=nullptr;
	    else pok=p.pok->DajKopiju();
	}
	PolimorfniSpremnik(PolimorfniSpremnik &&p){
	    pok=p.pok;
	    p.pok=nullptr;
	}
	PolimorfniSpremnik &operator=(const PolimorfniSpremnik &p){
	    std::shared_ptr<Spremnik> privremeni(nullptr);
	    if(p.pok!=nullptr) privremeni=p.pok->DajKopiju();
	    pok=nullptr;
	    pok=privremeni;
	    return *this;
	}
	PolimorfniSpremnik &operator =(PolimorfniSpremnik &&p){
	    std::swap(p.pok,pok);
	    return *this;
	}
    void Ispisi() const{
        Test();
        pok->Ispisi();
    }
    double DajTezinu() const{
        Test();
        return pok->DajTezinu();
    }
    double DajUkupnuTezinu() const{
        Test();
        return pok->DajUkupnuTezinu();
    }
};

int main ()
{
	return 0;
}
