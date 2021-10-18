#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka T1,T2,T3;
public:    
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Postavi(t1,t2,t3);
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error{"Nekorektne pozicije tjemena"};
    try{
    T1=t1;
    T2=t2;
    T3=t3;
    }catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
}
    

void Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error{"Nekorektan indeks"};
    try{
    if(indeks==1) T1=t;
    if(indeks==2) T2=t;
    if(indeks==3) T3=t;
    }
    catch(std::range_error r){
        std::cout<<r.what()<<std::endl;
    }
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    int br, n;
    br=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    n=t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    if(br>0) return 1;
    if(br<0) return -1;
    if(n==0) return 0;
}
Tacka DajTjeme(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error{"Nekorektan indeks"};
    try{
    if(indeks==1) return T1;
    if(indeks==2) return T2;
    if(indeks==3) return T3;
    }
    catch(std::range_error r){
        std::cout<<r.what()<<std::endl;
    }
}
double DajStranicu(int indeks) const{
    double a,b,c;
    a=sqrt((T1.first-T2.first)*(T1.first-T2.first)+(T1.second-T2.second)*(T1.second-T2.second));
    b=sqrt((T2.first-T3.first)*(T2.first-T3.first)+(T2.second-T3.second)*(T2.second-T3.second));
    c=sqrt((T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second));
    if(indeks==1) return b;
    if(indeks==2) return c;
    if(indeks==3) return a;
}
double DajUgao(int indeks) const{
    double alfa,beta,gama,a,b,c;
    a=sqrt((T1.first-T2.first)*(T1.first-T2.first)+(T1.second-T2.second)*(T1.second-T2.second));
    b=sqrt((T2.first-T3.first)*(T2.first-T3.first)+(T2.second-T3.second)*(T2.second-T3.second));
    c=sqrt((T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second));
    alfa=acos((a*a+c*c-b*b)/(2*a*c))*((4*atan(1))/180);
    beta=acos((a*a+b*b-c*c)/(2*a*b))*((4*atan(1))/180);
    gama=acos((b*b+c*c-a*a)/(2*b*c))*((4*atan(1))/180);
    if(indeks==1) return alfa;
    if(indeks==2) return beta;
    if(indeks==3) return gama;
}
Tacka DajCentar() const  {
    Tacka c;
    c.first=(T1.first+T2.first+T3.first)/3;
    c.second=(T1.second+T2.second+T3.second)/3;
    return c;
}
double DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double DajPovrsinu() const{
    double P;
    P=0.5*abs(T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second));
    return P;
}
bool DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(T1,T2,T3)==1) return true;
    else return false;
}
bool DaLiJeUnutra(const Tacka &t) const{
    double P1,P2,P3,P;
    P=0.5*abs(T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second));
    P1=0.5*abs(t.first*(T2.second-T3.second)-T2.first*(t.second-T3.second)+T3.first*(t.second-T2.second));
    P2=0.5*abs(T1.first*(t.second-T3.second)-t.first*(T1.second-T3.second)+T3.first*(T1.second-t.second));
    P3=0.5*abs(T1.first*(T2.second-t.second)-T2.first*(T1.second-t.second)+t.first*(T1.second-T2.second));
    if(P==(P1+P2+P3)) return true;
    else return false;
}
void Ispisi() const{
    std::cout<<"(("<<T1.first<<","<<T1.second<<"),("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";
}
void Transliraj(double delta_x, double delta_y){
    T1.first+=delta_x;
    T1.second+=delta_y;
    T2.first+=delta_x;
    T2.second+=delta_y;
    T3.first+=delta_x;
    T3.second+=delta_y;
    
}
void Centriraj(const Tacka &t){
    double dx,dy;
    dx=t.first-DajCentar().first;
    dy=t.second-DajCentar().second;
    Transliraj(dx,dy);
    
}
void Rotiraj(const Tacka &t, double ugao){
    T1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
    T1.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
    T2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
    T2.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
    T3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
    T3.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
}
void Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw std::domain_error{"Nekorektan faktor skaliranja"};
    try{
    T1.first=t.first+faktor*(T1.first-t.first);
    T1.second=t.second+faktor*(T1.second-t.second);
    T2.first=t.first+faktor*(T2.first-t.first);
    T2.second=t.second+faktor*(T2.second-t.second);
    T3.first=t.first+faktor*(T3.first-t.first);
    T3.second=t.second+faktor*(T3.second-t.second);
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
}
void Rotiraj(double ugao){
    Trougao T(T1,T2,T3);
    Tacka p;
    p=T.DajCentar();
    T1.first=p.first+(T1.first-p.first)*cos(ugao)-(T1.second-p.second)*sin(ugao);
    T1.second=p.second+(T1.first-p.first)*sin(ugao)+(T1.second-p.second)*cos(ugao);
    T2.first=p.first+(T2.first-p.first)*cos(ugao)-(T2.second-p.second)*sin(ugao);
    T2.second=p.second+(T2.first-p.first)*sin(ugao)+(T2.second-p.second)*cos(ugao);
    T3.first=p.first+(T3.first-p.first)*cos(ugao)-(T3.second-p.second)*sin(ugao);
    T3.second=p.second+(T3.first-p.first)*sin(ugao)+(T3.second-p.second)*cos(ugao);
    
}
void Skaliraj(double faktor){
    Trougao T(T1,T2,T3);
    Tacka p;
    p=T.DajCentar();
    if(faktor==0) throw std::domain_error{"Nekorektan faktor skaliranja"};
    try{
    T1.first=p.first+faktor*(T1.first-p.first);
    T1.second=p.second+faktor*(T1.second-p.second);
    T2.first=p.first+faktor*(T2.first-p.first);
    T2.second=p.second+faktor*(T2.second-p.second);
    T3.first=p.first+faktor*(T3.first-p.first);
    T3.second=p.second+faktor*(T3.second-p.second);
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::vector<Tacka> v1(3);
    std::vector<Tacka> v2(3);
    for(int i=0; i<3; i++){
        v1.push_back(t1.DajTjeme(i+1));
        v2.push_back(t2.DajTjeme(i+1));
    }
    std::sort(v1.begin(),v1.end()); std::sort(v2.begin(),v2.end());
    if(v1==v2)
    return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<double> v1;
    std::vector<double> v2;
    for(int i=0; i<3; i++){
        v1.push_back(t1.DajStranicu(i+1));
        v2.push_back(t2.DajStranicu(i+1));
    }
    std::sort(v1.begin(),v1.end()); std::sort(v2.begin(),v2.end());
   if(v1!=v2) return false; 
   else{
       Trougao t=t2,p=t2;
       double dx,dy,x1,y1,x2,y2;
       x1=t1.DajTjeme(1).first+t1.DajTjeme(2).first+t1.DajTjeme(3).first;
       y1=t1.DajTjeme(1).second+t1.DajTjeme(2).second+t1.DajTjeme(3).second;
       x2=t2.DajTjeme(1).first+t2.DajTjeme(2).first+t2.DajTjeme(3).first;
       y2=t2.DajTjeme(1).second+t2.DajTjeme(2).second+t2.DajTjeme(3).second;
       dx=(x1-x2)/3;
       dy=(y1-y2)/3;
       t.Transliraj(dx,dy);
       if(DaLiSuIdenticni(t1,t)==true)
       {
           return true;
           
       }
      else{
           double ugao;
           ugao=90*(4*atan(1)/180);
           p.Rotiraj(ugao); 
           if(DaLiSuIdenticni(t1,p)==true) return true;
           /*else{
            double dp,dq,p1,p2;
            p1=p.DajTjeme(1).first+p.DajTjeme(2).first+p.DajTjeme(3).first;
            p2=p.DajTjeme(1).second+p.DajTjeme(2).second+p.DajTjeme(3).second;
            dp=(x1-p1)/3;
            dq=(y1-p2)/3;
            p.Transliraj(dp,dq);
            if(DaLiSuIdenticni(t1,p)==true) return true;
           } return false;
*/        return false;
   }
    
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double> v1;
    std::vector<double> v2;
    for(int i=0; i<3; i++){
        v1.push_back(t1.DajStranicu(i+1));
        v2.push_back(t2.DajStranicu(i+1));
    }
    std::sort(v1.begin(),v1.end()); std::sort(v2.begin(),v2.end());
    double a,b,c;
    a=v1[0]/v2[0]; b=v1[1]/v2[1]; c=v1[2]/v2[2];
    if(a==b && a==c)return true; 
    else return false;

}

int main(){
    int n;
    Tacka t1,t2,t3;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    try{
    for(int i=0; i<n; i++){
        v[i]=nullptr;
    }
    
    for(int i=0; i<n; i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
        try{
        v[i]=std::make_shared<Trougao>(t1,t2,t3);
        }
        catch(std::domain_error e){
        std::cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;
        i--;
        }
    }
    
    }
    catch(std::bad_alloc){
        std::cout<<"Memorijska greska"<<std::endl;
    }
    double delta_x, delta_y, k, u;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>delta_x>>delta_y;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>u;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>k;
    std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,k,u](const std::shared_ptr<Trougao> &t){t->Transliraj(delta_x,delta_y); t->Rotiraj(t->DajTjeme(1),u); t->Skaliraj(t->DajTjeme(1),k); return t;});
    std::sort(v.begin(),v.end(),[](const std::shared_ptr<Trougao> &t1, const std::shared_ptr<Trougao> &t2){return t1->DajPovrsinu()<t2->DajPovrsinu();});
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(v.begin(),v.end(),[](const std::shared_ptr<Trougao> &t){ t->Ispisi(); std::cout<<std::endl;});
    const std::shared_ptr<Trougao> znj=*std::min_element(v.begin(),v.end(),[](const std::shared_ptr<Trougao> &t1,const std::shared_ptr<Trougao> &t2){return t1->DajObim()<t2->DajObim();});
    std::cout<<"Trougao sa najmanjim obimom: ";
    znj->Ispisi();
    int brojac(0),brojac1(0),brojac2(0);
    std::cout<<"\nParovi identicnih trouglova:\n";
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
            v[i]->Ispisi(); 
            std::cout<<" i ";
            v[j]->Ispisi(); std::cout<<std::endl;
            brojac++;
            }
        }
    }
    std::cout<<"\nParovi podudarnih trouglova:\n";
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
            v[i]->Ispisi(); 
            std::cout<<" i ";
            v[j]->Ispisi(); std::cout<<std::endl;
            brojac2++;
            }     
        }
    }
    std::cout<<"\nParovi slicnih trouglova:\n";
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
            v[i]->Ispisi(); 
            std::cout<<" i ";
            v[j]->Ispisi(); std::cout<<std::endl;
            brojac1++;
            }
        }
    }
    
    if(brojac==0){
        std::cout<<"Nema identicnih trouglova!"<<std::endl;
    }
    if(brojac2==0){
        std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    }
    if(brojac1==0){
        std::cout<<"Nema slicnih touglova!"<<std::endl;
    }
    
    return 0;
}