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


bool JednakiDouble(double x, double y) {
    return std::fabs(x-y) < 1e-10 * (std::fabs(x) + std::fabs(y));
    //return x==y;
}

bool JednakiCentri(const std::tuple<double, double, double> &c1, const std::tuple<double, double, double> &c2) {
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


class NepreklapajucaKugla{
    double x,y,z,r;
    static constexpr double pi = 4 * std::atan(1);
    NepreklapajucaKugla *pokNaPrethodnog;
    static NepreklapajucaKugla *pokNaPosljednjeg;
    static bool DaLiSePreklapaju(double x, double y, double z, double r, const NepreklapajucaKugla &k2) {
        double xy = UdaljenostDvijeTacke(std::make_tuple(x,y,z), k2.DajCentar());
        double yz =  r + k2.DajPoluprecnik();
        return  UdaljenostDvijeTacke(std::make_tuple(x,y,z), k2.DajCentar()) < r + k2.DajPoluprecnik()
                || JednakiDouble(UdaljenostDvijeTacke(std::make_tuple(x,y,z), k2.DajCentar()), r + k2.DajPoluprecnik());
    }
    bool ProvjeriPreklapanje(double x, double y, double z, double r) {
        NepreklapajucaKugla *trenutnaKugla = pokNaPosljednjeg;
        while (trenutnaKugla != nullptr){
            if(trenutnaKugla != this && DaLiSePreklapaju(x,y,z,r, *trenutnaKugla))
                throw std::logic_error("Nedozvoljeno preklapanje");
            trenutnaKugla = trenutnaKugla->pokNaPrethodnog;
        }
    }
    void UbaciULanac(){
        this->pokNaPrethodnog = pokNaPosljednjeg;
        pokNaPosljednjeg = this;
    }
public:
    explicit NepreklapajucaKugla(double r);
    ~NepreklapajucaKugla();
    NepreklapajucaKugla(double x, double y, double z, double r);
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla operator =(const NepreklapajucaKugla &k) = delete;
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r);
    double DajX() const { return x; }
    double DajY() const { return y;}
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); };
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4. * pi * r*r; }
    double DajZapreminu() const { return (4. * pi * r*r*r) / 3.; }
    NepreklapajucaKugla &PostaviX(double x) {
        ProvjeriPreklapanje(x, this->y, this->z, this->r);
        this->x = x; return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        ProvjeriPreklapanje(this->x, y, this->z, this->r);
        this->y = y; return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        ProvjeriPreklapanje(this->x, this->y, z, this->r);
        this ->z = z; return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}"; }//endl?
    void Transliraj(double delta_x, double delta_y, double delta_z){
        ProvjeriPreklapanje(x+delta_x, y+delta_y, z+delta_z, this->r);
        x+=delta_x; y+=delta_y; z+=delta_z;
    };
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);

};

NepreklapajucaKugla *NepreklapajucaKugla::pokNaPosljednjeg(nullptr);


NepreklapajucaKugla::~NepreklapajucaKugla() {
    if(this == pokNaPosljednjeg) {
        pokNaPosljednjeg = pokNaPosljednjeg->pokNaPrethodnog;
    }
    else{
        NepreklapajucaKugla *ispredKugle(nullptr);
        for(ispredKugle = pokNaPosljednjeg; ispredKugle->pokNaPrethodnog != this; ispredKugle= ispredKugle->pokNaPrethodnog){}
        ispredKugle->pokNaPrethodnog = this->pokNaPrethodnog;
    }
}

NepreklapajucaKugla::NepreklapajucaKugla(double r = 0) {
    if(r <0) throw std::domain_error("Ilegalan poluprecnik");
    ProvjeriPreklapanje(0,0,0,r);
    this->r = r;
    this->x = 0; this->y = 0; this->z = 0;
    UbaciULanac();


}

NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r = 0) {
    if(r <0) throw std::domain_error("Ilegalan poluprecnik");
    ProvjeriPreklapanje(x,y,z,r);
    this->r = r;
    this->x = x; this->y = y; this->z = z;
    UbaciULanac();

}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
    if(r <0) throw std::domain_error("Ilegalan poluprecnik");
    ProvjeriPreklapanje(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar),r);
    this->r = r;
    this->x = std::get<0>(centar); this->y = std::get<1>(centar);
    this->z = std::get<2>(centar);
    UbaciULanac();

}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(double x, double y, double z) {
    ProvjeriPreklapanje(x,y,z,this->r);
    this->x = x; this->y = y; this->z = z;
    return *this;
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviPoluprecnik(double r) {
    if(r <0) throw std::domain_error("Ilegalan poluprecnik");
    ProvjeriPreklapanje(this->x, this->y, this->z, r);
    this->r = r;
    return *this;
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar) {
    ProvjeriPreklapanje(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), this->r);
    PostaviCentar(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar));

}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return UdaljenostDvijeTacke(k1.DajCentar(), k2.DajCentar());
}

bool DaLiSePreklapaju1(double x, double y, double z, double r, const NepreklapajucaKugla &k2) {
    double f(UdaljenostDvijeTacke(std::make_tuple(x, y, z), k2.DajCentar()));
    double h(r + k2.DajPoluprecnik());
    double xy = UdaljenostDvijeTacke(std::make_tuple(x, y, z), k2.DajCentar()) < r + k2.DajPoluprecnik();
    double yz = JednakiDouble(UdaljenostDvijeTacke(std::make_tuple(x, y, z), k2.DajCentar()), r + k2.DajPoluprecnik());
    return UdaljenostDvijeTacke(std::make_tuple(x, y, z), k2.DajCentar()) < r + k2.DajPoluprecnik()
           || JednakiDouble(UdaljenostDvijeTacke(std::make_tuple(x, y, z), k2.DajCentar()), r + k2.DajPoluprecnik());
}

