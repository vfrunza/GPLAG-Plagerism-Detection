/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <fstream>

class Spremnik {
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik() {}
    virtual ~Spremnik() {}
    Spremnik(double tezina,std::string naziv): tezina(tezina),naziv(naziv){}
    double DajTezinu() const {return tezina;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual Spremnik* DajKopiju() const=0;
};

class Sanduk:public Spremnik {
    std::vector<double>tezine_predmeta;
    public:
    Sanduk() {}
    Sanduk(double _tezina,std::string _naziv,std::vector<double>_tezine): Spremnik(_tezina,_naziv), tezine_predmeta(_tezine){}
    double DajUkupnuTezinu() const override {
        double suma(0);
        for(int i=0; i<tezine_predmeta.size(); i++) {
            suma+=tezine_predmeta[i];
        }
        suma+=DajTezinu();
        return suma;
    }
    std::vector<double>DajTezine()const {
        return tezine_predmeta;
    } 
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk\nSadrzaj: "<<Spremnik::naziv;
        std::cout<<"\nTezine predmeta: ";
        for(int i=0; i<tezine_predmeta.size(); i++) {
            std::cout<<tezine_predmeta[i]<<" "; 
        }
        std::cout<<"(kg)\nVlastita tezina: "<<Spremnik::DajTezinu()<<" (kg)"<<"\nUkupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Sanduk* DajKopiju() const{
        return new Sanduk(DajTezinu(),naziv,DajTezine());
    }
};

