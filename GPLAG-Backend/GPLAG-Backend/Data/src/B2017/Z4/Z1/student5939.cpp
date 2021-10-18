/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <iostream>
#include <vector> 
#include <memory>
#include <algorithm>
#include <locale>
#define PI 3.14159265359
//#define eps 10e-10

class Kugla {
    private:
        double x,y,z,r;
    public:
        explicit Kugla(double r = 0): x{0},y{0},z{0} {
            if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::r = r;
        }
        
        Kugla(double x, double y, double z, double r = 0) {
            if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::x = x;
            Kugla::y = y;
            Kugla::z = z;
            Kugla::r = r;
        }
        
        explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
            if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::x = std::get<0>(centar);
            Kugla::y = std::get<1>(centar);
            Kugla::z = std::get<2>(centar);
            Kugla::r = r;
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
        
        std::tuple<double, double, double> DajCentar() const {
            return std::make_tuple(x,y,z);
        }
        
        double DajPoluprecnik() const {
            return r;
        }
        
        double DajPovrsinu() const {
            return 4*PI*pow(DajPoluprecnik(),2);
        }
        
        double DajZapreminu() const {
            return 4/3*pow(DajPoluprecnik(), 3.0) * PI; 
        }
        
        Kugla &PostaviX(double x) {
            Kugla::x = x;
            return *this;
        }
        
        Kugla &PostaviY(double y) {
            Kugla::y=y;
            return *this;
        }
        
        Kugla &PostaviZ(double z) {
            Kugla::z=z;
            return *this;
        }
        
        Kugla &PostaviCentar(double x, double y, double z) {
            Kugla::x=x;
            Kugla::y=y;
            Kugla::z=z;
            return *this;
        }
        
 
        
        Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
            Kugla::x=std::get<0>(centar);
            Kugla::y=std::get<1>(centar);
            Kugla::z=std::get<2>(centar);
           // if ((int(Kugla::x)>='a' && int(Kugla::x)<='z') ||  (int(Kugla::y)>='a' && int(Kugla::y)<='z') || (int(Kugla::z)>='a' && int(Kugla::z)<='z')) throw std::domain_error("Neispravan centar");
            return *this;
        }
        
        Kugla &PostaviPoluprecnik(double r) {
            if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::r = r;
            return *this;
        }
        
        void Ispisi() const {
            std::cout << "{(" << this->x << "," << this->y << "," << this->z << ")," << DajPoluprecnik() << "}" << std::endl;
         }
        
        void Transliraj(double delta_x, double delta_y, double delta_z) {
            Kugla::x += delta_x;
            Kugla::y += delta_y;
            Kugla::z += delta_z;
        }
        
        friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
            return k1.x == k2.x && k1.y == k2.y && k1.z == k2.z && k1.r == k2.r;
        }
        
        friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
            return k1.r == k2.r;
        }
        
        friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
            return k1.x == k2.x && k1.y == k2.y && k1.z == k2.z;
        }
        
        friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
            return fabs(RastojanjeCentara(k1,k2)) == k1.r + k2.r || fabs(RastojanjeCentara(k1,k2)) == fabs(k1.r - k2.r);
        }
        
        friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
            return fabs(RastojanjeCentara(k1,k2)) > k1.r + k2.r && fabs(RastojanjeCentara(k1,k2)) < fabs(k1.r - k2.r);
        }
        
        friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
            if (DaLiSeSijeku(k1,k2))
            return true;
            else if (fabs(RastojanjeCentara(k1,k2)) < veci_poluprecnik(k1,k2)) return true;
            else return false;
            
        }
        
        friend double veci_poluprecnik(const Kugla &k1, const Kugla &k2) {
            if (k1.r > k2.r) return k1.r;
            else return k2.r;
            
        }
        
        friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
            /*bool a = fabs(RastojanjeCentara(k1,k2)) < k1.r + k2.r;
            std::cout << "PRVI USLOV: " << a << std::endl;
            bool b = fabs(RastojanjeCentara(k1,k2)) > fabs(k1.r - k2.r);
            std::cout << "DRUGI USLOV: " << b << std::endl;
            bool c = a && b;
            return c;*/
            return (fabs(RastojanjeCentara(k1,k2)) < k1.r + k2.r) && (fabs(RastojanjeCentara(k1,k2)) > fabs(k1.r - k2.r));
            
        }
        
        bool DaLiSadrzi(const Kugla &k) const {
            double s(std::sqrt((k.x-x)*(k.x-x)+(k.y-y)*(k.y-y)+(k.z-z)*(k.z-z)));
            if(s<std::fabs(r-k.r)) return true;
            else return false;
            
        }
        
        friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
          return sqrt(pow((k2.x - k1.x),2.0) + pow((k2.y - k1.y), 2.0) + pow((k2.z - k1.z), 2.0));
        }
        /*friend bool DaLiJeJednako (double x, double y) {
            return abs(x-y) < eps*(abs(x)+abs(y));
        }*/
        
        
        };

