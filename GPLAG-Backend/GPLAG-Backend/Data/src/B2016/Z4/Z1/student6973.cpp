/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <set>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao{
  Tacka a,b,c;
  static double Pom(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  static bool Poredjenje(double a, double b){
    bool ok(false);
    if(std::abs(a - b) < 0.0000001) ok = true;
    return ok;
  };
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

double Trougao::Pom(const Tacka &t1, const Tacka &t2, const Tacka &t3){
  return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    int rezz(0);
    rezz = Pom(t1,t2,t3);
    if(rezz < 0) rezz = -1;
    else if(rezz == 0) rezz = 0;
    else if(rezz > 0) rezz = 1;
    return rezz;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
  Postavi(t1,t2,t3);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
  if(Poredjenje(Orijentacija(t1,t2,t3), 0)) throw std::domain_error("Nekorektne pozicije tjemena");
  a = t1; b = t2; c= t3;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
  if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
  if(indeks == 1){
    if(Poredjenje(Orijentacija(t,b,c),0)) throw std::domain_error("Nekorektne pozicije tjemena");
    a = t;
  }
  else if(indeks == 2){
    if(Poredjenje(Orijentacija(a,t,c),0)) throw std::domain_error("Nekorektne pozicije tjemena");
    b = t;
  }
  else {
    if(Poredjenje(Orijentacija(a,b,t),0)) throw std::domain_error("Nekorektne pozicije tjemena");
    c = t;
  }
}

Tacka Trougao::DajTjeme(int indeks) const {
  if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
  if(indeks == 1) return a;
  else if(indeks == 2) return b;
  else {
    return c;
  }
}

double Trougao::DajStranicu(int indeks) const {
  if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
  if(indeks == 1) return std::sqrt((b.first - c.first)*(b.first - c.first) + (b.second - c.second) * (b.second - c.second));
  else if(indeks == 2) return std::sqrt((a.first - c.first)*(a.first - c.first) + (a.second - c.second) * (a.second - c.second));
  else {
    return std::sqrt((b.first - a.first)*(b.first - a.first) + (b.second - a.second) * (b.second - a.second));
  }
}

double Trougao::DajUgao(int indeks) const {
  if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
  if(indeks == 1) return std::acos((DajStranicu(2) * DajStranicu(2) + DajStranicu(3) * DajStranicu(3) - DajStranicu(1) * DajStranicu(1))/
  (2*DajStranicu(2) * DajStranicu(3)));
  else if(indeks == 2) return std::acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(3) * DajStranicu(3) - DajStranicu(2) * DajStranicu(2))/
  (2*DajStranicu(1) * DajStranicu(3)));
  else {
    return std::acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(2) * DajStranicu(2) - DajStranicu(3) * DajStranicu(3))/
  (2*DajStranicu(2) * DajStranicu(1)));
  }
}

Tacka Trougao::DajCentar() const {
  Tacka t;
  t.first = (a.first + b.first + c.first)/3;
  t.second = (a.second + b.second + c.second)/3;
  return t;
}

