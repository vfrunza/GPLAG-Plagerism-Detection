/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>

class Spremnik{
    protected:  
    std::string vrsta;
    double tezina;
    std::string naziv_sadrzaja;
    public:
    virtual ~Spremnik(){}
    Spremnik(std::string vrsta, double tezina, std::string ime): vrsta(vrsta),tezina(tezina), naziv_sadrzaja(ime){}
   // virtual std::string DajVrstu() const {return vrsta;}
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

class Skladiste{
  std::vector<std::shared_ptr<Spremnik>> elementi;
  public:
  Skladiste()=default;
  ~Skladiste()=default;
  Skladiste(const Skladiste &s);
  Skladiste(Skladiste &&s);
  Skladiste &operator=(const Skladiste &s);
  Skladiste &operator=(Skladiste &&s);
  Spremnik* DodajSanduk(double t, std::string ime, std::vector<double> v);
  Spremnik* DodajVrecu(double t, std::string ime, double tm);
  Spremnik* DodajBure(double t, std::string ime, double stt, double zt);
  Spremnik* DodajSpremnik(Spremnik *s, bool predaja);
  void BrisiSpremnik(Spremnik *s);
  Spremnik& DajNajlaksi(){
    if(elementi.size()==0) throw std::range_error("Skladiste je prazno");
    return **std::min_element(elementi.begin(), elementi.end(),
  [](std::shared_ptr<Spremnik>p1, std::shared_ptr<Spremnik> p2){return p1->DajTezinu()<p2->DajTezinu();});};
  Spremnik& DajNajtezi(){
    if(elementi.size()==0) throw std::range_error("Skladiste je prazno");
    return **std::max_element(elementi.begin(), elementi.end(),
  [](std::shared_ptr<Spremnik>p1, std::shared_ptr<Spremnik> p2){return p1->DajTezinu()<p2->DajTezinu();});}
  int BrojPreteskih(double granica) const;
  void IzlistajSkladiste() const;
  void UcitajIzDatoteke(const char ime_datoteke[]);
};

  Skladiste::Skladiste(const Skladiste &s):elementi(s.elementi.size()){
   for(int i=0;i<elementi.size();i++) elementi[i]=s.elementi[i]->DajKopiju();
 }
  Skladiste::Skladiste(Skladiste &&s):elementi(s.elementi.size()){
      for(int i=0;i<elementi.size();i++) elementi[i]=s.elementi[i]->DajKopiju();
 }
  Skladiste &Skladiste::operator=(const Skladiste &s){
    if(&s==this) return *this;
    for(int i=0;i<elementi.size();i++) elementi[i]=nullptr;
    elementi.resize(s.elementi.size());
    for(int i=0;i<elementi.size();i++) elementi[i]=s.elementi[i]->DajKopiju();
    return *this;
  }
  Skladiste &Skladiste::operator=(Skladiste &&s){
    if(&s==this) return *this;
    for(int i=0;i<elementi.size();i++) elementi[i]=nullptr;
    elementi=s.elementi;
    return *this;
  }
  
  Spremnik* Skladiste::DodajSanduk(double t, std::string ime, std::vector<double> v){
    std::shared_ptr<Spremnik> novi;
    novi=std::make_shared<Sanduk>(t,ime,v);
    elementi.push_back(novi);
    return novi.get();
  }
  Spremnik* Skladiste::DodajVrecu(double t, std::string ime, double tm){
    std::shared_ptr<Spremnik> novi;
    novi=std::make_shared<Vreca>(t,ime,tm);
    elementi.push_back(novi);
    return novi.get(); 
  }
  Spremnik* Skladiste::DodajBure(double t, std::string ime, double stt, double zt){
    std::shared_ptr<Spremnik> novi;
    novi=std::make_shared<Bure>(t,ime,stt,zt);
    elementi.push_back(novi);
    return novi.get();
  }
  Spremnik* Skladiste::DodajSpremnik(Spremnik *s, bool predaja){
    if(predaja){
      std::shared_ptr<Spremnik> novi(s);
      elementi.push_back(novi);
      return novi.get();
    }
    else {
      std::shared_ptr<Spremnik> novi;
      novi=s->DajKopiju();
      elementi.push_back(novi);
      return novi.get();
    }
  }
  
  void Skladiste::BrisiSpremnik(Spremnik *s){
    for(int i(0);i<elementi.size();i++)
      if(elementi[i].get()==s) {
        elementi[i]==nullptr; 
        elementi.erase(elementi.begin()+i);
      }
  }
  
  int Skladiste::BrojPreteskih(double granica)const{
    int br(0);
    for(int i=0;i<elementi.size();i++) 
    if(elementi[i]->DajUkupnuTezinu()>granica) br++;
    return br;
  }
  
  void Skladiste::IzlistajSkladiste() const {
    std::vector<std::shared_ptr<Spremnik>> pomocni(elementi.size());
    std::copy(elementi.begin(), elementi.end(), pomocni.begin());
    std::sort(pomocni.begin(), pomocni.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2){
      return p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu();
    });
    for(int i(0);i<pomocni.size();i++) pomocni[i]->Ispisi();
  }
  
  void Skladiste::UcitajIzDatoteke(const char ime_datoteke[]){
    for(int i(0);i<elementi.size();i++) elementi[i]=nullptr;
    elementi.resize(0);
    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) throw std::logic_error ("Trazena datoteka ne postoji");
    char c;
    for(;;){
      ulazni_tok>>c;
      if(c=='S'){
        std::string ime; char pomoc;
        pomoc=ulazni_tok.get();
        std::getline(ulazni_tok, ime);
        double t, x;
        int n;
        ulazni_tok>>t>>n;
        std::vector<double> tezine;
        for(int i(0);i<n;i++){
          ulazni_tok>>x;
          tezine.push_back(x);
        }
        this->DodajSanduk(t,ime,tezine);
        pomoc=ulazni_tok.get(); if(pomoc!='\n' && !ulazni_tok.eof()) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
      }
      else if (c=='V'){
        std::string ime; char pomoc;
        pomoc=ulazni_tok.get();
        std::getline(ulazni_tok, ime);
        double t, t_materije;
        ulazni_tok>>t>>t_materije;
        this->DodajVrecu(t,ime,t_materije);
        pomoc=ulazni_tok.get(); if(pomoc!='\n' && !ulazni_tok.eof()) throw std::logic_error ("Datoteka sadrzi besmislene podatke");

      }
      else if(c=='B'){
        std::string ime; char pomoc;
        pomoc=ulazni_tok.get();
        std::getline(ulazni_tok, ime);
        double t, tezina, zapremina;
        ulazni_tok>>t>>tezina>>zapremina;
        this->DodajBure(t,ime,tezina,zapremina);
        pomoc=ulazni_tok.get(); if(pomoc!='\n' && !ulazni_tok.eof()) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
      }
      else throw std::logic_error ("Datoteka sadrzi besmislene podatke");
      if(!ulazni_tok) break;
    } 
    if(ulazni_tok.eof()) return;
      else if(ulazni_tok.bad()) throw std::logic_error ("Problemi pri citanju datoteke");
        else throw std::logic_error ("Datoteka sadrzi besmislene podatke");
  }
int main ()
{
  try{
    Skladiste S;
    S.UcitajIzDatoteke("ROBA.TXT");
    S.IzlistajSkladiste();
  }
  catch(std::logic_error gr){
    std::cout << gr.what() << std::endl;
  }
  catch(std::range_error gr){
  std::cout << gr.what() << std::endl;
  }
	return 0;
}
