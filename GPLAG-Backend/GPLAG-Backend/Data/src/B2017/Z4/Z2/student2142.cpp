/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;


const double pi=4*atan(1);
const double eps=0.000001;
bool Jednakost(double k1,double k2)
{
    return abs(k1-k2)<eps*(abs(k1)+abs(k2));
}



class NepreklapajucaKugla
{   
    double x,y,z,r;
    static NepreklapajucaKugla *prethodni;
           NepreklapajucaKugla *trenutni;
    static int br;
    
        bool DaLiSePreklapaju(NepreklapajucaKugla s,NepreklapajucaKugla *s1)
        {   
            
            while(s1->prethodni!=nullptr)
            { 
                
                s1->Ispisi();
                if(s.DaLiSadrzi(*s1->prethodni) && s1->prethodni!=nullptr)
                {
                    return true;
                }
               s1=s1->prethodni;
                
    
            }
            return false;
        }
        
    public:
       /* explicit NepreklapajucaKugla(double r = 0):x(0),y(0),z(0)
        {
            NepreklapajucaKugla::r;
        }*/
        NepreklapajucaKugla(double x, double y, double z, double r = 0)
        {    
                NepreklapajucaKugla::x=x;
                NepreklapajucaKugla::y=y;
                NepreklapajucaKugla::z=z;
                NepreklapajucaKugla::r=r;
                
                NepreklapajucaKugla *novi=this;
                
                
                
                
                if(br==0)
                {
                    prethodni=nullptr;
                    trenutni=novi;
                    
                }
                else 
                {   
                    NepreklapajucaKugla *temp=prethodni;
                    
                    while(temp!=nullptr)
                    {  
                        if(novi->DaLiSadrzi(*temp))
                            throw logic_error("Ne valja");
                        temp=temp->prethodni;
                    }
                    prethodni=novi->prethodni;
                    trenutni=novi;
                }
                
            br++;
        }
        explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0):
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
        NepreklapajucaKugla &PostaviX(double x)
        {
            NepreklapajucaKugla::x=x;
            return *this;
        }
        NepreklapajucaKugla &PostaviY(double y)
        {
            NepreklapajucaKugla::y=y;
            return *this;
        }
        NepreklapajucaKugla &PostaviZ(double z)
        {
            NepreklapajucaKugla::z=z;
            return *this;
        }
       
        NepreklapajucaKugla &PostaviCentar(double x, double y, double z)
        {
            NepreklapajucaKugla::x=x;
            NepreklapajucaKugla::y=y;
            NepreklapajucaKugla::z=z;
            return *this;
        }
       
        NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar)
        {
            NepreklapajucaKugla::x=get<0>(centar);
            NepreklapajucaKugla::y=get<1>(centar);
            NepreklapajucaKugla::z=get<2>(centar);
            return *this;
        }
       
        NepreklapajucaKugla &PostaviPoluprecnik(double r)
        {
            NepreklapajucaKugla::r=r;
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
       
        bool DaLiSadrzi(const NepreklapajucaKugla &k) const
        {
                if(this->DajPoluprecnik()<k.DajPoluprecnik())
                {
                    return RastojanjeCentara(*this,k)<k.DajPoluprecnik();
                }
              
               return (this->DajPoluprecnik()>RastojanjeCentara(*this,k)) ;
                   
                      
        }
       
        friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
        {
           double d=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
           return d;
        }
};



NepreklapajucaKugla *NepreklapajucaKugla::prethodni=nullptr;
//NepreklapajucaKugla *NepreklapajucaKugla::trenutni=nullptr;
int NepreklapajucaKugla::br=0;

int main ()
{
   int n;
   cout<<"Unesite broj kugli: ";
   cin>>n;
   vector<shared_ptr<NepreklapajucaKugla>> Lopte;
   
   for(int i=0;i<n;i++)
   {
       cout<<"Unesite centar za "<<i+1<<". kuglu: ";
       int x,y,z;
       cin>>x>>y>>z;
       cout<<"Unesite poluprecnik: ";
       double  r;
       cin>>r;
      
       try
       {
         Lopte.push_back(make_shared<NepreklapajucaKugla>(x,y,z,r));
        
       }
       catch(logic_error e)
       {
           //a=1;
           cout<<e.what()<<endl;
           i--;
       }
      // cout<<"Ovdje sam";//if(a) i--;
   }
   
  
   
   sort(Lopte.begin(),Lopte.end(),[](shared_ptr<NepreklapajucaKugla> s1,shared_ptr<NepreklapajucaKugla> s2)
            {
                double v1=s1->DajPovrsinu();
                double v2=s2->DajPovrsinu();
                
                return v1>v2;
            }
       );
    
    cout<<"Kugle nakon obavljenog sortiranja: "<<endl;
    for_each(Lopte.begin(),Lopte.end(),[](shared_ptr<NepreklapajucaKugla> s)
                {
                    s->Ispisi();
                }
            );
         
   	return 0;
}
