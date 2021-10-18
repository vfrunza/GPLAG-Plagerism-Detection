#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory>

typedef std::pair<double, double> Tacka;

class Trougao{
    
    Tacka t1,t2,t3;
    
  static  bool ValidnostIndeksa(int indeks){
    if(indeks==1||indeks==2||indeks==3)
    return false;
    else
    return true;
}

static std::vector<Tacka> VratiIndeksirano(Tacka t1,Tacka t2,Tacka t3){
    return std::vector<Tacka>{t1,t2,t3};
}
    
    static std::vector<int> Indeksi(){
        return std::vector<int>{1,2,3};
    }
    public:
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1,Trougao::t2=t2,Trougao::t3=t3;
    }
    
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1,Trougao::t2=t2,Trougao::t3=t3;
}

void Postavi(int indeks, const Tacka &t){
    if(ValidnostIndeksa(indeks))throw std::range_error("Nekorektan indeks");
    std::vector<Tacka> T{t1,t2,t3};
    T[indeks]=t;
    Postavi(T[0],T[1],T[2]);
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    auto orijentacija(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    if(orijentacija>0)return 1;
    else if(orijentacija<0)return -1;
    else return 0;
}

Tacka DajTjeme(int indeks) const{
    if(ValidnostIndeksa(indeks))throw std::range_error("Nekorektan indeks");
    return VratiIndeksirano(t1,t2,t3)[indeks-1];
}

double DajStranicu(int indeks) const{
    if(ValidnostIndeksa(indeks))throw std::range_error("Nekorektan indeks");
    std::vector<Tacka> v(VratiIndeksirano(t1,t2,t3));
    v.erase(v.begin()+indeks-1);
    return sqrt(pow(v[0].first-v[1].first,2)+pow(v[0].second-v[1].second,2));
}

double DajUgao(int indeks) const{
    if(ValidnostIndeksa(indeks))throw std::range_error("Nekorektan indeks");
    auto v(Indeksi());
    v.erase(v.begin()+indeks-1);
    return acos((pow(DajStranicu(indeks),2)-pow(DajStranicu(v[0]),2)-pow(DajStranicu(v[1]),2))/(2*DajStranicu(v[0])*DajStranicu(v[1])));
}

Tacka DajCentar() const{
    return {(t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3};
}

double DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double DajPovrsinu() const{
    return DajStranicu(3)*(DajUgao(1)*DajStranicu(3))/2;
}

bool DaLiJePozitivnoOrijentiran() const{
    return Orijentacija(t1,t2,t3);
}

bool DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(t1,t2,t3)>0&&Orijentacija(t1,t2,t)>0&&Orijentacija(t2,t3,t)>0&&Orijentacija(t3,t1,t)>0)
    return 1;
    else if(Orijentacija(t1,t2,t3)<0&&Orijentacija(t1,t2,t)<0&&Orijentacija(t2,t3,t)<0&&Orijentacija(t3,t1,t)<0)
    return 1;
    else
    return 0;
}

void Ispisi() const{
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),"<<"("<<t2.first<<","<<t2.second<<"),"<<"("<<t3.first<<","<<t3.second<<"))";
}

void Transliraj(double dx, double dy){
    Tacka T1,T2,T3;
    T1.first=t1.first+dx;T2.first=t2.first+dx;T3.first=t3.first+dx;
    T1.second=t1.second+dy;T2.second=t2.second+dy;T3.second=t3.second+dy;
    Postavi(T1,T2,T3);
}

void Centriraj(const Tacka &t){
    Tacka T(DajCentar());
    auto delta_x(T.first-t.first);
    auto delta_y(T.second-t.second);
    Transliraj(delta_x,delta_y);
}

void Rotiraj(const Tacka &t, double ugao){
    Tacka T1,T2,T3;
    T1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    T1.second=t.second+(t1.first-t.first)*sin(ugao)-(t1.second-t.second)*cos(ugao);
    T2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    T2.second=t.second+(t2.first-t.first)*sin(ugao)-(t2.second-t.second)*cos(ugao);
    T3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    T3.second=t.second+(t3.first-t.first)*sin(ugao)-(t3.second-t.second)*cos(ugao);
    Postavi(T1,T2,T3);
}

void Skaliraj(const Tacka &t, double faktor){
    if(faktor==0)throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka T1,T2,T3;
    T1.first=t.first+faktor*(t1.first-t.first);
    T1.second=t.second+faktor*(t1.second-t.second);
    T2.first=t.first+faktor*(t2.first-t.first);
    T2.second=t.second+faktor*(t2.second-t.second);
    T3.first=t.first+faktor*(t3.first-t.first);
    T3.second=t.second+faktor*(t3.second-t.second);
     Postavi(T1,T2,T3);
     
}

void Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}

void Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}

friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::vector<Tacka> v1{t1.t1,t1.t2,t1.t3};
    std::vector<Tacka> v2{t2.t1,t2.t2,t2.t3};
    for(int i=0;i<3;i++){
    auto p=find(v1.begin(),v1.end(),v2[i]);
    if(p!=v1.end()){
        p=v1.erase(p);
    }
    else return false;
    }
    return true;
}

friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<Tacka> v1{t1.t1,t1.t2,t1.t3};
    std::vector<Tacka> v2{t2.t1,t2.t2,t2.t3};
    std::vector<int>v5{1,2,3};
    std::vector<int>v6{1,2,3};
    std::vector<double> v3{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
    std::vector<double> v4{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
     sort(v5.begin(),v5.end(),[t1](int x,int y){
        if(t1.DajStranicu(x)>t1.DajStranicu(y))return true;
        else return false;
    });
    sort(v6.begin(),v6.end(),[t2](int x,int y){
        if(t2.DajStranicu(x)>t2.DajStranicu(y))return true;
        else return false;
    });
    if((t1.DajStranicu(v5[0])/t2.DajStranicu(v6[0])-t1.DajStranicu(v5[1])/t2.DajStranicu(v6[1]))<1e-10&&(t1.DajStranicu(v5[0])/t2.DajStranicu(v6[0])-t1.DajStranicu(v5[2])/t2.DajStranicu(v6[2]))<1e-10);
    else return false;
    if(count_if(v3.begin(),v3.end(),[v3](double x){
        if(count(v3.begin(),v3.end(),x)==1)return false;
        else return true;
    } )>0&&Orijentacija(t1.t1,t1.t2,t1.t3)==Orijentacija(t2.t1,t2.t2,t2.t3))return true;
    if((Orijentacija(v1[v5[0]-1],v1[v5[1]-1],v1[v5[2]-1]))==(Orijentacija(v2[v6[0]-1],v2[v6[1]-1],v2[v6[2]-1])))
    return true;
    else 
    return false;
}
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
     std::vector<Tacka> v1{t1.t1,t1.t2,t1.t3};
    std::vector<Tacka> v2{t2.t1,t2.t2,t2.t3};
    std::vector<int>v5{1,2,3};
    std::vector<int>v6{1,2,3};
    std::vector<double> v3{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
    std::vector<double> v4{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
       for(int i=0;i<3;i++){
    auto p=find(v3.begin(),v3.end(),v4[i]);
    if(p!=v3.end()){
       p=v3.erase(p);
    }
    else return false;
    }
    if(count_if(v3.begin(),v3.end(),[v3](double x){
        if(count(v3.begin(),v3.end(),x)==1)return false;
        else return true;
    } )>0&&Orijentacija(t1.t1,t1.t2,t1.t3)==Orijentacija(t2.t1,t2.t2,t2.t3))return true;
    sort(v5.begin(),v5.end(),[t1](int x,int y){
        if(t1.DajStranicu(x)>t1.DajStranicu(y))return true;
        else return false;
    });
    sort(v6.begin(),v6.end(),[t2](int x,int y){
        if(t2.DajStranicu(x)>t2.DajStranicu(y))return true;
        else return false;
    });
    if((Orijentacija(v1[v5[0]-1],v1[v5[1]-1],v1[v5[2]-1]))==(Orijentacija(v2[v6[0]-1],v2[v6[1]-1],v2[v6[2]-1])))
    return true;
    else 
    return false;
}
};

int main ()
{
  int n;
  std::pair<double,double> t1,t2,t3;
  std::cout<<"Koliko zelite kreirati trouglova: ";
  std::cin>>n;
  std::vector<std::shared_ptr <Trougao> > v(n);
  for(int i=0;i<n;i++){
      std::shared_ptr<Trougao> p;
      std::cout<<"Unesite podatke za "<<i+1<<"."<<" trougao (x1 y1 x2 y2 x3 y3): ";
      std::cin>>t1.first;
      std::cin>>t1.second;
      std::cin>>t2.first;
      std::cin>>t2.second;
      std::cin>>t3.first;
      std::cin>>t3.second;
      try{
      p=std::make_shared<Trougao>(t1,t2,t3);}
      catch(std::domain_error e){
          std::cout<<e.what()<<", ponovite unos!";
          i--;continue;
      }
      v[i]=p;
  }
  double dx,dy,ugao,faktor;
  std::cout<<"Unesite vektor translacije (dx dy): ";
  std::cin>>dx>>dy;
  std::cout<<"Unesite ugao rotacije: ";
  std::cin>>ugao;
  std::cout<<"Unesite faktor skaliranja: ";
  std::cin>>faktor;
    for(int i=0;i<n;i++){
          v[i]->Skaliraj(v[i]->DajTjeme(1),faktor);
     v[i]->Rotiraj(v[i]->DajTjeme(1),ugao);
         v[i]->Transliraj(dx,dy);
  }
  std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
  for(int i=0;i<n;i++){
      v[i]->Ispisi();
      std::cout<<std::endl;
  }
	return 0;
}