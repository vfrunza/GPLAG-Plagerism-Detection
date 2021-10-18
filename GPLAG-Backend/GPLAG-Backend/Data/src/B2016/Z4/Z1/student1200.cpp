/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>

typedef std::pair<double, double> Tacka;

const double eps = 1E-10;

class Trougao {
    
    Tacka t1,t2,t3;
    
    static double PomocnaOrjentacija(Tacka t1, Tacka t2, Tacka t3) {
        return t1.first * ( t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
    }
    
    static void ProvjeriTjemena(Tacka t1, Tacka t2, Tacka t3) {
        auto rez = t1.first * ( t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
        if(DaLiSuJednaki(rez,0)) throw std::domain_error("Nekorektne pozicije tjemena");
    }
    
    static double UdaljenostIzmedjuDvijeTacke(const Tacka &a, const Tacka &b) {
        return std::sqrt( (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second) );
    }
    
    static void ProvjeriIndeks(int indeks) {
        if(indeks != 1 && indeks!=2 && indeks != 3) 
            throw std::range_error("Nekorektan indeks");
    }
    
    double Kosinusna(int indeks) const {
        if(indeks == 1)
            return (DajStranicu(2)*DajStranicu(2) + DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1) ) / ( 2 * DajStranicu(2)*DajStranicu(3) ) ;
        else if(indeks == 2)
            return (DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3) - DajStranicu(2)*DajStranicu(2) ) / ( 2 * DajStranicu(1)*DajStranicu(3) ) ;
        else
            return (DajStranicu(1)*DajStranicu(1) + DajStranicu(2)*DajStranicu(2) - DajStranicu(3)*DajStranicu(3) ) / ( 2 * DajStranicu(1)*DajStranicu(2) ) ;
    }
    
    static bool DaLiSuJednaki(double a, double b) {
        return std::fabs(a-b) < eps;
    }
    
    static bool IstaOrijentacija(Trougao t1, Trougao t2, int x,int y, int z, int a, int b, int c) {
        return (t1.Orijentacija(t1.DajTjeme(x),t1.DajTjeme(y), t1.DajTjeme(z)) == t2.Orijentacija(t2.DajTjeme(a), t2.DajTjeme(b), t2.DajTjeme(c)));
    }
    
    static bool DaLiSuProporcionalne(double a,double b, double c) {
        if(a<1) a = 1./a;
        if(b<1) b = 1./b;
        if(c<1) c = 1./c;
        return DaLiSuJednaki(a,b) && DaLiSuJednaki(a,c);
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        ProvjeriTjemena(t1,t2,t3);
        Trougao::t1 = t1;
        Trougao::t2 = t2;
        Trougao::t3 = t3;
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        ProvjeriTjemena(t1,t2,t3);
        Trougao::t1 = t1;
        Trougao::t2 = t2;
        Trougao::t3 = t3;
    }
    
    void Postavi(int indeks, const Tacka &t) {
        ProvjeriIndeks(indeks);
        if(indeks == 1 ) {
            ProvjeriTjemena(t,t2,t3);
            t1 = t;
        }
        else if(indeks == 2) {
            ProvjeriTjemena(t1,t,t3);
            t2 = t;
        }
        else if(indeks == 3) {
            ProvjeriTjemena(t1,t2,t);
            t3 = t;
        }
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(PomocnaOrjentacija(t1,t2,t3)>0)
            return 1;
        else if(PomocnaOrjentacija(t1,t2,t3)<0)
            return -1;
        else return 0;
    }
    
    Tacka DajTjeme(int indeks) const {
        ProvjeriIndeks(indeks);
        if(indeks == 1 ) return t1;
        else if(indeks ==2) return t2;
        else if(indeks == 3) return t3;
        else throw "belaj";
    }
    
    double DajStranicu(int indeks) const {
       ProvjeriIndeks(indeks);
        if(indeks == 1) return UdaljenostIzmedjuDvijeTacke(t2,t3);
        else if(indeks == 2) return UdaljenostIzmedjuDvijeTacke(t1,t3);
        else return UdaljenostIzmedjuDvijeTacke(t1,t2);
    }
    
    double DajUgao(int indeks) const {
        ProvjeriIndeks(indeks);
        auto p = Kosinusna(indeks);
        return acos(p); 
    }
    ///
    Tacka DajCentar() const {
        long double x = (t1.first + t2.first + t3.first)/3.;
        long double y = (t1.second + t2.second + t3.second)/3.;
        return std::make_pair(x,y);
    }
    double DajObim() const { return DajStranicu(1) + DajStranicu(2) + DajStranicu(3); }
    
