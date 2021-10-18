/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
 
class Spremnik
{
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(double t, std::string s){tezina=t;
        naziv=s;
    }
    virtual ~Spremnik(){}
    double DajTezinu() const {return tezina;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
   
   
};
class Sanduk: public Spremnik{
    std::vector<double> predmeti;
    public:
    Sanduk(double t, std::string s, std::vector<double> p): Spremnik(t,s)
    {
       
        predmeti=p;
    }
    ~Sanduk(){}
    std::shared_ptr<Spremnik> DajKopiju() const override
    {
        return std::make_shared<Sanduk> (*this);
    }
    double DajUkupnuTezinu() const override
    {
        double suma(0);
        for(int i=0; i<predmeti.size();i++)
        {
            suma+=predmeti[i];
        }
       
        return suma+tezina;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(int i=0; i<predmeti.size(); i++)
        {
            std::cout<<predmeti[i]<<" ";
        }
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
class Vreca: public Spremnik
{
    double prasak;
    public:
    Vreca(double t, std::string s, double p): Spremnik(t,s)
    {
        prasak=p;
       
    }
    ~Vreca(){}
    std::shared_ptr<Spremnik> DajKopiju()const override
    {
        return std::make_shared<Vreca>(*this);
    }
   
    double DajUkupnuTezinu() const override
    {
        return prasak+tezina;
    }
    void Ispisi() const override
    {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<prasak<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
       
    }
   
};
class Bure : public Spremnik{
    double gustina, zapremina;
    public:
    Bure(double t, std::string s, double g, double v): Spremnik(t,s)
    {
        gustina=g;
        zapremina=v;
    }
    ~Bure(){}
    std::shared_ptr<Spremnik> DajKopiju() const override
    {
        return std::make_shared<Bure>(*this);
    }
    double DajUkupnuTezinu() const override
    {
        double m(zapremina*0.001*gustina);
        return tezina+m;
    }
    void Ispisi() const override
    {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
       
    }
   
   
};
class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> skladiste;
    public:
    Skladiste(){}
    ~Skladiste(){}
    Skladiste(const Skladiste &s)
    {
        skladiste.resize(s.skladiste.size());
        for(int i=0; i<s.skladiste.size(); i++)
        {
            std::shared_ptr<Spremnik>p(s.skladiste[i]->DajKopiju());
            skladiste[i]=p;
        }
    }
    Skladiste(Skladiste &&s)
    {
        skladiste=s.skladiste;
        s.skladiste.resize(0);
    }
    Skladiste &operator =(const Skladiste &s)
    {
        if(&s!=this)
        {
            for(int i=0; i<skladiste.size(); i++)
            {
                std::shared_ptr<Spremnik>p(s.skladiste[i]->DajKopiju());
                skladiste[i]=p;
            }
        }
        return *this;
    }
    Skladiste &operator =(Skladiste &&s)
    {
        if(&s!=this)
        {
            skladiste=s.skladiste;
            s.skladiste.resize(0);
        }
        return *this;
    }
   
   
    Spremnik* DodajSanduk(double t, std::string s, std::vector<double> p)
    {
        skladiste.push_back(std::make_shared<Sanduk> (t,s,p));
        return skladiste[skladiste.size()-1].get();
    }
    Spremnik* DodajVrecu(double t, std::string s, double p)
    {
        skladiste.push_back(std::make_shared<Vreca> (t,s,p));
        return skladiste[skladiste.size()-1].get();
    }
    Spremnik* DodajBure( double t, std::string s, double g, double v)
    {
        skladiste.push_back(std::make_shared<Bure>(t,s,g,v));
        return skladiste[skladiste.size()-1].get();
    }
   
   
   
    Spremnik* DodajSpremnik(Spremnik *s, bool brisati=true)
    {
        if(brisati==true)
        {
            skladiste.push_back(std::shared_ptr<Spremnik> (s));
        }
        else
        {
            std::shared_ptr<Spremnik> p=s->DajKopiju();
            skladiste.push_back(p);
        }
        return skladiste[skladiste.size()-1].get();
       
       
    }
   
    Spremnik & DajNajlaksi() const
    {
        if(skladiste.size()==0) throw std::range_error("Skladiste je prazno");
        int indeks(0);
        double tezina_najlakseg(skladiste[0]->DajTezinu());
        for( int i=0; i<skladiste.size(); i++)
        {
            if(skladiste[i]->DajTezinu()<tezina_najlakseg)
            {
                tezina_najlakseg=skladiste[i]->DajTezinu();
                indeks=i;
            }
        }
        return *skladiste[indeks];
    }
    Spremnik & DajNajtezi() const
    {
        if(skladiste.size()==0) throw std::range_error("Skladiste je prazno");
        int indeks=0;
        double tezina_najtezeg(skladiste[0]->DajTezinu());
        for( int i=0; i<skladiste.size(); i++)
        {
            if(skladiste[i]->DajTezinu()>=tezina_najtezeg)
            {
                tezina_najtezeg=skladiste[i]->DajTezinu();
                indeks=i;
            }
        }
        return *skladiste[indeks];
    }
   
   
    int BrojPreteskih(double t)
    {
        int brojac(0);
        for( int i=0; i<skladiste.size(); i++)
        {
            if(skladiste[i]->DajUkupnuTezinu()>t)
            {
                brojac++;
            }
        }
        return brojac;
    }
    int BrojPreteskih(double t) const
    {
        int brojac(0);
        for( int i=0; i<skladiste.size(); i++)
        {
            if(skladiste[i]->DajUkupnuTezinu()>t)
            {
                brojac++;
            }
        }
        return brojac;
    }
    void IzlistajSkladiste()
    {
        sort(skladiste.begin(), skladiste.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)
        {
            if((s1->DajUkupnuTezinu()) > (s2->DajUkupnuTezinu())) return true;
            return false;
        }
        );
        for(int i=0; i<skladiste.size(); i++)
        {
            skladiste[i]->Ispisi();
        }
    }
    void IzlistajSkladiste() const
    {
        std::vector<std::shared_ptr<Spremnik>> temp;
        for(int i=0; i<skladiste.size(); i++)
        {
            temp.push_back(skladiste[i]);
        }
       
        sort(temp.begin(), temp.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)
        {
            if((s1->DajUkupnuTezinu()) > (s2->DajUkupnuTezinu())) return true;
            return false;
        }
        );
        for(int i=0; i<temp.size(); i++)
        {
            temp[i]->Ispisi();
        }
    }
    void BrisiSpremnik(Spremnik* s)
    {
        for(int i=0; i<skladiste.size(); i++)
        {
            if(skladiste[i].get()==s)
            {
                for(int j=i; j<skladiste.size()-1; j++)
                {
                    skladiste[j]=skladiste[j+1];
                }
                skladiste.resize(skladiste.size()-1);
            }
        }
    }
   
   
   
   
   
   
};
 
 
 
int main ()
{
     Skladiste ETF;
ETF.DodajSanduk(50, "Voce", {1,3,5,6});
ETF.DodajVrecu(0.1, "Brasno", 25.5);
ETF.DodajBure(5, "Krv", 1300, 150);
Skladiste ETF1(ETF);
Skladiste ETF2;
ETF2 = ETF1;
ETF2.IzlistajSkladiste();
    return 0;
}
 