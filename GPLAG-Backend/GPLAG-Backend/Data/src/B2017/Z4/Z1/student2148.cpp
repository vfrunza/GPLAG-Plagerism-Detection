/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

const double PI(4*atan(1));

class Kugla
{
    double x,y,z;
    double r;
    bool TestirajPoluprecnik(double r) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); return true; }
public:
    explicit Kugla(double r=0) { if(TestirajPoluprecnik(r)) { this->r=r; x=y=z=0; } }
    Kugla(double x, double y, double z, double r=0) { if(TestirajPoluprecnik(r)) { this->x=x; this->y=y; this->z=z; this->r=r; } }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0)
    {
        if(TestirajPoluprecnik(r))
        {
            x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
            this->r=r;
        }
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const
    {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*PI; }
    double DajZapreminu() const { return (4./3)*PI*r*r*r; }
    Kugla &PostaviX(double x) { this->x=x; return *this; }
    Kugla &PostaviY(double y) { this->y=y; return *this; }
    Kugla &PostaviZ(double z) { this->z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { this->x=x; this->y=y; this->z=z; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this;
    }
    Kugla &PostaviPoluprecnik(double r) { if(TestirajPoluprecnik(r)) { this->r=r; return *this; } }
    void Ispisi() const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const
    {
        if(RastojanjeCentara(*this, k)+k.DajPoluprecnik()<r) return true;
        else return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ() && k1.DajPoluprecnik()==k2.DajPoluprecnik()) return true;
    else return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(k1.DajPoluprecnik()==k2.DajPoluprecnik()) return true;
    else return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ()) return true;
    else return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double d(RastojanjeCentara(k1, k2));
    double r1(k1.DajPoluprecnik());
    double r2(k2.DajPoluprecnik());
    std::tuple<double, double, double> centar1=k1.DajCentar();
    std::tuple<double, double, double> centar2=k2.DajCentar();
    if(d==r1+r2 && d>r1 && d>r2 && centar1!=centar2 && d-r1==r2) return true;
    else return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double d(RastojanjeCentara(k1, k2));
    double r1(k1.DajPoluprecnik());
    double r2(k2.DajPoluprecnik());
    std::tuple<double, double, double> centar1=k1.DajCentar();
    std::tuple<double, double, double> centar2=k2.DajCentar();
    if(d<r1+r2 && (r1<=r2+d || r2<=r1+d) && centar1!=centar2) return true;
    else return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    double d(RastojanjeCentara(k1, k2));
    double r1(k1.DajPoluprecnik());
    double r2(k2.DajPoluprecnik());
    if(d<r1+r2) return true;
    else return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeDodirujuIznutra(k1, k2)) return true;
    else return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return(std::sqrt(((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()))+((k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY()))+((k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()))));
}

int main()
{
    try
    {
        int n;
        std::cout << "Unesite broj kugla: ";
        std::cin >> n;
        std::vector<std::shared_ptr<Kugla>> vektorKugli(n);
        for(int i=0; i<n; i++)
        {
            double x,y,z,r;
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin >> x >> y >> z;
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: "; std::cin >> r;
            if(std::cin && x>=0 && y>=0 && z>=0 && r>=0) vektorKugli[i]=std::make_shared<Kugla>(Kugla(x,y,z,r));
            else
            {
                std::cout << "Neispravno uneseni podaci!";
                i--;
            }
        }
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double delta_x, delta_y, delta_z;
        std::cin >> delta_x >> delta_y >> delta_z;
        std::transform(vektorKugli.begin(), vektorKugli.end(), vektorKugli.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> k)
                                                                {
                                                                    (*k).Transliraj(delta_x, delta_y, delta_z);
                                                                    return k;
                                                                });
        std::sort(vektorKugli.begin(), vektorKugli.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2)
                                                            {
                                                                if((*k1).DajZapreminu()<(*k2).DajZapreminu()) return true;
                                                                else return false;
                                                            });
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:" << std::endl;
        std::for_each(vektorKugli.begin(), vektorKugli.end(), [](std::shared_ptr<Kugla> k){ (*k).Ispisi(); });
        auto it_na_max=std::max_element(vektorKugli.begin(), vektorKugli.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2)
                                                            {
                                                                if((*k1).DajPovrsinu()<(*k2).DajPovrsinu()) return true;
                                                                else return false;
                                                            });
        std::cout << "Kugla sa najvecom povrsinom je: ";
        (*(it_na_max))->Ispisi();
        std::cout << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << e.what();
    }
    return 0;
}

