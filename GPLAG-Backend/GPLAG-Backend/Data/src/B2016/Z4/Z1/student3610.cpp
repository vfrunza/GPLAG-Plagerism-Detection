/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<utility>
#include<stdexcept>
#include<cmath>
#include<vector>
#include<memory>
#include<algorithm>
#define pi  4*atan(1)
using std:: cout;
using std:: cin;
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t[3];
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const{if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");return t[indeks-1];}
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
Trougao:: Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
   try{
    Postavi(t1, t2, t3);
   }
   catch(...){throw;}
}
void Trougao:: Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    t[0]=t1; t[1]=t2; t[2]=t3;
    if(Orijentacija(t1, t2, t3)==0) throw std:: domain_error ("Nekorektne pozicije tjemena");
    
}
void Trougao:: Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    Tacka pomocna (Trougao::t[indeks-1]);
    Trougao::t[indeks-1]=t;
    if(Orijentacija(Trougao::t[0],Trougao:: t[1], Trougao::t[2])==0) {Trougao::t[indeks-1]=pomocna;throw std:: domain_error ("Nekorektne pozicije tjemena");}
}
 int Trougao:: Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double x(t1.first*(t2.second-t3.second) -t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second));
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
}
double Trougao:: DajStranicu(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
   int predznak(1);
   double x(0), y(0);
    for(int i=0; i<3; i++){
        if(i==indeks-1) continue;
        x+=predznak*t[i].first;
        y+=predznak*t[i].second;
        predznak=-1;
        
    }
    return std:: sqrt(x*x + y*y);
}
double Trougao:: DajUgao(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    double a(DajStranicu(indeks)), b, c;
    int pomocna(0);
    for (int i=0; i<3; i++){
        if(i==indeks-1) continue;
        if(pomocna==0) {b=DajStranicu(i+1);pomocna=1;}
        else c= DajStranicu(i+1);
    }
    return std::acos(( b*b + c*c - a*a)/(2*b*c));
    
}
Tacka  Trougao::DajCentar() const{
    double x(0), y(0);
    for ( int i=0; i<3; i++){
        x+=t[i].first;
        y+=t[i].second;
    }
    return std:: make_pair(x/3, y/3);
}
double Trougao:: DajObim() const{
    return(DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
}
 double Trougao:: DajPovrsinu() const{
     return std:: abs(t[0].first*(t[1].second-t[2].second) -t[1].first*(t[0].second-t[2].second) + t[2].first*(t[0].second-t[1].second));
 }
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(t[0], t[1], t[2])==1) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    int a(Orijentacija(Trougao::t[0], Trougao::t[1], Trougao::t[2])), b(Orijentacija(Trougao::t[0], Trougao::t[1], t)), c(Orijentacija(Trougao::t[1], Trougao::t[2], t)), d(Orijentacija(Trougao::t[2], Trougao::t[0], t));
    if(a==0 || b==0 || c==0) return true;
    if(a==b && b==c && c==d) return true;
    return false;
}
void Trougao:: Ispisi() const{
    cout << "(";
    for (int i=0; i<3; i++){
        cout << " ("<< t[i].first<< "," << t[i].second<<") ";
        if(i!=2) cout << ",";
    }
    cout << ")";
}
void Trougao:: Transliraj(double delta_x, double delta_y){
    for (int i=0; i<3; i++){
        t[i].first+= delta_x;
        t[i].second+=delta_y;
    }
}
void Trougao:: Centriraj(const Tacka &t){
    Tacka tez(DajCentar());
    Transliraj(t.first-tez.first, t.second-tez.second);
}
void Trougao:: Rotiraj(const Tacka &t, double ugao){
    for ( int i=0; i<3; i++){
        Trougao::t[i].first=t.first +(Trougao::t[i].first-t.first)*std:: cos(ugao) - (Trougao::t[i].second-t.second)*std::sin(ugao);
        Trougao::t[i].second=t.second +(Trougao::t[i].first-t.first)*std:: sin(ugao) +(Trougao::t[i].second-t.second)*std::cos(ugao);
    }
}
 void Trougao::Skaliraj(const Tacka &t, double faktor){
     if(std::fabs(faktor-0)<0.00001) throw std:: domain_error ("Nekorektan faktor skaliranja");
     for(int i=0; i<3; i++){
         Trougao::t[i].first=t.first+ std:: abs(faktor)*(Trougao:: t[i].first-t.first);
          Trougao::t[i].second=t.second+ std:: abs(faktor)*(Trougao:: t[i].second-t.second);
     }
     if(faktor<0) Rotiraj(pi);
 }
  void Trougao::Rotiraj(double ugao){
      Rotiraj(DajCentar(), ugao);
  }
  void Trougao::Skaliraj(double faktor){
      Skaliraj(DajCentar(), faktor);
  }
  bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
      int br(0);
      for (int i=0 ; i<3; i++){
          for(int  j=0; j<3; j++){
              if(std:: fabs(t1.t[i].first- t2.t[j].first)<0.00001 &&std:: fabs( t1.t[i].second-t2.t[j].second)<0.00001){ br++; break;}
          }
      }
      if(br==3) return true;
      return false;
  }
  bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
      int br(0),k1(-1),k2(-1);
      for(int i=0; i<3; i++){
          for ( int j=0; j<3; j++){
              if(br==3) break;
              if(br==1 && j==k1) continue;
              if(br== 2 &&(j==k1 || j==k2)) continue;
              if(std::fabs(t1.DajStranicu(i+1)-t2.DajStranicu(j+1))<0.00001){ br++; if(std:: fabs (t1.DajUgao(i+1)-t2.DajUgao(j+1)) >0.00001) return false;}
              
          }
      }
      if(br==3&& (t1.DaLiJePozitivnoOrijentiran()== t2.DaLiJePozitivnoOrijentiran())) return true;
      return false;
      
  }
  bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
      int min(1), min2(1);
      for( int i=0; i<3; i++){
          if(t1.DajStranicu(min)> t1.DajStranicu(i+1)) min= i+1;
      }
      for( int i=0; i<3; i++){
          if(t1.DajStranicu(min2)> t2.DajStranicu(i+1)) min2= i+1;
      }
      double k(min/min2);
      int br(0),k1(-1),k2(-1);
      for(int i=0; i<3; i++){
          for ( int j=0; j<3; j++){
              if(br==3) break;
              if(br==1 && j==k1) continue;
              if(br== 2 &&(j==k1 || j==k2)) continue;
              if(std::fabs(t1.DajStranicu(i+1)-k*t2.DajStranicu(j+1))<0.00001){ br++; if(std:: fabs (t1.DajUgao(i+1)-t2.DajUgao(j+1)) >0.00001) return false;}
              
          }
      }
      if(br==3&& (t1.DaLiJePozitivnoOrijentiran()== t2.DaLiJePozitivnoOrijentiran())) return true;
      return false;
      
  }
