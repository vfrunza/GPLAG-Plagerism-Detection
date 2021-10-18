/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>

struct Kugla {
    double x, y, z, r;
};

class NepreklapajucaKugla {
    using PokNaKuglu = NepreklapajucaKugla*;
    private:
        static PokNaKuglu lastSphere;
        PokNaKuglu previousSphere;
        double x, y, z, r;
        
        /// additional functions and variables
		constexpr static double PI = 4 * atan(1);
		constexpr static double ERROR = std::pow(10, -10);
		
		/// additional control functions
		bool static _equal(const double& x, const double& y) { return std::fabs(x - y) < ERROR; };
        void static checkCenter(const double& _r) { if(_r < 0) throw std::domain_error("Ilegalan poluprecnik");}
        double static _SQR(const double& x) { return x*x; };
        double static _distance(const double& x1, const double& y1, const double& z1, 
                            const double& x2, const double& y2, const double& z2) { return _SQR(x1 - x2) + _SQR(y1 - y2) + _SQR(z1 - z2); }
        /// function to check if sphere details
        double static KugleRastojanje(const Kugla &k1, const Kugla &k2) { return std::sqrt(_distance(k1.x, k1.y, k1.z, k2.x, k2.y, k2.z)); }
        bool static DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) { return _equal(k1.r, k2.r) && _equal(k1.x, k2.x) && _equal(k1.y, k2.y) && _equal(k1.z, k2.z); }
    	bool static CenterIn(const Kugla& k1, const Kugla& k2) { return KugleRastojanje(k1, k2) <= std::fabs(k1.r - k2.r); }
        bool static CenterOut(const Kugla& k1, const Kugla& k2) { return KugleRastojanje(k1, k2) >= std::fabs(k1.r + k2.r); }
        bool static DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) { return _equal(KugleRastojanje(k1, k2), k1.r + k2.r) && CenterOut(k1, k2); }
        bool static DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) { return DaLiSeSijeku(k1, k2) || CenterIn(k1, k2) || DaLiSeDodirujuIzvana(k1, k2); }
        bool static DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
            bool _return(false);
            if(CenterIn(k1, k2)) _return = k1.r + KugleRastojanje(k1, k2) > k2.r - ERROR;
            else if(CenterIn(k2, k1)) _return = k2.r + KugleRastojanje(k1, k2) > k1.r - ERROR;
            else _return = KugleRastojanje(k1, k2) < k1.r + k2.r + ERROR;
            return _return;
        }
        /// check intersection
        void static checkIntersection(const std::tuple<double, double, double>& centar, const double& poluprecnik) {
            return checkIntersection(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), poluprecnik);
        }
        void static checkIntersection(const double& _x, const double& _y, const double& _z, const double& _r) {
            for(auto it(NepreklapajucaKugla::lastSphere); it != nullptr; it = it->previousSphere)
                if(DaLiSePreklapaju({_x, _y, _z, _r}, {it->x, it->y, it->z, it->r})) 
                    throw std::logic_error("Nedozvoljeno preklapanje");
        }
    public:
        void setPointers();
        /// constructors and destructor
        NepreklapajucaKugla(const NepreklapajucaKugla&) = delete;
        NepreklapajucaKugla& operator=(const NepreklapajucaKugla&) = delete;
        
        NepreklapajucaKugla(NepreklapajucaKugla&&) = delete; 
        NepreklapajucaKugla& operator=(NepreklapajucaKugla&&) = delete;
        
        explicit NepreklapajucaKugla(double r = 0);
        NepreklapajucaKugla(double x, double y, double z, double r = 0);
        explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
        ~NepreklapajucaKugla();
        
        /// inspectors
        double DajX() const { return x; };
        double DajY() const { return y; };
        double DajZ() const { return z; };
        std::tuple<double, double, double> DajCentar() const { return std::make_tuple(this->DajX(), this->DajY(), this->DajZ()); };
        double DajPoluprecnik() const { return r; };
        double DajPovrsinu() const { return 4 * PI * _SQR(this->DajPoluprecnik()); };
        double DajZapreminu() const { return this->DajPovrsinu() * this->DajPoluprecnik() / 3.; };
        void Ispisi() const;
        bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
        
        /// mutators
        NepreklapajucaKugla &PostaviX(double x);
        NepreklapajucaKugla &PostaviY(double y);
        NepreklapajucaKugla &PostaviZ(double z);
        NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
        NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
        NepreklapajucaKugla &PostaviPoluprecnik(double r);
        void Transliraj(double delta_x, double delta_y, double delta_z);
        
        /// friend functions
        friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2); /// check if sphere intersects with rest
};