int main() {
    //Svi testovi se nasljeđuju iz prvog zadatka koji ostaju, dodati još testove kad se desi degeneracija u tačku i prvi

//     //AT1 (skriveni) - test konstruktora sa jednim parametrom
//     try {
//         std::cout << std::boolalpha << std::is_convertible<double, NepreklapajucaKugla>::value << std::endl;
//         NepreklapajucaKugla k;
//         k.Ispisi();
//         std::cout << std::endl;
//         try {
//             NepreklapajucaKugla k1(5);
//         }
//         catch(std::logic_error &ex){
//             std::cout << "OK " << ex.what() << std::endl;
//         }
//         NepreklapajucaKugla k2(-1);

//     }
//     catch(std::domain_error &ex){
//         std::cout << "OK " << ex.what();
//     }
//     catch(...){
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 2\n-----------\n";

//     //AT2 (skriveni) - Test konstruktora sa 4 parametra
//     try{
//         NepreklapajucaKugla k1(5,5,5,5);
//         k1.Ispisi();
//         std::cout << std::endl;
//         NepreklapajucaKugla k2 = {-5,-5,-5,2};
//         k2.Ispisi();
//         std::cout << std::endl;
//         NepreklapajucaKugla k3(-1,1,-1,-1);

//     }
//     catch(std::domain_error ex){
//         std::cout << "OK " << ex.what();
//     }
//     catch(...){
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 3\n-----------\n";

//     //AT3 (skriveni) - Test konstruktra sa tuple-om

//     try{
//         std::cout << std::boolalpha << pretvorba_tipa_vise_argumenata<NepreklapajucaKugla, std::tuple<double, double, double>, double>::value << std::endl;
//         NepreklapajucaKugla k1(std::make_tuple(5,5,5),5);
//         k1.Ispisi();
//         std::cout << std::endl;
//         NepreklapajucaKugla k2 = {-5,-5,-5,2};
//         k2.Ispisi();
//         std::cout << std::endl;
//         NepreklapajucaKugla k3(-1,1,-1,-1);

//     }
//     catch(std::domain_error ex){
//         std::cout << "OK " << ex.what();
//     }
//     catch(...){
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 4\n-----------\n";

//     //AT4 (skriveni) - Test metoda DajX, DajY, DajZ i DajCentar

//     try{
//         const NepreklapajucaKugla k(std::make_tuple(1,2,3), 2.3);
//         std:: cout << std::fixed << std::setprecision(3);
//         std::cout << "Centar: " << k.DajX() << " " << k.DajY() << " "<< k.DajZ();
//         std::cout << "\nPoluprecnik: " << k.DajPoluprecnik();
//         NepreklapajucaKugla k1(4,3,10,1);
//         std::tuple<double, double, double> centar(k1.DajCentar());
//         std::cout << "\nNovi centar: " <<std::get<0>(centar) << " " << std::get<1>(centar) << " " << std::get<2>(centar);

//     }
//     catch(...) {
//         std::cout << "IZUZETAK";
//     }

//     std::cout << "\n-----------\nAutotest 5\n-----------\n";


//     //AT5 (skriveni) - Test metoda DajPovrsinu,  DajZapreminu i Ispisi i RastojanjeCentara

//     try{
//         const NepreklapajucaKugla k(std::make_tuple(8,16,32), 30.3);
//         const NepreklapajucaKugla k1(std::make_tuple(-80,-100,30.3), 18.01);
//         std::cout << std::fixed << std::setprecision(5);
//         std::cout << "Povrsina kugle k: " << k.DajPovrsinu()
//                   << "\nZapremina kugle k : " << k.DajZapreminu();
//         std::cout << std::endl;
//         std::cout << "Povrsina kugle k1: " << k.DajPovrsinu()
//                   << "\nZapremina kugle k1: " << k.DajZapreminu();
//         std::cout << "\nRastojanje centara kugle k i k1: "
//                   << RastojanjeCentara(k,k1);
//         std::cout << std::endl << std::defaultfloat;
//         k.Ispisi();
//         std::cout << "\nEND";

//     }
//     catch(...) {
//         std::cout << "IZUZETAK";
//     }

//     std::cout << "\n-----------\nAutotest 6\n-----------\n";

//     //AT6 (skriveni)  - Test medota PostaviX, PostaviY, PostaviZ


//     try{
//         NepreklapajucaKugla k(std::make_tuple(8,16,32), 30.3);
//         k.PostaviX(-1).PostaviY(-2).PostaviZ(-3);
//         k.Ispisi();
//     }
//     catch(...) {
//         std::cout << "IZUZETAK";
//     }


//     std::cout << "\n-----------\nAutotest 7\n-----------\n";


//     //AT7 (skriveni) - Test metode postavi poluprecnik

//     try{
//         NepreklapajucaKugla k(std::make_tuple(8,16,32), 30.3);
//         k.PostaviPoluprecnik(20.289);
//         k.Ispisi();
//         std::cout << std::endl;
//         k.PostaviPoluprecnik(-0.0000001);

//     }
//     catch(std::domain_error ex){
//         std::cout << "OK " << ex.what();
//     }
//     catch(...) {
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 8\n-----------\n";

//     //AT8 (skriveni) - Test metoda PostaviCentar

//     try{
//         NepreklapajucaKugla k(20);
//         k.PostaviCentar(1.5,10,25);
//         k.Ispisi();
//         std::cout << std::endl;
//         k.PostaviCentar(std::make_tuple(25,10,1.5));
//         k.Ispisi();
//     }
//     catch(...){
//         std::cout << "IZUZETAK";
//     }

//     std::cout << "\n-----------\nAutotest 9\n-----------\n";

//     //AT9 (skriveni) - Test metode Transliraj

//     try{
//         NepreklapajucaKugla k(10,10,10,20);
//         k.Transliraj(20.25, 1,-18.31);
//         k.Transliraj(-20.25, -1,18.31);
//         k.Ispisi();
//     }
//     catch(...){
//         std::cout << "IZUZETAK";
//     }


//     std::cout << "\n-----------\nAutotest 10\n-----------\n";


// //    AT10 (neaktivni) Provjera da li su zabranjeni koperacijuci konstruktor i operator dodjele

//     try {
//         std::cout << std::boolalpha << std::is_constructible<NepreklapajucaKugla, NepreklapajucaKugla>::value
//                   << " " << std::is_assignable<NepreklapajucaKugla, NepreklapajucaKugla>::value;
//         std::cout << "\nEND";
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "OK1 " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK1";
//     }

//     std::cout << "\n-----------\nAutotest 11\n-----------\n";


// //    AT11 (skriveni) - Trivijalno testiranje preklapanja
//     try{
//         NepreklapajucaKugla k1(2, 3, 1, 5);
//         k1.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k2(10, 7, 8, 2);
//         k2.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k3(4, 6, 3, 7);
//         k3.Ispisi(); std::cout << std::endl;
//     }
//     catch(std::logic_error &ex){
//         std::cout << "OK " << ex.what();
//     }
//     catch(...){
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 12\n-----------\n";


//     //AT12 (skriveni) - Test dodirivanje dvije kugle
//     try{
//         NepreklapajucaKugla k1(2, 3, 1, 5);
//         k1.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k2(10, 7, 8, 2);
//         k2.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k3(2, 9.1, 1, 1);
//         k3.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k4(2, -3, 1, 1);
//         k4.Ispisi(); std::cout << std::endl;
//     }
//     catch(std::logic_error &ex){
//         std::cout << "OK " << ex.what();
//     }
//     catch(...){
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 13\n-----------\n";

//     //AT13 (skriveni) - Iskljucivanje kugle sa kraja
//     try{
//         NepreklapajucaKugla k1(2, 3, 1, 5);
//         k1.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k2(10, 7, 8, 2);
//         k2.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k3(2, 9.1, 1, 1);
//         k3.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla k4(2, -3.1, 1, 1);
//         k4.Ispisi(); std::cout << std::endl;
//         NepreklapajucaKugla *k5(new NepreklapajucaKugla(2, -4, 10, 2));
//         k5->Ispisi(); std::cout << std::endl;
//         delete k5;
//         NepreklapajucaKugla k6(2, -4, 10, 2);
//         k6.Ispisi(); std::cout << std::endl;
//     }
//     catch(std::logic_error &ex){
//         std::cout << "OK " << ex.what();
//     }
//     catch(...){
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 14\n-----------\n";

// //    AT14 (nekativni) - Iskljucivanje kugli iz sredine
//     try {
//         typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
//         std::vector<pokKugla> p;
//         for (int i = 1; i <= 10; i++) {
//             p.push_back(std::make_shared<NepreklapajucaKugla>(i * 3, i * 4, i * 2, 1));
//         }
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }

