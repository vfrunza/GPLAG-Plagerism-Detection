/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>

#define PI 4*atan(1)
#define epsilon 0.00000000001

class NepreklapajucaKugla
{
    double x, y, z, r;
    NepreklapajucaKugla *prethodno_kreirana = nullptr;
    static NepreklapajucaKugla *zadnja_kreirana;
    friend bool DaLiSePreklapa(const NepreklapajucaKugla &k1);
    
   public:
   
    explicit NepreklapajucaKugla(double r = 0);
    NepreklapajucaKugla(double x, double y, double z, double r = 0);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
    
    ~NepreklapajucaKugla();
    
    NepreklapajucaKugla(const NepreklapajucaKugla &k) =delete;
    NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k) =delete;
    
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

//PODRAZUMIJEVANA VRIJEDNOST NA KOJU POSTAVLJAMO STATICKE FUNKCIJE SE PISE NA GLOBALNOM NIVO VAN DEKLARACIJE KLASE
NepreklapajucaKugla *NepreklapajucaKugla::zadnja_kreirana = nullptr;  

bool DaLiSePreklapa(const NepreklapajucaKugla &k)
{
   for(NepreklapajucaKugla *p=NepreklapajucaKugla::zadnja_kreirana; p!=nullptr; p=p->prethodno_kreirana)
   {
       if( RastojanjeCentara(k, *p) < (k.DajPoluprecnik() + p->r))
       throw std::logic_error ("Nedozvoljeno preklapanje");
   }
   
   return false;
}

NepreklapajucaKugla::NepreklapajucaKugla(double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    NepreklapajucaKugla::r=r;
    x=0;
    y=0;
    z=0;
    
    try
    {
        if(!DaLiSePreklapa(*this) )
        {
            prethodno_kreirana=zadnja_kreirana;   //u prvom prolazu su oba nullptr, pa ne treba razdvajati na dva if uslova
            NepreklapajucaKugla::zadnja_kreirana=this;
        }
    }
    catch(...)
    {
        throw;
    }
    
}

NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    NepreklapajucaKugla::r=r;
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    
    try
    {
        if(!DaLiSePreklapa(*this) )
        {
            prethodno_kreirana=zadnja_kreirana;   //u prvom prolazu su oba nullptr, pa ne treba razdvajati na dva if uslova
            NepreklapajucaKugla::zadnja_kreirana=this;
        }
    }
    catch(...)
    {
        throw;
    }
    
}

NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    NepreklapajucaKugla::r=r;
    x = std::get<0>(centar);
    y = std::get<1>(centar);
    z = std::get<2>(centar);

    try
    {
        if(!DaLiSePreklapa(*this) )
        {
            prethodno_kreirana=zadnja_kreirana;   //u prvom prolazu su oba nullptr, pa ne treba razdvajati na dva if uslova
            NepreklapajucaKugla::zadnja_kreirana=this;
        }
    }
    catch(...)
    {
        throw;
    }
    
}

NepreklapajucaKugla::~NepreklapajucaKugla()
{
       NepreklapajucaKugla *prije, *ovaj;
       
       for(ovaj=NepreklapajucaKugla::zadnja_kreirana; ovaj!=this; ovaj=ovaj->prethodno_kreirana)
       {
           ovaj=ovaj->prethodno_kreirana;
       }
       
       if(ovaj==zadnja_kreirana)
       {
           auto pomocna = zadnja_kreirana->prethodno_kreirana;
           zadnja_kreirana->prethodno_kreirana=nullptr;
           zadnja_kreirana=pomocna;
           
       }
       
       for(prije=NepreklapajucaKugla::zadnja_kreirana; prije!=ovaj; prije=prije->prethodno_kreirana)
       {
           prije=prije->prethodno_kreirana; ////ovdje greska
       }
     
       
       if(ovaj->prethodno_kreirana!=nullptr)
       {
            prije->prethodno_kreirana = ovaj->prethodno_kreirana;
            ovaj->prethodno_kreirana = nullptr;
       }
       else if(ovaj->prethodno_kreirana == nullptr)
       {
           prije->prethodno_kreirana = nullptr;
       }
       
}

