/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>

const PI (atan(1))

class Kugla {
    private:
    double x;
    double y;
    double z;
    
    public:
    explicit Kugla(double r = 0) {
        Kugla::x = 0,
        Kugla::y = 0;
        Kugla::z = 0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        Kugla::x = std::get<0>(centar);
        Kugla::y = std::get<1> (centar);
        Kugla::z = std::get<2>(centar);
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
        // return make tuple?
    }
    double DajPoluprecnik() const {
        return Kugla::r;
    }
    double DajPovrsinu() const;
    double DajZapreminu() const {
        return (4/3 * r * r * r * PI)
    }
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

int main ()
{
	return 0;
}
