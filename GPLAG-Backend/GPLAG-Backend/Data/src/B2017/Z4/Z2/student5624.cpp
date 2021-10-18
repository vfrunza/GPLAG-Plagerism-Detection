/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <algorithm>

using std::cout;
using std::cin;
using std::get;
using std::vector;
using std::shared_ptr;

const double Pi=4*atan(1);
bool Jednakost(double x, double y);
class NepreklapajucaKugla
{
    double r, x, y, z;
    NepreklapajucaKugla *prethodni;
    static NepreklapajucaKugla *stat_prethodni;
    bool DaLiPostoji()
    {
        NepreklapajucaKugla *k1 = this;
        NepreklapajucaKugla *k2 = stat_prethodni;
        while(k2 != nullptr)
        {
            double r1, r2;
            r1=k1->DajPoluprecnik();
            r2=k2->DajPoluprecnik();
            if((RastojanjeCentara(*k1, *k2) < r1 + r2 || Jednakost(RastojanjeCentara(*k1, *k2), r1+r2)) && k1!=k2)
                return true;
           k2=k2->prethodni;
        }
        //if(k2 == nullptr)
            return false;
    }
    public:
    explicit NepreklapajucaKugla(double r = 0)
    {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        x=0; y=0; z=0;
        if (DaLiPostoji()==false)
        {
            prethodni=stat_prethodni;
            stat_prethodni=this;
        }
        else
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0)
    { 
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
        if (DaLiPostoji()==false)
        {
            prethodni=stat_prethodni;
            stat_prethodni=this;
        }
        else    
            throw std::logic_error("Nedozvoljeno preklapanje");
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0)
    {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        NepreklapajucaKugla::r=r;
        if (DaLiPostoji()==false)
        {
            prethodni=stat_prethodni;
            stat_prethodni=this;
        }
        else
            throw std::logic_error("Nedozvoljeno preklapanje");
    }
    
