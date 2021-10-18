/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;
const double  EPSILON = 1E-10;
typedef pair<double, double> Tacka;
double Distanca(Tacka tac1, Tacka tac2){ return sqrt(pow(tac1.first-tac2.first,2)+pow(tac1.second-tac2.second,2)); }
double Produkt(Tacka tac1, Tacka tac2, Tacka tac3){ return tac1.first*(tac2.second-tac3.second)-tac2.first*(tac1.second-tac3.second)+tac3.first*(tac1.second-tac2.second); }
bool Eq(double x,double y) { double infinitezimala {fabs(x-y)}; return infinitezimala<EPSILON;  }
class Trougao{
  Tacka tac[3];
  public: 
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
       if(Eq(Produkt(t1,t2,t3),0)) throw domain_error("Nekorektne pozicije tjemena");
    tac[0]=t1; tac[1]=t2; tac[2]=t3;
  };
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  void Postavi(int indeks, const Tacka &t);
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  Tacka DajTjeme(int indeks)const;
  double DajStranicu(int indeks)const;
  double DajUgao(int indeks) const;
  Tacka DajCentar()const {return { (tac[0].first+tac[1].first+tac[2].first)/3, (tac[0].second+tac[1].second+tac[2].second)/3 };}
  double DajObim()const{ return {Distanca(tac[0],tac[1])+Distanca(tac[1],tac[2])+Distanca(tac[2],tac[0])}; }
  double DajPovrsinu()const{ return fabs(Produkt(tac[0],tac[1],tac[2]))/2; }
  bool DaLiJePozitivnoOrijentiran()const{ if(Produkt(tac[0],tac[1],tac[2])>0) return true; else return false; }
  bool DaLiJeUnutra(const Tacka &t)const;
  void Ispisi()const{ cout << "(("<<tac[0].first<<","<<tac[0].second<<"),("<<tac[1].first<<","<<tac[1].second<<"),("<<tac[2].first<<","<<tac[2].second<<"))";}
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

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Eq(Produkt(t1,t2,t3),0)) throw domain_error("Nekorektne pozicije tjemena");
    tac[0]=t1; tac[1]=t2; tac[2]=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks>3 || indeks < 1 ) throw range_error("Nekorektan indeks");
    tac[indeks-1]=t;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Eq(Produkt(t1,t2,t3),0)) return 0;
    if(Produkt(t1,t2,t3)>0) return 1; 
    return -1;
}
Tacka Trougao::DajTjeme(int indeks)const{
    if(indeks >3 ||indeks<1) throw range_error("Nekorektan indeks");
    return tac[indeks-1];
}
double Trougao::DajStranicu(int indeks)const{
    if(indeks>3||indeks<1) { throw range_error("Nekorektan indeks"); }
    
    if (indeks==1) return Distanca(tac[1],tac[2]); 
    if (indeks==2) return Distanca(tac[0],tac[2]); 
    if (indeks==3) return Distanca(tac[0],tac[1]);
}
double Trougao::DajUgao(int indeks)const{
    if(indeks>3||indeks<1) throw range_error("Nekorektan indeks");
    double a = Distanca(tac[1],tac[2]); double b = Distanca(tac[0],tac[2]); double c = Distanca(tac[0], tac[1]);
    if(indeks == 1) return acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
    if(indeks == 2) return acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*b*c));
    if(indeks == 3) return acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(Orijentacija(tac[0],tac[1],tac[2]))
        if(Orijentacija(tac[0],tac[1],t))
                if(Orijentacija(tac[1],tac[2],t))
                        if(Orijentacija(tac[2],tac[1],t)) return true;
                        return false;
}
void Trougao::Transliraj(double delta_x,double  delta_y){
    for(int i{0}; i<3; i++) {tac[i].first+=delta_x; tac[i].second+=delta_y;}
}
void Trougao::Centriraj(const Tacka &t){ Transliraj(t.first-DajCentar().first, t.second-DajCentar().second);  }
void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka a=tac[0];
    Tacka b=tac[1];
    Tacka c=tac[2];
    tac[0].first=t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
    tac[1].first=t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
    tac[2].first=t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
    tac[0].second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
    tac[1].second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
    tac[2].second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
}
void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(const Tacka &t, double k){
    if(Eq(k,0))throw domain_error("Nekorektan faktor skaliranja");
    for(int i{0}; i<3; i++){
        tac[i].first = t.first+k*(tac[i].first-t.first);
        tac[i].second = t.second+k*(tac[i].second-t.second);
    }
}
void Trougao::Skaliraj(double k){
    Skaliraj(this->DajCentar(), k);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    
    
    
    bool Yaa = Eq(t1.tac[0].second, t2.tac[0].second);
    bool Xaa = Eq(t1.tac[0].first, t2.tac[0].first);
    bool Xbb = Eq(t1.tac[1].first, t2.tac[1].first);
    bool Ybb = Eq(t1.tac[1].second, t2.tac[1].second);
    bool Xcc = Eq(t1.tac[2].first, t2.tac[2].first);
    bool Ycc = Eq(t1.tac[2].second,t2.tac[2].second);
    if(  ( Xaa && Yaa && Xbb & Ybb && Xcc & Ycc ) || (Eq(t1.tac[0].first, t2.tac[1].first) && Eq(t1.tac[0].second, t2.tac[1].second) &&  Eq(t1.tac[1].first,t2.tac[0].first) && Eq(t1.tac[1].second, t2.tac[0].second) && Eq(t1.tac[2].first,t2.tac[2].first) && Eq(t1.tac[2].second,t2.tac[2].second))
    ||(Eq(t1.tac[0].first, t2.tac[2].first) && Eq(t1.tac[0].second,t2.tac[2].second) && Eq(t1.tac[1].first,t2.tac[1].first)&& Eq(t1.tac[1].second, t2.tac[2].second) && Eq(t1.tac[2].first, t2.tac[2].first) && Eq(t1.tac[2].second,t2.tac[2].second))
    ||( Eq(t1.tac[0].first, t2.tac[1].first) && Eq(t1.tac[0].second,t2.tac[1].second) && Eq(t1.tac[1].first, t2.tac[2].first) && Eq(t1.tac[1].second, t2.tac[2].second) && Eq(t1.tac[2].first, t2.tac[0].first) && Eq(t1.tac[2].second, t2.tac[0].second) )
    || ( Eq(t1.tac[0].first, t2.tac[2].first) && Eq(t1.tac[0].second, t2.tac[2].second) && Eq(t1.tac[1].first, t2.tac[0].first) && Eq(t1.tac[1].second, t2.tac[0].second) && Eq(t1.tac[2].first, t2.tac[1].first) && Eq(t1.tac[2].second, t2.tac[1].second))
    ||( Eq(t1.tac[0].first, t2.tac[0].first) && Eq(t1.tac[0].second, t2.tac[0].second) && Eq(t1.tac[1].first, t2.tac[2].first) && Eq(t1.tac[1].second, t2.tac[2].second) && Eq(t1.tac[2].first, t2.tac[1].first) && Eq(t1.tac[2].second, t2.tac[1].second) )) return true;
    else return false;
    
    
}
  bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
      Tacka a1x,a2x,b1x,b2x,c1x,c2x;
      double c1=Distanca(t1.tac[0], t1.tac[1]),c1p,c2=Distanca(t2.tac[0],t2.tac[1]),c2p,a1=Distanca(t1.tac[1],t1.tac[2]),a1p,a2=Distanca(t2.tac[1],t2.tac[2]),a2p, b1=Distanca(t1.tac[0],t1.tac[2]),b1p,b2=Distanca(t2.tac[0],t2.tac[2]),b2p;
      //pronalazenje refernetnih a1p,a2p,b2p,b1p,c1p,c2p
      if(a1>=b1 && a1>=c1){ a1p=a1; a1x=t1.tac[0];
          if(b1>=c1) { b1p=b1; c1p=c1; b1x=t1.tac[1]; c1x=t1.tac[2];}
          else       { b1p=c1; c1p=b1; b1x=t1.tac[2]; c1x=t1.tac[1];}
      } if (b1>=a1 && b1>=c1 ){ a1p=b1; a1x=t1.tac[1];
          if(a1>=c1) { b1p=a1; c1p=c1; b1x=t1.tac[0]; c1x=t1.tac[2];}
          else       { b1p=c1; c1p=a1; b1x=t1.tac[2]; c1x=t1.tac[0];}
      } if (c1>=a1 && c1>=b1) { a1p=c1; a1x=t1.tac[2];
          if(a1>=b1) { b1p=a1; c1p=b1; b1x=t1.tac[0]; c1x=t1.tac[1];}
          else       { b1p=b1; c1p=a1; b1x=t1.tac[1]; c1x=t1.tac[0];}
      }
      if(a2>=b2 && a2>=c2){ a2p=a2; a2x=t2.tac[0];
          if(b2>=c2) { b2p=b2; c2p=c2; b2x=t2.tac[1]; c2x=t2.tac[2];}
          else       { b2p=c2; c2p=b2; b2x=t2.tac[2]; c2x=t2.tac[1];}
      }if (b2>=a2 && b2>=c2 ){ a2p=b2; a2x=t2.tac[1];
          if(a2>=c2) { b2p=a2; c2p=c2; b2x=t2.tac[0]; c2x=t2.tac[2];}
          else       { b2p=c2; c2p=a2; b2x=t2.tac[2]; c2x=t2.tac[0];}
      } if (c2>=a2 && c2>=b2) { a2p=c2; a2x=t2.tac[2];
          if(a2>=b2) { b2p=a2; c2p=b2; b2x=t2.tac[0]; c2x=t2.tac[1];}
          else       { b1p=b2; c1p=a2; b2x=t2.tac[1]; c2x=t2.tac[0];}
      }
      bool big = Eq(a1p,a2p),medium=Eq(b1p,b2p),small=Eq(c1p,c2p);
      bool Okrenutost(Trougao::Orijentacija(a1x,b1x,c1x)==Trougao::Orijentacija(a2x,b2x,c2x));
      if(Okrenutost && big && medium && small )return true;
      return false;
  }
   bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
      Tacka a1x,a2x,b1x,b2x,c1x,c2x;
      double 
      c1=Distanca(t1.tac[0],t1.tac[1]),c1p=0,
      c2=Distanca(t2.tac[0],t2.tac[1]),c2p=0,
      a1=Distanca(t1.tac[1],t1.tac[2]),a1p=0,
      a2=Distanca(t2.tac[1],t2.tac[2]),a2p=0, 
      b1=Distanca(t1.tac[0],t1.tac[2]),b1p=0,
      b2=Distanca(t2.tac[0],t2.tac[2]),b2p=0;
      //pronalazenje refernetnih a1p,a2p,b2p,b1p,c1p,c2p
      if(a1>=b1 && a1>=c1){ a1p=a1; a1x=t1.tac[0];
          if(b1>=c1) { b1p=b1; c1p=c1; b1x=t1.tac[1]; c1x=t1.tac[2];}
          else       { b1p=c1; c1p=b1; b1x=t1.tac[2]; c1x=t1.tac[1];}
      }else if (b1>=a1 && b1>=c1 ){ a1p=b1; a1x=t1.tac[1];
          if(a1>=c1) { b1p=a1; c1p=c1; b1x=t1.tac[0]; c1x=t1.tac[2];}
          else       { b1p=c1; c1p=a1; b1x=t1.tac[2]; c1x=t1.tac[0];}
      }else if (c1>=a1 && c1>=b1) { a1p=c1; a1x=t1.tac[2];
          if(a1>=b1) { b1p=a1; c1p=b1; b1x=t1.tac[0]; c1x=t1.tac[1];}
          else       { b1p=b1; c1p=a1; b1x=t1.tac[1]; c1x=t1.tac[0];}
      }
      if(a2>=b2 && a2>=c2){ a2p=a2; a2x=t2.tac[0];
          if(b2>=c2) { b2p=b2; c2p=c2; b2x=t2.tac[1]; c2x=t2.tac[2];}
          else       { b2p=c2; c2p=b2; b2x=t2.tac[2]; c2x=t2.tac[1];}
      }else if (b2>=a2 && b2>=c2 ){ a2p=b2; a2x=t2.tac[1];
          if(a2>=c2) { b2p=a2; c2p=c2; b2x=t2.tac[0]; c2x=t2.tac[2];}
          else       { b2p=c2; c2p=a2; b2x=t2.tac[2]; c2x=t2.tac[0];}
      }else if (c2>=a2 && c2>=b2) { a2p=c2; a2x=t2.tac[2];
          if(a2>=b2) { b2p=a2; c2p=b2; b2x=t2.tac[0]; c2x=t2.tac[1];}
          else       { b1p=b2; c1p=a2; b2x=t2.tac[1]; c2x=t2.tac[0];}
      }
      double k = a1p/a2p, l=b1p/b2p, m=c1p/c2p;
      //Proporcionalnost stranica uz urbi
      bool big = Eq(k,l),medium=Eq(l,m),small=Eq(k,m);
      bool Okrenutost(Trougao::Orijentacija(a1x,b1x,c1x)==Trougao::Orijentacija(a2x,b2x,c2x));
      if(Okrenutost && big && medium && small )return true;
      return false;
  }
