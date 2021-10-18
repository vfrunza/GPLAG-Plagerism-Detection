/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
const double eps=0.00000001;
typedef std::pair<double, double> Tacka;

class Trougao{
  Tacka T1,T2,T3;
  static bool Jednakost(double a,double b){
      if(fabs(a-b)<eps)return true;
      return false;
  }
  static bool ZaTacke(const Tacka &t1,const Tacka &t2){
      if(fabs(t1.first-t2.first)<eps && fabs(t1.second-t2.second)<eps)return true;
      return false;
  }
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
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    //std::cout<<t1.DajCentar().first<<" "<<t2.DajCentar().first<<std::endl;
    //std::cout<<t1.DajCentar().second<<" "<<t2.DajCentar().second<<std::endl;
    if (Jednakost(t1.DajObim(),t2.DajObim())==true && Jednakost(t1.DajPovrsinu(),t2.DajPovrsinu())==true && ZaTacke(t1.DajCentar(),t2.DajCentar())==true ) {
        if(ZaTacke(t1.DajTjeme(1),t2.DajTjeme(1))==true
           || ZaTacke(t1.DajTjeme(1),t2.DajTjeme(2))==true
           || ZaTacke(t1.DajTjeme(1),t2.DajTjeme(1))==true )
        return true;

    }