//         p.erase(p.begin() + 5);
//         p.erase(p.begin() + 5);
//         p.erase(p.begin() + 5);

//         try{NepreklapajucaKugla(16,21,11,2);}catch(std::logic_error ex){std::cout<<" OK1 " << ex.what() << std::endl;}
//         try{NepreklapajucaKugla(16,21,11,1);}catch(std::logic_error ex){std::cout<< " OK2 " << ex.what() << std::endl;}
//         try{NepreklapajucaKugla(16,21,11,0.73);}catch(std::logic_error ex){std::cout<< " NOT OK ";}
//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "OK " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 15\n-----------\n";


// //    AT15  (skriveni) Iskljucivanje kugle sa pocetka

//     try {
//         typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
//         std::vector<pokKugla> p;
//         for (int i = 1; i <= 10; i++) {
//             p.push_back(std::make_shared<NepreklapajucaKugla>(i*-2, i * -4, i *-1, 1.5));
//         }
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//         p.erase(p.begin());
//         p.erase(p.begin());

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//         try{NepreklapajucaKugla(-5,-8,-20,16.5);}catch(std::logic_error ex){std::cout<<" OK1 "<< ex.what() << std::endl;}
//         try{NepreklapajucaKugla(-5,-8,-20,16);}catch(std::logic_error ex){std::cout<< " OK2 "<< ex.what() << std::endl;}
//         try{NepreklapajucaKugla(-22,-20,11,20);}catch(std::logic_error ex){std::cout<< " OK3 "<< ex.what() << std::endl;}
//         try{NepreklapajucaKugla(-22,-40,-12,2*sqrt(2)-1.5);}catch(std::logic_error ex){std::cout<< " OK4 "<< ex.what() << std::endl;}
//         try{NepreklapajucaKugla(-22,-40,-12,2*sqrt(2)-1.6);}catch(std::logic_error ex){std::cout<< " NOT OK ";}

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "OK " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 16\n-----------\n";


