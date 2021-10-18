#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <set>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double,double> Tacka;

class Trougao{
  Tacka tjeme[3]{};
  
  static bool JesuLiJednaki(double x,double y,double Eps=1e-10){ return std::fabs(x-y)<=Eps*(std::fabs(x)*std::fabs(y));}
  static void TestIndeksa(int indeks){if(indeks!=1 and indeks!=2 and indeks!=3) throw std::range_error ("Nekorektan indeks");}
  static bool TestKolinearnosti(const Tacka &t1,const Tacka &t2,const Tacka &t3){ return (Orijentacija(t1,t2,t3)==0); }
  static void TestKolinearnostiIzuzetak(const Tacka &t1,const Tacka &t2,const Tacka &t3) {if(TestKolinearnosti(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");}
  Tacka RoracijaTacke(const Tacka& t,double ugao,int indeks){return {t.first+(tjeme[indeks].first-t.first)*std::cos(ugao)-(tjeme[indeks].second-t.second)*std::sin(ugao),t.second+(tjeme[indeks].first-t.first)*std::sin(ugao)+(tjeme[indeks].second-t.second)*std::cos(ugao)};}
  Tacka SkalirajTacku(const Tacka&t,double k,int indeks){return {t.first+k*(tjeme[indeks].first-t.first),t.second+k*(tjeme[indeks].second-t.second)};}
  static bool PoklapajuLiSe(const Tacka &t1,const Tacka &t2);
  
  public:
  Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){Postavi(t1,t2,t3); }
  void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){TestKolinearnostiIzuzetak(t1,t2,t3); tjeme[0]=t1; tjeme[1]=t2; tjeme[2]=t3;}
  void Postavi(int indeks,const Tacka &t);
  static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
  Tacka DajTjeme(int indeks) const{TestIndeksa(indeks); return tjeme[indeks-1];}
  double DajStranicu(int indeks) const;
  double DajUgao(int indeks) const;
  Tacka DajCentar() const;
  double DajObim() const;
  double DajPovrsinu() const;
  bool DaLiJePozitivnoOrijentiran() const{return Orijentacija(tjeme[0],tjeme[1],tjeme[2])==1;}
  bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const{std::cout<<"(("<<tjeme[0].first<<","<<tjeme[0].second<<"),("<<tjeme[1].first<<","<<tjeme[1].second<<"),("<<tjeme[2].first<<","<<tjeme[2].second<<"))";}
  void Transliraj(double delta_x,double delta_y);
  void Centriraj(const Tacka &t);
  void Rotiraj(const Tacka &t, double ugao);
  void Skaliraj(const Tacka &t, double faktor);
  void Rotiraj(double ugao){Rotiraj(DajCentar(),ugao);}
  void Skaliraj(double faktor){Skaliraj(DajCentar(),faktor);}
  friend bool DaLiSuIdenticni (const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuPodudarni (const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuSlicni (const Trougao &t1,const Trougao &t2);    
};

void Trougao::Postavi(int indeks, const Tacka &t){
  TestIndeksa(indeks);
  tjeme[indeks-1]=t;
  TestKolinearnostiIzuzetak(tjeme[0],tjeme[1],tjeme[2]);
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
  return t1.first*(t2.second - t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
}
double Trougao::DajStranicu(int indeks)const{
  TestIndeksa(indeks);
  std::set<int> pom{0,1,2};
  indeks--;
  pom.erase(indeks);
  auto it(pom.begin());
  return std::sqrt(std::pow(tjeme[*it++].first-tjeme[*it].first,2)+std::pow(tjeme[*it--].second-tjeme[*it].second,2));
}
double Trougao::DajUgao(int indeks)const{
  TestIndeksa(indeks);
  std::set<int> pom{0,1,2};
  indeks--;
  pom.erase(indeks);
  auto it(pom.begin());
  return std::acos( (std::pow(DajStranicu(*it++),2)+std::pow(DajStranicu(*it--),2)-DajStranicu(++indeks))/(2*DajStranicu(*it++)*DajStranicu(*it)) );
//  std::cout<<*it++<<*it--<<*it++<<*it;
//  return 2;
}
Tacka Trougao::DajCentar()const{
  return {(tjeme[0].first+tjeme[1].first+tjeme[2].first)/3,(tjeme[0].second+tjeme[1].second+tjeme[2].second)/3};
}
double Trougao::DajObim()const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu()const{
  return 1/2.*std::fabs(DajTjeme(1).first*(DajTjeme(2).second-DajTjeme(3).second)+DajTjeme(2).first*(DajTjeme(3).second-DajTjeme(1).second)+DajTjeme(3).first*(DajTjeme(1).second-DajTjeme(2).second));
}
bool Trougao::DaLiJeUnutra(const Tacka &t)const{
    return ((Orijentacija(tjeme[0],tjeme[1],tjeme[2])==1) and (Orijentacija(tjeme[0],tjeme[1],t)==1) and (Orijentacija(tjeme[1],tjeme[2],t)==1) and (Orijentacija(tjeme[2],tjeme[0],t)==1));
}
void Trougao::Transliraj(double delta_x,double delta_y){
  for(int i=0;i<3;i++)
  tjeme[i].first+=delta_x;
  for(int i=0;i<3;i++)
  tjeme[i].second+=delta_y;
}
void Trougao::Centriraj(const Tacka& t){
  for(;;){
    double as(DajCentar().first);
    if(JesuLiJednaki(t.first,as)) break;
    Transliraj(t.first-as,0);
  }
  for(;;){
    double as(DajCentar().second);
    if(JesuLiJednaki(t.second,as)) break;
    Transliraj(0,t.second-as);
  }
}
void Trougao::Rotiraj(const Tacka& t,double ugao){
  tjeme[0]=RoracijaTacke(t,ugao,0);
  tjeme[1]=RoracijaTacke(t,ugao,1);
  tjeme[2]=RoracijaTacke(t,ugao,2);
}
void Trougao::Skaliraj(const Tacka& t,double faktor){
  if(JesuLiJednaki(faktor,0.)) throw std::domain_error("Nekorektan faktor skaliranja");
  tjeme[0]=SkalirajTacku(t,faktor,0);
  tjeme[1]=SkalirajTacku(t,faktor,1);
  tjeme[2]=SkalirajTacku(t,faktor,2);
}
bool Trougao::PoklapajuLiSe(const Tacka &t1,const Tacka &t2){
  return (JesuLiJednaki(t1.first,t2.first) and JesuLiJednaki(t1.second,t2.second));
}
bool DaLiSuIdenticni (const Trougao &t1,const Trougao &t2){
  for(int i(0);;i++){
    if (i==3) return false;
    if(Trougao::PoklapajuLiSe(t1.tjeme[0],t2.tjeme[i])) break;
  }
  for(int i(0);;i++){
    if (i==3) return false;
    if(Trougao::PoklapajuLiSe(t1.tjeme[1],t2.tjeme[i])) break;
  }
  for(int i(0);;i++){
    if (i==3) return false;
    if(Trougao::PoklapajuLiSe(t1.tjeme[2],t2.tjeme[i])) break;
  }
  return true;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
 for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
      Trougao pomoc(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3));
      double omjer(t1.DajStranicu(i)/t2.DajStranicu(j));
      pomoc.Skaliraj(omjer);
      if(DaLiSuPodudarni(pomoc,t1)) return true;
    }
 }
 return false;
}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
  int i(1),j(1);
  for(; i<=3 ;i++){
      for(; j<=3; j++){
        if(Trougao::JesuLiJednaki(t1.DajStranicu(i),t2.DajStranicu(j))) goto izlaz;
        if(j==3) return false;
      }
   }
izlaz:
   i++;
   for(;i<=3; i++){
     if((Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))>0 and Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))>0) or (Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))<0 and Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))<0)){
        if(j==3) j=1;  
        else j++;
     }else{
       if(j==1) j=3;  
        else j--;
     }
     if(Trougao::JesuLiJednaki(t1.DajStranicu(i),t2.DajStranicu(j))) continue;
     return false;
   }
   return true;
}

