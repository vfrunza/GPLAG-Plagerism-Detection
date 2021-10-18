/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <iterator>

class Spremnik {
    double tezina;
    std::string naziv;
    
    public:
    Spremnik(double tezina, std::string naziv): tezina(tezina), naziv(naziv){}
    double DajTezinu() const { return tezina;}
    virtual double DajUkupnuTezinu() const =0;
    virtual void Ispisi() const { std::cout<<"Sadrzaj: "<<naziv<<std::endl;}
     virtual std::shared_ptr<Spremnik> DajKopiju() const =0;
     virtual ~Spremnik()=default;
        
    
};
class Sanduk:public Spremnik {
    std::vector<double> tezine_predmeta;
    public:
    Sanduk(double tezina, std::string naziv, std::vector<double> tezine_predmeta): Spremnik(tezina, naziv), 
    tezine_predmeta(tezine_predmeta) {}
    double DajUkupnuTezinu() const override{
        double suma(0);
        std::for_each(tezine_predmeta.begin(), tezine_predmeta.end(), [&suma](double p){suma+=p; });
        suma+=DajTezinu();
        return suma;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        Spremnik::Ispisi();
                std::cout<<"Tezine predmeta: "; 
    std::for_each(tezine_predmeta.begin(), tezine_predmeta.end(), [](double p){std::cout<<p<<" ";});
    std::cout<<"(kg)"<<std::endl
    <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
    <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
                 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk> (*this);
    }
    
    ~Sanduk() =default;
};

class Vreca: public Spremnik{
    double tezina_materije;
    public:
    Vreca(double tezina, std::string naziv, double tezina_materije): Spremnik(tezina, naziv), 
    tezina_materije(tezina_materije){}
    double DajUkupnuTezinu() const { return DajTezinu()+tezina_materije;}
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        Spremnik::Ispisi();
                
   std::cout <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
    <<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<std::endl
    <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
                 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca> (*this);
    }
   ~Vreca() =default; 
};
class Bure: public Spremnik{
    double specificna_tezina, zapremina;
    public:
    Bure(double tezina, std::string naziv, double specificna_tezina, double zapremina): Spremnik(tezina, naziv), 
    specificna_tezina(specificna_tezina), zapremina(zapremina){}
    double DajUkupnuTezinu() const { return DajTezinu()+specificna_tezina*zapremina/1000.;}
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        Spremnik::Ispisi();
                
