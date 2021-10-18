/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair <double, double> Tacka;

class Trougao{
    Tacka t1, t2, t3;
    static double udaljenostIzmedjuDvijeTacke(const Tacka & t1, const Tacka & t2){
        return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)(t2.second-t1.second));
    }
    static bool JesuLiJednaki(double x, double y, double Eps=1e-10){
        return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
    }
    static bool JesuLiJednakeTacke(const Tacka& t1, const Tacka& t2){
        return JesuLiJednaki(t1.first, t2.first) && JesuLiJednaki(t1.second,t2.second);
    }
    static Tacka RotirajTacku(Tacka t,Tacka c, double ugao){
        Tacka r;
        r.first=c.first+(t.first-c.first)*cos(ugao);
        return r;
    }
    static Tacka SkalirajTacku(Tacka t, Tacka c, double faktor){
        Tacka s;
        s.first=c.first+faktor*(t.second-c.second);
        return s;
    }
    static double testiranje(const Tacka & t1, const Tacka & t2, const Tacka & t3){
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        }
    public:
    Trougao(const Tacka & t1, const Tacka & t2, const Tacka & t3){
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka & t1, const Tacka & t2, const Tacka & t3){
        if(Orijentacija(t1,t2,t3)==0){
            throw domain_error("Nekorektne pozicije tjemena");
        }
        this->t1=t1;
        this->t2=t2;
        this->t3=t3;
    }
    void Postavi(int indeks, const Tacka & t){
        if(indeks==1){
            Postavi(t,t2,t3);
        }
        if(indeks==2){
            Postavi(t1,t,t3);
        }
        if(indeks==3){
            Postavi(t1,t2,t);
        }
        else{
            throw range_error("Nekorektan indeks");
    }
}
static int Orijentacija(const Tacka & t1, const Tacka & t2, const Tacka & t3){
    double izraz=testiranje(t1,t2,t3);
    if(izraz>0) return 1;
    else if (izraz<0) return -1;
    else return 0;
};
Tacka DajTjeme(int indeks)const{
    if(indeks==1){
        return t1;
    }
else if(indeks==2){
    return t2;
}
else if(indeks==3){
    return t3;
}
else{
  throw range_error("Nekorektan indeks"); 
 }
}
double DajStranicu(int indeks)const{
    if(indeks==1){
        return UdaljenostIzmedjuDvijeTacke(t2,t3);
    }
else if(indeks==2){
    return UdaljenostIzmedjuDvijeTacke(t1,t3);
}
else if(indeks==3){
    return UdaljenostIzmedjuDvijeTacke(t1,t2);
}
else{
    throw range_error("Nekorektan indeks");
 }
}
double DajUgao(int indeks)const{
    double a=DajStranicu(1), b=DajStranicu(2), c=DajStranicu(3);
if(indeks==1){
    return acos((b*b+c*c-a*a)/(2*b*c));
}
else if(indeks==2){
    return acos((a*a+c*c-b*b)/(2*a*c));
}
else if(indeks==3){
    return acos((b*b+a*a-c*c)/(2*b*a));
}
else{
    throw range_error("Nekorektan indeks");
 }
}
Tacka DajCentar() const{
    Tacka t;
    t.first=(t1.first+t2.first+t3.first)/3;
    return t;
}
double DajObim() const{
    double a=DajStranicu(1), b=DajStranicu(2), c=DajStranicu(3);
    return a+b+c;
}
double DajPovrsinu() const{
    double izraz=fabs(testiranje(t1,t2,t3));
    return izraz*0.5;
}
bool DaLiJePozitivnoOrijentiran() const{
    return testiranje(t1,t2,t3)>0;
}
bool DaLiJeUnutra(const Tacka & t) const{
    
}
void Ispisi() const{
    cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","t2.second<<"),("<<t3.first<<","t3.second<<"))"<<endl;
}
void Transliraj(double delta_x,double delta_y){
    t1.first+=delta_x;
    t2.first+=delta_x;
    t3.first+=delta_x;
    t1.second+=delta_y;
    t2.second+=delta_y;
    t3.second+=delta_y;
}
void Centriraj(const Tacka & t){
    Tacka C=this->DajCentar();
    Transliraj(t.first-C.first,t.second-C.second);
}
void Rotiraj(const Tacka & t,double ugao){
    t1.rotirajTacku(t1,t,ugao);
    t2.rotirajTacku(t2,t,ugao);
    t3.rotirajTacku(t3,t,ugao);
}
void Skaliraj(const Tacka & t,double faktor){
    if(JesuLiJednaki(faktor,0)){
        throw domain_error("Nekorektan faktor skaliranja");
    }
    if(faktor<0){
        Rotiraj(t,atan(1)*4);
    }
    t1=SkalirajTacku(t1,t,faktor);
    t2=SkalirajTacku(t2,t,faktor);
    t3=SkalirajTacku(t3,t,faktor);
}
void Rotiraj(double ugao){
    Rotiraj(DajCentar(),faktor);
}
void Skaliraj(double ugao){
    Skaliraj(DajCentar(),faktor);
}
friend bool DaLiSuIdenticni(const Trougao & t1, const Trougao & t2){
    if(JesuLiJednakeTacke(t1.t1,t2.t1) && JesuLiJednakeTacke(t1.t2,t2.t2) && JesuLiJednakeTacke(t1.t3,t2.t3))||
       JesuLiJednakeTacke(t1.t1,t2.t1) && JesuLiJednakeTacke(t1.t2,t2.t3) && JesuLiJednakeTacke(t1.t3,t2.t2))||
       JesuLiJednakeTacke(t1.t1,t2.t2) && JesuLiJednakeTacke(t1.t2,t2.t1) && JesuLiJednakeTacke(t1.t3,t2.t3))||
       JesuLiJednakeTacke(t1.t1,t2.t2) && JesuLiJednakeTacke(t1.t2,t2.t3) && JesuLiJednakeTacke(t1.t3,t2.t1))||
       JesuLiJednakeTacke(t1.t1,t2.t3) && JesuLiJednakeTacke(t1.t2,t2.t1) && JesuLiJednakeTacke(t1.t3,t2.t2))||
       JesuLiJednakeTacke(t1.t1,t2.t3) && JesuLiJednakeTacke(t1.t2,t2.t2) && JesuLiJednakeTacke(t1.t3,t2.t1))||
){
    return true;
 }
