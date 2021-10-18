/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>

typedef std::pair<double,double> Tacka;


class Trougao {
  Tacka T1,T2,T3;
  static bool JesuLiJednaki(double x, double y, double Eps=1e-10) {
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
  }
  public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) {
      throw std::range_error("Nekorektne pozicije tjemena");
    }
     T1=t1; T2=t2; T3=t3;
  }
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
     if(Orijentacija(t1,t2,t3)==0) {
      throw std::range_error("Nekorektne pozicije tjemena");
    }
    T1=t1; T2=t2; T3=t3;
  }
  void Postavi(int indeks,const Tacka &t);
  static int Orijentacija(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
    int rezultat=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
  if(rezultat>0) {
    return 1;
  }
  if(rezultat<0) {
    return -1;
  }
  if(rezultat==0) {
    return 0;
  }
  }
  Tacka DajTjeme(int indeks) const;
  double DajStranicu(int indeks) const;
  double DajUgao(int indeks) const;
  Tacka DajCentar() const;
  double DajObim() const;
  double DajPovrsinu() const;
  bool DaLiJePozitivnoOrijentiran() const {
    if(Orijentacija(T1,T2,T3)==1) {
      return true;
    }
    return false;
  }
  bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const {
    std::cout<<"(("<<T1.first<<","<<T1.second<<"),("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";
  }
  void Transliraj(double delta_x,double delta_y);
  void Centriraj(const Tacka &t);
  void Rotiraj(const Tacka &t,double ugao);
  void Skaliraj(const Tacka &t,double faktor);
  void Rotiraj(double ugao);
  void Skaliraj(double faktor);
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);

};
void Trougao::Postavi(int indeks, const Tacka &t) {
  if(indeks!=1 || indeks!=2 || indeks!=3) {
    throw std::range_error("Nekorektan indeks");
  }
  if(indeks==1) {
    T1=t;
  }
  else if(indeks==2) {
    T2=t;
  }
  else if(indeks==3) {
    T3=t;
  }
}
Tacka Trougao::DajTjeme(int indeks) const {
  if(indeks==1) {
    return T1;
  }
  else if(indeks==2) {
    return T2;
  }
  else if(indeks==3) {
    return T3;
  }
}
double Trougao::DajStranicu(int indeks) const {
  if(indeks==1) {
    return std::sqrt((T3.first-T2.first)*(T3.first-T2.first)+(T2.second-T2.second)*(T3.second-T2.second));
  }
  if(indeks==2) {
    return std::sqrt((T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second));
  }
  if(indeks==3) {
    return std::sqrt((T1.first-T2.first)*(T1.first-T2.first)+(T1.second-T2.second)*(T1.second-T2.second));
  }
}
double Trougao::DajUgao(int indeks) const {  
  double a=std::sqrt((T3.first-T2.first)*(T3.first-T2.first)+(T2.second-T2.second)*(T3.second-T2.second));
  double b=std::sqrt((T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second));
  double c=std::sqrt((T1.first-T2.first)*(T1.first-T2.first)+(T1.second-T2.second)*(T1.second-T2.second));
  if(indeks==1) {
    double alfa=std::acos((b*b+c*c-a*a)/(2*b*c));
    return alfa;
  }
  if(indeks==2) {
    double beta=std::acos((a*a+c*c-b*b)/(2*a*c));
    return beta;
  }
  if(indeks==3) {
    double gama=std::acos((a*a+b*b-c*c)/(2*a*b));
    return gama;
  }
}

double Trougao::DajObim() const {
  double x=DajStranicu(1);
  double y=DajStranicu(2);
  double z=DajStranicu(3);
  return x+y+z;
}

