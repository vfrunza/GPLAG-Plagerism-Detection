#include <iostream>
#include <utility>
#include <vector> 
#include <stdexcept>
#include <cmath>
#include <memory>
#include <algorithm>
double e=pow(10,-10);
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka  x,y,z;
public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(int indeks, const Tacka &t);
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    auto a=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    return a;
}
Tacka DajTjeme(int indeks) const;
double DajStranicu(int indeks) const;
double DajUgao(int indeks) const;
Tacka DajCentar() const;
double DajObim() const;
double DajPovrsinu() const;
bool DaLiJePozitivnoOrijentiran() const;
bool DaLiJeUnutra(const Tacka &t) const;
void Ispisi() const;
void Transliraj(double delta_x, double delta_y);
void Centriraj(const Tacka &t);
void Rotiraj(const Tacka &t, double ugao);
void Skaliraj(const Tacka &t, double faktor);
void Rotiraj(double ugao);
void Skaliraj(double faktor);
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
     x=t1; y=t2; z=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
    x=t1; y=t2; z=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        if(Orijentacija(t,y,z)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        x=t;
    }
    if(indeks==2){
         if(Orijentacija(x,t,z)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
         y=t;
    }
    if(indeks==3){
         if(Orijentacija(x,y,t)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
         z=t;
    }
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return x;
    else if(indeks==2) return y;
    else  return z;
}
double Trougao::DajStranicu(int indeks) const{
     if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
     if(indeks==1) return sqrt(pow((y.second-z.second),2)+pow((y.first-z.first),2));
     else if(indeks==2) return sqrt(pow((x.second-z.second),2)+pow((x.first-z.first),2));
     else return sqrt(pow((y.second-x.second),2)+pow((y.first-x.first),2));
}
double Trougao::DajUgao(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        auto a=DajStranicu(1);
        auto b=DajStranicu(2);
        auto c=DajStranicu(3);
        return acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
    }
    else if(indeks==2){
        auto a=DajStranicu(1);
        auto b=DajStranicu(2);
        auto c=DajStranicu(3);
        return acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
    }
    else {
         auto a=DajStranicu(1);
        auto b=DajStranicu(2);
        auto c=DajStranicu(3);
        return acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
    }
    
    
}
Tacka Trougao::DajCentar() const{
    Tacka p;
    p.first=(x.first+y.first+z.first)/3.;
    p.second=(x.second+y.second+z.second)/3.;
    return p;
}
double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const{
    auto p=x.first*(y.second-z.second)-y.first*(x.second-z.second)+z.first*(x.second-y.second);
    p=fabs(p)/2.;
    return p;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(x,y,z)==1) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if((Orijentacija(x,y,z)==1 && Orijentacija(x,y,t)==1 && Orijentacija(y,z,t)==1 && Orijentacija(x,z,t)==-1)||(Orijentacija(x,y,z)==-1 && Orijentacija(x,y,t)==-1 && Orijentacija(y,z,t)==-1 && Orijentacija(x,z,t)==1))
    return true;
    return false;
}
void Trougao::Ispisi() const{
    std::cout << "((" <<x.first<<","<<x.second<<"),("<<y.first<<","<<y.second<<"),("<<z.first<<","<<z.second<<"))";
}
void Trougao::Transliraj(double delta_x, double delta_y){
    x.first+=delta_x; y.first+=delta_x; z.first+=delta_x;
    x.second+=delta_y; y.second+=delta_y; z.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka stari=DajCentar();
    auto ux1=stari.first-x.first;
    auto uy1=stari.second-x.second;
    x.first=ux1+t.first;
    x.second=uy1+t.second;
    auto ux2=stari.first-y.first;
    auto uy2=stari.second-y.second;
    y.first=ux2+t.first;
    y.second=uy2+t.second;
    auto ux3=stari.first-z.first;
    auto uy3=stari.second-z.second;
    z.first=ux3+t.first;
    z.second=uy3+t.second;
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    double a=x.first;
    double b=y.first;
    double c=z.first;
    x.first=t.first+(a-t.first)*cos(ugao)-(x.second-t.second)*sin(ugao);
    x.second=t.second+(a-t.first)*sin(ugao)+(x.second-t.second)*cos(ugao);
    y.first=t.first+(b-t.first)*cos(ugao)-(y.second-t.second)*sin(ugao);
    y.second=t.second+(b-t.first)*sin(ugao)+(y.second-t.second)*cos(ugao);
    z.first=t.first+(c-t.first)*cos(ugao)-(z.second-t.second)*sin(ugao);
    z.second=t.second+(c-t.first)*sin(ugao)+(z.second-t.second)*cos(ugao);
}
void Trougao::Rotiraj( double ugao){
    Tacka t=DajCentar();
    double a=x.first;
    double b=y.first;
    double c=z.first;
    x.first=t.first+(a-t.first)*cos(ugao)-(x.second-t.second)*sin(ugao);
    x.second=t.second+(a-t.first)*sin(ugao)+(x.second-t.second)*cos(ugao);
    y.first=t.first+(b-t.first)*cos(ugao)-(y.second-t.second)*sin(ugao);
    y.second=t.second+(b-t.first)*sin(ugao)+(y.second-t.second)*cos(ugao);
    z.first=t.first+(c-t.first)*cos(ugao)-(z.second-t.second)*sin(ugao);
    z.second=t.second+(c-t.first)*sin(ugao)+(z.second-t.second)*cos(ugao);

}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(fabs(faktor)<e) throw std::domain_error("Nekorektan faktor skaliranja");
    x.first=t.first+faktor*(x.first-t.first);
    x.second=t.second+faktor*(x.second-t.second);
    y.first=t.first+faktor*(y.first-t.first);
    y.second=t.second+faktor*(y.second-t.second);
    z.first=t.first+faktor*(z.first-t.first);
    z.second=t.second+faktor*(z.second-t.second);
}
void Trougao::Skaliraj(double faktor){
    if(fabs(faktor)<e) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t=DajCentar();
    x.first=t.first+faktor*(x.first-t.first);
    x.second=t.second+faktor*(x.second-t.second);
    y.first=t.first+faktor*(y.first-t.first);
    y.second=t.second+faktor*(y.second-t.second);
    z.first=t.first+faktor*(z.first-t.first);
    z.second=t.second+faktor*(z.second-t.second);
}
  bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    auto a1=t1.DajStranicu(1); auto b1=t1.DajStranicu(2); auto c1=t1.DajStranicu(3);
    auto a2=t2.DajStranicu(1); auto b2=t2.DajStranicu(2); auto c2=t2.DajStranicu(3);
    std::vector<std::pair<Tacka,double>> v1{std::make_pair(t1.x,a1),std::make_pair(t1.y,b1),std::make_pair(t1.z,c1)};
     std::vector<std::pair<Tacka,double>> v2{std::make_pair(t2.x,a2),std::make_pair(t2.y,b2),std::make_pair(t2.z,c2)};
     for(int i=0;i<2;i++){
         for(int j=i+1;j<3;j++){
             if(v1[i].second-v1[j].second<0){
                 auto pom=v1[i];
                 v1[i]=v1[j];
                 v1[j]=pom;
             }
         }
     }
     for(int i=0;i<2;i++){
         for(int j=i+1;j<3;j++){
             if(v2[i].second-v2[j].second<0){
                 auto pom=v2[i];
                 v2[i]=v2[j];
                 v2[j]=pom;
             }
         }
     }
     if((Trougao::Orijentacija(v1[0].first,v1[1].first,v1[2].first)==Trougao::Orijentacija(v2[0].first,v2[1].first,v2[2].first))&&(fabs(t1.DajObim()-t2.DajObim())<e))
     return true;
     return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    auto a1=t1.DajStranicu(1); auto b1=t1.DajStranicu(2); auto c1=t1.DajStranicu(3);
    auto a2=t2.DajStranicu(1); auto b2=t2.DajStranicu(2); auto c2=t2.DajStranicu(3);
    std::vector<std::pair<Tacka,double>> v1{std::make_pair(t1.x,a1),std::make_pair(t1.y,b1),std::make_pair(t1.z,c1)};
     std::vector<std::pair<Tacka,double>> v2{std::make_pair(t2.x,a2),std::make_pair(t2.y,b2),std::make_pair(t2.z,c2)};
     for(int i=0;i<2;i++){
         for(int j=i+1;j<3;j++){
             if(v1[i].second-v1[j].second<0){
                 auto pom=v1[i];
                 v1[i]=v1[j];
                 v1[j]=pom;
             }
         }
     }
     for(int i=0;i<2;i++){
         for(int j=i+1;j<3;j++){
             if(v2[i].second-v2[j].second<0){
                 auto pom=v2[i];
                 v2[i]=v2[j];
                 v2[j]=pom;
             }
         }
     }
     auto n=v1[0].second/v2[0].second;
     if((Trougao::Orijentacija(v1[0].first,v1[1].first,v1[2].first)==Trougao::Orijentacija(v2[0].first,v2[1].first,v2[2].first))&&(fabs(v1[1].second/v2[1].second-n)<e)&&(fabs(v1[2].second/v2[2].second-n)<e))
     return true;
     return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(fabs(t1.x.first+t1.y.first+t1.z.first-t2.x.first-t2.y.first-t2.z.first)<e&&fabs(t1.x.second+t1.y.second+t1.z.second-t2.x.second-t2.y.second-t2.z.second)<e &&fabs((t1.x.first)*(t1.y.first)*(t1.z.first)-(t2.x.first)*(t2.y.first)*(t2.z.first))<e&&fabs((t1.x.second)*(t1.y.second)*(t1.z.second)-(t2.x.second)*(t2.y.second)*(t2.z.second))<e)
    return true;
    return false;
    }
