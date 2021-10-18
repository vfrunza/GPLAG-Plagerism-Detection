/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
class Spremink{
    double tezina_v;
    protected:
    std::string naziv;
    public:
    Spremink(double tezina_v,std::string naziv):tezina_v(tezina_v),naziv(naziv){}
    double DajTezinu()const {return tezina_v;}
    virtual double DajUkupnuTezinu()const=0;
    virtual void Ispisi()const=0;
};

class Sanduk: public Spremink{
  std::vector<double> tezina_p;
  public:
  Sanduk(double tezina_v,std::string naziv,std::vector<double> tezina_p):Spremink(tezina_v,naziv),tezina_p(tezina_p){}
  double DajUkupnuTezinu() const override { double suma{}; for(double x:tezina_p)suma+=x; return suma+this->DajTezinu();}
  void Ispisi()const override;
};
class Vreca: public Spremink{
    double tezina_p;
    public:
    Vreca(double tezina_v,std::string naziv,double tezina_p):Spremink(tezina_v,naziv),tezina_p(tezina_p){}
    double DajUkupnuTezinu()const override{return tezina_p+this->DajTezinu();}
    void Ispisi()const override;
};
class Bure: public Spremink{
    double gustina,zapremina;
    public:
    Bure(double tezina_v,std::string naziv,double gustina,double zapremina):Spremink(tezina_v,naziv),gustina(gustina),zapremina(zapremina){}
    double DajUkupnuTezinu()const override{ return this->DajTezinu()+gustina*zapremina*0.001;}
    void Ispisi()const override;
};

void Sanduk::Ispisi()const {
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Tezine predmeta: ";
    for(double x:tezina_p)std::cout<<x<<" ";
    std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<this->DajTezinu()<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
}

void Vreca::Ispisi()const {
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<this->DajTezinu()<<" (kg)"<<std::endl
    <<"Tezina pohranjene materije: "<<tezina_p<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
}
void Bure::Ispisi()const {
    std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<this->DajTezinu()<<" (kg)"<<std::endl
    <<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl
    <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)";
}

class Skladiste{
  std::shared_ptr<Spremink> pok;
      
};


int main ()
{
	return 0;
}
