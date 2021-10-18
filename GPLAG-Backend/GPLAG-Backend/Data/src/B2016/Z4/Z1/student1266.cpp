#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::shared_ptr;
using std::make_shared;

typedef std::pair<double, double> Tacka;

double s(const Tacka &t1, const Tacka &t2, const Tacka &t3) {return t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);}

class Trougao
{
    Tacka koor[3];
    double duz(const Tacka &A, const Tacka &B) const
    {
        return sqrt((A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second));
    }
    double strnas(int o) const
    {
        if(o==1) return duz(koor[1], koor[2]);
        if(o==2) return duz(koor[0], koor[2]);
        return duz(koor[0], koor[1]);
    }
    static bool prd(double a, double b){return fabs(a-b)<1e-10;}
    
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

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(s(t1, t2, t3) > 0)
    return 1;
    else
    if(s(t1, t2, t3) < 0)
    return -1;
    return 0;
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(!Orijentacija(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
    this->koor[0]=t1;
    this->koor[1]=t2;
    this->koor[2]=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(!Orijentacija(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
    this->koor[0]=t1;
    this->koor[1]=t2;
    this->koor[2]=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t)
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    this->koor[indeks-1]=t;
}
Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    return this->koor[indeks-1];
}
double Trougao::DajStranicu(int indeks) const
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    return this->strnas(indeks);
}
double Trougao::DajUgao(int indeks) const
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    int a, b, c;
    if(indeks==1)
    {
        a=2;
        b=3;
        c=1;
    }
    if(indeks==2)
    {
        a=1;
        b=3;
        c=2;
    }
    if(indeks==3)
    {
        a=1;
        b=2;
        c=3;
    }
    return acos((Trougao::DajStranicu(a)*Trougao::DajStranicu(a) + Trougao::DajStranicu(b)*Trougao::DajStranicu(b) - Trougao::DajStranicu(c)*Trougao::DajStranicu(c)) / (2*Trougao::DajStranicu(a)*Trougao::DajStranicu(b)));
}
Tacka Trougao::DajCentar() const
{
    Tacka cen;
    cen.first=(this->koor[0].first + this->koor[1].first + this->koor[2].first)/3;
    cen.second=(this->koor[0].second + this->koor[1].second + this->koor[2].second)/3;
    return cen;
}
double Trougao::DajObim() const
{
    return this->DajStranicu(1) + this->DajStranicu(2) + this->DajStranicu(3);
}
double Trougao::DajPovrsinu() const
{
    Tacka t1=this->DajTjeme(1);
    Tacka t2=this->DajTjeme(2);
    Tacka t3=this->DajTjeme(3);
    return 1/2. * fabs(s(t1, t2, t3));
}
bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    return(Trougao::Orijentacija(Trougao::DajTjeme(1), Trougao::DajTjeme(2), Trougao::DajTjeme(3)));
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    int orj=Trougao::Orijentacija(Trougao::DajTjeme(1), Trougao::DajTjeme(2), Trougao::DajTjeme(3));
    return(orj==Trougao::Orijentacija(Trougao::DajTjeme(1), Trougao::DajTjeme(2), t) && orj==Trougao::Orijentacija(Trougao::DajTjeme(2), Trougao::DajTjeme(3), t) && orj==Trougao::Orijentacija(Trougao::DajTjeme(3), Trougao::DajTjeme(1), t));
}
void Trougao::Ispisi() const
{
    cout << "((" << koor[0].first << "," << koor[0].second << "),(" << koor[1].first << "," << koor[1].second << "),(" << koor[2].first << "," << koor[2].second << "))";
}
void Trougao::Transliraj(double delta_x, double delta_y)
{
    this->koor[0].first+=delta_x;
    this->koor[0].second+=delta_y;
    this->koor[1].first+=delta_x;
    this->koor[1].second+=delta_y;
    this->koor[2].first+=delta_x;
    this->koor[2].second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t)
{
    Trougao::Transliraj(t.first-Trougao::DajCentar().first, t.second-Trougao::DajCentar().second);
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double a;
    a=t.first + (koor[0].first-t.first)*cos(ugao) - (koor[0].second-t.second)*sin(ugao);
    this->koor[0].second=t.second + (koor[0].first-t.first)*sin(ugao) + (koor[0].second-t.second)*cos(ugao);
    this->koor[0].first=a;
    a=t.first + (koor[1].first-t.first)*cos(ugao) - (koor[1].second-t.second)*sin(ugao);
    this->koor[1].second=t.second + (koor[1].first-t.first)*sin(ugao) + (koor[1].second-t.second)*cos(ugao);
    this->koor[1].first=a;
    a=t.first + (koor[2].first-t.first)*cos(ugao) - (koor[2].second-t.second)*sin(ugao);
    this->koor[2].second=t.second + (koor[2].first-t.first)*sin(ugao) + (koor[2].second-t.second)*cos(ugao);
    this->koor[2].first=a;
}
void Trougao::Rotiraj(double ugao)
{
    Trougao::Rotiraj(Trougao::DajCentar(), ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
    this->koor[0].first=t.first + faktor*(koor[0].first-t.first);
    this->koor[0].second=t.second + faktor*(koor[0].second-t.second);
    this->koor[1].first=t.first + faktor*(koor[1].first-t.first);
    this->koor[1].second=t.second + faktor*(koor[1].second-t.second);
    this->koor[2].first=t.first + faktor*(koor[2].first-t.first);
    this->koor[2].second=t.second + faktor*(koor[2].second-t.second);
}
void Trougao::Skaliraj(double faktor)
{
    Trougao::Skaliraj(Trougao::DajCentar(), faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    int a, b;
    if(t1.koor[0]==t2.koor[0])
    {
        a=1;
        b=2;
    }
    else if(t1.koor[0]==t2.koor[1])
    {
        a=0;
        b=2;
    }
    else if(t1.koor[0]==t2.koor[2])
    {
        a=0;
        b=1;
    }
    else return false;
    if(t1.koor[1]==t2.koor[a])
    {
        if(t1.koor[2]==t2.koor[b]) return true;
    }
    else if(t1.koor[1]==t2.koor[b])
    {
        if(t1.koor[2]==t2.koor[a]) return true;
    }
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                if(t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(i), t2.DajTjeme(j), t2.DajTjeme(k)))
                {
                    double a1=t1.DajStranicu(1);
                    double a2=t2.DajStranicu(i);
                    double b1=t1.DajStranicu(2);
                    double b2=t2.DajStranicu(j);
                    double c1=t1.DajStranicu(3);
                    double c2=t2.DajStranicu(k);
                    if(Trougao::prd(a1, a2) && Trougao::prd(b1, b2) && Trougao::prd(c1, c2)) return true;
                }
            }
        }
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                if(t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(i), t2.DajTjeme(j), t2.DajTjeme(k)))
                {

                    double a1=t1.DajUgao(1);
                    double a2=t2.DajUgao(i);
                    double b1=t1.DajUgao(2);
                    double b2=t2.DajUgao(j);
                    double c1=t1.DajUgao(3);
                    double c2=t2.DajUgao(k);
                    if(Trougao::prd(a1, a2) && Trougao::prd(b1, b2) && Trougao::prd(c1, c2)) return true;
                }
            }
        }
    }
    return false;
}

