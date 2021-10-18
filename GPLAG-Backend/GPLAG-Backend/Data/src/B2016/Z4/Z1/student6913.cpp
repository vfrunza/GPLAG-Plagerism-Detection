#include <map>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <algorithm> 
#include <vector>
#include <memory>
    

typedef std::pair<double,double> Tacka;
double Eps=pow(10,-10);

class Trougao {
    Tacka a,b,c;
    
    public:
    Trougao (const Tacka &t1,const Tacka &t2,const Tacka &t3){
        Postavi(t1,t2,t3);
    }

    
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    a=t1;
    b=t2;
    c=t3;
    if (Orijentacija(a,b,c)==0){
        throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
    }
}


void Postavi(int indeks, const Tacka &t){
    if(indeks == 1){
        a=t;
    }
    if(indeks == 2){
        b=t;
    }
    if(indeks == 3){
        c=t;
    }
    if(indeks >3 || indeks<1){
        throw std::range_error("Nekorektan indeks");
    }
    if(Orijentacija(a,b,c)==0){
        throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
    }
}


static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0){
        return 1;
    }
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0){
        return -1;
     }
      else return 0;
}


Tacka DajTjeme(int indeks) const{
    if(indeks==1) return a;
    if(indeks==2) return b;
    if(indeks==3) return c;
else throw std::range_error("Nekorektan indeks");
}


double DajStranicu(int indeks) const{
    double str;
    if(indeks==1){
        str=sqrt((c.first-b.first)*(c.first-b.first)+(c.second-b.second)*(c.second-b.second));
    }
    if(indeks==2){
        str=sqrt((c.first-a.first)*(c.first-a.first)+(c.second-a.second)*(c.second-a.second));
    }
    if(indeks==3){
        str=sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
    }
    return str;
}


double DajUgao(int indeks) const{
    double ugao;
    double a1=DajStranicu(1);
    double b1=DajStranicu(2);
    double c1=DajStranicu(3);
if(indeks==1){
    ugao=acos((b1*b1+c1*c1-a1*a1)/(2*b1*c1));
}
if(indeks==2){
    ugao=acos((a1*a1-b1*b1+c1*c1)/(2*a1*c1));
}
if(indeks==3){
    ugao=acos((a1*c1+b1*b1-c1*c1)/(2*a1*b1));
}
return ugao;
}


Tacka DajCentar() const{
    Tacka Centar;
    Centar.first=(a.first+b.first+c.first)/3;
    Centar.second=(a.second+b.second+c.second)/3;
    return Centar;
}


double DajObim() const{
    double obim;
    obim=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    return obim;
}


double DajPovrsinu() const{
    double p;
    p=0.5*abs(a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second));
    return p;
}


bool DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(a,b,c)==1) return true;
    else return false;
}


bool DaLiJeUnutra(const Tacka &t) const{
 if(Orijentacija(a,b,c)>0 && Orijentacija(a,b,t)>0 && Orijentacija(b,c,t)>0 && Orijentacija(c,a,t)>0){
     return true;
 }
 if(Orijentacija(a,b,c)<0 && Orijentacija(a,b,t)<0 && Orijentacija(b,c,t)<0 && Orijentacija(c,a,t)<0){
     return true;
 }
 else return false;
}


void Ispisi() const{
std::cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";   
}


void Transliraj(double delta_x, double delta_y){
    a.first=a.first+delta_x;
    a.second=a.second+delta_y;
    b.first=b.first+delta_x;
    b.second=b.second+delta_y;
    c.first=c.first+delta_x;
    c.second=c.second+delta_y;
}


void Centriraj(const Tacka &t){
    Tacka p=DajCentar();
    double x=t.first-p.first;
    double y=t.second-p.second;
    
    a.first=a.first+x;
    a.second=a.second+y;
    b.first=b.first+x;
    b.second=b.second+y;
    c.first=c.first+x;
    c.second=c.second+y;
}