return false;
}
friend bool DaLiSuPodudarni(const Trougao & t1, const Trougao & t2){
    double alfa1=t1.DajUgao(1), beta1=t1.DajUgao(2), gama1=t1.DajUgao(3);
    double alfa2=t2.DajUgao(1), beta2=t2.DajUgao(2), gama1=t2.DajUgao(3);
    
    double a1=t1.DajStranicu(1),b1=t1.DajStranicu(2),c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1),b2=t2.DajStranicu(2),c2=t2.DajStranicu(3);
}
Tacka A1,B1,C1,A2,B2,C2;
if(a1<=b1&&a1<=c1){
    A1=t1.t1;
    if(b1<c1){
        B1=t1.t2;
        C1=t1.t3;
    }else{
        B1=t1.t3;
        C1=t1.t2;
    }
}
else if(b1<=a1&&b1<=c1){
    A1=t1.t2;
    if(a1<c1){
        B1=t1.t1;
        C1=t1.t3;
    }else{
        B1=t1.t3;
        C1=t1.t1;
    }
}
else{
    A1=t1.t3;
    if(a1<b1){
        B1=t1.t1;
        C1=t1.t2;
    }else{
        B1=t1.t2;
        C1=t1.t1;
    }
}
if(a2<=b2&&a2<=c2){
    A2=t2.t1;
    if(b2<c2){
        B2=t2.t2;
        C2=t2.t3;
    }else{
        B2=t2.t3;
        C2=t2.t2;
    }
}
else if(b2<=a2&&b2<=c2){
    A2=t2.t2;
    if(a2<c2){
        B2=t2.t1;
        C2=t2.t3;
    }else{
        B2=t2.t3;
        C2=t2.t1;
    }
}
else{
    A2=t2.t3;
    if(a2<b2){
        B2=t2.t1;
        C2=t2.t2;
    }else{
        B2=t2.t2;
        C2=t2.t1;
    }
}

