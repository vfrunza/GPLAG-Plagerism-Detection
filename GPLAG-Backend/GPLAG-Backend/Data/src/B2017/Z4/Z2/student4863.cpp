#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
const double pi(4*atan(1));
const double eps(1e-10);

class NepreklapajucaKugla{
    double x, y, z, r;
    NepreklapajucaKugla *prethodni;
    static NepreklapajucaKugla *zadnji;
    bool DaLiSePreklapaju(NepreklapajucaKugla *k1, NepreklapajucaKugla *k2){
        double D1((k1->DajPoluprecnik()+k2->DajPoluprecnik()));
       // double D2(abs(k1->DajPoluprecnik()-k2->DajPoluprecnik()));
        double D(RastojanjeCentara(*k1, *k2));
        if(abs(D)>D1) return true;
        else return false;
    }
    public:

explicit NepreklapajucaKugla(double r = 0){
    try{
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        if(!zadnji){
            zadnji=nullptr;
        }

        prethodni=nullptr;
        prethodni=zadnji;
        zadnji=this;

        if(zadnji!=nullptr){
            for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
        }

    }catch(std::domain_error e){
        throw;
    }catch(std::logic_error e){
        throw;
    }
}

NepreklapajucaKugla(double x, double y, double z, double r = 0){
        try{
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
        if(!zadnji){
            zadnji=nullptr;
        }

        prethodni=nullptr;
        prethodni=zadnji;
        zadnji=this;

        if(zadnji!=nullptr){
            for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
        }

    }catch(std::domain_error e){
        throw;
    }catch(std::logic_error e){
        throw;
    }
}

explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
    try{
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
        if(!zadnji){
            zadnji=nullptr;
        }

        prethodni=nullptr;
        prethodni=zadnji;
        zadnji=this;

        if(zadnji!=nullptr){
            for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, pok)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
        }


    }catch(std::domain_error e){
        throw;
    }catch(std::logic_error e){
        throw;
    }
}
NepreklapajucaKugla (const NepreklapajucaKugla &k)=delete;
NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k)=delete;
//~NepreklapajucaKugla(){auto d=zadnji; zadnji=prethodni; delete d;}

double DajX() const{return x;}
double DajY() const{return y;}
double DajZ() const{return z;}
std::tuple<double, double, double> DajCentar() const{return std::tuple<double, double, double>(DajX(), DajY(), DajZ());}
double DajPoluprecnik() const{return r;}
double DajPovrsinu() const{return (4*DajPoluprecnik()*DajPoluprecnik()*pi);}
double DajZapreminu() const{return((4/3)*pi*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik());}
NepreklapajucaKugla &PostaviX(double x){
    try{
    NepreklapajucaKugla::x=x;
        for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
    }catch(std::logic_error e){
     throw;
    }
     return *this;
    }
NepreklapajucaKugla &PostaviY(double y){
    try{
    NepreklapajucaKugla::y=y;
        for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
    }catch(std::logic_error e){
     throw;
    }
    return *this;
    
}
NepreklapajucaKugla &PostaviZ(double z){
    try{
    NepreklapajucaKugla::z=z;
        for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
    }catch(std::logic_error e){
     throw;
    }
    return *this;
    
}

NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
    try{
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
    }catch(std::logic_error e){
        throw;
    }
    return *this;
}
NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    try{
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
    }catch(std::logic_error e){
        throw;
    }
    return *this;
}
NepreklapajucaKugla &PostaviPoluprecnik(double r){
    try{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    for(auto pok=zadnji; pok->prethodni!=nullptr; pok=pok->prethodni){
        if(!DaLiSePreklapaju(this, prethodni)){
                     zadnji=prethodni;
                     throw std::logic_error("Nedozvoljeno preklapanje");
                }
            }
    return *this;
    }catch(std::domain_error e){
        throw;
    }catch(std::logic_error e){
        throw;
    }
}
void Ispisi() const{std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;}
void Transliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}

friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla *NepreklapajucaKugla::zadnji=nullptr;

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){ //Okej
    return (sqrt(  ((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())) + ((k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())) +  ((k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ())) ));
}
int main()
{

    double a,b,c,r;
    int n;
    std::cout << "Unesite broj kugli: ";
    std::cin>>n;
    while(n<0 || n==0 || !std::cin){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin>>n;
    }

    std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
    
    for(int i=0; i<n; i++){
        try{
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        std::cin>>a>>b>>c;
        while(!std::cin){
            std::cout<<"Neispravan centar, unesite ponovo:"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin>>a>>b>>c;
        }
        std::cout<<"Unesite poluprecnik: ";
        std::cin>>r;
        while(!std::cin || r<0){
            std::cout<<"Neispravan poluprecnik, unesite ponovo:"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin>>r;
        }
        v.push_back(std::shared_ptr<NepreklapajucaKugla>(new NepreklapajucaKugla(a,b,c,r)));
        }catch(std::logic_error e){
         std::cout<<e.what()<<std::endl;
         i--;
    }
    
    }
    std::cout<<std::endl;
    
    
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
    std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> k){k->Ispisi();});
    return 0;
}