    ~NepreklapajucaKugla();
    
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const
    {
        double a, b, c;
        a=x; b=y; c=z;
        std::tuple<double, double, double> centar;
        centar=std::make_tuple(a, b, c);
        return centar;
    }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*Pi; } 
    double DajZapreminu() const { return 4/3.*r*r*r*Pi; }
    NepreklapajucaKugla &PostaviX(double x)
    {
        double stari_x;
        stari_x=NepreklapajucaKugla::x;
        NepreklapajucaKugla::x=x;
        if (DaLiPostoji())
        {
            NepreklapajucaKugla::x=stari_x;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }    
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y)
    {
        double stari_y;
        stari_y=NepreklapajucaKugla::y;
        NepreklapajucaKugla::y=y;
        if (DaLiPostoji())
        {
            NepreklapajucaKugla::y=stari_y;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }    
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z)
    {
        double stari_z;
        stari_z=NepreklapajucaKugla::z;
        NepreklapajucaKugla::z=z;
        if (DaLiPostoji())
        {
            NepreklapajucaKugla::z=stari_z;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }    
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z)
    {
        double stx, sty, stz;
        stx=NepreklapajucaKugla::x;
        sty=NepreklapajucaKugla::y;
        stz=NepreklapajucaKugla::z;
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
        if (DaLiPostoji())
        {
            NepreklapajucaKugla::x=stx;
            NepreklapajucaKugla::y=sty;
            NepreklapajucaKugla::z=stz;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }    
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        double stx, sty, stz;
        stx=NepreklapajucaKugla::x;
        sty=NepreklapajucaKugla::y;
        stz=NepreklapajucaKugla::z;
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        if (DaLiPostoji())
        {
            NepreklapajucaKugla::x=stx;
            NepreklapajucaKugla::y=sty;
            NepreklapajucaKugla::z=stz;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }    
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r)
    {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        double str;
        str=NepreklapajucaKugla::r;
        NepreklapajucaKugla::r=r;
        if (DaLiPostoji())
        {
            NepreklapajucaKugla::r=str;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }    
        return *this;
    }
    void Ispisi() const
    {
        cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        double stx, sty, stz;
        stx=NepreklapajucaKugla::x;
        sty=NepreklapajucaKugla::y;
        stz=NepreklapajucaKugla::z;
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
         if (DaLiPostoji())
        {
            NepreklapajucaKugla::x=stx;
            NepreklapajucaKugla::y=sty;
            NepreklapajucaKugla::z=stz;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }    
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

bool Jednakost(double x, double y)
{
    double eps=1e-10;
    if ((x<0 && y>0) || (x>0 && y<0))
        return false;
    if (!(std::fabs(x-y)<=eps*(std::fabs(x) + std::fabs(y))))
        return false;
    return true;    
}

NepreklapajucaKugla::~NepreklapajucaKugla()
{
    if(this==stat_prethodni)
    {
        stat_prethodni=this->prethodni;
        return;
    }
    NepreklapajucaKugla *pok1;
    pok1=stat_prethodni;
    while(pok1 && pok1->prethodni!=this)
        pok1=pok1->prethodni;
    
    pok1->prethodni=this->prethodni;    
}

bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    if (Jednakost(k1.DajX(), k2.DajX()) == false)
        return false;
    if (Jednakost(k1.DajY(), k2.DajY()) == false)
        return false;
    if (Jednakost(k1.DajZ(), k2.DajZ()) == false)
        return false;
    if (Jednakost(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == false)
        return false;
    return true;    
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    double d, a, b, c;
    a=k1.DajX() - k2.DajX();
    b=k1.DajY() - k2.DajY();
    c=k1.DajZ() - k2.DajZ();
    d=std::sqrt(a*a + b*b + c*c);
    return d;
}

bool DaLiSadrzi(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    double d;
    d=RastojanjeCentara(k1, k2);
    double r1, r2;
    if (k1.DajPoluprecnik() >= k2.DajPoluprecnik())
    {
        r1=k1.DajPoluprecnik();
        r2=k2.DajPoluprecnik();
    }
    else
    {
        r1=k2.DajPoluprecnik();
        r2=k1.DajPoluprecnik();
    }
    return ((d<r1 + r2) && (!(d>r1 - r2)));
}
NepreklapajucaKugla *NepreklapajucaKugla::stat_prethodni = nullptr;

int main ()
{
    int n, br(0);
    cout<<"Unesite broj kugli: ";
    do
    {
        if (br!=0)
        {
            cin.clear();
            cin.ignore(10000,'\n');
        }    
        cin>>n;
        if (n<=0 || !cin)
        {
           // cin.clear();
           // cin.ignore(10000,'\n');
            cout<<"Neispravan broj kugli, unesite ponovo!\n";
            br++;
        }
    }while(n<=0 || !cin);
    
    try
    {
        vector<shared_ptr<NepreklapajucaKugla>> vektor(n);
        int i=0;
        bool pogresan_unos(true);
        for(int k=0; k<n; k++)
        {
            pogresan_unos=true;
            while(pogresan_unos)
            {
                double x, y, z, r;
                try
                {
                    cout<<"Unesite centar za "<<i+1<<". kuglu: ";
                    cin>>x>>y>>z;
                    while (!cin)
                    {
                        cout<<"Neispravan centar, unesite ponovo: \n";
                        cin.clear();
                        cin.ignore(10000,'\n');
                        cin >> x >> y >> z;
                    }    
                    cout<<"Unesite poluprecnik: ";
                    cin>>r;
                    while (!cin || r<0)
                    {
                        cout<<"Neispravan poluprecnik, unesite ponovo: \n";
                        cin.clear();
                        cin.ignore(10000,'\n');
                        cin>>r;
                    }
                
                
                shared_ptr<NepreklapajucaKugla> pok;
                
                    pok=std::make_shared<NepreklapajucaKugla>(x, y, z, r);
                    vektor[i]=pok;
                    i++;
                }
                catch(std::logic_error izuzetak)
                {
                    cout<<izuzetak.what()<<"\n";
                    continue;
                }
                catch(...)
                {
                    throw;
                }
                pogresan_unos=false;
            }
            
        }
       /* double delta_x, delta_y, delta_z;
        cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        br=0;
        do
        {
            if (br!=0)
            {
                cin.clear();
                cin.ignore(10000,'\n');
            }   
            cin>>delta_x>>delta_y>>delta_z;
            if (!cin)
            {
                cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            }
        }while(!cin);  */  
       
        std::sort(vektor.begin(), vektor.end(), [] (shared_ptr<NepreklapajucaKugla> pok1, shared_ptr<NepreklapajucaKugla> pok2)
        {
            return pok1->DajPovrsinu() < pok2->DajPovrsinu();  
        });
        
        cout<<"\nKugle nakon obavljenog sortiranja: ";
        std::for_each(vektor.begin(), vektor.end(), [] (shared_ptr<NepreklapajucaKugla> pok)
        {
            cout<<"\n";
            pok->Ispisi();
        });
    }
    catch(...)
    {
        cout<<"Nedovoljno memorije";
    }
return 0;
}