double NepreklapajucaKugla::DajX() const
{
    return x;
}

double NepreklapajucaKugla::DajY() const
{
    return y;
}

double NepreklapajucaKugla::DajZ() const
{
    return z;
}

std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const
{
    return std::make_tuple(x, y, z);
}

double NepreklapajucaKugla::DajPoluprecnik() const
{
    return r;
}

double NepreklapajucaKugla::DajPovrsinu() const
{
    return 4*r*r*PI;
}

double NepreklapajucaKugla::DajZapreminu() const
{
    return (4./3)*r*r*r*PI;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviX(double x)
{
    try
    {
        NepreklapajucaKugla(x, y, z, r);  //ako ovo pozivanje konstruktora ne baci izuzetak, dole dodjeljujem
        NepreklapajucaKugla::x=x;
        
    }
    catch(...)
    {
        throw;
    }
    
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviY(double y)
{
    try
    {
        NepreklapajucaKugla(x, y, z, r);
        NepreklapajucaKugla::y=y;
    }
    catch(...)
    {
        throw;
    }
    
    
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ(double z)
{
    try
    {
        NepreklapajucaKugla(x, y, z, r);
        NepreklapajucaKugla::z=z;
    }
    catch(...)
    {
        throw;
    }
    
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z)
{
    try
    {
        NepreklapajucaKugla(x, y, z, r);
        
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
    }
    catch(...)
    {
        throw;
    }
    
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    try
    {
        NepreklapajucaKugla(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r);
        
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
    }
    catch(...)
    {
        throw;
    }
    
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    try
    {
        NepreklapajucaKugla(x, y, z, r);
        NepreklapajucaKugla::r=r;
    }
    catch(...)
    {
        throw;
    }
    
    return *this;
}

void NepreklapajucaKugla::Ispisi() const
{
    std::cout<< "{(" <<x<< "," <<y<< "," <<z<< ")," <<r<< "}" <<std::endl;
}

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    try
    {
        NepreklapajucaKugla(x+delta_x, y+delta_y, z+delta_z, r);
        
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    catch(...)
    {
        throw;
    }
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return  sqrt( (k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z) );
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugli: ";
    
    while(true)
    {
        std::cin>>n;
        
        if(std::cin && n>0)
        break;
        
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);
    
    for(int i=0; i<v.size(); i++)
    {
        double x, y, z, r;
        std::cout<<"Unesite centar za "<<i+1<<". kugle: ";
        
        std::cin>>x>>y>>z;
        
        if(!std::cin)
        {
            std::cout<<"Neispravan centar "<<std::endl;;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }
        
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        
        std::cin>>r;
        
        if(!std::cin )
        {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }
        
        if(r<0)
        {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            i--;
            continue;
        }
        try
        {
            v.at(i)=std::make_shared<NepreklapajucaKugla>(x, y, z, r);
        }
        catch(std::logic_error poruka)
        {
            std::cout<<poruka.what()<<std::endl;
            i--;
            continue;
        }
    }
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> prvi, std::shared_ptr<NepreklapajucaKugla> drugi )
    {
        return prvi->DajPovrsinu() < drugi->DajPovrsinu();
    });
    
    std::cout<<"\nKugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> prvi)
    {
        prvi->Ispisi();
    });
    
    /*try
    {
        NepreklapajucaKugla(2, 3, 1, 5);
        std::cout<<"daa"<<std::endl;
        NepreklapajucaKugla(10, 7, 8, 2);
         std::cout<<"daa"<<std::endl;
        NepreklapajucaKugla(4, 6, 3, 7);
         std::cout<<"daa"<<std::endl;
    }
    catch(...)
    {
        std::cout<<"Izuzetak";
    }*/
    
	return 0;
}
