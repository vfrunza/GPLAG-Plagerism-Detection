/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>
#include <algorithm>

class Spremnik{
  
  protected:
      double tezina_spremnika;
      std::string ime;
  public:
      Spremnik(double tezina_spremnika,std::string ime): tezina_spremnika(tezina_spremnika), ime(ime) {} 
      double DajTezinu() const { 
          return tezina_spremnika;
      }
      virtual double DajUkupnuTezinu() const {return 0;}
      virtual void Ispisi() const=0;
      virtual ~Spremnik() {};
      virtual std::shared_ptr<Spremnik> dajKopiju () const = 0;
};

class Sanduk:public Spremnik{
    std::vector<double> tezine;
    public:
        Sanduk(double tezina_spremnika,std::string ime, std::vector<double> tezine): Spremnik(tezina_spremnika,ime),tezine(tezine) {}
        Sanduk(const Sanduk &s) : Spremnik(s.tezina_spremnika,s.ime), tezine(s.tezine) {}
      //  Spremnik std::shared_ptr<Spremnik>dajKopiju () const override {return new Sanduk(*this);};
        double DajUkupnuTezinu() const override {
           double ukupna(0);
           for(int i=0;i<tezine.size();i++){
               ukupna+=tezine.at(i);
           }
           ukupna+=tezina_spremnika;
           
        return ukupna;
        }
        double DajTezinu() const { return tezina_spremnika;}
        std::string DajIme() const {return ime;}
        std::vector<double> DajTezine() const {return tezine;}
        
        void Ispisi()  const override {
            std::cout << "Vrsta spremnika: Sanduk" << std::endl;
            std::cout << "Sadrzaj: " <<ime<< std::endl;
            std::cout << "Tezine predmeta: ";
            for(int i=0;i<tezine.size();i++){
                std::cout << tezine.at(i)<<" ";
            }
            std::cout << "(kg)" << std::endl;
            std::cout << "Vlastita tezina: "<< DajTezinu()<<" (kg)" << std::endl;
            std::cout << "Ukupna tezina: "<< DajUkupnuTezinu()<<" (kg)" << std::endl;
        }
};

class Vreca:public Spremnik{
  double tezina_praskaste;
  public: 
    Vreca(double tezina_spremnika,std::string ime, double tezina_praskaste):Spremnik(tezina_spremnika,ime),tezina_praskaste(tezina_praskaste){}
    Spremnik std::shared_ptr<Spremnik> dajKopiju() const override {return new Vreca(*this);};
    double DajUkupnuTezinu() const override{
        double ukupna;
        ukupna=tezina_spremnika+tezina_praskaste;
        return ukupna;
    }
    void Ispisi() const override{
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: "<<ime << std::endl;
        std::cout << "Vlastita tezina: " <<DajTezinu()<<" (kg)"<<std::endl;
        std::cout << "Tezina pohranjene materije: "<<tezina_praskaste<<" (kg)" << std::endl;
        std::cout << "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)" << std::endl;
    }   
};

class Bure:public Spremnik{
    double spec_gustina;
    double zapremina;
    public:
        Bure(double tezina_spremnika,std::string ime,double spec_gustina,double zapremina): Spremnik(tezina_spremnika,ime),spec_gustina(spec_gustina),zapremina(zapremina){};
        std::shared_ptr<Spremnik>dajKopiju () const override {return std::shared_ptr<Spremnik>(new Bure(*this));}
        double DajUkupnuTezinu() const override{
            double ukupna(0);
            ukupna+=tezina_spremnika;
            ukupna+=(spec_gustina*(zapremina/1000));
        return ukupna;
        }
        
        void Ispisi() const override{
            std::cout << "Ispisujem bure" << std::endl;
            std::cout << "Vrsta spremnika: Bure" << std::endl;
            std::cout << "Sadrzaj: "<<ime << std::endl;
            std::cout << "Vlastita tezina: "<<DajTezinu()<<" (kg)" << std::endl;
            std::cout << "Specificna tezina tecnosti: "<<spec_gustina<<" (kg/m^3)" << std::endl;
            std::cout << "Zapremina tecnosti: "<<zapremina<<" (l)" << std::endl;
            std::cout << "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)" << std::endl;
        }
};

