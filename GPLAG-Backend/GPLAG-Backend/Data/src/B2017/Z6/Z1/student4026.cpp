/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>

class Spremnik {
    
  double tezina;
  std::string naziv;
  public:
  Spremnik(double tezina, std::string naziv):tezina(tezina),naziv(naziv){}
  virtual void Ispisi()=0;
  virtual double DajUkupnuTezinu()=0;
   std::string DajNaziv() {
       return naziv;
   }
   double DajTezinu(){
       return tezina;
   }
 
 
  };
  
    class Sanduk:public Spremnik {
        std::vector<double> predmeti;
        public:
        Sanduk(double tezina, std::string naziv, std::vector<double>tezine):
        Spremnik(tezina,naziv),predmeti(tezine){}
        
        void Ispisi() const {
            std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
            std::cout<<"Sadrzaj: "<<((Spremnik*)this)->DajNaziv(); std::cout<<std::endl;
            std::cout<<"Tezine predmeta: ";
            double suma=0;
            for(auto a:predmeti){
                std::cout<<a<<" ";
             suma+=a;   
            }
            std::cout<<"(kg)"<<std::endl;
            std::cout<<"Vlastita tezina: "<<((Spremnik*)this)->DajTezinu()<<" (kg)"<<std::endl;
            std::cout<<"Ukupna tezina: "<<((Spremnik*)this)->DajTezinu()+suma<<" (kg)";
        }
    };
    
    class Vreca:public Spremnik {
      double tezina_materije;
      public:
      Vreca(double tezina, std::string naziv, double materije ):Spremnik(tezina,naziv),tezina_materije(materije){}
    void Ispisi() {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<((Spremnik*)this)->DajNaziv(); std::cout<<std::endl;
        std::cout<<"Vlastita tezina: "<<((Spremnik*)this)->DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<tezina_materije<<std::endl;
        std::cout<<"Ukupna tezina: "<<tezina_materije+((Spremnik*)this)->DajTezinu();
    }       
    };

    class Bure:public Spremnik {
        double gustina, zapremina;
        public:
        Bure(double tezina, std::string naziv, double gustina, double zapremina):Spremnik(tezina, naziv),
        gustina(gustina),zapremina(zapremina){}
        void Ispisi() {
            std::cout<<"Vrsta spremnika: Bure"<<std::endl;
            std::cout<<"Sadrzaj: "<<((Spremnik*)this)->naziv<<std::cout<<std::endl;
            std::cout<<"Vlastita tezina: "<<((Spremnik*)this)->DajTezinu()<<std::endl;
            std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
            std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)";
            std::cout<<"Ukupna tezina: "<<gustina*zapremina*1000 + ((Spremnik*)this)->DajTezinu();
        }
    };


class Skladiste {
    
  
  
    
};




int main ()
{
	return 0;
}
