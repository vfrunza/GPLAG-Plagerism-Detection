#include <iostream>
#include <type_traits>
#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <type_traits>
#include <limits>
#include <memory>
#include <stdexcept>

#include <iomanip>

template <typename To_, typename... From_>
class pretvorba_tipa_vise_argumenata {
private:
    template <typename To>
    struct testKonstrukcije {
        testKonstrukcije(To);
    };

    template <typename To, typename... From>
    struct pomocna {};

    template <typename To, typename... From>
    static auto test(pomocna<To, From...>)
    -> decltype(testKonstrukcije<To>({std::declval<From>()...}), std::true_type());
    static auto test(...)
    -> std::false_type;

public:
    static constexpr bool value = decltype(test(pomocna<To_, From_...>()))::value;
};



bool JednakiDouble(double x, double y){
    return std::fabs(x-y) <= 1e-10 * (std::fabs(x) + std::fabs(y));
    //return x==y;
}

bool JednakiCentri(const std::tuple<double, double, double> &c1, const std::tuple<double, double, double> &c2){
    double x1, x2, y1, y2, z1, z2;
    std::tie(x1, y1, z1) = c1;
    std::tie(x2, y2, z2) = c2;
    return JednakiDouble(x1, x2) && JednakiDouble(y1, y2) && JednakiDouble(z1, z2);
}

double UdaljenostDvijeTacke(const std::tuple<double, double, double> &c1, const std::tuple<double, double, double> &c2) {
    double x1, x2, y1, y2, z1, z2;
    std::tie(x1, y1, z1) = c1;
    std::tie(x2, y2, z2) = c2;
    return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) + (z2-z1) * (z2-z1));
}
class Kugla{
    double x,y,z,r;
    static constexpr double pi = 4 * std::atan(1);
public:
    explicit Kugla(double r);
    Kugla(double x, double y, double z, double r);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r);
    double DajX() const { return x; }
    double DajY() const { return y;}
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); };
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4. * pi * r*r; }
    double DajZapreminu() const { return (4. * pi * r*r*r) / 3.; }
    Kugla &PostaviX(double x) { this->x = x; return *this; }
    Kugla &PostaviY(double y) { this->y = y; return *this; }
    Kugla &PostaviZ(double z) { this ->z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}"; }//endl?
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x+=delta_x; y+=delta_y; z+=delta_z;
    };
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

Kugla::Kugla(double r = 0) {
    PostaviPoluprecnik(r);
    PostaviCentar(0,0,0);
}

Kugla::Kugla(double x, double y, double z, double r = 0) {
    PostaviPoluprecnik(r);
    PostaviCentar(x,y,z);
}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
    PostaviPoluprecnik(r);
    PostaviCentar(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar));
}

Kugla& Kugla::PostaviCentar(double x, double y, double z) {
    this->x = x; this->y = y; this->z = z;
    return *this;
}

Kugla& Kugla::PostaviPoluprecnik(double r) {
    if(r <0) throw std::domain_error("Ilegalan poluprecnik");
    this->r = r;
    return *this;
}

