/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <cmath>
#include <memory>
#include <algorithm>

#define e 0.0000000001

bool DaLiJeJednako(double x, double y)
{
    return fabs(x - y) <= e*(fabs(x) + fabs(y));
}

double UdaljenostDvijeTacke(double x1,double y1, double z1,double x2,double y2, double z2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
}

class Kugla {
    double x,y,z,poluprecnik;
public:
    explicit Kugla(double r = 0) : x(0), y(0), z(0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
    }
    Kugla(double x, double y, double z, double r = 0) : x(x), y(y), z(z) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
        std::tie(x,y,z) = centar;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return poluprecnik; }
    double DajPovrsinu() const { return 4*poluprecnik*poluprecnik*4*atan(1); }
    double DajZapreminu() const { return (4*poluprecnik*poluprecnik*poluprecnik*4*atan(1))/3; }
    Kugla &PostaviX(double x) { Kugla::x = x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y = y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { Kugla::x = x; Kugla::y = y; Kugla::z = z; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { std::tie(x,y,z) = centar; return *this; }
    Kugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
        return *this;
    }
    void Ispisi() const { std::cout << "{(" << x << "," << y <<"," << z << ")," << poluprecnik << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { x += delta_x; y += delta_y; z += delta_z; }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const { return(UdaljenostDvijeTacke(x,y,z,k.x,k.y,k.z) + k.poluprecnik) < poluprecnik; }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    friend double UdaljenostDvijeTacke(double x1,double y1, double z1,double x2,double y2, double z2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return(DaLiJeJednako(k1.x, k2.x) && DaLiJeJednako(k1.y, k2.y) && DaLiJeJednako(k1.z, k2.z) && DaLiJeJednako(k1.poluprecnik, k2.poluprecnik));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return DaLiJeJednako(k1.poluprecnik, k2.poluprecnik);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return(DaLiJeJednako(k1.x, k2.x) && DaLiJeJednako(k1.y, k2.y) && DaLiJeJednako(k1.z, k2.z));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return DaLiJeJednako(UdaljenostDvijeTacke(k1.x,k1.y,k1.z,k2.x,k2.y,k2.z), k1.poluprecnik + k2.poluprecnik);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return DaLiJeJednako(UdaljenostDvijeTacke(k1.x,k1.y,k1.z,k2.x,k2.y,k2.z), fabs(k1.poluprecnik - k2.poluprecnik)) && !DaLiJeJednako(k1.poluprecnik,k2.poluprecnik);
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return(DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1) || DaLiSeDodirujuIznutra(k1,k2) || DaLiSuIdenticne(k1,k2) || DaLiSuKoncentricne(k1,k2));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return((UdaljenostDvijeTacke(k1.x,k1.y,k1.z,k2.x,k2.y,k2.z) < k1.poluprecnik + k2.poluprecnik) && !DaLiJeJednako(UdaljenostDvijeTacke(k1.x,k1.y,k1.z,k2.x,k2.y,k2.z), k1.poluprecnik + k2.poluprecnik)
    && !(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) && !DaLiSeDodirujuIznutra(k1,k2) && !DaLiSuIdenticne(k1,k2));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return UdaljenostDvijeTacke(k1.x,k1.y,k1.z,k2.x,k2.y,k2.z);
}

int main ()
{
    /*Kugla k1(0,0,0,4), k2(6,0,0,3);
    std::cout << RastojanjeCentara(k1,k2);*/
    bool nije_ispravno(false);
    char c;
    std::vector<std::shared_ptr<Kugla>> vektor;
    int n;
    do {
        if(!nije_ispravno)std::cout << "Unesite broj kugla: ";
        else std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin >> n;
        nije_ispravno = false;
        c = std::cin.peek();
            if(c != '\n' && c != ' ') {
                nije_ispravno = true;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
            }
        if(n < 1) {
            nije_ispravno = true;
        }
    } while(nije_ispravno);
    double  x,y,z,r;
    
    for(int i = 0; i < n; i++) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        std::cin >> x >> y >> z;
        c = std::cin.peek();
        if(c != '\n' && c != ' ') {
            std::cout << "Neispravan centar\n";
            i -= 1;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        c = std::cin.peek();
        if((c != '\n' && c != ' ') || r < 0) {
            std::cout << "Ilegalan poluprecnik\n";
            i -= 1;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        try {
            vektor.push_back(std::make_shared<Kugla> (x,y,z,r));
        } catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    nije_ispravno = false;
    do {
        if(!nije_ispravno) std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        nije_ispravno = false;
        std::cin >> x >> y >> z;
        if(!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
            nije_ispravno = true;    
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            }
    } while(nije_ispravno);
    
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [x,y,z] (std::shared_ptr<Kugla> pok) {
        pok->Transliraj(x,y,z);
        return pok;
    });
    
    std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> pok, std::shared_ptr<Kugla> pok1) {
        return pok->DajZapreminu() < pok1->DajZapreminu();
    });
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> &pok) {
       pok->Ispisi(); 
    });
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*std::max_element(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> pok, std::shared_ptr<Kugla> pok1) {
        return pok1->DajPovrsinu() > pok->DajPovrsinu();
    }))->Ispisi();
    
    int brojac(0);
    int i(0);
    std::for_each(vektor.begin(), vektor.end(), [&vektor,&brojac,&i] (std::shared_ptr<Kugla> &pok) { 
         std::for_each(vektor.begin() + i, vektor.end(), [pok,&brojac,&i] (std::shared_ptr<Kugla> &pok1) { 
            if(DaLiSeSijeku(*pok,*pok1)) {
                i++;
                brojac++;
                std::cout << "Presjecaju se kugle: ";
                pok->Ispisi(); pok1->Ispisi();
            }
        });
    });
    if(brojac == 0) std::cout << "Ne postoje kugle koje se presjecaju!";
    
	return 0;
}
