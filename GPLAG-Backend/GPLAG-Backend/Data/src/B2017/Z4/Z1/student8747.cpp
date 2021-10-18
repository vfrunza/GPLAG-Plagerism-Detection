/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

class Kugla{
double x,y,z,r;
public:
    explicit Kugla(double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = 0; Kugla::y = 0; Kugla::z = 0; Kugla::r = r;
    }
    Kugla(double x, double y, double z, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = x; Kugla::y = y; Kugla::z = z; Kugla::r = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = std::get<0>(centar); Kugla::y = std::get<1>(centar); Kugla::z = std::get<2>(centar); Kugla::r = r;
    }
    double DajX() const{
        return x;
    }
    double DajY() const{
        return y;
    }
    double DajZ() const{
        return z;
    }
    std::tuple<double, double, double> DajCentar() const{
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const{
        return r;
    }
    double DajPovrsinu() const{
        return 4 * 4 * atan(1) * r * r;
    }
    double DajZapreminu() const{
        return 4 / 3 * 4 * atan(1) * r * r * r;
    }
    Kugla &PostaviX(double x){
        (*this).x = x;
        return *this;
    }
    Kugla &PostaviY(double y){
        (*this).y = y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        (*this).z = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z){
        (*this).x = x; (*this).y = y; (*this).z = z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        (*this).x = std::get<0>(centar); (*this).y = std::get<1>(centar); (*this).z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        (*this).r = r;
        return *this;
    }
    void Ispisi() const{
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Translatiraj(double delta_x, double delta_y, double delta_z){
        (*this).x += delta_x; (*this).y += delta_y; (*this).z += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const{
        //std::cout << std::endl << (*this).r << " , novi" << k.r << " RastojanjeCentara " << RastojanjeCentara((*this), k) <<std::endl;
        //if((*this).r < k.r) 
        return abs((*this).r - k.r) >= RastojanjeCentara((*this), k);
        //else return k.r <= RastojanjeCentara((*this), k);
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    bool tacno(true);
    if(!(abs(k1.x-k2.x) < 1e-10*(abs(k1.x) + abs(k2.x)))) tacno = false;
    if(!(abs(k1.y-k2.y) < 1e-10*(abs(k1.y) + abs(k2.y)))) tacno = false;
    if(!(abs(k1.z-k2.z) < 1e-10*(abs(k1.z) + abs(k2.z)))) tacno = false;
    if(!(abs(k1.r-k2.r) < 1e-10*(abs(k1.r) + abs(k2.r)))) tacno = false;
    return tacno;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return (abs(k1.r-k2.r) < 1e-10*(abs(k1.r) + abs(k2.r)));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    bool tacno(true);
    if(!(abs(k1.x-k2.x) < 1e-10*(abs(k1.x) + abs(k2.x)))) tacno = false;
    if(!(abs(k1.y-k2.y) < 1e-10*(abs(k1.y) + abs(k2.y)))) tacno = false;
    if(!(abs(k1.z-k2.z) < 1e-10*(abs(k1.z) + abs(k2.z)))) tacno = false;
    return tacno;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    //std::cout << k1.DaLiSadrzi(k2);
    return (abs(abs(k2.r - k1.r) - RastojanjeCentara(k1, k2) < 1e-10 * (abs(k2.r - k1.r) + abs(RastojanjeCentara(k1, k2)))));     // x =  abs(k2.r - k1.r) == y = RastojanjeCentara(k1,k2);
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return (abs(k1.r + k2.r - RastojanjeCentara(k1, k2)) < 1e-10 * (abs(k1.r + k2.r) + abs(RastojanjeCentara(k1, k2)))); //k1.r + k2.r == RastojanjeCentara(k1, k2);
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    //if(k1.r < k2.r) return k2.r <= RastojanjeCentara(k1, k2);
    //else return k1.r <= RastojanjeCentara(k1, k2);
    //return abs(k1.r - k2.r) <= RastojanjeCentara(k1, k2);
    return k1.r + k2.r > RastojanjeCentara(k1, k2);
    //else return pow(k2.r, 2) > RastojanjeCentara(k1, k2);
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    //std::cout << DaLiSePreklapaju(k1, k2);
    if(!k1.DaLiSadrzi(k2)) return k1.r + k2.r > RastojanjeCentara(k1, k2);
    //else if(!k1.DaLiSadrzi(k2)) return pow(k2.r, 2) > RastojanjeCentara(k1, k2);
    //return abs(pow(k1.r,2) - pow(k2.r,2)) < RastojanjeCentara(k1, k2);
    return 0;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt(pow((k1.x-k2.x),2)+pow((k1.y-k2.y),2)+pow((k1.z-k2.z),2));
}

void Unos(double &x, double &y, double &z, int nesto, int brojac){
    while(!(std::cin >> x >> y >> z)){
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        if(nesto == 1) {
            std::cout << "Neispravan centar" << std::endl;
            std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
        }
        if(nesto == 0) std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite broj kugla: ";
    int broj(-1);
    double x, y, z, r(-1);
    int brojac(0);
    double dx, dy, dz;

    while(!(std::cin >> broj)||broj <= 0){
        //std::cin >> broj;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        if(broj <= -1) std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        else std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    }
    try{
        std::vector<std::shared_ptr<Kugla>> vektor(broj);
        for(;;){
            std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
            Unos(x,y,z, 1, brojac);
            std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
            while(!(std::cin >> r) || r < 0){
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                if(r < 0){
                    std::cout << "Ilegalan poluprecnik" << std::endl;
                    std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                    Unos(x, y, z, 1, brojac);
                    std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
                }
                else {
                    std::cout << "Ilegalan poluprecnik" << std::endl;
                    std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                    Unos(x, y, z, 1, brojac);
                    std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
                }
            }
            vektor[brojac] = std::make_shared<Kugla> (x, y, z, r);
            brojac++;
            if(brojac==broj) break;
        }
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        Unos(dx, dy, dz, 0, brojac);
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        std::transform(vektor.begin(), vektor.end(), vektor.begin(),
            [=](std::shared_ptr<Kugla>& prvo) -> std::shared_ptr<Kugla> {
                (*prvo).PostaviX(dx+(*prvo).DajX()); (*prvo).PostaviY(dy+(*prvo).DajY()); (*prvo).PostaviZ(dz+(*prvo).DajZ());
                return prvo;
            });
        std::sort(vektor.begin(), vektor.end(),
        [](const std::shared_ptr<Kugla>& prvo, const std::shared_ptr<Kugla>& drugo){
            return (*prvo).DajZapreminu()<(*drugo).DajZapreminu();
        });
        
        std::for_each(vektor.begin(), vektor.end(),
            [](std::shared_ptr<Kugla>& prvo){
                return (*prvo).Ispisi();
            });
        std::cout << "Kugla sa najvecom povrsinom je: ";
        (**(std::max_element(vektor.begin(), vektor.end(),
        [](std::shared_ptr<Kugla>& prvo, std::shared_ptr<Kugla>& drugo){
            return (*prvo).DajPovrsinu()<(*drugo).DajPovrsinu();
        }))).Ispisi();
        brojac=1;
        bool tacno(false);
        //(*vektor[brojac]).Ispisi();
    	std::for_each(vektor.begin(), vektor.end(),
    	    [&](const std::shared_ptr<Kugla> &prvo) -> void{
    	        std::for_each(vektor.begin()+brojac, vektor.end(),
    	            [&](const std::shared_ptr<Kugla> &drugo) -> void{
    	                //std::cout << "Pozvano" ;
    	                if(DaLiSeSijeku((*prvo), (*drugo))){
    	                    std::cout << "Presjecaju se kugle: ";
    	                    (*prvo).Ispisi(); 
    	                    (*drugo).Ispisi();
    	                    tacno = true;
    	                };
    	            });
    	        brojac++;
    	    });
    	if(!tacno) std::cout << "Ne postoje kugle koje se presjecaju!";
    }
    catch(const std::exception &greska){
        std::cout << greska.what();
    }
	return 0;
}
