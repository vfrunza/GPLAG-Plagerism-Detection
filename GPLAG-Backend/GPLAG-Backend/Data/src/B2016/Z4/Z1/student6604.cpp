/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;
const double PI= 4*atan(1);

class Trougao
{
    Tacka A, B, C;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1, t2, t3);
    };
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        A.first=t1.first;
        A.second=t1.second;
        B.first=t2.first;
        B.second=t2.second;
        C.first=t3.first;
        C.second=t3.second;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        else if(indeks==1) {
            A.first=t.first;
            A.second=t.second;
        } else if(indeks==2) {
            B.first=t.first;
            B.second=t.second;
        } else if(indeks==3) {
            C.first=t.first;
            C.second=t.second;
        }
        if(Orijentacija(A, B, C)==0) throw std::domain_error("Nekorektne pozicije tjemena");

    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0) return 1;
        else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))==0) return 0;
        else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0) return -1;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return A;
        if(indeks==2) return B;
        if(indeks==3) return C;
    }
    double DajStranicu(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        double x;
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) x=std::sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
        if(indeks==2)  x=std::sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
        if(indeks==3) x=std::sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
        return x;
    }
    double DajUgao(int indeks) const {
        double ugao;
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) {
            ugao=std::acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        }
        if(indeks==2) {
            ugao=std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
        }
        if(indeks==3) {
            ugao=std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
        }
        return ugao;
    }
    Tacka DajCentar() const {
        Tacka T;
        T.first=(A.first+B.first+C.first)/3.;
        T.second=(A.second+B.second+C.second)/3.;
        return T;
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu()const {
        double P=(A.first*(B.second-C.second)-B.first*(A.second-C.second)+C.first*(A.second-B.second));
        if(P<0)P*=-1;
        P/=2.;
        return P;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(A, B, C)==1) return 1;
        return 0;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(A,B,C)==1 && Orijentacija(A, B, t)==1 && Orijentacija(B, C, t)==1 && Orijentacija(C, A, t)==1) return 1;
        return 0;
    }
    void Ispisi() const {
        std::cout<<"(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        A.first+=delta_x;
        A.second+=delta_y;
        B.first+=delta_x;
        B.second+=delta_y;
        C.first+=delta_x;
        C.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        A.first+=(t.first-DajCentar().first);
        A.second+=(t.second-DajCentar().second);
        B.first+=(t.first-DajCentar().first);
        B.second+=(t.second-DajCentar().second);
        C.first+=(t.first-DajCentar().first);
        C.second+=(t.second-DajCentar().second);
        DajCentar()=t;
    }
    void Rotiraj(const Tacka &t, double ugao) {
        Tacka D, E, F;
        D.first=t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
        D.second=t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao);
        E.first=t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao);
        E.second=t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao);
        F.first=t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao);
        F.second=t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao);
        Postavi(D, E, F);
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
        A.first=t.first+faktor*(A.first-t.first);
        A.second=t.second+faktor*(A.second-t.second);
        B.first=t.first+faktor*(B.first-t.first);
        B.second=t.second+faktor*(B.second-t.second);
        C.first=t.first+faktor*(C.first-t.first);
        C.second=t.second+faktor*(C.second-t.second);
        if(faktor<0) Rotiraj(t,PI);
    }
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if(t1.A.first==t2.A.first && t1.A.second==t2.A.second && t1.B.first==t2.B.first && t1.B.second==t2.B.second && t1.C.first==t2.C.first && t1.C.second==t2.C.second) return 1;
    if(t1.A.first==t2.A.first && t1.A.second==t2.A.second && t1.B.first==t2.C.first && t1.B.second==t2.C.second && t1.C.first==t2.B.first && t1.C.second==t2.B.second) return 1;
    if(t1.A.first==t2.B.first && t1.A.second==t2.B.second && t1.B.first==t2.A.first && t1.B.second==t2.A.second && t1.C.first==t2.C.first && t1.C.second==t2.C.second) return 1;
    if(t1.A.first==t2.B.first && t1.A.second==t2.B.second && t1.B.first==t2.C.first && t1.B.second==t2.C.second && t1.C.first==t2.A.first && t1.C.second==t2.A.second) return 1;
    if(t1.A.first==t2.C.first && t1.A.second==t2.C.second && t1.B.first==t2.A.first && t1.B.second==t2.A.second && t1.C.first==t2.B.first && t1.C.second==t2.B.second) return 1;
    if(t1.A.first==t2.C.first && t1.A.second==t2.C.second && t1.B.first==t2.B.first && t1.B.second==t2.B.second && t1.C.first==t2.A.first && t1.C.second==t2.A.second) return 1;
    return 0;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if(t1.DaLiJePozitivnoOrijentiran()==1 && t2.DaLiJePozitivnoOrijentiran()==1) {
        if(t1.DajStranicu(3)==t2.DajStranicu(3) && t1.DajStranicu(1)==t2.DajStranicu(1) && t1.DajStranicu(2)==t2.DajStranicu(2) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(1) && t1.DajStranicu(1)==t2.DajStranicu(2) && t1.DajStranicu(2)==t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(2) && t1.DajStranicu(1)==t2.DajStranicu(1) && t1.DajStranicu(2)==t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(2) && t1.DajStranicu(1)==t2.DajStranicu(3) && t1.DajStranicu(2)==t2.DajStranicu(1) )return 1;

    }
    if(Trougao::Orijentacija(t1.A, t1.B, t1.C)==-1 && Trougao::Orijentacija(t2.A, t2.B, t2.C)==-1) {
        if(t1.DajStranicu(3)==t2.DajStranicu(3) && t1.DajStranicu(1)==t2.DajStranicu(1) && t1.DajStranicu(2)==t2.DajStranicu(2) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(1) && t1.DajStranicu(1)==t2.DajStranicu(2) && t1.DajStranicu(2)==t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(2) && t1.DajStranicu(1)==t2.DajStranicu(3) && t1.DajStranicu(2)==t2.DajStranicu(1) )return 1;
    }
    if(Trougao::Orijentacija(t1.A, t1.B, t1.C)==1 && Trougao::Orijentacija(t2.A, t2.B, t2.C)==-1) {
        if(t1.DajStranicu(3)==t2.DajStranicu(3) && t1.DajStranicu(1)==t2.DajStranicu(2) && t1.DajStranicu(2)==t2.DajStranicu(1) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(2) && t1.DajStranicu(1)==t2.DajStranicu(1) && t1.DajStranicu(2)==t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(1) && t1.DajStranicu(1)==t2.DajStranicu(3) && t1.DajStranicu(2)==t2.DajStranicu(2) )return 1;

    }
    if(Trougao::Orijentacija(t1.A, t1.B, t1.C)==-1 && Trougao::Orijentacija(t2.A, t2.B, t2.C)==1) {
        if(t1.DajStranicu(3)==t2.DajStranicu(3) && t1.DajStranicu(1)==t2.DajStranicu(2) && t1.DajStranicu(2)==t2.DajStranicu(1) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(2) && t1.DajStranicu(1)==t2.DajStranicu(1) && t1.DajStranicu(2)==t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)==t2.DajStranicu(1) && t1.DajStranicu(1)==t2.DajStranicu(3) && t1.DajStranicu(2)==t2.DajStranicu(2) )return 1;

    }
    return 0;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if(t1.DaLiJePozitivnoOrijentiran()==1 && t2.DaLiJePozitivnoOrijentiran()==1) {
        if((t1.DajStranicu(3)/t2.DajStranicu(3)) == (t1.DajStranicu(1)/t2.DajStranicu(1)) == (t1.DajStranicu(2)/t2.DajStranicu(2)) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)/t2.DajStranicu(1) )return 1;

    }
    if(Trougao::Orijentacija(t1.A, t1.B, t1.C)==-1 && Trougao::Orijentacija(t2.A, t2.B, t2.C)==-1) {
        if(t1.DajStranicu(3)/t2.DajStranicu(3) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(2) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)==t2.DajStranicu(1) )return 1;
    }
    if(Trougao::Orijentacija(t1.A, t1.B, t1.C)==1 && Trougao::Orijentacija(t2.A, t2.B, t2.C)==-1) {
        if(t1.DajStranicu(3)/t2.DajStranicu(3) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(1) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)/t2.DajStranicu(2) )return 1;

    }
    if(Trougao::Orijentacija(t1.A, t1.B, t1.C)==-1 && Trougao::Orijentacija(t2.A, t2.B, t2.C)==1) {
        if(t1.DajStranicu(3)/t2.DajStranicu(3) == t1.DajStranicu(1)/t2.DajStranicu(2) == t1.DajStranicu(2)/t2.DajStranicu(1) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(2) == t1.DajStranicu(1)/t2.DajStranicu(1) == t1.DajStranicu(2)/t2.DajStranicu(3) )return 1;
        if(t1.DajStranicu(3)/t2.DajStranicu(1) == t1.DajStranicu(1)/t2.DajStranicu(3) == t1.DajStranicu(2)/t2.DajStranicu(2) )return 1;

    }
    return 0;
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>v;
    Tacka A, B, C;
    double x, y, x2, y2, x3, y3;
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x;
        std::cin>>y;
        A.first=x;
        A.second=y;
        std::cin>>x2;
        std::cin>>y2;
        B.first=x2;
        B.second=y2;
        std::cin>>x3;
        std::cin>>y3;
        C.first=x3;
        C.second=y3;
        try {
            std::shared_ptr<Trougao>pok(new Trougao(A, B, C));
            v.emplace_back(pok);
        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<", ponovite unos!" << std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double delta_x, delta_y;
    std::cin>>delta_x>> delta_y;
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y](std::shared_ptr<Trougao>&p) {
        p->Transliraj(delta_x, delta_y);
        return p;
    });
    std::cout<<"Unesite ugao rotacije: ";
    double alfa;
    std::cin>>alfa;
    std::transform(v.begin(), v.end(), v.begin(), [alfa](std::shared_ptr<Trougao>&p) {
        p->Rotiraj(p->DajCentar(), alfa);
        return p;
    });
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::transform(v.begin(), v.end(), v.begin(), [faktor](std::shared_ptr<Trougao>&p) {
        p->Skaliraj(p->DajTjeme(1), faktor);
        return p;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao>p, std::shared_ptr<Trougao>p2) {
        if(p->DajPovrsinu()<p2->DajPovrsinu())return 1;
        return 0;
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao>p) {
        p->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    std::vector<std::shared_ptr<Trougao>>::iterator it=std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao>p, std::shared_ptr<Trougao>p2) {
        return p->DajObim()<p2->DajObim();
    });
    (*it)->Ispisi();
    std::cout<<std::endl;
    int imai(0);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                imai++;
                if(imai==1) std::cout<<"Parovi identicnih trouglova: "<<std::endl;
                (*v[i]).Ispisi();
                std::cout<<" i ";
                (*v[j]).Ispisi();
                std::cout<<std::endl;
                imai++;
            }
        }
    }
    if(imai==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
    int imap(0);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                imap++;
                if(imap==1) std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
                (*v[i]).Ispisi();
                std::cout<<" i ";
                (*v[j]).Ispisi();
                std::cout<<std::endl;
                imap++;
            }
        }
    }
    if(imap==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    int imas(0);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) {
                imas++;
                if(imas==1) std::cout<<"Parovi slicnih trouglova: "<<std::endl;
                (*v[i]).Ispisi();
                std::cout<<" i ";
                (*v[j]).Ispisi();
                std::cout<<std::endl;
                imas++;
            }
        }
    }
    if(imas==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
    return 0;
}
