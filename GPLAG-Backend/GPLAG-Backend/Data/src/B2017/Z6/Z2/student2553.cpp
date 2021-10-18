/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;


class Spremnik  // apstraktna nadklasa
{

  double tezina;

protected :
  std::string naziv_robe;


public:

  virtual ~Spremnik() {}

  Spremnik(double tezina, const std::string &naziv_robe) : tezina(tezina), naziv_robe(naziv_robe) {}

  double DajTezinu() const {
    return tezina;
  }
  virtual double DajUkupnuTezinu() const = 0;
  virtual void Ispisi() const = 0;

  virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;

};

//--------------------------------------------------------


class Sanduk : public Spremnik //naslijedjene klase...
{


  std::vector<double> tezine_predmeta;

public:

  Sanduk(double tezina_sanduka, const std::string &naziv_predmeta, const std::vector<double> &tezine_predmeta) : Spremnik(tezina_sanduka,naziv_predmeta), tezine_predmeta(tezine_predmeta) {}

  double DajUkupnuTezinu() const override {
    double ukupna_tezina_sanduka(DajTezinu());
    for (int i=0; i<tezine_predmeta.size(); i++) ukupna_tezina_sanduka+=tezine_predmeta.at(i);
    return ukupna_tezina_sanduka;
  }
  void Ispisi() const override {
    cout<<"Vrsta spremnika: Sanduk"<<endl<<"Sadrzaj: "<<naziv_robe<<endl<<"Tezine predmeta: ";
    for(int i=0; i<tezine_predmeta.size(); i++) cout<<tezine_predmeta.at(i)<<" ";
    cout<<"(kg)"<<endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;

  }

  virtual std::shared_ptr<Spremnik> DajKopiju() const override {
    return std::make_shared<Sanduk> (*this);
  }


};

class Vreca : public Spremnik
{


  double tezina_predmeta;

public:

  Vreca(double tezina_vrece, const std::string &naziv_predmeta, double tezina_predmeta) : Spremnik(tezina_vrece,naziv_predmeta), tezina_predmeta(tezina_predmeta) {}

  double DajUkupnuTezinu() const override {
    double ukupna_tezina_vrece(DajTezinu());
    ukupna_tezina_vrece+=tezina_predmeta;
    return ukupna_tezina_vrece;
  }
  void Ispisi() const override {
    cout<<"Vrsta spremnika: Vreca"<<endl<<"Sadrzaj: "<<naziv_robe<<endl;

    cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl<<"Tezina pohranjene materije: "<<tezina_predmeta<<" (kg)"<<endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;

  }

  virtual std::shared_ptr<Spremnik> DajKopiju() const override {
    return std::make_shared<Vreca> (*this);
  }


};

class Bure : public Spremnik
{

  double gustina_tecnosti;
  double zapremina_tecnosti;

public:

  Bure(double tezina_bureta, const std::string &naziv_tecnosti, double gustina_tecnosti, double zapremina_tecnosti) : Spremnik(tezina_bureta, naziv_tecnosti), gustina_tecnosti(gustina_tecnosti), zapremina_tecnosti(zapremina_tecnosti) {}

  double DajUkupnuTezinu() const override {
    double ukupna_tezina_bureta(DajTezinu());
    ukupna_tezina_bureta+=(gustina_tecnosti*zapremina_tecnosti*0.001);
    return ukupna_tezina_bureta;
  }
  void Ispisi() const override {
    cout<<"Vrsta spremnika: Bure"<<endl<<"Sadrzaj: "<<naziv_robe<<endl;

    cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl<<"Specificna tezina tecnosti: "<<gustina_tecnosti<<" (kg/m^3)"<<endl<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)"<<endl;
    cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;

  }

  virtual std::shared_ptr<Spremnik> DajKopiju() const override {
    return std::make_shared<Bure> (*this);
  }

};

//-----------------------------------------------------------


class PolimorfniSpremnik // surogatska klasa
{
    std::shared_ptr<Spremnik> pok_spremnik;
    
    void Test() const {
        if(!pok_spremnik) throw std::logic_error("Nespecificiran spremnik");
    }
    
public:
    PolimorfniSpremnik() : pok_spremnik(nullptr) {}
    ~PolimorfniSpremnik() { pok_spremnik=nullptr; }
    
    PolimorfniSpremnik(const Spremnik &spremnik) : pok_spremnik(spremnik.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &polimorfni_spremnik) {
        if(!polimorfni_spremnik.pok_spremnik) pok_spremnik = nullptr;
        else pok_spremnik = polimorfni_spremnik.pok_spremnik->DajKopiju();

    }
    PolimorfniSpremnik(PolimorfniSpremnik &&polimorfni_spremnik) {
        pok_spremnik = polimorfni_spremnik.pok_spremnik;
        polimorfni_spremnik.pok_spremnik = nullptr;

    }

    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &polimorfni_spremnik) {
        std::shared_ptr<Spremnik> pok_novi(nullptr);
        if(polimorfni_spremnik.pok_spremnik != nullptr) pok_novi = polimorfni_spremnik.pok_spremnik->DajKopiju();
        pok_spremnik=nullptr;
        pok_spremnik = pok_novi;
        return *this;
    }

    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&polimorfni_spremnik) {
        std::swap(pok_spremnik, polimorfni_spremnik.pok_spremnik);
        return *this;
    }

    double DajTezinu() const {
        Test();
        return pok_spremnik->DajTezinu();

    }

    double DajUkupnuTezinu() const {
        Test();
        return pok_spremnik->DajUkupnuTezinu();

    }

    void Ispisi() const {
        Test();
        pok_spremnik->Ispisi();

    }

};

//-----------------------------------------------------------


int main ()
{
    
    
    PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70));    // s1 je bure  
    PolimorfniSpremnik s2, s3;       // s2 i s3 su nespecificirani  
    s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});    // s2 je sada sanduk  
    s3 = Vreca(0.4, "Brasno", 30);      // a s3 vreca  
    cout << s1.DajTezinu() << endl;     
    cout << s2.DajUkupnuTezinu() <<endl;     
    s3.Ispisi();  
    s1 = s2;          // sad je i s1 sanduk...  
    s1.Ispisi(); 
 
 
    return 0;
}