Kugla& Kugla::PostaviCentar(const std::tuple<double, double, double> &centar) {
    PostaviCentar(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar));

}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return DaLiSuPodudarne(k1,k2) && DaLiSuKoncentricne(k1,k2);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return JednakiDouble(k1.DajPoluprecnik(), k2.DajPoluprecnik());
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return JednakiCentri(k1.DajCentar(), k2.DajCentar());
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return JednakiDouble(UdaljenostDvijeTacke(k1.DajCentar(), k2.DajCentar()), k1.DajPoluprecnik() + k2.DajPoluprecnik());
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    return JednakiDouble(UdaljenostDvijeTacke(k1.DajCentar(), k2.DajCentar()), std::fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()))
            && !JednakiCentri(k1.DajCentar(), k2.DajCentar());
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return UdaljenostDvijeTacke(k1.DajCentar(), k2.DajCentar()) < k1.DajPoluprecnik() + k2.DajPoluprecnik();
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return DaLiSePreklapaju(k1, k2) && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1);
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    return fabs(this->r - k.DajPoluprecnik()) > UdaljenostDvijeTacke(this->DajCentar(), k.DajCentar())
            || JednakiDouble(fabs(this->r - k.DajPoluprecnik()), UdaljenostDvijeTacke(this->DajCentar(), k.DajCentar()));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return UdaljenostDvijeTacke(k1.DajCentar(), k2.DajCentar());
}
int main() {

//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//   AT1 - test konstruktora sa jednim parametrom
//    try {
//        std::cout << std::boolalpha << std::is_convertible<double, Kugla>::value << std::endl;
//        Kugla k;
//        k.Ispisi();
//        std::cout << std::endl;
//        Kugla k1(5);
//        k1.Ispisi();
//        std::cout << std::endl;
//        Kugla k2(-1);
//
//    }
//    catch(std::domain_error ex){
//        std::cout << "OK " << ex.what();
//    }
//    catch(...){
//        std::cout << "NOT OK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//    AT2 - Test konstruktora sa 4 parametra
//    try{
//        Kugla k1(5,5,5,5);
//        k1.Ispisi();
//        std::cout << std::endl;
//        Kugla k2 = {-5,-5,-5,2};
//        k2.Ispisi();
//        std::cout << std::endl;
//        Kugla k3(-1,1,-1,-1);
//
//    }
//    catch(std::domain_error ex){
//        std::cout << "OK " << ex.what();
//    }
//    catch(...){
//        std::cout << "NOT OK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//    //AT3 - Test konstruktra sa tuple-om
//
//    try{
//        std::cout << std::boolalpha << pretvorba_tipa_vise_argumenata<Kugla, std::tuple<double, double, double>, double>::value << std::endl;
//        Kugla k1(std::make_tuple(5,5,5),5);
//        k1.Ispisi();
//        std::cout << std::endl;
//        Kugla k2 = {-5,-5,-5,2};
//        k2.Ispisi();
//        std::cout << std::endl;
//        Kugla k3(-1,1,-1,-1);
//
//    }
//    catch(std::domain_error ex){
//        std::cout << "OK " << ex.what();
//    }
//    catch(...){
//        std::cout << "NOT OK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//    //AT4 - Test metoda DajX, DajY, DajZ i DajCentar
//
//    try{
//        const Kugla k(std::make_tuple(1,2,3), 10.5);
//        std:: cout << std::fixed << std::setprecision(3);
//        std::cout << "Centar: " << k.DajX() << " " << k.DajY() << " "<< k.DajZ();
//        std::cout << "\nPoluprecnik: " << k.DajPoluprecnik();
//        Kugla k1 = Kugla(4,3,2,1);
//        std::tuple<double, double, double> centar(k1.DajCentar());
//        std::cout << "\nNovi centar: " <<std::get<0>(centar) << " " << std::get<1>(centar) << " " << std::get<2>(centar);
//
//    }
//    catch(...) {
//        std::cout << "IZUZETAK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT5 - Test metoda DajPovrsinu,  DajZapreminu i Ispisi i RastojanjeCentara
//
//    try{
//        const Kugla k(std::make_tuple(8,16,32), 30.3);
//        const Kugla k1(std::make_tuple(8,-1,30.3), 18.01);
//        std::cout << std::fixed << std::setprecision(5);
//        std::cout << "Povrsina kugle k: " << k.DajPovrsinu()
//                  << "\nZapremina kugle k : " << k.DajZapreminu();
//        std::cout << std::endl;
//        std::cout << "Povrsina kugle k1: " << k.DajPovrsinu()
//                  << "\nZapremina kugle k1: " << k.DajZapreminu();
//        std::cout << "\nRastojanje centara kugle k i k1: "
//                  << RastojanjeCentara(k,k1);
//        std::cout << std::endl << std::defaultfloat;
//        k.Ispisi();
//        std::cout << "\nEND";
//
//    }
//    catch(...) {
//        std::cout << "IZUZETAK";
//    }
////
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//    //AT6 - Test medota PostaviX, PostaviY, PostaviZ
//
//
//    try{
//        Kugla k(std::make_tuple(8,16,32), 30.3);
//        k.PostaviX(-1).PostaviY(-2).PostaviZ(-3);
//        k.Ispisi();
//    }
//    catch(...) {
//        std::cout << "IZUZETAK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT7 - Test metode postavi poluprecnik
//
//    try{
//        Kugla k(std::make_tuple(8,16,32), 30.3);
//        k.PostaviPoluprecnik(20.289);
//        k.Ispisi();
//        std::cout << std::endl;
//        k.PostaviPoluprecnik(-0.0000001);
//
//    }
//    catch(std::domain_error ex){
//        std::cout << "OK " << ex.what();
//    }
//    catch(...) {
//        std::cout << "NOT OK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT8 - Test metoda PostaviCentar
//
//    try{
//        Kugla k(20);
//        k.PostaviCentar(1.5,10,25);
//        k.Ispisi();
//        std::cout << std::endl;
//        k.PostaviCentar(std::make_tuple(25,10,1.5));
//        k.Ispisi();
//    }
//    catch(...){
//       std::cout << "IZUZETAK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT9 - Test metode Transliraj
//
//    try{
//        Kugla k(10,10,10,20);
//        k.Transliraj(20.25, 1e-10,-18.31);
//        k.Transliraj(-20.25, -1e-10,18.31);
//        k.Ispisi();
//    }
//    catch(...){
//       std::cout << "IZUZETAK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
////
//    //AT10 - Test funkcije DaLiSuIdenticne
//
//    try{
//        Kugla k1(1,2,3,4), k2(1,2,3,4);
//        std::cout << std::boolalpha << DaLiSuIdenticne(k1,k2);
//        Kugla k3(1,2,3,4.001);
//        std::cout << " " << DaLiSuIdenticne(k3,k2);
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT11 - Test funkcije DaLiSuPodudarne
//
//    try{
//        Kugla k1(1,2,3+1e-15, 4+1e-15), k2(1,2,3,4);
//        std::cout << std::boolalpha << DaLiSuPodudarne(k1,k2);
//        Kugla k3(1,2,3,4.001);
//        std::cout << " " << DaLiSuPodudarne(k3,k2);
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
//    std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT12 - Test funkcije DaLiSuKoncentricne
//
//    try{
//        Kugla k1(1,2,3+1e-15, 4+1e-15), k2(1,2,3,4);
//        std::cout << std::boolalpha << DaLiSuKoncentricne(k1,k2);
//        Kugla k3(1,2,3.01,4.001);
//        std::cout << " " << DaLiSuKoncentricne(k3,k2);
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
//        std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
////    AT13 - Test funckije DaLiSeDodirujuIzvana
//
//    try{
//        Kugla k1(1,0.3,0.4,0.3), k2(1,0.30000001,0.9,0.2);
//        std::cout << std::boolalpha << DaLiSeDodirujuIzvana(k1,k2);
//        Kugla k3(1,0.3,0.9,0.19);
//        std::cout << " " << DaLiSeDodirujuIzvana(k3,k1);
//        Kugla k4(1,0.3,0.9,0.2001);
//        std::cout << " " << DaLiSeDodirujuIzvana(k4,k1);
//        Kugla k5(1,0.3,0.9,0.2);
//        std::cout << " " << DaLiSeDodirujuIzvana(k5,k1);
//        Kugla k6(1,0.3,0.3,0.3);
//        std::cout << " " << DaLiSeDodirujuIzvana(k6,k1);
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
//       std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
////    AT14 - Test funkcije DaLiSeDodirujuIznutra
//
//    try{
//        Kugla k1(1,0.3,0.4,0.3), k2(1,0.3,0.9,0.2);
//        std::cout << std::boolalpha << DaLiSeDodirujuIznutra(k1,k2);
//        Kugla k3(1,0.3,0.9,0.19);
//        std::cout << " " << DaLiSeDodirujuIznutra(k3,k1);
//        Kugla k4(1,0.3,0.9,0.2001);
//        std::cout << " " << DaLiSeDodirujuIznutra(k4,k1);
//        Kugla k5(1,0.3,0.3+1e14,0.4);
//        std::cout << " " << DaLiSeDodirujuIznutra(k5,k1);
//        Kugla k6(1,0.3,0.3,0.3);
//        std::cout << " " << DaLiSeDodirujuIznutra(k6,k1);
//        Kugla k7(1,0.3,0.4,0.3);
//        std::cout << " " << DaLiSeDodirujuIznutra(k7,k1);
//
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
//           std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
////    AT15 - Test funkcije DaLiSePreklapaju
//
//    try{
//        Kugla k1(1,0.3,0.4,0.3), k2(1,0.3,0.9,0.2);
//        std::cout << std::boolalpha << DaLiSePreklapaju(k1,k2);
//        Kugla k3(1,0.3,0.9,0.19);
//        std::cout << " " << DaLiSePreklapaju(k3,k1);
//        Kugla k4(1,0.3,0.9,0.2001);
//        std::cout << " " << DaLiSePreklapaju(k4,k1);
//        Kugla k5(1,0.3,0.3+1e-14,0.4);
//        std::cout << " " << DaLiSePreklapaju(k5,k1);
//        Kugla k6(1,0.3,0.3,0.3);
//        std::cout << " " << DaLiSePreklapaju(k6,k1);
//        Kugla k7(1,0.3,0.4,0.3);
//        std::cout << " " << DaLiSePreklapaju(k7,k1);
//
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
//           std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT16 - Test funkcije DaLiSeSijeku
//
//    try{
//        Kugla k1(1,0.3,0.4,0.3), k2(1,0.3,0.9,0.2);//dodiruju se izvana
//        std::cout << std::boolalpha << DaLiSeSijeku(k1,k2);
//        Kugla k3(1,0.3,0.9,0.19);//ne dodiriju se
//        std::cout << " " << DaLiSeSijeku(k3,k1);
//        Kugla k4(1,0.3,0.9,0.2001);//sijeku se
//        std::cout << " " << DaLiSeSijeku(k4,k1);
//        Kugla k5(1,0.3,0.3,0.4);//dodirju se iznutra
//        std::cout << " " << DaLiSeSijeku(k5,k1);
//        Kugla k6(1,0.3,0.3,0.3);//ove se sijeku
//        std::cout << " " << DaLiSeSijeku(k6,k1);
//        Kugla k7(1,0.3,0.3,0.2);//ova se nalazi unutar
//        std::cout << " " << DaLiSeSijeku(k7,k1);
//        Kugla k8(1,0.3,0.4,0.3);//identicna
//        std::cout << " " << DaLiSeSijeku(k8,k1);
//
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
//               std::cout << "\n\n|----------|\n| Autotest |\n|----------|\n\n";
//
//
//    //AT17 - Test metode DaLiSadrzi
//
//    try{
//        Kugla k1(1,0.3,0.4,0.3), k2(1,0.3,0.9,0.2);
//        std::cout << std::boolalpha << k1.DaLiSadrzi(k2);
//        Kugla k3(1,0.3,0.9,0.19);
//        std::cout << " " << k1.DaLiSadrzi(k3);
//        Kugla k4(1,0.3,0.9,0.2001);
//        std::cout << " " << k1.DaLiSadrzi(k4);
//        Kugla k5(1,0.3,0.3,0.4);
//        std::cout << " " << k1.DaLiSadrzi(k5);
//        Kugla k6(1,0.3,0.4,0.2);
//        std::cout << " " << k1.DaLiSadrzi(k6);
//        Kugla k7(1,0.3,0.4,0.3);
//        std::cout << " " << k1.DaLiSadrzi(k7);
//
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
////    AT18 - Provjera da li su prijateljske funkcije definisane van klase
////    ako se ne kompajlira znaci da su prijateljske funkcije definirane unutar klase
////    što je naglašeno da se ne radi, koga vise interesuje zasto se ovo desava neka
////    istrazi argument-dependent lookup(ADL)
//
//    try{
//        std::cout << std::boolalpha << DaLiSePreklapaju({1,2,3,4}, {1,2,3,4})
//        << " " << DaLiSeSijeku({1,2,3,4}, {1,2,3,4}) << " " << DaLiSeDodirujuIznutra({1,2,3,4}, {1,2,3,4})
//        << " " << DaLiSuPodudarne({1,2,3,4}, {1,2,3,4}) << " " << DaLiSuIdenticne({1,2,3,4}, {1,2,3,4})
//        << " " << DaLiSeDodirujuIzvana({1,2,3,4}, {1,2,3,4}) << DaLiSuKoncentricne({1,2,3,4}, {1,2,3,4});
//    }
//    catch(...){
//        std::cout << "IZUZETAK";
//    }
//
////    dodati jos testove maina jedan obicni i 4 testa u kojima se provjerava da li su korištene funkcije iz alghoritm i testirati rastojanje centara
////    test degenracije u jednu tacku
////
////    AT19 Test degeneracije u tačku
//    try{
//        Kugla k1(8,8,8,0);
//        Kugla k2(8,8,8,0);
//        Kugla k3(8,8,9, 1);
//        Kugla k4(8,11,9, 1+1e-14);
//        std::cout << std::boolalpha << DaLiSeSijeku(k1,k2) << " " << DaLiSePreklapaju(k1,k2)
//                  << " " << DaLiSeDodirujuIzvana(k1,k2) << " " << DaLiSeDodirujuIznutra(k1,k2)
//                  << " " << DaLiSeDodirujuIzvana(k2,k3) << " " << DaLiSuIdenticne(k1,k2)
//                  << " " << RastojanjeCentara(k1,k2) << " " << DaLiSuKoncentricne(k1,k2)
//                  << " " << k1.DaLiSadrzi(k1) << " " << DaLiSuKoncentricne(k1,k2)
//                  << " " << DaLiSeDodirujuIzvana(k3, k4) << " " << k4.DaLiSadrzi(k3)
//                  << " " << DaLiSuPodudarne(k1,k2)
//                  << "\nEND";
//
//    }
//    catch(...){
//        std::cout << "NOT OK";
//    }




    //main, ovdje jos treba smislit neke glupe testove

   // std::cout << std::boolalpha << DaLiSeSijeku(Kugla({0,0,0},4),Kugla({1,2,3},4));




    int n;
    std::cout <<"Unesite broj kugla: ";
while(!(std::cin >> n) || n <= 0){        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
    }
    try
    {
        std::vector<std::shared_ptr<Kugla>> v;
        double x, y, z, r;
        for (int i(0); i < n; ++i)
            try
            {
                std::cout << "Unesite centar " << i+1 << ". kugle: ";
                if(!(std::cin >> x >> y >> z)){
                    std::cout << "Neispravan centar\n";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    i--;
                    continue;
                }
                std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
                if(!(std::cin >> r) || r < 0){
                    std::cout << "Ilegalan poluprecnik\n";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    i--;
                    continue;
                }
                v.emplace_back(new Kugla(x, y, z, r));
            }
            catch (const std::exception &e) { std::cout << e.what() << '\n'; --i; }
            catch (...) {}
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        while(!(std::cin >> x >> y >> z)){
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        std::transform(v.begin(), v.end(), v.begin(), [=](const std::shared_ptr<Kugla> &a) { a->Transliraj(x, y, z); return a; });
        std::sort(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &a, const std::shared_ptr<Kugla> &b) { return a->DajZapreminu() < b->DajZapreminu(); });
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
        std::for_each(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &a) { std::cout << '\n'; a->Ispisi(); });
        std::cout << "\nKugla sa najvecom povrsinom je: ";
        (*std::max_element(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &a, const std::shared_ptr<Kugla> &b) { return a->DajPovrsinu() < b->DajPovrsinu(); }))->Ispisi();
        bool f(false);
        for_each(v.begin(), v.end(), [&](const std::shared_ptr<Kugla> &a) {
            std::for_each(v.begin(), v.end(), [&](const std::shared_ptr<Kugla> &b) {
                if (&b > &a && DaLiSeSijeku(*a, *b))
                {
                    std::cout << "\nPresjecaju se kugle: ";
                    a->Ispisi(); std::cout << '\n'; b->Ispisi();
                    if (!f) f = true;
                }
            });
        });
        if (!f) std::cout << "\nNe postoje kugle koje se presjecaju!";
    }
    catch (...) {}
    return 0;

}

/*
d
-1
1 2 d
1 2 0
4
0 -1 3
-1

*/