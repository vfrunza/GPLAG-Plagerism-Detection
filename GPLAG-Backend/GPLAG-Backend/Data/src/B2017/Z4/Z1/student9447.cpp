/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <vector>

#define PI (4*atan(1))
#define eps 0.0000000001

class Kugla {
    double x,y,z,r;
public:
    explicit Kugla(double r = 0) {
        PostaviPoluprecnik(r);
    }
    Kugla(double x, double y, double z, double r = 0){
        PostaviCentar(x,y,z);
        PostaviPoluprecnik(r);
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        PostaviCentar(centar);
        PostaviPoluprecnik(r);
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple<double, double, double> DajCentar() const{
        return std::tuple <double, double, double> {DajX(),DajY(),DajZ()};
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return (4*DajPoluprecnik()*DajPoluprecnik()*PI);
    }
    double DajZapreminu() const {
        return (4/3*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*PI);
    }
    Kugla &PostaviX(double x){
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z){
        if (x<=0 || x>0 || y<=0 || y>0 || z<=0 || z>0){
            Kugla::x=x;
            Kugla::y=y;
            Kugla::z=z;
            return *this;
        }
        else throw std::domain_error ("Neispravan centar");
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        if (std::get<0>(centar)<=0 || std::get<0>(centar)>0 || std::get<1>(centar)<=0 || std::get<1>(centar)>0 || std::get<2>(centar)<=0 || std::get<2>(centar)>0){
            x=std::get<0>(centar);
            y=std::get<1>(centar);
            z=std::get<2>(centar);
            return *this;
        }
        else throw std::domain_error ("Neispravan centar");
    }
    Kugla &PostaviPoluprecnik(double r){
        if (r<0 || !std::cin) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        if (delta_x<=0 || delta_x>0 || delta_y<=0 || delta_y>0 || delta_z<=0 || delta_z>0){
            x=x+delta_x;
            y=y+delta_y;
            z=z+delta_z;
        }
        else throw std::domain_error ("Neispravni parametri translacije, unesite ponovo!");
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        return (abs(k1.DajX()-k2.DajX())<eps*(abs(k1.DajX())+abs(k2.DajX())) && 
                abs(k1.DajY()-k2.DajY())<eps*(abs(k1.DajY())+abs(k2.DajY())) &&
                abs(k1.DajZ()-k2.DajZ())<eps*(abs(k1.DajZ())+abs(k2.DajZ())) &&
                abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<eps*(abs(k1.DajPoluprecnik())+abs(k2.DajPoluprecnik()))); 
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        return (abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<eps*(abs(k1.DajPoluprecnik())+abs(k2.DajPoluprecnik()))); 
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        return (abs(k1.DajX()-k2.DajX())<eps*(abs(k1.DajX())+abs(k2.DajX())) && 
                abs(k1.DajY()-k2.DajY())<eps*(abs(k1.DajY())+abs(k2.DajY())) &&
                abs(k1.DajZ()-k2.DajZ())<eps*(abs(k1.DajZ())+abs(k2.DajZ())));
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){  //rastojanje dva centra da je jednako zbiru poluprecnika
        return abs(sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()))-(k1.DajPoluprecnik()+k2.DajPoluprecnik()))<eps*(abs(sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ())))+abs(k1.DajPoluprecnik()+k2.DajPoluprecnik()));
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        return abs(sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()))-abs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))<eps*(abs(sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ())))+abs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
        return RastojanjeCentara(k1,k2)<fabs(k1.r-k2.r);
    }
    
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        double razmak(RastojanjeCentara(k1,k2)),poluprecnik(k1.DajPoluprecnik()+k2.DajPoluprecnik());
        if (DaLiSuIdenticne(k1,k2))return false;
        if(DaLiSeDodirujuIznutra(k1,k2))return false;
        if (DaLiSuKoncentricne(k1,k2))return false;
        if(k1.r<eps || k2.r<eps) return false;
        if (razmak<poluprecnik) return true;
        return false;
    }
    
    bool DaLiSadrzi(const Kugla &k) const{
      
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
    }
};


int main ()
{
	int a(0);
	std::cout << "Unesite broj kugla: ";
	std::cin >> a;
	for(;;){
	    if (a>0) break;
	    else std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
	    std::cin.clear();
        std::cin.ignore(10000, '\n');
	    std::cin >> a;
	}
	int l(0);
	std::vector<std::shared_ptr<Kugla>> t1;
	for (int i(0);i<a;i++){
	    double x(0),y(0),z(0),r(0);
	    std::cout << "Unesite centar " << i+1 << ". kugle: ";
	    std::cin >> x >> y >> z;
	    if (!std::cin) {
	        std::cout << "Neispravan centar" << std::endl; 
	        std::cin.clear();
            std::cin.ignore(10000, '\n');
	        i--;
	        continue;
	        l++;
	    }
	    std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
	    std::cin >> r;
	    if (!std::cin) {
	        std::cout << "Ilegalan poluprecnik" << std::endl; 
	        std::cin.clear();
            std::cin.ignore(10000, '\n');
	        i--;
	        continue;
	        l++;
	    }
	    if (l==0){
	    try{
	        auto X(std::make_shared<Kugla>(Kugla(x,y,z,r)));
	        t1.push_back(X);
	    }
	    catch (std::domain_error err){
	        std::cout << err.what() << std::endl;
	        i--;
	    }
	    }
	    l=0;
	}
	double dx,dy,dz;
	std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
	std::cin >> dx >> dy >> dz;
	for(;;){
	    if (!std::cin){
	        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
	        std::cin.clear();
            std::cin.ignore(10000, '\n');
	    }
	    else break;
	    std::cin >> dx >> dy >> dz;
	}
	for (int i(0);i<1;i++){
    	try{
    	    std::transform (t1.begin(),t1.end(),t1.begin(),[dx,dy,dz](std::shared_ptr<Kugla> t){t->Transliraj(dx,dy,dz);return t;});
    	}
    	catch (std::domain_error err){
    	    std::cout << err.what() << std::endl;
    	    i--;
    	}
	}
	std::sort(t1.begin(), t1.end(), [](const std::shared_ptr<Kugla> &t2,const std::shared_ptr<Kugla> &t3){return t2->DajZapreminu()<t3->DajZapreminu();});
	std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
	std::for_each(t1.begin(), t1.end(), [] (std::shared_ptr<Kugla> t){t->Ispisi();std::cout << std::endl;});
	std::cout << "Kugla sa najvecom povrsinom je: ";
	auto k=std::max_element (t1.begin(),t1.end(),[](const std::shared_ptr<Kugla> &t2,const std::shared_ptr<Kugla> &t3){return t2->DajPovrsinu()<t3->DajPovrsinu();});
	(*k)->Ispisi();std::cout<<std::endl;
	
	auto it(t1.begin()); 
	it++;
	int p(0),u(0);
    for_each(t1.begin(),t1.end(),[&](const std::shared_ptr<Kugla> &t2){
        u++;
        for_each(it, t1.end(), [&](const std::shared_ptr<Kugla> &t3){
            if(DaLiSeSijeku(*t2,*t3)){
                p++;
                std::cout << "Presjecaju se kugle: ";
                t2->Ispisi();
                std::cout << std::endl;
                t3->Ispisi();
                std::cout << std::endl;
            }
        });
        it++;
    });
    if (p==0) std::cout << "Ne postoje kugle koje se presjecaju!";
	
	return 0;
}
