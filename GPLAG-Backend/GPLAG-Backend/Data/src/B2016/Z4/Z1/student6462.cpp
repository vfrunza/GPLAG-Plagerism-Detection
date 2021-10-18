/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka ;

const double Eps(1e-10);

Tacka TackaDobivenaRotacijom(const Tacka &t, const Tacka &x, double ugao) {
    Tacka nova;
    nova.first = t.first + (x.first - t.first) * cos(ugao) - (x.second - t.second) * sin(ugao);
    nova.second = t.second + (x.first - t.first) * sin(ugao) + (x.second - t.second) * cos(ugao);
    return nova;
}

Tacka TackaNakonSkaliranja(const Tacka &t, const Tacka &x, double faktor) {
    Tacka nova;
    nova.first = t.first + faktor * (x.first - t.first);
    nova.second = t.second + faktor * (x.second - t.second);
    return nova;
}

class Trougao {
    Tacka a, b, c;
    
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        a=t1;  b=t2;  c=t3;
    }
    
    void Postavi(int indeks, const Tacka &t);
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double x = t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
        if (x > 0) return 1;
        else if (x < 0) return -1;
        else return 0;
    }
    
    Tacka DajTjeme(int indeks) const {
        if (indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        if (indeks == 1) return a;
        else if (indeks == 2) return b;
        else return c;
    }
    
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const; 
    
    Tacka DajCentar() const {
        Tacka t;
        t.first = (a.first + b.first + c.first) / 3;
        t.second = (a.second + b.second + c.second) / 3;
        return t;
    }
    
    double DajObim() const {
       double s_a=DajStranicu(1);  double s_b=DajStranicu(2);  double s_c=DajStranicu(3);
       return s_a + s_b + s_c;
    }
    
    double DajPovrsinu() const {
        return 0.5 * (fabs(a.first*(b.second-c.second) - b.first*(a.second-c.second) + c.first*(a.second-b.second)));
    }
    
    bool DaLiJePozitivnoOrijentiran() const {
        double x = a.first*(b.second - c.second) - b.first*(a.second-c.second) + c.first*(a.second - b.second);
        if (x > 0) return true;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const { std::cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))"; }
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
};