   std::cout <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
    <<"Specificna tezina tecnosti: "<<specificna_tezina<<" (kg/m^3)"<<std::endl
    <<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl
    <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
                 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure> (*this);
    }
    ~Bure () =default;
};
class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> sadrzaj;
    public:
    Skladiste()=default;
    Skladiste(const Skladiste &v){
       try{ 
        for(int i=0;i<v.sadrzaj.size();i++){
        sadrzaj.push_back(v.sadrzaj[i]->DajKopiju());}
       }
        catch(...){
            sadrzaj.resize(0);
            throw;
        }
        
    }
    Skladiste& operator=(const Skladiste& v){
        std::vector<std::shared_ptr<Spremnik>> kopija(sadrzaj);
        sadrzaj.resize(0);
        try{ 
        for(int i=0;i<v.sadrzaj.size();i++){
        sadrzaj.push_back(v.sadrzaj[i]->DajKopiju());}
       }
        catch(...){
            sadrzaj=kopija;
            throw;
        }
        
      return *this;  
    }
    Skladiste(Skladiste&&v): sadrzaj(std::move(v.sadrzaj)){
        v.sadrzaj.resize(0);
}
Skladiste & operator = (Skladiste && v){
    sadrzaj=std::move(v.sadrzaj);
    v.sadrzaj.resize(0);
    return *this;
}
    
    Spremnik* DodajSanduk(double tezina, std::string naziv, std::vector<double> tezine_predmeta){
        sadrzaj.push_back(std::make_shared<Sanduk>(tezina, naziv, tezine_predmeta));
        return sadrzaj[sadrzaj.size()-1].get();
    }
    Spremnik* DodajVrecu(double tezina, std::string naziv, double tezina_materije){
         sadrzaj.push_back(std::make_shared<Vreca>(tezina, naziv, tezina_materije));
        return sadrzaj[sadrzaj.size()-1].get();
    }
     Spremnik* DodajBure(double tezina, std::string naziv, double specificna_tezina, double zapremina){
         sadrzaj.push_back(std::make_shared<Bure>(tezina, naziv, specificna_tezina, zapremina));
        return sadrzaj[sadrzaj.size()-1].get();
    }
    Spremnik* DodajSpremnik(Spremnik* objekat, bool vlasnistvo){
        if(vlasnistvo){
            sadrzaj.push_back(std::shared_ptr<Spremnik>(objekat)); return objekat;}
       
            sadrzaj.push_back(objekat->DajKopiju());
            
        return sadrzaj[sadrzaj.size()-1].get();
    }
    void BrisiSpremnik(Spremnik* objekat){
       
      int i;
      for( i=0;i<sadrzaj.size();i++){
          if(sadrzaj[i].get()==objekat)break;
      }  
        if(i!=sadrzaj.size()) sadrzaj.erase(sadrzaj.begin()+i);
       
    }
     Spremnik& DajNajlaksi(){
         if(!sadrzaj.size()) throw std::range_error("Skladiste je prazno");
         auto it(std::min_element(sadrzaj.begin(), sadrzaj.end(), []
         (std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2){
             return p1->DajTezinu()<p2->DajTezinu();
         }));
         return **it;
     }
      Spremnik& DajNajtezi(){
         if(!sadrzaj.size()) throw std::range_error("Skladiste je prazno");
         auto it(std::max_element(sadrzaj.begin(), sadrzaj.end(), []
         (std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2){
             return p1->DajTezinu()<p2->DajTezinu();
         }));
         return **it;
     }
     int BrojPreteskih(int tezina) const {
         return std::count_if(sadrzaj.begin(), sadrzaj.end(), [tezina]( std::shared_ptr<Spremnik>p){
             return p->DajUkupnuTezinu()>tezina;}
         );
     }
     void IzlistajSkladiste() const {
         Skladiste a(*this);
         std::sort(a.sadrzaj.begin(), a.sadrzaj.end(),  [](std::shared_ptr<Spremnik>p, std::shared_ptr<Spremnik>p1)
         {
             return p->DajUkupnuTezinu()>p1->DajUkupnuTezinu();
         });
         for(std::shared_ptr<Spremnik>p : a.sadrzaj) p->Ispisi();
         
     }
     void UcitajIzDatoteke (std::string ime){
         sadrzaj.resize(0);
         std::ifstream ulazni_tok(ime);
         if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
         char znak;
        while(ulazni_tok>>znak){
            ulazni_tok.get();
         if(znak=='S'){
             
             std::string naziv;
             std::getline(ulazni_tok, naziv);
             double tezina(0),predmet(0);int broj_predmeta(0); 
             ulazni_tok>>tezina>>broj_predmeta;
             std::vector<double> m;
             for(int i=0;i<broj_predmeta;i++){
                 ulazni_tok>>predmet;
                 if(!ulazni_tok && !ulazni_tok.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                m.push_back(predmet);
             }
            DodajSanduk(tezina, naziv, m);
    }
    else if(znak=='V'){
        std::string naziv;
             std::getline(ulazni_tok, naziv);
             double tezina(0), tezina_materije(0);
             ulazni_tok>>tezina>>tezina_materije;
             if(!ulazni_tok && !ulazni_tok.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        DodajVrecu( tezina,naziv,tezina_materije);
         
    }
    else if(znak=='B'){
        std::string naziv;
             std::getline(ulazni_tok, naziv);
             double tezina(0), specificna_tezina(0), zapremina(0);
             ulazni_tok>>tezina>>specificna_tezina>>zapremina;
             if(!ulazni_tok && !ulazni_tok.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajBure(tezina, naziv, specificna_tezina, zapremina);
             
        
    }
  else throw std::logic_error("Datoteka sadrzi besmislene podatke");      
     } if(!ulazni_tok.eof()) throw std::logic_error("Problemi pri citanju datoteke");
     ulazni_tok.clear();ulazni_tok.close();}
  /*   ~Skladiste(){
         std::cout<<sadrzaj.size();
         for(int i=0;i<sadrzaj.size();i++) sadrzaj[i]=nullptr;
     }*/
    
};
int main ()
{ 
    try{
        
        Skladiste a;
        a.UcitajIzDatoteke("ROBA.TXT");
        a.IzlistajSkladiste();
    }catch(std::range_error iz){
        std::cout<<iz.what();
    }
    catch(std::logic_error iz){
        std::cout<<iz.what();
    }

    
	return 0;
}
