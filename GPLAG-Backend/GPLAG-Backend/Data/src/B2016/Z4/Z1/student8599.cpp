
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

typedef std::pair<double, double> Tacka;

bool Jednako(double a, double b, double e=1e-10){
    return std::fabs(a-b)<=e*(std::fabs(a)+std::fabs(b));
}

class Trougao
{
    Tacka tacka1, tacka2, tacka3;
    static bool DaLiSuJednake(const Tacka &t1, const Tacka &t2) {
        if(Jednako(t1.first, t2.first) && Jednako(t1.second, t2.second))
            return true;
        return false;
    }
    static bool DaLiSuKolinearne(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if((Jednako(t1.first,0) && Jednako(t2.first,0) && !Jednako(t3.first,0)) ||
        (!Jednako(t1.first,0) && Jednako(t2.first,0) && Jednako(t3.first,0)) || (Jednako(t1.first,0) && !Jednako(t2.first,0) && Jednako(t3.first,0)) 
        || (Jednako(t1.first,0) && !Jednako(t2.first,0) && !Jednako(t3.first,0)) || (!Jednako(t1.first,0) && Jednako(t2.first,0) && !Jednako(t3.first,0)) 
        || (!Jednako(t1.first,0) && !Jednako(t2.first,0) && Jednako(t3.first,0)))
            return false;
        if (DaLiSuJednake(t1, t2) || DaLiSuJednake(t1, t3) || DaLiSuJednake(t2, t3) || (Jednako(t1.first,0) && Jednako(t2.first,0) && Jednako(t3.first,0)) 
        || (Jednako(t1.second/t1.first,t2.second/t2.first) && Jednako(t2.second/t2.first,t3.second/t3.first)))
            return true;
        return false;
    }
    bool DaLiJeIspravanIndeks ( int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        return true;
    }
    static double DuzinaStraince(const Tacka &t1, const Tacka &t2) {
        double duzina;
        duzina=std::sqrt((t1.first-t2.first)*(t1.first-t2.first) + (t1.second-t2.second)*(t1.second-t2.second));
        return duzina;
    }
    static  double Ugao(const Tacka &t1, const Tacka &t2, const Tacka &t3)  {
        double x;
        x=std::acos((DuzinaStraince(t1, t2)*DuzinaStraince(t1,t2)+DuzinaStraince(t1,t3)*DuzinaStraince(t1,t3)-DuzinaStraince(t2,t3)*DuzinaStraince(t2,t3))/
                    (2*DuzinaStraince(t1,t2)*DuzinaStraince(t1,t3)));
        return x;
    }
    double IzrazZaP(const Tacka &t1, const Tacka &t2, const Tacka &t3) const {
        return (1./2)*fabs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second));
    }
    double UgaoNagiba(const Tacka &t1, const Tacka &t2) {
        return std::atan((t2.second-t1.second)/(t2.first-t1.first));
    }
    Tacka RotacijaTacke(const Tacka &t1, const Tacka &t2, double ugao) {
        Tacka t;
        t.first=t2.first+(t1.first-t2.first)*std::cos(ugao)-(t1.second-t2.second)*std::sin(ugao);
        t.second=t2.second+(t1.first-t2.first)*std::sin(ugao)+(t1.second-t2.second)*std::cos(ugao);
        return t;
    }
    static bool JednakostStranica(const Tacka &t1, const Tacka &t2, const Trougao &t)  {
        if(Jednako(DuzinaStraince(t1, t2),DuzinaStraince(t.tacka1,t.tacka2)) || Jednako(DuzinaStraince(t1,t2),DuzinaStraince(t.tacka2,t.tacka3))
                || Jednako(DuzinaStraince(t1,t2),DuzinaStraince(t.tacka1,t.tacka3))) return true;
        return false;
    }
    static  double NajvecaStranica(const Trougao &t) {
        double max(DuzinaStraince(t.tacka1,t.tacka2));
        if(DuzinaStraince(t.tacka1,t.tacka3)>=max) max=DuzinaStraince(t.tacka1, t.tacka3);
        if(DuzinaStraince(t.tacka2,t.tacka3)>=max) max=DuzinaStraince(t.tacka2, t.tacka3);
        return max;
    }
    static   Tacka TemeNajvece(const Trougao &t) {
        double max(NajvecaStranica(t));
        if(Jednako(DuzinaStraince(t.tacka1,t.tacka2),max)) return t.tacka3;
        if(Jednako(DuzinaStraince(t.tacka2,t.tacka3),max)) return t.tacka1;
        if(Jednako(DuzinaStraince(t.tacka1,t.tacka3),max)) return t.tacka2;
        return t.tacka1;
    }
    static  double NajmanjaStranica(const Trougao &t) {
        double min(DuzinaStraince(t.tacka1, t.tacka2));
        if(DuzinaStraince(t.tacka1,t.tacka3)<=min) min=DuzinaStraince(t.tacka1, t.tacka3);
        if(DuzinaStraince(t.tacka2,t.tacka3)<=min) min=DuzinaStraince(t.tacka2,t.tacka3);
        return min;
    }
    static  Tacka TemeNajmanje(const Trougao &t) {
        double min(NajmanjaStranica(t));
        if(Jednako(DuzinaStraince(t.tacka1,t.tacka2),min)) return t.tacka3;
        if(Jednako(DuzinaStraince(t.tacka2,t.tacka3),min)) return t.tacka1;
        if(Jednako(DuzinaStraince(t.tacka1,t.tacka3),min)) return t.tacka2;
        return t.tacka1;
    }
    static Tacka TemeSrednje(const Trougao &t) {
        auto max(TemeNajvece(t));
        auto min(TemeNajmanje(t));
        if(!DaLiSuJednake(t.tacka1, max) && !DaLiSuJednake(t.tacka1, min)) return t.tacka1;
        if(!DaLiSuJednake(t.tacka2, max) && !DaLiSuJednake(t.tacka2, min)) return t.tacka2;
        if(!DaLiSuJednake(t.tacka3, max) && !DaLiSuJednake(t.tacka3, min)) return t.tacka3;
        return t.tacka1;
    }
    static bool JednakostUglova(const Tacka &t1, const Tacka &t2, const Tacka &t3, const Trougao t) {
        if(Jednako(Ugao(t1, t2, t3),Ugao(t.tacka1, t.tacka2, t.tacka3)) || Jednako(Ugao(t1, t2, t3),Ugao(t.tacka2, t.tacka1, t.tacka3))
                || Jednako(Ugao(t1, t2, t3),Ugao(t.tacka3, t.tacka2, t.tacka1))) return true;
        return false;
    }

