/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
class Kugla{
    double x,y,z;
    double poluprecnik;

    public:
    explicit Kugla(double r=0);
    Kugla (double x,double y, double z,double r=0);
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0);
    double DajX();
    double DajY();
    double DajZ();
    std::tuple< double,double, double> DajCentar() const;
    double DajPoluprecnik();
    double DajPovrsinu();
    double DajZapreminu();
    Kugla &Postavi(double x);
    Kugla &Postavi(double y);
    Kugla &Postavi(double z);
    Kugla &PostaviCentar(double x,double y,double z);
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiseSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const ;
    friend double RastojanjeCentra(const Kugla &k1, const Kugla &k2);
};

Kugla::Kugla(double r=0){ if(r>=0) poluprecnik=r; x=0; y=0; z=0;}

Kugla::Kugla(double x,double y, double z,double r=0){ if(r>=0) poluprecnik=r; Kugla::x=x; Kugla::y=y, Kugla::z=z;}

Kugla::Kugla((const std::tuple<double,double,double> &centar, double r=0){ if(r>=0) poluprecnik=r; x=std::get<0>(centar); 
                                        y=std::get<1>(centar); z=std::get<2>(centar);
}
double Kugla::DajX(){ return x;}
double Kugla::DajY(){return y;}
double Kugla::DajZ(){return z;}
 
std::tuple<double,double,double> Kugla::DajCentar(){ 
    std::touple<double,double,double> centar;
    std::get<0>(centar)=x;
    std::get<1>(centar)=y;
    std::get<2>(centar)=z;
    return centar;
    
}

double Kugla::DajPoluprecnik (){ return r;}

double Kugla::DajPovrsinu(){
    double P;
}




int main ()
{
	return 0;
}