int main ()
{
    /*Trougao t(std:: make_pair(2,1), std:: make_pair(6,1), std:: make_pair(6,4));
    Trougao t2(std:: make_pair(1,3), std:: make_pair(1,7), std:: make_pair(4,3));
    cout << DaLiSuPodudarni(t,t2);*/
    cout << "Koliko zelite kreirati trouglova: ";
    int n; 
    cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for ( int i=0; i<n ; i++){
        try{
        cout << "Unesite podatke za " << i+1<<" . trougao (x1 y1 x2 y2 x3 y3):";
        Tacka t1, t2, t3;
        cin>> t1.first>> t1.second >>t2.first>>t2.second>> t3.first>> t3.second;
        
        Trougao t(t1,t2,t3);
        v[i]= std::shared_ptr<Trougao>(new Trougao(t));
        }
        catch(std:: domain_error e){
            cout << e.what()<< ", ponovite unos!"<< std:: endl;
            i--;
        }
        
    }
   
    cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    cin >> dx >> dy;
    cout << "Unesite ugao rotacije: ";
    double ugao;
    cin >> ugao;
    cout << "Unesite faktor skaliranja: ";
    double faktor;
    cin >> faktor;
  /* std:: transform(v.begin(), v.end(), v.begin(),[dx,dy](std:: shared_ptr<Trougao> t){t->Transliraj(dx,dy);});*/
   
	return 0;
}