#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdexcept>
#include<cmath>
#include<algorithm>
#include<memory>

class Spremnik
{
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(double tezina,std::string naziv): tezina(tezina),naziv(naziv){}
   
    double DajTezinu() const{return tezina;}
    virtual double DajUkupnuTezinu() const=0;
    virtual Spremnik *DajKopiju() const=0;
    virtual void Ispisi() const=0;
    virtual~Spremnik(){}
};


class Sanduk:public Spremnik
{
    std::vector<double>tezine;
    public:
    Sanduk(double tezina,std::string naziv,std::vector<double>tezine):Spremnik(tezina,naziv),tezine(tezine){}
    double DajUkupnuTezinu() const override{
        double tezinasanduk=DajTezinu();
        //ukupna
        for(int i=0;i<tezine.size();i++)
        tezinasanduk=tezinasanduk+tezine[i];
    return tezinasanduk;}
Sanduk* DajKopiju() const override{return new Sanduk(*this);}
void Ispisi() const override
{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Tezine predmeta: ";
    for(int i=0;i<tezine.size();i++)
    std::cout<<tezine[i]<<" ";
    std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}
};
class Bure:public Spremnik
{
    double spectezina;
    double zapremina;
    
    public:
    Bure(double tezina,std::string naziv,double spectezina,double zapremina): Spremnik(tezina,naziv),spectezina(spectezina),zapremina(zapremina){}
    Bure* DajKopiju() const override{return new Bure(*this);}
    double DajUkupnuTezinu() const override
    {
       
        double ukupnatezina=spectezina*zapremina/1000+DajTezinu();
        return ukupnatezina;
    }
    void Ispisi() const override
    {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Specificna tezina tecnosti: "<<spectezina<<" (kg/m^3)"<<std::endl<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
class Vreca:public Spremnik{
    double tezinamaterije;
    public:
    Vreca(double tezina,std::string naziv,double tezinamaterije):Spremnik(tezina,naziv),tezinamaterije(tezinamaterije){}
    Vreca* DajKopiju() const override{return new Vreca(*this);}
    double DajUkupnuTezinu() const override
    {double materija=DajTezinu();
        return materija+tezinamaterije;
    }
    void Ispisi() const override
    {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Tezina pohranjene materije: "<<tezinamaterije<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
//nova
class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> vektor;
    public:
    Skladiste() {}
    Skladiste(const Skladiste &skladiste)
    {
        for(auto x:skladiste.vektor){
        vektor.push_back(std::shared_ptr<Spremnik>(x->DajKopiju()));}
    }
    Skladiste(Skladiste &&skladiste)
    {
        std::swap(vektor,skladiste.vektor);
        skladiste.vektor.resize(0);
    }
    Skladiste &operator=(const Skladiste &skladiste)
    {
        for(auto x:vektor){
        x=nullptr;}
        vektor.resize(0);
        for(auto x:skladiste.vektor){
        vektor.push_back(std::shared_ptr<Spremnik>(x->DajKopiju()));}
        return *this;
    }
    Skladiste &operator=(Skladiste &&skladiste)
    {
        //if(&skladiste!=this)
         std::swap(vektor,skladiste.vektor);
         return *this;
    }
    Spremnik* DodajBure(double tezina,std::string naziv,double spectezina,double zapremina)
    {
        Bure* pomocni=new Bure(tezina,naziv,spectezina,zapremina);
        vektor.push_back(std::shared_ptr<Spremnik>(pomocni));
        return pomocni;
    }
    Spremnik* DodajVrecu(double tezina,std::string naziv,double tezinamaterije)
    {
        
        Vreca* pomocni=new Vreca(tezina,naziv,tezinamaterije);
        vektor.push_back(std::shared_ptr<Spremnik>(pomocni));
        return pomocni;
    }
    Spremnik* DodajSanduk(double tezina,std::string naziv,std::vector<double>tezine)
    {
        Sanduk* pomocni=new Sanduk(tezina,naziv,tezine);
        vektor.push_back(std::shared_ptr<Spremnik>(pomocni));
        return pomocni;
    }
    
    Spremnik* DodajSpremnik(Spremnik* pok,bool logvrijednost)
    {
        if(logvrijednost==true)
        {
            Spremnik* pomocni=pok->DajKopiju(); delete pok;
            vektor.push_back(std::shared_ptr<Spremnik>(pomocni));
            return pomocni;
            
        }
        else
        {
            Spremnik* pomocni=pok->DajKopiju(); 
            vektor.push_back(std::shared_ptr<Spremnik>(pomocni));
            return pomocni;
        }
    }
    Spremnik &DajNajlaksi()
    {
        if(vektor.size()==0)
        throw std::range_error("Skladiste je prazno");
        auto it=std::min_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Spremnik>p1,std::shared_ptr<Spremnik>p2)
        {
           return p1->DajTezinu()<p2->DajTezinu();
            
        });
        return **it;
    }
    Spremnik &DajNajtezi(){
        if(vektor.size()==0)
        throw std::range_error("Skladiste je prazno");
        auto it=std::max_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Spremnik>p1,std::shared_ptr<Spremnik>p2)
        {
           return (p1->DajTezinu()<p2->DajTezinu());
            
        });
        return **it;
    }
    void IzlistajSkladiste() const
    {
       auto kopija=vektor;
       std::sort(kopija.begin(),kopija.end(),[](std::shared_ptr<Spremnik>p1,std::shared_ptr<Spremnik>p2)
       {
           return p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu();
       });
       
       for(auto x:kopija)
       {
           x->Ispisi();     }
    }
    int BrojPreteskih(int teski) const
    {
         return std::count_if(vektor.begin(),vektor.end(),[teski](std::shared_ptr<Spremnik>p1){
             if(p1->DajUkupnuTezinu()>teski)
             return true;
             return false;
         });
    }
    void BrisiSpremnik(Spremnik *mjesto)
    {
        for(int i=0;i<vektor.size();i++)
        {
            if(mjesto==vektor[i].get()){
                
            vektor.erase(vektor.begin()+i);
            break;}
        }
    }
    void UcitajIzDatoteke(std::string ime);
    
    
};
void Skladiste::UcitajIzDatoteke(std::string ime)
{
   std::ifstream tok(ime);
   if(!tok)
    throw std::logic_error("Trazena datoteka ne postoji");
    std::string naziv;
    char znak;
    double tezina;
    for(;;)
    {
        znak=tok.get();
        if(!tok)
        break;
        std::getline(tok,naziv);
        if(znak=='S')
        {
           int brojpred;
           double tezina;
           std::vector<double>tezine;
           tok>>tezina>>brojpred;
          
           for(int i=0;i<brojpred;i++)
           {
                double element;
               tok>>element;
               if(!tok && !tok.eof() && !tok.bad())
               throw std::logic_error("Datoteka sadrzi besmislene podatke");
               tezine.push_back(element);
           }
           DodajSanduk(tezina,naziv,tezine);
        }
        else if(znak=='B')
        {
            double spectezina,zapremina;
            tok>>spectezina>>zapremina;
            DodajBure(tezina,naziv,spectezina,zapremina);
            
        }else if(znak=='V')
        {
            double tezinamaterije;
            tok>>tezina>>tezinamaterije;
            DodajVrecu(tezina,naziv,tezinamaterije);
        }
            
        }
        if(tok.bad())
        throw std::logic_error("Problem pri citanju datoteke");
        else if(!tok.bad() && !tok.eof())
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
   
int main ()
{
    Skladiste s1;
    try
    {
        s1.UcitajIzDatoteke("ROBA.TXT");
        s1.IzlistajSkladiste();
    }
    catch(std::logic_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
	return 0;
}