public:

    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(DaLiSuKolinearne(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=t1;
        tacka2=t2;
        tacka3=t3;
    }

    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(DaLiSuKolinearne(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=t1;
        tacka2=t2;
        tacka3=t3;
    }

    void Postavi(int indeks, const Tacka &t) {
        DaLiJeIspravanIndeks(indeks);
        if(indeks==1) tacka1=t;
        if(indeks==2) tacka2=t;
        if(indeks==3) tacka3=t;
    }

    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);

    Tacka DajTjeme(int indeks) const {
        DaLiJeIspravanIndeks(indeks);
        if(indeks==1) return tacka1;
        if(indeks==2) return tacka2;
        if(indeks==3) return tacka3;
        return tacka1;
    }

    double DajStranicu(int indeks) const;

    double DajUgao(int indeks) const;

    Tacka DajCentar() const {
        Tacka x;
        x.first=(tacka1.first+tacka2.first+tacka3.first)/3;
        x.second=(tacka1.second+tacka2.second+tacka3.second)/3;
        return x;
    }

    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }

    double DajPovrsinu() const {
        return IzrazZaP(tacka1, tacka2, tacka3);
    }

    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tacka1, tacka2, tacka3)==1) return true;
        return false;
    }

    bool DaLiJeUnutra(const Tacka &t) const;

    void Ispisi() const {
        std::cout << "((" << tacka1.first << "," << tacka1.second << "),(" << tacka2.first << "," << tacka2.second << "),("
                  << tacka3.first << "," << tacka3.second << "))";
    }

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

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0) return 1;
    else if ((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0) return -1;
    else return 0;
}

double Trougao::DajStranicu(int indeks) const
{
    DaLiJeIspravanIndeks(indeks);
    if(indeks==1) return DuzinaStraince(tacka2, tacka3);
    else if(indeks==2) return DuzinaStraince(tacka1, tacka3);
    else return DuzinaStraince(tacka1, tacka2);
}