double Trougao::DajPovrsinu() const {
  return std::fabs(T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second))/2;
}
Tacka Trougao::DajCentar() const {
  return {(T1.first+T2.first+T3.first)/3,(T1.second+T2.second+T3.second)/3};
}
void Trougao::Transliraj(double delta_x,double delta_y) {
  T1.first+=delta_x;
  T1.second+=delta_y;
  T2.first+=delta_x;
  T2.second+=delta_y;
  T3.first+=delta_x;
  T3.second+=delta_y;
}
void Trougao::Rotiraj(const Tacka &t,double ugao) { 
  double a=T1.first;
  double b=T2.first;
  double c=T3.first;
  T1.first=t.first+(T1.first-t.first)*std::cos(ugao)-(T1.second-t.second)*std::sin(ugao);
  T1.second=t.second+(a-t.first)*std::sin(ugao)+(T1.second-t.second)*std::cos(ugao);
  T2.first=t.first+(T2.first-t.first)*std::cos(ugao)-(T2.second-t.second)*std::sin(ugao);
  T2.second=t.second+(b-t.first)*std::sin(ugao)+(T2.second-t.second)*std::cos(ugao);
  T3.first=t.first+(T3.first-t.first)*std::cos(ugao)-(T3.second-t.second)*std::sin(ugao);
  T3.second=t.second+(c-t.first)*std::sin(ugao)+(T3.second-t.second)*std::cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t,double faktor) {
  if(faktor==0) {
    throw std::domain_error("Nekorektan faktor skaliranja");
  }
  T1.first=t.first+faktor*(T1.first-t.first);
  T1.second=t.second+faktor*(T1.second-t.second);
  T2.first=t.first+faktor*(T2.first-t.first);
  T2.second=t.second+faktor*(T2.second-t.second);
  T3.first=t.first+faktor*(T3.first-t.first);
  T3.second=t.second+faktor*(T3.second-t.second);
  if(faktor<0) Rotiraj(180);

}
void Trougao::Rotiraj(double ugao) {
  Tacka T=DajCentar();
  double a=T1.first;
  double b=T2.first;
  double c=T3.first;
  T1.first=T.first+(T1.first-T.first)*std::cos(ugao)-(T1.second-T.second)*std::sin(ugao);
  T1.second=T.second+(a-T.first)*std::sin(ugao)+(T1.second-T.second)*std::cos(ugao);
  T2.first=T.first+(T2.first-T.first)*std::cos(ugao)-(T2.second-T.second)*std::sin(ugao);
  T2.second=T.second+(b-T.first)*std::sin(ugao)+(T2.second-T.second)*std::cos(ugao);
  T3.first=T.first+(T3.first-T.first)*std::cos(ugao)-(T3.second-T.second)*std::sin(ugao);
  T3.second=T.second+(c-T.first)*std::sin(ugao)+(T3.second-T.second)*std::cos(ugao);
  
}
void Trougao::Skaliraj(double faktor) {
  if(faktor==0) {
    throw std::domain_error("Nekorektan faktor skaliranja");
  }
  Tacka T=DajCentar();
  T1.first=T.first+faktor*(T1.first-T.first);
  T1.second=T.second+faktor*(T1.second-T.second);
  T2.first=T.first+faktor*(T2.first-T.first);
  T2.second=T.second+faktor*(T2.second-T.second);
  T3.first=T.first+faktor*(T3.first-T.first);
  T3.second=T.second+faktor*(T3.second-T.second);
  if(faktor<0) Rotiraj(180);
  
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
  if(t1.DajTjeme(1)==t2.DajTjeme(1) && t1.DajTjeme(2)==t2.DajTjeme(2) && t1.DajTjeme(3)==t2.DajTjeme(3)) {
    return true;
  }
  if(t1.DajTjeme(1)==t2.DajTjeme(1) && t1.DajTjeme(2)==t2.DajTjeme(3) && t1.DajTjeme(3)==t2.DajTjeme(2)) {
    return true;
  }
  if(t1.DajTjeme(1)==t2.DajTjeme(2) && t1.DajTjeme(2)==t2.DajTjeme(1) && t1.DajTjeme(3)==t2.DajTjeme(3)) {
    return true;
  }
  if(t1.DajTjeme(1)==t2.DajTjeme(2) && t1.DajTjeme(2)==t2.DajTjeme(3) && t1.DajTjeme(3)==t2.DajTjeme(1)) {
    return true;
  }
  if(t1.DajTjeme(1)==t2.DajTjeme(3) && t1.DajTjeme(2)==t2.DajTjeme(1) && t1.DajTjeme(3)==t2.DajTjeme(2)) {
    return true;
  }
  if(t1.DajTjeme(1)==t2.DajTjeme(3) && t1.DajTjeme(2)==t2.DajTjeme(2) && t1.DajTjeme(3)==t2.DajTjeme(1)) {
    return true;
  }
  return false;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2) {
  double a=t1.DajStranicu(1);
  double b=t1.DajStranicu(2);
  double c=t1.DajStranicu(3);
  double a1=t2.DajStranicu(1);
  double b1=t2.DajStranicu(2);
  double c1=t2.DajStranicu(3);
  if(a/a1==b/b1 && a/a1==c/c1) {
    return true;
  }
  
return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
 double a1=t1.DajStranicu(1);
  double b1=t1.DajStranicu(2);
  double c1=t1.DajStranicu(3);
  double a2=t2.DajStranicu(1);
  double b2=t2.DajStranicu(2);
  double c2=t2.DajStranicu(3);
  if(Trougao::JesuLiJednaki(a1,c2)==true && Trougao::JesuLiJednaki(b1,b2)==true && Trougao::JesuLiJednaki(c1,a2)==true && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1))) {
    return true;
  }
  else  if(Trougao::JesuLiJednaki(a1,a2)==true && Trougao::JesuLiJednaki(b1,b2)==true && Trougao::JesuLiJednaki(c1,c2)==true && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) {
    return true;
  }
  else if(Trougao::JesuLiJednaki(a1,a2)==true && Trougao::JesuLiJednaki(b1,c2)==true && Trougao::JesuLiJednaki(c1,b2)==true && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(3))) {
    return true;
  }
  else if(Trougao::JesuLiJednaki(a1,b2)==true && Trougao::JesuLiJednaki(b1,a2)==true && Trougao::JesuLiJednaki(c1,c2)==true && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3))) {
    return true;
  }
  else if(Trougao::JesuLiJednaki(a1,b2)==true && Trougao::JesuLiJednaki(b1,c2)==true && Trougao::JesuLiJednaki(c1,a2)==true && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1))) {
    return true;
  }
   else if(Trougao::JesuLiJednaki(a1,c2)==true && Trougao::JesuLiJednaki(b1,a2)==true && Trougao::JesuLiJednaki(c1,b2)==true && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2))) {
    return true;
  }
  else {
  return false;
  }
}
 