void Rotiraj(const Tacka &t, double ugao){
    double e=a.first;
    double w=b.first;
    double q=c.first;
   a.first=t.first+(e-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
    a.second=t.second+(e-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
    b.first=t.first+(w-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
    b.second=t.second+(w-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
    c.first=t.first+(q-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
    c.second=t.second+(q-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
}

void Rotiraj(double ugao){
    Tacka t=DajCentar();
    double e=a.first;
    double w=b.first;
    double q=c.first;
    a.first=t.first+(e-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
    a.second=t.second+(e-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
    b.first=t.first+(w-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
    b.second=t.second+(w-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
    c.first=t.first+(q-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
    c.second=t.second+(q-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
}

void Skaliraj(const Tacka &t, double faktor){
    if(fabs(faktor)<Eps){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    a.first=t.first+faktor*(a.first-t.first);
    a.second=t.second+faktor*(a.second-t.second);
    b.first=t.first+faktor*(b.first-t.first);
    b.second=t.second+faktor*(b.second-t.second);
    c.first=t.first+faktor*(c.first-t.first);
    c.second=t.second+faktor*(c.second-t.second);
}


void Skaliraj(double faktor){
     if(fabs(faktor)<Eps){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    Tacka t=DajCentar();
    a.first=t.first+faktor*(a.first-t.first);
    a.second=t.second+faktor*(a.second-t.second);
    b.first=t.first+faktor*(b.first-t.first);
    b.second=t.second+faktor*(b.second-t.second);
    c.first=t.first+faktor*(c.first-t.first);
    c.second=t.second+faktor*(c.second-t.second);
}


friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};


bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(fabs((t1.a.first+t1.b.first+t1.c.first-(t2.a.first+t2.b.first+t2.c.first))<Eps) && (fabs(t1.a.second+t1.b.second+t1.c.second-(t2.a.second+t2.b.second+t2.c.second))<Eps)&& (fabs(t1.a.first*t1.b.first*t1.c.first-(t2.a.first*t2.b.first*t2.c.first))<Eps) && (fabs(t1.a.second*t1.b.second*t1.c.second-(t2.a.second*t2.b.second*t2.c.second))<Eps) ){
    return true;
    }
        else return false;
    }


bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
  auto k=t1.DajStranicu(1);
     auto l=t2.DajStranicu(1);
     if(fabs(t1.DajStranicu(2)-k)<Eps && fabs(t1.DajStranicu(3)-k)<Eps && fabs(t2.DajStranicu(2)-l)<Eps && fabs(t2.DajStranicu(3)-l)<Eps)
     return true;
    std::vector<double> v1(3);
     std::map<double,Tacka> m;
     m.insert(std::make_pair(t1.DajStranicu(1),t1.a));
     m.insert(std::make_pair(t1.DajStranicu(2),t1.b));
     m.insert(std::make_pair(t1.DajStranicu(3),t1.c));
     v1[0]=t1.DajStranicu(1); v1[1]=t1.DajStranicu(2); v1[2]=t1.DajStranicu(3);
     std::sort(v1.begin(),v1.end());
     auto min1=m.find(v1[0]);
     auto sre1=m.find(v1[1]);
     auto max1=m.find(v1[2]);
     std::vector<double> v2(3);
     std::map<double, Tacka> n;
     n.insert(std::make_pair(t2.DajStranicu(1),t2.a));
     n.insert(std::make_pair(t2.DajStranicu(2),t2.b));
     n.insert(std::make_pair(t2.DajStranicu(3),t2.c));
     v2[0]=t2.DajStranicu(1); v2[1]=t2.DajStranicu(2); v2[2]=t2.DajStranicu(3);
     std::sort(v2.begin(),v2.end());
     auto min2=n.find(v2[0]);
     auto sre2=n.find(v2[1]);
     auto max2=n.find(v2[2]);
     double obim1=t1.DajObim();
     double obim2=t2.DajObim();
     if(fabs(obim1-obim2)>Eps)
     return false;
     if (Trougao::Orijentacija(min1->second,sre1->second,max1->second)==Trougao::Orijentacija(min2->second,sre2->second,max2->second))
     return true;
     return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
     auto k=t1.DajStranicu(1);
     auto l=t2.DajStranicu(1);
     if(fabs(t1.DajStranicu(2)-k)<Eps && fabs(t1.DajStranicu(3)-k)<Eps && fabs(t2.DajStranicu(2)-l)<Eps && fabs(t2.DajStranicu(3)-l)<Eps)
     return true;
     std::vector<double> v1(3);
     std::map<double,Tacka> m;
     m.insert(std::make_pair(t1.DajStranicu(1),t1.a));
     m.insert(std::make_pair(t1.DajStranicu(2),t1.b));
     m.insert(std::make_pair(t1.DajStranicu(3),t1.c));
     v1[0]=t1.DajStranicu(1); v1[1]=t1.DajStranicu(2); v1[2]=t1.DajStranicu(3);
     std::sort(v1.begin(),v1.end());
     auto min1=m.find(v1[0]);
     auto sre1=m.find(v1[1]);
     auto max1=m.find(v1[2]);
     std::vector<double> v2(3);
     std::map<double, Tacka> n;
     n.insert(std::make_pair(t2.DajStranicu(1),t2.a));
     n.insert(std::make_pair(t2.DajStranicu(2),t2.b));
     n.insert(std::make_pair(t2.DajStranicu(3),t2.c));
     v2[0]=t2.DajStranicu(1); v2[1]=t2.DajStranicu(2); v2[2]=t2.DajStranicu(3);
     std::sort(v2.begin(),v2.end());
     auto min2=n.find(v2[0]);
     auto sre2=n.find(v2[1]);
     auto max2=n.find(v2[2]);
     double odnos1=v1[0]/v2[0];
     double odnos2=v1[1]/v2[1];
     double odnos3=v1[2]/v2[2];
     if(fabs(odnos1-odnos2)>Eps || fabs(odnos1-odnos3)>Eps)
     return false;
     if (Trougao::Orijentacija(min1->second,sre1->second,max1->second)==Trougao::Orijentacija(min2->second,sre2->second,max2->second))
     return true;
     return false;
}



int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int h;
    std::cin>>h;
    std::vector<std::shared_ptr<Trougao>>v(h);
    std::vector<std::shared_ptr<Trougao>>w(h);
    double a,b,c,d,e,f;
    Tacka m,n,o;
    for(int i=0;i<h;i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>a>>b>>c>>d>>e>>f;
        m=std::make_pair(a,b);
        n=std::make_pair(c,d);
        o=std::make_pair(e,f);
        try{
            v[i]=std::make_shared<Trougao>(Trougao(m,n,o));
        }
        catch(std::domain_error a){
            std::cout<<a.what()<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy):";
    double x1,y1;
    std::cin>>x1>>y1;
    std::cout<<" Unesite ugao rotacije: ";
    double y2;
    std::cin>>y2;
    std::cout<<"Unesite faktor skaliranja: ";
    double x2;
    std::cin>>x2;
    Tacka g;
    try{
   std::transform(v.begin(),v.end(),w.begin(), [=](std::shared_ptr<Trougao>p){ (*p).Transliraj(x1,y1); (*p).Rotiraj(y2);try{ (*p).Skaliraj((*p).DajTjeme(1),x2); } catch(std::domain_error d){std::cout<<d.what(); throw; } return p;}); }
   catch(...){
       return 0;
   }
      std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
   std::sort(w.begin(),w.end(),[=](std::shared_ptr<Trougao>p,std::shared_ptr<Trougao>q){return (*p).DajPovrsinu()-(*q).DajPovrsinu()<0;});
   std::for_each(w.begin(),w.end(),[=](std::shared_ptr<Trougao>p){(*p).Ispisi(); std::cout  << std::endl; });
   auto mini=std::min_element(w.begin(),w.end(),[=](std::shared_ptr<Trougao>p,std::shared_ptr<Trougao>q){return (*p).DajObim()-(*q).DajObim()<0;});
std::cout<<"Trougao sa najmanjim obimom: ";
(*mini)->Ispisi();
std::cout  << std::endl;
bool Identicni(false),Podudarni (false),Slicni(false);
std::vector<std::pair<Trougao,Trougao>> I;
std::vector<std::pair<Trougao,Trougao>> P;
std::vector<std::pair<Trougao,Trougao>> S;
for(int i=0;i<w.size()-1;i++){
    for(int j=i+1;j<w.size();j++){
        if(DaLiSuIdenticni(*w[i],*w[j])){
            Identicni=true;
            I.push_back(std::make_pair(*w[i],*w[j]));
        }
        if(DaLiSuPodudarni(*w[i],*w[j])){
            Podudarni=true;
            P.push_back(std::make_pair(*w[i],*w[j]));
        }
        if(DaLiSuSlicni(*w[i],*w[j])){
            Slicni=true;
            S.push_back(std::make_pair(*w[i],*w[j]));
        }
    }
}
 if(!Identicni)
std::cout << "Nema identicnih trouglova!" << std::endl;
else {
    std::cout << "Parovi identicnih trouglova: " << std::endl;
    for(int i=0;i<I.size();i++){
    I[i].first.Ispisi(); std::cout << " i "; I[i].second.Ispisi();
    std::cout  << std::endl;
    }
}

if(!Podudarni)
std::cout << "Nema podudarnih trouglova!" << std::endl;
else {
    std::cout << "Parovi podudarnih trouglova: " << std::endl;
    for(int i=0;i<P.size();i++){
    P[i].first.Ispisi(); std::cout << " i " ; P[i].second.Ispisi();
    std::cout  << std::endl;
    }
}
if(!Slicni)
std::cout << "Nema slicnih trouglova!" << std::endl;
else {
    std::cout << "Parovi slicnih trouglova: " << std::endl;
    for(int i=0;i<S.size();i++){
    S[i].first.Ispisi(); std::cout  <<" i ";
    S[i].second.Ispisi();
    std::cout  << std::endl;
    }
}
 	return 0;
}