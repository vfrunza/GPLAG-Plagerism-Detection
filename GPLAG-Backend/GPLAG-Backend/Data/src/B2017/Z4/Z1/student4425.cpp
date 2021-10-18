/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <vector>
#include<utility>
#include <iterator>

class Kugla{
    double x, y, z, r;
     bool Sadrzi(double a1, double r1, double a2, double r2)const{
        double eps(0.000000001);
        if(fabs(a1-r1-(a2-r2))<=eps*(fabs(a1-r1)+fabs(a2-r2))&&(fabs(a1+r1-(a2+r2))<=eps*(fabs(a1+r1)+fabs(a2+r2))))
        return true;
        return false;
    }
    public:
    explicit Kugla(double r = 0){PostaviCentar(0,0,0); PostaviPoluprecnik(r);}
    Kugla(double x, double y, double z, double r = 0){if(r<0) throw std::domain_error("Ilegalan poluprecnik"); PostaviCentar(x, y, z); PostaviPoluprecnik(r);}
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){PostaviCentar(centar); PostaviPoluprecnik(r);}
    double DajX() const{return x;}
    double DajY() const{return y;}
    double DajZ() const{return z;}
    std::tuple<double, double, double> DajCentar() const{return std::make_tuple(x,y,z);};
    double DajPoluprecnik() const{return r;}
    double DajPovrsinu() const{return 4*r*r*4*std::atan(1);}
    double DajZapreminu() const{return (4/3)*r*r*r*4*std::atan(1);}
    Kugla &PostaviX(double x){Kugla::x=x; return *this;}
    Kugla &PostaviY(double y){Kugla::y=y; return *this;}
    Kugla &PostaviZ(double z){Kugla::z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z){PostaviX(x); PostaviY(y); PostaviZ(z); return *this;}
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
            PostaviX(std::get<0>(centar));
            PostaviY(std::get<1>(centar));
            PostaviZ(std::get<2>(centar));
            return *this;
    }
    Kugla &PostaviPoluprecnik(double r){Kugla::r=r; return *this;}
    void Ispisi() const{std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
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
    if(Sadrzi(DajX(), DajPoluprecnik(), k.DajX(), k.DajPoluprecnik())&&Sadrzi(DajY(), DajPoluprecnik(), k.DajY(), k.DajPoluprecnik())&&Sadrzi(DajZ(), DajPoluprecnik(), k.DajZ(), k.DajPoluprecnik()))
    return true;
    return false;
}
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    double eps(0.000000001);
    int a(0);
    if(k1.r>0&&k2.r>0){
    if(fabs(k1.x+k1.r-k2.x-k2.r)<eps*(fabs(k1.x+k1.r)+fabs(k2.x+k2.r))) a++;
    if(fabs(k1.y+k1.r-k2.y-k2.r)<eps*(fabs(k1.y+k1.r)+fabs(k2.y+k2.r))) a++;
    if(fabs(k1.z+k1.r-k2.z-k2.r)<eps*(fabs(k1.z+k1.r)+fabs(k2.z+k2.r))) a++;
    if(fabs(k1.r-k2.r)<eps*(fabs(k1.r)+fabs(k2.r))) a++;}
    else{
        if(fabs(k1.x-k2.x)<=eps*(fabs(k1.x)+fabs(k2.x))) a++;
        if(fabs(k1.y-k2.y)<=eps*(fabs(k1.y)+fabs(k2.y))) a++;
        if(fabs(k1.z-k2.z)<=eps*(fabs(k1.z)+fabs(k2.z))) a++;
        if(fabs(k1.r-k2.r)<=eps*(fabs(k1.r)+fabs(k2.r))) a++;
    }
    if(a==4)
    return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    double eps(0.000000001);
    if(fabs(k1.r-k2.r)<=eps*(fabs(k1.r)+fabs(k2.r)))
    return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    double eps(0.000000001);
    if((fabs(k1.x-k2.x)<=eps*(fabs(k1.x)+fabs(k2.x)))&&(fabs(k1.y-k2.y)<=eps*(fabs(k1.y)+fabs(k2.y)))&&(fabs(k1.z-k2.z)<=eps*(fabs(k1.z)+fabs(k2.z))))
    return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    double udaljenost (RastojanjeCentara(k1, k2)), poluprecnici(k1.r+k2.r), eps(0.000000001);
    if (fabs(udaljenost-poluprecnici)<=eps*(fabs(udaljenost)+fabs(poluprecnici)));
    return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    double udaljenost (RastojanjeCentara(k1, k2)), eps(0.000000001);
    if(((fabs(2*udaljenost-k1.r)<=eps*(fabs(2*udaljenost)+fabs(k1.r)))||fabs(2*udaljenost-k2.r)<=eps*(fabs(2*udaljenost)+fabs(k2.r))))
    return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    double udaljenost(RastojanjeCentara(k1,k2)), poluprecnici(k1.DajPoluprecnik()+k2.DajPoluprecnik()), eps(0.000000001);
    if(DaLiSuIdenticne(k1,k2))
    return false;
    if(DaLiSuKoncentricne(k1,k2))
    return false;
    if(DaLiSeDodirujuIznutra(k1,k2))
    return false;
    if(k1.r<eps||k2.r<eps)
    return false;
    if(udaljenost<poluprecnici) 
    return true;
    return false;
}