    return false;
}
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
static int nesto(Tacka t1,Tacka t2,Tacka t3){
    //std::cout<<t1.first<<(t2.second-t3.second)<<-t2.first<<(t1.second-t3.second)<<t3.first<<(t1.second-t2.second)<<std::endl;
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Jednakost(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second),0))throw std::domain_error("Nekorektne pozicije tjemena");
    T1=t1;
    T2=t2;
    T3=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Jednakost(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second),0))throw std::domain_error("Nekorektne pozicije tjemena");
    T1=t1;
    T2=t2;
    T3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks==1){
        if(nesto(t,T2,T3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
    T1=t;
    }
    else if(indeks==2){T2=t;if(nesto(T1,t,T3)==0)throw std::domain_error("Nekorektne pozicije tjemena");}
    else if(indeks==3){T3=t;if(nesto(T1,T2,t)==0)throw std::domain_error("Nekorektne pozicije tjemena");}
    else throw std::range_error("Nekorektan indeks");
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(nesto(t1,t2,t3)>0)return 1;
    else if(nesto(t1,t2,t3)<0)return -1;
    return 0;
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks==1)return T1;
    else if(indeks==2)return T2;
    else if(indeks==3)return T3;
        else throw std::range_error("Nekorektan indeks");
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks==1)
    return fabs(sqrt((T2.first-T3.first)*(T2.first-T3.first)+(T2.second-T3.second)*(T2.second-T3.second)));
    else if(indeks==2)
    return fabs(sqrt((T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second)));
    else if(indeks==3)
    return fabs(sqrt((T2.first-T1.first)*(T2.first-T1.first)+(T2.second-T1.second)*(T2.second-T1.second)));
    else throw std::range_error("Nekorektan indeks");
}
double Trougao::DajUgao(int indeks) const{
    if(indeks==1)
            return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
    else if(indeks==2)
            return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
    else if(indeks==3)
            return std::acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        else throw std::range_error("Nekorektan indeks");
}
Tacka Trougao::DajCentar() const{
    Tacka t;
    t.first=(T1.first+T2.first+T3.first)/3;
    t.second=(T1.second+T2.second+T3.second)/3;
    return t;
}
double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const{
    return fabs(T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second))/2;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    return T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second)>0;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
            return nesto(T1,T2,T3)*nesto(T1,T2,t)*nesto(T2,T3,t)*nesto(T3,T1,t)>0;
}
void Trougao::Ispisi() const{
    std::cout<<"(("<<T1.first<<","<<T1.second<<"),("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";
}
void Trougao::Transliraj(double delta_x, double delta_y){
    T1.first+=delta_x;
    T2.first+=delta_x;
    T3.first+=delta_x;
    T1.second+=delta_y;
    T2.second+=delta_y;
    T3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka tac=DajCentar();
    Transliraj(t.first-tac.first,t.second-tac.second);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka tac1(t.first+(T1.first-t.first)*std::cos(ugao)-(T1.second-t.second)*std::sin(ugao),t.second+(T1.first-t.first)*std::sin(ugao)+(T1.second-t.second)*std::cos(ugao));
    Tacka tac2(t.first+(T2.first-t.first)*std::cos(ugao)-(T2.second-t.second)*std::sin(ugao),t.second+(T2.first-t.first)*std::sin(ugao)+(T2.second-t.second)*std::cos(ugao));
    Tacka tac3(t.first+(T3.first-t.first)*std::cos(ugao)-(T3.second-t.second)*std::sin(ugao),t.second+(T3.first-t.first)*std::sin(ugao)+(T3.second-t.second)*std::cos(ugao));
    this->Postavi(tac1,tac2,tac3);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if (Jednakost(faktor,0))throw std::domain_error("Nekorektan faktor skaliranja");
    if(faktor>0){
    T1.first=t.first+faktor*(T1.first-t.first);
    T1.second=t.second+faktor*(T1.second-t.second);
    T2.first=t.first+faktor*(T2.first-t.first);
    T2.second=t.second+faktor*(T2.second-t.second);
    T3.first=t.first+faktor*(T3.first-t.first);
    T3.second=t.second+faktor*(T3.second-t.second);
    }
    else{
        T1.first=t.first+faktor*(T1.first-t.first);
    T1.second=t.second+faktor*(T1.second-t.second);
    T2.first=t.first+faktor*(T2.first-t.first);
    T2.second=t.second+faktor*(T2.second-t.second);
    T3.first=t.first+faktor*(T3.first-t.first);
    T3.second=t.second+faktor*(T3.second-t.second);
    Rotiraj(T1,4*std::atan(1));
    }
}
void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}
/*bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    return Trougao::Jednakost(t1.DajUgao(1),t2.DajUgao(1)) && Trougao::Jednakost(t1.DajUgao(2),t2.DajUgao(3)) && Trougao::Jednakost(t1.DajUgao(3),t2.DajUgao(2)) && Trougao::Jednakost(t1.DajObim(),t2.DajObim()) && Trougao::Jednakost(t1.DajPovrsinu(),t2.DajPovrsinu());
}*/
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double x1=t1.DajStranicu(1),y1=t1.DajStranicu(2),z1=t1.DajStranicu(3);
    double x2=t2.DajStranicu(1),y2=t2.DajStranicu(2),z2=t2.DajStranicu(3);
    if(Trougao::Jednakost(x1,x2) && Trougao::Jednakost(y1,y2) && Trougao::Jednakost(z1,z2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T2,t2.T3,t2.T1)))return true;
    else if(Trougao::Jednakost(x1,x2) && Trougao::Jednakost(y1,z2) && Trougao::Jednakost(z1,y2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T3,t2.T2,t2.T1)))return true;
     else if(Trougao::Jednakost(x1,y2) && Trougao::Jednakost(y1,x2) && Trougao::Jednakost(z1,z2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T1,t2.T3,t2.T2)))return true;
       else if(Trougao::Jednakost(x1,y2) && Trougao::Jednakost(y1,z2) && Trougao::Jednakost(z1,x2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T3,t2.T1,t2.T2)))return true;
    else if(Trougao::Jednakost(x1,z2) && Trougao::Jednakost(y1,x2) && Trougao::Jednakost(z1,y2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T1,t2.T2,t2.T3)))return true;
    else if(Trougao::Jednakost(x1,z2) && Trougao::Jednakost(y1,y2) && Trougao::Jednakost(z1,x2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T2,t2.T1,t2.T3)))return true;
    return false;
}
bool DaLiSuSlicni(const Trougao & t1, const Trougao & t2) {
    double x1=t1.DajStranicu(1),y1=t1.DajStranicu(2),z1=t1.DajStranicu(3);
    double x2=t2.DajStranicu(1),y2=t2.DajStranicu(2),z2=t2.DajStranicu(3);
    if(Trougao::Jednakost(x1/x2,y1/y2) && Trougao::Jednakost(y1/y2,z1/z2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T2,t2.T3,t2.T1))) return true;
    else if(Trougao::Jednakost(x1/x2,y1/z2) && Trougao::Jednakost(y1/z2,z1/y2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T3,t2.T2,t2.T1))) return true;
    else if(Trougao::Jednakost(x1/y2,y1/x2) && Trougao::Jednakost(y1/x2,z1/z2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T1,t2.T3,t2.T2))) return true;
    else if(Trougao::Jednakost(x1/y2,y1/z2) && Trougao::Jednakost(y1/z2,z1/x2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T3,t2.T1,t2.T2))) return true;
    else if(Trougao::Jednakost(x1/z2,y1/x2) && Trougao::Jednakost(y1/x2,z1/y2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T1,t2.T2,t2.T3))) return true;
    else if(Trougao::Jednakost(x1/z2,y1/y2) && Trougao::Jednakost(y1/y2,z1/x2) && Trougao::Jednakost(nesto(t1.T2,t1.T3,t1.T1),nesto(t2.T2,t2.T1,t2.T3))) return true;
    return false;
}
using namespace std;
int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    vector<shared_ptr<Trougao>> v;
    for(int i=0;i<n;i++){
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        Tacka t1{a,b},t2{c,d},t3{e,f};
        try{
        shared_ptr<Trougao> pok(new Trougao(t1,t2,t3));
        v.push_back(pok);
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    double dx,dy;
    std::cout << "Unesite vektor translacije (dx dy): ";
        std::cin >> dx >> dy;
        std::cout<<"Unesite ugao rotacije: ";
        double ugao,faktor;
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja: ";
        std::cin>>faktor;

        std::transform(v.begin(), v.end(), v.begin(), [dx,dy,ugao,faktor](shared_ptr<Trougao> p){p->Transliraj(dx,dy); p->Rotiraj(p->DajCentar(),ugao);p->Skaliraj(p->DajTjeme(1),faktor); return p; });
    std::sort(v.begin(),v.end(),[](shared_ptr<Trougao>t1,shared_ptr<Trougao>t2){return t1->DajPovrsinu()<t2->DajPovrsinu();});
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
    std::for_each(v.begin(),v.end(),[](shared_ptr<Trougao> p){ p->Ispisi();std::cout<<endl;  return p; });
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto min_obim(std::min_element(v.begin(), v.end(), [](shared_ptr<Trougao>p1,shared_ptr<Trougao>p2) { return p1->DajObim()<p2->DajObim(); }));
    (**min_obim).Ispisi();
    std::cout<<std::endl;
    std::vector<std::pair<Trougao,Trougao>>i;
    for(int k=0;k<n;k++){
        for(int j=k;j<n;j++){
                if(k!=j)
            //if(DaLiSuIdenticni(*v[i],*v[j])){(*v[i]).Ispisi();std::cout<<" i ";(*v[j]).Ispisi();std::cout<<std::endl;}
            if(DaLiSuIdenticni(*v[k],*v[j]))i.push_back(make_pair(*v[k],*v[j]));
        }
    }
    if(i.size()!=0){
        std::cout<<"Parovi identicnih trouglova:"<<std::endl;
        for(int j=0;j<i.size();j++){
            i[j].first.Ispisi();std::cout<<" i ";i[j].second.Ispisi();std::cout<<endl;
        }
    }
    else std::cout<<"Nema identicnih trouglova!"<<std::endl;
    std::vector<std::pair<Trougao,Trougao>>p;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
                if(i!=j)
            if(DaLiSuPodudarni(*v[i],*v[j]))p.push_back(make_pair(*v[i],*v[j]));
            //{(*v[i]).Ispisi();std::cout<<" i ";(*v[j]).Ispisi();std::cout<<std::endl;}
        }
    }
    if(p.size()!=0){
        std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
        for(int i=0;i<p.size();i++){
            p[i].first.Ispisi();std::cout<<" i ";p[i].second.Ispisi();std::cout<<std::endl;
        }
    }
    else std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    std::vector<std::pair<Trougao,Trougao>>s;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
                if(i!=j)
            if(DaLiSuSlicni(*v[i],*v[j]))s.push_back(make_pair(*v[i],*v[j]));
            //{(*v[i]).Ispisi();std::cout<<" i ";(*v[j]).Ispisi();std::cout<<std::endl;}
        }
    }
    if(s.size()!=0){
        std::cout<<"Parovi slicnih trouglova:"<<std::endl;
        for(int i=0;i<s.size();i++){
            s[i].first.Ispisi();std::cout<<" i ";s[i].second.Ispisi();std::cout<<std::endl;
        }
    }
    else std::cout<<"Nema slicnih trouglova!"<<std::endl;
	return 0;
}