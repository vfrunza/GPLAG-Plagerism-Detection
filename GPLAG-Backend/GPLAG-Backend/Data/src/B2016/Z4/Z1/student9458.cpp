/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <memory>
#include <utility>
#include <cmath>
#include <algorithm>
#define EPS 1E-10
typedef std::pair<double,double> Tacka;
class Trougao{
    Tacka x,y,z;
    static bool Isti(double a, double b){if(abs(a-b)<EPS)return true; else return false;}
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks,const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){static int orijent=int(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second)); return orijent;}
    Tacka DajTjeme(int indeks)const{if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");if(indeks==1)return x; else if(indeks==2)return y; else return z;}
    double DajStranicu(int indeks)const{
        double pov;
        if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
        if(indeks ==1){pov=(std::sqrt(std::pow(z.first-y.first,2)+std::pow(z.second-y.second,2)));}
        else if(indeks==2){pov=(std::sqrt(std::pow(z.first-x.first,2)+std::pow(z.second-x.second,2)));}
        else {pov=(std::sqrt(std::pow(y.first-x.first,2)+std::pow(y.second-x.second,2)));}
        return pov;
    }
    double DajUgao(int indeks)const{
        if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
        double kut=0;
        double a=DajStranicu(1);
        double b=DajStranicu(2);
        double c=DajStranicu(3);
        if(indeks==1){kut=std::acos((b*b+c*c-a*a)/(2*b*c));}
        else if(indeks==2){kut=std::acos((a*a+c*c-b*b)/(2*a*c));}
        else kut=std::acos((a*a+b*b-c*c)/(2*a*b));
        return kut;
    }
    Tacka DajCentar()const{
        Tacka a;
        double b=(x.first+y.first+z.first)/3.;
        double c=(x.second+ y.second+z.second)/3.;
        a=std::make_pair(b,c);
        return a;
    }
    double DajObim()const{
        double str1,str2,str3,O;
        str1=(std::sqrt(std::pow(z.first-y.first,2)+std::pow(z.second-y.second,2)));
        str2=(std::sqrt(std::pow(z.first-x.first,2)+std::pow(z.second-x.second,2)));
        str3=(std::sqrt(std::pow(y.first-x.first,2)+std::pow(y.second-x.second,2)));
        O=str3+str2+str1;
        return O;
    }
    double DajPovrsinu()const{
        return fabs(x.first*(y.second-z.second)-y.first*(x.second-z.second)+z.first*(x.second-y.second))/2;
    }
    bool DaLiJePozitivnoOrijentiran()const{
        int b=Orijentacija(x,y,z);
        if(b==1)return true;
        else return false;
    }
    bool DaLiJeUnutra(Tacka t){
        int a=Orijentacija(x,y,z),b=Orijentacija(x,y,t),c=Orijentacija(y,z,t),d=Orijentacija(z,x,t);
        if(a==b && b==c &&c==d)return true;
        else return false;
    }
    void Ispisi()const{
        std::cout<<"(("<<x.first<<","<<x.second<<"),("<<y.first<<","<<y.second<<"),("<<z.first<<","<<z.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        x.first+=delta_x; y.first+=delta_x; z.first+=delta_x;
        x.second+=delta_y; y.second+=delta_y; z.second+=delta_y;
    }
    void Rotiraj(const Tacka &t, double ugao){
        if(ugao<0)ugao+=180;
        x.first=(t.first+(x.first-t.first)*cos(ugao)-(x.second-t.second)*sin(ugao));
        y.first=(t.first+(y.first-t.first)*cos(ugao)-(y.second-t.second)*sin(ugao));
        z.first=(t.first+(z.first-t.first)*cos(ugao)-(z.second-t.second)*sin(ugao));
        x.second=(t.second+(x.first-t.first)*sin(ugao)+(x.second-t.second)*cos(ugao));
        y.second=(t.second+(y.first-t.first)*sin(ugao)+(y.second-t.second)*cos(ugao));
        z.second=(t.second+(z.first-t.first)*sin(ugao)+(z.second-t.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor<EPS)throw std::domain_error("Nekorektan faktor skaliranja");
        x.first=t.first+faktor*(x.first-t.first);
        x.second=t.second+faktor*(x.second-t.second);
        y.first=t.first+faktor*(y.first-t.first);
        y.second=t.second+faktor*(y.second-t.second);
        z.first=t.first+faktor*(z.first-t.first);
        z.second=t.second+faktor*(z.second-t.second);
    }
    void Rotiraj(double ugao){
        Tacka t=DajCentar();
        if(ugao<0)ugao+=180;
        x.first=(t.first+(x.first-t.first)*cos(ugao)-(x.second-t.second)*sin(ugao));
        y.first=(t.first+(y.first-t.first)*cos(ugao)-(y.second-t.second)*sin(ugao));
        z.first=(t.first+(z.first-t.first)*cos(ugao)-(z.second-t.second)*sin(ugao));
        x.second=(t.second+(x.first-t.first)*sin(ugao)+(x.second-t.second)*cos(ugao));
        y.second=(t.second+(y.first-t.first)*sin(ugao)+(y.second-t.second)*cos(ugao));
        z.second=(t.second+(z.first-t.first)*sin(ugao)+(z.second-t.second)*cos(ugao));
    }
    void Skaliraj(double faktor){
        Tacka t=DajCentar();
        x.first=t.first+faktor*(x.first-t.first);
        x.second=t.second+faktor*(x.second-t.second);
        y.first=t.first+faktor*(y.first-t.first);
        y.second=t.second+faktor*(y.second-t.second);
        z.first=t.first+faktor*(z.first-t.first);
        z.second=t.second+faktor*(z.second-t.second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao&t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
    bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        double str[3];
        str[0]=t1.DajStranicu(1);
        str[1]=t1.DajStranicu(2);
        str[2]=t1.DajStranicu(3);
        std::sort(str,str+3);
        double str1[3];
        str1[0]=t2.DajStranicu(1);
        str1[1]=t2.DajStranicu(2);
        str1[2]=t2.DajStranicu(3);
        std::sort(str1, str1+3);
        double al,be,ga,alf,bet,gam;
        al=t1.DajUgao(1);
        be=t1.DajUgao(2);
        ga=t1.DajUgao(3);
        alf=t2.DajUgao(1);
        bet=t2.DajUgao(2);
        gam=t2.DajUgao(3);
        if((fabs(al-alf)<EPS && fabs(be-bet)<EPS)||(fabs(al-alf)<EPS && fabs(ga-bet)<EPS) || (fabs(al-alf)<EPS && fabs(ga-gam)<EPS) || (fabs(al-alf)<EPS && fabs(be-gam)<EPS) || (fabs(be-bet)<EPS && fabs(ga-gam)<EPS)||(fabs(be-bet)<EPS && fabs(ga-alf)<EPS) ||(fabs(be-bet)<EPS && fabs(al-gam)<EPS)||(fabs(ga-gam)<EPS && fabs(al-bet)<EPS)||(fabs(ga-gam)<EPS && fabs(be-alf)<EPS))return true;
        else return false;
    }
    bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        int a,b,c,a1,b1,c1;
        a=t1.DajStranicu(1);
        b=t1.DajStranicu(2);
        c=t1.DajStranicu(3);
        
        a1=t2.DajStranicu(1);
        b1=t2.DajStranicu(2);
        c1=t2.DajStranicu(3);
        
        if((fabs(a-a1)<EPS && fabs(b-b1)<EPS) ||(fabs(a-a1)<EPS && fabs(c-c1)<EPS) ||(fabs(a-a1)<EPS && fabs(b-c1)<EPS) ||(fabs(b-b1)<EPS && fabs(c-c1)<EPS) ||(fabs(b-b1)<EPS && fabs(a-c1)<EPS) ||(fabs(c-c1)<EPS && fabs(a-b1)<EPS) ){
            return true;
        }
        return false;
    }

 bool DaLiSuIdenticni(const Trougao &t1, const Trougao&t2){
        double str[3];
        str[0]=t1.DajStranicu(1);
        str[1]=t1.DajStranicu(2);
        str[2]=t1.DajStranicu(3);
        double str1[3];
        str1[0]=t2.DajStranicu(1);
        str1[1]=t2.DajStranicu(2);
        str1[2]=t2.DajStranicu(3);
        int broj=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(fabs(str[i]-str1[i])<EPS)broj++;
            }
        }
        if(broj>=3 ){
            int a,b,c,a1,b1,c1;
        a=t1.DajStranicu(1);
        b=t1.DajStranicu(2);
        c=t1.DajStranicu(3);
        
        a1=t2.DajStranicu(1);
        b1=t2.DajStranicu(2);
        c1=t2.DajStranicu(3);
        
        if((fabs(a-a1)<EPS &&fabs(b-b1)<EPS) ||(fabs(a-a1)<EPS && fabs(c-c1)<EPS) ||(fabs(a-a1)<EPS && fabs(b-c1)<EPS) ||(fabs(b-b1)<EPS && fabs(c-c1)<EPS) ||(fabs(b-b1)<EPS && fabs(a-c1)<EPS) ||(fabs(c-c1)<EPS && fabs(a-b1)<EPS) )return true;
        
    }
    return false;
 }
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(fabs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<EPS){throw std::domain_error("Nekorektne pozicije tjemena");}
    Trougao::x=t1; Trougao::y=t2; Trougao::z=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Tacke su kolinearne");
    Trougao::x=t1; Trougao::y=t2; Trougao::z=t3;
}
void Trougao::Postavi(int indeks,const Tacka &t){
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
    if(indeks==1)Trougao::x=t;
    else if(indeks==2)Trougao::y=t;
    else Trougao::z=t;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>pok(n);
    for(int i=0; i<n; i++){
        std::pair<int,int> x,y,z;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x.first;
        std::cin>>x.second;
        std::cin>>y.first;
        std::cin>>y.second;
        std::cin>>z.first;
        std::cin>>z.second;
        if(Trougao::Orijentacija(x,y,z)==0){std::cout<<"Tacke su kolinearne";i--;}
        else { 
            try{
            Trougao a(x,y,z);
            pok[i]=std::make_shared<Trougao>(a);
        }catch(std::domain_error pok){
            std::cout<<"Nekorektne pozicije tjemena";
        }
        }
    }
    std::pair<double,double>vektor_translacije;
    std::cout<<"Unesite vektor translacije (dx,dy): ";
    std::cin>>vektor_translacije.first>>vektor_translacije.second;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double skal;
    std::cin>>skal;
    for(int i=0; i<pok.size(); i++){
        pok[i]->Transliraj(vektor_translacije.first, vektor_translacije.second);
        pok[i]->Rotiraj(pok[i]->DajCentar(),ugao);
        Tacka z=pok[i]->DajTjeme(1);
        pok[i]->Skaliraj(z,skal);
    }
    std::sort(pok.begin(),pok.end(),[](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });
    std::cout<<"Trouglovi nakon obavljenih trensformacija: "<<std::endl;
    std::for_each(pok.begin(), pok.end(), [](std::shared_ptr<Trougao> p1){p1->Ispisi();std::cout<<std::endl;});
   // Trougao OBIM=std::min_element(pok.begin(), pok.end(),[](std::shared_ptr<Trougao>p1, std::shared_ptr<Trougao>p2){
    //    return p1->DajObim()<p2->DajObim();
   // });
   // std::cout<<"Trougao sa najmanjim obimom: "<<*(std::min_element(pok.begin(), pok.end(),[](std::shared_ptr<Trougao>p1, std::shared_ptr<Trougao>p2){
  //      return p1->DajObim()<p2->DajObim();
   // });).Ispisi();
    std::vector<std::pair<int,int>>ide;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n-1; j++){
            if(DaLiSuIdenticni(*pok[i],*pok[j]))ide.push_back(std::make_pair(i,j));
        }
    }
    std::cout<<"Parovi identicnih trouglova:"<<std::endl;
    for(int i=0; i<ide.size(); i++){
        pok[ide[i].first]->Ispisi();std::cout<<" i ";
        pok[ide[i].second]->Ispisi();
    }
    
    std::vector<std::pair<int,int>>pod;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n-1; j++){
            if(DaLiSuPodudarni(*pok[i],*pok[j]))pod.push_back(std::make_pair(i,j));
        }
    }
    std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
    for(int i=0; i<pod.size(); i++){
        pok[pod[i].first]->Ispisi();std::cout<<" i ";
        pok[pod[i].second]->Ispisi();std::cout<<std::endl;
         }
    
    std::vector<std::pair<int,int>>sli;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n-1; j++){
            if(DaLiSuSlicni(*pok[i],*pok[j]))sli.push_back(std::make_pair(i,j));
        }
    }
    std::cout<<"Parovi slicnih trouglova:"<<std::endl;
    for(int i=0; i<sli.size(); i++){
        pok[sli[i].first]->Ispisi();std::cout<<" i ";
        pok[sli[i].second]->Ispisi();std::cout<<std::endl;
    }
	return 0;
}