bool DaLiSuPreklapaju(const Kugla &k1, const Kugla &k2){
    double udaljenost(RastojanjeCentara(k1,k2)), poluprecnici(k1.DajPoluprecnik()+k2.DajPoluprecnik());
    if(DaLiSeDodirujuIznutra(k1,k2)||DaLiSuIdenticne(k1,k2)||DaLiSuKoncentricne(k1,k2)||udaljenost<poluprecnici)
    return true;
    return false;
}

int main ()
{
    try{
    std::cout<<"Unesite broj kugla: ";
    int n, i(1);
    double x, y, z, r;
    while(1){
        std::cin>>n;
        if(!std::cin||n<=0){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        }
        else break;
    }
    std::vector<std::shared_ptr<Kugla>> v;
    while(n!=0){
        std::cout<<"Unesite centar "<<i<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!std::cin){
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i<<". kugle: ";
        std::cin>>r;
        if(!std::cin||r<0){
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        Kugla k(x,y,z,r);
        v.push_back(std::make_shared<Kugla>(k));
        n--;
        i++;
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    while(1){
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        }
        else break;
    }
    //std::cin>>delta_x>>delta_y>>delta_z;
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> p){p->Transliraj(delta_x,delta_y, delta_z); return p;});
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {return(p1->DajZapreminu()<p2->DajZapreminu());});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> p){p->Ispisi();});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto it=std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla>p1, std::shared_ptr<Kugla>p2){return(p1->DajPovrsinu()<p2->DajPovrsinu());});
    (*it)->Ispisi();
    int presjecene(0);
    if(v.size()>1){
    auto it1(v.begin()), it2(v.begin());
    std::vector<std::pair<Kugla, Kugla>> kuglex;
    it2++;
    std::for_each(it1, v.end(), [&v, &it1, &it2, &presjecene, &kuglex](std::shared_ptr<Kugla>p1){
        std::for_each(it2, v.end(), [p1, &presjecene, &kuglex](std::shared_ptr<Kugla>p2){
        if(DaLiSeSijeku(*p1,*p2)&&!DaLiSuIdenticne(*p1,*p2)) {
        //std::cout<<"Presjecaju se kugle: ";
        presjecene++; 
        if(kuglex.size()==0)
        kuglex.push_back(std::make_pair(*p1,*p2));
            else{
                int z(0);
           std::for_each(kuglex.begin(), kuglex.end(), [kuglex, &z, p1, p2](std::pair<Kugla, Kugla> kugle){
             if(((DaLiSuIdenticne(kugle.first, *p1)&&DaLiSuIdenticne(kugle.second, *p2))||(DaLiSuIdenticne(kugle.first,*p2)&&DaLiSuIdenticne(kugle.second, *p1))))
            z++;
           });
           if(z==0) kuglex.push_back(std::make_pair(*p1,*p2));
            }
        }
        //p1->Ispisi();
        //p2->Ispisi();}
        });
        it2++;
    });
   /* std::cout<<"EEEE"<<std::endl;
    for(int i=0; i<kuglex.size(); i++){
        (kuglex.at(i).first).Ispisi(); std::cout<<" ";
        (kuglex.at(i).second).Ispisi(); std::cout<<std::endl;
    }*/
    if(presjecene==0)
    std::cout<<"Ne postoje kugle koje se presjecaju!";
    if(kuglex.size()>1){
        int a(0);
        std::for_each(kuglex.begin(), kuglex.end(), [kuglex,&a](std::pair<Kugla, Kugla> kugle1){
           std::for_each(kuglex.begin(), kuglex.end(), [kugle1, &a](std::pair<Kugla, Kugla> kugle2){
             if(!((DaLiSuIdenticne(kugle1.first, kugle2.first)&&DaLiSuIdenticne(kugle1.second, kugle2.second))||(DaLiSuIdenticne(kugle1.first,kugle2.second)&&DaLiSuIdenticne(kugle1.second, kugle2.first))))
             {if(a==0){std::cout<<"Presjecaju se kugle: "; 
             (kugle1.first).Ispisi();
             (kugle1.second).Ispisi();  a++;}}
           });
           a=0;
        });
    }
        if(kuglex.size()==1){
            std::for_each(kuglex.begin(), kuglex.end(), [](std::pair<Kugla, Kugla> kugle1){
                std::cout<<"Presjecaju se kugle: ";
                (kugle1.first).Ispisi();
                (kugle1.second).Ispisi();
            });
        }
    }
    else
    std::cout<<"Ne postoje kugle koje se presjecaju!";}
    catch(std::domain_error iz){
        std::cout<<iz.what()<<std::endl;
    }
	return 0;
}
