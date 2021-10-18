/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <string>

class Spremnik{
    protected:
    double tezina;
    std::string ime;
    public:
    Spremnik (double tezina,std::string ime):tezina(tezina),ime(ime){}
    
    double DajTezinu() const {
        return tezina;
    }
    virtual double DajUkupnuTezinu () const=0;
    virtual void Ispisi () const=0;
    virtual ~Spremnik() {};
    virtual std::shared_ptr<Spremnik> DajKopiju () const=0;
    
};
class Sanduk : public Spremnik{
    std::vector <double> tezine_predmeta;
    public: 
    Sanduk(double tezina,std::string ime,std::vector<double> tezine_predmeta)
    :Spremnik(tezina,ime),tezine_predmeta(tezine_predmeta){}
    double DajUkupnuTezinu () const override {
        double suma=0;
        for(double x:tezine_predmeta) suma=suma+x;
        return suma+DajTezinu();
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<ime<<std::endl<<"Tezine predmeta: ";
        for(double x:tezine_predmeta) std::cout<<x<<" ";
        std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
        
    }
    std::shared_ptr<Spremnik>DajKopiju() const override{
        return std::make_shared<Sanduk> (*this);
    }
    
};
class Vreca: public Spremnik{
    double tezina_pohranjenog;
    public:
    Vreca(double tezina,std::string ime,double tezina_pohranjenog):Spremnik(tezina,ime),tezina_pohranjenog(tezina_pohranjenog){}
    double DajUkupnuTezinu () const override {
        return tezina+tezina_pohranjenog;
    }
    void Ispisi () const override{
         std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<ime<<std::endl<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
         <<"Tezina pohranjene materije: "<<tezina_pohranjenog<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
         
    }
    std::shared_ptr<Spremnik>DajKopiju() const override{
        return std::make_shared<Vreca>(*this);
    }
};
class Bure:public Spremnik{
    double tezina_tecnosti,zapremina_tecnosti;
    public:
     Bure(double tezina,std:: string ime, double tezina_tecnosti, double zapremina_tecnosti): Spremnik(tezina,ime),tezina_tecnosti(tezina_tecnosti),zapremina_tecnosti(zapremina_tecnosti){}
     double DajUkupnuTezinu() const override{
         return zapremina_tecnosti*(tezina_tecnosti/1000)+tezina;
     }
     void Ispisi () const override{
          std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<ime<<std::endl<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
         <<"Specificna tezina tecnosti: "<<tezina_tecnosti<<" (kg/m^3)"<<std::endl<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
         
     }
     std::shared_ptr<Spremnik>DajKopiju() const override {
         return std::make_shared<Bure>(*this);

     }
};
class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> v;
    public:
    Skladiste():v(0){};
    Skladiste(const Skladiste &s){
        v.resize(0);
        for(auto x:s.v) v.push_back(x->DajKopiju());
       // return *this;
    }
    Skladiste(Skladiste &&s){
        v=std::move(s.v);
    }
    Skladiste &operator=(const Skladiste &s){
        v.resize(0);
        for(auto x:s.v) v.push_back(x->DajKopiju());
        return *this;

    }
    Skladiste &operator =(Skladiste &&s){
         v=std::move(s.v);
         return *this;
    }
    Spremnik*DodajSanduk(double tez, std::string ime,std::vector<double> tezine_predmeta){
        auto pok= std::make_shared <Sanduk> (tez,ime,tezine_predmeta);
        v.push_back(pok);
        return &*pok;
    }
    Spremnik*DodajVrecu(double tezina,std::string ime,double tezina_pohranjenog){
         auto pok= std::make_shared <Vreca> (tezina,ime,tezina_pohranjenog);
        v.push_back(pok);
        return &*pok;
    }
    Spremnik*DodajBure(double tezina,std::string ime,double tezina_tecnosti,double zapremina_tecnosti){
        auto pok= std::make_shared <Bure> (tezina,ime,tezina_tecnosti,zapremina_tecnosti);
        v.push_back(pok);
        return &*pok;
    }
    Spremnik*DodajSpremnik(Spremnik*pok,bool vlasnistvo);
    void BrisiSpremnik(Spremnik *pok);
    Spremnik&DajNajlaksi();
    Spremnik&DajNajtezi();
    int BrojPreteskih(int n) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(std::string ime2);
};
void Skladiste::IzlistajSkladiste() const {
    auto vek(this->v);
    std::sort(vek.begin(),vek.end(),[](std::shared_ptr<Spremnik> pok1,std::shared_ptr<Spremnik>pok2){
        return pok1->DajUkupnuTezinu()>pok2->DajUkupnuTezinu();
    });
    for(int i=0;i<vek.size();i++){
        vek[i]->Ispisi();
        std::cout<<std::endl;
    }
}
void Skladiste::UcitajIzDatoteke(std::string ime2){
    v.resize(0);
    std::ifstream tok(ime2);
    if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
    char slovo;
    std::string naziv;
    while(tok>>slovo){
        if (!(slovo=='S'||slovo=='V'||slovo=='B'))
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
        std::getline (tok,naziv);
        if(slovo=='S'){
            double tezina;
            int brojpr;
            tok>>tezina>>brojpr;
            if(!tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            std::vector<double> v(brojpr);
            for(int i=0;i<brojpr;i++){
                tok>>v[i];
                  if(!tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            DodajSanduk(tezina,naziv,v);
        }
        else if(slovo=='V'){
            double tezina,tezina_pohranjenog;
            tok>>tezina>>tezina_pohranjenog;
              if(!tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
              DodajVrecu(tezina,naziv,tezina_pohranjenog);
        }
        else if(slovo=='B'){
            double tezina,spect,zapremina;
            tok>>tezina>>spect>>zapremina;
              if(!tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
              DodajBure(tezina,naziv,spect,zapremina);
        }
        if(tok.eof()) return;
    }
      if(!tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
    
}
int Skladiste::BrojPreteskih(int n) const {
    int broj=count_if(v.begin(),v.end(),[n](std::shared_ptr<Spremnik> pok){
        return pok->DajUkupnuTezinu()>n;
    });
    return broj;
}
Spremnik& Skladiste::DajNajlaksi(){
    if(v.size()==0) throw std::range_error ("Skladiste je prazno");
    auto it=std::min_element(v.begin(),v.end(),[](std::shared_ptr<Spremnik> pok1,std::shared_ptr<Spremnik> pok2){
        return pok1->DajTezinu()<pok2->DajTezinu();
    });
    return **it;
}
Spremnik& Skladiste::DajNajtezi(){
        if(v.size()==0) throw std::range_error ("Skladiste je prazno");
         auto it=std::max_element(v.begin(),v.end(),[](std::shared_ptr<Spremnik> pok1,std::shared_ptr<Spremnik> pok2){
        return pok1->DajTezinu()<pok2->DajTezinu();
    });
    return **it;

}
void Skladiste::BrisiSpremnik(Spremnik* pok){
    for(int i=0;i<v.size();i++){
        if(&*v[i]==&*pok){
            v.erase(v.begin()+i);
            break;
        }
    }
}
Spremnik* Skladiste::DodajSpremnik(Spremnik*pok,bool vlasnistvo){
    if(vlasnistvo){
        std::shared_ptr<Spremnik> pametni(pok);
        v.push_back(pametni);
        return &*pametni;
    }
    auto pametni(pok->DajKopiju());
    v.push_back(pametni);
    return &*pametni;
}

int main ()
{
    Skladiste s;
    s.UcitajIzDatoteke("ROBA.TXT");
    s.IzlistajSkladiste();
    
	return 0;
}
