/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class Spremnik{
    protected:  
    std::string vrsta;
    double tezina;
    std::string naziv_sadrzaja;
    public:
    virtual ~Spremnik(){}
    Spremnik(std::string vrsta, double tezina, std::string ime): vrsta(vrsta),tezina(tezina), naziv_sadrzaja(ime){}
    virtual double DajTezinu() const{return tezina;}
    virtual double DajUkupnuTezinu() const =0;
    virtual void Ispisi() const =0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
};
class Sanduk : public Spremnik{
  std::vector<double> tezine_sadrzaja;
  public:
  Sanduk(double t, std::string ime, std::vector<double> v): Spremnik("Sanduk", t, ime), tezine_sadrzaja(v){}
  double DajUkupnuTezinu()const override {
    double ukupna(this->DajTezinu()); 
    for(auto x: tezine_sadrzaja) ukupna+=x; return ukupna;
    }
  void Ispisi()const override {
    std::cout << "Vrsta spremnika: "<< vrsta << std::endl;
    std::cout << "Sadrzaj: "<< naziv_sadrzaja << std::endl;
    std::cout << "Tezine predmeta: "; for (auto x:tezine_sadrzaja) std::cout << x <<" "; std::cout << "(kg)" << std::endl;
    std::cout << "Vlastita tezina: " << this->DajTezinu() << " (kg)" << std::endl;
    std::cout << "Ukupna tezina: "<< this->DajUkupnuTezinu()<<" (kg)" << std::endl;
  }
  std::shared_ptr<Spremnik> DajKopiju() const override {return std::make_shared<Sanduk>(*this);}
};
class Vreca : public Spremnik{
  double tezina_materije;
  public:
  Vreca(double t, std::string ime, double tm):Spremnik("Vreca", t, ime), tezina_materije(tm){}
  double DajUkupnuTezinu()const override {return this->DajTezinu()+tezina_materije; }
  void Ispisi() const override{
    std::cout << "Vrsta spremnika: "<< vrsta << std::endl;
    std::cout << "Sadrzaj: "<< naziv_sadrzaja << std::endl;
    std::cout << "Vlastita tezina: " << this->DajTezinu() << " (kg)" << std::endl;
    std::cout << "Tezina pohranjene materije: "<<tezina_materije<<" (kg)" << std::endl;
    std::cout << "Ukupna tezina: "<< this->DajUkupnuTezinu()<<" (kg)" << std::endl;
  }
  std::shared_ptr<Spremnik> DajKopiju() const override {return std::make_shared<Vreca>(*this);}
};
class Bure : public Spremnik{
    double spec_tezina_tecnosti;
    double zapremina_tecnosti;
    public:
    Bure(double t, std::string ime, double stt, double zt): Spremnik("Bure", t, ime), spec_tezina_tecnosti(stt), zapremina_tecnosti(zt){}
    double DajUkupnuTezinu()const override{return this->DajTezinu()+(spec_tezina_tecnosti*(zapremina_tecnosti/1000.));}
  void Ispisi() const override{
    std::cout << "Vrsta spremnika: "<< vrsta << std::endl;
    std::cout << "Sadrzaj: "<< naziv_sadrzaja << std::endl;
    std::cout << "Vlastita tezina: " << this->DajTezinu() << " (kg)" << std::endl;
    std::cout << "Specificna tezina tecnosti: "<<spec_tezina_tecnosti<<" (kg/m^3)" << std::endl;
    std::cout << "Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)" << std::endl;
    std::cout << "Ukupna tezina: "<< this->DajUkupnuTezinu()<<" (kg)" << std::endl;
  }
  std::shared_ptr<Spremnik> DajKopiju() const override {return std::make_shared<Bure>(*this);}
};

class PolimorfniSpremnik{
  std::shared_ptr<Spremnik> p_spremnik;
  void Test() const {if (p_spremnik==nullptr) throw std::logic_error("Nespecificiran spremnik");}
  public:
  PolimorfniSpremnik():p_spremnik(nullptr){}
  ~PolimorfniSpremnik(){p_spremnik=nullptr;}
  PolimorfniSpremnik(const Spremnik &s): p_spremnik(s.DajKopiju()){}
  PolimorfniSpremnik(const PolimorfniSpremnik &s){
     // if(p_spremnik==nullptr) p_spremnik=nullptr;
       p_spremnik=s.p_spremnik->DajKopiju();
  }
  PolimorfniSpremnik(PolimorfniSpremnik &&s){
      p_spremnik=s.p_spremnik; s.p_spremnik=nullptr;
  }
  PolimorfniSpremnik &operator =(const PolimorfniSpremnik &s){
      std::shared_ptr<Spremnik> novi(nullptr);
      if(s.p_spremnik!=nullptr) novi=s.p_spremnik->DajKopiju();
      p_spremnik=nullptr;
      p_spremnik=novi;
      return *this;
  }
  PolimorfniSpremnik &operator =(PolimorfniSpremnik &&s){
      std::swap(s.p_spremnik, p_spremnik); 
      return*this;
  }
  double DajTezinu(){ Test();  return p_spremnik->DajTezinu();}
  double DajUkupnuTezinu(){ Test(); return p_spremnik->DajUkupnuTezinu();}
  void Ispisi(){Test(); return p_spremnik->Ispisi();}
  std::shared_ptr<Spremnik> DajKopiju(){Test(); return p_spremnik->DajKopiju();}
  
  
};
int main ()
{
  try{
  PolimorfniSpremnik s1(Bure(30,"Fanta", 700, 150));
PolimorfniSpremnik s2(s1);
s1.Ispisi();
s2.Ispisi();
Sanduk sanduk(15, "Lubenica", {5,5,7.5,8,10,12,11,5.8});
PolimorfniSpremnik s3(sanduk);
PolimorfniSpremnik s4=s3;
s3.Ispisi();
s4.Ispisi();
PolimorfniSpremnik s5;
s5.Ispisi();
}catch(std::logic_error g){
  std::cout << g.what() << std::endl;
}
	return 0;
}
