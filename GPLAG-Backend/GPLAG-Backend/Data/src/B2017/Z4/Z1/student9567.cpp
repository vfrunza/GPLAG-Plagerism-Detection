/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <tuple>
#include <memory>
#include <cmath>
#include <stdexcept>
#include <algorithm>

class Kugla
{
   double x,y,z,r;
    const double PI = 4* atan(1);
    static constexpr long double EPS = 1e-10;


public :
 

    explicit Kugla (double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=0;
        Kugla::y=0;
        Kugla::z=0;
    }
    Kugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla (const std::tuple<double,double,double> &centar, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple <double, double, double> DajCentar () const {
        auto Vrati= std::make_tuple (x,y,z);
        return Vrati;
    }
    double DajPoluprecnik () const {
        return r;
    }
    double DajPovrsinu () const {
        return 4*std::pow (r,2)*PI;
    }
    double DajZapreminu () const {
        return (4/3)*std::pow (r,3)*PI;
    }
    Kugla &PostaviX (double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY (double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ (double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar (double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar (const std::tuple <double,double,double> &centar) {
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik (double r) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi () const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    }
    void Transliraj (double delta_x, double delta_y, double delta_z){
        Kugla::x+=delta_x; Kugla::y+=delta_y; Kugla::z+=delta_z;
    }
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) ;
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) ;
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) ;
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const;
    friend  double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};

bool Kugla::DaLiSadrzi (const Kugla &k) const {
    if (k.DajPoluprecnik()> DajPoluprecnik()) return true;
    return false;
}
bool JRB (const double x, const double y)
{
    const long double EPS = 1e-10;
    long double lijevo(fabs (x-y)), desno (EPS*(fabs (x)+ fabs (y)));
    if (lijevo<desno) return true;
    return false;
}
bool DaLiSuKoncentricne ( const Kugla &k1, Kugla &k2)
{
    if ((JRB(k1.DajX(), k2.DajX()) && JRB(k1.DajY(), k2.DajY()) && JRB(k1.DajZ(), k2.DajZ()))) return true;
    return false;
}

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2)
{
    if (JRB(k1.DajX(), k2.DajX()) && JRB(k1.DajY(), k2.DajY()) && JRB(k1.DajZ(), k2.DajZ()) && JRB(k1.DajPoluprecnik(), k2.DajPoluprecnik()) ) return true;
    return false;
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    if( JRB(k1.DajPoluprecnik(), k2.DajPoluprecnik())) return true;
    return false;
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2)
{
    if (JRB (RastojanjeCentara(k1,k2), k1.DajPoluprecnik()+k2.DajPoluprecnik())) return true;
    return false;
}
//mozda bude problem
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2)
{
    if (JRB(RastojanjeCentara(k1,k2) , fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
    return false;
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2)
{
    return std::sqrt (std::pow (k2.DajX()- k1.DajX(),2)  + std::pow (k2.DajY()- k1.DajY(),2)+ std::pow (k2.DajZ()- k1.DajZ(),2));
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2)
{
  if (RastojanjeCentara(k1,k2)<k1.DajPoluprecnik()+ k2.DajPoluprecnik()) return true;
  return false;
}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2)
//R1-R2<rastojanje<r1+r2
{
    if ((RastojanjeCentara(k1,k2)<k1.DajPoluprecnik()+ k2.DajPoluprecnik()) &&  (RastojanjeCentara(k1,k2)>fabs(k1.DajPoluprecnik()- k2.DajPoluprecnik())) ) return true;
  return false;
}

 void Oporavi () {
     
    std::cin.clear();
    std::cin.ignore (10000, '\n');
 }


int main ()
{
    
    int n;
    bool tester=false;
    std::cout<<"Unesite broj kugla: ";
   do {
     
    std::cin>>n;
    if (n<=0) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        Oporavi();  
        continue;
    }
    if (!std::cin)  { 
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        Oporavi();  
    continue;}
     tester=true;
    } while (tester==false);
    if (n==0) return 0;
    std::vector<std::shared_ptr<Kugla>> objekti;
    for (int i(1); i<=n; i++) {
        double x(0), y(0), z(0), r(0);
        std::cout<<"Unesite centar "<<i<<". kugle: ";
        std::cin>>x>>y>>z;
        if (!std::cin) {
             std::cout<<"Neispravan centar"<<std::endl;
        Oporavi();
        i--;
            continue;
             }
       std::cout<<"Unesite poluprecnik "<<i<<". kugle: ";
       std::cin>>r;
      
       try {
           Kugla tr;
           tr.PostaviPoluprecnik(r);
       }
       catch (std::domain_error e) {
           std::cout<<e.what()<<std::endl;
           i--;
           continue;
       } 
   if (!std::cin) {
       std::cout<<"Ilegalan poluprecnik"<<std::endl;
        Oporavi();
        i--;
        continue;
             } 
     std::shared_ptr<Kugla> sfera= std::make_shared<Kugla> (x,y,z,r);
       objekti.push_back(sfera);
      }
    tester=false;
     std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx(0), dy(0), dz(0);
     do {
  
       
        std::cin>>dx>>dy>>dz;
        if (!std::cin) {
            Oporavi();
            std::cout<<"Neispravni parametri translacije, unesite ponovo!";
              std::cout<<std::endl;
             dx=0 ; dy=0; dz=0;
        }
        else tester=true;
     } while (tester==false);
 
     std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
     
     std::transform (objekti.begin(),objekti.end(), objekti.begin() , [dx,dy,dz] (std::shared_ptr<Kugla> ite) {
        ite->Transliraj(dx, dy, dz);
        return ite;
     });
     
     
     
     std::sort (objekti.begin(),objekti.end(), [] (std::shared_ptr<Kugla> a1, std::shared_ptr<Kugla> a2) {
         return a1->DajZapreminu()< a2->DajZapreminu();
     });
     
     std::for_each (objekti.begin(),objekti.end(), [] (std::shared_ptr<Kugla> ax) {
         ax->Ispisi();
     });
     auto pok_na_max= *std::max_element (objekti.begin(), objekti.end(), [] (std::shared_ptr<Kugla> neka_1, std::shared_ptr<Kugla> neka_2) {
         return neka_1->DajPovrsinu()< neka_2->DajPovrsinu();
     });
     std::cout<<"Kugla sa najvecom povrsinom je: ";
     pok_na_max->Ispisi();
   
     bool sjeca=false;
     int br=0;
     std::vector<std::tuple<int,int,int,int>> norm;
    std::vector<std::tuple<int,int,int ,int>> kontra;
     std::for_each (objekti.begin(), objekti.end(), [&objekti , &norm, &kontra, &br, &sjeca] (std::shared_ptr<Kugla> A){
         std::for_each (objekti.begin()+br, objekti.end (), [&objekti,A, &norm, &kontra, &br, &sjeca] (std::shared_ptr<Kugla> B){
             if (DaLiSeSijeku(*A,*B)) {
            
                 sjeca=true;
               //   std::pair<Kugla,Kugla> kontraa= std::make_pair (*B,*A); 
             //   std::count (kontra.begin(), kontra.end(), kontraa);
            // std::find (norm.begin(), norm.end(), norma);
              
                    if (sjeca==true) std::cout<<"Presjecaju se kugle: ";
                 
                 A->Ispisi(); B->Ispisi();
                 br++;
              //   std::pair<Kugla,Kugla> norma= std::make_pair (*A,*B);
              //   norm.push_back(norma);
              //    std::pair<Kugla,Kugla> kontraa= std::make_pair (*B,*A);
              //    kontra.push_back(kontraa);
                 }
             
             
         }) ;
         
         
        }); 
 if (sjeca==false) std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}
