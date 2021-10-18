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



class NepreklapajucaKugla {
    double x,y,z,poluprecnik;
    NepreklapajucaKugla *pok_na_prethodnu_kuglu = nullptr;
    static NepreklapajucaKugla *pok_na_posljednju;
    bool TestPreklapanja() const;
public:
    explicit NepreklapajucaKugla(double r = 0) : x(0), y(0), z(0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
        if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje");
        pok_na_prethodnu_kuglu = pok_na_posljednju;
        pok_na_posljednju = this;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) : x(x), y(y), z(z) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
        if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje");
        pok_na_prethodnu_kuglu = pok_na_posljednju;
        pok_na_posljednju = this;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
        std::tie(x,y,z) = centar;
        if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje");
        pok_na_prethodnu_kuglu = pok_na_posljednju;
        pok_na_posljednju = this;
    }
    NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator=(NepreklapajucaKugla &&k) = delete;
    ~NepreklapajucaKugla() {
        if(pok_na_prethodnu_kuglu == nullptr) {
            auto pok(pok_na_posljednju);
            while(pok != this) pok = pok->pok_na_prethodnu_kuglu;
            pok->pok_na_prethodnu_kuglu = nullptr;
        } else if(pok_na_posljednju == this) {
            pok_na_posljednju = pok_na_prethodnu_kuglu;
            pok_na_prethodnu_kuglu = nullptr;
        } else  {
            auto pok(pok_na_posljednju);
            while(pok != this) pok = pok->pok_na_prethodnu_kuglu;
            pok->pok_na_prethodnu_kuglu = pok_na_prethodnu_kuglu;
            pok_na_prethodnu_kuglu = nullptr;
        }
        
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return poluprecnik; }
    double DajPovrsinu() const { return 4*poluprecnik*poluprecnik*4*atan(1); }
    double DajZapreminu() const { return (4*poluprecnik*poluprecnik*poluprecnik*4*atan(1))/3; }
    NepreklapajucaKugla &PostaviX(double x) { NepreklapajucaKugla::x = x; if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje"); return *this; }
    NepreklapajucaKugla &PostaviY(double y) { NepreklapajucaKugla::y = y; if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje"); return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { NepreklapajucaKugla::z = z; if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje"); return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) { 
        NepreklapajucaKugla::x = x; NepreklapajucaKugla::y = y; NepreklapajucaKugla::z = z; 
        if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje"); 
        return *this; 
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) { std::tie(x,y,z) = centar; if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje"); return *this; }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); poluprecnik = r;
        if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje");
        return *this;
    }
    void Ispisi() const { std::cout << "{(" << x << "," << y <<"," << z << ")," << poluprecnik << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { x += delta_x; y += delta_y; z += delta_z; if(TestPreklapanja()) throw std::logic_error("Nedozvoljeno preklapanje"); }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const { return(RastojanjeCentara(*this, k) + k.poluprecnik) < poluprecnik; }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return sqrt((k1.x - k2.x)*(k1.x - k2.x) + (k1.y - k2.y)*(k1.y - k2.y) + (k1.z - k2.z)*(k1.z - k2.z));
}

NepreklapajucaKugla *NepreklapajucaKugla::pok_na_posljednju = nullptr;


bool NepreklapajucaKugla::TestPreklapanja() const
{
    auto pok(pok_na_posljednju);
    while(pok != nullptr) {
        if(this != pok && RastojanjeCentara(*this,*pok) <= poluprecnik + pok->poluprecnik) return true;
        pok = pok->pok_na_prethodnu_kuglu;
    }
    return false;
}

int main ()
{
   /*NepreklapajucaKugla k1(2, 3, 1, 5);
NepreklapajucaKugla k2(10, 7, 8, 2);
NepreklapajucaKugla k3(15, 15, 15, 7);
   k3.PostaviCentar(3,5,5);*/
    bool nije_ispravno(false);
    char c;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor;
    int n;
    do {
        if(!nije_ispravno)std::cout << "Unesite broj kugli: ";
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
    nije_ispravno = false;
    
    for(int i = 0; i < n; i++) {
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        do {
            nije_ispravno = false;
            std::cin >> x >> y >> z;
            c = std::cin.peek();
            if(!std::cin) {
            std::cout << "Neispravan centar, unesite ponovo\n";
            nije_ispravno = true;    
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            }
        } while(nije_ispravno);
        nije_ispravno = false;
        std::cout << "Unesite poluprecnik: ";
        do {
            nije_ispravno = false;
            std::cin >> r;
            if(!std::cin || r < 0) {
            std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
            nije_ispravno = true;    
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            }
    } while(nije_ispravno);
        try {
           vektor.push_back(std::make_shared<NepreklapajucaKugla> (x,y,z,r));
        } catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        } catch (std::logic_error izuzetak) {
            i--;
            std::cout << izuzetak.what() << std::endl;
        }
    }
    std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<NepreklapajucaKugla> pok, std::shared_ptr<NepreklapajucaKugla> pok1) {
        return pok->DajPovrsinu() < pok1->DajPovrsinu();
    });
    std::cout << "\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(vektor.begin(), vektor.end(), [] (std::shared_ptr<NepreklapajucaKugla> pok) { pok->Ispisi();} );
 
	return 0;
}
