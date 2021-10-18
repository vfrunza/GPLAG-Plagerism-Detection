/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

const double PI(4*atan(1));
int brojac=0;

class NepreklapajucaKugla
{
    static NepreklapajucaKugla *posljednja_kugla;
    NepreklapajucaKugla *prethodna_kugla=nullptr;
    double x,y,z;
    double r;
    bool TestirajPoluprecnik(double r) { if(r<0) throw std::domain_error("Ilegalan poluprecnik"); return true; }
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
    {
        double d(RastojanjeCentara(k1, k2));
        double r1(k1.DajPoluprecnik());
        double r2(k2.DajPoluprecnik());
        if(d<r1+r2) return true;
        else return false;
    }
    bool ProdjiKrozListu()
    {
        for(auto pocetak=posljednja_kugla; pocetak->prethodna_kugla!=nullptr; pocetak->prethodna_kugla)
        {
            if(DaLiSePreklapaju(*pocetak, *this))
            {
                throw std::logic_error("Ilegalna kugla");
                return false;
            }
            else return true;
        }
    }
public:
    explicit NepreklapajucaKugla(double r=0)
    {
        if(TestirajPoluprecnik(r))
        {
            this->r=r; x=y=z=0;
            if(brojac==0)
            {
                prethodna_kugla=nullptr; posljednja_kugla=this;
            }
            else if(brojac!=0 && ProdjiKrozListu())
            {
                prethodna_kugla=posljednja_kugla; posljednja_kugla=this;
            }
            brojac++;
        }
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0)
    {
        if(TestirajPoluprecnik(r))
        {
            this->x=x; this->y=y; this->z=z; this->r=r;
            if(brojac==0)
            {
                prethodna_kugla=nullptr; posljednja_kugla=this;
            }
            else if(brojac!=0 && ProdjiKrozListu())
            {
                prethodna_kugla=posljednja_kugla; posljednja_kugla=this;
            }
            brojac++;
        }
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0)
    {
        if(TestirajPoluprecnik(r))
        {
            x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
            this->r=r;
            if(brojac==0)
            {
                prethodna_kugla=nullptr; posljednja_kugla=this;
            }
            else if(brojac!=0 && ProdjiKrozListu())
            {
                prethodna_kugla=posljednja_kugla; posljednja_kugla=this;
            }
            brojac++;
        }
    }
    ~NepreklapajucaKugla();
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
    NepreklapajucaKugla &PostaviX(double x) { this->x=x; return *this; }
    NepreklapajucaKugla &PostaviY(double y) { this->y=y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { this->z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) { this->x=x; this->y=y; this->z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) { if(TestirajPoluprecnik(r)) { this->r=r; return *this; } }
    void Ispisi() const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const
    {
        if(RastojanjeCentara(*this, k)+k.DajPoluprecnik()<r) return true;
        else return false;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla::~NepreklapajucaKugla()
{
    if(posljednja_kugla==this && this->prethodna_kugla!=nullptr) posljednja_kugla=this->prethodna_kugla;
    else if(posljednja_kugla==this && this->prethodna_kugla==nullptr) posljednja_kugla=nullptr;
    /*else if(posljednja_kugla!=this && this->prethodna_kugla==nullptr)
    {
        NepreklapajucaKugla* prije_prethodnog=nullptr;
        for(auto pocetak=posljednja_kugla; pocetak!=nullptr; pocetak->prethodna_kugla)
        {
            auto pom(pocetak);
            if(pom->prethodna_kugla==this)
            {
                prije_prethodnog=pom;
                break;
            }
        }
        prije_prethodnog->prethodna_kugla=nullptr;
    }*/
    else if(posljednja_kugla!=this && this->prethodna_kugla!=nullptr)
    {
        NepreklapajucaKugla* prije_prethodnog=nullptr;
        for(auto pocetak=posljednja_kugla; pocetak!=nullptr; pocetak->prethodna_kugla)
        {
            auto pom(pocetak);
            if(pom->prethodna_kugla==this)
            {
                prije_prethodnog=pom;
                break;
            }
        }
        prije_prethodnog->prethodna_kugla=this->prethodna_kugla;
        this->prethodna_kugla=nullptr;
    }
}

NepreklapajucaKugla* NepreklapajucaKugla::posljednja_kugla(nullptr);

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return(std::sqrt(((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()))+((k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY()))+((k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()))));
}

int main()
{
    try
    {
        int n;
        std::cout << "Unesite broj kugli: ";
        std::cin >> n;
        std::vector<std::shared_ptr<NepreklapajucaKugla>> vektorKugli(n);
        for(int i=0; i<n; i++)
        {
            double x,y,z,r;
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            std::cin >> x >> y >> z;
            std::cout << "Unesite poluprecnik: "; std::cin >> r;
            try
            {
                vektorKugli[i]=std::make_shared<NepreklapajucaKugla>(NepreklapajucaKugla(x,y,z,r));
            }
            catch(std::domain_error e)
            {
                std::cout << e.what();
                std::cout << "Neispravno uneseni podaci!";
                i--;
            }
            catch(std::logic_error e)
            {
                std::cout << e.what();
                std::cout << "Neispravno uneseni podaci!";
                i--;
            }
        }
        std::sort(vektorKugli.begin(), vektorKugli.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2)
                                                            {
                                                                if((*k1).DajPovrsinu()<(*k2).DajPovrsinu()) return true;
                                                                else return false;
                                                            });
        std::for_each(vektorKugli.begin(), vektorKugli.end(), [](std::shared_ptr<NepreklapajucaKugla> k){ (*k).Ispisi(); });
    }
    catch(std::domain_error e)
    {
        std::cout << e.what();
    }
    catch(std::logic_error e)
    {
        std::cout << e.what();
    }
    return 0;
}