int main (){
    
    int broj_trouglova;
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> broj_trouglova;
  vector<shared_ptr<Trougao>> vektor_pokova(broj_trouglova,nullptr);
    for(int i{0}; i<broj_trouglova; i++){
        try{Tacka pomocna1, pomocna2, pomocna3; cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin >> pomocna1.first>>pomocna1.second;
        cin >>pomocna2.first>>pomocna2.second;
        cin >> pomocna3.first >> pomocna3.second;
        auto pok (make_shared<Trougao>(pomocna1,pomocna2,pomocna3));
        vektor_pokova[i]=pok;
        } catch(domain_error gre){
            cout << gre.what()<<", ponovite unos!"<<endl;
            i--;
        }
    }
    double dx, dy, ugao, koef;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> dx >>dy;
    cout << "Unesite ugao rotacije: ";
    cin >> ugao;
    cout << "Unesite faktor skaliranja: ";
    cin >> koef;
    transform(vektor_pokova.begin(), vektor_pokova.end(), vektor_pokova.begin(), [dx,dy,ugao,koef](shared_ptr<Trougao>p1){
       p1->Transliraj(dx,dy);p1->Rotiraj(ugao);p1->Skaliraj(p1->DajTjeme(1), koef); return p1;
    });
    sort(vektor_pokova.begin(), vektor_pokova.end(), [](shared_ptr<Trougao> pt1, shared_ptr<Trougao> pt2){return pt1->DajPovrsinu()<pt2->DajPovrsinu(); });
    vector<pair<Trougao, Trougao>> parovi;
    for(int i{0}; i<broj_trouglova-1; i++) for(int k{i+1}; k<broj_trouglova; k++) if(DaLiSuIdenticni(*vektor_pokova[i], *vektor_pokova[k]))  parovi.push_back(make_pair(*vektor_pokova[i],*vektor_pokova[k]));
    cout << "Trouglovi nakon obavljenih transformacija:"<<endl;
    for_each(vektor_pokova.begin(), vektor_pokova.end(), [](shared_ptr<Trougao>pt1){pt1->Ispisi(); cout <<endl;});
    cout << "Trougao sa najmanjim obimom: ";
     (*(min_element(vektor_pokova.begin(), vektor_pokova.end(), [](shared_ptr<Trougao> pt1, shared_ptr<Trougao> pt2){ return pt1->DajObim()<pt2->DajObim(); })))->Ispisi();
    cout <<endl; if (parovi.size()==0) cout << "Nema identicnih trouglova!"<<endl;
    else {
        cout <<"Parovi identicnih trouglova:"<<endl;
        for_each(parovi.begin(), parovi.end(), [](pair<Trougao, Trougao> p1){ p1.first.Ispisi(); 
        cout << " i ";
        p1.second.Ispisi(); cout <<endl;
            
        });
    }
        vector<pair<Trougao,Trougao>> parovi2;
        for(int i{0}; i<broj_trouglova-1; i++) for(int k{i+1}; k<broj_trouglova; k++) if(DaLiSuPodudarni(*vektor_pokova[i], *vektor_pokova[k])) parovi2.push_back(make_pair(*vektor_pokova[i],*vektor_pokova[k]));
    if (parovi2.size()==0) cout << "Nema podudarnih trouglova!"<<endl;
    else {
        cout <<"Parovi podudarnih trouglova:"<<endl;
        for_each(parovi2.begin(), parovi2.end(), [](pair<Trougao, Trougao> p1){ p1.first.Ispisi(); 
        cout << " i ";
        p1.second.Ispisi(); cout <<endl;
            
        });}
        vector<pair<Trougao,Trougao>> parovi3;
        for(int i{0}; i<broj_trouglova-1; i++) for(int k{i+1}; k<broj_trouglova; k++) if (DaLiSuSlicni(*vektor_pokova[i], *vektor_pokova[k])) parovi3.push_back(make_pair(*vektor_pokova[i], *vektor_pokova[k]));
	    if (parovi3.size()==0 )cout << "Nema slicnih trouglova!"<<endl;
    else {
        cout <<"Parovi slicnih trouglova:"<<endl;
        for_each(parovi3.begin(), parovi3.end(), [](pair<Trougao, Trougao> p1){ p1.first.Ispisi(); 
        cout << " i ";
        p1.second.Ispisi(); cout <<endl;
            
        });
    }
	return 0;
}