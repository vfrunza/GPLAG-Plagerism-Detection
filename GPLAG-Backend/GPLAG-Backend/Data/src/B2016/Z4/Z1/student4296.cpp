/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <memory>
#include <cmath>
#include <vector>
#include <algorithm>
#define eps  1E-10
using std::cout;
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t[3];
    static bool TestIndeks(int indeks) {
        if(indeks<1 || indeks>3) return false;
        else return true;
    }
    static double duzina(const Tacka &p1, const Tacka &p2) {
        Tacka v;
        v= {p1.first-p2.first,p1.second-p2.second};
        double duzina;
        duzina=std::sqrt(v.first*v.first + v.second*v.second);
        return duzina;
    }
    static double Racun(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return ((t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))+(t3.first*(t1.second-t2.second)));
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        t[0]=t1;
        t[1]=t2;
        t[2]=t3;
        if(this->Orijentacija(t1, t2, t3)==0)
            throw std::domain_error ("Nekorektne pozicije tjemena");
    }
    void Postavi(int indeks, const Tacka &t) {
        if(!TestIndeks(indeks)) throw std::range_error ("Nekorektan indeks");
        Trougao::t[indeks-1]=t;
        if(this->Orijentacija==0)
            throw std::domain_error ("Nekorektne pozicije tjemena");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double izraz;
        izraz=Racun(t1,t2,t3);
        if(izraz>0)
            return 1;
        else if(izraz<0)
            return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(!TestIndeks(indeks)) throw std::range_error ("Nekorektan indeks");
        return t[indeks-1];
    }
    double DajStranicu(int indeks) const {
        Tacka p(DajTjeme(indeks)),f(DajTjeme(indeks));
        for(int i=0; i<3; i++) {
            if(p==DajTjeme(indeks) && i+1!=indeks )
                p=DajTjeme(i+1);
            else if(f==DajTjeme(indeks) && i+1!=indeks )
                f=DajTjeme(i+1);
        }
        return duzina(f,p);
    }
    double DajUgao(int indeks) const {
        double a,b,c;
        int i1=-1,i2=-1;
        for(int i=0; i<3; i++) {
            if(i!=indeks-1 && i1==-1)
                i1=i;
            else if(i!=indeks-1 && i2==-1)
                i2=i;
        }
        a=duzina(t[i1],t[i2]);
        b=duzina(t[indeks-1],t[i1]);
        c=duzina(t[indeks-1],t[i2]);
        double alfa;
        alfa=std::acos((b*b+c*c-a*a)/(2*b*c));
        return alfa;
    }
    Tacka DajCentar() const {
        double suma1=0,suma2=0;
        for(int i=0; i<3; i++) {
            suma1+=t[i].first;
            suma2+=t[i].second;
        }
        Tacka v;
        v= {suma1/3,suma2/3};
        return v;
    }
    double DajObim() const {
        double stranice1[3];
        stranice1[0]=duzina(t[0],t[1]);
        stranice1[1]=duzina(t[1],t[2]);
        stranice1[2]=duzina(t[2],t[0]);
        return stranice1[0]+stranice1[1]+stranice1[2];

    }
    double DajPovrsinu() const {
        return fabs(Racun(t[0],t[1],t[2]))/2;
    }

    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(t[0],t[1],t[2])==1)
            return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(Trougao::t[0],Trougao::t[1],Trougao::t[2])==Orijentacija(Trougao::t[0],Trougao::t[1],t) && Orijentacija(Trougao::t[0],Trougao::t[1],t)==Orijentacija(Trougao::t[1],Trougao::t[2],t) && Orijentacija(Trougao::t[1],Trougao::t[2],t)==Orijentacija(Trougao::t[2],Trougao::t[0],t))
            return true;
        else return false;
    }
    void Ispisi() const {
        std::cout<<"(("<<t[0].first<<","<<t[0].second<<"),("<<t[1].first<<","<<t[1].second<<"),("<<t[2].first<<","<<t[2].second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        for(int i=0; i<3; i++) {
            t[i].first+=delta_x;
            t[i].second+=delta_y;
        }
    }
    void Centriraj(const Tacka &t) {
        Tacka p;
        p=DajCentar();
        for(int i=0; i<3; i++) {
            if(Trougao::t[i]==p)
                Trougao::t[i]=t;
        }
    }
    void Rotiraj(const Tacka &t, double ugao) {
        double x,y;
        for(int i=0; i<3; i++) {
            x=t.first+(Trougao::t[i].first-t.first)*std::cos(ugao)-(Trougao::t[i].second-t.second)*std::sin(ugao);
            y=t.second+(Trougao::t[i].first-t.first)*std::sin(ugao)+(Trougao::t[i].second-t.second)*std::cos(ugao);
            Trougao::t[i]= {x,y};
        }
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(fabs(faktor-0)<eps) throw std::domain_error ("Nekorektan faktor skaliranja");
        double x,y;
        for(int i=0; i<3; i++) {
            x=t.first+(faktor*(Trougao::t[i].first-t.first));
            y=t.second+(faktor*(Trougao::t[i].second-t.second));
            Trougao::t[i]= {x,y};
        }
        if(faktor<0) this->Rotiraj(3.1415926536);
    }
    void Rotiraj(double ugao) {
        Tacka p;
        p=DajCentar();
        double x,y;
        for(int i=0; i<3; i++) {
            x=p.first+((t[i].first-p.first)*std::cos(ugao))-((t[i].second-p.second)*std::sin(ugao));
            y=p.second+((t[i].first-p.first)*std::sin(ugao))+((t[i].second-p.second)*std::cos(ugao));
            Trougao::t[i]= {x,y};
        }
    }
    void Skaliraj(double faktor) {
        Tacka t(DajCentar());
        if(fabs(faktor-0)<eps) throw std::domain_error ("Nekorektan faktor skaliranja");
        double x,y;
        for(int i=0; i<3; i++) {
            x=t.first+(faktor*(Trougao::t[i].first-t.first));
            y=t.second+(faktor*(Trougao::t[i].second-t.second));
            Trougao::t[i]= {x,y};
        }
        if(faktor<0) this->Rotiraj(3.1415926536);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    std::pair<double, Tacka> Tro1[3], Tro2[3];
    if(DaLiSuPodudarni(t1,t2))
        return true;
    Tro1[0].first=Trougao::duzina(t1.DajTjeme(1),t1.DajTjeme(2));
    Tro1[0].second=t1.DajTjeme(3);
    Tro1[1].first=Trougao::duzina(t1.DajTjeme(2),t1.DajTjeme(3));
    Tro1[1].second=t1.DajTjeme(1);
    Tro1[2].first=Trougao::duzina(t1.DajTjeme(3),t1.DajTjeme(1));
    Tro1[2].second=t1.DajTjeme(2);
    Tro2[0].first=Trougao::duzina(t2.DajTjeme(1),t2.DajTjeme(2));
    Tro2[0].second=t2.DajTjeme(3);
    Tro2[1].first=Trougao::duzina(t2.DajTjeme(2),t2.DajTjeme(3));
    Tro2[1].second=t2.DajTjeme(1);
    Tro2[2].first=Trougao::duzina(t2.DajTjeme(3),t2.DajTjeme(1));
    Tro2[2].second=t2.DajTjeme(2);
    std::pair<double, Tacka> *z;
    z=Tro1;
    std::sort(z,z+3);
    z=Tro2;
    std::sort(z,z+3);
     if(Trougao::Orijentacija(Tro1[0].second,Tro1[1].second,Tro1[2].second)!=Trougao::Orijentacija(Tro2[0].second,Tro2[1].second,Tro2[2].second))
        return false;
    for(int i=0; i<2; i++){
        if(fabs(Tro1[i].first/Tro2[i].first-Tro1[i+1].first/Tro2[i+1].first)>eps)
            return false;
    }
    return true;


}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    double stranice1[3],stranice2[3];
    stranice1[0]=Trougao::duzina(t1.DajTjeme(1),t1.DajTjeme(2));
    stranice1[1]=Trougao::duzina(t1.DajTjeme(2),t1.DajTjeme(3));
    stranice1[2]=Trougao::duzina(t1.DajTjeme(3),t1.DajTjeme(1));
    stranice2[0]=Trougao::duzina(t2.DajTjeme(1),t2.DajTjeme(2));
    stranice2[1]=Trougao::duzina(t2.DajTjeme(2),t2.DajTjeme(3));
    stranice2[2]=Trougao::duzina(t2.DajTjeme(3),t2.DajTjeme(1));
    int pronasao {};
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(fabs(stranice1[i]-stranice2[j])<eps) {
                pronasao++;
                break;
            }
    if(pronasao!=3)
        return false;
    std::pair<double, Tacka> Tro1[3], Tro2[3];

    Tro1[0].first=Trougao::duzina(t1.DajTjeme(1),t1.DajTjeme(2));
    Tro1[0].second=t1.DajTjeme(3);
    Tro1[1].first=Trougao::duzina(t1.DajTjeme(2),t1.DajTjeme(3));
    Tro1[1].second=t1.DajTjeme(1);
    Tro1[2].first=Trougao::duzina(t1.DajTjeme(3),t1.DajTjeme(1));
    Tro1[2].second=t1.DajTjeme(2);
    Tro2[0].first=Trougao::duzina(t2.DajTjeme(1),t2.DajTjeme(2));
    Tro2[0].second=t2.DajTjeme(3);
    Tro2[1].first=Trougao::duzina(t2.DajTjeme(2),t2.DajTjeme(3));
    Tro2[1].second=t2.DajTjeme(1);
    Tro2[2].first=Trougao::duzina(t2.DajTjeme(3),t2.DajTjeme(1));
    Tro2[2].second=t2.DajTjeme(2);
    std::pair<double, Tacka> *z;
    z=Tro1;
    std::sort(z,z+3);
    z=Tro2;
    std::sort(z,z+3);
    if(Trougao::Orijentacija(Tro1[0].second,Tro1[1].second,Tro1[2].second)!=Trougao::Orijentacija(Tro2[0].second,Tro2[1].second,Tro2[2].second))
        return false;
    return true;


}


bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    int pronasao=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(t1.DajTjeme(i+1)==t2.DajTjeme(j+1)) {
                pronasao++;
                break;
            }
    if(pronasao==3)
        return true;
    else return false;
}

int main ()
{
    Tacka t[3];
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> T(n);
    for(int i=0; i<n; i++) {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        for(int j=0; j<3; j++)
            std::cin>>t[j].first>>t[j].second;
        try {
            T[i] = std::make_shared<Trougao>(t[0], t[1], t[2]);
        } catch(std::domain_error e) {
            cout<<e.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    double dx,dy,ugao,faktor;
    cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;

    std::transform(T.begin(),T.end(),T.begin(),[dx,dy](std::shared_ptr<Trougao> p) {
        p->Transliraj(dx,dy);
        return p;
    });
    std::transform(T.begin(),T.end(),T.begin(),[ugao](std::shared_ptr<Trougao> p) {
        p->Rotiraj(ugao);
        return p;
    });
    std::transform(T.begin(),T.end(),T.begin(),[faktor](std::shared_ptr<Trougao> p) {
        p->Skaliraj(p->DajTjeme(1),faktor);
        return p;
    });
    std::sort(T.begin(),T.end(),[](std::shared_ptr<Trougao> p1,std::shared_ptr<Trougao> p2) {
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });

    cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(T.begin(),T.end(),[](std::shared_ptr<Trougao> p) {
        p->Ispisi();
        cout<<std::endl;

    });
    std::shared_ptr<Trougao> O;
    if(n!=0) {O = std::make_shared<Trougao>(t[0], t[1], t[2]);
    O=*std::max_element(T.begin(),T.end(),[](std::shared_ptr<Trougao> p1,std::shared_ptr<Trougao> p2) {
        return p1->DajObim()>p2->DajObim();
    });
        cout<<"Trougao sa najmanjim obimom: ";
    O->Ispisi();
    cout<<std::endl;
    }else  cout<<"Trougao sa najmanjim obimom: "<<std::endl;
    int z=0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(i==j)
                continue;
            if(DaLiSuIdenticni(*T[i],*T[j])) {
                if(z==0) {
                    cout<<"Parovi identicnih trouglova: "<<std::endl;
                    z++;
                }
                T[i]->Ispisi();
                cout<<" i ";
                T[j]->Ispisi();
                cout<<std::endl;
            }
        }
    }
    if(z==0) cout<<"Nema identicnih trouglova!"<<std::endl;
    z=0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(i==j)
                continue;
            else if(DaLiSuPodudarni(*T[i],*T[j])) {
                if(z==0) {
                    cout<<"Parovi podudarnih trouglova: "<<std::endl;
                    z++;
                }
                T[i]->Ispisi();
                cout<<" i ";
                T[j]->Ispisi();
                cout<<std::endl;
            }
        }
    }
    if(z==0) cout<<"Nema podudarnih trouglova!"<<std::endl;
    z=0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(i==j)
                continue;
            if(DaLiSuSlicni(*T[i],*T[j])) {
                if(z==0) {
                    cout<<"Parovi slicnih trouglova: "<<std::endl;
                    z++;
                }
                T[i]->Ispisi();
                cout<<" i ";
                T[j]->Ispisi();
                cout<<std::endl;
            }
        }
    }

    if(z==0)
        cout<<"Nema slicnih trouglova!"<<std::endl;
    return 0;
}