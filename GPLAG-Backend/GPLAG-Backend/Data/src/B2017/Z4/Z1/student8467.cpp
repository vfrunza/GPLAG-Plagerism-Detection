/B2017/2018: Zadaća 4, Zadatak 1
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <tuple>
#include <vector>


#define PI (4*atan(1))
#define EPS 1e-10
typedef std::tuple<double, double, double> Centar;

bool Jednaki(double x, double y){
    return std::abs(x-y) <= EPS*( std::abs(x) + std::abs(y) ); //SUMNJIVO
}
double Max(double x, double y){
    return x > y ? x : y;
}

double Min(double x, double y){
       return x < y ? x : y;
}


class Kugla{
  double x,y,z,r;

public:
    //Konstruktori
    explicit Kugla(double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = 0; Kugla::y = 0; Kugla::z = 0; Kugla::r = r;
    }
    Kugla(double x, double y, double z, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = x; Kugla::y = y; Kugla::z = z; Kugla::r = r;
    }
    explicit Kugla(const Centar &c, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = std::get<0>(c); Kugla::y = std::get<1>(c); Kugla::z = std::get<2>(c); Kugla::r = r;
    }
    //Geteri
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    Centar DajCentar() const{ return Centar{x,y,z}; }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return(4. * r * r * PI);}
    double DajZapreminu() const{ return((4./3.) * r * r * r  *PI); }
    //Seteri
    Kugla &PostaviX(double x){ Kugla::x = x; return *(this);}
    Kugla &PostaviY(double y){ Kugla::y = y; return *(this);}
    Kugla &PostaviZ(double z){ Kugla::z = z; return *(this);}
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x = x; Kugla::y = y; Kugla::z=z;
        return *(this);
    }
    Kugla &PostaviCentar(Centar c){
        Kugla::x = std::get<0>(c); Kugla::y = std::get<1>(c); Kugla::z = std::get<2>(c);
        return *(this);
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        return *(this);
    }
    //Ispisivanje objekta
    void Ispisi() const { std::cout << "{" << "(" << x << "," << y << "," << z << ")," << r << "}"; }
    //Translacija, pomjeranje centra kruga
    void Transliraj(double delta_x, double delta_y, double delta_z){
        Kugla::x += delta_x; Kugla::y += delta_y; Kugla::z += delta_z;
    }
    bool DaLiSadrzi(const Kugla &k);
    //Prijateljske funkcije
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){ return(Jednaki(k1.r, k2.r) && Jednaki(k1.x, k2.x) && Jednaki(k1.y, k2.y)  &&Jednaki(k1.z, k2.z)); }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){ return(Jednaki(k1.r, k2.r)); }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){ return(Jednaki(k1.x, k2.x)&&Jednaki(k1.y, k2.y)&&Jednaki(k1.z, k2.z)); }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){return sqrt( (k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z) );}
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    friend std::shared_ptr<Kugla> VecaKugla(const Kugla &k1, const Kugla &k2);
    friend std::shared_ptr<Kugla> ManjaKugla(const Kugla &k1, const Kugla &k2);
};
std::shared_ptr<Kugla> VecaKugla(const Kugla &k1, const Kugla &k2){
    if(k1.DajZapreminu() > k2.DajZapreminu()) return std::make_shared<Kugla>(k1);
    if(k2.DajZapreminu() > k1.DajZapreminu()) return std::make_shared<Kugla>(k2);
    return std::make_shared<Kugla>(k1);
}
std::shared_ptr<Kugla> ManjaKugla(const Kugla &k1, const Kugla &k2){
    if(k1.DajZapreminu() < k2.DajZapreminu()) return std::make_shared<Kugla>(k1);
    if(k2.DajZapreminu() < k1.DajZapreminu()) return std::make_shared<Kugla>(k2);
    return std::make_shared<Kugla>(k2);
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return Jednaki(k1.r + k2.r, RastojanjeCentara(k1,k2));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return Jednaki(Max(k1.r, k2.r), ( Min(k1.r, k2.r) + RastojanjeCentara(k1, k2)) );
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if ( Jednaki(k1.r, 0.) || Jednaki(k2.r,  0.) ) return false;
    return( (RastojanjeCentara(k1, k2) < (k1.r + k2.r)) );
    
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return k1.r > 0 && k2.r > 0 &&( DaLiSuIdenticne(k1, k2) || (DaLiSePreklapaju(k1, k2) && RastojanjeCentara(k1, k2) > abs(k1.r - k2.r))); //SUMNJIVO
}
bool Kugla::DaLiSadrzi(const Kugla &k){
    return RastojanjeCentara(k, *this) + k.r <= r;
}

