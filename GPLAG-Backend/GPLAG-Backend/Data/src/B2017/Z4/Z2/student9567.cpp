/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <tuple>
#include <memory>
#include <cmath>
#include <stdexcept>
#include <algorithm>

class NepreklapajucaKugla
{
   double x,y,z,r;
    const double PI = 4* atan(1);
    static constexpr long double EPS = 1e-10;


public :
  explicit NepreklapajucaKugla (double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        NepreklapajucaKugla::x=0;
        NepreklapajucaKugla::y=0;
        NepreklapajucaKugla::z=0;
    }
   NepreklapajucaKugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla (const std::tuple<double,double,double> &centar, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
       NepreklapajucaKugla::x=std::get<0>(centar);
       NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
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
    NepreklapajucaKugla &PostaviX (double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY (double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ (double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar (double x, double y, double z) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar (const std::tuple <double,double,double> &centar) {
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik (double r) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi () const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    }
    void Transliraj (double delta_x, double delta_y, double delta_z){
        NepreklapajucaKugla::x+=delta_x; NepreklapajucaKugla::y+=delta_y; NepreklapajucaKugla::z+=delta_z;
    }
   
    bool DaLiSadrzi (const NepreklapajucaKugla &k) const;
    friend  double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
bool JRB (const double x, const double y)
{
    const long double EPS = 1e-10;
    long double lijevo(fabs (x-y)), desno (EPS*(fabs (x)+ fabs (y)));
    if (lijevo<desno) return true;
    return false;
}


double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt (std::pow (k2.DajX()- k1.DajX(),2)  + std::pow (k2.DajY()- k1.DajY(),2)+ std::pow (k2.DajZ()- k1.DajZ(),2));
}

bool DaLiSePreklapaju (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
  if (RastojanjeCentara(k1,k2)<k1.DajPoluprecnik()+ k2.DajPoluprecnik()) return true;
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
    std::vector<std::shared_ptr<NepreklapajucaKugla>> objekti;
    for (int i(1); i<=n; i++) {
        double x(0), y(0), z(0), r(0);
        std::cout<<"Unesite centar "<<i<<". kugle: ";
        std::cin>>x>>y>>z;
        if (!std::cin) {
             std::cout<<"Ilegalan poluprecnik"<<std::endl;
        Oporavi();
        i--;
            continue;
             }
       std::cout<<"Unesite poluprecnik "<<i<<". kugle: ";
       std::cin>>r;
      
       try {
          NepreklapajucaKugla tr;
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
     std::shared_ptr<NepreklapajucaKugla> sfera= std::make_shared<NepreklapajucaKugla> (x,y,z,r);
       objekti.push_back(sfera);
      }
    tester=false;
    double dx(0), dy(0), dz(0);
     do {
  
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        std::cin>>dx>>dy>>dz;
        if (!std::cin) {
            Oporavi();
             dx=0 ; dy=0; dz=0;
        }
        else tester=true;
     } while (tester==false);
   
     
     
     std::transform (objekti.begin(),objekti.end(), objekti.begin() , [dx,dy,dz] (std::shared_ptr<NepreklapajucaKugla> ite) {
        ite->Transliraj(dx, dy, dz);
        return ite;
     });
     
     
     
     std::sort (objekti.begin(),objekti.end(), [] (std::shared_ptr<NepreklapajucaKugla> a1, std::shared_ptr<NepreklapajucaKugla> a2) {
         return a1->DajZapreminu()< a2->DajZapreminu();
     });
     std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
     std::for_each (objekti.begin(),objekti.end(), [] (std::shared_ptr<NepreklapajucaKugla> ax) {
         ax->Ispisi();
     });
     auto pok_na_max= *std::max_element (objekti.begin(), objekti.end(), [] (std::shared_ptr<NepreklapajucaKugla> neka_1, std::shared_ptr<NepreklapajucaKugla> neka_2) {
         return neka_1->DajPovrsinu()< neka_2->DajPovrsinu();
     });
     std::cout<<"Kugla sa najvecom povrsinom je: ";
     pok_na_max->Ispisi();
   
     bool sjeca=false;
     int br=0;
     std::vector<std::tuple<int,int,int,int>> norm;
    std::vector<std::tuple<int,int,int ,int>> kontra;
     std::for_each (objekti.begin(), objekti.end(), [&objekti , &norm, &kontra, &pm, &sjeca] (std::shared_ptr<NepreklapajucaKugla> A){
         std::for_each (objekti.begin()+br, objekti.end (), [&objekti,A, &norm, &kontra, &pm, &sjeca] (std::shared_ptr<NepreklapajucaKugla> B){
             if (DaLiSeSijeku(*A,*B)) {
              std::tuple<int,int,int,int> norma= std::make_tuple (A->DajX(),A->DajY(), A->DajZ(), A->DajPoluprecnik());
                 sjeca=true;
               //   std::pair<Kugla,Kugla> kontraa= std::make_pair (*B,*A); 
             //   std::count (kontra.begin(), kontra.end(), kontraa);
            // std::find (norm.begin(), norm.end(), norma);
                 if ((norm.size()>=0)  ) {
                    if (sjeca==true) std::cout<<"Presjecaju se kugle: ";
                 
                 A->Ispisi(); B->Ispisi();
              //   std::pair<Kugla,Kugla> norma= std::make_pair (*A,*B);
              //   norm.push_back(norma);
              //    std::pair<Kugla,Kugla> kontraa= std::make_pair (*B,*A);
              //    kontra.push_back(kontraa);
                 }
             }
             
         }) ;
         
         
        }); 
 if (sjeca==false) std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}