/// implementing constructors, destructor and list connections
void NepreklapajucaKugla::setPointers() {
    this->previousSphere = lastSphere;
    lastSphere = this;
}
NepreklapajucaKugla::NepreklapajucaKugla(double r) : x(0), y(0), z(0) {
    checkCenter(r);
    checkIntersection(0, 0, 0, r);
    NepreklapajucaKugla::r = r;
    this->setPointers();
}
NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r) : x(x), y(y), z(z) {
    checkCenter(r);
    checkIntersection(x, y, z, r);
    NepreklapajucaKugla::r = r;
    this->setPointers();
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r) : 
    x(std::get<0>(centar)), 
    y(std::get<1>(centar)),
    z(std::get<2>(centar)) {
    checkCenter(r);
    checkIntersection(centar, r);
    NepreklapajucaKugla::r = r;
    this->setPointers();
}
NepreklapajucaKugla::~NepreklapajucaKugla() {
    NepreklapajucaKugla* it(lastSphere);
    
    if (lastSphere == this) {
        lastSphere = lastSphere->previousSphere;
        return;
    }
    for (;it != nullptr && it->previousSphere != this; it = it->previousSphere);
    if(it != nullptr) it->previousSphere = it->previousSphere->previousSphere;
}
/// other interface implementations (mutators and inspectors)
NepreklapajucaKugla& NepreklapajucaKugla::PostaviX(double x) { 
    checkIntersection(x, this->DajY(), this->DajZ(), this->DajPoluprecnik());
    NepreklapajucaKugla::x = x; return *this; 
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviY(double y) { 
    checkIntersection(this->DajX(), y, this->DajZ(), this->DajPoluprecnik());
    NepreklapajucaKugla::y = y; return *this; 
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviZ(double z) { 
    checkIntersection(this->DajX(), this->DajY(), z, this->DajPoluprecnik());
    NepreklapajucaKugla::z = z; return *this; 
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(double x, double y, double z) { 
    checkIntersection(x, y, z, this->DajPoluprecnik());
    return this->PostaviX(x).PostaviY(y).PostaviZ(z); 
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar) { 
    checkIntersection(centar, this->DajPoluprecnik());
    return this->PostaviX(std::get<0>(centar)).PostaviY(std::get<1>(centar)).PostaviZ(std::get<2>(centar)); 
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviPoluprecnik(double r) { 
    checkCenter(r); 
    checkIntersection(this->DajX(), this->DajY(), this->DajZ(), r);
    NepreklapajucaKugla::r = r; return *this; 
}
void NepreklapajucaKugla::Ispisi() const { 
    std::cout << "{(" << this->DajX() << "," <<this->DajY() << ","<<this->DajZ() << "),"<<this->DajPoluprecnik() << "}" << std::endl; 
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    checkIntersection(this->DajX() + delta_x, this->DajY() + delta_y, this->DajZ() + delta_z, this->DajPoluprecnik());
    this->PostaviX(this->DajX() + delta_x).PostaviY(this->DajY() + delta_y).PostaviZ(this->DajZ() + delta_z);
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return std::sqrt(NepreklapajucaKugla::_distance(k1.DajX(), k1.DajY(), k1.DajZ(), k2.DajX(), k2.DajY(), k2.DajZ()));
}
bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const {
    return NepreklapajucaKugla::_equal(this->DajPoluprecnik(), k.DajPoluprecnik()) || (RastojanjeCentara(*this, k) > std::fabs(this->DajPoluprecnik() - k.DajPoluprecnik()));
}

/// initialise pointer last to null
NepreklapajucaKugla* NepreklapajucaKugla::lastSphere = nullptr;

/// main program logic
int main () {
    int n;
    std::cout << "Unesite broj kugli: "; 
    for(;;) {
        std::cin >> n;
        if(!std::cin || n <= 0) {
            if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
            std::cout << "Neispravan broj kugli, unesite ponovo!\n";
            continue;
        }
        break;
    }
    /// read data
    double x, y, z, r;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> _kugle;
    for(int i = 1; i <= n;) {
        std::cout << "Unesite centar za " << i << ". kuglu: ";
        for(;;) {
            std::cin >> x >> y >> z;
            if(!std::cin) {
                std::cout << "Neispravan centar, unesite ponovo:\n"; 
                std::cin.clear(); std::cin.ignore(10000, '\n');
                continue;
            } else break;
        }
        std::cout << "Unesite poluprecnik: ";
        for(;;) {
            std::cin >> r;
            if(!std::cin || r < 0) {
                std::cout << "Neispravan poluprecnik, unesite ponovo:\n"; 
                if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
                continue;
            } else break;
        }
		try {
			_kugle.push_back(std::shared_ptr<NepreklapajucaKugla>(new NepreklapajucaKugla(x, y, z, r)));
			++i;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }
    /// sort
    std::sort(_kugle.begin(), _kugle.end(), [](const std::shared_ptr<NepreklapajucaKugla> &_kugla1, const std::shared_ptr<NepreklapajucaKugla> &_kugla2) {
        return _kugla1->DajPovrsinu() < _kugla2->DajPovrsinu();
    });
    /// print
    std::cout << std::endl << "Kugle nakon obavljenog sortiranja: \n";
    std::for_each(_kugle.begin(), _kugle.end(), [](const std::shared_ptr<NepreklapajucaKugla> &_kugla) { _kugla->Ispisi(); });
	return 0;
}