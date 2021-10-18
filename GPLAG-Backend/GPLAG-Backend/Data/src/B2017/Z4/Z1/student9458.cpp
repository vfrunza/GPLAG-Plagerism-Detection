/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
#include <cmath>
#include <algorithm>
class Kugla
{

    double R,X,Y,Z;
public:
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
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

Kugla::Kugla(double r)
{
    R=r;
    X=0;
    Y=0;
    Z=0;
}
Kugla::Kugla(double x,double y,double z,double r)
{

    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    X=x;
    Y=y;
    Z=z;
    R=r;

}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r )
{
    X=std::get<0>(centar);
    Y=std::get<1>(centar);
    Z=std::get<2>(centar);
    R=r;
}
double Kugla::DajX() const
{
    return X;
}
double Kugla::DajY() const
{
    return Y;
}
double Kugla::DajZ() const
{
    return Z;
}
std::tuple<double, double, double> Kugla::DajCentar() const
{

return std::make_tuple(X,Y,Z);
}
double Kugla::DajPoluprecnik() const
{
    return R;
}
double Kugla::DajPovrsinu() const
{
    return 4*R*R*4*atan(1);
}
double Kugla::DajZapreminu() const
{
    return 4/3*R*R*R*4*atan(1);
}
Kugla &Kugla::PostaviX(double x)
{
    X=x;
}
Kugla &Kugla::PostaviY(double y)
{
    Y=y;
}
Kugla &Kugla::PostaviZ(double z)
{
    Z=z;
}
Kugla &Kugla::PostaviCentar(double x, double y, double z)
{
    X=x;
    Y=y;
    Z=z;
}
Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{

}
Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    R=r;
}
void Kugla::Ispisi() const
{
    std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}";
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    X=X+delta_x;
    Y=Y+delta_y;
    Z=Z+delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(k1.DajX()==k2.DajX() &&k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ() && k1.DajPoluprecnik()==k2.DajPoluprecnik() ) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        if(k1.DajPoluprecnik()==k2.DajPoluprecnik()) return true;
         return false;
    }
     bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
         if(k1.DajCentar()==k2.DajCentar()) return true;
         return false;
     }
     bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        if(RastojanjeCentara(k1,k2)==k1.DajPoluprecnik()+k2.DajPoluprecnik()) return true;
        return false;
     }
     bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
         if(RastojanjeCentara(k1,k2)==abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())) return true;
         return false;
         
     }
     bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
         int razlika;
         if(k1.DajPoluprecnik()<k2.DajPoluprecnik()) razlika=k2.DajPoluprecnik()-k1.DajPoluprecnik();
         else razlika=k1.DajPoluprecnik()-k2.DajPoluprecnik();
         if(razlika>RastojanjeCentara(k1,k2)) return true;
         return false;
         
     }
     bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
         int razlika; 
         if(k1.DajPoluprecnik()<k2.DajPoluprecnik()) razlika=k2.DajPoluprecnik()-k1.DajPoluprecnik();
         else razlika=k1.DajPoluprecnik()-k2.DajPoluprecnik();
         int zbir=k1.DajPoluprecnik()+k2.DajPoluprecnik();
        
         if(razlika<RastojanjeCentara(k1,k2)  ) return true;
         return false;
     }
     
     
     
    bool Kugla::DaLiSadrzi(const Kugla &k) const{
        auto razlika=abs(DajPoluprecnik()-k.DajPoluprecnik());
     if(RastojanjeCentara(*this, k)<razlika) return true;    
         return false;
    }
    double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        double x=std::get<0>(k1.DajCentar())-std::get<0>(k2.DajCentar());
        double y=std::get<1>(k1.DajCentar())-std::get<1>(k2.DajCentar());
        double z=std::get<2>(k1.DajCentar())-std::get<2>(k2.DajCentar());
        double razlika=x*x+y*y+z*z;
        return  sqrt(razlika);
    }
int main ()
{
    double n;
    std::cout<<"Unesite broj kugla: ";
     while(!(std::cin>>n) || n<=0 || n!=int(n)){
    std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
      std::cin.clear();
     std::cin.ignore(1000,'\n');
 
    }
    std::vector<std::shared_ptr<Kugla>> v;
    for(int i=0; i<n; i++) {

        int  x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
   
        while(!(std::cin>>x) ||!(std::cin>>y)||!(std::cin>>z) ){
       
        std::cout<<"Neispravan centar"<<std::endl;
      std::cin.clear();
     std::cin.ignore(1000,'\n');
     std::cout<<"Unesite centar "<<i+1<<". kugle: ";
     
}
            int je=0;
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        if(!(std::cin>>r)){
            
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            r=-1;
        }
        try {
            v.push_back(std::make_shared<Kugla>(Kugla(x,y,z,r)));
        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
            i--;
        }


    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    int dx,dy,dz;
    while(!(std::cin>>dx) ||!(std::cin>>dy) || !(std::cin>>dz)){
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        
            std::cin.clear();
            std::cin.ignore(1000,'\n');
    
    }

    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,dz](std::shared_ptr<Kugla>x) {
        x->Transliraj(dx,dy,dz);
        return x;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> jedan,std::shared_ptr<Kugla>dva) {
        if(jedan->DajZapreminu()<dva->DajZapreminu()) return true;
        return false;
    });
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> x) {
        (*x).Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto it=std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> jedan,std::shared_ptr<Kugla>dva) {
        return jedan->DajPovrsinu()<dva->DajPovrsinu();
    });
    (*it)->Ispisi();
    std::cout <<std::endl;
    int brojac=0;
    int ispisani=0;
    std::for_each(v.begin(),v.end(),[v,&brojac,&ispisani](std::shared_ptr<Kugla>jedan){
        brojac++;
        std::for_each(v.begin()+brojac,v.end(),[jedan,&brojac,&ispisani](std::shared_ptr<Kugla> druga){
            if(DaLiSeSijeku(*jedan,*druga)){
                std::cout <<"Presjecaju se kugle: ";
                (*jedan).Ispisi();
                std::cout<<std::endl;
                (*druga).Ispisi();
                ispisani++;
                std::cout << std::endl;
            }});
        });

    if(ispisani==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
            
        

    return 0;
}
