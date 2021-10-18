/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <fstream>

class Spremnik
{
protected:
    double tezina;
    std::string ime_sadrzaja;
public:
    Spremnik (double tezina, std::string ime_sadrzaja) :
        tezina(tezina), ime_sadrzaja(ime_sadrzaja) {}
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const {
        std::cout << "Sadrzaj: " << ime_sadrzaja << std::endl;
    }
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;

};

typedef std::shared_ptr<Spremnik> PokNaSpremnik;

class Sanduk : public Spremnik
{
    std::vector<double> tezina_sadrzaja;
public:
    Sanduk(double tezina, std::string ime_sadrzaja, std::vector<double> tezina_sadrzaja) :
        Spremnik(tezina, ime_sadrzaja), tezina_sadrzaja(tezina_sadrzaja) {}
    double DajUkupnuTezinu() const override {
        double ukupna_tezina(tezina);
        for(auto e : tezina_sadrzaja) ukupna_tezina+=e;
        return ukupna_tezina;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        Spremnik::Ispisi();
        std::cout << "Tezine predmeta: ";
        for(auto e : tezina_sadrzaja)
            std::cout << e  << " ";
        std::cout << "(kg)" << std::endl;
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PokNaSpremnik DajKopiju() const {
        return std::make_shared<Sanduk>(*this);
    }
};

class Vreca : public Spremnik
{
    double tezina_sadrzaja;
public:
    Vreca(double tezina, std::string ime_sadrzaja, double tezina_sadrzaja) :
        Spremnik(tezina, ime_sadrzaja), tezina_sadrzaja(tezina_sadrzaja) {}
    double DajUkupnuTezinu() const override {
        return tezina + tezina_sadrzaja;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        Spremnik::Ispisi();
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Tezina pohranjene materije: " << tezina_sadrzaja << " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PokNaSpremnik DajKopiju() const {
        return std::make_shared<Vreca>(*this);
    }
};

class Bure : public Spremnik
{
    double gustina_sadrzaja, zapremina_sadrzaja;
public:
    Bure(double tezina, std::string ime_sadrzaja, double gustina_sadrzaja, double zapremina_sadrzaja):
        Spremnik(tezina, ime_sadrzaja), gustina_sadrzaja(gustina_sadrzaja), zapremina_sadrzaja(zapremina_sadrzaja) {}
    double DajUkupnuTezinu() const override {
        return tezina + gustina_sadrzaja * zapremina_sadrzaja/1000.;
    }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        Spremnik::Ispisi();
        std::cout << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: " << gustina_sadrzaja << " (kg/m^3)" << std::endl;
        std::cout << "Zapremina tecnosti: " << zapremina_sadrzaja << " (l)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    PokNaSpremnik DajKopiju() const {
        return std::make_shared<Bure>(*this);
    }
};



class PolimorfniSpremnik{
    PokNaSpremnik spremnik;
    public:
    PolimorfniSpremnik() : spremnik(nullptr){}
    PolimorfniSpremnik(Sanduk s){
        spremnik = s.DajKopiju();
    }
    PolimorfniSpremnik(Vreca s){
        spremnik = s.DajKopiju();
    }
    PolimorfniSpremnik(Bure s){
        spremnik = s.DajKopiju();
    }
    PolimorfniSpremnik(double tezina, std::string ime_sadrzaja, std::vector<double> tezina_sadrzaja){
        spremnik = std::make_shared<Sanduk>(tezina, ime_sadrzaja, tezina_sadrzaja);
    }
    PolimorfniSpremnik(double tezina, std::string ime_sadrzaja, double tezina_sadrzaja){
        spremnik = std::make_shared<Vreca>(tezina, ime_sadrzaja, tezina_sadrzaja);
    }
    PolimorfniSpremnik(double tezina, std::string ime_sadrzaja, double gustina_sadrzaja, double zapremina_sadrzaja){
        spremnik = std::make_shared<Bure>(tezina, ime_sadrzaja, gustina_sadrzaja, zapremina_sadrzaja);
    }
    PolimorfniSpremnik(const PolimorfniSpremnik &ps){
        spremnik = ps.spremnik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&ps){
        spremnik = ps.spremnik;
        ps.spremnik = nullptr;
    }
    PolimorfniSpremnik& operator = (const Sanduk& s){
        spremnik = s.DajKopiju();
        return *this;
    }
    PolimorfniSpremnik& operator = (const Vreca& s){
        spremnik = s.DajKopiju();
        return *this;
    }
    PolimorfniSpremnik& operator = (const Bure& s){
        spremnik = s.DajKopiju();
        return *this;
    }
    PolimorfniSpremnik& operator = (const PolimorfniSpremnik &ps){
        spremnik = ps.spremnik->DajKopiju();
        return *this;
    }
    PolimorfniSpremnik& operator = (PolimorfniSpremnik &&ps){
        spremnik = ps.spremnik;
        ps.spremnik = nullptr;
        return *this;
    }
    double DajTezinu(){
        if(spremnik == nullptr)
            throw std::logic_error ("Nespecificiran spremnik");
        return spremnik->DajTezinu();
    }
    double DajUkupnuTezinu(){
        if(spremnik == nullptr)
            throw std::logic_error ("Nespecificiran spremnik");
        return spremnik->DajUkupnuTezinu();
    }
    void Ispisi(){
        if(spremnik == nullptr)
            throw std::logic_error ("Nespecificiran spremnik");
        spremnik->Ispisi();
    }
    PokNaSpremnik DajKopiju() const {
        if(spremnik == nullptr)
            throw std::logic_error ("Nespecificiran spremnik"); 
        return spremnik->DajKopiju();
    }
    
};

int main ()
{
	return 0;
}