std::shared_ptr<Kugla> UnosKugle(int n){
    bool neispravan_centar(true);
    bool neispravan_poluprecnik(true);
    double x, y, z, r;
    do{
        //if(neispravan_centar){
            std::cout << "Unesite centar "<< n + 1 << ". kugle: ";
            std::cin >> x >> y >> z;
            if(!std::cin){
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
        		std::cin.ignore(100000,'\n');
                continue;
            }
            neispravan_centar = false;
        //}
        std::cout << "Unesite poluprecnik "<< n + 1 << ". kugle: ";
        std::cin >> r;
        if(r < 0 || !std::cin){
            std::cout << "Ilegalan poluprecnik" << std::endl;
            std::cin.clear();
    		std::cin.ignore(100000,'\n');
            continue;
        }
        neispravan_poluprecnik = false;
    }while(neispravan_centar || neispravan_poluprecnik);
    
    try{
        std::shared_ptr<Kugla> ptr(new Kugla(x,y,z,r));
        return ptr;
    }catch(...){
        throw;
    }
}


int main ()
{
    int broj_kugla;
    //Provjera unosa za broj_kugli
    bool neispravno(true);
    std::cout << "Unesite broj kugla: ";
    do{
        std::cin >> broj_kugla;
        if(!std::cin || broj_kugla < 1){
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            std::cin.clear();
    		std::cin.ignore(100000,'\n');
            continue;
        }
        neispravno = false;
    }while(broj_kugla < 1 || neispravno);
    //
    std::vector<std::shared_ptr<Kugla>> vektor(broj_kugla);
    //UNOS KUGLI
    for(int i = 0; i < broj_kugla; i++){
        vektor.at(i) = UnosKugle(i);
    }
    //Unos i provjera parametara za translaciju
    double dx, dy, dz;
    neispravno = true;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    do{
        std::cin >> dx >> dy >> dz;
        if(!std::cin){
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin.clear();
    		std::cin.ignore(100000,'\n');
            continue;
        }
        neispravno = false;
    }while(neispravno);
    //U ovom trenutku znamo da su nam svi parametri ispravni
    //TRANSFORM - Translacija kugli
    std::transform(vektor.begin(), vektor.end(), vektor.begin(),
    [dx, dy, dz](const std::shared_ptr<Kugla> &k) -> std::shared_ptr<Kugla>{
        k->Transliraj(dx,dy,dz);
        return k;
    }
    );
    //Soritiranje kuhli po zapremini
    std::sort(vektor.begin(), vektor.end(), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2){return k1->DajZapreminu() < k2->DajZapreminu();});
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    //Ispisivanje sa for_each
    std::for_each(vektor.begin(),vektor.end(),
    [](const std::shared_ptr<Kugla> &x){
        x->Ispisi();
        std::cout << std::endl;
    });
    //Ispisivanje kugle sa najvećom povrsinom
    std::cout << "Kugla sa najvecom povrsinom je: ";
    std::vector<std::shared_ptr<Kugla>>::iterator it = std::max_element(vektor.begin(), vektor.end(),
    [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) -> bool{
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });
    (**it).Ispisi();
    std::cout << std::endl;
    
    /*std::cout << "Velicina:" << vektor.size();
    for(std::shared_ptr<Kugla> x : vektor) x->Ispisi();
	std::cout << "RastojanjeCentara: " << RastojanjeCentara(*vektor.at(0), *vektor.at(1));
	std::cout << "DaLiSePreklapaju: " << DaLiSePreklapaju(*vektor.at(0), *vektor.at(1));
	std::cout << "DaLiSuIdenticne: " << DaLiSuIdenticne(*vektor.at(0), *vektor.at(1));
	std::cout << "DaLiSeSijeku: " << DaLiSeSijeku(*vektor.at(0), *vektor.at(1));
	std::cout << "Jednika: " << Jednaki(vektor.at(0)->DajPoluprecnik(), vektor.at(1)->DajPoluprecnik());
	*/
	int brojac_ispisa(0);
	std::for_each(vektor.begin(), vektor.end(),
	[&vektor, &brojac_ispisa](const std::shared_ptr<Kugla> &x){
	    std::for_each(vektor.begin() + (&x-&*vektor.begin()) + 1, vektor.end(),
	    [&x, &brojac_ispisa](const std::shared_ptr<Kugla> &y){
	        if(DaLiSeSijeku(*x, *y) /*&& !VecIspisani(*x, *y)*/){ //OVO NISI DOVRŠIO!
                std::cout << "Presjecaju se kugle: ";
                x->Ispisi();
                std::cout << std::endl;
                y->Ispisi();
                std::cout << std::endl;
                brojac_ispisa++;
	        }
	    });
	}
	);
	if(!brojac_ispisa) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
	
	return 0;
}