int main(){
    int n;
    std::cout << "Koliko zelite kreirati trouglova: " ;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0;i<n;i++){
        std::cout << "Unesite podatke za "<<i+1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
    double a,b,c,d,e,f;
    std::cin >> a>>b>>c>>d>>e>>f;
    try{
    v[i]=std::make_shared<Trougao>(Trougao(std::make_pair(a,b),std::make_pair(c,d),std::make_pair(e,f)));
    }
    catch(std::domain_error d){
        std::cout << d.what() << std::endl;
        i--;
    }
    }
     std::vector<std::shared_ptr<Trougao>> novi(n);
     double x,y; std::cout <<"Unesite vektor translacije (dx dy): "; std::cin >> x>>y;
     double ugao; std::cout <<"Unesite ugao rotacije: "; std::cin >> ugao;
      double faktor; std::cout<<"Unesite faktor skaliranja: "; std::cin >> faktor;
       std::transform(v.begin(),v.end(),novi.begin(),[=](std::shared_ptr<Trougao> t){ (*t).Transliraj(x,y);  (*t).Rotiraj(ugao); (*t).Skaliraj((*t).DajTjeme(1),faktor); return t;});
     std::sort(novi.begin(),novi.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){auto a=(*t1).DajPovrsinu(); auto b=(*t2).DajPovrsinu(); return a-b<0;  });
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::for_each(novi.begin(),novi.end(),[](std::shared_ptr<Trougao> t){(*t).Ispisi(); std::cout  << std::endl;});
    std::cout << "Trougao sa najmanjim obimom: ";
    auto h=std::min_element(novi.begin(),novi.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){auto a=(*t1).DajObim(); auto b=(*t2).DajObim(); return a-b<0;  });
    (*h)->Ispisi(); std::cout << std::endl;
    bool imali(false),prvi(false),imalp(false),imals(false);
    for(int i=0;i<novi.size()-1;i++){
        for(int j=i+1;j<novi.size();j++){
            if(DaLiSuIdenticni(*novi[i],*novi[j])){
                imali=true;
                if(prvi==false){
                    std::cout << "Parovi identicnih trouglova:" << std::endl;
                    prvi=true;
                }
                novi[i]->Ispisi(); std::cout << " i "; novi[j]->Ispisi();
                std::cout  << std::endl;
            }
        }
    }
    if(!imali) std::cout << "Nema identicnih trouglova!" << std::endl;
    prvi=false;
    for(int i=0;i<novi.size()-1;i++){
        for(int j=i+1;j<novi.size();j++){
            if(DaLiSuPodudarni(*novi[i],*novi[j])){
                imalp=true;
                if(prvi==false){
                    std::cout << "Parovi podudarnih trouglova:" << std::endl;
                    prvi=true;
                }
                novi[i]->Ispisi(); std::cout << " i "; novi[j]->Ispisi();
                std::cout  << std::endl;
            }
        }
    }
    if(!imalp) std::cout << "Nema podudarnih trouglova!" << std::endl;
    prvi=false;
    for(int i=0;i<novi.size()-1;i++){
        for(int j=i+1;j<novi.size();j++){
            if(DaLiSuSlicni(*novi[i],*novi[j])){
                imals=true;
                if(prvi==false){
                    std::cout << "Parovi slicnih trouglova:" << std::endl;
                    prvi=true;
                }
                novi[i]->Ispisi(); std::cout << " i "; novi[j]->Ispisi();
                std::cout  << std::endl;
            }
        }
    }
    if(!imals) std::cout << "Nema slicnih trouglova!" << std::endl;
    
    return 0;
}