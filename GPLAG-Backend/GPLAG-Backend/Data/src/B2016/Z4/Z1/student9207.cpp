/B 2016/2017, Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
typedef std::pair<double,double> Tacka;
class Trougao{
  static constexpr double  eps=1e-10;
  Tacka a,b,c;
  void Testindeksa(int indeks)const {if(indeks<0 || indeks>3)throw std::range_error("Nekorektan indeks");}
  static int test_orijentacije(Tacka t1, Tacka t2, Tacka t3);
  double Udaljenost_tacaka  (const Tacka &t1,const Tacka &t2)const ;
  static bool Isti(double x,double y);
  static bool Proporcionalne(double x1,double y1,double x2,double y2);
  Tacka Rotacija(const Tacka &t,const Tacka &r,double ugao);
  Tacka Skaliranje(const Tacka &t,const Tacka &r,double faktor);
  public:
  Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3);
  void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3);
  void Postavi(int indeks,const Tacka &t);
  static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
  Tacka DajTjeme(int indeks) const;
  double DajStranicu(int indeks)const;
  double DajUgao (int indeks) const;
  Tacka DajCentar() const;
  double DajObim() const;
  double DajPovrsinu() const;
  bool DaLiJePozitivnoOrijentiran() const;
  bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const;
  void Transliraj(double delta_x,double delta_y);
  void Centriraj(const Tacka &t);
  void Rotiraj(const Tacka &t,double ugao);
  void Skaliraj(const Tacka &t,double faktor);
  void Rotiraj(double ugao);
  void Skaliraj(double faktor);
  friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
  
};
bool Trougao::Isti(double x,double y){
return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
}
int Trougao::test_orijentacije(Tacka t1, Tacka t2, Tacka t3){
return(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
}

int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
  if(test_orijentacije(t1,t2,t3)==0)return 0;
  if(test_orijentacije(t1,t2,t3)>0) return 1;
  if(test_orijentacije(t1,t2,t3)<0) return -1;
  return 0;
}


Trougao::Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
  Postavi(t1,t2,t3);
}

