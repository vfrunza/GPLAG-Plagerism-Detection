/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;


const double pi=4*atan(1);
const double eps=0.000001;
bool Jednakost(double k1,double k2)
{
    return abs(k1-k2)<eps*(abs(k1)+abs(k2));
}

class Kugla
{   
    double x,y,z,r;
    public:
    explicit Kugla(double r = 0):x(0),y(0),z(0)
    {
        r=0;
    }
    Kugla(double x, double y, double z, double r = 0):x(x),y(y),z(z),r(r){};
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0):
        x(get<0>(centar)),y(get<1>(centar)),z(get<2>(centar)),r(r){};
    double DajX() const{ return x;}
    double DajY() const{ return y;}
    double DajZ() const{ return z;}
    std::tuple<double, double, double> DajCentar() const
    {
        return make_tuple(x,y,z);
    }
    double DajPoluprecnik() const
    {
        return r;
    }
    double DajPovrsinu() const
    {
        return r*r*pi;
    }
    double DajZapreminu() const
    {
        return (4/3)*r*r*r*pi;
    }
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
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        Kugla::x=get<0>(centar);
        Kugla::y=get<1>(centar);
        Kugla::z=get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r)
    {
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const
    {
        cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<endl;
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        x=x+delta_x;
        y=y+delta_y;
        z=z+delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
    {
        return Jednakost(k1.DajX(),k2.DajX()) && Jednakost(k1.DajY(),k2.DajY()) && 
            Jednakost(k1.DajZ(),k2.DajZ()) && Jednakost(k1.DajPoluprecnik(),k2.DajPoluprecnik());
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
    {
        return Jednakost(k1.DajPoluprecnik(),k2.DajPoluprecnik());
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
    {
        return Jednakost(get<0>(k1.DajCentar()),get<0>(k2.DajCentar()))
         &&    Jednakost(get<1>(k1.DajCentar()),get<1>(k2.DajCentar()))
         &&    Jednakost(get<2>(k1.DajCentar()),get<2>(k2.DajCentar()));
         
    }
   
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
    {
        if(k1.DajPoluprecnik()<k2.DajPoluprecnik())
        {
           return Jednakost(k2.DajPoluprecnik()+k1.DajPoluprecnik(),RastojanjeCentara(k1,k2));
       
        }
        
        return Jednakost(k1.DajPoluprecnik()+k2.DajPoluprecnik(),RastojanjeCentara(k1,k2));
       
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
    {
        
        if(k1.DajPoluprecnik()<k2.DajPoluprecnik())
        {
           return Jednakost(k2.DajPoluprecnik()-k1.DajPoluprecnik(),RastojanjeCentara(k1,k2));
       
        }
        
        return Jednakost(k1.DajPoluprecnik()-k2.DajPoluprecnik(),RastojanjeCentara(k1,k2));
       
    }
   
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
    {
        
        
        return (k1.DajPoluprecnik()+k2.DajPoluprecnik()<RastojanjeCentara(k1,k2)) 
            && (k2.DajPoluprecnik()-k1.DajPoluprecnik()>RastojanjeCentara(k1,k2));
                
       
    }
   
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
    {
        if(k1.DajPoluprecnik()<k2.DajPoluprecnik())
        {
           return (k2.DajPoluprecnik()+k1.DajPoluprecnik()>RastojanjeCentara(k1,k2) && k2.DajPoluprecnik()-k1.DajPoluprecnik()<RastojanjeCentara(k1,k2));
       
        }
        
         return (k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2) && k1.DajPoluprecnik()-k2.DajPoluprecnik()<RastojanjeCentara(k1,k2));
       
    }
   
    bool DaLiSadrzi(const Kugla &k) const
    {
           return (this->DajPoluprecnik()<RastojanjeCentara(*this,k)) 
               && (k.DajPoluprecnik()>RastojanjeCentara(*this,k));
                  
    }
   
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
    {
       double r=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
       return r;
    }
};



int main ()
{
   int n;
   cout<<"Unesite broj kugla: ";
   cin>>n;
   vector<shared_ptr<Kugla>> Lopte;
   
   for(int i=0;i<n;i++)
   {
       cout<<"Unesite centar "<<i+1<<". kugle: ";
       int x,y,z;
       cin>>x>>y>>z;
       cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
       double  r;
       cin>>r;
       Lopte.push_back(make_shared<Kugla>(x,y,z,r));
   }
   
   cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
   int dx,dy,dz;
   cin>>dx>>dy>>dz;
   transform(Lopte.begin(),Lopte.end(),Lopte.begin(),[dx,dy,dz](shared_ptr<Kugla> s)
   {
       s->Transliraj(dx,dy,dz);
       return s;
   });
   
   sort(Lopte.begin(),Lopte.end(),[](shared_ptr<Kugla> s1,shared_ptr<Kugla> s2)
            {
                double v1=s1->DajZapreminu();
                double v2=s2->DajZapreminu();
                
                return v1<v2;
            }
       );
    
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    for_each(Lopte.begin(),Lopte.end(),[](shared_ptr<Kugla> s)
                {
                    s->Ispisi();
                }
            );
            
    auto s=max_element(Lopte.begin(),Lopte.end(),[](shared_ptr<Kugla>s1,shared_ptr<Kugla>s2)
                {
                    return s1->DajPovrsinu()<s2->DajPovrsinu();    
                }
            );
    cout<<"Kugla sa najvecom povrsinom je: "; 
    s->get()->Ispisi();
    bool flag=0;int br=-1;
    
    vector<shared_ptr<Kugla>>::iterator it=Lopte.begin();
    vector<shared_ptr<Kugla>>::iterator it1=Lopte.end();
    
    for_each(Lopte.begin(),Lopte.end(),[&flag,&br,&it,it1](shared_ptr<Kugla> s1)
            {   
                it++;
                for_each(it,it1,[&flag,s1](shared_ptr<Kugla> s2)
                {
                    if(DaLiSeSijeku(*s1,*s2))
                    {   
                        flag=1;
                        cout<<"Presjecaju se kugle: ";
                        s1->Ispisi();
                        s2->Ispisi();
                    }
                });      
                
            });
     
    if(!flag) cout<<"Ne postoje kugle koje se presjecaju!";       
	return 0;
}
