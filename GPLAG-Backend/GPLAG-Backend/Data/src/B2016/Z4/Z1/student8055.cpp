/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <deque>
#include <algorithm>
#include <vector>
#include <memory>
typedef std::pair<double, double> Tacka;

const double PI=4*std::atan(1);


class Trougao {
    Tacka x,y,z;
   
    static bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
    return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
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
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
    x=t1;
    y=t2;
    z=t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
    x=t1;
    y=t2;
    z=t3;
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double izraz(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    if (izraz>0) return 1;
    else if (izraz<0) return -1;
    return 0;
    
}

 void Trougao::Postavi(int indeks, const Tacka &t) {
     if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
     if(indeks==1) {
         if(Orijentacija(t,y,z)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
         x=t;
     }
     if(indeks==2) {
         if(Orijentacija(x,t,z)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
         y=t;
     }
     if(indeks==3) {
         if(Orijentacija(x,y,t)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
         z=t;
     }
 }
 Tacka Trougao::DajTjeme(int indeks) const {
     if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
     if(indeks==1) return x;
     if(indeks==2) return y;
     if(indeks==3) return z;
 }
 
  double Trougao::DajStranicu(int indeks) const {
      if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
      if(indeks==1) return std::sqrt((y.first-z.first)*(y.first-z.first)+(y.second-z.second)*(y.second-z.second));
      if(indeks==2) return std::sqrt((x.first-z.first)*(x.first-z.first)+(x.second-z.second)*(x.second-z.second));
      if(indeks==3) return std::sqrt((y.first-x.first)*(y.first-x.first)+(y.second-x.second)*(y.second-x.second));
  }
 double Trougao::DajUgao(int indeks) const {
      if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
      double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
      if(indeks==1) return std::acos((b*b+c*c-a*a)/(2*b*c));
      if(indeks==2) return std::acos((a*a+c*c-b*b)/(2*a*c));
      if(indeks==3) return std::acos((b*b+a*a-c*c)/(2*b*a));
 }
 
 Tacka Trougao::DajCentar() const {
     Tacka t;
     t.first=(x.first+y.first+z.first)/3;
     t.second=(x.second+y.second+z.second)/3;
     
     return t;
 }
 
 double Trougao::DajObim() const {
     double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
     double izrazo=a+b+c;
     if(izrazo<0) izrazo*=-1;
     return izrazo;
 }
 double Trougao::DajPovrsinu() const {
     double izraz(x.first*(y.second-z.second)-y.first*(x.second-z.second)+z.first*(x.second-y.second));
     if(izraz<0) izraz*=-1;
     return 0.5*izraz;
 }
 
  bool Trougao::DaLiJePozitivnoOrijentiran() const {
      if(Orijentacija(x,y,z)==1) return true;
      return false;
  }
  
   bool Trougao::DaLiJeUnutra(const Tacka &t) const {
       if(Orijentacija(x,y,z)==1 && Orijentacija(x,y,t)==1 && Orijentacija(y,z,t)==1 && Orijentacija(z,x,t)==1)
       return true;
       if(Orijentacija(x,y,z)==-1 && Orijentacija(x,y,t)==-1 && Orijentacija(y,z,t)==-1 && Orijentacija(z,x,t)==-1)
       return true;
       return false;
   }
   
   void Trougao::Ispisi() const {
       std::cout<<"(("<<x.first<<","<<x.second<<"),("<<y.first<<","<<y.second<<"),("<<z.first<<","<<z.second<<"))";
   }
   
    void Trougao::Transliraj(double delta_x, double delta_y) {
        
        x={x.first+delta_x, x.second+delta_y};
        y={y.first+delta_x, y.second+delta_y};
        z={z.first+delta_x, z.second+delta_y};
        
    
    }
    
    void Trougao::Centriraj(const Tacka &t) {
        Tacka teziste(DajCentar());
        double delta_x(teziste.first-t.first);
        if (delta_x<0) delta_x*=-1;
        double delta_y(teziste.second-t.second);
        if (delta_y<0) delta_y*=-1;
        Transliraj(delta_x,delta_y);
    }
    
    void Trougao::Rotiraj(const Tacka &t, double ugao) {
        double a,b,c,d,e,f;
    a = (t.first + (x.first - t.first) * std::cos(ugao) - ((x.second - t.second) * std::sin(ugao)));
    b = (t.second + (x.first - t.first) * std::sin(ugao) + (x.second - t.second) * std::cos(ugao));
    c = (t.first + (y.first - t.first) * std::cos(ugao) - ((y.second - t.second) * std::sin(ugao)));
    d = (t.second + (y.first - t.first) * std::sin(ugao) + (y.second - t.second) * std::cos(ugao));
    e = (t.first + (z.first - t.first) * std::cos(ugao) - ((z.second - t.second) * std::sin(ugao)));
    f = (t.second + (z.first - t.first) * std::sin(ugao) + (z.second - t.second) * std::cos(ugao));
    
    x.first = a;
    x.second = b;
    y.first = c;
    y.second = d;
    z.first = e;
    z.second = f;

  }
    
     void Trougao::Skaliraj(const Tacka &t, double faktor) {
         if(JesuLiJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
         x={t.first+faktor*(x.first-t.first) , t.second+faktor*(x.second-t.second)};
         y={t.first+faktor*(y.first-t.first) , t.second+faktor*(y.second-t.second)};
         z={t.first+faktor*(z.first-t.first) , t.second+faktor*(z.second-t.second)};
     }
     
     void Trougao::Rotiraj(double ugao) {
         Rotiraj(DajCentar(),ugao);
     }
      void Trougao::Skaliraj(double faktor) {
          Skaliraj(DajCentar(),faktor);
      }
      
      bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
          std::deque<Tacka>d2{t2.x,t2.y,t2.z};
          auto it(std::find(d2.begin(),d2.end(),t1.x));
          if(it!=d2.end()) {
              d2.erase(it);
          }
          else return false;
          it=std::find(d2.begin(),d2.end(),t1.y);
          if(it!=d2.end(t1.second,t1.end)
              d2.erase(it);
          }
          else return false;
          if(DaLiSuPodudarni()==true)
          it=std::find(d2.begin(),d2.end(),t1.z);
          if(it!=d2.end()) {
              d2.erase(it);
          }
          else return false;
          return true;
      }
     
           bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
                
                std::vector<double> v,v1,u,u1;
                
                for(int i=0; i<3; i++) {
                    v.push_back(t1.DajStranicu(i+1));
                    v1.push_back(t2.DajStranicu(i+1));
                }
                
                for(int i=0; i<3; i++) {
                    u.push_back(t1.DajUgao(i+1));
                    u1.push_back(t2.DajUgao(i+1));
                }
                
                for(int i=0; i<3; i++) {
                    bool ima = false;
                    for(int j=0; j<3; j++) {
                    if (Trougao::JesuLiJednaki(v[i], v1[j]) && (Trougao::JesuLiJednaki(u[i], u1[j]))) {
                        ima = true;
                        break;
                    }
                    if(ima == false) return false;
                    }
                    return true;
                }
      
           }
      
    bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
       
       double a,b,c;
       
       a = t1.DajStranicu(1);
       b = t1.DajStranicu(2);
       c = t1.DajStranicu(3);
       
       double a1,b1,c1;
       a1 = t2.DajStranicu(1);
       b1 = t2.DajStranicu(2);
       c1 = t2.DajStranicu(3);
        
        
        return false;

    }

int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    double a,b,c,d, e, f;
    std::vector<std::shared_ptr<Trougao>>v(n);
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        
        std::cin>>a>>b>>c>>d>>e>>f;
        try {
            v[i]=std::make_shared<Trougao> (Trougao({a,b},{c,d},{e,f}));
        }
       catch(std::domain_error t) {
           std::cout<<t.what()<<std::endl;
           i--;
       }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double x,y;
    std::cin>>x>>y;
    std::transform(v.begin(),v.end(),v.begin(),[x,y](std::shared_ptr<Trougao> t){
        t->Transliraj(x,y);
        return t;
    });
    
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::transform(v.begin(),v.end(),v.begin(),[ugao](std::shared_ptr<Trougao> t){t->Rotiraj(ugao);return t;}); //
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor; 
    std::cin>>faktor;
    std::transform(v.begin(),v.end(),v.begin(),[faktor](std::shared_ptr<Trougao> t){t->Skaliraj(t->DajTjeme(1),faktor); return t;});
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
       return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
    
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> t){
        t->Ispisi();
        std::cout<<std::endl;}
    );
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto it=std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2)
    {return t1->DajObim()<t2->DajObim();});
    (*it)->Ispisi();
    std::cout<<std::endl;
    
    int br1=0;
     for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuIdenticni(*v[i],*v[j])) {
                if(br1 == 0)
                    std::cout<<"Parovi identicnih trouglova:"<<std::endl;
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                std::cout<<std::endl;
                br1++;
            }
        }
    }
    if(br1==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
    
    
    
    int br2=0;
     for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuPodudarni(*v[i],*v[j])) {
                if(br2 == 0)
                    std::cout<<"Parovi podudarnih trouglova:"<<std::endl;  
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                std::cout<<std::endl;
                br2++;
            }
        }
    }
    if(br2==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    
    
    
    int br=0;
     for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuSlicni(*v[i],*v[j])) {
                if(br == 0)
                    std::cout<<"Parovi slicnih trouglova:"<<std::endl;
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                std::cout<<std::endl;
                br++;
            }
        }
    }
    if(br==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
    
	return 0;
}