int main ()
{
    int n;
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    vector<shared_ptr<Trougao>> v(n);
    double x1, y1, x2, y2, x3, y3;
    for(int i=0;i<n;i++)
    {
        cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        try
        {
            Tacka A(x1, y1);
            Tacka B(x2, y2);
            Tacka C(x3, y3);
            Trougao t(A, B, C);
            v[i]=make_shared<Trougao> (t);
        }
        catch(std::domain_error ero)
        {
            cout << ero.what() << ", ponovite unos!\n";
            i--;
        }
    }
    double dx, dy;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> dx >> dy;
    double ug;
    cout << "Unesite ugao rotacije: ";
    cin >> ug;
    double fak;
    cout << "Unesite faktor skaliranja: ";
    cin >> fak;
    vector <shared_ptr<Trougao>> tr(n);
    std::transform(v.begin(), v.end(), tr.begin(), [dx, dy, ug, fak](shared_ptr<Trougao> t)
    {
        t->Transliraj(dx, dy);
        t->Rotiraj(ug);
        t->Skaliraj(t->DajTjeme(1), fak);
        return t;
    });
    std::sort(tr.begin(), tr.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2)
    {
        double p1=t1->DajPovrsinu();
        double p2=t2->DajPovrsinu();
        return p1<p2;
    });
    cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(tr.begin(), tr.end(), [](shared_ptr<Trougao> t)
    {
        t->Ispisi();
        cout << "\n";
    });
    shared_ptr<Trougao> m=*min_element(tr.begin(), tr.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2)
    {
        double o1=t1->DajObim();
        double o2=t2->DajObim();
        return o1<o2;
    });
    cout << "Trougao sa najmanjim obimom: ";
    m->Ispisi();
    cout << "\n";
    int kk=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(DaLiSuIdenticni(*tr[i], *tr[j]))
            {
                if(!kk) cout << "Parovi identicnih trouglova:\n";
                tr[i]->Ispisi();
                cout << " i ";
                tr[j]->Ispisi();
                cout << "\n";
                kk++;
            }
        }
    }
    if(!kk) cout << "Nema identicnih trouglova!\n";
    kk=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(DaLiSuPodudarni(*tr[i], *tr[j]))
            {
                if(!kk) cout << "Parovi podudarnih trouglova:\n";
                tr[i]->Ispisi();
                cout << " i ";
                tr[j]->Ispisi();
                cout << "\n";
                kk++;
            }
        }
    }
    if(!kk) cout << "Nema podudarnih trouglova!\n";
    kk=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(DaLiSuSlicni(*tr[i], *tr[j]))
            {
                if(!kk) cout << "Parovi slicnih trouglova:\n";
                tr[i]->Ispisi();
                cout << " i ";
                tr[j]->Ispisi();
                cout << "\n";
                kk++;
            }
        }
    }
    if(!kk) cout << "Nema slicnih trouglova!\n";
    return 0;
}