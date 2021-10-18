#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double,double> Tacka;
const double eps(1e-10);
const double PI=4*atan(1);
class Trougao {
    
    Tacka tacke[3];
    
    void ProvjeraIndeksa(int indeks) const { if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks"); }
    
    static const double IzrazZaPovrsinu(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    
    static bool Jednaki(double x, double y) {
        if(std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y))) return true;
        return false;
    }
    
    //Nisam se mogla snaci sa sintaksom za bilo kakvo smislenije/pametnije rjesenje
    static Trougao SortirajTjemena(Trougao t) {
        if(t.DajUgao(1)>t.DajUgao(2)) std::swap(t.tacke[0], t.tacke[1]);
        if(t.DajUgao(2)>t.DajUgao(3)) std::swap(t.tacke[1], t.tacke[2]);
        if(t.DajUgao(1)>t.DajUgao(2)) std::swap(t.tacke[0], t.tacke[1]);
        return t;
    }
    
    public:
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1,t2,t3); }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        tacke[0]=t1; tacke[1]=t2; tacke[2]=t3;
    }
    
    void Postavi(int indeks, const Tacka &t);
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double izraz(IzrazZaPovrsinu(t1,t2,t3));
        if(izraz>0) return 1;
        if(izraz<0) return -1;
        return 0;
    }
    
    Tacka DajTjeme(int indeks) const { ProvjeraIndeksa(indeks); return tacke[indeks-1]; }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
    double DajPovrsinu() const { return std::fabs(IzrazZaPovrsinu(tacke[0], tacke[1], tacke[2]))/2.; }
    bool DaLiJePozitivnoOrijentiran() const { if(Orijentacija(tacke[0], tacke[1], tacke[2])==1) return true; return false; }
    bool DaLiJeUnutra(const Tacka &t) const {
        int orijent( Orijentacija( tacke[0], tacke[1], tacke[2] ) );
        if(Orijentacija(tacke[0], tacke[1], t)!=orijent || Orijentacija(tacke[1], tacke[2], t)!=orijent || Orijentacija(tacke[2], tacke[0], t)!=orijent) return false;
        return true;
    }
    void Ispisi() const { std::cout<<"(("<<DajTjeme(1).first<<","<<DajTjeme(1).second<<"),("<<DajTjeme(2).first<<","<<DajTjeme(2).second<<"),("<<DajTjeme(3).first<<","<<DajTjeme(3).second<<"))"; }
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t) {
        double delta_x(t.first-DajCentar().first), delta_y(t.second-DajCentar().second);
        Transliraj(delta_x, delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); }
    void Skaliraj(double faktor) { Skaliraj(DajCentar(), faktor); }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

void Trougao::Postavi(int indeks, const Tacka &t) {
        ProvjeraIndeksa(indeks);
        Tacka pom=tacke[indeks-1];
        tacke[indeks-1]=t;
        if(Orijentacija(tacke[0],tacke[1],tacke[2])==0) {
            tacke[indeks-1]=pom;
            throw std::domain_error ("Nekorektne pozicije tjemena");
        }
    }

double Trougao::DajStranicu(int indeks) const {
    ProvjeraIndeksa(indeks); indeks-=1;
    Tacka dvije[2];
    int j(0);
    for(int i=0; i<3; i++) {
        if(i!=indeks) { dvije[j]=tacke[i]; j++; }
    }
    
    return std::sqrt( std::pow((dvije[1].first-dvije[0].first),2) + std::pow((dvije[1].second-dvije[0].second),2) );
}

double Trougao::DajUgao(int indeks) const {
    ProvjeraIndeksa(indeks);
    double ugao;
    int druga_dva_indeksa[2];
    int j(0);
    for(int i=0; i<3; i++) {
        if(i!=indeks-1) { druga_dva_indeksa[j]=i; j++; }
    }
    double a(DajStranicu(indeks)), b(DajStranicu(druga_dva_indeksa[0]+1)), c(DajStranicu(druga_dva_indeksa[1]+1));
    ugao=acos((b*b+c*c-a*a)/(2*b*c));
    return ugao;
}

Tacka Trougao::DajCentar() const {
        Tacka centar;
        centar.first=(tacke[0].first+tacke[1].first+tacke[2].first)/3.;
        centar.second=(tacke[0].second+tacke[1].second+tacke[2].second)/3.;
        return centar;
    }