if(
   JesuLiJednaki(udaljenostIzmedjuDvijeTacke(A1,B1),udaljenostIzmedjuDvijeTacke(A2,B2))&&
   JesuLiJednaki(udaljenostIzmedjuDvijeTacke(A1,C1),udaljenostIzmedjuDvijeTacke(A2,C2))&&
   JesuLiJednaki(udaljenostIzmedjuDvijeTacke(B1,C1),udaljenostIzmedjuDvijeTacke(B2,C2))&&
   Orijentacija(A1,B1,C1)==Orijentacija(A2,B2,C2)
   )
   return true;
   return false;
}
friend bool DaLiSuSlicni(const Trougao & t1, const Trougao & t2){
    double alfa1=t1.DajUgao(1),beta1=t1.DajUgao(2),gama1=t1.DajUgao(3);
    double alfa2=t2.DajUgao(1),beta2=t2.DajUgao(2),gama2=t2.DajUgao(3);
    
    double a1=t1.DajStranicu(1),b1=t1.DajStranicu(2),c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1),b2=t2.DajStranicu(2),c2=t2.DajStranicu(3);
}
Tacka A1,B1,C1,A2,B2,C2;
if(a1<=b1&&a1<=c1){
      A1 = t1.t1;
      if(b1<c1){
        B1=t1.t2;
        C1=t1.t3;
      }else{
        B1=t1.t3;
        C1=t1.t2;
      }
  }
   else if(b1<=a1&&b1<=c1){
      A1 = t1.t2;
      if(a1<c1){
        B1=t1.t1;
        C1=t1.t3;
      }else{
        B1=t1.t3;
        C1=t1.t1;
      }
  }
   else{
      A1 = t1.t3;
      if(a1<b1){
        B1=t1.t1;
        C1=t1.t2;
      }else{
        B1=t1.t2;
        C1=t1.t1;
      }
  }


    if(a2<=b2&&a2<=c2){
      A2 = t2.t1;
      if(b2<c2){
        B2=t2.t2;
        C2=t2.t3;
      }else{
        B2=t2.t3;
        C2=t2.t2;
      }
  }
   else if(b2<=a2&&b2<=c2){
      A2 = t2.t2;
      if(a2<c2){
        B2=t2.t1;
        C2=t2.t3;
      }else{
        B2=t2.t3;
        C2=t2.t1;
      }
  }
   else{
      A2 = t2.t3;
      if(a2<b2){
        B2=t2.t1;
        C2=t2.t2;
      }else{
        B2=t2.t2;
        C2=t2.t1;
      }
  }

  a1=udaljenostIzmedjuDvijeTacke(A1,B1);
  b1=udaljenostIzmedjuDvijeTacke(A1,C1);
  c1=udaljenostIzmedjuDvijeTacke(B1,C1);

  a2=udaljenostIzmedjuDvijeTacke(A2,B2);
  b2=udaljenostIzmedjuDvijeTacke(A2,C2);
  c2=udaljenostIzmedjuDvijeTacke(B2,C2);

if(JesuLiJednaki(a1/a2,b1/b2)&&JesuLiJednaki(b1/b2,c1/c2))&&Orijentacija(A1,B1,C1)==Orijentacija(A2,B2,C2))
  return true;
  return false;
  }
};
int main(){
    int n;
    cout<<"Koliko zelite kreirati trouglova";
    cin>>n;
    vector<shared_ptr<Trougao> >(t,nullptr);
    for(int i=0;i<n;i++){
        cout<<"Unesite podatke za"<<i+1<<".trougao(x1 y1 x2 y2 x3 y3):";
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        try{
         t[i]=make_shared<Trougao>(Tacka(x1,y1),Tacka(x2,y2),Tacka(x3,y3));   
        }
        catch(domain_error e){
            cout<<e.what()<<endl;
            i--;
        }
    }
  double dx,dy,ugao,f;
  cout<<"Unesite vektor translacije (dx dy):";
  cin>>dx>>dy;
  cout<<"Unesite ugao rotacije:";
  cin>>ugao;
  cout<<"Unesite faktor skaliranja";
  cin>>f;
  transform(t.begin(),t.end(),t.begin(),[dx,dy,ugao,f](shared_ptr<Trougao>t){
      t->Transliraj(dx,dy);
      t->Rotiraj(ugao);
      t->Skaliraj(t->DajTjeme(1),f);
      return t
  });
  cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
  for_each(t.begin(),t.end(),[](shared_ptr<Triugao>t){
      t->Ispisi();
  }
);
 return 0;
)
  



    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
