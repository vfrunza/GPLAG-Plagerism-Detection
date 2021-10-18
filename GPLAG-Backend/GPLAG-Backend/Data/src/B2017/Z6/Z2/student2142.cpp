/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

using namespace std;


class Spremnik
{
    protected:
    string sadrzaj;
    double tezina;
    
    public:
    Spremnik(string s,double t):sadrzaj(s),tezina(t){};
    virtual shared_ptr<Spremnik> DajKopiju() const =0;
    string DajNaziv() const{ return sadrzaj;}
    double DajTezinu() const{return tezina;}
    virtual double DajUkupnuTezinu()const =0;
    virtual void Ispisi()=0;
    virtual ~Spremnik(){};
};
//Sanduk,Vreca,Bure
//Skladiste(kontejner)

class Sanduk:public Spremnik
{
  vector<double> v;
  public:  
  Sanduk(const double &t,const string &s,const vector<double>&v):Spremnik(s,t),v(v){};
  double DajUkupnuTezinu() const
  {
      double suma=0;
      for(int i=0;i<v.size();i++)
        suma+=v[i];
      return suma+DajTezinu();
  }
  void Ispisi()
  {
      cout<<"Vrsta spremnika: Sanduk"<<endl;
      cout<<"Sadrzaj: "<<DajNaziv()<<endl;
      cout<<"Tezine predmeta: ";
      for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
      cout<<"(kg)"<<endl;
      cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
      cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
  }
  shared_ptr<Spremnik> DajKopiju()const {
      return make_shared<Sanduk>(*this);
  }
};

class Vreca:public Spremnik
{
    double t;
    public:
    Vreca(double t,string s,const double t1):Spremnik(s,t),t(t1){};
    double DajUkupnuTezinu() const
    {
      return t+DajTezinu();
    }
    void Ispisi()
    {
      cout<<"Vrsta spremnika: Vreca"<<endl;
      cout<<"Sadrzaj: "<<DajNaziv()<<endl;
      cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl;
      cout<<"Tezina pohranjene materije: "<<t<<" (kg)"<<endl;
      cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    
 
  shared_ptr<Spremnik> DajKopiju() const {
      return make_shared<Vreca>(*this);
  }
};

class Bure:public Spremnik
{
    double gust,zapremina;
    public:
    Bure(const double &t,const string &s,const double &gust,const double &z):Spremnik(s,t),gust(gust),zapremina(z){};
    double DajUkupnuTezinu() const
    {
      return (gust*zapremina)/1000+DajTezinu();
    }
    void Ispisi()
    {
      cout<<"Vrsta spremnika: Bure"<<endl;
      cout<<"Sadrzaj: "<<DajNaziv()<<endl;
      cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl;
      cout<<"Specificna tezina tecnosti: "<<gust<<" (kg/m^3)"<<endl;
      cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<endl;
      cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    
  shared_ptr<Spremnik> DajKopiju() const {
      return make_shared<Bure>(*this);
  }
};

class PolimorfniSpremnik
{
  shared_ptr<Spremnik> pok;
  
  public:
  PolimorfniSpremnik():pok(nullptr){}
  ~PolimorfniSpremnik(){pok=nullptr;}
  PolimorfniSpremnik(const Spremnik &s):pok(s.DajKopiju()){};
  PolimorfniSpremnik(PolimorfniSpremnik &p):pok(p.pok->DajKopiju()){};
  PolimorfniSpremnik(PolimorfniSpremnik &&p):pok(p.pok){p.pok=nullptr;}
  PolimorfniSpremnik &operator=(PolimorfniSpremnik &p)
  {
    pok=p.pok->DajKopiju();
    return *this;
  }
  PolimorfniSpremnik &operator=(PolimorfniSpremnik &&p)
  {
    pok=p.pok->DajKopiju();
    p.pok=nullptr;
    return *this;
  }
  double DajTezinu() const {if (!pok) throw logic_error("Nespecificiran spremnik");return pok->DajTezinu();}
  string DajNaziv() const{if (!pok) throw logic_error("Nespecificiran spremnik"); return pok->DajNaziv();}
  double DajUkupnuTezinu() const{if (!pok) throw logic_error("Nespecificiran spremnik"); return pok->DajUkupnuTezinu();}
  void Ispisi(){if (!pok) throw logic_error("Nespecificiran spremnik"); pok->Ispisi();}
  
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
    catch(std::logic_error le)
    {
        std::cout << le.what();
    }
	return 0;
}