double Trougao::DajObim() const {
  return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const {
  return (std::abs(Pom(a,b,c))/2);
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
  if(Poredjenje(Orijentacija(a,b,c), 1)) return true;
  else{
    return false;
  } 
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
  if(DaLiJePozitivnoOrijentiran()) {
    if(Orijentacija(a,b,t) == 1 && Orijentacija(b,c,t) == 1 && Orijentacija(c,a,t) == 1) return true;
    else return false;
  }
  else {
    if(Orijentacija(a,b,t) == -1 && Orijentacija(b,c,t) == -1 && Orijentacija(c,a,t) == -1) return true;
    else return false;
  }
  return false;
}

void Trougao::Ispisi() const {
  std::cout << "((" << a.first <<  "," << a.second << "),(" <<  b.first <<  "," << b.second << "),(" <<
   c.first <<  "," << c.second << "))" << std::endl;
}

void Trougao::Transliraj(double delta_x, double delta_y) {
  a.first += delta_x; a.second += delta_y;
  b.first += delta_x; b.second += delta_y;
  c.first += delta_x; c.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
  double delta_bx(b.first - a.first);
  double delta_by(b.second - a.second);
  double delta_cx(c.first - a.first);
  double delta_cy(c.second - a.second);
  double delta_ax(a.first - DajCentar().first);
  double delta_ay(a.second - DajCentar().second);
  a.first = t.first + delta_ax;
  a.second = t.second + delta_ay;
  b.first = a.first + delta_bx;
  b.second = a.second + delta_by;
  c.first = a.first + delta_cx;
  c.second = a.second + delta_cy;
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
  a.first = t.first + ((a.first - t.first) * std::cos(ugao)) - ((a.second - t.second) * std::sin(ugao));
  a.second = t.second + (a.first - t.first) * std::sin(ugao) - (a.second - t.second) * std::cos(ugao);
  b.first = t.first + (b.first - t.first) * std::cos(ugao) - (b.second - t.second) * std::sin(ugao);
  b.second = t.second + (b.first - t.first) * std::sin(ugao) - (b.second - t.second) * std::cos(ugao);
  c.first = t.first + (c.first - t.first) * std::cos(ugao) - (c.second - t.second) * std::sin(ugao);
  c.second = t.second + (c.first - t.first) * std::sin(ugao) - (c.second - t.second) * std::cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
  if(Poredjenje(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
  if(a == t) {
    b.first = a.first + faktor * (b.first - a.first);
    b.second = a.second + faktor * (b.second - a.second);
    c.first = a.first + faktor * (c.first - a.first);
    c.second = a.second + faktor * (c.second - a.second);
  }
  if(b == t) {
    a.first = b.first + faktor * (a.first - b.first);
    a.second = b.second + faktor * (a.second - b.second);
    c.first = b.first + faktor * (c.first - b.first);
    c.second = b.second + faktor * (c.second - b.second);
  }
  else if(c == t) {
    b.first = c.first + faktor * (b.first - c.first);
    b.second = c.second + faktor * (b.second - c.second);
    a.first = c.first + faktor * (a.first - c.first);
    a.second = c.second + faktor * (a.second - c.second);
  }
}

void Trougao::Rotiraj(double ugao) {
  a.first = DajCentar().first + ((a.first - DajCentar().first) * std::cos(ugao)) - ((a.second - DajCentar().second) * std::sin(ugao));
  a.second = DajCentar().second + ((a.first - DajCentar().first) * std::sin(ugao)) - ((a.second - DajCentar().second) * std::cos(ugao));
  b.first = DajCentar().first + (b.first - DajCentar().first) * std::cos(ugao) - (b.second - DajCentar().second) * std::sin(ugao);
  b.second = DajCentar().second + (b.first - DajCentar().first) * std::sin(ugao) - (b.second - DajCentar().second) * std::cos(ugao);
  c.first = DajCentar().first + (c.first - DajCentar().first) * std::cos(ugao) - (c.second - DajCentar().second) * std::sin(ugao);
  c.second = DajCentar().second + (c.first - DajCentar().first) * std::sin(ugao) - (c.second - DajCentar().second) * std::cos(ugao); 
}

void Trougao::Skaliraj(double faktor) {
  a.first = DajCentar().first + faktor * (a.first - DajCentar().first);
  a.second = DajCentar().second + faktor * (a.second - DajCentar().second); 
  b.first = DajCentar().first + faktor * (b.first - DajCentar().first);
  b.second = DajCentar().second + faktor * (b.second - DajCentar().second);
  c.first = DajCentar().first + faktor * (c.first - DajCentar().first);
  c.second = DajCentar().second + faktor * (c.second - DajCentar().second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
  if(t1.a == t2.a) {
    if(t1.b == t2.b && t1.c == t2.c) return true;
    else if(t1.b == t2. c && t1.c == t2.b) return true;
    return false;
  }
  else if(t1.a == t2.b) {
    if(t1.b == t2.a && t1.c == t2.c) return true;
    else if(t1.b == t2.c && t1.c == t2.a) return true;
    return false;
  }
  else if(t1.a == t2.c) {
    if(t1.b == t2.a && t1.c == t2.b) return true;
    else if(t1.b == t2.b && t1.c == t2.a) return true;
    return false;
  }
  return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
  std::multiset<double> m1{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)},
  m2{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
  auto it1(m1.begin());
  auto it2(m2.begin());
  double koeficijenti(*it1 / *it2);
  bool slicni(true);
  for(int i = 0; i < 3; i++) {
      double pom(*it1 / *it2);
      if(!Trougao::Poredjenje(pom,koeficijenti)) {
        slicni = false;
        break;
      }
      it1++;
      it2++;
  }
  return slicni;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
  int brojac(3);
  std::vector<double> v1{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)}, 
  v2{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
  bool podudarni(true);
  for(int i = 0; i < brojac; i++) {
    for(int j = 0; j < brojac; j++) {
      if(i < v1.size() && Trougao::Poredjenje(v1[i], v2[j])) {
        v1.erase(v1.begin() + i);
        v2.erase(v2.begin() + j);
        brojac--;
        j = -1;
      }
    }
    if(brojac != 0) podudarni = false;
    return podudarni;
  }
  
  return podudarni;
}

int main ()
{
  double PI=4*std::atan(1);
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    double a,b,c,d, e, f;
    std::vector<std::shared_ptr<Trougao>>v(n);
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        
        std::cin>>a>>b>>c>>d>>e>>f;
        try {
            v[i]=std::make_shared<Trougao> (Trougao(Tacka(a,b),Tacka(c,d),Tacka(e,f)));
        }
       catch(std::domain_error izuzetak) {
           std::cout<<izuzetak.what()<<std::endl;
           i--;
           std::cin.ignore();
           std::cin.clear();
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
    ugao*=(PI/180);
    std::transform(v.begin(),v.end(),v.begin(),[ugao](std::shared_ptr<Trougao> t){t->Rotiraj(ugao);return t;});
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
        }
    );
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto it=std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2)
    {return t1->DajObim()>t2->DajObim();});
    (*it)->Ispisi();
    std::cout<<"Parovi identicnih trouglova:"<<std::endl;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuIdenticni(*v[i],*v[j])) {
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                //std::cout<<std::endl;
            }
        }
    }
    
     std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
     for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuPodudarni(*v[i],*v[j])) {
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                std::cout<<std::endl;
            }
        }
    }
    
     std::cout<<"Parovi slicnih trouglova:"<<std::endl;
     int br=0;
     for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuSlicni(*v[i],*v[j])) {
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                std::cout<<std::endl;
                br++;
            }
        }
     }
	return 0;
}