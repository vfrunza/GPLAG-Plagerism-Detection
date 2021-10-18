#include<iostream>
#include<utility>
#include<stdexcept>
#include<cmath>
#include<vector>
#include<algorithm>
#include<memory>
const double Pi= 4*atan(1);
typedef std::pair<double, double> Tacka;
class Trougao
{
    Tacka a, b,c;
    static bool TestirajIndex(int index) {
        if(index<1 || index>3) throw std::range_error("Nekorektan indeks");
        return true;
    }
    static bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
 return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
}

public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        a.first=t1.first;
        a.second=t1.second;
        b.first=t2.first;
        b.second=t2.second;
        c.first=t3.first;
        c.second=t3.second;
    }
    void Postavi(int indeks, const Tacka &t) {
        TestirajIndex(indeks);
        if(indeks==1) {
            a.first=t.first;
            a.second=t.second;
        } else if(indeks==2) {
            b.first=t.first;
            b.second=t.second;
        } else if(indeks==3) {
            b.first=t.first;
            b.second=t.second;
        }
         if(Orijentacija(a,b,c)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double x=(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));

        if( JesuLiJednaki(x,0)) return 0;
        else if( x>0) return 1;
        else return -1;
    }
    Tacka DajTjeme(int indeks) const {
        TestirajIndex(indeks);
        if(indeks == 1) return a;
        if(indeks == 2) return b;
        if(indeks ==3) return c;
    }
    double DajStranicu(int indeks) const {
        TestirajIndex(indeks);
        if(indeks == 1) return std::sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second));
        if(indeks == 2) return std::sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        if(indeks == 3) return std::sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
    }
    double DajUgao(int indeks) const {
        TestirajIndex(indeks);
        double stra=DajStranicu(1);
        double strb=DajStranicu(2);
        double strc=DajStranicu(3);
        if(indeks == 1) return double(std::acos((strb*strb+strc*strc-stra*stra)/(2*strb*strc)));
        if(indeks == 2) return double(std::acos((stra*stra+strc*strc-strb*strb)/(2*stra*strc)));
        if(indeks == 3) return double(std::acos((strb*strb+stra*stra-strc*strc)/(2*strb*stra)));
    }
    Tacka DajCentar() const {
        Tacka z;
        z.first=(a.first+b.first+c.first)/3;
        z.second=(a.second+b.second+c.second)/3;
        return z;
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
   double DajPovrsinu()const {
        double P=(a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second));
        if(P<0)P*=-1;
        P/=2.;
        return P;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(JesuLiJednaki(Orijentacija(a,b,c),1)) return true;
        if(JesuLiJednaki(Orijentacija(a,b,c),-1)) return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if (JesuLiJednaki(Orijentacija(a,b,c), Orijentacija(a,b,t)) && JesuLiJednaki(Orijentacija(b,c,t), Orijentacija(c,a,t)) &&  JesuLiJednaki(Orijentacija(a,b,c), Orijentacija(b,c,t)) ) return true;
        return false ;
    }
    void Ispisi() const {
        std::cout<<"("<<"("<<a.first<<","<<a.second<<")"<<","<<"("<<b.first<<","<<b.second<<")"<<","<<"("<<c.first<<","<<c.second<<")"<<")";
    }
    void Transliraj(double delta_x, double delta_y) {
        a.first+=delta_x;
        b.first+=delta_x;
        c.first+=delta_x;
        a.second+=delta_y;
        b.second+=delta_y;
        c.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Transliraj(t.first -DajCentar().first, t.second-DajCentar().second);
    
    }
    void Rotiraj(const Tacka &t, double ugao) {
        Tacka D,E,F; 
        D.first=t.first+(a.first-t.first)*std::cos(ugao)-(a.second-t.second)*std::sin(ugao);
        D.second=t.second+(a.first-t.first)*std::sin(ugao)+(a.second-t.second)*std::cos(ugao);
        E.first=t.first+(b.first-t.first)*std::cos(ugao)-(b.second-t.second)*std::sin(ugao);
        E.second=t.second+(b.first-t.first)*std::sin(ugao)+(b.second-t.second)*std::cos(ugao);
        F.first=t.first+(c.first-t.first)*std::cos(ugao)-(c.second-t.second)*std::sin(ugao);
        F.second=t.second+(c.first-t.first)*std::sin(ugao)+(c.second-t.second)*std::cos(ugao);
        Postavi(D,E,F); 
    }
    void Skaliraj(const Tacka & t, double faktor) {
        if (JesuLiJednaki(faktor, 0))throw std:: domain_error("Nekorektan faktor skaliranja");
        a.first=t.first+faktor*(a.first-t.first);
        b.first=t.first+faktor*(b.first-t.first);
        c.first=t.first+faktor*(c.first-t.first);
        a.second=t.second+faktor*(a.second-t.second);
        b.second=t.second+faktor*(b.second-t.second);
        c.second=t.second+faktor*(c.second-t.second);
        if (faktor<0) Rotiraj(t, Pi);
    }
    void Rotiraj(double ugao) {
        Tacka t;
        t.first=DajCentar().first;
        t.second=DajCentar().second;
        Rotiraj(t, ugao);
    }
    void Skaliraj(double faktor) {
        Tacka t;
        t.first=DajCentar().first;
        t.second=DajCentar().second;
        Skaliraj(t, faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if(JesuLiJednaki(t1.a.first,t2.a.first) && JesuLiJednaki(t1.a.second,t2.a.second) && JesuLiJednaki(t1.b.first,t2.b.first) && JesuLiJednaki(t1.b.second,t2.b.second) && JesuLiJednaki(t1.c.first,t2.c.first) && JesuLiJednaki(t1.c.second,t2.c.second)) return 1;
    if(JesuLiJednaki(t1.a.first,t2.a.first) && JesuLiJednaki(t1.a.second,t2.a.second) && JesuLiJednaki(t1.b.first,t2.c.first) && JesuLiJednaki(t1.b.second,t2.c.second) && JesuLiJednaki(t1.c.first,t2.b.first) && JesuLiJednaki(t1.c.second,t2.b.second)) return 1;
    if(JesuLiJednaki(t1.a.first,t2.b.first) && JesuLiJednaki(t1.a.second,t2.b.second) && JesuLiJednaki(t1.b.first,t2.a.first) && JesuLiJednaki(t1.b.second,t2.a.second) && JesuLiJednaki(t1.c.first,t2.c.first) && JesuLiJednaki(t1.c.second,t2.c.second)) return 1;
    if(JesuLiJednaki(t1.a.first,t2.b.first) && JesuLiJednaki(t1.a.second,t2.b.second) && JesuLiJednaki(t1.b.first,t2.c.first) && JesuLiJednaki(t1.b.second,t2.c.second) && JesuLiJednaki(t1.c.first,t2.a.first) && JesuLiJednaki(t1.c.second,t2.a.second)) return 1;
    if(JesuLiJednaki(t1.a.first,t2.c.first) && JesuLiJednaki(t1.a.second,t2.c.second) && JesuLiJednaki(t1.b.first,t2.a.first) && JesuLiJednaki(t1.b.second,t2.a.second) &&JesuLiJednaki(t1.c.first,t2.b.first) && JesuLiJednaki(t1.c.second,t2.b.second)) return 1;
    if(JesuLiJednaki(t1.a.first,t2.c.first) && JesuLiJednaki(t1.a.second,t2.c.second) && JesuLiJednaki(t1.b.first,t2.b.first) && JesuLiJednaki(t1.b.second,t2.b.second) && JesuLiJednaki(t1.c.first,t2.a.first) && JesuLiJednaki(t1.c.second,t2.a.second)) return 1;
    return 0; 
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        
    if(t1.DaLiJePozitivnoOrijentiran()==1 && t2.DaLiJePozitivnoOrijentiran()==1) {
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(1))  && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(2)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(1))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(2)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(3)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(2))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(3)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(2))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(1)) )return 1;

    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==-1 && Trougao::Orijentacija(t2.a, t2.b, t2.c)==-1) {
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(1))  && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(2)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(1))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(2)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(3)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(2))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(1)) )return 1;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==1 && Trougao::Orijentacija(t2.a, t2.b, t2.c)==-1) {
        
  if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(2))  && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(1)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(2))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(3)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(1))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(2)) )return 1;
    
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==-1 && Trougao::Orijentacija(t2.a, t2.b, t2.c)==1) {
         if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(2))  && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(1)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(2))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(3)) )return 1;
        if(JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(1))  && JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(2)) )return 1;
    
    }
    return 0;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        if(t1.DaLiJePozitivnoOrijentiran()==1 && t2.DaLiJePozitivnoOrijentiran()==1) {
        if(JesuLiJednaki((t1.DajStranicu(3)/t2.DajStranicu(3)) , (t1.DajStranicu(1)/t2.DajStranicu(1))) && JesuLiJednaki(t1.DajStranicu(3)/t2.DajStranicu(3), (t1.DajStranicu(2)/t2.DajStranicu(2))) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)/t2.DajStranicu(1) )return 1;

    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==-1 && Trougao::Orijentacija(t2.a, t2.b, t2.c)==-1) {
        if(t1.DajStranicu(3)/t2.DajStranicu(3) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(2) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)==t2.DajStranicu(1) )return 1;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==1 && Trougao::Orijentacija(t2.a, t2.b, t2.c)==-1) {
        if(t1.DajStranicu(3)/t2.DajStranicu(3) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(1) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)/t2.DajStranicu(2) )return 1;

    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==-1 && Trougao::Orijentacija(t2.a, t2.b, t2.c)==1) {
        if(t1.DajStranicu(3)/t2.DajStranicu(3) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(1) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)/t2.DajStranicu(2) )return 1;

    }
