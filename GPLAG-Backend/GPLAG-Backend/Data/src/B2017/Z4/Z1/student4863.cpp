#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <ctime>
const double pi(4*atan(1));
const double eps(1e-10);

class Kugla{
    double x, y, z, r;
    public:
explicit Kugla(double r = 0){
    try{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    }catch(std::domain_error e){
        throw;
    }
}
Kugla(double x, double y, double z, double r = 0){
    try{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
    }catch(std::domain_error e){
        throw;
    }
}
explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
    try{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    Kugla::r=r;
    }catch(std::domain_error e){
        throw;
    }
}
double DajX() const{return x;}
double DajY() const{return y;}
double DajZ() const{return z;}
std::tuple<double, double, double> DajCentar() const{return std::tuple<double, double, double>(DajX(), DajY(), DajZ());}
double DajPoluprecnik() const{return r;}
double DajPovrsinu() const{return (4*DajPoluprecnik()*DajPoluprecnik()*pi);}
double DajZapreminu() const{return((4./3)*pi*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik());}
Kugla &PostaviX(double x){Kugla::x=x; return *this;}
Kugla &PostaviY(double y){Kugla::y=y; return *this;}
Kugla &PostaviZ(double z){Kugla::z=z; return *this;}
Kugla &PostaviCentar(double x, double y, double z){
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
}
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    return *this;
}
Kugla &PostaviPoluprecnik(double r){
    try{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
    }catch(std::domain_error e){
        throw;
    }
}
void Ispisi() const{std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;}
void Transliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
bool DaLiSadrzi(const Kugla &k) const{
    return (RastojanjeCentara(k, *this)+k.DajPoluprecnik()<=(this->DajPoluprecnik()));
}
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){ //Okej
    if((std::abs(k1.DajX()-k2.DajX())<=eps*(std::abs(k1.DajX())+std::abs(k2.DajX()))) && (std::abs(k1.DajY()-k2.DajY())<=eps*(std::abs(k1.DajY())+std::abs(k2.DajY()))) && (std::abs(k1.DajZ()-k2.DajZ())<=eps*(std::abs(k1.DajZ())+std::abs(k2.DajZ()))) && (std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<=eps*(std::abs(k1.DajPoluprecnik())+std::abs(k2.DajPoluprecnik())))) return true;
    else return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){ //Okej
    return (std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<=eps*(std::abs(k1.DajPoluprecnik())+std::abs(k2.DajPoluprecnik())));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){ //Okej
    if((std::abs(k1.DajX()-k2.DajX())<=eps*(std::abs(k1.DajX())+std::abs(k2.DajX()))) && (std::abs(k1.DajY()-k2.DajY())<=eps*(std::abs(k1.DajY())+std::abs(k2.DajY()))) && (std::abs(k1.DajZ()-k2.DajZ())<=eps*(std::abs(k1.DajZ())+std::abs(k2.DajZ())))) return true;
    else return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){ //Okej
    double D(RastojanjeCentara(k1, k2));
    double D1((k1.DajPoluprecnik()+k2.DajPoluprecnik()));
    if(std::abs(D1-D)<=eps*(std::abs(D)+std::abs(D1))) return true;
    else return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){ //Okej
    double D(RastojanjeCentara(k1, k2));
    double D1(std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
    if(DaLiSuIdenticne(k1, k2)) return false;
    if(std::abs(D1-D)<=eps*(std::abs(D)+std::abs(D1))) return true;
    else return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){ //Okej
    if(DaLiSeDodirujuIzvana(k1, k2)) return false;
    if(DaLiSeSijeku(k1, k2)) return true;
    if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    if(DaLiSeDodirujuIznutra(k1, k2)) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){ //Okej
    double D(RastojanjeCentara(k1, k2));
    if(k1.DajPoluprecnik()==0 || k2.DajPoluprecnik()==0) return false;
    if(DaLiSuIdenticne(k1, k2) && (k1.DajPoluprecnik()!=0 && k2.DajPoluprecnik()!=0)) return true;
    if((k1.DajPoluprecnik()+k2.DajPoluprecnik())>D && std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<D) return true;
    else return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){ //Okej
    return (sqrt(  ((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())) + ((k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())) +  ((k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ())) ));
}



int main()
{
    int n;
    double a, b, c;
    std::cout << "Unesite broj kugla: ";
    std::cin>>n;
    while(n<0 || n==0 || !std::cin){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin>>n;
    }

    std::vector<std::shared_ptr<Kugla>> v;
    for(int i=0; i<n; i++){
        try{
        double x, y, z, r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!std::cin) throw std::domain_error("Neispravan centar");
        std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!std::cin) throw std::range_error("Ilegalan poluprecnik");
        v.push_back(std::shared_ptr<Kugla>(new Kugla(x, y, z, r)));
        }catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
            i--;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }catch(std::range_error e){
            std::cout<<e.what()<<std::endl;
            i--;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;){
        try{
    std::cin>>a;
    if(!std::cin || a<0) throw std::logic_error("Neispravni parametri translacije, unesite ponovo!\n");
    std::cin>>b;
    if(!std::cin || b<0) throw std::logic_error("Neispravni parametri translacije, unesite ponovo!\n");
    std::cin>>c;
    if(!std::cin || c<0) throw std::logic_error("Neispravni parametri translacije, unesite ponovo!\n");
    break;
        }catch(std::logic_error e){
            std::cout<<e.what();
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }


    std::transform(v.begin(), v.end(), v.begin(), [a, b, c](std::shared_ptr<Kugla> k){k->Transliraj(a, b, c); return std::shared_ptr<Kugla>(new Kugla(*k));});
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){return k1->DajZapreminu()<k2->DajZapreminu();});
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> k){k->Ispisi();});
    auto k=std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2)->bool{return k1->DajPovrsinu()<k2->DajPovrsinu();});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*k)->Ispisi();

    int br(0), p(0);
    std::for_each(v.begin(), v.end(), [&p, &br, v](std::shared_ptr<Kugla> k1){
        p++;
        std::for_each(v.begin()+p, v.end(), [&p, &br, k1](std::shared_ptr<Kugla> k2){
            if(DaLiSeSijeku(*k1, *k2)==true){
                std::cout<<"Presjecaju se kugle: "; k1->Ispisi(); k2->Ispisi();
                br++;
            }
        });
    });
    if(br==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}