#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <memory>
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t1, t2, t3;
    double pomocna() const{
        return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) );
    }
    public:
 Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
     if(t1.first==t2.first && t2.first==t3.first && t1.first==t3.first) throw std::domain_error
     ("Nekorektne pozicije tjemena");
     else if(t1.second==t2.second && t2.second==t3.second && t1.second==t3.second)throw std::domain_error
     ("Nekorektne pozicije tjemena");
     Trougao::t1=t1;
     Trougao::t2=t2;
     Trougao::t3=t3;
 }
 void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      if( t1.first==t2.first && t2.first==t3.first && t1.first==t3.first) throw std::domain_error
     ("Nekorektne pozicije tjemena");
     else if(t1.second==t2.second && t2.second==t3.second && t1.second==t3.second)throw std::domain_error
     ("Nekorektne pozicije tjemena");
     else if(t1.first==t1.second && t2.first==t2.second && t3.first==t3.second) 
     throw std::domain_error("Nekorektne pozicije tjemena");
     Trougao::t1=t1;
     Trougao::t2=t2;
     Trougao::t3=t3;
 }
 void Postavi(int indeks, const Tacka &t){
     if((indeks==1 && t==t2 && t==t3) || (indeks==2 && t==t1 && t==t3) || (indeks==3 && t==t1 && t==t2) ) throw std::domain_error("Nekorektna pozicija tjemena");
     if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
     if(indeks==1) t1=t;
     else if(indeks==2) t2=t;
     else t3=t;
 }
 static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
     if( (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) )>0 ) return 1;
     else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) )<0 ) return -1;
     else return 0;
 }
 Tacka DajTjeme(int indeks) const{
     if(indeks==1) return t1;
     else if(indeks==2) return t2;
     else if(indeks==3) return t3;
     else throw std::range_error("Nekorektan indeks");
 }
 double DajStranicu(int indeks) const{
     if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
     if(indeks==1){
         double x(sqrt((t3.first-t2.first)*(t3.first-t2.first)+ (t3.second-t2.second)*(t3.second-t2.second)));
         return x;
     } else if(indeks==2){
       double x(sqrt((t3.first-t1.first)*(t3.first-t1.first)+ (t3.second-t1.second)*(t3.second-t1.second)));
         return x;  
     } else {
       double x(sqrt((t2.first-t1.first)*(t2.first-t1.first)+ (t2.second-t1.second)*(t2.second-t1.second)));
         return x;    
     }
 }
 double DajUgao(int indeks) const{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) {
        double x( (DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)- DajStranicu(1)*DajStranicu(1))/(2.*DajStranicu(2)*DajStranicu(3)));
    return x;
    }else if(indeks==2){
               double x( (DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)- DajStranicu(2)*DajStranicu(2))/(2.*DajStranicu(1)*DajStranicu(3)));
    return x; 
    } else{
        double x( (DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)- DajStranicu(3)*DajStranicu(3))/(2.*DajStranicu(1)*DajStranicu(2)));
    return x; 
    }
    
 }
 Tacka DajCentar() const{
     Tacka centar;
     centar.first=(t1.first+t2.first+t3.first)/3.;
     centar.second=(t1.second+t2.second+t3.second)/3.;
     return centar;
 }
 double DajObim() const{
     return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
 }
 double DajPovrsinu() const{
     double x=1/2.*abs(pomocna());
     return x;
 }
  bool DaLiJePozitivnoOrijentiran() const  {
      if(Orijentacija(t1,t2,t3)==1) return true;
      return false;
  }
  bool DaLiJeUnutra(const Tacka &t) const{
      if(Orijentacija(t1,t2,t3)==1 && Orijentacija(t1,t2,t)==1 && Orijentacija(t2,t3,t)==1 && Orijentacija(t3,t1,t)==1) return true;
      return false;
  }
  void Ispisi() const{
      std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<
      t3.first<<","<<t3.second<<"))";
  }
  void Transliraj(double delta_x, double delta_y){
      t1.first+=delta_x; t1.second+=delta_y;
       t2.first+=delta_x; t2.second+=delta_y;
        t3.first+=delta_x; t3.second+=delta_y;
  }
  void Centriraj(const Tacka &t){
      double x=t.first*3.;
      t1.first=x/3.;
      t2.first=x-t1.first;
      t3.first=x-t1.first-t2.first;
       double y=t.second*3.;
      t1.second=y/3.;
      t2.second=y-t1.second;
      t3.second=y-t1.second-t2.second;
  }
  void Rotiraj(const Tacka &t, double ugao){
      double x,y,a,b,c,d;
       x=(t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao));
       y=(t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao));
      t1.first=x;
      t1.second=y;
       a=(t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao));
       b=(t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao));
      t2.first=a;
      t2.second=b;
      c=(t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao));
     d=(t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao));
      t3.first=c;
      t3.second=d;
  }
  void Skaliraj(const Tacka &t, double faktor){
      if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
      double a,b,c,d,e,f;
       a=t.first+(faktor*(t1.first-t.first));
       b=t.second+(faktor*(t1.second-t.second));
      t1.first=a;
      t1.second=b;
       c=t.first+(faktor*(t2.first-t.first));
       d=t.second+(faktor*(t2.second-t.second));
      t2.first=c;
      t2.second=d;
       e=t.first+(faktor*(t3.first-t.first));
       f=t.second+(faktor*(t3.second-t.second));
      t3.first=e;
      t3.second=f;
  }
  void Rotiraj(double ugao){
  //    double a,b,c,d,e,f;
      Tacka haha(DajCentar());
      Rotiraj(haha,ugao);
/*     a=(haha.first+(t1.first-haha.first)*cos(ugao)-((t1.second-haha.second)*sin(ugao) ));
     b=(haha.second+(t1.first-haha.first)*sin(ugao)+(t1.second-haha.second)*cos(ugao));
      t1.first=a;
      t1.second=b;
      c=(haha.first+(t2.first-haha.first)*cos(ugao)-((t2.second-haha.second)*sin(ugao)) );
      d=(haha.second+(t2.first-haha.first)*sin(ugao)+(t2.second-haha.second)*cos(ugao));
      t2.first=c;
      t2.second=d;
       e=(haha.first+(t3.first-haha.first)*cos(ugao)- ((t3.second-haha.second)*sin(ugao)) );
       f=(haha.second+(t3.first-haha.first)*sin(ugao)+(t3.second-haha.second)*cos(ugao));
      t3.first=e;
      t3.second=f; 
      */
  }
  void Skaliraj(double faktor){
     if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
      double x,y;
       x=DajCentar().first+faktor*(t1.first-DajCentar().first);
       y=DajCentar().second+faktor*(t1.second-DajCentar().second);
      t1.first=x;
      t1.second=y;
       x=DajCentar().first+faktor*(t2.first-DajCentar().first);
       y=DajCentar().second+faktor*(t2.second-DajCentar().second);
      t2.first=x;
      t2.second=y;
       x=DajCentar().first+faktor*(t3.first-DajCentar().first);
       y=DajCentar().second+faktor*(t3.second-DajCentar().second);
      t3.first=x;
      t3.second=y; 
  }
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if( ((t1.t1.first==t2.t1.first && t1.t1.second==t2.t1.second) || (t1.t1.first==t2.t2.first &&  t1.t1.second==t2.t2.second) || ( t1.t1.first==t2.t3.first 
    && t1.t1.second==t2.t3.second) )
    && ( (t1.t2.first==t2.t1.first && t1.t2.second==t2.t1.second) || ( t1.t2.first==t2.t2.first && t1.t2.second==t2.t2.second  )
    || (t1.t2.first==t2.t3.first && t1.t2.second==t2.t3.second)) 
    && ( (t1.t3.first==t2.t1.first && t1.t3.second==t2.t1.second )|| (t1.t3.first==t2.t2.first && t1.t3.second==t2.t2.second )||
   ( t1.t3.first==t2.t3.first && t1.t3.second==t2.t3.second ))
    && t1.DajPovrsinu()==t2.DajPovrsinu()
    ) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
 bool da_li;
 if( (t1.DajStranicu(1)==t2.DajStranicu(1) || t1.DajStranicu(1)==t2.DajStranicu(2) ||
 t1.DajStranicu(1)==t2.DajStranicu(3)) && (t1.DajStranicu(2)==t2.DajStranicu(1) || 
 t1.DajStranicu(2)==t2.DajStranicu(2) || t1.DajStranicu(2)==t2.DajStranicu(3)) &&
 (t1.DajStranicu(3)==t2.DajStranicu(1) || t1.DajStranicu(3)==t2.DajStranicu(2) ||
 t1.DajStranicu(3)==t2.DajStranicu(3))) da_li=true;
 else da_li=false;
  Tacka niz1[3];
 Tacka niz2[3];
 if(da_li==true){
  niz1[0]=t1.t1;
  niz1[1]=t1.t2;
  niz1[2]=t1.t3;
 niz2[0]=t2.t1;
  niz2[1]=t2.t2;
  niz2[2]=t2.t3;
  std::sort(niz1, niz1+3, [t1,niz1](Tacka a, Tacka b) {
   int indeks1(0);
   int indeks2(0);
   if(a==niz1[0]) indeks1=1;
   else if(a==niz1[1]) indeks1=2;
   else if(a==niz1[2]) indeks1=3;
   if(b==niz1[0]) indeks2=1;
   else if(b==niz1[1]) indeks2=2;
   else if(b==niz1[2]) indeks2=3;
   if(t1.DajStranicu(indeks1)<=t1.DajStranicu(indeks2)) return true;
   return false;
  });
  std::sort(niz2, niz2+3, [t2,niz2](Tacka a, Tacka b) {
  int indeks1;
   int indeks2;
   if(a==niz2[0]) indeks1=1;
   else if(a==niz2[1]) indeks1=2;
   else if(a==niz2[2]) indeks1=3;
   if(b==niz2[0]) indeks2=1;
   else if(b==niz2[1]) indeks2=2;
   else if(b==niz2[2]) indeks2=3;
   if(t2.DajStranicu(indeks1)<=t2.DajStranicu(indeks2)) return true;
   return false;
  });
 
 if(Trougao::Orijentacija(niz1[0],niz1[1],niz1[2])==Trougao::Orijentacija(niz2[0],niz2[1],niz2[2])) return true;
 else return false;
}
return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
 int niza[3];
 int nizb[3];
 niza[0]=t1.DajStranicu(1);
  niza[1]=t1.DajStranicu(2);
  niza[2]=t1.DajStranicu(3);
 nizb[0]=t2.DajStranicu(1);
  nizb[1]=t2.DajStranicu(2);
  nizb[2]=t2.DajStranicu(3);
  std::sort(niza,niza+3);
  std::sort(nizb,nizb+3);
  bool da_li;
  if(niza[0]%nizb[0]==0 && niza[1]%nizb[1]==0 && niza[2]%nizb[2]==0 ) da_li=true;
  else da_li=false;
   Tacka niz1[3];
 Tacka niz2[3];
 if(da_li==true){
  niz1[0]=t1.t1;
  niz1[1]=t1.t2;
  niz1[2]=t1.t3;
 niz2[0]=t2.t1;
  niz2[1]=t2.t2;
  niz2[2]=t2.t3;
  std::sort(niz1, niz1+3, [t1,niz1](Tacka a, Tacka b)->bool {
   int indeks1(0);
   int indeks2(0);
   if(a==niz1[0]) indeks1=1;
   else if(a==niz1[1]) indeks1=2;
   else if(a==niz1[2]) indeks1=3;
   if(b==niz1[0]) indeks2=1;
   else if(b==niz1[1]) indeks2=2;
   else if(b==niz1[2]) indeks2=3;
   if(t1.DajStranicu(indeks1)<=t1.DajStranicu(indeks2)) return true;
   return false;
  });
  std::sort(niz2, niz2+3, [t2,niz2](Tacka a, Tacka b) {
  int indeks1;
   int indeks2;
   if(a==niz2[0]) indeks1=1;
   else if(a==niz2[1]) indeks1=2;
   else if(a==niz2[2]) indeks1=3;
   if(b==niz2[0]) indeks2=1;
   else if(b==niz2[1]) indeks2=2;
   else if(b==niz2[2]) indeks2=3;
   if(t2.DajStranicu(indeks1)<=t2.DajStranicu(indeks2)) return true;
   return false;
  });
 
 if(Trougao::Orijentacija(niz1[0],niz1[1],niz1[2])==Trougao::Orijentacija(niz2[0],niz2[1],niz2[2])) return true;
 else return false;
}
return false;

}
int main ()
{
 
Tacka t1,t2,t3;
 double a,b,c,d,e,f;
 int n;
 std::cout<<"Koliko zelite kreirati trouglova: ";
 std::cin>>n;
 std::vector<std::shared_ptr<Trougao>> trokutovi(n);
 for(int i=0; i<n; i++){
  pocetak:
  std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
  std::cin>>a;
  std::cin>>b;
  std::cin>>c;
  std::cin>>d;
  std::cin>>e;
  std::cin>>f;
  t1.first=a;
  t1.second=b;
  t2.first=c;
  t2.second=d;
  t3.first=e;
  t3.second=f;
 try{
  Trougao tr(t1,t2,t3);
  tr.Postavi(t1,t2,t3);
  trokutovi[i]=std::make_shared<Trougao>(tr);
 }catch(std::domain_error izuzetak){
 std::cout<<izuzetak.what()<<", ponovite unos!"<<std::endl;
   goto pocetak;
 }
  
  
 }
 std::cout<<"Unesite vektor translacije (dx dy): ";
 double dx,dy;
 std::cin>>dx;
 std::cin>>dy;
 std::cout<<"Unesite ugao rotacije: ";
 double ugao;
 std::cin>>ugao;
 std::cout<<"Unesite faktor skaliranja: ";
 double faktor;
 std::cin>>faktor;
 std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
 std::transform(trokutovi.begin(), trokutovi.end(), trokutovi.begin(), [dx,dy,faktor,ugao] (std::shared_ptr<Trougao> v){
  v->Transliraj(dx,dy);
  Tacka t=v->DajTjeme(1);
  v->Rotiraj(ugao);
  v->Skaliraj(t,faktor);
  return v;
});
std::sort(trokutovi.begin(), trokutovi.end(), [] (std::shared_ptr<Trougao>v1,std::shared_ptr<Trougao>v2 )->bool {
 if(v1->DajPovrsinu()<v2->DajPovrsinu()) return true;
 return false;
});
std::for_each(trokutovi.begin(), trokutovi.end(), [] (std::shared_ptr<Trougao>v){
 v->Ispisi();
 std::cout<<std::endl;
});

auto it=std::min_element(trokutovi.begin(), trokutovi.end(), [] (std::shared_ptr<Trougao>v1,std::shared_ptr<Trougao>v2)->bool{
  if(v1->DajObim()<=v2->DajObim()) return true;
 return false;
});
std::cout<<"Trougao sa najmanjim obimom: ";
(**it).Ispisi();
std::cout<<std::endl;
std::vector<std::pair<Trougao, Trougao>> ident;
std::vector<std::pair<Trougao, Trougao>> podud;
std::vector<std::pair<Trougao, Trougao>> slicni;
for(int i=0; i<n-1; i++){
 for(int j=i+1; j<n; j++){
  if(DaLiSuIdenticni(*trokutovi[i],*trokutovi[j])==true){
  ident.push_back(std::make_pair(*trokutovi[i],*trokutovi[j]));
  }
  if(DaLiSuPodudarni(*trokutovi[i],*trokutovi[j])==true){
  podud.push_back(std::make_pair(*trokutovi[i],*trokutovi[j]));
  }
  if(DaLiSuSlicni(*trokutovi[i],*trokutovi[j])==true) {
   slicni.push_back(std::make_pair(*trokutovi[i],*trokutovi[j]));
  }
  }
 
}
if(ident.size()==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
if(ident.size()!=0){
std::cout<<"Parovi identicnih trouglova:"<<std::endl;
for(int i=0; i<ident.size(); i++){
 ident[i].first.Ispisi();
std::cout<<" i ";
ident[i].second.Ispisi();
std::cout<<std::endl;
}
}
if(podud.size()==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
if(podud.size()!=0){
std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
for(int i=0; i<podud.size(); i++){
podud[i].first.Ispisi();
std::cout<<" i ";
podud[i].second.Ispisi();
std::cout<<std::endl;
}
}
if(slicni.size()==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
if(slicni.size()!=0){
std::cout<<"Parovi slicnih trouglova:"<<std::endl;
for(int i=0; i<slicni.size(); i++){
slicni[i].first.Ispisi();
std::cout<<" i ";
slicni[i].second.Ispisi();
std::cout<<std::endl;
}
}

	return 0;
}