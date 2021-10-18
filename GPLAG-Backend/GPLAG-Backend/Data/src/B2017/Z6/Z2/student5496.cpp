/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
//apstraktna klasa
class Spremnik{
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(double tezina, std::string naziv):tezina(tezina),naziv(naziv){}
    virtual ~Spremnik(){}
    double DajTezinu() const{ return this->tezina;}
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual std::shared_ptr<Spremnik> DajKopiju()  const= 0;
    
};
class Sanduk : public Spremnik{
    std::vector<double> tezine_p;
    
    public:
    Sanduk(double tezina, std::string naziv, std::vector<double> tezine_predmeta):Spremnik(tezina,naziv){
        tezine_p.resize(tezine_predmeta.size());
        for(int i=0; i<tezine_predmeta.size(); i++)
        tezine_p[i]=tezine_predmeta[i];
    }
    double DajUkupnuTezinu() const override{
        double u_tezina(0);
        for(int i=0; i<tezine_p.size(); i++){
            u_tezina+=tezine_p[i];
        }
        return this->tezina+u_tezina;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<this->naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(int i=0; i<tezine_p.size(); i++) std::cout<<tezine_p[i]<<" ";
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<this->DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override{
        std::shared_ptr<Sanduk> s;
        s=std::make_shared<Sanduk>(this->tezina,this->naziv,this->tezine_p);
        return s;
    }
};
class Vreca : public Spremnik{
    double tezina_p;
    public:
    Vreca(double tezina, std::string naziv, double tezina_pr):Spremnik(tezina,naziv), tezina_p(tezina_pr){}
    double DajUkupnuTezinu() const override{
        return this->tezina+tezina_p;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<this->naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<this->DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<this->tezina_p<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override{
        return std::make_shared<Vreca>(*this);
    }
};
class Bure : public Spremnik{
    double spec_t, zapremina;
    public:
    Bure(double tezina, std::string naziv, double spec_t, double zapremina):
    Spremnik(tezina,naziv), spec_t(spec_t),zapremina(zapremina){}
    double DajUkupnuTezinu() const override{
        return this->tezina+(spec_t*(double(zapremina)/1000.));
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<this->naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<this->DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<this->spec_t<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<this->zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override{
        return std::make_shared<Bure>(*this);
    }
};
class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> skladiste;
    public:
    Skladiste(){}
    ~Skladiste(){}
    Skladiste(const Skladiste &s);
    Skladiste &operator=(const Skladiste &s);
    Skladiste(Skladiste &&s) = default;
    Skladiste &operator=(Skladiste &&s) = default;
    Spremnik* DodajSanduk(double tezina, std::string naziv, std::vector<double> tezine_predmeta);
    Spremnik* DodajVrecu(double tezina, std::string naziv, double tezina_pr);
    Spremnik* DodajBure(double tezina, std::string naziv, double spec_t, double zapremina);
    Spremnik* DodajSpremnik(Spremnik* s, bool x);
    void BrisiSpremnik(Spremnik* nesto);
    Spremnik &DajNajlaksi();
    Spremnik &DajNajtezi();
    int BrojPreteskih(double n) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const char *c);
};
Skladiste::Skladiste(const Skladiste &s){
    skladiste.resize(s.skladiste.size());
    for(int i=0; i<s.skladiste.size(); i++)
    skladiste[i]=s.skladiste[i]->DajKopiju();
}
Skladiste &Skladiste::operator=(const Skladiste &s){
    if(&s!=this){
        for(int i=0; i<skladiste.size(); i++) skladiste[i]=nullptr;
        skladiste.resize(s.skladiste.size());
        for(int i=0; i<s.skladiste.size(); i++) skladiste[i]=s.skladiste[i]->DajKopiju();
    }
    return *this;
}
Spremnik* Skladiste::DodajSanduk(double tezina, std::string naziv, std::vector<double> tezine_predmeta){
    std::shared_ptr<Spremnik> p(std::make_shared<Sanduk>(tezina,naziv,tezine_predmeta));
    skladiste.push_back(p);
    return p.get();
}
Spremnik* Skladiste::DodajVrecu(double tezina, std::string naziv, double tezina_pr){
    std::shared_ptr<Spremnik> p(std::make_shared<Vreca>(tezina,naziv,tezina_pr));
    skladiste.push_back(p);
    return p.get();
}
Spremnik* Skladiste::DodajBure(double tezina, std::string naziv, double spec_t, double zapremina){
    std::shared_ptr<Spremnik> p(std::make_shared<Bure>(tezina,naziv,spec_t,zapremina));
    skladiste.push_back(p);
    return p.get();
}
Spremnik* Skladiste::DodajSpremnik(Spremnik *s, bool x){
    std::shared_ptr<Spremnik> p;
    if(typeid(*s)==typeid(Sanduk)){
        p=static_cast<Sanduk*>(s)->DajKopiju();
        if(x) delete s;
        skladiste.push_back(p);
        return p.get();
    }
    else if(typeid(*s)==typeid(Vreca)){
        p=static_cast<Vreca*>(s)->DajKopiju();
        if(x) delete s;
        skladiste.push_back(p);
        return p.get();
    }
    else if(typeid(*s)==typeid(Bure)){
        p=static_cast<Bure*>(s)->DajKopiju();
        if(x) delete s;
        skladiste.push_back(p);
        return p.get();
    }
}
void Skladiste::BrisiSpremnik(Spremnik *nesto){
    for(int i=0; i<skladiste.size(); i++){
        if(skladiste[i].get()==nesto) {
            skladiste.erase(skladiste.begin()+i);
        }
    }
}
Spremnik &Skladiste::DajNajtezi(){
    if(skladiste.size()==0) throw std::range_error("Skladiste je prazno");
    Spremnik *maks(skladiste[0].get());
    int indeks(0);
    for(int i=0; i<skladiste.size(); i++){
        if(skladiste[i].get()->DajTezinu() > maks->DajTezinu()){
            maks=(skladiste[i].get());
            indeks=i;
        }
    }
    return *(skladiste[indeks].get());
}
Spremnik &Skladiste::DajNajlaksi(){
    if(skladiste.size()==0) throw std::range_error("Skladiste je prazno");
    Spremnik *min(skladiste[0].get());
    int indeks(0);
    for(int i=0; i<skladiste.size(); i++){
        if(skladiste[i].get()->DajTezinu() < min->DajTezinu()){
            min=(skladiste[i].get());
            indeks=i;
        }
    }
    return *(skladiste[indeks].get());
}
int Skladiste::BrojPreteskih(double n) const{
    int brojac(0);
    for(int i=0; i<skladiste.size(); i++){
        if(skladiste[i].get()->DajUkupnuTezinu() > n) brojac++;
    }
    return brojac;
}

void Skladiste::IzlistajSkladiste() const{
    std::vector<std::shared_ptr<Spremnik>> pom(skladiste);
   std::sort(pom.begin(), pom.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b)->bool{
        return (a->DajUkupnuTezinu()>b->DajUkupnuTezinu());
    });
    for(int i=0; i<pom.size(); i++){
        pom[i].get()->Ispisi();
        std::cout<<std::endl;
    }
}
void Skladiste::UcitajIzDatoteke(const char *c){
    std::string s(c);
    std::ifstream ulazni_tok(s);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    for(;;){
        char ime[25];
        char znak;
        /*if(!ulazni_tok){
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
            break;
        }*/
        ulazni_tok>>znak;
        ulazni_tok.getline(ime, sizeof ime);
        ulazni_tok.ignore(1000,'\n');
        if(znak=='V'){
            char znak1;
            double tezina, tezina_predmeta;
            ulazni_tok>>tezina>>znak1>>tezina_predmeta;
            if(!ulazni_tok || znak1!=' ') {
                throw std::logic_error("Datoteka sadrzi besmislene podatke"); break;}
            ulazni_tok.ignore(1000,'\n');
            this->DodajVrecu(tezina,ime,tezina_predmeta);
        }
        else if(znak=='B'){
            char znak1,znak2;
            double tezina,spec_t,zapremina;
            ulazni_tok>>tezina>>znak1>>spec_t>>znak2>>zapremina;
            if(!ulazni_tok || znak1!=' ' || znak2!=' ') {
                throw std::logic_error("Datoteka sadrzi besmislene podatke"); break;}
            ulazni_tok.ignore(1000,'\n');
            this->DodajBure(tezina,ime,spec_t,zapremina);
        }
        else if(znak=='S'){
            double tezina, broj_predmeta;
            char znak1, znak2;
            std::vector<double> tezine_predmeta;
            ulazni_tok>>tezina>>znak1>>broj_predmeta>>znak2;
            if(!ulazni_tok || znak1!=' ' || znak2!=' ') {
                throw std::logic_error("Datoteka sadrzi besmislene podatke"); break;}
            for(int i=0; i<broj_predmeta; i++){
                double x;
                char znak3;
                ulazni_tok>>x>>znak3;
                if(!ulazni_tok || znak3!=' ') {
                throw std::logic_error("Datoteka sadrzi besmislene podatke"); break;}
                tezine_predmeta.push_back(x);
            }
            this->DodajSanduk(tezina,ime,tezine_predmeta);
        }
    }
}
//surogat klasa
class PolimorfniSpremnik{
  std::shared_ptr<Spremnik> p_spremnik;
  void Test() const{
      if(!p_spremnik) throw std::logic_error("Nespecificiran spremnik");
  }
  public:
  PolimorfniSpremnik(): p_spremnik(nullptr){}
  ~PolimorfniSpremnik(){}
  PolimorfniSpremnik(const Spremnik &spremnik):p_spremnik(spremnik.DajKopiju()) {}
  PolimorfniSpremnik(const PolimorfniSpremnik &spremnik){
      if(!spremnik.p_spremnik) p_spremnik=nullptr;
      else p_spremnik=spremnik.p_spremnik->DajKopiju();
  }
  PolimorfniSpremnik(PolimorfniSpremnik &&spremnik){
      p_spremnik=spremnik.p_spremnik;
      spremnik.p_spremnik=nullptr;
  }
  PolimorfniSpremnik &operator =(const PolimorfniSpremnik &spremnik){
      std::shared_ptr<Spremnik> p_novi(nullptr);
      if(spremnik.p_spremnik!=nullptr) p_novi=spremnik.p_spremnik->DajKopiju();
      p_spremnik=nullptr; 
      p_spremnik=p_novi;
      return *this;
  }
  PolimorfniSpremnik &operator =(PolimorfniSpremnik &&spremnik){
      std::swap(p_spremnik,spremnik.p_spremnik);
      return *this;
  }
  double DajTezinu() const{ Test(); return p_spremnik->DajTezinu(); }
  double DajUkupnuTezinu() const {Test(); return p_spremnik->DajUkupnuTezinu();}
  void Ispisi() const{ Test(); p_spremnik->Ispisi();}
};
int main ()
{
    try
    {

        PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70));
        PolimorfniSpremnik s2, s3, s4;
        s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});
        s3 = Vreca(0.1, "Patak", 15.5);
        std::cout << s1.DajTezinu() << std::endl;
        std::cout << s2.DajUkupnuTezinu() << std::endl;
        s3.Ispisi();
        s1 = s2;
        s1.Ispisi();
        s4.DajTezinu();
    }
    catch(std::logic_error e)
    {
        std::cout << e.what();
    }
	return 0;
}

