/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>


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


template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke)
    {
        tok.open(ime_datoteke,fstream::out | fstream::in  | fstream::app | fstream::binary);
        if(!tok) 
            throw logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
        
    }
    void DodajNoviElement(const TipElemenata &element);
    int DajBrojElemenata();
    TipElemenata DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const TipElemenata &element);
  
};

template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element)
{
    tok.write((char *) (&element),sizeof (TipElemenata));
}

template<typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata()
{   
    int br=0;
    TipElemenata broj;
    while(tok.read(reinterpret_cast<char*>(&broj), sizeof broj))
         br++;
         
    tok.clear();
    tok.seekg(0,ios::beg);
  return br;
}

template<typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija)
{   
    int br=0;
    if(pozicija>DajBrojElemenata()|| pozicija<0) throw range_error("Neispravna pozicija");
    
    TipElemenata broj;
    while(tok.read(reinterpret_cast<char*>(&broj), sizeof broj))
    {   
         if(br==pozicija) return broj;
         br++;
    }
    
    tok.clear();
    tok.seekg(0,ios::beg);
    throw logic_error("Problemi prilikom pristupa datoteci");
}

template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element)
{
    int br=0;
    if(pozicija>DajBrojElemenata()|| pozicija<0) throw range_error("Neispravna pozicija");
    
    TipElemenata *broj=new TipElemenata[DajBrojElemenata()];
    while(tok.read(reinterpret_cast<char*>(&broj[br]), sizeof broj))
    {   
         br++;
    }

        
    tok.clear();
    tok.seekg(0,ios::beg);
    throw logic_error("Problemi prilikom pristupa datoteci");

}

int main ()
{   
    
  
    return 0;
}