    double DajPovrsinu() const { return fabs(PomocnaOrjentacija(t1,t2,t3))/2.; }
    
    bool DaLiJePozitivnoOrijentiran() const {
        return (Orijentacija(t1,t2,t3) > 0) ? true : false;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const {
        return (Orijentacija(t1,t2,t3) == Orijentacija(t1,t2,t) && Orijentacija(t1,t2,t3) == Orijentacija(t2,t3,t) && Orijentacija(t1,t2,t3) == Orijentacija(t3,t1,t));
    }
    
    void Ispisi() const {
        std::cout<<"(("<<t1.first<<","<<t1.second<<")";
        std::cout<<",("<<t2.first<<","<<t2.second<<")";
        std::cout<<",("<<t3.first<<","<<t3.second<<"))";
    }
    
    void Transliraj(double delta_x, double delta_y) {
        t1.first += delta_x;
        t2.first += delta_x;
        t3.first += delta_x;
        
        t1.second += delta_y;
        t2.second += delta_y;
        t3.second += delta_y;
    }
    
    void Centriraj(const Tacka &t) {
        Tacka x = DajCentar();
        auto dx = t.first - x.first;
        auto dy = t.second - x.second;
        Transliraj(dx,dy);
    }
    
    void Rotiraj(const Tacka &t, double ugao) {
        Tacka tmp = t1;
        t1.first  = t.first  + (tmp.first - t.first)*cos(ugao) - (tmp.second - t.second)*sin(ugao);
        t1.second = t.second + (tmp.first - t.first)*sin(ugao) + (tmp.second - t.second)*cos(ugao);
        tmp = t2;
        t2.first  = t.first  + (tmp.first - t.first)*cos(ugao) - (tmp.second - t.second)*sin(ugao);
        t2.second = t.second + (tmp.first - t.first)*sin(ugao) + (tmp.second - t.second)*cos(ugao);
        tmp = t3;
        t3.first  = t.first  + (tmp.first - t.first)*cos(ugao) - (tmp.second - t.second)*sin(ugao);
        t3.second = t.second + (tmp.first - t.first)*sin(ugao) + (tmp.second - t.second)*cos(ugao);
        
    }
    
    void Skaliraj(const Tacka &t, double faktor) {
        if(DaLiSuJednaki(faktor,0))
            throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first =  t.first  + faktor*( t1.first  - t.first);
        t1.second = t.second + faktor*( t1.second - t.second);
        t2.first =  t.first  + faktor*( t2.first  - t.first);
        t2.second = t.second + faktor*( t2.second - t.second);
        t3.first =  t.first  + faktor*( t3.first  - t.first);
        t3.second = t.second + faktor*( t3.second - t.second);
    }
    
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor) {
        if(DaLiSuJednaki(faktor,0))
            throw std::domain_error("Nekorektan faktor skaliranja");
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
        std::vector<Tacka> v1 = { t1.t1, t1.t2, t1.t3 };
        std::vector<Tacka> v2 = { t2.t1, t2.t2, t2.t3 };
        std::sort(v1.begin(),v1.end(), [] (Tacka x, Tacka y) { return (x.first<y.first); } );
        std::sort(v2.begin(),v2.end(), [] (Tacka x, Tacka y) { return (x.first<y.first); } );
        for(int i(0);i<3;i++)
            if(!(DaLiSuJednaki(v1[i].first,v2[i].first) && DaLiSuJednaki(v1[i].second,v2[i].second)))
                return false;
        return true;
        
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
        double a1,b1,c1,a2,b2,c2;
        a1 = t1.DajStranicu(1);
        a2 = t2.DajStranicu(1);
        b1 = t1.DajStranicu(2);
        b2 = t2.DajStranicu(2);
        c1 = t1.DajStranicu(3);
        c2 = t2.DajStranicu(3);
        if( (DaLiSuJednaki(a1,a2) && DaLiSuJednaki(b1,b2) && DaLiSuJednaki(c1,c2) && IstaOrijentacija(t1,t2,1,2,3,1,2,3) )||
            (DaLiSuJednaki(a1,a2) && DaLiSuJednaki(b1,c2) && DaLiSuJednaki(c1,b2) && IstaOrijentacija(t1,t2,1,2,3,1,3,2) )||
            (DaLiSuJednaki(a1,b2) && DaLiSuJednaki(b1,a2) && DaLiSuJednaki(c1,c2) && IstaOrijentacija(t1,t2,1,2,3,2,1,3) )||
            (DaLiSuJednaki(a1,b2) && DaLiSuJednaki(b1,c2) && DaLiSuJednaki(c1,a2) && IstaOrijentacija(t1,t2,1,2,3,2,3,1) )||
            (DaLiSuJednaki(a1,c2) && DaLiSuJednaki(b1,b2) && DaLiSuJednaki(c1,a2) && IstaOrijentacija(t1,t2,1,2,3,3,2,1) )||
            (DaLiSuJednaki(a1,c2) && DaLiSuJednaki(b1,a2) && DaLiSuJednaki(c1,b2) && IstaOrijentacija(t1,t2,1,2,3,3,1,2) ))
            return true;
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
        double a1,b1,c1,a2,b2,c2;
        a1 = t1.DajStranicu(1);
        a2 = t2.DajStranicu(1);
        b1 = t1.DajStranicu(2);
        b2 = t2.DajStranicu(2);
        c1 = t1.DajStranicu(3);
        c2 = t2.DajStranicu(3);
        if( (DaLiSuProporcionalne(a1/a2, b1/b2, c1/c2) && IstaOrijentacija(t1,t2,1,2,3,1,2,3) )||
            (DaLiSuProporcionalne(a1/a2, b1/c2, c1/b2) && IstaOrijentacija(t1,t2,1,2,3,1,3,2) )||
            (DaLiSuProporcionalne(a1/b2, b1/a2, c1/c2) && IstaOrijentacija(t1,t2,1,2,3,2,1,3) )||
            (DaLiSuProporcionalne(a1/b2, b1/c2, c1/a2) && IstaOrijentacija(t1,t2,1,2,3,2,3,1) )||
            (DaLiSuProporcionalne(a1/c2, b1/b2, c1/a2) && IstaOrijentacija(t1,t2,1,2,3,3,2,1) )||
            (DaLiSuProporcionalne(a1/c2, a2/a2, c1/b2) && IstaOrijentacija(t1,t2,1,2,3,3,1,2) ))
            return true;
        return false;
    }
};

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vektor;
    for(int i(0);i<n;i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1,y1,x2,y2,x3,y3;
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        std::cin.ignore(10000,'\n');
        Tacka x = std::make_pair(x1,y1);
        Tacka y = std::make_pair(x2,y2);
        Tacka z = std::make_pair(x3,y3);
        try {
           vektor.push_back(std::make_shared<Trougao>(x,y,z));
        } catch(std::domain_error e) {
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    double dx,dy,ugao,faktor;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(),
    [dx,dy,ugao,faktor] (std::shared_ptr<Trougao> t) {
        t->Transliraj(dx,dy);
        t->Rotiraj(ugao);
        t->Skaliraj(t->DajTjeme(1), faktor);
        return t;
    });
    std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) { return (t1->DajPovrsinu() < t2->DajPovrsinu()); });
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t) { t->Ispisi(); std::cout<<std::endl;});
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto tro = std::min_element(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) { return (t1->DajObim() < t2->DajObim());});
    (*tro)->Ispisi();
    std::cout<<std::endl;
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> identicni;
    for(int i(0);i<vektor.size()-1;i++)
        for(int j(i+1);j<vektor.size();j++)
            if(DaLiSuIdenticni(*vektor[i],*vektor[j]))
                identicni.push_back(std::make_pair(vektor[i],vektor[j]));
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> slicni;
    for(int i(0);i<vektor.size()-1;i++)
        for(int j(i+1);j<vektor.size();j++)
            if(DaLiSuSlicni(*vektor[i],*vektor[j]))
                slicni.push_back(std::make_pair(vektor[i],vektor[j]));
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> podudarni;
    for(int i(0);i<vektor.size()-1;i++)
        for(int j(i+1);j<vektor.size();j++)
            if(DaLiSuPodudarni(*vektor[i],*vektor[j]))
                podudarni.push_back(std::make_pair(vektor[i],vektor[j]));
    if(!identicni.size())
        std::cout<<"Nema identicnih trouglova!"<<std::endl;
    else {
        std::cout<<"Parovi identicnih trouglova:"<<std::endl;
        for(auto x : identicni) {
            x.first->Ispisi(); std::cout<<" i "; x.second->Ispisi();
            std::cout<<std::endl;
        }
    }
    if(!podudarni.size())
        std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    else {
        std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
        for(auto x : podudarni) {
            x.first->Ispisi(); std::cout<<" i "; x.second->Ispisi();
            std::cout<<std::endl;
        }
    }
    if(!slicni.size())
        std::cout<<"Nema slicnih trouglova!"<<std::endl;
    else {
        std::cout<<"Parovi slicnih trouglova:"<<std::endl;
        for(auto x : slicni) {
            x.first->Ispisi(); std::cout<<" i "; x.second->Ispisi();
            std::cout<<std::endl;
        }
    }
	return 0;
}