// //    AT16 (skriveni)  Test metode PostaviPoluprecnik

//     try {
//         typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
//         std::vector<pokKugla> p;
//         int znak = 1;
//         for (int i = 1; i <= 10; i++) {
//             p.push_back(std::make_shared<NepreklapajucaKugla>(i*3, i * 4, i , 2));
//         }

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }

//         try{p[4]->PostaviPoluprecnik(sqrt(26)-(2 + 1e-14));}catch(std::logic_error ex){std::cout<<" OK1 "<< ex.what() << std::endl;}
//         try{p[4]->PostaviPoluprecnik(sqrt(26)-2.1);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         p.erase(p.begin() + 3);
//         try{p[0]->PostaviPoluprecnik(sqrt(26)-(2 + 1e-14));}catch(std::logic_error ex){std::cout<<" OK2 "<< ex.what() << std::endl;}
//         try{p[0]->PostaviPoluprecnik(sqrt(26)-2.1);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[8]->PostaviPoluprecnik(sqrt(26)-2);}catch(std::logic_error ex){std::cout<<" OK3 "<< ex.what() << std::endl;}
//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "OK " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 17\n-----------\n";

// //    AT17 (skriveni)  Test metoda postavi centar

//     try {
//         typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
//         std::vector<pokKugla> p;
//         int znak = 1;
//         for (int i = 1; i <= 10; i++) {
//             p.push_back(std::make_shared<NepreklapajucaKugla>(i*10, i * 15, i*20 , i));
//         }

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }

//         try{p[0]->PostaviCentar(20,30,36.9);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[0]->PostaviCentar(20,30,37 - 1e-14);}catch(std::logic_error ex){std::cout<<" OK1 "<< ex.what() << std::endl;}
//         p.erase(p.begin() + 5);
//         try{p[2]->PostaviCentar(std::make_tuple(40,60,70));}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[2]->PostaviCentar(std::make_tuple(40,60,73));}catch(std::logic_error ex){std::cout<<" OK2 "<< ex.what() << std::endl;}
//         try{p[8]->PostaviCentar(std::make_tuple(80,120,60));}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[8]->PostaviCentar(std::make_tuple(40,60,73));}catch(std::logic_error ex){std::cout<<" OK3 "<< ex.what() << std::endl;}
//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "OK " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 18\n-----------\n";

// //    AT18 (skriveni) Test metode Transliraj

//     try {
//         typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
//         std::vector<pokKugla> p;
//         int znak = 1;
//         for (int i = 1; i <= 10; i++) {
//             p.push_back(std::make_shared<NepreklapajucaKugla>(i*10, i * 15, i*20 , i));
//         }

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }

//         try{p[0]->Transliraj(10,15,15);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[0]->Transliraj(0,0,3);}catch(std::logic_error ex){std::cout<<" OK1 "<< ex.what() << std::endl;}
//         try{p[5]->Transliraj(10,15,7);}catch(std::logic_error ex){std::cout<<" OK2 "<< ex.what() << std::endl;}
//         try{p[5]->Transliraj(10,15,6);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[9]->Transliraj(-10,-15,-1.1);}catch(std::logic_error ex){std::cout<<" OK3 "<< ex.what() << std::endl;}
//         try{p[9]->Transliraj(-10,-15,-0.9);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         std::cout << "\nEND";

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "NOT OK " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK";
//     }

