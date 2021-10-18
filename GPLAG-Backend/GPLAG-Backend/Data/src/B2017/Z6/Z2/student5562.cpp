/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <memory>
using namespace std;



class Spremnik{
protected: 
    double tezina; 
    string naziv;
public:
    virtual ~Spremnik(){}
    double DajTezinu() const { return tezina;}
    string DajNaziv() const { return naziv;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const =0;
    //virtual shared_ptr<Spremnik> DajKopiju() const  = 0;
    //virtual shared_ptr<Spremnik> DajIsti() const = 0;
    virtual shared_ptr<Spremnik> DajKopiju() const   = 0;
    virtual shared_ptr<Spremnik> DajIsti()  = 0;
    //virtual shared_ptr<Spremnik> DajKopiju()  = 0;
    //virtual shared_ptr<Spremnik> DajIsti()  = 0;
};

class Sanduk: public Spremnik
{
  vector<double> tezine;
public:
    
    Sanduk(double t, string naz, vector<double> v)
    {
        tezina=t; naziv=naz;  tezine=v;
    }
    //shared_ptr<Spremnik> DajKopiju() const override { return make_shared<Sanduk>(*this);}
     shared_ptr<Spremnik> DajKopiju() const override { return make_shared<Sanduk>(*this);}
    //shared_ptr<Spremnik> DajKopiju()  override { return make_shared<Sanduk>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Sanduk"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl;
        cout<<"Tezine predmeta: "; for(int i=0; i<tezine.size(); i++) cout<<tezine[i]<<" ";
        cout<<"(kg)"<<endl;
        cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    double DajUkupnuTezinu() const { 
        double suma=0;
        for(int i=0; i<tezine.size(); i++) suma+=tezine[i];
        return  suma+tezina;
    }
    shared_ptr<Spremnik> DajIsti() override{
        shared_ptr<Sanduk>rez (this);
        return rez;
    }
   
    
};

class Bure: public Spremnik
{
   double gustina, zapremina;
public:
    Bure(double t, string naz, double g, double z)
    {
        tezina=t; naziv=naz;  gustina=g; zapremina=z;
    }
    //shared_ptr<Spremnik> DajKopiju() const  override { return make_shared<Bure>(*this);}
    shared_ptr<Spremnik> DajKopiju() const override { return make_shared<Bure>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Bure"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl;
        cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<endl;
        cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    double DajUkupnuTezinu() const { 
        return ((zapremina*gustina)/1000)+tezina;
    }
    
    shared_ptr<Spremnik> DajIsti()  override {
        shared_ptr<Bure>rez(this);
        return rez;
    }

};

class Vreca: public Spremnik
{
    double materija;
public:
    Vreca(double t, string naz, double g)
    {
        tezina=t; naziv=naz;  materija=g; 
    }
    //shared_ptr<Spremnik> DajKopiju() const override{ return make_shared<Vreca>(*this);}
    shared_ptr<Spremnik> DajKopiju()  const override{ return make_shared<Vreca>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Vreca"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl;
        cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Tezina pohranjene materije: "<<materija<<" (kg)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    double DajUkupnuTezinu() const { 
        return materija+tezina;
    }
    shared_ptr<Spremnik> DajIsti()  override{
        shared_ptr<Vreca>rez(this);
        return rez;
    }
    
};


class PolimorfniSpremnik {
 shared_ptr<Spremnik> p_lik;
 void Test() const {
 if(!p_lik) throw std::logic_error("Nespecificiran spremnik");
 }
public:
     PolimorfniSpremnik() : p_lik(nullptr) {}
     ~PolimorfniSpremnik() { p_lik=nullptr; }
     PolimorfniSpremnik(const Spremnik &lik)  {
         p_lik=lik.DajKopiju();
     }
     PolimorfniSpremnik(PolimorfniSpremnik &lik) {
         if(!lik.p_lik) p_lik = nullptr;
         else p_lik = lik.p_lik->DajKopiju();
     }
     PolimorfniSpremnik(PolimorfniSpremnik &&lik) {
         p_lik = lik.p_lik; lik.p_lik = nullptr;
     }
     PolimorfniSpremnik &operator =(PolimorfniSpremnik &lik) {
         shared_ptr<Spremnik>p_novi(nullptr);
         if(lik.p_lik != nullptr) p_novi = lik.p_lik->DajKopiju();
         p_lik=nullptr;
         p_lik = p_novi;
         return *this;
         }
     PolimorfniSpremnik &operator =(PolimorfniSpremnik &&lik) {
         std::swap(p_lik, lik.p_lik);
         return *this;
     }
     double DajTezinu() const { Test(); return p_lik->DajTezinu();}
     string DajNaziv() const { Test(); return p_lik->DajNaziv();}
     double DajUkupnuTezinu() const { Test(); return p_lik->DajUkupnuTezinu();}
     void Ispisi() const { Test(); p_lik->Ispisi();}
};

int main ()
{
   try{
        PolimorfniSpremnik s1(Bure(10,"Ziva", 30, 70)); 
        PolimorfniSpremnik s2, s3;
        s2 = Sanduk(6, "Flase", {0.5, 0.5, 0.5, 0.5});
        s3 = Vreca(1, "Jabuke", 10);
        PolimorfniSpremnik s4(s3);
        
        cout<<"Bure:"<<endl; s1.Ispisi();
        cout<<endl<<"Sanduk:"<<endl; s2.Ispisi();
        cout<<endl<<"Vrece: "<<endl;
        s3.Ispisi(); s4.Ispisi();
        
        cout<<endl<<"Sad vise nisu vreca i vreca nego vreca i bure"<<endl;
        s4=s1;
        s3.Ispisi(); s4.Ispisi(); 
   }
   catch(logic_error l) { cout<<l.what();}
	return 0;
}