void Trougao::Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
if(test_orijentacije(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");

  a.first=t1.first;a.second=t1.second;
  b.first=t2.first;b.second=t2.second;
  c.first=t3.first;c.second=t3.second;
}

void Trougao::Postavi(int indeks,const Tacka &t){
 Testindeksa(indeks);
 if(indeks==1)      Postavi(t,b,c);
 else if(indeks==2) Postavi(a,t,c);
 else if(indeks==3) Postavi(a,b,t);
}

Tacka Trougao::DajTjeme(int indeks)const {
  Testindeksa(indeks);
  if(indeks==1) return a;
  else if(indeks==2) return b;
  return c;
}

double Trougao::Udaljenost_tacaka (const Tacka &t1,const Tacka &t2)const{
return sqrt( ((t2.first-t1.first)*(t2.first-t1.first))+((t2.second-t1.second)*(t2.second-t1.second)));
}

double Trougao::DajStranicu(int indeks)const{
  Testindeksa(indeks);
  if(indeks==1) return Udaljenost_tacaka(b,c);
  else  if(indeks==2) return Udaljenost_tacaka(a,c);
  else return Udaljenost_tacaka(a,b);
}

double Trougao::DajUgao(int indeks)const{
  Testindeksa(indeks);
  double A(Udaljenost_tacaka(b,c));
  double B(Udaljenost_tacaka(a,c));
  double C(Udaljenost_tacaka(a,b));
  if(indeks ==1 ) return acos((C*C+B*B-A*A)*1./(2*C*B));
  else if(indeks==2) return acos((A*A+C*C-B*B)*1./(2*A*C));
  else return acos((A*A+B*B-C*C)*1./(2*A*B));
  
}

Tacka Trougao::DajCentar()const{
  return Tacka((a.first+b.first+c.first)/3. ,(a.second+b.second+c.second)/3.);
}

double Trougao::DajObim()const{
  return Udaljenost_tacaka(a,b)+Udaljenost_tacaka(a,c)+Udaljenost_tacaka(b,c);
}

double Trougao::DajPovrsinu()const{
  return double((std::abs(test_orijentacije(a,b,c)/2.))) ;
}

bool Trougao::DaLiJePozitivnoOrijentiran()const{
  if(Orijentacija(a,b,c)==1)return true;
  return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t)const{
  Trougao P(a,b,c);
  Trougao A(a,b,t);
  Trougao B(b,c,t);
  Trougao C(a,c,t);
  if(Isti( (A.DajPovrsinu()+B.DajPovrsinu()+C.DajPovrsinu()),P.DajPovrsinu() )) return true;
  return false;
}

void Trougao::Ispisi()const{
  std::cout<<"(("<<a.first<<","<<a.second<<"),"
  <<"("<<b.first<<","<<b.second<<"),"
  <<"("<<c.first<<","<<c.second<<"))";
}

void Trougao::Transliraj(double delta_x,double delta_y){
Postavi(Tacka(a.first+delta_x,a.second+delta_y),Tacka(b.first+delta_x,b.second+delta_y),Tacka(c.first+delta_x,c.second+delta_y));  
}

void Trougao::Centriraj(const Tacka &t){
  Trougao A(a,b,c);
  Tacka p=A.DajCentar();
  Transliraj(t.first-p.first,t.second-p.second);
}

Tacka Trougao::Rotacija(const Tacka &t,const Tacka &r,double ugao){
return(Tacka(r.first+(t.first-r.first)*(cos(ugao))-(t.second-r.second)*(sin(ugao)),r.second+(t.first-r.first)*(sin(ugao))+(t.second-r.second)*(cos(ugao))));  
}

void Trougao::Rotiraj(const Tacka &t,double ugao){
  
  Postavi(1,Rotacija(a,t,ugao));
  Postavi(2,Rotacija(b,t,ugao));
  Postavi(3,Rotacija(c,t,ugao));
 
}

void Trougao::Rotiraj(double ugao){
  Trougao A (a,b,c);
  Rotiraj(A.DajCentar(),ugao);
}

Tacka Trougao::Skaliranje(const Tacka &t,const Tacka &r,double faktor){
return (Tacka(r.first+faktor*(t.first-r.first),r.second+faktor*(t.second-r.second)));
}

void Trougao::Skaliraj(const Tacka &t,double faktor){
  if(Isti(faktor,0))throw std::domain_error ("Nekorektan faktor skaliranja");
  else if(Isti(t.first,a.first) && Isti(t.second,a.second)){ 
    Postavi(2,Skaliranje(b,t,faktor));
    Postavi(3,Skaliranje(c,t,faktor));
  }
  else if(Isti(t.first,b.first) && Isti(t.second,b.second)){
   Postavi(1,Skaliranje(a,t,faktor));
   Postavi(3,Skaliranje(c,t,faktor));
  }
  else if(Isti(t.first,c.first) && Isti(t.second,c.second)){
   Postavi(1,Skaliranje(a,t,faktor));
   Postavi(2,Skaliranje(b,t,faktor));
  }

}
void Trougao::Skaliraj(double faktor){
  Trougao A (a,b,c);
  Skaliraj(A.DajCentar(),faktor);
}

bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
  std::vector<double>x1{t1.a.first,t1.b.first,t1.c.first};
  std::vector<double>y1{t1.a.second,t1.b.second,t1.c.second};
  std::vector<double>x2{t2.a.first,t2.b.first,t2.c.first};
  std::vector<double>y2{t2.a.second,t2.b.second,t2.c.second};
  std::sort(x1.begin(),x1.end());
  std::sort(y1.begin(),y1.end());
  std::sort(x2.begin(),x2.end());
  std::sort(y2.begin(),y2.end());

 return (x1==x2 && y1==y2);
}
bool Trougao::Proporcionalne(double x1,double y1,double x2,double y2){
  std::vector<double>v1{x1,y1};
  std::vector<double>v2{x2,y2};
  std::sort(v1.begin(),v1.end());
  std::sort(v2.begin(),v2.end());
  double a(v1[0]/v2[0]);double b(v1[1]/v2[1]);
  return (Trougao::Isti(a,b));
  
}
bool DaLiSuPodudarni(const Trougao&t1,const Trougao &t2){
  if(Trougao::Isti(t1.DajStranicu(1),t2.DajStranicu(1))){
     if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(3)) && Trougao::Isti(t1.DajUgao(3),t2.DajUgao(2)) &&
        t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
     if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(2)) && Trougao::Isti(t1.DajUgao(3),t2.DajUgao(3))&&
        t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
  }
  else if(Trougao::Isti(t1.DajStranicu(1),t2.DajStranicu(2))){
          if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(1))&& Trougao::Isti(t1.DajUgao(3),t2.DajUgao(3))&&
             t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran())return true;
          if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(3)) && Trougao::Isti(t1.DajUgao(3),t2.DajUgao(1))&&
             t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
  }
    else if(Trougao::Isti(t1.DajStranicu(1),t2.DajStranicu(3))){
          if(Trougao::Isti(t1.DajUgao(3),t2.DajUgao(1))&&Trougao::Isti(t1.DajUgao(2),t2.DajUgao(2))&&
            t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
          if(Trougao::Isti(t1.DajUgao(3),t2.DajUgao(2))&& Trougao::Isti(t1.DajUgao(2),t2.DajUgao(1))&&
            t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
    }
  return false;
  }
  bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
   if(DaLiSuPodudarni(t1,t2)) return true;
   else if(Trougao::Isti(t1.DajStranicu(1),t2.DajStranicu(1))){
          if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(3))&&Trougao::Isti(t1.DajUgao(3),t2.DajUgao(2))&&
            t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
          if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(2))&& Trougao::Isti(t1.DajUgao(3),t2.DajUgao(3))&&
            t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
  }
  else if(Trougao::Proporcionalne(t1.DajStranicu(1),t1.DajStranicu(2),t2.DajStranicu(1),t2.DajStranicu(2))){
          if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(1))&&Trougao::Isti(t1.DajUgao(3),t2.DajUgao(3))&&
            t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
          if(Trougao::Isti(t1.DajUgao(2),t2.DajUgao(3))&& Trougao::Isti(t1.DajUgao(3),t2.DajUgao(1))&&
             t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;  
  }
  
  else if(Trougao::Proporcionalne(t1.DajStranicu(1),t1.DajStranicu(3),t2.DajStranicu(1),t2.DajStranicu(3))){
          if(Trougao::Isti(t1.DajUgao(3),t2.DajUgao(1))&&Trougao::Isti(t1.DajUgao(2),t2.DajUgao(2))&&
          t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
          if(Trougao::Isti(t1.DajUgao(3),t2.DajUgao(2))&&Trougao::Isti(t1.DajUgao(2),t2.DajUgao(1))&&
          t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
  }
  return false;
  }
  
  
int main(){
  int n;
  std::cout<<"Koliko zelite kreirati trouglova: ";
  std::cin>>n;
  std::vector<std::shared_ptr<Trougao>>Trouglovi;
  Tacka a,b,c;
  for(int i(0);i<n;i++){
  std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
  std::cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
  try{
    Trouglovi.emplace_back(std::make_shared<Trougao>(Trougao(a,b,c)));
  }
  catch(std::domain_error iz){
    std::cout<<iz.what()<<", ponovite unos!"<<std::endl;
    i--;
  }
}

  double delta_x,delta_y,ugao,faktor;
  std::cout<<"Unesite vektor translacije (dx dy): ";
  std::cin>>delta_x>>delta_y;
  std::cout<<"Unesite ugao rotacije: ";
  std::cin>>ugao;
  std::cout<<"Unesite faktor skaliranja: ";
  std::cin>>faktor;

try{
  std::transform(Trouglovi.begin(),Trouglovi.end(),Trouglovi.begin(),[delta_x,delta_y,ugao,faktor](std::shared_ptr<Trougao> t1){
  t1->Transliraj(delta_x,delta_y);
  t1->Rotiraj(t1->DajCentar(),ugao);
  t1->Skaliraj(t1->DajTjeme(1),faktor);
  return t1;});

std::sort(Trouglovi.begin(),Trouglovi.end(),[](std::shared_ptr<const Trougao>t1,std::shared_ptr<const Trougao>t2){
  return t1->DajPovrsinu() < t2->DajPovrsinu();});
 std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
 std::for_each(Trouglovi.begin(),Trouglovi.end(),[](std::shared_ptr<const Trougao>t){t->Ispisi();std::cout<<std::endl;});

auto p=std::min_element(Trouglovi.begin(),Trouglovi.end(),[](std::shared_ptr<const Trougao>t1,std::shared_ptr<const Trougao>t2){
   return (t1->DajObim() < t2->DajObim());}  );
 std::cout<<"Trougao sa najmanjim obimom: "; (*p)->Ispisi();
  std::cout<<std::endl;
 int identicnih(0);
  for(int i(0);i<n;i++){
    for(int j=i+1;j<n;j++) if(DaLiSuIdenticni(*Trouglovi[i],*Trouglovi[j]))identicnih++;
    }
  if(identicnih==0) std::cout<<"Nema identicnih trouglova!\n";
  else{
    std::cout<<"Parovi identicnih trouglova:\n";
    for(int i(0);i<n;i++){
      for(int j=i+1;j<n;j++){
        if(DaLiSuIdenticni(*Trouglovi[i],*Trouglovi[j])){
        Trouglovi[i]->Ispisi();std::cout<<" i "; Trouglovi[j]->Ispisi();
        std::cout<<std::endl;
        }
      }
    }
  } 
  int podudarnih(0);
  for(int i(0);i<n;i++){
    for(int j=i+1;j<n;j++) if(DaLiSuPodudarni(*Trouglovi[i],*Trouglovi[j])) podudarnih++;
  }
  if(podudarnih==0) std::cout<<"Nema podudarnih trouglova!\n";
  else{
    std::cout<<"Parovi podudarnih trouglova:\n";
    for(int i(0);i<n;i++){
      for(int j=i+1;j<n;j++){
        if(DaLiSuPodudarni(*Trouglovi[i],*Trouglovi[j])){
          Trouglovi[i]->Ispisi();std::cout<<" i ";Trouglovi[j]->Ispisi();
          std::cout<<std::endl;
        }
      }
    }
  }
  

 int slicnih(0);
 for(int i(0);i<n;i++){
   for(int j=i+1;j<n;j++)if(DaLiSuSlicni(*Trouglovi[i],*Trouglovi[j])) slicnih++;
 }
 if(slicnih==0) std::cout<<"Nema slicnih trouglova!\n";
else{
  std::cout<<"Parovi slicnih trouglova:\n";
  for(int i(0);i<n;i++){
    for(int j=i+1;j<n;j++){
      if(DaLiSuSlicni(*Trouglovi[i],*Trouglovi[j])){
        Trouglovi[i]->Ispisi();std::cout<<" i ";Trouglovi[j]->Ispisi();
        std::cout<<std::endl;
          }
        }
      }
    }
    

}
catch(std::domain_error iz){
  std::cout<<iz.what();
}
return 0;
}


