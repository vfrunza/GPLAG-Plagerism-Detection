/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#define EPS 0.0000000001
typedef std::pair<double,double> Tacka;

class Trougao {
  Tacka a,b,c;  
  public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      if(Orjentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
      a=t1;
      b=t2;
      c=t3;
  }
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      if(Orjentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
      a=t1;
      b=t2;
      c=t3; 
  }
  void Postavi(int indeks, const Tacka &t){
      if(indeks>3 || indeks<1) throw std::range_error ("Nekorektan indeks");
      if(indeks==1) a=t;
      if(indeks==2) b=t;
      if(indeks==3) c=t;
      if(Orjentacija(a,b,c)==0) throw std::domain_error("Nekorektne pozicije tjemena");
  }
  static int Orjentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0) return 1;
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0) return -1;
    if(abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<EPS) {
      return 0;}
  }
  Tacka DajTjeme(int indeks) const{
    if(indeks>3 || indeks<1) throw std::range_error ("Nekorektan indeks");
    if(indeks==1) return a;
    if(indeks==2) return b;
    if(indeks==3) return c;
  }
  double DajStranicu(int indeks) const{
  if(indeks>3 || indeks<1) throw std::range_error ("Nekorektan indeks");
  if(indeks==1)   return sqrt((c.first-b.first)*(c.first-b.first)+(c.second-b.second)*(c.second-b.second)); 
  if(indeks==2)   return sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
  if(indeks==3)   return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
  }
  double DajUgao(int indeks) const{
  if(indeks>3 || indeks<1) throw std::range_error ("Nekorektan indeks");
  if(indeks==1) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
  if(indeks==2) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
  if(indeks==3) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(2)*DajStranicu(1)));
  }
  Tacka DajCentar() const {
    double x=(a.first+b.first+c.first)/3; 
    double y=(a.second+b.second+c.second)/3;
    Tacka t=std::make_pair(x,y);
    return t;
  }
  double DajObim() const {
    return(DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
  }
  double DajPovrsinu() const {
    return abs(a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second))/2;
  }
  bool DaLiJePozitivnoOrijentiran() const{
    if(Orjentacija(a,b,c)>0) return true;
    return false;
  }
  bool DaLiJeUnutra(const Tacka &t) const {
    if(Orjentacija(a,b,c)>0 && Orjentacija(a,b,t)>0 && Orjentacija(b,c,t)>0 && Orjentacija(c,a,t)>0) return true;
    if(Orjentacija(a,b,c)<0 && Orjentacija(a,b,t)<0 && Orjentacija(b,c,t)<0 && Orjentacija(c,a,t)<0) return true;
    return false;
  }
  void Ispisi() const {
    std::cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
  }
  void Transliraj(double delta_x, double delta_y){
    a.first+=delta_x;
    a.second+=delta_y;
    b.first+=delta_x;
    b.second+=delta_y;
    c.first+=delta_x;
    c.second+=delta_y;
  }
  void Centriraj(const Tacka &t){
    Transliraj((t.first-a.first-b.first-c.first)/3,(t.second-a.second-b.second-c.second)/3);
  }
  void Rotiraj(const Tacka &t, double ugao){
    double x1=(t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao));
    double x2=(t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao));
    double y1=(t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao));
    double y2=(t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao));
    double z1=(t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao));
    double z2=(t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao));
    Postavi(1,std::make_pair(x1,x2));
    Postavi(2,std::make_pair(y1,y2));
    Postavi(3,std::make_pair(z1,z2));
  }
  void Skaliraj(const Tacka &t,double faktor){
    if(faktor<EPS ) throw std::domain_error("Nekorektan faktor skaliranja");
    a.first=t.first+faktor*(a.first-t.first);
    a.second=t.second+faktor*(a.second-t.second);
    b.first=t.first+faktor*(b.first-t.first);
    b.second=t.second+faktor*(b.second-t.second);
    c.first=t.first+faktor*(c.first-t.first);
    c.second=t.second+faktor*(c.second-t.second);
  }
  void Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao); 
  }
  void Skaliraj(double faktor){
  
    Skaliraj(DajCentar(),faktor);
  }
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
  if(((abs(t1.a.first-t2.a.first)<EPS && abs(t1.a.second-t2.a.second)<EPS)||(abs(t1.a.first-t2.b.first)<EPS && abs(t1.a.second-t2.b.second)<EPS )||(abs(t1.a.first-t2.c.first)<EPS && abs(t1.a.second-t2.c.second)<EPS )) && 
  ((abs(t1.b.first-t2.a.first)<EPS && abs(t1.b.second-t2.a.second)<EPS)|| (abs(t1.b.first-t2.b.first)<EPS && abs(t1.b.second-t2.b.second)<EPS)|| (abs(t1.b.first-t2.c.first)<EPS && abs(t1.b.second-t2.c.second)<EPS )) &&
  ((abs(t1.c.first-t2.a.first)<EPS && abs(t1.c.second-t2.a.second)<EPS )||(abs(t1.c.first-t2.b.first)<EPS && abs(t1.c.second-t2.b.second)<EPS)||(abs(t1.c.first-t2.c.first)<EPS && abs(t1.c.second-t2.c.second)<EPS))) return true;
  return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
  Tacka a=t1.DajTjeme(1);
  Tacka b=t1.DajTjeme(2);
  Tacka c=t1.DajTjeme(3);
  Tacka d=t2.DajTjeme(1);
  Tacka e=t2.DajTjeme(2);
  Tacka f=t2.DajTjeme(3);
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(d,e,f))  && 
  abs(t1.DajStranicu(1)-t2.DajStranicu(1))<EPS && abs(t1.DajStranicu(2)-t2.DajStranicu(2))<EPS && abs(t1.DajStranicu(3)-t2.DajStranicu(3))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(e,d,f))  && 
  abs(t1.DajStranicu(1)-t2.DajStranicu(2))<EPS && abs(t1.DajStranicu(2)-t2.DajStranicu(1))<EPS && abs(t1.DajStranicu(3)-t2.DajStranicu(3))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(e,f,d))  && 
  abs(t1.DajStranicu(1)-t2.DajStranicu(2))<EPS && abs(t1.DajStranicu(2)-t2.DajStranicu(3))<EPS && abs(t1.DajStranicu(3)-t2.DajStranicu(1))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(f,e,d))  && 
  abs(t1.DajStranicu(1)-t2.DajStranicu(3))<EPS && abs(t1.DajStranicu(2)-t2.DajStranicu(2))<EPS && abs(t1.DajStranicu(3)-t2.DajStranicu(1))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(f,d,e))  && 
  abs(t1.DajStranicu(1)-t2.DajStranicu(3))<EPS && abs(t1.DajStranicu(2)-t2.DajStranicu(1))<EPS && abs(t1.DajStranicu(3)-t2.DajStranicu(2))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(d,f,e))  && 
  abs(t1.DajStranicu(1)-t2.DajStranicu(1))<EPS && abs(t1.DajStranicu(2)-t2.DajStranicu(3))<EPS && abs(t1.DajStranicu(3)-t2.DajStranicu(2))<EPS)  return true;
  return false;
  
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
  Tacka a=t1.DajTjeme(1);
  Tacka b=t1.DajTjeme(2);
  Tacka c=t1.DajTjeme(3);
  Tacka d=t2.DajTjeme(1);
  Tacka e=t2.DajTjeme(2);
  Tacka f=t2.DajTjeme(3);

  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(d,e,f))  && DaLiSuPodudarni(t1,t2) &&
  abs(t1.DajUgao(1)-t2.DajUgao(1))<EPS && abs(t1.DajUgao(2)-t2.DajUgao(2))<EPS && abs(t1.DajUgao(3)-t2.DajUgao(3))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(e,d,f))  && DaLiSuPodudarni(t1,t2) && 
  abs(t1.DajUgao(1)-t2.DajUgao(2))<EPS && abs(t1.DajUgao(2)-t2.DajUgao(1))<EPS && abs(t1.DajUgao(3)-t2.DajUgao(3))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(e,f,d))  &&  DaLiSuPodudarni(t1,t2) &&
  abs(t1.DajUgao(1)-t2.DajUgao(2))<EPS && abs(t1.DajUgao(2)-t2.DajUgao(3))<EPS && abs(t1.DajUgao(3)-t2.DajUgao(1))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(f,e,d))  &&  DaLiSuPodudarni(t1,t2) &&
  abs(t1.DajUgao(1)-t2.DajUgao(3))<EPS && abs(t1.DajUgao(2)-t2.DajUgao(2))<EPS && abs(t1.DajUgao(3)-t2.DajUgao(1))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(f,d,e))  && DaLiSuPodudarni(t1,t2) &&
  abs(t1.DajUgao(1)-t2.DajUgao(3))<EPS && abs(t1.DajUgao(2)-t2.DajUgao(1))<EPS && abs(t1.DajUgao(3)-t2.DajUgao(2))<EPS)  return true;
  if((Trougao::Orjentacija(a,b,c)==Trougao::Orjentacija(d,f,e))  &&  DaLiSuPodudarni(t1,t2) &&
  abs(t1.DajUgao(1)-t2.DajUgao(1))<EPS && abs(t1.DajUgao(2)-t2.DajUgao(3))<EPS && abs(t1.DajUgao(3)-t2.DajUgao(2))<EPS)  return true;
  return false;
  
}
  