int main (){                                                                // M A I N
	std::cout<<"Koliko zelite kreirati trouglova: ";
	int n;
	std::cin>>n;
	std::vector<std::shared_ptr<Trougao>> vek;
	for(int i=0; i<n; i++){
	  Tacka niz[3];
	  std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
	  for(int j=0; j<3; j++){
	    std::cin>>niz[j].first>>niz[j].second;
	  }
	 try{
	  auto p(std::make_shared<Trougao> (niz[0],niz[1],niz[2]));
	     vek.push_back(p);
	 }catch(std::domain_error izuza){
	   std::cout<<izuza.what()<<", ponovite unos!"<<std::endl;
	   i--;
	 }catch(std::bad_alloc izuza){
	   std::cout<<"Nema dovoljno memorije!";
	   return 0;
	 }
	}  
	std::cout<<"Unesite vektor translacije (dx dy): ";
	double delta_x,delta_y;
	std::cin>>delta_x>>delta_y;
	std::cout<<"Unesite ugao rotacije: ";
	double ugao;
	std::cin>>ugao;
	std::cout<<"Unesite faktor skaliranja: ";
	double faktor;
	std::cin>>faktor;
	std::transform(vek.begin(),vek.end(),vek.begin(),[delta_x,delta_y,ugao,faktor](std::shared_ptr<Trougao> x){ 
	    x->Transliraj(delta_x,delta_y);
	    x->Rotiraj(ugao);
	    x->Skaliraj(x->DajTjeme(1),faktor);
	    return x;
	});
	std::sort(vek.begin(),vek.end(),[](std::shared_ptr<Trougao> x,std::shared_ptr<Trougao> y){return x->DajPovrsinu()<y->DajPovrsinu();});
	std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
	std::for_each(vek.begin(),vek.end(),[](std::shared_ptr<Trougao> x){std::cout<<"(("<<x->DajTjeme(1).first<<","<<x->DajTjeme(1).second<<"),("<<x->DajTjeme(2).first<<","<<x->DajTjeme(2).second<<"),("<<x->DajTjeme(3).first<<","<<x->DajTjeme(3).second<<"))"<<std::endl;});
  std::cout<<"Trougao sa najmanjim obimom: ";
  (*std::min_element(vek.begin(),vek.end(),[](std::shared_ptr<Trougao> x,std::shared_ptr<Trougao> y){ return x->DajObim()<y->DajObim();}))->Ispisi();
  
  bool pomoc(true);
  for(int i=0; i<vek.size(); i++){
    for(int j=i+1; j<vek.size(); j++){
        if(DaLiSuIdenticni(*vek[i],*vek[j])){
          pomoc=false;
        }
    }
  }
  if(pomoc) std::cout<<std::endl<<"Nema identicnih trouglova!";
  else{
  pomoc=true;
  std::cout<<std::endl<<"Parovi identicnih trouglova:"<<std::endl;
  for(int i=0; i<vek.size(); i++){
    for(int j=i+1; j<vek.size(); j++){
        if(DaLiSuIdenticni(*vek[i],*vek[j])){
          vek[i]->Ispisi();
          std::cout<<" i ";
          vek[j]->Ispisi();
          std::cout<<std::endl;
        }
    }
  }
  }
  for(int i=0; i<vek.size(); i++){
    for(int j=i+1; j<vek.size(); j++){
        if(DaLiSuPodudarni(*vek[i],*vek[j])){
          pomoc=false;
        }
    }
  }if(pomoc) std::cout<<std::endl<<"Nema podudarnih trouglova!";
  else {pomoc=true;
  std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
  for(int i=0; i<vek.size(); i++){
    for(int j=i+1; j<vek.size(); j++){
        if(DaLiSuPodudarni(*vek[i],*vek[j])){
          vek[i]->Ispisi();
          std::cout<<" i ";
          vek[j]->Ispisi();
          std::cout<<std::endl;
        }    
    }
  }
  }
  
  
  for(int i=0; i<vek.size(); i++){
    for(int j=i+1; j<vek.size(); j++){
        if(DaLiSuSlicni(*vek[i],*vek[j])){
          pomoc=false;
        }
    }
  }
  if(pomoc) std::cout<<std::endl<<"Nema slicnih trouglova!"; 
  else{
  std::cout<<"Parovi slicnih trouglova:"<<std::endl;
  for(int i=0; i<vek.size(); i++){
    for(int j=i+1; j<vek.size(); j++){
        if(DaLiSuSlicni(*vek[i],*vek[j])){
          vek[i]->Ispisi();
          std::cout<<" i ";
          vek[j]->Ispisi();
          std::cout<<std::endl;
        }    
    }
  }
  }               
	return 0;     
}