double Trougao::DajUgao(int indeks) const
{
    DaLiJeIspravanIndeks(indeks);
    if(indeks==1) return Ugao(tacka1, tacka2, tacka3);
    else if(indeks==2) return Ugao(tacka2, tacka1, tacka3);
    else return Ugao(tacka3, tacka1, tacka2);
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    if((DaLiJePozitivnoOrijentiran() && Orijentacija(tacka1, tacka2, t)==1 && Orijentacija(tacka2, tacka3, t)==1
            && Orijentacija(tacka3, tacka1, t)==1) || (!DaLiJePozitivnoOrijentiran() &&
                    Orijentacija(tacka1, tacka2, t)==-1 && Orijentacija(tacka2, tacka3, t)==-1 && Orijentacija(tacka3,tacka1, t)==-1))
        return true;
    return false;
}
void Trougao::Transliraj(double delta_x, double delta_y)
{
    tacka1.first+=delta_x;
    tacka2.first+=delta_x;
    tacka3.first+=delta_x;
    tacka1.second+=delta_y;
    tacka2.second+=delta_y;
    tacka3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t)
{
    double x(DuzinaStraince(t, DajCentar()));
    double alfa(UgaoNagiba(t, DajCentar()));
    tacka1.first+=x*std::acos(alfa);
    tacka2.first+=x*std::acos(alfa);
    tacka3.first+=x*std::acos(alfa);
    tacka1.second+=x*std::asin(alfa);
    tacka2.second+=x*std::asin(alfa);
    tacka3.second+=x*std::asin(alfa);
}
void Trougao::Rotiraj(const Tacka &t,double ugao)
{
    tacka1=RotacijaTacke(tacka1, t, ugao);
    tacka2=RotacijaTacke(tacka2, t, ugao);
    tacka3=RotacijaTacke(tacka3, t, ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(Jednako(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    tacka1.first=t.first+faktor*(tacka1.first-t.first);
    tacka2.first=t.first+faktor*(tacka2.first-t.first);
    tacka3.first=t.first+faktor*(tacka3.first-t.first);
    tacka1.second=t.second+faktor*(tacka1.second-t.second);
    tacka2.second=t.second+faktor*(tacka2.second-t.second);
    tacka3.second=t.second+faktor*(tacka3.second-t.second);
}
void Trougao::Rotiraj(double ugao)
{
    Tacka x(DajCentar());
    tacka1=RotacijaTacke(tacka1, x, ugao);
    tacka2=RotacijaTacke(tacka2, x, ugao);
    tacka3=RotacijaTacke(tacka3, x, ugao);
}
void Trougao::Skaliraj(double faktor)
{
    if(Jednako(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka x(DajCentar());
    tacka1.first=x.first+faktor*(tacka1.first-x.first);
    tacka2.first=x.first+faktor*(tacka2.first-x.first);
    tacka3.first=x.first+faktor*(tacka3.first-x.first);
    tacka1.second=x.second+faktor*(tacka1.second-x.second);
    tacka2.second=x.second+faktor*(tacka2.second-x.second);
    tacka3.second=x.second+faktor*(tacka3.second-x.second);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((Trougao::DaLiSuKolinearne(t1.tacka1, t1.tacka2, t1.tacka3)) || Trougao::DaLiSuKolinearne(t2.tacka1, t2.tacka2, t2.tacka3)) return false;
    if((Trougao::DaLiSuJednake(t1.tacka1, t2.tacka1) || Trougao::DaLiSuJednake(t1.tacka1, t2.tacka2) || Trougao::DaLiSuJednake(t1.tacka1, t2.tacka3)) &&
            (Trougao::DaLiSuJednake(t1.tacka2, t2.tacka1) || Trougao::DaLiSuJednake(t1.tacka2, t2.tacka2) || Trougao::DaLiSuJednake(t1.tacka2, t2.tacka3)) &&
            (Trougao::DaLiSuJednake(t1.tacka3, t2.tacka1) || Trougao::DaLiSuJednake(t1.tacka3, t2.tacka2) || Trougao::DaLiSuJednake(t1.tacka3, t2.tacka3)))
        return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if((Trougao::DaLiSuKolinearne(t1.tacka1, t1.tacka2, t1.tacka3)) || Trougao::DaLiSuKolinearne(t2.tacka1, t2.tacka2, t2.tacka3)) return false;
    if(!Trougao::JednakostStranica(t1.tacka1,t1.tacka2, t2) || !Trougao::JednakostStranica(t1.tacka2,t1.tacka3,t2)
            || !Trougao::JednakostStranica(t1.tacka3, t1.tacka1, t2)) return false;
    if((Trougao::Orijentacija(Trougao::TemeNajmanje(t1),Trougao::TemeNajvece(t1), Trougao::TemeSrednje(t1))>0 &&
            Trougao::Orijentacija(Trougao::TemeNajmanje(t2), Trougao::TemeNajvece(t2), Trougao::TemeSrednje(t2))>0) ||
            (Trougao::Orijentacija(Trougao::TemeNajmanje(t1), Trougao::TemeNajvece(t1), Trougao::TemeSrednje(t1))<0 &&
             Trougao::Orijentacija(Trougao::TemeNajmanje(t2), Trougao::TemeNajvece(t2), Trougao::TemeSrednje(t2))<0))
        return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if((Trougao::DaLiSuKolinearne(t1.tacka1,t1.tacka2, t1.tacka3)) || Trougao::DaLiSuKolinearne(t2.tacka1, t2.tacka2, t2.tacka3)) return false;
    if((((Trougao::Orijentacija(Trougao::TemeNajmanje(t1), Trougao::TemeNajvece(t1), Trougao::TemeSrednje(t1))>0) &&
            (Trougao::Orijentacija(Trougao::TemeNajmanje(t2), Trougao::TemeNajvece(t2), Trougao::TemeSrednje(t2))>0)) ||
            ((Trougao::Orijentacija(Trougao::TemeNajmanje(t1),Trougao::TemeNajvece(t1), Trougao::TemeSrednje(t1))<0) &&
             (Trougao::Orijentacija(Trougao::TemeNajmanje(t2), Trougao::TemeNajvece(t2), Trougao::TemeSrednje(t2))<0))) &&
            (Trougao::JednakostUglova(t1.tacka1,t1.tacka2,t1.tacka3,t2) && Trougao::JednakostUglova(t1.tacka2, t1.tacka3, t1.tacka1, t2) &&
             Trougao::JednakostUglova(t1.tacka3, t1.tacka2, t1.tacka1, t2))) return true;
    return false;

}



int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0; i<n; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Tacka t1(std::make_pair(x1,y1));
        Tacka t2(std::make_pair(x2,y2));
        Tacka t3(std::make_pair(x3,y3));
        std::shared_ptr<Trougao> p;
        try {
            p=std::make_shared<Trougao>(Trougao(t1, t2, t3));
            v[i]=p;
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what();
            std::cout <<", ponovite unos!" << std::endl;
            i--;
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    double x, y;
    std::cin >> x >> y;
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    std::transform(v.begin(), v.end(), v.begin(), [x, y, ugao, faktor](std::shared_ptr<Trougao> a) {
        a->Transliraj(x, y);
        a->Rotiraj(ugao);
        a->Skaliraj(a->DajTjeme(1), faktor);
        return a;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) {
        return x->DajPovrsinu()<y->DajPovrsinu();
    });
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> x) {
        x->Ispisi();
        std::cout << std::endl;
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) {
        return x->DajObim()<y->DajObim();
    }))->Ispisi();
    int brojac1(0), brojac2(0), brojac3(0);
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++) {
            if(DaLiSuIdenticni(*v[i],*v[j])) brojac1++;
            if(DaLiSuPodudarni(*v[i],*v[j])) brojac2++;
            if(DaLiSuSlicni(*v[i],*v[j])) brojac3++;
        }
    if(brojac1==0) std::cout << std::endl << "Nema identicnih trouglova!";
    else {
        std::cout << std::endl << "Parovi identicnih trouglova:" << std::endl;
        for(int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if(DaLiSuIdenticni(*v[i],*v[j])) {
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
    }
    if(brojac2==0) std::cout << std::endl << "Nema podudarnih trouglova!";
    else {
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(DaLiSuPodudarni(*v[i], *v[j])) {
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
    }
    if(brojac3==0) std::cout << std::endl << "Nema slicnih trouglova!";
    else {
        std::cout << "Parovi slicnih trouglova:" << std::endl;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(DaLiSuSlicni(*v[i], *v[j])) {
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
    }


    return 0;
}
