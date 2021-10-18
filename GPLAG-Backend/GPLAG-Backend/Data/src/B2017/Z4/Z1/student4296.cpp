#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
class Kugla{
    double x,y,z,r;
    void Provjera(double r){    if(r<0) throw std::domain_error("Ilegalan poluprecnik"); }
    const double pi=4.*std::atan(1.);
    static bool ProvjeriVrijednosti(double r1, double r2){        return std::fabs(r1-r2)<1e-10;}
public:
    explicit Kugla(double r = 0): x(0),y(0),z(0),r(r){Provjera(r);}
    Kugla(double x, double y, double z, double r = 0):x(x),y(y),z(z),r(r){Provjera(r);}
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0):x(std::get<0>(centar)),y(std::get<1>(centar)),z(std::get<2>(centar)),r(r)    {Provjera(r);}
    double DajX() const{return x;}
    double DajY() const{return y;}
    double DajZ() const{return z;}
    std::tuple<double, double, double> DajCentar() const{return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const{return r;}
    double DajZapreminu() const{return (4./3.)*r*r*r*pi;}
    double DajPovrsinu() const{return 4.*pi*r*r;}
    Kugla &PostaviX(double x){Kugla::x=x; return*this;}
    Kugla &PostaviY(double y){Kugla::y=y; return*this;}
    Kugla &PostaviZ(double z){Kugla::z=z; return*this;}
    Kugla &PostaviCentar(double x, double y, double z){this->x=x; this->y=y; this->z=z;  return *this;}
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this;}
    Kugla &PostaviPoluprecnik(double r){ Provjera(r); this->r=r; return *this;}
    void Ispisi() const{std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z){ x+=delta_x; y+=delta_y; z+=delta_z;}
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
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return Kugla::ProvjeriVrijednosti(k1.x,k2.x) && Kugla::ProvjeriVrijednosti(k1.y,k2.y) && Kugla::ProvjeriVrijednosti(k1.z,k2.z) && Kugla::ProvjeriVrijednosti(k1.r,k2.r);
}
 bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return Kugla::ProvjeriVrijednosti(k1.r,k2.r);
 }
 bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return Kugla::ProvjeriVrijednosti(k1.x,k2.x) && Kugla::ProvjeriVrijednosti(k1.y,k2.y) && Kugla::ProvjeriVrijednosti(k1.z,k2.z);
 }
 bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        return std::fabs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<1e-10;
 }
 bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        return (std::fabs(RastojanjeCentara(k1,k2)+k1.r-k2.r)<1e-10 && k2.DaLiSadrzi(k1)) || (std::fabs(RastojanjeCentara(k1,k2)+k2.r-k1.r)<1e-10 && k1.DaLiSadrzi(k2) );
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    return DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        return RastojanjeCentara(k1,k2)<k1.r+k2.r && (!k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const{
        double x1(k.DajX()),z1(k.DajZ()),y1(k.DajY()),r1(k.DajPoluprecnik());
        return (RastojanjeCentara(*this,k)+k.r)<=this->r && k.r<=this->r;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
int main(){
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Kugla>> v(n);
    double x,y,z,r;
    for(int i = 0; i < n; i++){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(r<0){
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            i--;
            continue;
        }
        v[i]=std::make_shared<Kugla>(x,y,z,r);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>x>>y>>z;
    std::transform(v.begin(),v.end(), v.begin(),[x,y,z](std::shared_ptr<Kugla> & k){ k->Transliraj(x,y,z); return k;});
    std::sort(v.begin(), v.end(),[](const std::shared_ptr<Kugla>& k1,const std::shared_ptr<Kugla>& k2 ) ->bool{return k1->DajZapreminu()<k2->DajZapreminu();});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](const std::shared_ptr<Kugla>& k){k->Ispisi();});
    auto max=std::max_element(v.begin(),v.end(),[](const std::shared_ptr<Kugla>& k1, const std::shared_ptr<Kugla>& k2){ return k1->DajPovrsinu()< k2->DajPovrsinu();});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (**max).Ispisi();
    bool b=false;
    int i=0;
    std::for_each(v.begin(),v.end(),[v,&b,&i](const std::shared_ptr<Kugla>& k){
                  std::for_each(v.begin()+i,v.end(),[k,&b]( const std::shared_ptr<Kugla>& k2) {
                                 if(DaLiSeSijeku(*k,*k2) && k!=k2 ) {
                                    b=true;
                                    std::cout<<"Presjecaju se kugle: ";
                                    k->Ispisi();
                                    k2->Ispisi();
                                }
                    }); i++;  });
    if(!b) std::cout<<"Ne postoje kugle koje se presjecaju!" <<std::endl;

    return 0;
}

int imain()
{
   /* {
        //Testiranje konstruktora
            Kugla k(std::tuple<double,double,double>(2,8,3),5);
            k.Ispisi();
            Kugla k1(2,8,2,5);
            k1.Ispisi();
            Kugla k2(4);
            k2.Ispisi();
            Kugla k3;
            k3.Ispisi();
            {(2,8,3),5}
                {(2,8,2),5}
                {(0,0,0),4}
                {(0,0,0),0}
    }*/
    {
        //Testiranje metoda Daj..
       /*  Kugla k(std::tuple<double,double,double>(2.5,8.1,3.3),5.4);
            k.Ispisi();
            std::cout<<k.DajX()<<" "<<k.DajY()<<" "<<k.DajZ()<<" "<<k.DajPoluprecnik()<<std::endl;
            std::tuple<double,double,double> centar (k.DajCentar());
            std::cout<<std::get<0>(centar)<<" "<<std::get<1>(centar)<<" "<<std::get<2>(centar)<<std::endl;
            {(2.5,8.1,3.3),5.4}
                2.5 8.1 3.3 5.4
                2.5 8.1 3.3*/
    }
    /*{
        //Testiranje DajPovrisnu i DajZapreminu
         Kugla k(std::tuple<double,double,double>(2.5,8.1,3.3),5.4);
        std::cout<<"Povrsina: "<<k.DajPovrsinu()<<std::endl<<"Zapremina: "<<k.DajZapreminu()<<std::endl;

    }
    {
        //Testiranje Postavi x y z
                    Kugla k;
                    k.Ispisi();
                    k.PostaviX(1);
                    k.PostaviY(8.5);
                    k.PostaviZ(11.2);
                    k.PostaviPoluprecnik(21.5);
                    k.Ispisi();

    }*/
    {
        //Testiranje postaviCentar
       /*      Kugla k;
            k.Ispisi();
            k.PostaviCentar(12,3,4);
            k.Ispisi();
            k.PostaviCentar(std::tuple<double,double,double>(12.5,1,5.3));
            k.Ispisi();*/
    }
    {
        //Testiranje Kaskadnog pozivanja
      /*     Kugla k;
                    k.Ispisi();
                    k.PostaviX(1).PostaviY(8.5).PostaviZ(11.2).PostaviPoluprecnik(21.5).Ispisi();*/
    }
    {

   /*     Kugla k;
        k.PostaviCentar(std::tuple<double,double,double>(12.5,1,5.3)).PostaviPoluprecnik(8).Ispisi();*/
    }
    {
        //Testiranje Transliraj
       /* Kugla k;
                k.PostaviCentar(std::tuple<double,double,double>(12.5,1,5.3)).PostaviPoluprecnik(8);
                k.Transliraj(0.1,0.5,1.2);
                k.Ispisi();*/
    }
    {
        //Testiranje DaLiSadrzi;
    /*       Kugla k(0,0,0,5);
    Kugla k1(0,0,0,5);
    std::cout<<k.DaLiSadrzi(k1)<<std::endl;;
    k1.PostaviPoluprecnik(2);
    std::cout<<k.DaLiSadrzi(k1)<<std::endl;;
    std::cout<<k1.DaLiSadrzi(k)<<std::endl;;
    k1.Transliraj(3,0,0);
    std::cout<<k.DaLiSadrzi(k1)<<std::endl;;
    k1.Transliraj(0,3,0);
        std::cout<<k.DaLiSadrzi(k1)<<std::endl;;
    k1.Transliraj(0,0,3);
    std::cout<<k.DaLiSadrzi(k1)<<std::endl;;
    k1.Transliraj(1e-9,0,0);
    std::cout<<k.DaLiSadrzi(k1)<<std::endl;;
*/
    }
    {
        //Testiranje DaLiSuIdenticne
   /*     Kugla k1(0,0,0,2);
        Kugla k2(1,1,1,2);
        std::cout<<DaLiSuIdenticne(k1,k2)<<std::endl;
        k2.Transliraj(-1,-1,-1);
            std::cout<<DaLiSuIdenticne(k1,k2)<<std::endl;
        k1.PostaviPoluprecnik(2+1e-9);
        std::cout<<DaLiSuIdenticne(k1,k2)<<std::endl;*/
    }
    {
        //Testiranje DaLiSuPodudarne
     /*   Kugla k1(0,3,0,2);
        Kugla k2(1,4,1,2);
        std::cout<<DaLiSuPodudarne(k1,k2)<<std::endl;
        k1.PostaviPoluprecnik(2+1e-9);
        std::cout<<DaLiSuPodudarne(k1,k2)<<std::endl;*/
    }
    {
        //Testiranje DaLiSuKoncntricne
       /*   Kugla k1(0,0,0,2);
        Kugla k2(1,1,1,2);
        std::cout<<DaLiSuKoncentricne(k1,k2)<<std::endl;
        k2.Transliraj(-1,-1,-1);
        std::cout<<DaLiSuKoncentricne(k1,k2)<<std::endl;
        k1.PostaviPoluprecnik(2+1e-9);
        std::cout<<DaLiSuKoncentricne(k1,k2)<<std::endl;
        k1.PostaviX(1e-9);
                std::cout<<DaLiSuKoncentricne(k1,k2)<<std::endl;*/

    }
    {
        //Testiranje RastojanjeCentra
         /* Kugla k1(0,0,0,2);
        Kugla k2(1,1,1,2);
        std::cout<<RastojanjeCentara(k1,k2)<<std::endl;
        k2.Transliraj(-1,-1,-1);
                std::cout<<RastojanjeCentara(k1,k2)<<std::endl;
*/
    }
    {
        //Testiranj DaLiSeDodirujuIzvana
       /* Kugla k1(0,0,0,2);
        Kugla k2(4,0,0,2);
        Kugla k3(0,0,3,2);
        std::cout<<DaLiSeDodirujuIzvana(k1,k2)<<std::endl;
        std::cout<<DaLiSeDodirujuIzvana(k1,k3)<<std::endl;
        std::cout<<DaLiSeDodirujuIzvana(k3,k2)<<std::endl;*/
    }
    {
        //Testiranje DaLiSeDodirijiIznutra
        /*    Kugla k1(0,0,0,2);
        Kugla k2(0,0,1,1);
        Kugla k3(0,0,0,3);
        std::cout<<DaLiSeDodirujuIznutra(k1,k2)<<std::endl;
        std::cout<<DaLiSeDodirujuIznutra(k3,k2)<<std::endl;
        k2.PostaviCentar(0,0,1.5).PostaviPoluprecnik(0.5);
        std::cout<<DaLiSeDodirujuIznutra(k1,k2)<<std::endl;
*/


    }
    {
        //Testiranje DaLiSePreklapaju
/*
     Kugla k1(0,0,0,2);
        Kugla k2(3,0,0,2);
        Kugla k3(4,0,0,2);
        std::cout<<DaLiSePreklapaju(k1,k2)<<std::endl;
        std::cout<<DaLiSePreklapaju(k3,k2)<<std::endl;
        std::cout<<DaLiSePreklapaju(k1,k3)<<std::endl;
        Kugla k4(0,0,1,1);
        std::cout<<DaLiSePreklapaju(k1,k4)<<std::endl;*/

    }
 /*   {
        //Testiranje DaLiSeSijeku
         Kugla k1(0,0,0,2);
        Kugla k2(3,0,0,2);
        Kugla k3(4,0,0,2);
        std::cout<<DaLiSeSijeku(k1,k2)<<std::endl;
        std::cout<<DaLiSeSijeku(k3,k2)<<std::endl;
        std::cout<<DaLiSeSijeku(k1,k3)<<std::endl;

    }
{
    //Testiranje izuzetka
    try{
        Kugla k(-8);
    }catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(...){
        std::cout<<"Pogresan tip izuzetka"<<std::endl;
    }
    try{
        Kugla k(2,5,8,-8);
    }catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(...){
        std::cout<<"Pogresan tip izuzetka"<<std::endl;
    }
        try{
        Kugla k;
        k.PostaviPoluprecnik(-7);
    }catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(...){
        std::cout<<"Pogresan tip izuzetka"<<std::endl;
    }
}*/
{
    //Testiranje DaLiSeDodiruju ako se kugla degenerira u tačku
    Kugla k1(2,0,0,0);
    Kugla k2(0,0,0,2);
    std::cout<<DaLiSeDodirujuIznutra(k1,k2)<<std::endl;
    std::cout<<DaLiSeDodirujuIzvana(k1,k2)<<std::endl;
    k2.Transliraj(1e-9,0,0);
    std::cout<<DaLiSeDodirujuIzvana(k1,k2)<<std::endl;

}
       return 0;
}
