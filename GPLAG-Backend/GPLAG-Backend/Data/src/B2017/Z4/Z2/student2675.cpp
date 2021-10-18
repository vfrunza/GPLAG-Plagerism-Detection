/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream> 
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

class NepreklapajucaKugla
{
    double x,y,z,r; 
    static NepreklapajucaKugla* kraj_liste;
    NepreklapajucaKugla* prethodni=nullptr;
    static bool Jednaki(double x, double y);
    static bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    void AzurirajLanac();
    bool Preklapanje() const;

public:
    explicit NepreklapajucaKugla(double r);
    NepreklapajucaKugla (double x, double y, double z, double r);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r);
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla operator = (const NepreklapajucaKugla &k) = delete;
    ~NepreklapajucaKugla();
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla* NepreklapajucaKugla::kraj_liste = nullptr;

NepreklapajucaKugla::NepreklapajucaKugla(double r = 0) : x(0), y(0), z(0)
{   
    PostaviPoluprecnik(r);
    AzurirajLanac();
}
 
NepreklapajucaKugla::NepreklapajucaKugla (double x, double y, double z, double r) : x(x), y(y), z(z)
{
    PostaviPoluprecnik(r);
    AzurirajLanac();
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0)
{
    std::tie(x,y,z) = centar;
    PostaviPoluprecnik(r);
    AzurirajLanac();
}

NepreklapajucaKugla::~NepreklapajucaKugla()
{

    auto pok(kraj_liste);
    while (pok != nullptr) {
        if(this == kraj_liste) {
            kraj_liste = this->prethodni;
            break;
        }
        if(this == (pok->prethodni)) {
            if(this->prethodni == nullptr) {
                pok->prethodni = nullptr;
                break;
            } 
            pok->prethodni = prethodni; 
        }
        pok = pok->prethodni;
    }
}

void NepreklapajucaKugla::AzurirajLanac()  
{
    bool preklapanje(Preklapanje());
    if(!preklapanje) {
        prethodni = kraj_liste;
        kraj_liste = this;
    } else throw std::logic_error ("Nedozvoljeno preklapanje");
}

bool NepreklapajucaKugla::Preklapanje() const
{
    auto pok(kraj_liste);
    bool preklapanje(false);
    while (pok != nullptr) {
        if(DaLiSePreklapaju(*this, *pok) && pok != this) {
            preklapanje = true;
            break;
        }
        pok = pok->prethodni;
    }
    return preklapanje;
}

double NepreklapajucaKugla::DajX() const
{
    return x;
}

double NepreklapajucaKugla::DajY() const
{
    return y;
}

double NepreklapajucaKugla::DajZ() const
{
    return z;
}

std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const
{
    return std::make_tuple(x,y,z);
}

double NepreklapajucaKugla::DajPoluprecnik() const
{
    return r;
}

double NepreklapajucaKugla::DajPovrsinu() const
{
    return 4*4*atan(1)*r*r;
}

double NepreklapajucaKugla::DajZapreminu() const
{
    return (4./3)*4*atan(1)*r*r*r;
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviX(double x)
{

    NepreklapajucaKugla::x = x;
    if(!Preklapanje())
        return *this;
    throw std::logic_error ("Nedozvoljeno preklapanje");
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviY(double y)
{
    NepreklapajucaKugla::y = y;
    if(!Preklapanje())
        return *this;
    throw std::logic_error ("Nedozvoljeno preklapanje");
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviZ(double z)
{
    NepreklapajucaKugla::z = z;
    if(!Preklapanje())
        return *this;
    throw std::logic_error ("Nedozvoljeno preklapanje");
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(double x, double y, double z)
{
    PostaviX(x);
    PostaviY(y);
    PostaviZ(z);
    if(!Preklapanje())
        return *this;
    throw std::logic_error ("Nedozvoljeno preklapanje");
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    std::tie(x,y,z) = centar;
    if(Preklapanje() == false)
        return *this;
    throw std::logic_error ("Nedozvoljeno preklapanje");
}

NepreklapajucaKugla& NepreklapajucaKugla::PostaviPoluprecnik(double r)
{
    if(r < 0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::r = r;
    if(!Preklapanje())
        return *this; 
    else throw std::logic_error ("Nedozvoljeno preklapanje");
}

void NepreklapajucaKugla::Ispisi() const
{
    std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}"<<std::endl;
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    double x1,y1,z1,x2,y2,z2;
    std::tie(x1,y1,z1) = k1.DajCentar();
    std::tie(x2,y2,z2) = k2.DajCentar();
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
}

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    PostaviX(x+delta_x);
    PostaviY(y+delta_y);
    PostaviZ(z+delta_z);
    if(Preklapanje())
        throw std::logic_error ("Nedozvoljeno preklapanje");
}

bool NepreklapajucaKugla::DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return RastojanjeCentara(k1,k2) < k1.r + k2.r || Jednaki(RastojanjeCentara(k1,k2), k1.r+k2.r);
} 

bool NepreklapajucaKugla::Jednaki(double x, double y)
{
    return (fabs(x-y) <= pow(10, -10) * (fabs(x) + fabs(y)));
}

typedef std::shared_ptr<NepreklapajucaKugla> PokNaKuglu;

int main ()
{
    std::cout << "Unesite broj kugli: ";
    int broj_kugli;
    for(;;) {
        std::cin >> broj_kugli;
        if(!std::cin || broj_kugli<=0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        } else break;
    }
    std::vector<PokNaKuglu> kugle;
    for(int i=0; i<broj_kugli; i++) {
        double x,y,z;
        std::cout << "Unesite centar za " << i+1<< ". kuglu: ";
        for(;;){
        std::cin >> x >> y >> z;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
        }
        else break;
        }
        double r;
        std::cout << "Unesite poluprecnik: ";
        for(;;){
        std::cin >> r;
        if(!std::cin || r<0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
        }
        else break;
        }
        try {
            PokNaKuglu pok_na_kuglu(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
            kugle.push_back(pok_na_kuglu);
        } catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    
    std::cout << std::endl;
    std::cout << "Kugle nakon obavljenog sortiranja:" << std::endl;

    std::sort(kugle.begin(), kugle.end(), [](PokNaKuglu p1, PokNaKuglu p2) {
        return p1->DajPovrsinu() < p2->DajPovrsinu();
    });

    std::for_each(kugle.begin(), kugle.end(), [](PokNaKuglu p1) {
        p1->Ispisi();
        
    });

    return 0;
}