int main ()
{
    int n;
    Tacka A,B,C;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> trouglovi(n);
    double x1,y1,x2,y2,x3,y3;
    for(int i=0;i<n;i++) {
      std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
      std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
      A.first=x1; A.second=y1;
      B.first=x2; B.second=y2;
      C.first=x3; C.second=y3;
      try {
      trouglovi[i]=std::make_shared<Trougao>(Trougao(A,B,C));
      }
      catch(std::range_error e) {
        std::cout<<e.what() << ", ponovite unos!"<<std::endl;
        i--;
      }
    }
    Tacka T;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>T.first>>T.second;
    double alfa;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>alfa;
    double faktor_skaliranja;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor_skaliranja;
    std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[T] (std::shared_ptr<Trougao>t1) {
      t1->Transliraj(T.first,T.second);
      return t1;
    });
    std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[alfa](std::shared_ptr<Trougao>t1) {
      t1->Rotiraj(alfa);
      return t1;
    });
    std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[faktor_skaliranja](std::shared_ptr<Trougao>t1) {
      t1->Skaliraj(t1->DajTjeme(1),faktor_skaliranja);
      return t1;
    });
    std::sort(trouglovi.begin(),trouglovi.end(),[] (std::shared_ptr<Trougao>t1,std::shared_ptr<Trougao>t2) {
      return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(trouglovi.begin(),trouglovi.end(),[] (std::shared_ptr<Trougao>t) {
      t->Ispisi();
      std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    const double eps=1e-10;
    auto it=std::min_element(trouglovi.begin(),trouglovi.end(),[eps] (std::shared_ptr<Trougao>t1,std::shared_ptr<Trougao>t2) {
      //return t1->DajObim()<t2->DajObim();
      return std::fabs(t1->DajObim()-t2->DajObim())<eps;
      //return (t1->DajObim()>t2->DajObim() && !(std::fabs(t1->DajObim()-t2->DajObim())<=eps*(std::fabs(t1->DajObim())+std::fabs(t2->DajObim()))));
    });
    (*it)->Ispisi();
    std::cout<<std::endl;
    bool identicni(false);
    for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
        if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])) {
          std::cout<<"Parovi identicnih trouglova:"<<std::endl;
          trouglovi[i]->Ispisi();
          std::cout<<" i ";
          trouglovi[j]->Ispisi();
          std::cout<<std::endl;
          identicni=true;
        }
      }
    }
    if(identicni==false) {
      std::cout<<"Nema identicnih trouglova!"<<std::endl;
    }
       bool podudarni(false);
    for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
        if(DaLiSuPodudarni(*trouglovi[i],*trouglovi[j])) {
          podudarni=true;
          std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
          trouglovi[i]->Ispisi();
          std::cout<<" i ";
          trouglovi[j]->Ispisi();
          std::cout<<std::endl;
          
        }
      }
    }
    if(podudarni==false) {
      std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    }
    /*bool slicni(false);
    for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
        if(DaLiSuSlicni(*trouglovi[i],*trouglovi[j])) {
          std::cout<<"Parovi slicnih trouglova:"<<std::endl;
          trouglovi[i]->Ispisi();
          std::cout<<" i ";
          trouglovi[j]->Ispisi();
          std::cout<<std::endl;
          slicni=true;
        }
      }
    }
    if(slicni==false) {
      std::cout<<"Nema slicnih trouglova!";
    }*/
    
    
    
    
    
   
    
	return 0;
}