//     std::cout << "\n-----------\nAutotest 19\n-----------\n";

// //    AT19 (nekativni)  Provjera metoda PostaviX, PostaviY, PostaviZ

//     try {
//         typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
//         std::vector<pokKugla> p;
//         int znak = 1;
//         for (int i = 1; i <= 10; i++) {
//             p.push_back(std::make_shared<NepreklapajucaKugla>(i*10, i * 15, i*20 , i));
//         }

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }

//         try{p[0]->PostaviX(20).PostaviY(30).PostaviZ(36.9);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[0]->PostaviZ(37);}catch(std::logic_error ex){std::cout<<" OK1 "<< ex.what() << std::endl;}
//         p.erase(p.begin()+6);
//         try{p[5]->PostaviY(80).PostaviZ(100);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[5]->PostaviX(59.7);}catch(std::logic_error ex){std::cout<<" OK2 "<< ex.what() << std::endl;}
//         try{p[8]->PostaviX(95).PostaviZ(195);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[8]->PostaviY(145);}catch(std::logic_error ex){std::cout<<" OK3 "<< ex.what() << std::endl;}
//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "OK " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK1";
//     }

//     std::cout << "\n-----------\nAutotest 20\n-----------\n";

// //    AT20 (nekativni) - Preklapanje kugle sa samom sobom
// //    pomjeramo kuglu tako da se ona poklapa sa samim sobom
// //    u metodama setterima, pri promjeni parametara kugla se ne bi trebala provjeravati sa samim sobom

//         try {
//         typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
//         std::vector<pokKugla> p;
//         int znak = 1;
//         for (int i = 1; i <= 10; i++) {
//             p.push_back(std::make_shared<NepreklapajucaKugla>(i*20, i * 15, i*10 , i));
//         }

//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }

//         try{p[0]->PostaviX(20).PostaviY(15).PostaviZ(10);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[0]->Transliraj(1,-1,0);}catch(std::logic_error ex){std::cout<<"NOT OK ";}
//         p.erase(p.begin()+6);
//         try{p[4]->PostaviCentar(100,75,50);}catch(std::logic_error ex){std::cout<<" NOT OK ";}
//         try{p[4]->PostaviCentar(std::make_tuple(100,75,50));}catch(std::logic_error ex){std::cout<<"NOT OK ";}
//         try{p[5]->PostaviCentar(100,75,50);}catch(std::logic_error ex){std::cout<<" OK1 "<< ex.what() << std::endl;}
//         try{p[5]->PostaviCentar(std::make_tuple(100,75,50));}catch(std::logic_error ex){std::cout<<" OK2 "<< ex.what() << std::endl;}
//         std::cout << std::endl;
//         for(pokKugla &k : p) {
//             k->Ispisi(); std::cout << std::endl;
//         }
//     }
//     catch (std::logic_error &ex) {
//         std::cout << "OK1 " << ex.what();
//     }
//     catch (...) {
//         std::cout << "NOT OK1";
//     }






    //main

    typedef std::shared_ptr<NepreklapajucaKugla> pokKugla;
    std::vector<pokKugla> p;
    int n;
    std::cout << "Unesite broj kugli: ";
    while(!(std::cin >> n) || n <= 0){
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    for(int i = 0; i < n; i++){
        double x, y, z, r;
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        while(!(std::cin >> x >> y >> z)){
            std::cout << "Neispravan centar, unesite ponovo:\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        std::cout << "Unesite poluprecnik: ";
        while(!(std::cin >> r) || r < 0){
            std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        try {p.push_back(std::make_shared<NepreklapajucaKugla>(x,y,z,r));}
        catch(std::logic_error &ex){std::cout << ex.what(); std::cout << std::endl; i--;}
    }

    std::sort(p.begin(), p.end(), [](pokKugla k1, pokKugla k2){
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });

    std::cout << "\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(p.begin(), p.end(), [](pokKugla k) {k->Ispisi(); std::cout << std::endl;});
}

