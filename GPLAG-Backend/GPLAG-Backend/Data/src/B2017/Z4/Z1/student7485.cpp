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

class Kugla
{
    double r, x, y, z;
    
    public:
    explicit Kugla(double r = 0)
    {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        x=0; y=0; z=0;
    }
    Kugla(double x, double y, double z, double r = 0)
    { 
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0)
    {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        Kugla::r=r;
    }
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
    Kugla &PostaviX(double x)
    {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y)
    {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z)
    {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z)
    {
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r)
    {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const
    {
        cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
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


bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
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

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if (Jednakost(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == true)
        return true;
    return false;    
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if (Jednakost(k1.DajX(), k2.DajX()) == false)
        return false;
    if (Jednakost(k1.DajY(), k2.DajY()) == false)
        return false;
    if (Jednakost(k1.DajZ(), k2.DajZ()) == false)
        return false;
    return true;    
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    double d, a, b, c;
    a=k1.DajX() - k2.DajX();
    b=k1.DajY() - k2.DajY();
    c=k1.DajZ() - k2.DajZ();
    d=std::sqrt(a*a + b*b + c*c);
    return d;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
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
    double rez;
    rez=r1-r2;
    return (Jednakost(rez, d));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double d;
    d=RastojanjeCentara(k1, k2);
    double r1, r2;
    r1=k1.DajPoluprecnik();
    r2=k2.DajPoluprecnik();
    double rez;
    rez=r1 + r2;
    return (Jednakost(rez, d));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    double r1, r2;
    r1=k1.DajPoluprecnik();
    r2=k2.DajPoluprecnik();
    return RastojanjeCentara(k1, k2) < r1 + r2;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
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
    return ((d<r1+r2) && (d>r1-r2));
}

bool DaLiSadrzi(const Kugla &k1, const Kugla &k2)
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

int main ()
{
    int n, br(0);
    cout<<"Unesite broj kugla: ";
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
        vector<shared_ptr<Kugla>> vektor(n);
        //int i=0;
        bool pogresan_unos(true);
        for(int i=0; i<n; i++)
        {
            pogresan_unos=true;
            while(pogresan_unos)
            {
                double x, y, z, r;
                cout<<"Unesite centar "<<i+1<<". kugle: ";
                cin>>x>>y>>z;
                if (!cin)
                {
                    cout<<"Neispravan centar\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                        continue;
                }    
                cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                cin>>r;
                if (!cin || r<0)
                {
                    cout<<"Ilegalan poluprecnik\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                    continue;
                }
              //  pogresan_unos=false;
                shared_ptr<Kugla> pok;
                try
                {
                    pok=std::make_shared<Kugla>(x, y, z, r);
                    vektor[i]=pok;
                   // i++;
                }
                catch(...)
                {
                    throw;
                }
                pogresan_unos=false;
            }
            
        }
        double delta_x, delta_y, delta_z;
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
                br++;
            }
        }while(!cin);    
       std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x, delta_y, delta_z](shared_ptr<Kugla> pok)
        {
            pok->Transliraj(delta_x, delta_y, delta_z);
            return pok;
        });
        
       std::sort(vektor.begin(), vektor.end(), [] (shared_ptr<Kugla> pok1, shared_ptr<Kugla> pok2)
        {
            return pok1->DajZapreminu() < pok2->DajZapreminu();  
        });
        
        cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
        std::for_each(vektor.begin(), vektor.end(), [] (shared_ptr<Kugla> pok)
        {
            cout<<"\n";
            pok->Ispisi();
        });
        
        auto povrs=*std::max_element(vektor.begin(), vektor.end(), [] (shared_ptr<Kugla> pok1, shared_ptr<Kugla> pok2)
        {
            return pok1->DajPovrsinu() < pok2->DajPovrsinu();
        });
        cout<<"\nKugla sa najvecom povrsinom je: ";
        povrs -> Ispisi();
        int brojac(0);
        std::for_each(vektor.begin(), vektor.end(), [&vektor, &brojac](shared_ptr<Kugla> &pok1)
        {
            std::for_each(vektor.begin(), vektor.end(), [&pok1, &brojac](shared_ptr<Kugla> &pok2)
            {
                
                if(&pok2 > &pok1)
                {
                    if(DaLiSeSijeku(*pok1, *pok2))
                    {
                        cout<<"\nPresjecaju se kugle: ";
                        pok1->Ispisi();
                        cout<<"\n";
                        pok2->Ispisi();
                        brojac++;
                    }
                }
            });
        }
        );
        if (brojac==0)
            cout<<"\nNe postoje kugle koje se presjecaju!";
    }
    catch(...)
    {
        cout<<"Nedovoljno memorije";
    }
	return 0;
}