class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> spremnici;
    public:
    qq
  /*  Skladiste(const Skladiste &s){
        try{
            for(auto a:s.spremnici) spremnici.push_back(a->dajKopiju());
        }
        catch(...){
            for(auto a: spremnici)delete a;
        }
        
    }*/
    Skladiste(Skladiste &&s)=default;
    Skladiste &operator =(Skladiste s){
        std::swap(spremnici,s.spremnici);
        return *this;
    }
    Spremnik *operator[](int i){
        return (spremnici[i].get());
    }
    const Spremnik *operator[](int i) const {
        return (spremnici[i].get());
    }
    Skladiste(const Skladiste &s):spremnici(s.spremnici.size()){
        try{
            for(int i=0;i<s.spremnici.size();i++) spremnici[i]=std::shared_ptr<Spremnik>(s.spremnici[i]->dajKopiju());
        }
        catch(...){
            for(int i=0;i<spremnici.size();i++) delete spremnici[i].get();
        }
        
    }
    Spremnik *DodajSpremnik(Spremnik *novi,bool opcija){
        if(opcija){
            
            std::cout << "Usao u opciju" << std::endl;
            std::shared_ptr<Spremnik> pomocni(novi);
           
            spremnici.push_back(pomocni);
            return(pomocni.get());
        }
        else{
            std::cout << "usao u !opciju" << std::endl;
            std::shared_ptr<Spremnik>pomocni = std::make_shared<Spremnik>(novi->dajKopiju());
            std::cout << "Ispisujem novi" << std::endl;
            novi -> Ispisi();
            std::cout << "Ispisujem pomocni" << std::endl;
            pomocni->Ispisi();
            std::cout << "Prosao ispis" << std::endl;
            spremnici.push_back(pomocni); 
            return(pomocni.get());
        }
     // return (spremnici.at(spremnici.size()-1).get()); 
    }    
    
    Spremnik *DodajSanduk(double tezina_spremnika,std::string ime,std::vector<double>tezine){
        Sanduk *sanduk1(new Sanduk(tezina_spremnika,ime,tezine));
        return this->DodajSpremnik(sanduk1,true);
    }
    Spremnik *DodajVrecu(double tezina_spremnika,std::string ime, double tezina_praskaste){
        Vreca *vreca1(new Vreca(tezina_spremnika,ime,tezina_praskaste));
        return this->DodajSpremnik(vreca1,true);
    }
    Spremnik *DodajBure(double tezina_spremnika,std::string ime,double spec_gustina,double zapremina){
        Bure *bure1(new Bure(tezina_spremnika,ime,spec_gustina,zapremina));
        return this->DodajSpremnik(bure1,true);
    }
    
    void BrisiSpremnik(Spremnik *poslani){
        delete poslani;
    }
    
    Spremnik &DajNajlaksi(){
        if(spremnici.size()==0) throw std::range_error("Skladiste je prazno");
        std::shared_ptr<Spremnik> pomocni;
        pomocni=spremnici.at(0);
        for(int i=0;i<spremnici.size();i++){
            if(spremnici.at(i)->DajTezinu()<pomocni->DajTezinu()){
                pomocni=spremnici.at(i);
            }
        }
    return *pomocni;
    }
    
    Spremnik &DajNajtezi(){
        if(spremnici.size()==0) throw std::range_error("Skladiste je prazno");
        std::shared_ptr<Spremnik> pomocni;
        pomocni=spremnici.at(0);
        for(int i=0;i<spremnici.size();i++){
            if(spremnici.at(i)->DajTezinu()>pomocni->DajTezinu()){
                pomocni=spremnici.at(i);
            }
        }
    return *pomocni;
    }
    
    int BrojPreteskih(int x){
        int brojac;
        for(int i=0;i<spremnici.size();i++){
            if(spremnici.at(i)->DajUkupnuTezinu()>x) brojac++;
        }
        return brojac;
    }
    void IzlistajSkladiste(){
       std::sort(spremnici.begin(),spremnici.end(),[](std::shared_ptr<Spremnik>s1,std::shared_ptr<Spremnik>s2)->bool{return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();});
       
       std::for_each(spremnici.begin(),spremnici.end(),[](std::shared_ptr<Spremnik> s)->void{s->Ispisi(); std::cout << "ispiso" << std::endl; });
    }
    
    void UcitajIzDatoteke(std::string ime_datoteke){
        std::ifstream podaci(ime_datoteke);
        if(!podaci){
             throw std::logic_error("Trazena datoteka ne postoji");
        }
        std::string red_datoteke;
        while(std::getline(podaci,red_datoteke)&& red_datoteke!=""){
            std::string tip;
            tip=red_datoteke.substr(0,1);
            if(tip!="B" && tip!="V" && tip!="S"){
             throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            std::string namirnica;
            int duzina=red_datoteke.length();
            namirnica=red_datoteke.substr(2,(duzina-2));
            
           if(tip=="S"){
                double tezina_sanduka;
                int broj;
                std::vector<double> predmeti ;
                podaci>>tezina_sanduka;
                podaci>>broj;
                 for(int i=0;i<broj;i++){
                    double trenutni;
                     podaci>>trenutni;
                     predmeti.push_back(trenutni);
                }
                this->DodajSanduk(tezina_sanduka,namirnica,predmeti);
                  
                }
                
               else if(tip=="B"){
                    double tezina;
                    double gustina;
                    double zapremina;
                    podaci>>tezina;
                    podaci>>gustina;
                    podaci>>zapremina;
                   /** double tezina_materije;
                    tezina_materije=gustina*(zapremina/1000);*/
                    this->DodajBure(tezina,namirnica,gustina,zapremina);
                }
               else if(tip=="V"){
                    double tezina;
                    double tezina_materije;
                    podaci>>tezina;
                    podaci>>tezina_materije;
                    
                    this->DodajVrecu(tezina,namirnica,tezina_materije);
                }
             
            }
            
            
        } 
};

int main ()
{
    try{
        Skladiste ETF;
        ETF.DodajBure(5,"Voda",1000,150);
        //ETF.IzlistajSkladiste();
        ETF.DodajSanduk(50,"Povrce",{1,2,3,4});
        //ETF.IzlistajSkladiste();
        ETF.DodajVrecu(0.1,"Brasno",25.5);
        //ETF.IzlistajSkladiste();
        ETF.DodajSpremnik(new Vreca(0.5,"Secer",30),true);
        //ETF.IzlistajSkladiste();
        Bure *b=new Bure(15,"Voda",1000,200);
        ETF.DodajSpremnik(b,false);
        delete b;
        ETF.IzlistajSkladiste();
    }
    catch(std::range_error re){
        std::cout << re.what();
    }
    
   /* try{
        Skladiste B;
        B.UcitajIzDatoteke("ROBA.TXT") ;
        B.IzlistajSkladiste();
    }
    catch(std::logic_error e){
        std::cout << e.what() << std::endl;
    }*/
    
	return 0;
}
