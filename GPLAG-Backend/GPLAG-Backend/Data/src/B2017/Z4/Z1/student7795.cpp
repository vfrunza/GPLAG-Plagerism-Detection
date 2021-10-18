/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>

class Kugla {
    private:
        double x, y, z, r;
        /// additional functions and variables
		constexpr static double PI = 4 * atan(1);
		constexpr static double ERROR = std::pow(10, -10);
		
        void static checkCenter(const double& _r) { if(_r < 0) throw std::domain_error("Ilegalan poluprecnik"); }
        bool static _equal(const double& x, const double& y) { return std::fabs(x - y) <= ERROR * (std::fabs(x) + std::fabs(y)); };
        double static _SQR(const double& x) { return x*x; };
        double static _distance(const double& x1, const double& y1, const double& z1, 
                            const double& x2, const double& y2, const double& z2) { return _SQR(x1 - x2) + _SQR(y1 - y2) + _SQR(z1 - z2); }
        bool static CenterIn(const Kugla& k1, const Kugla& k2) { return RastojanjeCentara(k1, k2) <= std::fabs(k1.r - k2.r) + ERROR; }
        bool static CenterOut(const Kugla& k1, const Kugla& k2) { return RastojanjeCentara(k1, k2) > k1.r + k2.r - ERROR; }
    // public interface
    public:
        /// constructors
        explicit Kugla(double r = 0);
        Kugla(double x, double y, double z, double r = 0);
        explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
        
        /// inspectors
        double DajX() const { return x; };
        double DajY() const { return y; };
        double DajZ() const { return z; };
        std::tuple<double, double, double> DajCentar() const { return std::make_tuple(this->DajX(), this->DajY(), this->DajZ()); };
        double DajPoluprecnik() const { return r; };
        double DajPovrsinu() const { return 4 * PI * _SQR(this->DajPoluprecnik()); };
        double DajZapreminu() const { return this->DajPovrsinu() * this->DajPoluprecnik() / 3.; };
        void Ispisi() const;
        bool DaLiSadrzi(const Kugla &k) const;
        
        /// mutators
        Kugla &PostaviX(double x) { Kugla::x = x; return *this; };
        Kugla &PostaviY(double y) { Kugla::y = y; return *this; };
        Kugla &PostaviZ(double z) { Kugla::z = z; return *this; };
        Kugla &PostaviCentar(double x, double y, double z) { return this->PostaviX(x).PostaviY(y).PostaviZ(z); };
        Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { return this->PostaviX(std::get<0>(centar)).PostaviY(std::get<1>(centar)).PostaviZ(std::get<2>(centar)); };
        Kugla &PostaviPoluprecnik(double r) { checkCenter(r); Kugla::r = r; return *this; };
        void Transliraj(double delta_x, double delta_y, double delta_z);
        
        /// friend functions
        friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
        friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

// implementation of constructors
Kugla::Kugla(double r) : x(0), y(0), z(0) {
    checkCenter(r);
    Kugla::r = r;
}
Kugla::Kugla(double x, double y, double z, double r) : x(x), y(y), z(z) {
    checkCenter(r);
    Kugla::r = r;
}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r) : 
    x(std::get<0>(centar)), 
    y(std::get<1>(centar)),
    z(std::get<2>(centar)) {
    checkCenter(r);
    Kugla::r = r;
}
/// implementation of additional inspectors and mutators
void Kugla::Ispisi() const { 
    std::cout << "{(" << this->DajX() << "," <<this->DajY() << ","<<this->DajZ() << "),"<<this->DajPoluprecnik() <<"}" << std::endl; 
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    this->PostaviX(this->DajX() + delta_x).PostaviY(this->DajY() + delta_y).PostaviZ(this->DajZ() + delta_z);
}
/// friend functions implementation
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return DaLiSuPodudarne(k1, k2) && DaLiSuKoncentricne(k1, k2); 
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return Kugla::_equal(k1.DajPoluprecnik(), k2.DajPoluprecnik()); 
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return Kugla::_equal(k1.DajX(), k2.DajX()) && Kugla::_equal(k1.DajY(), k2.DajY()) && Kugla::_equal(k1.DajZ(), k2.DajZ());
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return Kugla::_equal(RastojanjeCentara(k1, k2), k1.DajPoluprecnik() + k2.DajPoluprecnik()) && 
            (Kugla::CenterOut(k1, k2));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    bool _return(false);
    
    if(Kugla::CenterIn(k1, k2))
        _return = Kugla::_equal(RastojanjeCentara(k1, k2) + k1.r, k2.r);
    if(!_return && Kugla::CenterIn(k2, k1))
        _return = Kugla::_equal(RastojanjeCentara(k1, k2) + k2.r, k1.r);
    
    if(_return && DaLiSuIdenticne(k1, k2) && k1.r > Kugla::ERROR)
        _return = false;
    return _return;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt(Kugla::_distance(k1.DajX(), k1.DajY(), k1.DajZ(), k2.DajX(), k2.DajY(), k2.DajZ()));
}
bool Kugla::DaLiSadrzi(const Kugla &k) const {
    return Kugla::CenterIn(k, *this) && r >= RastojanjeCentara(k, *this) + k.r;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return DaLiSeSijeku(k1, k2) || Kugla::CenterIn(k1, k2) || DaLiSeDodirujuIznutra(k1, k2) || DaLiSeDodirujuIzvana(k1, k2);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    bool _return(false);
    
    if(Kugla::CenterIn(k1, k2))
        _return = k1.r + RastojanjeCentara(k1, k2) > k2.r;
    else if(Kugla::CenterIn(k2, k1))
        _return = k2.r + RastojanjeCentara(k1, k2) > k1.r;
    else 
        _return = RastojanjeCentara(k1, k2) < k1.r + k2.r;
    
    return _return;
}

