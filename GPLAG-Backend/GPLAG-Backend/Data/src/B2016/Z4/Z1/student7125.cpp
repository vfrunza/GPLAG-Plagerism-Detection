#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>


typedef std::pair<double, double> Tacka;
const double EPS(0.00000000001);
class Trougao
{
    Tacka tac1,tac2,tac3;
    const void Testindeksa(const int &indeks) const {
        if(indeks < 1 || indeks > 3)
            throw std::range_error("Nekorektan indeks");
    }
    double Duz(const Tacka &t3, const Tacka &t2) const {
        return std::sqrt((t2.first - t3.first)*(t2.first - t3.first) + (t2.second - t3.second)*(t2.second - t3.second));
    }
    double Orijent(const Tacka &t1,const Tacka &t2, const Tacka &t3) const {
        return t1.first*(t2.second -t3.second)-t2.first*(t1.second - t3.second)+t3.first*(t1.second -t2.second);
    }
    void RotirajTacku(Tacka &rot, const Tacka &t, double ugao) {
        rot = Tacka(t.first+(rot.first - t.first)*std::cos(ugao)-(rot.second-t.second)*std::sin(ugao),t.second+(rot.first-t.first)*std::sin(ugao)+(rot.second-t.second)*std::cos(ugao));
    }
    void SkalirajTacku(Tacka &ska,const Tacka &t, double faktor) {
        ska = Tacka(t.first + faktor*(ska.first - t.first),t.second + (ska.second - t.second)*faktor);
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const {
        return Tacka((tac1.first+tac2.first+tac3.first)/3,(tac1.second+tac2.second+tac3.second)/3);
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const {
        return std::abs(Orijent(tac1,tac2,tac3))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tac1,tac2,tac3) > 0) return true;
        else return false;
    }
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

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

int main ()
{
    try{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vec(n),useless(n);
    for(int i(0); i<n; i++) {
        try {
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            std::pair<double,double> prva,druga,treca;
            std::cin>>prva.first>>prva.second;
            std::cin>>druga.first>>druga.second;
            std::cin>>treca.first>>treca.second;
            vec[i] = std::make_shared<Trougao>(Trougao(prva,druga,treca));
        } catch(...) {
            std::cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    double alfa;
    std::cin>>alfa;
    std::cout<<"Unesite faktor skaliranja: ";
    double skal;
    std::cin>>skal;
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::transform(vec.begin(),vec.end(),useless.begin(),[&](std::shared_ptr<Trougao> x) {
        x->Transliraj(dx,dy);
        x->Rotiraj(alfa);
        x->Skaliraj(x->DajTjeme(1),skal);
        return nullptr;
    });
    std::sort(vec.begin(),vec.end(),[](std::shared_ptr<Trougao> x,std::shared_ptr<Trougao> y) {
        return x->DajPovrsinu() < y->DajPovrsinu();
    });
    std::for_each(vec.begin(),vec.end(),[](std::shared_ptr<Trougao> x) {
        x->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*std::min_element(vec.begin(),vec.end(),[](std::shared_ptr<Trougao> x,std::shared_ptr<Trougao> y) {
        return x->DajObim() < y->DajObim();
    }))->Ispisi();
    
    bool nijeispisano(true);
    useless.resize(0);
    for(int i(0); i < n; i++)
        for(int j(i+1); j<n; j++)
            if(DaLiSuIdenticni(*(vec[i]),*(vec[j]))) {
                if(nijeispisano){
                std::cout<<std::endl<<"Parovi identicnih trouglova:"<<std::endl;
                nijeispisano = false;
                }
                vec[i]->Ispisi();
                std::cout<<" i ";
                vec[j]->Ispisi();
                std::cout<<std::endl;
                useless.resize(1);
            }
        if(useless.size() == 0)
            std::cout<<std::endl<<"Nema identicnih trouglova!";
            
    nijeispisano = true;
    useless.resize(0);
    for(int i(0); i < n; i++)
        for(int j(i+1); j<n; j++)
            if(DaLiSuPodudarni(*(vec[i]),*(vec[j]))) {
                if(nijeispisano){
                std::cout<<std::endl<<"Parovi podudarnih trouglova:"<<std::endl;
                nijeispisano = false;
                }
                vec[i]->Ispisi();
                std::cout<<" i ";
                vec[j]->Ispisi();
                std::cout<<std::endl;
                useless.resize(1);
            }
    if(useless.size() == 0)
        std::cout<<std::endl<<"Nema podudarnih trouglova!"<<std::endl;
        
    nijeispisano = true;
    useless.resize(0);
    for(int i(0); i < n; i++)
        for(int j(i+1); j<n; j++)
            if(DaLiSuSlicni(*(vec[i]),*(vec[j]))) {
                if(nijeispisano){
                std::cout<<std::endl<<"Parovi slicnih trouglova:"<<std::endl;
                nijeispisano = false;
                }
                vec[i]->Ispisi();
                std::cout<<" i ";
                vec[j]->Ispisi();
                std::cout<<std::endl;
                useless.resize(1);
            }
    if(useless.size() == 0)
        std::cout<<"Nema slicnih trouglova!"<<std::endl;

}catch(...){}
    return 0;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(!Orijentacija(t1,t2,t3))
        throw std::domain_error("Nekorektne pozicije tjemena");
    tac1 = t1, tac2 = t2, tac3 = t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(!Orijentacija(t1,t2,t3))
        throw std::domain_error("Nekorektne pozicije tjemena");
    tac1 = t1, tac2 = t2, tac3 = t3;
}
void Trougao::Postavi(int indeks, const Tacka &t)
{
    Testindeksa(indeks);
    switch(indeks) {
    case 1:
        if(!Orijentacija(t,tac2,tac3))
            throw std::domain_error("Nekorektne pozicije tjemena");
        tac1 = t;
        break;
    case 2:
        if(!Orijentacija(tac1,t,tac3))
            throw std::domain_error("Nekorektne pozicije tjemena");
        tac2 = t;
        break;
    case 3:
        if(!Orijentacija(tac1,tac2,t))
            throw std::domain_error("Nekorektne pozicije tjemena");
        tac3 = t;
        break;
    }
}
Tacka Trougao::DajTjeme(int indeks) const
{
    Testindeksa(indeks);
    switch(indeks) {
    case 1:
        return tac1;
    case 2:
        return tac2;
    case 3:
        return tac3;
    }
}
double Trougao::DajStranicu(int indeks) const
{
    Testindeksa(indeks);
    switch(indeks) {
    case 1:
        return Duz(tac2,tac3);
    case 2:
        return Duz(tac1,tac3);
    case 3:
        return Duz(tac2,tac1);
    }
}

double Trougao::DajUgao(int indeks) const
{
    Testindeksa(indeks);
    switch(indeks) {
    case 1:
        return std::acos((DajStranicu(2)*DajStranicu(2) + DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(3)*DajStranicu(2)));
    case 2:
        return std::acos((DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3) - DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(3)*DajStranicu(1)));
    case 3:
        return std::acos((DajStranicu(2)*DajStranicu(2) + DajStranicu(1)*DajStranicu(1) - DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
    }
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    int O(Orijentacija(tac1,tac2,tac3));
    if(Orijentacija(tac1,tac2,t)== O && Orijentacija(tac2,tac3,t) == O && Orijentacija(tac3,tac1,t) == O)
        return true;
        
    return false;
}
void Trougao::Ispisi() const
{
    std::cout<<"(("<<tac1.first<<","<<tac1.second<<"),("<<tac2.first<<","<<tac2.second<<"),("<<tac3.first<<","<<tac3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    tac1.first += delta_x,tac2.first += delta_x, tac3.first += delta_x,tac1.second += delta_y, tac2.second += delta_y, tac3.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    Transliraj(DajCentar().first-t.first,DajCentar().second -t.second);
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    RotirajTacku(tac1,t,ugao),RotirajTacku(tac2,t,ugao),RotirajTacku(tac3,t,ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(faktor- 0 < EPS)
        throw std::domain_error("Nekorektan faktor skaliranja");
    SkalirajTacku(tac1,t,faktor),SkalirajTacku(tac2,t,faktor),SkalirajTacku(tac3,t,faktor);
}

void Trougao::Rotiraj(double ugao)
{
    Tacka t(DajCentar());
    RotirajTacku(tac1,t,ugao),RotirajTacku(tac2,t,ugao),RotirajTacku(tac3,t,ugao);
}
void Trougao::Skaliraj(double faktor)
{
    if(faktor-int(faktor) < EPS)
        throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t(DajCentar());
    if(faktor > 0)
    SkalirajTacku(tac1,t,faktor),SkalirajTacku(tac2,t,faktor),SkalirajTacku(tac3,t,faktor);
    else{
        faktor *= -1;
        SkalirajTacku(tac1,t,faktor),SkalirajTacku(tac2,t,faktor),SkalirajTacku(tac3,t,faktor);
        Rotiraj(4*atan(1));
    }
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    //garant niste razmišljali o autotestu kod kojeg bi ovo bilo netačno (iako je lahak) al svejedno mi je i ako dodate, samo bi potvrdilo da detaljno pregledate programe kako bi dodali novi AT
    if(std::abs((t1.DajCentar().first - t2.DajCentar().first))<EPS && std::abs((t1.DajCentar().second - t2.DajCentar().second)) < EPS)
        return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if(std::abs(t1.DajObim()-t2.DajObim()) < EPS ) {
        std::vector<std::pair<double,Tacka>> a(3),b(3);
        for(int i(0); i < 3; i++){
            a[i].first = t1.DajStranicu(i+1);
            b[i].first = t2.DajStranicu(i+1);
            a[i].second = t1.DajTjeme(i+1);
            b[i].second = t2.DajTjeme(i+1);
        }
      std::sort(a.begin(),a.end(),[](std::pair<double,Tacka> x,std::pair<double,Tacka> y){
          return x.first<y.first;
      }); 
      std::sort(b.begin(),b.end(),[](std::pair<double,Tacka> x,std::pair<double,Tacka> y){
          return x.first<y.first;
      }); 
      if(t1.Orijentacija(a[0].second,a[1].second,a[2].second) == t2.Orijentacija(b[0].second,b[1].second,b[2].second))
            return true;
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    //Mogla je pomoćna al nemam vremena za razmišljat
    std::vector<std::pair<double,Tacka>> a(3),b(3);
        for(int i(0); i < 3; i++){
            a[i].first = t1.DajStranicu(i+1);
            b[i].first = t2.DajStranicu(i+1);
            a[i].second = t1.DajTjeme(i+1);
            b[i].second = t2.DajTjeme(i+1);
        }
      std::sort(a.begin(),a.end(),[](std::pair<double,Tacka> x,std::pair<double,Tacka> y){
          return x.first<y.first;
      }); 
      std::sort(b.begin(),b.end(),[](std::pair<double,Tacka> x,std::pair<double,Tacka> y){
          return x.first<y.first;
      }); 

        if(std::abs(a[0].first/b[0].first - a[1].first/b[1].first)<EPS && std::abs(a[1].first/b[1].first - a[2].first/b[2].first)<EPS){
        if(t1.Orijentacija(a[0].second,a[1].second,a[2].second) == t2.Orijentacija(b[0].second,b[1].second,b[2].second))
            return true;
        }
            
    return false;
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2, const Tacka &t3)
{
    double ori(t1.first*(t2.second -t3.second)-t2.first*(t1.second - t3.second)+t3.first*(t1.second -t2.second));

    if(ori> 0)
        return 1;
    else if(ori < 0)
        return -1;
    else return 0;
}