return 0; 
    }

};
int main()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v;
     double x, y, x2, y2, x3, y3;
     Tacka a,b,c; 
    try {
        for(int i=0; i<n; i++) {
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x;
        std::cin>>y;
        a.first=x;
        a.second=y;
        std::cin>>x2;
        std::cin>>y2;
        b.first=x2;
        b.second=y2;
        std::cin>>x3;
        std::cin>>y3;
        c.first=x3;
        c.second=y3;
            try {
                v.emplace_back(new Trougao(a,b,c));
            } catch (std::domain_error iz) {
                std::cout<<iz.what()<<", ponovite unos"<<std::endl;
                i--;
            }
        }
       
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double delta_x, delta_y;
        std::cin>>delta_x>>delta_y;
        std::transform(v.begin(), v.end(), v.begin(), [delta_x,delta_y](std::shared_ptr<Trougao> &pok) {
            Trougao pom((*pok).DajTjeme(1),(*pok).DajTjeme(2),(*pok).DajTjeme(3));
            pok=nullptr;
            pom.Transliraj(delta_x, delta_y);
            pok=std::make_shared<Trougao>(pom.DajTjeme(1),pom.DajTjeme(2),pom.DajTjeme(3));
            return pok;
        });
        std::cout<<"Unesite ugao rotacije: ";
        double alfa;
        std::cin>>alfa;
        std::transform(v.begin(), v.end(), v.begin(), [alfa](std::shared_ptr<Trougao> &pok) {
            Trougao pom((*pok).DajTjeme(1),(*pok).DajTjeme(2),(*pok).DajTjeme(3));
            pok=nullptr;
            pom.Rotiraj(alfa);
            pok=std::make_shared<Trougao>(pom.DajTjeme(1),pom.DajTjeme(2),pom.DajTjeme(3));
            return pok;
        });
         std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::transform(v.begin(), v.end(), v.begin(), [faktor](std::shared_ptr<Trougao>&p) {
        p->Skaliraj(p->DajTjeme(1), faktor);
        return p;
    });
       
        std::sort(v.begin(), v.end(),  [](std::shared_ptr<Trougao> pok1,std::shared_ptr<Trougao> pok2 ) {
            if(pok1->DajPovrsinu()<pok2->DajPovrsinu()) return true;
            else return false;
        });
        std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
        std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> pok) {
            pok->Ispisi();
            std::cout<<std::endl;
        });
        auto pok3=std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> pok1,std::shared_ptr<Trougao> pok2 ) {
            return (pok1->DajObim()<pok2->DajObim());
          
        });
        std::cout<<"Trougao sa najmanjim obimom: ";
        (*pok3)->Ispisi();
        
        int g=0;
        std::vector<int> postoji; 
        for(int i=0; i<n; i++) {  
            for(int j=i+1; j<n; j++) {
                if(DaLiSuIdenticni(*(v[i]), *(v[j]))&& i!=j) { g++; 
                if(g==1) std::cout<<"\nParovi identicnih trouglova:"<<std::endl;
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                     }
                }
            }
        if(g==0) std::cout<<"\nNema identicnih trouglova!\n"; 
       
        g=0;
       
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(DaLiSuPodudarni(*(v[i]), *(v[j]))&& i!=j) { g++; 
                     if(g==1 )  std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                }
            }
        }
      if(g==0 ) std::cout<<"Nema podudarnih trouglova!\n";
        g=0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(DaLiSuSlicni(*(v[i]), *(v[j]))&& i!=j) {
                   g++; 
                     if(g==1 )std::cout<<"Parovi slicnih trouglova:"<<std::endl; 
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                }
            }
        }
        if(g==0 ) std::cout<<"Nema slicnih trouglova!\n";
    } catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!";
    }
    for(int i=0; i<v.size(); i++)v[i]=nullptr;
    return 0;
}