int main ()
{
  int n{};
  
  std::cout<<"Koliko zelite kreirati trouglova: ";
  std::cin>>n;
  std::vector<std::shared_ptr<Trougao> > v(n);
  for(int i = 0; i < n; i++){
    int x1{},x2{},x3{},y1{},y2{},y3{};
    std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
    try{
    v[i] = std::make_shared<Trougao>(Tacka(x1,y1),Tacka(x2,y2),Tacka(x3,y3));
    }
    catch(std::domain_error e){
      i--;
      std::cout<<e.what()<<", ponovite unos!"<<std::endl;
    }
  }
  double dx{},dy{};
  std::cout<<"Unesite vektor translacije (dx dy): ";
  std::cin>>dx>>dy;
  std::transform(v.begin(), v.end(), v.begin(), [dx,dy](std::shared_ptr<Trougao> t){ t->Transliraj(dx,dy); return t;});
  double ugao{};
  std::cout<<"Unesite ugao rotacije: ";
  std::cin>>ugao;
  std::transform(v.begin(), v.end(), v.begin(), [ugao](std::shared_ptr<Trougao> t){ t->Rotiraj(ugao); return t;});
  
	double faktor{};
	std::cout<<"Unesite faktor skaliranja: ";
	std::cin>>faktor;
	std::transform(v.begin(),v.end(),v.begin(), [faktor](std::shared_ptr<Trougao> t){ t->Skaliraj(t->DajTjeme(1),faktor); return t; });
	
	std::sort(v.begin(),v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
	  return (t1->DajPovrsinu() < t2->DajPovrsinu());
	});

	std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
	std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){ t->Ispisi(); std::cout << std::endl; });
	std::cout<<"Trougao sa najmanjim obimom: ";
	(*std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){     
	  return (t1->DajObim() < t2->DajObim());
	}))->Ispisi();
	std::cout<<std::endl;
	

	std::vector<std::pair<Trougao,Trougao>> s ;
	for(int i=0;i<n;i++){
	  for(int j=i+1;j<n;j++){
	    if(DaLiSuIdenticni(*v[i],*v[j])) s.push_back(std::make_pair(*v[i],*v[j]));
	    }
	}
		if(s.size()==0){
	  std::cout<<"Nema identicnih trouglova!"<<std::endl;
	} else 	std::cout<<"Parovi identicnih trouglova: "<<std::endl;
	for(auto x: s) {x.first.Ispisi();std::cout<<" i ";x.second.Ispisi();std::cout<<std::endl;}
		std::vector<std::pair<Trougao,Trougao>> p ;

	for(int i=0;i<n;i++){
	  for(int j=i+1;j<n;j++){
	    if(DaLiSuPodudarni(*v[i],*v[j])) p.push_back(std::make_pair(*v[i],*v[j]));
	    }
	}
		if(p.size()==0){
	  std::cout<<"Nema podudarnih trouglova!"<<std::endl;
	 
	} else 	std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
	for(auto x: p) {x.first.Ispisi();std::cout<<" i ";x.second.Ispisi();std::cout<<std::endl;}
	std::vector<std::pair<Trougao,Trougao>> k ;

	for(int i=0;i<n;i++){
	  for(int j=i+1;j<n;j++){
	    if(DaLiSuSlicni(*v[i],*v[j])) k.push_back(std::make_pair(*v[i],*v[j]));
	    }
	}
	if(k.size()==0){
	  std::cout<<"Nema slicnih trouglova!"<<std::endl;

	} else 	std::cout<<"Parovi slicnih trouglova: "<<std::endl;
	for(auto x: k) {x.first.Ispisi();std::cout<<" i ";x.second.Ispisi();std::cout<<std::endl;}
	return 0;
}