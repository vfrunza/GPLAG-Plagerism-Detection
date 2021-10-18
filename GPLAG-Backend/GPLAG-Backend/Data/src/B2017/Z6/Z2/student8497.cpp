/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdexcept>
#include<cmath>
#include<algorithm>              


class Spremnik
{
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(double tezina,std::string naziv): tezina(tezina),naziv(naziv){}
    virtual~Spremnik(){}
    double DajTezinu() const{return tezina;}
    virtual double DajUkupnuTezinu() const=0;
    virtual Spremnik *DajKopiju() const=0;
    virtual void Ispisi() const=0;
};

/*class Skladiste{
    
}*/
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
        double ukupnatezina;
        ukupnatezina=spectezina*zapremina/1000+DajTezinu();
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
class PolimorfniSpremnik
{
    Spremnik *spremnik;
    void Test() const
    {
        if(!spremnik) throw std::logic_error("Nespecificiran spremnik");
    }
    public:
    PolimorfniSpremnik():spremnik(nullptr){};
    ~PolimorfniSpremnik(){delete spremnik;}
    PolimorfniSpremnik(const Spremnik &spremnik11){spremnik=spremnik11.DajKopiju();}
    PolimorfniSpremnik(const PolimorfniSpremnik &spremnik11)
    {
        if(!spremnik11.spremnik)
        spremnik=nullptr;
        else spremnik=spremnik11.spremnik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&spremnik11)
    {
        spremnik=spremnik11.spremnik;
        spremnik11.spremnik=nullptr;
    }
      PolimorfniSpremnik &operator=(const PolimorfniSpremnik &spremnik11)
    {
        if(&spremnik11!=this){
        delete spremnik;
        if(!spremnik11.spremnik)
        spremnik=nullptr;
        else spremnik=spremnik11.spremnik->DajKopiju();
    }
    return *this;}
    PolimorfniSpremnik &operator=(PolimorfniSpremnik &&spremnik11)
    {
        if(&spremnik11!=this){
            delete spremnik;
        spremnik=spremnik11.spremnik;
        spremnik11.spremnik=nullptr;}
        return *this;
    }
    double DajTezinu() const{Test();return spremnik->DajTezinu();}
    double DajUkupnuTezinu() const{Test();return spremnik->DajUkupnuTezinu();}
    void Ispisi() const{Test();return spremnik->Ispisi();}
    
    };
    int main()
    {
        return 0;
    }
    
