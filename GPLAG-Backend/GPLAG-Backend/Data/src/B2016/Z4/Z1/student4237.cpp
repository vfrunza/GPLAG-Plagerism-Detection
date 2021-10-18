#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;

class Trougao{
  Tacka tacke[3];
public: 
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);  
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
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
  if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
  Postavi(t1,t2,t3);
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
  if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
  tacke[0]=t1; tacke[1]=t2; tacke[2]=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
  if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
  tacke[indeks-1]=t;
  if(!Orijentacija(tacke[0],tacke[1],tacke[2])) throw std::domain_error("Nekorektne pozicije tjemena");
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
  double rez=t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);
  if(rez>0) return 1;
  if(std::fabs(rez)<1e-10) return 0;
  return -1;
}
Tacka Trougao::DajTjeme(int indeks) const{
  if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
  return tacke[indeks-1];   
}
double Trougao::DajStranicu(int indeks) const{
  if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
  if(indeks==1){
    return std::sqrt(std::pow(tacke[1].first-tacke[2].first,2) + std::pow(tacke[1].second-tacke[2].second,2));
  }
  if(indeks==2){
    return std::sqrt(std::pow(tacke[0].first-tacke[2].first,2) + std::pow(tacke[0].second-tacke[2].second,2));
  }
  else return std::sqrt(std::pow(tacke[0].first-tacke[1].first,2) + std::pow(tacke[0].second-tacke[1].second,2));
}
double Trougao::DajUgao(int indeks) const{
  if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
  if(indeks==1){
    return std::acos( (std::pow(DajStranicu(2),2) + std::pow(DajStranicu(3),2) - std::pow(DajStranicu(1),2)) / (2*DajStranicu(2)*DajStranicu(3)));
  }
  if(indeks==2){
    return std::acos( (std::pow(DajStranicu(1),2) + std::pow(DajStranicu(3),2) - std::pow(DajStranicu(2),2)) / (2*DajStranicu(1) * DajStranicu(3)));
  }
  return std::acos( (std::pow(DajStranicu(2),2) + std::pow(DajStranicu(1),2) - std::pow(DajStranicu(3),2)) / (2*DajStranicu(2)* DajStranicu(1)));
}
Tacka Trougao::DajCentar() const{
  Tacka c;
  c.first=(tacke[0].first +tacke[1].first+tacke[2].first)/3;
  c.second=(tacke[0].second +tacke[1].second+tacke[2].second)/3;
  return c;
}
double Trougao::DajObim() const{
  return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const{
  Tacka t1(tacke[0]);
  Tacka t2(tacke[1]);
  Tacka t3(tacke[2]);
  return (0.5)*std::fabs(t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second)); 
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
  if(Orijentacija(tacke[0], tacke[1], tacke[2])==1) return true;
  return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
  int niz[4];
  niz[0]=Orijentacija(tacke[0],tacke[1],tacke[2]);
  niz[1]=Orijentacija(tacke[0],tacke[1],t);
  niz[2]=Orijentacija(t,tacke[1],tacke[2]);
  niz[3]=Orijentacija(tacke[0],t,tacke[2]);
  for(int i=0; i<4; i++)
      if(niz[i]!=niz[0])
          return false;
  return true;
}  
void Trougao::Ispisi() const{
  std::cout <<"(("<<tacke[0].first <<","<< tacke[0].second<<"),("<<tacke[1].first<<","<< tacke[1].second <<"),("<<tacke[2].first <<","<<tacke[2].second<<"))";
}
void Trougao::Transliraj(double delta_x, double delta_y){
  tacke[0].first+=delta_x;
  tacke[1].first+=delta_x;
  tacke[2].first+=delta_x;
  tacke[0].second+=delta_y;
  tacke[1].second+=delta_y;
  tacke[2].second+=delta_y;
}  
void Trougao::Centriraj(const Tacka &t){
  double delta_x=t.first-this->DajCentar().first;
  double delta_y=t.second-this->DajCentar().second;
  Transliraj(delta_x,delta_y);
}  
void Trougao::Rotiraj(const Tacka &t, double ugao){
  auto x1=t.first+(tacke[0].first-t.first)*std::cos(ugao)-(tacke[0].second-t.second)*std::sin(ugao);
  auto x2=t.first+(tacke[1].first-t.first)*std::cos(ugao)-(tacke[1].second-t.second)*std::sin(ugao);
  auto x3=t.first+(tacke[2].first-t.first)*std::cos(ugao)-(tacke[2].second-t.second)*std::sin(ugao);
  tacke[0].second=t.second+(tacke[0].first-t.first)*std::sin(ugao)+(tacke[0].second-t.second)*std::cos(ugao);
  tacke[1].second=t.second+(tacke[1].first-t.first)*std::sin(ugao)+(tacke[1].second-t.second)*std::cos(ugao);
  tacke[2].second=t.second+(tacke[2].first-t.first)*std::sin(ugao)+(tacke[2].second-t.second)*std::cos(ugao);
  tacke[0].first=x1;tacke[1].first=x2;tacke[2].first=x3;
} 
void Trougao::Skaliraj(const Tacka &t, double faktor){
  if(std::fabs(faktor)<1e-10) throw std::domain_error("Nekorektan faktor skaliranja");
  tacke[0].first=t.first+(tacke[0].first-t.first)*faktor;
  tacke[1].first=t.first+(tacke[1].first-t.first)*faktor;
  tacke[2].first=t.first+(tacke[2].first-t.first)*faktor;
  tacke[0].second=t.second+(tacke[0].second-t.second)*faktor;
  tacke[1].second=t.second+(tacke[1].second-t.second)*faktor;
  tacke[2].second=t.second+(tacke[2].second-t.second)*faktor;
}  
void Trougao::Rotiraj(double ugao){
  Rotiraj(DajCentar(),ugao);
}  
void Trougao::Skaliraj(double faktor){
  Skaliraj(DajCentar(),faktor);
}  
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
  std::vector<double> v1x{t1.tacke[0].first,t1.tacke[1].first,t1.tacke[2].first};
  std::vector<double> v1y{t1.tacke[0].second,t1.tacke[1].second,t1.tacke[2].second};
  std::vector<double> v2x{t2.tacke[0].first,t2.tacke[1].first,t2.tacke[2].first};
  std::vector<double> v2y{t2.tacke[0].second,t2.tacke[1].second,t2.tacke[2].second};
  std::sort(v1x.begin(),v1x.end());
  std::sort(v1y.begin(),v1y.end());
  std::sort(v2x.begin(),v2x.end());
  std::sort(v2y.begin(),v2y.end());
  return v1x==v2x && v1y==v2y;   
}  
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
  double a=t1.DajStranicu(1), b=t1.DajStranicu(2),c=t1.DajStranicu(3);
  auto o(t1.Orijentacija(t1.tacke[0],t1.tacke[1],t1.tacke[2]));
  double ep(1e-10);
  if( t2.Orijentacija(t2.tacke[0],t2.tacke[1],t2.tacke[2])==o && std::fabs(t2.DajStranicu(1)-a)<ep && std::fabs(t2.DajStranicu(2)-b)<ep && std::fabs(t2.DajStranicu(3)-c)<ep) return true;
  if( t2.Orijentacija(t2.tacke[0],t2.tacke[2],t2.tacke[1])==o && std::fabs(t2.DajStranicu(1)-a)<ep && std::fabs(t2.DajStranicu(3)-b)<ep && std::fabs(t2.DajStranicu(2)-c)<ep) return true;
  if( t2.Orijentacija(t2.tacke[1],t2.tacke[0],t2.tacke[2])==o && std::fabs(t2.DajStranicu(2)-a)<ep && std::fabs(t2.DajStranicu(1)-b)<ep && std::fabs(t2.DajStranicu(3)-c)<ep) return true;
  if( t2.Orijentacija(t2.tacke[1],t2.tacke[2],t2.tacke[0])==o && std::fabs(t2.DajStranicu(2)-a)<ep && std::fabs(t2.DajStranicu(3)-b)<ep && std::fabs(t2.DajStranicu(1)-c)<ep) return true;   
  if( t2.Orijentacija(t2.tacke[2],t2.tacke[1],t2.tacke[0])==o && std::fabs(t2.DajStranicu(3)-a)<ep && std::fabs(t2.DajStranicu(2)-b)<ep && std::fabs(t2.DajStranicu(1)-c)<ep) return true;
  if( t2.Orijentacija(t2.tacke[2],t2.tacke[0],t2.tacke[1])==o && std::fabs(t2.DajStranicu(3)-a)<ep && std::fabs(t2.DajStranicu(1)-b)<ep && std::fabs(t2.DajStranicu(2)-c)<ep) return true;
  return false;
}
bool Ok(double a, double a_2,double b, double b_2,double c, double c_2){
  double ep(1e-10);
   return (a/a_2 >= (b/b_2 - ep) && a/a_2 <= (b/b_2 + ep) && b/b_2 >= (c/c_2 - ep) && b/b_2 <= (c/c_2 + ep));
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
  double a=t1.DajStranicu(1), b=t1.DajStranicu(2),c=t1.DajStranicu(3);
  auto o(t1.Orijentacija(t1.tacke[0],t1.tacke[1],t1.tacke[2]));
  if( t2.Orijentacija(t2.tacke[0],t2.tacke[1],t2.tacke[2])==o && Ok(t2.DajStranicu(1),a,t2.DajStranicu(2),b,t2.DajStranicu(3),c)) return true;
  if( t2.Orijentacija(t2.tacke[0],t2.tacke[2],t2.tacke[1])==o && Ok(t2.DajStranicu(1),a,t2.DajStranicu(3),b,t2.DajStranicu(2),c)) return true;
  if( t2.Orijentacija(t2.tacke[1],t2.tacke[0],t2.tacke[2])==o && Ok(t2.DajStranicu(2),a,t2.DajStranicu(1),b,t2.DajStranicu(3),c)) return true;
  if( t2.Orijentacija(t2.tacke[1],t2.tacke[2],t2.tacke[0])==o && Ok(t2.DajStranicu(2),a,t2.DajStranicu(3),b,t2.DajStranicu(1),c)) return true;   
  if( t2.Orijentacija(t2.tacke[2],t2.tacke[1],t2.tacke[0])==o && Ok(t2.DajStranicu(3),a,t2.DajStranicu(2),b,t2.DajStranicu(1),c)) return true;
  if( t2.Orijentacija(t2.tacke[2],t2.tacke[0],t2.tacke[1])==o && Ok(t2.DajStranicu(3),a,t2.DajStranicu(1),b,t2.DajStranicu(2),c)) return true;
  return false;
}
int main() {
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n; std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    std::vector<std::shared_ptr<Trougao>> v2(n);
    for(int i=0; i<n;i++){
      std::cout << "Unesite podatke za "<<1+i<<". trougao (x1 y1 x2 y2 x3 y3): ";
      double x1, y1, x2, y2, x3, y3;
      std::cin >>x1>> y1>> x2>> y2>> x3>> y3;
      Tacka t1(x1,y1),t2(x2,y2), t3(x3,y3);
      try{
        Trougao T(t1,t2,t3);
        v[i]=std::make_shared<Trougao>(T);
      }catch(std::domain_error e){
        std::cout <<e.what()<<", ponovite unos!"<< std::endl;
        i--;
      }
    } 
    double faktor, ugao;
    double dx,dy;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::transform(v.begin(), v.end(), v2.begin(), [ugao,faktor,dx,dy](std::shared_ptr<Trougao> p){
      p->Transliraj(dx,dy);
      p->Rotiraj(ugao);
      p->Skaliraj(p->DajTjeme(1),faktor);
      return p;
    });
    std::sort(v2.begin(), v2.end(),[](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
      return p1->DajPovrsinu()<p2->DajPovrsinu();
    });
    std::for_each(v2.begin(), v2.end(), [](std::shared_ptr<Trougao> p){p->Ispisi();std::cout << std::endl;});
    auto x(*std::min_element(v2.begin(),v2.end(),[](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
      return p1->DajObim()<p2->DajObim();
    }));
    std::cout <<"Trougao sa najmanjim obimom: ";(*x).Ispisi();std::cout  << std::endl;
    bool prvi(true);
    for(int i=0;i<n;i++){
      for(int j=i+1; j<n;j++){
        if(DaLiSuIdenticni(*v[i],*v[j])){
          if(prvi){
            std::cout << "Parovi identicnih trouglova: " << std::endl;
            prvi=false;
          }
          v[i]->Ispisi();
          std::cout << " i ";
          v[j]->Ispisi();
          std::cout << std::endl;
        }
      }
    }
    if(prvi) std::cout << "Nema identicnih trouglova!" << std::endl;
    bool prvi_1(true);
    for(int i=0;i<n;i++){
      for(int j=i+1; j<n;j++){
        if(DaLiSuPodudarni(*v[i],*v[j])){
          if(prvi_1){
            std::cout << "Parovi podudarnih trouglova: " << std::endl;
            prvi_1=false;
          }
          v[i]->Ispisi();
          std::cout << " i ";
          v[j]->Ispisi();
          std::cout << std::endl;
        }
      }
    }
    if(prvi_1) std::cout << "Nema podudarnih trouglova!" << std::endl;
    bool prvi_2(true);
    for(int i=0;i<n;i++){
      for(int j=i+1; j<n;j++){
        if(DaLiSuSlicni(*v[i],*v[j])){
          if(prvi_2){
            std::cout << "Parovi slicnih trouglova: " << std::endl;
            prvi_2=false;
          }
          v[i]->Ispisi();
          std::cout << " i ";
          v[j]->Ispisi();
          std::cout << std::endl;
        }
      }
    }
    if(prvi_2) std::cout << "Nema slicnih trouglova!" << std::endl;
    return 0;
}