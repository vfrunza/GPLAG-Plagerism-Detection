/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
 
class Spremnik
{
    protected:
    double teg;
    std::string ime;
    public:
    Spremnik(double t, std::string s){teg=t;
        ime=s;
    }
    virtual ~Spremnik(){}
    double DajTezinu() const {return teg;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual Spremnik* DajKopiju() const=0;
   
   
};
class Sanduk: public Spremnik{
    std::vector<double> predmeti;
    public:
    Sanduk(double t, std::string s, std::vector<double> p): Spremnik(t,s)
    {
       
        predmeti=p;
    }
    ~Sanduk(){}
    Spremnik* DajKopiju() const override
    {
        return new Sanduk (*this);
    }
    double DajUkupnuTezinu() const override
    {
        double rez(0);
        for(int i=0; i<predmeti.size();i++)
        {
            rez+=predmeti[i];
        }
       
        return rez+teg;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
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
    Spremnik* DajKopiju()const override
    {
        return new Vreca(*this);
    }
   
    double DajUkupnuTezinu() const override
    {
        return prasak+teg;
    }
    void Ispisi() const override
    {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
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
    Spremnik* DajKopiju() const override
    {
        return new Bure(*this);
    }
    double DajUkupnuTezinu() const override
    {
        double m(zapremina*0.001*gustina);
        return teg+m;
    }
    void Ispisi() const override
    {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Vlastita tezina: "<<teg<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
       
    }
   
   
};
 
class PolimorfniSpremnik
{
    Spremnik *polimspr;
    void Test() const
    {
        if(!polimspr) throw std::logic_error("Nespecificiran spremnik");
    }
    public:
    PolimorfniSpremnik()
    {
        polimspr=nullptr;
    }
    ~PolimorfniSpremnik()
    {
        delete polimspr;
    }
    PolimorfniSpremnik(const Spremnik &s): polimspr(s.DajKopiju()){}
    PolimorfniSpremnik(const PolimorfniSpremnik &s)
    {
        if(!s.polimspr) polimspr=nullptr;
        else polimspr=s.polimspr->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&s)
    {
        polimspr=s.polimspr;
        s.polimspr=nullptr;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &s)
    {
        Spremnik *temp(nullptr);
        if(s.polimspr!=nullptr)
        {
            temp=s.polimspr->DajKopiju();
        }
        delete polimspr;
        polimspr=temp;
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&s)
    {
        std::swap(polimspr, s.polimspr);
        return *this;
    }
    double DajTezinu() const
    {
        Test();
        return polimspr->DajTezinu();
    }
    double DajUkupnuTezinu() const
    {
        Test();
        return polimspr->DajUkupnuTezinu();
    }
    void Ispisi() const
    {
        Test();
        polimspr->Ispisi();
    }
   
};
 
 
 
 
int main ()
{
    try{
    std::cout<<"====Unos za sanduk===="<<std::endl;
    std::cout<<"Unesite tezinu: ";
    int tez;
    std::cin>>tez;
    std::cout<<"Unesite naziv predmeta koji zelite cuvati u sanduku : ";
    std::cin.ignore(10000,'\n');
    std::string naz;
    std::getline(std::cin, naz);
    std::cout<<"Koliko "<<naz<<" zelite cuvati u sanduku? ";
    int tmp;
    std::cin>>tmp;
    std::cout<<"Unesite tezine svake od "<<naz<<std::endl;
    std::vector<double> predmeti(tmp);
    for( int i=0; i<tmp ; i++)
    {
        std::cin>>predmeti[i];
    }
    PolimorfniSpremnik s(Sanduk(tmp,naz,predmeti));
    PolimorfniSpremnik s2,s3;
    s2=s;
    s2.Ispisi();
    std::cout<<"====Unos za vrecu===="<<std::endl;
    std::cout<<"Unesite tezinu: ";
    int tmp2;
    std::cin>>tmp2;
    std::cout<<"Unesite naziv praska koji zelite cuvati u vreci : ";
    std::cin.ignore(10000,'\n');
    std::string drnaz;
    std::getline(std::cin, drnaz);
    std::cout<<"Unesite tezinu praska: ";
    int tmp3;
    std::cin>>tmp3;
    s=Vreca(tmp2,drnaz,tmp3);
    s.DajTezinu();
    s.DajUkupnuTezinu();
    s2=Bure(4, "Voda", 2.5 , 6.3);
    s2.Ispisi();
    s3.DajTezinu();
 
    }
   
     
    catch(std::logic_error e)
    {
        std::cout << e.what();
    }
   
   
    return 0;
}