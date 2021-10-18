/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <cmath>

 const double PI(4*std::atan(1));
 const double eps(1e-10);
 bool Jednakost(double prvi, double drugi){
     return std::abs(prvi-drugi)<eps*(std::abs(prvi)+std::abs(drugi));
 }

class NepreklapajucaKugla{
    double x,y,z, r;
    NepreklapajucaKugla*veza;
    static NepreklapajucaKugla* zajednicki;
    static void DaLiSeNalazi(double x,double y, double z,double r){
        NepreklapajucaKugla*pok=NepreklapajucaKugla::zajednicki; 
       while(pok!=nullptr){
           
          //double udaljenost=std::sqrt((x-(*pok).x) * (x-(*pok).x)+(y-(*pok).y)*(y-(*pok).y)+(z-(*pok).z)*(z-(*pok).z)); 
if(((*pok).r+r)>std::sqrt((x-(*pok).x) * (x-(*pok).x)+(y-(*pok).y)*(y-(*pok).y)+(z-(*pok).z)*(z-(*pok).z))
||Jednakost((*pok).r+r, std::sqrt((x-(*pok).x) * (x-(*pok).x)+(y-(*pok).y)*(y-(*pok).y)+(z-(*pok).z)*(z-(*pok).z)))) 
            throw std::logic_error("Nedozvoljeno preklapanje");
            pok=pok->veza;
        }  
    }
    // za provjeru lanca;
    
  
    
    public:
    explicit NepreklapajucaKugla(double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik"); DaLiSeNalazi(0,0,0,r);
        NepreklapajucaKugla::r=r;  NepreklapajucaKugla::x=0; NepreklapajucaKugla::y=0; NepreklapajucaKugla::z=0;
       this->veza=NepreklapajucaKugla::zajednicki;
     zajednicki=this;
       
        }
    NepreklapajucaKugla(double x, double y, double z, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik"); DaLiSeNalazi(x,y,z,r);
        NepreklapajucaKugla::r=r; NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
       this->veza=NepreklapajucaKugla::zajednicki;
        zajednicki=this;
         
    }
    explicit NepreklapajucaKugla (const std::tuple<double, double, double>&centar, double r=0)
    : NepreklapajucaKugla(std::get<0>(centar), std::get<1>(centar),std::get<2>(centar),r){}
   ~NepreklapajucaKugla(){
      if(zajednicki!=nullptr){
        if(this==zajednicki) zajednicki=this->veza;
        else { NepreklapajucaKugla*pok=zajednicki;
            while(pok!=nullptr  && pok->veza!=this) pok=pok->veza;
            if(this->veza==nullptr) pok->veza=nullptr;
            else pok->veza=this->veza;
        }}
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple <double, double, double> DajCentar () const { return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const { return r;}
    double DajPovrsinu() const {return 4*PI*r*r;}
    
    
    NepreklapajucaKugla( const NepreklapajucaKugla& r)=delete;
    NepreklapajucaKugla &operator=(const NepreklapajucaKugla& r)=delete;
    
    
    
    double DajZapreminu() const { return double(4./3)*PI*r*r*r;}
    NepreklapajucaKugla &PostaviX(double x) {DaLiSeNalazi(x, NepreklapajucaKugla::y,NepreklapajucaKugla::z,r); NepreklapajucaKugla::x=x; return *this;}
    NepreklapajucaKugla &PostaviY(double y) {DaLiSeNalazi(NepreklapajucaKugla::x, y,NepreklapajucaKugla::z,r);  NepreklapajucaKugla::y=y; return *this;}
    NepreklapajucaKugla &PostaviZ(double z) { DaLiSeNalazi( NepreklapajucaKugla::x,NepreklapajucaKugla::y,z,r);NepreklapajucaKugla::z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {DaLiSeNalazi(x, y,z,r);NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){ 
        DaLiSeNalazi(std::get<0>(centar), std::get<1>(centar),std::get<2>(centar),r);
        std::tie(x,y,z)=centar; return *this;}
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");DaLiSeNalazi(x, y,z,r);
    NepreklapajucaKugla::r=r; return *this;}
    //Provjeriti je li se ispisuje novi red u Ispisi
    void Ispisi() const {std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z){ DaLiSeNalazi(x+delta_x, y+delta_y,z+delta_z,r);
        x+=delta_x; y+=delta_y;z+=delta_z;}
        
    
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla* NepreklapajucaKugla::zajednicki=nullptr;

typedef std::shared_ptr<NepreklapajucaKugla> pametni;
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));}
    
//trebat ce
 /*bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){  
    return (k1.DajPoluprecnik()+k2.DajPoluprecnik())>RastojanjeCentara(k1,k2);}*/
 template<typename NekiTip>
 bool ProvjeraUnosa(NekiTip &broj){
     std::cin>>broj;
     if(!std::cin){// || (std::cin.peek()!=' ' && std::cin.peek()!='\n')){
         std::cin.clear();
         std::cin.ignore(1000,'\n');
         return false;
     }
     return true;
}
 void Unos(double &x1, double &y1, double &z1, double &r1, int i){ 
     double r,x,y,z;
     std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
     do{
     if(!ProvjeraUnosa(x) || !ProvjeraUnosa(y) || !ProvjeraUnosa(z)){
         std::cout<<"Neispravan centar, unesite ponovo:"<<std::endl;
      }
         else break;
     }
      while(true);
     std::cout<<"Unesite poluprecnik: ";
     do{
     if(!ProvjeraUnosa(r) || r<0) { std::cout<<"Neispravan poluprecnik, unesite ponovo:"<<std::endl;
         }
         else break;
     } while(true);
     x1=x;z1=z;y1=y;r1=r;
   
}
int main ()
{
    try{
    int n;
    std::cout<<"Unesite broj kugli: ";
    do{
   
        if(!ProvjeraUnosa(n) || n<=0) std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        else break;
    } while(true);
    //provjeriti treba li provjera za n i sta se desava za n=0
    std::vector<pametni> Kugle(n);
    for(int i=0;i<n;i++){
        double x,y,z,r;
        Unos(x,y,z,r,i);
            try{
            Kugle[i]=std::make_shared<NepreklapajucaKugla>(x,y,z,r);}
            catch(std::logic_error iz){
                std::cout<<iz.what()<<std::endl;
                i--;
            }
            catch(std::bad_alloc){
                i--;
            }
        
        
    }
   
     std::sort(Kugle.begin(), Kugle.end(), [](pametni p1, pametni p2){
        return p1->DajPovrsinu()<p2->DajPovrsinu();});
    
    std::cout<<std::endl<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    std::for_each(Kugle.begin(), Kugle.end(), [](pametni p1)->void{
        //provjeriti gdje treba razmak ili novi red
        p1->Ispisi();
    }) ;
   
  
    }
    catch(std::domain_error iz){
        std::cout<<iz.what();
    }
	return 0;
}