/// read function
Kugla UnesiKuglu(int id = 1) {
    double x, y, z, r;
    for(;;) {
        std::cout << "Unesite centar " << id << ". kugle: "; std::cin >> x >> y >> z;
        if(!std::cin) {
            std::cout << "Neispravan centar\n"; 
            std::cin.clear(); std::cin.ignore(10000, '\n');
            continue;
        }
        std::cout << "Unesite poluprecnik " << id << ". kugle: "; std::cin >> r;
        if(!std::cin || r < 0) {
            std::cout << "Ilegalan poluprecnik\n"; 
            if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
            continue;
        }
        break;
    } 
    return Kugla(x, y, z, r);
}

// main program logic
int main () {
    int n;
    std::vector<std::shared_ptr<Kugla>> _kugle;
    std::cout << "Unesite broj kugla: "; 
    for(;;) {
        std::cin >> n;
        if(!std::cin || n <= 0) {
            if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
            std::cout << "Neispravan broj kugli, unesite ponovo!\n";
            continue;
        } break;
    }
    /// read spheres
    for(int i = 1; i <= n; ++i)  _kugle.push_back(std::make_shared<Kugla>(UnesiKuglu(i)));
    /// transform spheres
    double dx, dy, dz;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): "; 
    for(;;) {
        std::cin >> dx >> dy >> dz;
        if(!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear(); std::cin.ignore(10000, '\n'); 
            continue;
        } break;
    }
    /// translate spheres
    std::transform(_kugle.begin(), _kugle.end(), _kugle.begin(), [dx, dy, dz](std::shared_ptr<Kugla> _kugla) {
        _kugla->Transliraj(dx, dy, dz);
        return _kugla;
    });
    /// sort spheres by volume
    std::sort(_kugle.begin(), _kugle.end(), [](const std::shared_ptr<Kugla> &_kugla1, const std::shared_ptr<Kugla> &_kugla2) {
        return _kugla1->DajZapreminu() < _kugla2->DajZapreminu();
    });
    /// print spheres after transformation and sort
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(_kugle.begin(), _kugle.end(), [](const std::shared_ptr<Kugla> &_kugla) {
        _kugla->Ispisi(); 
    });
    /// find and print max element (by surface area)
    auto _max (std::max_element(_kugle.begin(), _kugle.end(), [](const std::shared_ptr<Kugla> &_kugla1, const std::shared_ptr<Kugla> &_kugla2) {
        return _kugla1->DajPovrsinu() < _kugla2->DajPovrsinu();
    }));
    if(_max != _kugle.end()) { std::cout << "Kugla sa najvecom povrsinom je: "; (*_max)->Ispisi(); }
    else std::cout << "Kugla sa najvecom povrsinom nije pronadjena.\n";
    /// print spheres that intersect 
    bool _exists(false);
    std::vector<std::shared_ptr<Kugla> >::iterator _pos (_kugle.begin()), _end(_kugle.end());
    std::for_each(_kugle.begin(), _kugle.end(), [_kugle, &_exists, &_pos, &_end](const std::shared_ptr<Kugla> &_prev) {
       ++_pos;
       std::for_each(_pos, _end, [_prev, &_exists](const std::shared_ptr<Kugla> &_next)  {
            if(DaLiSeSijeku(*_prev, *_next)) {
                std::cout << "Presjecaju se kugle: ";
                _prev->Ispisi();  
                _next->Ispisi();
                _exists = true;
            }
       });
    });
    if(!_exists) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}