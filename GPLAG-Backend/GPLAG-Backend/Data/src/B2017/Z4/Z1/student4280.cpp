/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory>
#include <tuple>
#include <utility>

const double PI (atan(1)*4);
const double EPS(pow(10,-10));

typedef std::tuple <double, double, double> Tacka;

class Kugla
{

    double x,y,z,r;
    bool Jedn(double x, double y) {
        return fabs(x-y)<EPS*(fabs(x)+fabs(y));
    }
public:


    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
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

Kugla::Kugla(double r) {

    if(r<0) throw std::domain_error("Ilegalan poluprecnik");

    x=0;
    y=0;
    z=0;
    r=r;
}

Kugla::Kugla(double x, double y, double z, double r) {

    if(r<0) throw std::domain_error("Ilegalan poluprecnik");

    this->x=x;
    this->y=y;
    this->z=z;
    this->r=r;
}

Kugla::Kugla(const std::tuple<double, double, double> &centar, double r) {

    if(r<0) throw std::domain_error("Ilegalan poluprecnik");

    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    this->r=r;
}

double Kugla::DajX() const {

    return x;
}

double Kugla::DajY() const {

    return y;
}

double Kugla::DajZ() const {

    return z;

}


std::tuple<double, double, double> Kugla::DajCentar() const {

    return  std::make_tuple(x,y,z);
}

double Kugla::DajPoluprecnik() const {

    return r;
}


double Kugla::DajPovrsinu() const {

    double r=DajPoluprecnik();
    return 4*r*r*PI;
}

double Kugla::DajZapreminu() const {

    double r=DajPoluprecnik();
    return (4/3)*r*r*r*PI;

}

Kugla& Kugla::PostaviX(double x) {

    this->x=x;
    return *this;
}

Kugla& Kugla::PostaviY(double y) {

    this->y=y;
    return *this;
}

Kugla& Kugla::PostaviZ(double z) {

    this->z=z;
    return *this;
}

Kugla& Kugla::PostaviCentar(double x, double y, double z) {

    this->x=x;
    this->y=y;
    this->z=z;

    return *this;
}

Kugla& Kugla::PostaviCentar(const std::tuple<double, double, double> &centar) {

    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);

    return *this;
}

Kugla& Kugla::PostaviPoluprecnik(double r) {

    if(r<0) throw std::domain_error("Neispravan poluprecnik");

    r=r;
    return *this;
}


void Kugla::Ispisi() const {

    std::cout <<"{("<< x << "," << y << "," << z << ")," << r <<"}";
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z) {

    x=x+delta_x;
    y=y+delta_y;
    z=z+delta_z;
}


bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if((fabs(k1.x-k2.x)<EPS*fabs(k1.x)+fabs(k2.x)) && (fabs(k1.y-k2.y)<EPS*fabs(k1.y)+fabs(k2.y)) && (fabs(k1.z-k2.z)<EPS*fabs(k1.z)+fabs(k2.z)))
        return true;
    else return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.r-k2.r)<EPS*fabs(k1.r)+fabs(k2.r))
        return true;
    else return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if((fabs(k1.x-k2.x)<EPS*fabs(k1.x)+fabs(k2.x)) &&(fabs(k1.y-k2.y)<EPS*fabs(k1.y)+fabs(k2.y)) && (fabs(k1.z-k2.z)<EPS*fabs(k1.z)+fabs(k2.z)))
        return true;
    else return false;
}

bool Jedn(double x, double y) {
    return fabs(x-y)<EPS*(fabs(x)+fabs(y));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    if(Jedn(k1.r+k2.r, RastojanjeCentara(k1,k2)))
        return true;
    else return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    if(Jedn(fabs(k1.r-k2.r), RastojanjeCentara(k1,k2)))
        return true;
    else return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(DaLiSeSijeku(k1,k2)) return true;
    if(RastojanjeCentara(k1,k2)<k1.r+k2.r)
        return true;
    else return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if(k1.r+k2.r>RastojanjeCentara(k1,k2) && fabs(k1.r-k2.r)<RastojanjeCentara(k1,k2))
        return true;
    else return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    if(RastojanjeCentara(*this,k) < (r-k.r))
        return true;
    else return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {

    return sqrt(pow(k1.x-k2.x,2) + pow(k1.y-k2.y,2)+ pow(k1.z-k2.z,2));
}



int main ()
{

    int n=0;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    while (!std::cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<Kugla>> vekt(n);
    double x,y,z;


    for(int i=0; i<n; i++) {
        try {
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin >> x;
            std::cin >> y;
            std::cin >> z;

            if(!std::cin) {
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }

            double poluprecnik;
            std::cout << "Unesite poluprecnik " << i+1 <<". kugle: ";
            std::cin >> poluprecnik;

            if(!std::cin) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }

            vekt.at(i)=std::make_shared<Kugla>(x,y,z,poluprecnik);
        }

        catch(std::domain_error w) {
            std::cout <<w.what() << std::endl;
            i--;
        }
    }

    double delta_x, delta_y, delta_z;

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin >> delta_x;
    std::cin >> delta_y;
    std::cin >> delta_z;

    std::transform(vekt.begin(), vekt.end(), vekt.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> x)  {
        x->Transliraj(delta_x,delta_y,delta_z);
        return x;
    });

    std::sort(vekt.begin(), vekt.end(), [] (std::shared_ptr<Kugla> x, std::shared_ptr<Kugla> y) {
        return x->DajZapreminu() < y->DajZapreminu();
    });

    std::cout << "Kugle nakon obavljene transformacije imaju sljedece vrijednosti: \n";
    std::for_each(vekt.begin(), vekt.end(), [] (std::shared_ptr<Kugla> x) {
        x->Ispisi();
        std::cout << std::endl;
    });
    

    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*std::max_element(vekt.begin(), vekt.end(), [] (std::shared_ptr<Kugla> x, std::shared_ptr<Kugla> y) {
        return x->DajPovrsinu() < y->DajPovrsinu();
    })) -> Ispisi();;;
    std::cout << std::endl;

/*


   std::vector<std::shared_ptr<Kugla>> &k1,&k2;

   k1=std::make_shared<Kugla>(x,y,z,poluprecnik);
   k2=std::make_shared<Kugla>(x,y,z,poluprecnik);
   
    bool SijekuSe=true; //foreach!!
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++) {
            if(DaLiSeSijeku(k1,k2))
            std::cout << "\nPresjecaju se kugle: ";
                k1.Ispisi();
                k2.Ispisi();
        }
    }
    if(SijekuSe=false) {
        std::cout << "\nNe postoje kugle koje se presjecaju!";
    }*/
    

    return 0;
}
    
    
    
    
