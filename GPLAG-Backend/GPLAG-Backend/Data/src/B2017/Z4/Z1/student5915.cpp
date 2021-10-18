/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
const double pi=4*atan(1);
const double epsilon=pow(10,-10);
class Kugla
{
    double x,y,z;
    double r;
public:
    explicit Kugla (double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    
    Kugla (double x,double y,double z,double r=0) {
    if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
    }
    explicit Kugla (const std::tuple<double,double,double> &centar,double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
    
        Kugla::r=r;
        
        
    }
    double DajX () const {
        return x;
    }
    double DajY () const {
        return y;
    }
    double DajZ () const {
        return z;
    }
    std::tuple<double,double,double> DajCentar () const {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu () const {
        return 4*DajPoluprecnik()*DajPoluprecnik()*pi;
    }
    double DajZapreminu () const {
        return (4./3)*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*pi;
    }
    Kugla &PostaviX (double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY (double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar (double x,double y,double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviPoluprecnik (double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    
    Kugla &PostaviCentar( const std::tuple<double,double,double> &centar) {
       x= std::get<0>(centar);
       y= std::get<1>(centar);
       z= std::get<2>(centar);
        return *this;
    }


    void Ispisi () const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    }

    void Transliraj (double deltax,double deltay,double deltaz) {
        x+=deltax;
        y+=deltay;
        z+=deltaz;
    }

    friend bool DaliSuIdenticne (const Kugla &k1,  const Kugla &k2)  {
        if (fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<=epsilon*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik())) && RastojanjeCentara(k1, k2)<=epsilon) return true;
        return false;
    }
    friend bool DaLiSuPodudarne (const Kugla &k1,const Kugla &k2) {
        if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<=epsilon*(fabs(k1.DajPoluprecnik()+fabs(k2.DajPoluprecnik())))) return true;
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2) {
        if(k1.DajCentar()==k2.DajCentar()) return true;
        return false;
    }
    friend double  RastojanjeCentara(const Kugla &k1,const Kugla &k2 ) {
        return sqrt(fabs((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ())));
    }
     friend bool DaLiSeDodirujuIzvana (const Kugla &k1,const Kugla &k2) {
         if(fabs(RastojanjeCentara(k1,k2)-fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))<=epsilon*fabs(RastojanjeCentara(k1,k2)+fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
         return false;
     } 
 friend bool DaLiSeDodirujuIznutra (const Kugla &k1,const Kugla &k2) 
 {
     if(fabs(RastojanjeCentara(k1,k2)-(k1.DajPoluprecnik()+k2.DajPoluprecnik())<=epsilon*(fabs(RastojanjeCentara(k1,k2)+fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik()))))) return true;
     return false;
 }
 friend bool DaLiSeSijeku (const Kugla &k1,const Kugla &k2) {
    
    
   if(RastojanjeCentara(k1,k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && ( RastojanjeCentara(k1,k2) >fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
   return false;
}
    
 friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2) {
    if(DaLiSeSijeku(k1,k2)==true || (RastojanjeCentara(k1,k2)<=fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
    return false;
}
bool DaLiSadrzi(const Kugla &k)  {
    if(RastojanjeCentara(*this,k)< fabs(this->DajPoluprecnik()-k.DajPoluprecnik())) return true;
    return false;
}

};
        
int main () {
  std::vector<std::shared_ptr<Kugla>> v;
  
int n,x,y,z,r;

  std::cout<<"Unesite broj kugla: ";
 
  std::cin>>n;
  while (!std::cin || n<=0) {
      std::cin.clear();
      std::cin.ignore(10000,'\n');
      std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
      std::cin>>n;
  }
  for(int i=0;i<n;i++) {
      
  
  std::cout<<"Unesite centar "<<i+1<<". kugle: " ;
  std::cin>>x>>y>>z;
  if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(10000,'\n');
      std::cout<<"Neispravan centar"<<std::endl;
      i--;
      continue;
  }
  std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
  std::cin>>r;
      if (!std::cin || r<0) {
          std::cin.clear();
          std::cin.ignore(10000,'\n');
          std::cout<<"Ilegalan poluprecnik"<<std::endl;
          i--;
          continue;
      }
      try {
        v.push_back(std::make_shared<Kugla>(x,y,z,r)) ;
      }
      catch(std::exception &izuzetak) {
          std::cout << izuzetak.what();
      }
      }
double delta_x,delta_y,delta_z;
  std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
std::cin>>delta_x>>delta_y>>delta_z;
  while(!std::cin) {
      std::cin.clear();
      std::cin.ignore(10000,'\n');
      std::cout<<"Neispravni parametri translacije, unesite ponovo!" <<std::endl;
      std::cin>>delta_x>>delta_y>>delta_z;
  }
  
 
 std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;

  std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> k){ k->Transliraj(delta_x,delta_y,delta_z); return k;});
  std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2) {
      if(k1->DajZapreminu()<k2->DajZapreminu()) return true;
      return false;
  });
  std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla>k) {
      k->Ispisi();
  });
  auto p=std::max_element(v.begin(),v.end(),[] (std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) {
      if(k1->DajPovrsinu()<k2->DajPovrsinu()) return true;
      return false;
  });
  std::cout<<"Kugla sa najvecom povrsinom je: ";
  (*p)-> Ispisi();
  bool biopresjek (false);
  int indeks=0;
  std::for_each(v.begin(),v.end(),[&biopresjek,v,&indeks] 
     (std::shared_ptr<Kugla> k) {
         indeks ++;
         std::for_each(v.begin()+indeks,v.end(),[&biopresjek,k](std::shared_ptr<Kugla> k2) {
             if(DaLiSeSijeku(*k,*k2)) {
                 biopresjek=true;
                 std::cout << "Presjecaju se kugle: ";
                 k-> Ispisi();
                 k2->Ispisi();
             }
         
         });
     });
      
     if (!biopresjek) std::cout << "Ne postoje kugle koje se presjecaju!";
    
      
                 
                 
                 
    return 0;
}