void Trougao::Transliraj(double delta_x, double delta_y) {
    for(int i=0; i<3; i++) {
        tacke[i].first+=delta_x;
        tacke[i].second+=delta_y;
    }
}
//testirat
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    for(int i=0; i<3; i++) {
        double x(tacke[i].first), y(tacke[i].second);
        tacke[i].first=t.first+(x-t.first)*cos(ugao)-(y-t.second)*sin(ugao);
        tacke[i].second=t.second+(x-t.first)*sin(ugao)+(y-t.second)*cos(ugao);
    }
}
//testirat
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Jednaki(faktor,0)) throw std::domain_error ("Nekorektan faktor skaliranja");
    for(int i=0; i<3; i++) {
        tacke[i].first=t.first+faktor*(tacke[i].first-t.first);
        tacke[i].second=t.second+faktor*(tacke[i].second-t.second);
    }
}
//testirat
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    int brojac_istih_tjemena(0);
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(t1.tacke[i]==t2.tacke[j]) { brojac_istih_tjemena++; break; }
        }
    }
    if(brojac_istih_tjemena==3) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    
    Trougao t3=Trougao::SortirajTjemena(t1);
    Trougao t4=Trougao::SortirajTjemena(t2);
    bool sve_stranice_iste(true);
    for(int i=1; i<4; i++) {
        if(!Trougao::Jednaki(t3.DajStranicu(i), t4.DajStranicu(i))) {
            sve_stranice_iste=false; break;
        }
    }
    if(Trougao::Orijentacija(t3.tacke[0], t3.tacke[1], t3.tacke[2])==Trougao::Orijentacija(t4.tacke[0], t4.tacke[1], t4.tacke[2]) && sve_stranice_iste)
        return true;
    return false;
    
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    Trougao t3=Trougao::SortirajTjemena(t1);
    Trougao t4=Trougao::SortirajTjemena(t2);
    if( Trougao::Jednaki(t3.DajStranicu(1)/t3.DajStranicu(2), t4.DajStranicu(1)/t4.DajStranicu(2)) &&
        Trougao::Jednaki(t3.DajStranicu(2)/t3.DajStranicu(3), t4.DajStranicu(2)/t4.DajStranicu(3)) &&
        Trougao::Jednaki(t3.DajStranicu(1)/t3.DajStranicu(3), t4.DajStranicu(1)/t4.DajStranicu(3)) && DaLiSuPodudarni(t1,t2)) return true;
        
        return false;
}

int main ()
{ 
  
    
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v;
    for(int i=0; i<n; i++) {
        Tacka A,B,C;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x,y;
        std::cin>>x>>y;
        A.first=x; A.second=y;
        std::cin>>x>>y;
        B.first=x; B.second=y;
        std::cin>>x>>y;
        C.first=x; C.second=y;
        try {
        v.push_back(std::make_shared<Trougao>(A,B,C));
        }
        catch(std::domain_error greska) {
            std::cout<<greska.what()<<", ponovite unos!\n";
            i--;
        }
    }
    double ugao, dx, dy, faktor;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::transform(v.begin(), v.end(), v.begin(), [&] (std::shared_ptr<Trougao> t) {
                                                        t->Transliraj(dx,dy);
                                                        t->Rotiraj(t->DajCentar(), ugao);
                                                        t->Skaliraj(t->DajTjeme(1), faktor);
                                                        return t;
                                                     } );
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
                                        return t1->DajPovrsinu() < t2->DajPovrsinu();
                                    });
    
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t) {t->Ispisi(); std::cout<<std::endl;});
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto najmanji_obim(std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
                                                                return t1->DajObim() < t2->DajObim(); }));
    (**najmanji_obim).Ispisi();
    
    typedef std::pair<Trougao, Trougao> ParTrouglova;
    std::vector<ParTrouglova> identicni, podudarni, slicni;
    
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                ParTrouglova pom(*v[i], *v[j]);
                identicni.push_back(pom);
            }
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                ParTrouglova pom(*v[i], *v[j]);
                podudarni.push_back(pom);
            }
            if(DaLiSuSlicni(*v[i], *v[j])) {
                ParTrouglova pom(*v[i], *v[j]);
                slicni.push_back(pom);
            }
        }
    }
    if(identicni.size()==0) std::cout<<"\nNema identicnih trouglova!\n";
    else {
    std::cout<<"\nParovi identicnih trouglova:\n";
    for(int i=0; i<identicni.size(); i++) {
        identicni[i].first.Ispisi(); std::cout<<" i ";
        identicni[i].second.Ispisi(); std::cout<<std::endl;
    }
    }
    if(podudarni.size()==0) std::cout<<"Nema podudarnih trouglova!\n";
    else {
    std::cout<<"Parovi podudarnih trouglova:\n";
    for(int i=0; i<podudarni.size(); i++) {
        podudarni[i].first.Ispisi(); std::cout<<" i ";
        podudarni[i].second.Ispisi(); std::cout<<std::endl;
    }
    }
    if(slicni.size()==0) std::cout<<"Nema slicnih trouglova!\n";
    else {
    std::cout<<"Parovi slicnih trouglova:\n";
    for(int i=0; i<slicni.size(); i++) {
        slicni[i].first.Ispisi(); std::cout<<" i ";
        slicni[i].second.Ispisi(); std::cout<<std::endl;
    }
    }
    
    
    
	return 0;
}

