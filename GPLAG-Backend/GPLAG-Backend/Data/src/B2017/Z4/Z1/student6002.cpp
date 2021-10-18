#include <iostream>
#include<tuple>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>

class Kugla
{
    double x_koordinata, y_koordinata, z_koordinata, poluprecnik;

public:

    explicit Kugla( double r = 0 ) {
        if ( r < 0 ) throw std::domain_error ( "Ilegalan  poluprecnik" );
        x_koordinata = 0;
        z_koordinata = 0;
        y_koordinata = 0;
        poluprecnik = r;
    }
    Kugla(double x, double y,double z,double r = 0) {
        if ( r < 0 ) throw std::domain_error ( "Ilegalan  poluprecnik" );
        x_koordinata = x;
        z_koordinata = z;
        y_koordinata = y;
        poluprecnik = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if ( r < 0 ) throw std::domain_error ( "Ilegalan  poluprecnik" );
        x_koordinata = std::get<0>(centar);
        y_koordinata = std::get<1>(centar);
        z_koordinata = std::get<2>(centar);
        poluprecnik = r;
    }
    double DajX() const {
        // return x_koordinata;
    }
    double DajY() const {
        // return y_koordinata;
    }
    double DajZ() const {
        // return z_koordinata;
    }
    std::tuple<double, double, double> DajCentar() const {
        Kugla();
        return std::tie(x_koordinata, y_koordinata, z_koordinata);
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4 * 4 * atan(1) * poluprecnik * poluprecnik;
    }
    double DajZapreminu() const {
        return (4./3) * 4 * atan (1) * poluprecnik * poluprecnik * poluprecnik;
    }
    Kugla &PostaviX(double x) { }
    Kugla &PostaviY(double y) { }
    Kugla &PostaviZ(double z) { }
    Kugla &PostaviCentar(double x, double y, double z) {
        // return std::tie(x_koordinata, y_koordinata, z_koordinata);
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        // return std::tie(x_koordinata, y_koordinata, z_koordinata);
    }
    Kugla &PostaviPoluprecnik(double r) {
        if ( r < 0 ) throw std::domain_error ( "Ilegalan  poluprecnik" );
        poluprecnik = r;
    }
    void Ispisi() const {
        std::cout << "{(" << x_koordinata << ", " << y_koordinata << ", " << z_koordinata << "), " << poluprecnik << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x_koordinata += delta_x;
        y_koordinata += delta_y;
        z_koordinata += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        if ( k1.x_koordinata != k2.x_koordinata || k1.y_koordinata != k2.y_koordinata ||
                k1.z_koordinata != k2.z_koordinata || k1.poluprecnik != k2.poluprecnik )
            return false;
        return true;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        if ( k1.poluprecnik == k2.poluprecnik )
            return true;
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla&k1, const Kugla&k2) {
        if ( k1.x_koordinata == k2.x_koordinata && k1.y_koordinata == k2.y_koordinata && k1.z_koordinata == k2.z_koordinata )
            return true;
        return false;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla&k1, const Kugla&k2) {
        // |O1 O2| = r1 + r2
        if ( sqrt( pow( k1.x_koordinata - k2.x_koordinata,2 ) +  pow( k1.y_koordinata - k2.y_koordinata,2 ) + pow( k1.z_koordinata - k2.z_koordinata,2 ) )
                == k1.poluprecnik + k2.poluprecnik )
            return true;
        return false;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla&k1, const Kugla&k2) {
        // |O1 O2| = |r1 - r2|
        if ( sqrt( pow( k1.x_koordinata - k2.x_koordinata,2 ) + pow( k1.x_koordinata - k2.x_koordinata,2 ) + pow( k1.x_koordinata - k2.x_koordinata,2 ) )
                == abs( k1.poluprecnik - k2.poluprecnik ) )
            return true;
        return false;
    }
    friend bool DaLiSePreklapaju(const Kugla&k1, const Kugla&k2){
        
    }
    friend bool DaLiSeSijeku(const Kugla&k1, const Kugla&k2);
    bool DaLiSadrzi(const Kugla&k) const;
    friend double RastojanjeCentara(const Kugla&k1, const Kugla&k2);
};

int main ()
{
    int n;
    std::cout << "Unesite broj n: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Kugla> > Vektor_kugli(n);
    
    for(int i = 0; i < n; i++){
        Vektor_kugli.at (i) = new Kugla;
    }
    
    
    
    return 0;
}