int main ()
{
    int n{0};
    double x,y,z,r;
    double delta_y, delta_x, delta_z;

    std::cout << "Unesite broj kugla: " ;
    //std::cin >> n;
    
    while(!(std::cin >> n) || n <= 0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::tuple<double, double, double> t;
    
    std::vector<std::shared_ptr<Kugla>> e(n);
    
    for (int i = 0; i < e.size(); i++) {
        
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        while (!(std::cin >> x) || !(std::cin >> y) || !(std::cin >> z)) {
                std::cout << "Neispravan centar";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << std::endl;
                std::cout << "Unesite centar " << i+1 << ". kugle: ";
        }
        //std::cin >> x >> y >> z;
        t = std::make_tuple(x,y,z);
        
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        while(!(std::cin >> r)) {
            std::cout << "Ilegalan poluprecnik";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << std::endl;
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin >> x >> y >> z;
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        }
 
        try {
        e[i] = std::make_shared<Kugla>(t,r);
        e[i]->PostaviPoluprecnik(r);
        e[i]->PostaviCentar(t);
        
        }
        catch(std::domain_error e) {
            std::cout << e.what();
            i--;
            std::cout << std::endl;
        }
        
    }

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while (!(std::cin >> delta_x) || !(std::cin >> delta_y) || !(std::cin >> delta_z)) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!";
        std::cin.clear();
        std::cin.ignore (10000, '\n');
        std::cout << std::endl;
    }
    //std::cin >>delta_x >> delta_y >> delta_z;
    
    transform(e.begin(), e.end(), e.begin(), [delta_x,delta_y,delta_z](std::shared_ptr <Kugla> &u) {u->Transliraj(delta_x,delta_y,delta_z); return move(u); });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    sort(e.begin(), e.end(), [](const std::shared_ptr<Kugla> &k, const std::shared_ptr<Kugla> &k1) {return k->DajZapreminu() < k1 -> DajZapreminu();});
    
    std::for_each(e.begin(), e.end(), [](const std::shared_ptr <Kugla> &u) {u->Ispisi();});
    std::cout << "Kugla sa najvecom povrsinom je: ";
    std::shared_ptr<Kugla> max_povrsina = *max_element(e.begin(), e.end(), [](const std::shared_ptr <Kugla> &u1, const std::shared_ptr <Kugla> &u2) {return u2->DajPovrsinu() > u1->DajPovrsinu();});
    max_povrsina->Ispisi();
    //std::cout << std::endl;
    
    int brojac=0;
    int broj=0;
    
    std::for_each(e.begin(), e.end(), [&e, &brojac, &broj](std::shared_ptr<Kugla> k1) {
        brojac++;
        std::for_each (e.begin()+brojac, e.end(), [&e, &k1,&brojac,&broj](std::shared_ptr<Kugla> k2) {
            if (DaLiSeSijeku(*k1,*k2)) {
                std::cout << "Presjecaju se kugle: ";
                broj++;
                k1->Ispisi();
                k2->Ispisi();
            }
        }
    );});
    
    if(broj == 0) std::cout << "Ne postoje kugle koje se presjecaju!";
    
    
	return 0;
}