void Trougao::Postavi(int indeks, const Tacka &t) {
    if (indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
 //   if (Orijentacija(a, b, t)==0 || Orijentacija(a, t, c)==0 || Orijentacija(t, b, c)==0)
   //     throw std::domain_error("Nekorektne pozicije tjemena");
    if (indeks == 1) a=t;
    else if (indeks == 2) b=t;
    else c=t;
}

double Trougao::DajStranicu(int indeks) const {
    if (indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
    if (indeks == 1)
        return sqrt(((c.first-b.first) * (c.first-b.first)) + ((c.second-b.second) * (c.second-b.second)));
    if (indeks == 2)
        return sqrt(((c.first-a.first) * (c.first-a.first)) + ((c.second-a.second) * (c.second-a.second)));
    else return sqrt(((b.first-a.first) * (b.first-a.first)) + ((b.second-a.second) * (b.second-a.second)));
}

double Trougao::DajUgao(int indeks) const {
    if (indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
    double s_a=DajStranicu(1);
    double s_b=DajStranicu(2);
    double s_c=DajStranicu(3);
    double alfa = acos((s_b*s_b + s_c*s_c - s_a*s_a) / 2*s_b*s_c);
    double beta = acos((s_a*s_a + s_c*s_c - s_b*s_b) / 2*s_a*s_c);
    double gama = acos((s_a*s_a + s_b*s_b - s_c*s_c) / 2*s_a*s_b);
    if (indeks == 1) return alfa;
    else if (indeks == 2) return beta;
    else return gama;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    bool unutra=false;
    if (Orijentacija(a, b, t) == 1 && Orijentacija(a, b, c) == 1 && Orijentacija(b, c, t) == 1 && Orijentacija(c, a, t) == 1)
        unutra=true;
        return unutra;
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    Tacka nova_a(a.first+delta_x, a.second+delta_y);
    Postavi(1, nova_a);
    Tacka nova_b(b.first+delta_x, b.second+delta_y);
    Postavi(2, nova_b);
    Tacka nova_c(c.first+delta_x, c.second+delta_y);
    Postavi(3, nova_c);
}

void Trougao::Centriraj(const Tacka &t) {
    Tacka centar=DajCentar();
    double x=t.first-centar.first;
    double y=t.second-centar.second;
    do {
        Transliraj(x, y);
    }
    while (fabs(centar.first-t.first)>Eps && fabs(centar.second-t.second)>Eps);
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    Tacka nova_a=TackaDobivenaRotacijom(t, a, ugao);
    Postavi(1, nova_a);
    Tacka nova_b=TackaDobivenaRotacijom(t, b, ugao);
    Postavi(2, nova_b);
    Tacka nova_c=TackaDobivenaRotacijom(t, c, ugao);
    Postavi(3, nova_c);
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if (faktor == 0) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka nova_a=TackaNakonSkaliranja(t, a, faktor);
    Postavi(1, nova_a);
    Tacka nova_b=TackaNakonSkaliranja(t, b, faktor);
    Postavi(2, nova_b);
    Tacka nova_c=TackaNakonSkaliranja(t, c, faktor);
    Postavi(3, nova_c);
}

void Trougao::Rotiraj(double ugao) {
    Tacka centar=DajCentar();
    Tacka nova_a=TackaDobivenaRotacijom(centar, a, ugao);
    Postavi(1, nova_a);
    Tacka nova_b=TackaDobivenaRotacijom(centar, b, ugao);
    Postavi(2, nova_b);
    Tacka nova_c=TackaDobivenaRotacijom(centar, c, ugao);
    Postavi(3, nova_c);
}

void Trougao::Skaliraj(double faktor) {
    if (faktor == 0) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka centar=DajCentar();
    Tacka nova_a=TackaNakonSkaliranja(centar, a, faktor);
    Postavi(1, nova_a);
    Tacka nova_b=TackaNakonSkaliranja(centar, b, faktor);
    Postavi(2, nova_b);
    Tacka nova_c=TackaNakonSkaliranja(centar, c, faktor);
    Postavi(3, nova_c);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
   int brojac{};
   Tacka x1=t1.DajTjeme(1), y1=t1.DajTjeme(2), z1=t1.DajTjeme(3);
   Tacka x2=t2.DajTjeme(1), y2=t2.DajTjeme(2), z2=t2.DajTjeme(3);
 
   if ((fabs(x1.first - x2.first)<Eps && fabs(x1.second-x2.second)<Eps) || (fabs(x1.first - y2.first)<Eps && fabs(x1.second-y2.second)<Eps) || (fabs(x1.first-z2.first)<Eps && fabs(x1.second-z2.second)<Eps)) brojac++;
    if ((fabs(y1.first-x2.first)<Eps && fabs(y1.second-x2.second)<Eps) || (fabs(y1.first-y2.first)<Eps && fabs(y1.second-y2.second)<Eps) ||  (fabs(y1.first-z2.first)<Eps && fabs(y1.second-z2.second)<Eps)) brojac++;
    if ((fabs(z1.first-x2.first)<Eps && fabs(z1.second-x2.second)<Eps) || (fabs(z1.first-y2.first)<Eps && fabs(y1.second-y2.second)<Eps) || (fabs(z1.first-z2.first)<Eps && fabs(z1.second-z2.second)<Eps)) brojac++;
   
   if (brojac>=2) return true;
   else {
       //std::cout<<"Nema identicnih trouglova!"<<std::endl;
        return false;
   }
}

/*bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    int stranice{};
    double x1=t1.DajStranicu(1), y1=t1.DajStranicu(2), z1=t1.DajStranicu(3);
    double x2=t2.DajStranicu(1), y2=t2.DajStranicu(2), z2=t2.DajStranicu(3);
   
    if (fabs(x1-x2)<Eps || fabs(x1-y2)<Eps || fabs(x1-z2)<Eps) stranice++;
    else if (fabs(y1-x2)<Eps || fabs(y1-y2)<Eps || fabs(y1-z2)<Eps) stranice++;
    else if (fabs(z1-x2)<Eps || fabs(z1-y2)<Eps || fabs(z1-z2)<Eps) stranice++;
    
    
    
    if (stranice>=3 && (Orijentacija(t1.a, t1.b, t1.c)==Orijentacija(t2.a, t2.b, t2.c) || Orijentacija(t1.a, t1.b, t1.c)==O)) return true;
    return false;
}*/

int main ()
{
    int n{};
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao> > v(n);
    int i{};
    for (i=0; i<n; i++) {
        double x1{}, y1{}, x2{}, y2{}, x3{}, y3{};
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        try {
           v[i] = std::make_shared<Trougao> (Tacka(x1, y1), Tacka(x2, y2), Tacka(x3, y3));
        }
        catch(std::domain_error e) {
           std::cout<<e.what()<<", ponovite unos!"<<std::endl;
           i--;
        }
    }
    
    double dx{}, dy{};
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    
    double ugao{};
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    
    double faktor{};
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    
   std::transform(v.begin(), v.end(), v.begin(), [dx, dy](std::shared_ptr<Trougao> t) { t->Transliraj(dx, dy); return t; });
   std::transform(v.begin(), v.end(), v.begin(), [ugao](std::shared_ptr<Trougao> t) {t->Rotiraj(ugao); return t; });
   std::transform(v.begin(), v.end(), v.begin(), [faktor](std::shared_ptr<Trougao> t) {
        t->Skaliraj(t->DajTjeme(1), faktor);
        return t;
    });
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajPovrsinu() < t2->DajPovrsinu();
    });
    
   
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) { t->Ispisi(); std::cout<<std::endl; });
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    Trougao t = **std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) { 
       return t1->DajObim() < t2->DajObim(); });
    t.Ispisi();
    std::cout<<std::endl;
    
    bool y=false;
    int k{}, l{};
    
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v.size(); j++) {
            if (i == j) continue;
            
            y = DaLiSuIdenticni(*v[i], *v[j]);
            if (y == true)  {
                k=i; l=j;
                //IspisiIdenticne()
            }
        }
    }
        
    if (y==true) {
       std::cout<<"Parovi identicnih trouglova: "<<std::endl;
       v[k]->Ispisi();
       std::cout<<" i ";
       v[l]->Ispisi();
       std::cout<<std::endl;
    }
    
   // else if (y == false) std::cout<<"Nema parova identicnih trouglova!"<<std::endl;
    
  /*  bool x;
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v.size(); j++) {
             x = DaLiSuPodudarni(*v[i], *v[j]);
            if (x==true) {
                std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
            }
        }
    }*/
  //  if (!x) std::cout<<"Nema podudarnih trouglova!";
	return 0;
}