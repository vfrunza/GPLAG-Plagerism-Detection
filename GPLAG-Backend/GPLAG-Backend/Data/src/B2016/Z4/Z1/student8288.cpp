#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <new>
#include <stdexcept>
#include <utility>
#include <memory>
#include <iterator>

const double eps(1e-10);
const double PI(3.1415926535);
typedef std::pair<double,double> Tacka;
 class Trougao {
     Tacka t1,t2,t3;
     public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    Postavi(t1,t2,t3);
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(int indeks, const Tacka &t);
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
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

void Trougao::Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)) {
       this->t1.first=t1.first;
        this->t2.first=t2.first;
        this->t3.first=t3.first;
        this->t1.second=t1.second;
        this->t2.second=t2.second;
        this->t3.second=t3.second;
    }
    else 
    throw std::domain_error("Nekorektne pozicije tjemena");
}
void Trougao::Postavi(int indeks,const Tacka &t) {
    if(indeks<1 || indeks>3) {
        throw std::range_error("Nekorektan indeks");
    }
    else 
    switch(indeks) {
        case 1:
        if(Orijentacija(t,t2,t3)==0) 
        throw std::domain_error("Nekorektne pozicje tjemena");
        this->t1.first=t.first;
        this->t1.second=t.second;
        break;
        case 2:
        if(Orijentacija(t1,t,t3)==0)
        throw std::domain_error("Nekorektne pozicije tjemena");
        this->t2.first=t.first;
        this->t2.second=t.second;
        break;
        case 3:
        if(Orijentacija(t1,t2,t)==0) 
        throw std::domain_error("Nekorektne pozicije tjemena");
        this->t3.first=t.first;
        this->t3.second=t.second;
        break;
    }
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
    if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)>0)
    return 1;
    else {
        if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)<0)
        return -1;
        else 
        return 0;
    }
}
Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks<1 || indeks>3)
    throw std::range_error("Nekorektan indeks");
    else 
        switch(indeks) {
            case 1:
            return t1;
            
            case 2:
            return t2;
            
            case 3:
            return t3;
        }
}
double Trougao::DajStranicu(int indeks) const {
    if(indeks<1 || indeks>3) 
    throw std::range_error("Nekorektan indeks");
   
else {
    double str(0);
try {
    str=std::sqrt((DajTjeme(indeks-1).first-DajTjeme(indeks+1).first)*(DajTjeme(indeks-1).first-DajTjeme(indeks+1).first)+(DajTjeme(indeks-1).second-DajTjeme(indeks+1).second)*(DajTjeme(indeks-1).second-DajTjeme(indeks+1).second));
}
catch (std::range_error e) {
    try {
     str=std::sqrt((DajTjeme(indeks+1).first-DajTjeme(indeks+2).first)*(DajTjeme(indeks+1).first-DajTjeme(indeks+2).first)+(DajTjeme(indeks+1).second-DajTjeme(indeks+2).second)*(DajTjeme(indeks+1).second-DajTjeme(indeks+2).second));
}
catch(std::range_error e) {
 str=std::sqrt((DajTjeme(indeks-1).first-DajTjeme(indeks-2).first)*(DajTjeme(indeks-1).first-DajTjeme(indeks-2).first)+(DajTjeme(indeks-1).second-DajTjeme(indeks-2).second)*(DajTjeme(indeks-1).second-DajTjeme(indeks-2).second));   
}
}
return str;
}
}
double Trougao::DajUgao(int indeks) const {
    if(indeks<1 || indeks>3) 
    throw std::range_error("Nekorektan indeks");
else {
    double ugao(0);
    try {
   ugao=acos((DajStranicu(indeks+1)*DajStranicu(indeks+1)+DajStranicu(indeks-1)*DajStranicu(indeks-1)-DajStranicu(indeks)*DajStranicu(indeks))/(2*DajStranicu(indeks+1)*DajStranicu(indeks-1)))*PI/180.;
    }
    catch(std::range_error e) {
       try {
            ugao=acos((DajStranicu(indeks+1)*DajStranicu(indeks+1)+DajStranicu(indeks+2)*DajStranicu(indeks+2)-DajStranicu(indeks)*DajStranicu(indeks))/(2*DajStranicu(indeks+1)*DajStranicu(indeks+2)))*PI/180.;
       }
       catch(std::range_error e) {
           ugao=acos((DajStranicu(indeks-1)*DajStranicu(indeks-1)+DajStranicu(indeks-2)*DajStranicu(indeks-2)-DajStranicu(indeks)*DajStranicu(indeks))/(2*DajStranicu(indeks-1)*DajStranicu(indeks-2)))*PI/180.;
       }
    }
return ugao;
}
}
Tacka Trougao::DajCentar() const {
    Tacka c;
    c.first=(t1.first+t2.first+t3.first)/3.;
    c.second=(t1.second+t2.second+t3.second)/3.;
    return c;
}
double Trougao::DajObim() const {
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const {
    double povrsina(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    return std::abs(povrsina)/2.;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    return Orijentacija(t1,t2,t3)>0;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    double broj=Orijentacija(t1,t2,t)+Orijentacija(t2,t3,t)+Orijentacija(t3,t1,t);
    return broj-Orijentacija(t1,t2,t3)<eps;
}
void Trougao::Ispisi() const {
    std::cout<<"(";
    for(int i=1;i<4;i++) {
        if(i<3) 
        std::cout<<"("<<DajTjeme(i).first<<","<<DajTjeme(i).second<<"),";
        else 
        std::cout<<"("<<DajTjeme(i).first<<","<<DajTjeme(i).second<<")";
        }
    std::cout<<")";
}
void Trougao::Transliraj(double delta_x,double delta_y) {
       this->t1.first+=delta_x;
       this->t1.second+=delta_y;
       this->t2.first+=delta_x;
       this->t2.second+=delta_y;
       this->t3.first+=delta_x;
       this->t3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t) {
    double razlika_x(0),razlika_y(0);
    razlika_x=t.first-DajCentar().first;
    razlika_y=t.second-DajCentar().second;
        Trougao::Transliraj(razlika_x,razlika_y);
    }

void Trougao::Rotiraj(const Tacka &t,double ugao) {
     Tacka t6,t4,t5;
    t4=DajTjeme(1);
    t5=DajTjeme(2);
    t6=DajTjeme(3);
       this->t1.first=t.first+(t4.first-t.first)*std::cos(ugao)-(t4.second-t.second)*std::sin(ugao);
    this->t1.second=t.second+(t4.first-t.first)*std::sin(ugao)+(t4.second-t.second)*std::cos(ugao);
     this->t2.first=t.first+(t5.first-t.first)*std::cos(ugao)-(t5.second-t.second)*std::sin(ugao);
    this->t2.second=t.second+(t5.first-t.first)*std::sin(ugao)+(t5.second-t.second)*std::cos(ugao);
     this->t3.first=t.first+(t6.first-t.first)*std::cos(ugao)-(t6.second-t.second)*std::sin(ugao);
    this->t3.second=t.second+(t6.first-t.first)*std::sin(ugao)+(t6.second-t.second)*std::cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t,double faktor) {
    if(std::fabs(faktor)<std::fabs(eps)) 
    throw std::domain_error("Nekorektan faktor skaliranja");
    else {
        this->t1.first=t.first+faktor*(t1.first-t.first);
        this->t1.second=t.second+faktor*(t1.second-t.second);
        
         this->t2.first=t.first+faktor*(t2.first-t.first);
        this->t2.second=t.second+faktor*(t2.second-t.second);
        
         this->t3.first=t.first+faktor*(t3.first-t.first);
        this->t3.second=t.second+faktor*(t3.second-t.second);
}
}
void Trougao::Rotiraj(double ugao) {
   this->t1.first=DajCentar().first+DajCentar().first*std::cos(ugao)-DajCentar().second*std::sin(ugao);
    this->t1.second=DajCentar().second+DajCentar().first*std::sin(ugao)+DajCentar().second*std::cos(ugao);
    
     this->t2.first=DajCentar().first+DajCentar().first*std::cos(ugao)-DajCentar().second*std::sin(ugao);
    this->t2.second=DajCentar().second+DajCentar().first*std::sin(ugao)+DajCentar().second*std::cos(ugao);
    
     this->t3.first=DajCentar().first+DajCentar().first*std::cos(ugao)-DajCentar().second*std::sin(ugao);
    this->t3.second=DajCentar().second+DajCentar().first*std::sin(ugao)+DajCentar().second*std::cos(ugao);
}

void Trougao::Skaliraj(double faktor) {
     if(std::fabs(faktor)<std::fabs(eps)) 
    throw std::domain_error("Nekorektan faktor skaliranja");
    else  {
        this->t1.first=this->DajCentar().first+faktor*(t1.first-DajCentar().first);
        this->t1.second=this->DajCentar().second+faktor*(t1.second-DajCentar().second);
        this->t2.first=this->DajCentar().first+faktor*(t2.first-DajCentar().first);
        this->t2.second=this->DajCentar().second+faktor*(t2.second-DajCentar().second);
        this->t3.first=this->DajCentar().first+faktor*(t3.first-DajCentar().first);
        this->t3.second=this->DajCentar().second+faktor*(t3.second-DajCentar().second);
    }
}
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2) {
    int broj(0);
    Tacka t;
    Tacka s;
    for(int i=1;i<4;i++) {
        t.first=t1.DajTjeme(i).first;
        t.second=t1.DajTjeme(i).second;
        broj=0;
        for(int j=1;j<4;j++) {
            s.first=t2.DajTjeme(j).first;
            s.second=t2.DajTjeme(j).second;
            if(std::abs(t.first-s.first)<std::abs(eps) && std::abs(t.second-s.second)<std::abs(eps)) 
            broj++;
        }
        if(broj==1)
        continue;
        else 
        return false;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2) {
    std::vector<std::pair<double,Tacka>> v1;
    std::vector<std::pair<double,Tacka>> v2;
    int broj(0);
    for(int i=1;i<4;i++) {
        broj=0;
        v1.push_back(std::make_pair(t1.DajStranicu(i),t1.DajTjeme(i)));
        v2.push_back(std::make_pair(t2.DajStranicu(i),t2.DajTjeme(i)));
      for(int j=1;j<4;j++) {
          if(std::fabs(t1.DajStranicu(i)-t2.DajStranicu(j))<std::fabs(eps)) {
              broj++;
          }
      }
      if(broj)
      continue;
      else 
        return false;
    }
    return Trougao::Orijentacija(v1[0].second,v1[1].second,v1[2].second)==Trougao::Orijentacija(v2[0].second,v2[1].second,v2[2].second);
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2) {
    double br(0);
    Trougao t3=t2;
    if(DaLiSuIdenticni(t3,t1)) {
        return true;
    }
  for(int i=1;i<4;i++) {
      for(int j=1;j<4;j++) {
          t3=t2;
      br=t1.DajStranicu(j)/t2.DajStranicu(j);
      t3.Skaliraj(br);
      if(DaLiSuPodudarni(t3,t1)) {
          return true;
      }
  }
}
return false;
}

int main() {
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n(0);
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int j=0;j<n;j++) {
        v[j]=nullptr;
    }
    Tacka t1,t2,t3;
    double delta_x(0.),delta_y(0.),faktor(0.),ugao(0.);
    for(int i=0;i<n;i++) {
        try {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
        v[i]=std::make_shared<Trougao>(t1,t2,t3);
       }
    catch(std::domain_error e) {
        std::cout<<e.what()<<", ponovite unos!"<<std::endl;
        i--;
    }
    catch(std::bad_alloc) {
        std::cout<<"Problemi pri unosu podataka"<<std::endl;
    }
    }
     std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>delta_x>>delta_y;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    try {
  std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,faktor,ugao](std::shared_ptr<Trougao> t)->std::shared_ptr<Trougao> {
        (*t).Transliraj(delta_x,delta_y);
        (*t).Rotiraj(t->DajCentar(),ugao);
        (*t).Skaliraj(t->DajTjeme(1),faktor);
        return t;
    });
    }
    catch(std::range_error e) {
        std::cout<<e.what()<<std::endl;
        }
        catch(std::domain_error s) {
            std::cout<<s.what()<<std::endl;
        }
      std::sort(v.begin(),v.end(),[](const std::shared_ptr<Trougao> &t1,const std::shared_ptr<Trougao> &t2) {
        return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
  std::for_each(v.begin(),v.end(),[](const std::shared_ptr<Trougao> t) {
        (*t).Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    Trougao rezultat(**(std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2) {
      return (*t1).DajObim()<(*t2).DajObim();
  })));
  rezultat.Ispisi();
  std::vector<Trougao> b;
  int br1(0),br2(0),br3(0);
  int i,j;
   for(int i=0;i<v.size();i++) {
        for(int j=i+1;j<v.size();j++) {
      if(i!=j && DaLiSuIdenticni(*v[i],*v[j])) {
          b.push_back(*v[i]);
          br1++;
      }
        }
   }
   if(br1) {
       std::cout<<std::endl<<"Parovi identicnih trouglova:"<<std::endl;
    for(i=0;i<v.size()-1;i++) {
        for(j=i+1;j<v.size();j++) {
      if( i!=j && DaLiSuIdenticni(*v[i],*v[j])) {
      (*v[i]).Ispisi();
     std::cout<<" i ";
      (*v[j]).Ispisi();
      std::cout<<std::endl;
        }
          }
    }
   }

   
    int k,z;
    for(k=0;k<v.size();k++) {
      for(z=0;z<v.size();z++) {
      if(k!=z && DaLiSuPodudarni(*v[k],*v[z])) {
   br2++;
      }
      }
    }
    
   if(br2) {
   std::cout<<"Parovi podudarnih trouglova:"<<std::endl;

  for(k=0;k<v.size()-1;k++) {
      for(z=k+1;z<v.size();z++) {
      if(DaLiSuPodudarni(*v[k],*v[z])) {
      (*v[k]).Ispisi();
      std::cout<<" i ";
      (*v[z]).Ispisi();
      std::cout<<std::endl;
  }
  }
  }
  br2++;
   }
   int u,l;
     for(u=0;u<v.size();u++) {
       for(l=0;l<v.size();l++) {
        if(u!=l && DaLiSuSlicni(*v[u],*v[l])){
   br3++;
        }
       }
     }
   if(br3) {
       std::cout<<"Parovi slicnih trouglova:"<<std::endl;
   for(u=0;u<v.size()-1;u++) {
       br3=0;
       for(l=u+1;l<v.size();l++) {
        if(DaLiSuSlicni(*v[u],*v[l])) {
            for(int p=0;p<b.size();p++) {
            (*v[u]).Ispisi();
            std::cout<<" i ";
            (*v[l]).Ispisi();
            std::cout<<std::endl;
            br3++;
                }
    }
   }
   }
   br3++;
   }
   
   if(br1==0) std::cout<<std::endl<<"Nema identicnih trouglova!"<<std::endl;
   if(br2==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
   if(br3==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
        return 0;
}