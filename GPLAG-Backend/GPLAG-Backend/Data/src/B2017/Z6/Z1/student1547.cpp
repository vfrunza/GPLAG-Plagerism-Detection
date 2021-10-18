/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <fstream>


class Spremnik
{
protected:
    double tezina;
    std::string naziv;
public:
    Spremnik(double t, std::string ime) : tezina(t), naziv(ime) {}
    virtual ~Spremnik() {}
    double DajTezinu() const { return tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik *DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    std::vector<double> tezine;
public:
    Sanduk(double t, std::string ime, std::vector<double> vtezine) : Spremnik(t, ime), tezine(vtezine) {}
    void Ispisi() const override 
    {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Tezine predmeta: ";
        for(int i=0;i<tezine.size();i++) std::cout<<tezine.at(i)<<" ";
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    double DajUkupnuTezinu() const
    {
        double ukupna(tezina);
        for(int i=0;i<tezine.size();i++) ukupna+=tezine.at(i);
        return ukupna;
    }
    Spremnik *DajKopiju() const override { return new Sanduk(*this); }
};

class Vreca : public Spremnik
{
    double tezinamaterije;
public:
    Vreca(double t, std::string ime, double tm) : Spremnik(t, ime), tezinamaterije(tm) {}
    void Ispisi() const override 
    {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<tezinamaterije<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    double DajUkupnuTezinu() const
    {
        return tezina + tezinamaterije;
    }
    Spremnik *DajKopiju() const override { return new Vreca(*this); }
};

class Bure : public Spremnik
{
    double tezinatecnosti;
    double zapremina;
public:
    Bure(double t, std::string ime, double spec, double z) : Spremnik(t, ime), tezinatecnosti(spec), zapremina(z) {}
    void Ispisi() const override 
    {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<tezinatecnosti<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
    double DajUkupnuTezinu() const
    {
        return tezina + tezinatecnosti*zapremina/1000;
    }
    Spremnik *DajKopiju() const override { return new Bure(*this); }
};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> roba;
public:
    Skladiste() = default;
    Skladiste(const Skladiste &s)
    {
        for(int i=0;i<s.roba.size();i++)
        {
            auto p = std::shared_ptr<Spremnik>(s.roba.at(i)->DajKopiju());
            roba.push_back(p);
        }
    }
    Skladiste &operator=(const Skladiste &s)
    {
        if(this==&s) return *this;
        
        roba.clear();
        
        for(int i=0;i<s.roba.size();i++)
        {
            auto p = std::shared_ptr<Spremnik>(s.roba.at(i)->DajKopiju());
            roba.push_back(p);
        }
        
        return *this;
    }
    Spremnik* DodajSanduk(double t, std::string ime, std::vector<double> vtezine)
    {
        auto p = new Sanduk(t,ime,vtezine);
        roba.push_back(std::shared_ptr<Sanduk>(p));
        return p;
    }
    Spremnik* DodajVrecu(double t, std::string ime, double tm)
    {
        auto p = new Vreca(t,ime,tm);
        roba.push_back(std::shared_ptr<Vreca>(p));
        return p;
    }
    Spremnik* DodajBure(double t, std::string ime, double spec, double z)
    {
        auto p = new Bure(t,ime,spec,z);
        roba.push_back(std::shared_ptr<Bure>(p));
        return p;
    }
    Spremnik* DodajSpremnik(Spremnik *spremnik, bool cuvati)
    {
        if(cuvati)
        {
            roba.push_back(std::shared_ptr<Spremnik>(spremnik));
            return spremnik;
        }
        else
        {
            auto p = spremnik->DajKopiju();
            roba.push_back(std::shared_ptr<Spremnik>(p));
            return p;
        }
    }
    void BrisiSpremnik(Spremnik *spremnik)
    {
        for(int i=0;i<roba.size();i++) if(spremnik==roba.at(i).get()) {roba.erase(roba.begin()+i); break;}
    }
    Spremnik &DajNajlaksi()
    {
        if(roba.size()==0) throw std::range_error("Skladiste je prazno");
        auto m=roba.at(0);
        for(int i=1;i<roba.size();i++)
        {
            if(m->DajTezinu() > roba.at(i)->DajTezinu()) m=roba.at(i);
        }
        return *m;
    }
    Spremnik &DajNajtezi()
    {
        if(roba.size()==0) throw std::range_error("Skladiste je prazno");
        auto m=roba.at(0);
        for(int i=1;i<roba.size();i++)
        {
            if(m->DajTezinu() < roba.at(i)->DajTezinu()) m=roba.at(i);
        }
        return *m;
    }
    int BrojPreteskih(double x)
    {
        int broj(0);
        for(int i=0;i<roba.size();i++)
        {
            if(roba.at(i)->DajUkupnuTezinu()>x) broj++;
        }
        return broj;
    }
    int BrojPreteskih(double x) const
    {
        int broj(0);
        for(int i=0;i<roba.size();i++)
        {
            if(roba.at(i)->DajUkupnuTezinu()>x) broj++;
        }
        return broj;
    }
    void IzlistajSkladiste() const
    {
        auto pom = roba;
        std::sort(pom.begin(), pom.end(), [](const std::shared_ptr<Spremnik> s1, const std::shared_ptr<Spremnik> s2)
        {
            return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
        });
        for(int i=0;i<pom.size();i++) pom.at(i)->Ispisi();
    }
    void UcitajIzDatoteke(const char ime[])
    {
        std::fstream dat(ime, std::ios::in);
        if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
        roba.clear();
        bool error(false);
        while(true)
        {
            char c=dat.get();
            std::string ime;
            if(c=='S')
            {
                c=dat.get();
                if(c!=' ')
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                std::getline(dat,ime);
                double tezina;
                int brojpred;
                dat>>tezina;
                if(!dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                dat>>brojpred;
                if(!dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                std::vector<double> tezine;
                for(int i=0;i<brojpred;i++)
                {
                    dat>>std::ws;
                    if(dat.peek()=='\n' || dat.eof())
                    {
                        throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    }
                    double unos;
                    dat>>unos;
                    tezine.push_back(unos);
                }
                dat>>std::ws;
                if(dat.peek()!='B' && dat.peek()!='V' && dat.peek()!='S' && !dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                if(dat || dat.eof())
                {
                    auto p = new Sanduk(tezina,ime,tezine);
                    roba.push_back(std::shared_ptr<Spremnik>(p));
                }
            }
            else if(c=='V')
            {
                c=dat.get();
                if(c!=' ')
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                std::getline(dat,ime);
                double tezina;
                double materija;
                if(dat.peek()=='\n' || dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                dat>>tezina;
                if(dat.peek()=='\n' || dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                dat>>materija;
                if(!dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                dat>>std::ws;
                if(dat.peek()!='B' && dat.peek()!='V' && dat.peek()!='S' && !dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                if(dat || dat.eof())
                {
                    auto p = new Vreca(tezina,ime,materija);
                    roba.push_back(std::shared_ptr<Spremnik>(p));
                }
            }
            else if(c=='B')
            {
                c=dat.get();
                if(c!=' ')
                {
                    error=true;
                    break;
                }
                std::getline(dat,ime);
                double tezina;
                double spec;
                double zapremina;
                if(dat.peek()=='\n' || dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                dat>>tezina;
                if(dat.peek()=='\n' || dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                dat>>spec;
                if(dat.peek()=='\n' || dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                dat>>zapremina;
                dat>>std::ws;
                if(dat.peek()!='B' && dat.peek()!='V' && dat.peek()!='S' && !dat.eof())
                {
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                if(dat || dat.eof())
                {
                    auto p = new Bure(tezina,ime,spec,zapremina);
                    roba.push_back(std::shared_ptr<Spremnik>(p));
                }
            }
            else if(c!='\n' && !dat.eof() && c!=' ')
            {
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            if(dat.bad())
            {
                throw std::logic_error("Problemi pri citanju datoteke");
            }
            if(dat.eof()) break;
            if(!dat || error)
            {
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
        if(error)
        {
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
};

int main ()
{/*
    Bure b1(501,"dise",6,7);
    Vreca v1(1,"dise",6);
    Sanduk s1(7,"dise",{6,7});
    Bure b2(9,"dise",6,7);
    Sanduk s2(0.1,"dise",{6,5,7});
    Bure b3(0,"diEEEse",6,7);
    Vreca v2(6,"dise",1);
    Vreca v3(100,"dise",5);
    Bure b4(500,"dise",6,7);*/
    
    Skladiste ETF;/*
    ETF.DodajSpremnik(&b1,false);
    ETF.DodajSpremnik(&v1,false);
    ETF.DodajSpremnik(&s1,false);
    ETF.DodajSpremnik(&b2,false);
    ETF.DodajSpremnik(&s2,false);
    ETF.DodajSpremnik(&b3,false);
    ETF.DodajSpremnik(&v2,false);
    ETF.DodajSpremnik(&v3,false);
    ETF.DodajSpremnik(&b4,false);
    const Skladiste ETF2(ETF);*/
    ETF.UcitajIzDatoteke("ROBA.TXT");
    ETF.IzlistajSkladiste();
	return 0;
}