class Vreca: public Spremnik {
    double tezine_praskaste_materije;
    public:
    Vreca() {}
    Vreca(double _tezina,std::string _naziv, double _tezine):Spremnik(_tezina,_naziv),tezine_praskaste_materije(_tezine){}
    double DajUkupnuTezinu() const override {
        return DajTezinu()+tezine_praskaste_materije;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca\nSadrzaj: "<<Spremnik::naziv<<"\nVlastita tezina: "<<Spremnik::DajTezinu()<<" (kg)"<<"\nTezina pohranjene materije: "<<DajUkupnuTezinu()-DajTezinu()<<" (kg)"<<"\nUkupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Vreca* DajKopiju() const {
        return new Vreca(DajTezinu(),naziv,tezine_praskaste_materije);
    }
};
class Bure:public Spremnik {
    double ro_specificna_tezina;
    double zapremina;
    public:
    Bure(){}
    Bure(double _tezina,std::string _naziv, double _ro_specificna_tezina, double _zapremina):Spremnik(_tezina,_naziv),ro_specificna_tezina(_ro_specificna_tezina),zapremina(_zapremina) {}
    double Dajro() const {return ro_specificna_tezina;}
    double DajZapreminu() const {return zapremina;}
    double DajUkupnuTezinu() const override {
        double masa;
        masa=DajZapreminu()*Dajro()*1e-3+DajTezinu();
        return masa;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure\nSadrzaj: "<<Spremnik::naziv;
        std::cout<<"\nVlastita tezina: "<<Spremnik::DajTezinu()<<" (kg)"<<"\nSpecificna tezina tecnosti: "<<Dajro()<<" (kg/m^3)"<<"\nZapremina tecnosti: "<<DajZapreminu()<<" (l)"<<"\nUkupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    Bure* DajKopiju() const {
        return new Bure(DajTezinu(),naziv,Dajro(), DajZapreminu());
    }
};
class Skladiste {
   std::vector<std::shared_ptr<Spremnik>>vektor;
   public:
   Skladiste() {
       vektor.clear();
   }
   ~Skladiste() {
       for(int i=0; i<vektor.size(); i++) 
           vektor[i]=nullptr;
           vektor.clear();
   }
   Skladiste(const Skladiste &s) {
       try {
           vektor.clear();
           for(int i=0; i<s.vektor.size(); i++)
           vektor.push_back(s.vektor[i]);
       }
       catch(...) {
           throw;
       }
   }
   Skladiste &operator=(const Skladiste &s) {
       vektor=s.vektor;
       return *this;
   }
   Sanduk* DodajSanduk(double tezina,std::string naziv,std::vector<double>tezine) {
       std::shared_ptr<Sanduk>temp(std::make_shared<Sanduk>(tezina,naziv,tezine));
       vektor.push_back(temp);
       return temp.get();
   }
   Vreca* DodajVrecu(double tezina,std::string naziv,double tezine) {
       std::shared_ptr<Vreca>temp(std::make_shared<Vreca>(tezina,naziv,tezine));
       vektor.push_back(temp);
       return temp.get();
   }
   Bure* DodajBure(double tezina,std::string naziv,double ro_specificna_tezina, double zapremina) {
       std::shared_ptr<Bure>temp(std::make_shared<Bure>(tezina,naziv,ro_specificna_tezina,zapremina));
       vektor.push_back(temp);
       return temp.get();
   }
   Spremnik* DodajSpremnik(Spremnik *objekat, bool istinitost) {
       if(istinitost) {
           std::shared_ptr<Spremnik>temp(objekat);
           vektor.push_back(temp);
           return temp.get();
       }
       else {
           std::shared_ptr<Spremnik>temp(objekat->DajKopiju());
           vektor.push_back(temp);
           return temp.get();
       }
   }
   Spremnik* BrisiSpremnik(Spremnik *nekispremnik) {
       if(vektor.size()==0) throw std::range_error("Skladiste je prazno");
       for(int i=0;i<vektor.size(); i++) {
           if(vektor[i].get()==nekispremnik) {
               vektor.erase(vektor.begin()+i);
               return nekispremnik;
           }
       }
       
   }
   Spremnik& DajNajlaksi() const {
       if(vektor.size()==0) throw std::range_error("Skladiste je prazno");
       double najlaksi(10000.); 
       int p(-1);
       for(int i=0; i<vektor.size();i++) {
           if(!vektor[i]) continue;
           if(vektor[i]->DajTezinu()<najlaksi) {
               najlaksi=vektor[i]->DajTezinu();
               p=i;
           }
       }
       return *vektor[p].get();
   }
   Spremnik& DajNajtezi() const {
       if(vektor.size()==0) throw std::range_error("Skladiste je prazno");
       double najtezi(-1e10);
       int p(-1);
       for(int i=0; i<vektor.size();i++) {
           if(!vektor[i]) continue;
           if(vektor[i]->DajTezinu()>najtezi) {
               najtezi=vektor[i]->DajTezinu();
               p=i;
           }
       }
       return *vektor[p].get();
   }
   int BrojPreteskih(double broj) const {
       int brojac(0);
       for(int i=0; i<vektor.size(); i++) {
           if(vektor[i]->DajUkupnuTezinu()>broj) brojac++;
       }
       return brojac;
   }
   int BrojPreteskih(const double &broj) {
       int brojac(0);
       for(int i=0; i<vektor.size(); i++) {
           if(vektor[i]->DajUkupnuTezinu()>broj) brojac++;
       }
       return brojac;
   }
   void IzlistajSkladiste() {
       for(int i=0; i<vektor.size()-1; i++) {
           for(int j=i+1; j<vektor.size(); j++) {
               if(vektor[i]->DajUkupnuTezinu()<vektor[j]->DajUkupnuTezinu()) vektor[i].swap(vektor[j]);
           }
       }
       for(int i=0; i<vektor.size(); i++) {
           if(vektor[i]!=nullptr) vektor[i]->Ispisi();
       }
   }
   void UcitajIzDatoteke(const char ime_datoteke[]) {
       std::ifstream ulaz(ime_datoteke);
       if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
       char tip(0);
       ulaz>>std::ws;
       while(ulaz>>tip) {
           if(tip!='S' && tip!='B' && tip!='V') throw std::logic_error("Datoteka sadrzi besmislene podatke");
           char ime[30];
           if(tip=='S') {
               ulaz.getline(ime,30);
               double tezina;
               int br(0);
               std::vector<double>tezine;
               double t;
               ulaz>>tezina>>br;
               if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
               for(int i=0; i<br; i++) {
                   ulaz>>t;
                   if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                   tezine.push_back(t);
               }
               DodajSanduk(tezina,&ime[1],tezine);
           }
           else if(tip=='V') {
               ulaz.getline(ime,30);
               double tezina(0), tezina_poh(0);
               ulaz>>tezina;
               if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
               ulaz>>tezina_poh;
               DodajVrecu(tezina,&ime[1],tezina_poh);
           }
           else if(tip=='B') {
               ulaz.getline(ime,30);
               double tezina(0),spec(0),zap(0);
               ulaz>>tezina>>spec>>zap;
               if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
               DodajBure(tezina,&ime[1],spec,zap);
           }
           if(ulaz.bad()) throw std::logic_error("Problemi pri citanju datoteke");
       }
       ulaz.close();
   }
};
int main ()
{
    try {
        Skladiste ETF;
        ETF.UcitajIzDatoteke("ROBA.TXT");
        ETF.IzlistajSkladiste();
    }
    catch(std::logic_error re) {
        std::cout<<re.what();
    }
	return 0;
}
