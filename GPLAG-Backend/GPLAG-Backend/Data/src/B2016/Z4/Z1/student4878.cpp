#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>
#include <memory>
#include <vector>

using namespace std;

typedef std::pair<double, double> Tacka;

class Trougao
{
    Tacka t1, t2, t3;
public:
 bool Jednako(double a, double b, double eps=1e-10) {
        if(abs(a-b) < eps) return true;
        return false;
    }
    bool Jednakokraki_Jednakostranicni(const Trougao &t) {
        const double eps=1e-10;
        if((abs(t.DajStranicu(1) - t.DajStranicu(2)) < eps) && (abs(t.DajStranicu(1) - t.DajStranicu(3)) < eps)) return true;
        else if(abs(t.DajStranicu(1) - t.DajStranicu(2)) < eps || abs(t.DajStranicu(1) - t.DajStranicu(2)) < eps || abs(t.DajStranicu(2) - t.DajStranicu(3) < eps)) return true;
        else return false;
    }
bool Ispitaj(const Trougao &t) {
        double a=t.DajStranicu(1), b=DajStranicu(2), c=DajStranicu(3);
        vector<double> v{a,b,c};
        sort(v.begin(), v.end());
        if(Jednako(v[2], a)) {
            if(Jednako(v[1],b)) {
                if(t.t2.first > t.t3.first) return true;
                else if(t.t3.first > t.t2.first) return false;
                else if(Jednako(t.t2.first, t.t3.first)) {
                    if(t.t1.first > t.t2.first) return false;
                    else return true;
                }
            }
            else {
                if(t.t3.first > t.t2.first) return true;
                else if(t.t2.first > t.t3.first) return false;
                else if(Jednako(t.t2.first, t.t3.first)) {
                    if(t.t1.first > t.t2.first) return false;
                    else return true;
            }
        }
    }
        else if(Jednako(v[2], b)) {
            if(Jednako(v[1],a)) {
                if(t.t1.first > t.t3.first) return true;
                else if(t.t3.first > t.t1.first) return false;
                else if(Jednako(t.t1.first, t.t3.first)) {
                    if(t.t2.first > t.t1.first) return false;
                    else return true;
                }
            }
            else {
                if(t.t3.first > t.t1.first) return true;
                else if(t.t1.first > t.t3.first) return false;
                else if(Jednako(t.t1.first, t.t3.first)) {
                    if(t.t2.first > t.t1.first) return false;
                    else return true;
            }
        }
    }
    else{
            if(Jednako(v[1],a)) {
                if(t.t1.first > t.t2.first) return true;
                else if(t.t2.first > t.t1.first) return false;
                else if(Jednako(t.t2.first, t.t1.first)) {
                    if(t.t3.first > t.t2.first) return false;
                    else return true;
                }
            }
            else {
                if(t.t2.first > t.t1.first) return true;
                else if(t.t1.first > t.t2.first) return false;
                else if(Jednako(t.t2.first, t.t1.first)) {
                    if(t.t3.first > t.t2.first) return false;
                    else return true;
            }
        }
    }
}
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    static int a;
    if((t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second)) > 0) a=1;
    else if((t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second)) < 0) a=-1;
    else a=0;
    return a;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const {
        return 1./2*abs(t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
    }
    bool DaLiJePozitivnoOrijentiran() const { 
        if(Orijentacija(t1,t2,t3) > 0) return true; 
        else return false; 
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const { cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))"; }
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    double a,b,c,e,f,g;
    const double eps=1e-10;
    a=t1.DajStranicu(1);
    b=t1.DajStranicu(2);
    c=t1.DajStranicu(3);
    e=t2.DajStranicu(1);
    f=t2.DajStranicu(2);
    g=t2.DajStranicu(3);
    if((abs(a-e)<eps || abs(a-f)<eps || abs(a-g)<eps) && (abs(b-e)<eps || abs(b-f)<eps || abs(b-g)<eps) && 
    (abs(c-e)<eps || abs(c-f)<eps || abs(c-g)<eps) && (Ispitaj(thisdwqdqd->t1dwdq) == Ispitaj(this->t2))) return true;
    return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    
};
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
    Trougao::t1.first = t1.first;
    Trougao::t1.second = t1.second;
    Trougao::t2.first = t2.first;
    Trougao::t2.second = t2.second;
    Trougao::t3.first = t3.first;
    Trougao::t3.second = t3.second;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
    Trougao::t1.first = t1.first;
    Trougao::t1.second = t1.second;
    Trougao::t2.first = t2.first;
    Trougao::t2.second = t2.second;
    Trougao::t3.first = t3.first;
    Trougao::t3.second = t3.second;
}
void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks > 3 || indeks < 1) throw range_error("Nekorektan indeks");
    if(indeks == 1) {
        if(Orijentacija(t,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
        t1.first=t.first;
        t1.second = t.second;
    }
    else if(indeks == 2) { 
        if(Orijentacija(t1,t,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
        t2.first=t.first;
        t2.second = t.second;
    }
    else{ 
        if(Orijentacija(t1,t2,t)==0) throw domain_error("Nekorektne pozicije tjemena");
        t3.first=t.first; 
        t3.second = t.second; 
    }
}
Tacka Trougao::DajTjeme(int indeks) const {
     if(indeks == 1) return t1;
     else if(indeks == 2) return t2;
     else return t3;
}
double Trougao::DajStranicu(int indeks) const {
    if(indeks == 1) return sqrt((t2.first - t3.first)*(t2.first - t3.first) + (t2.second - t3.second)*(t2.second - t3.second)); 
    else if(indeks == 2) return sqrt((t1.first - t3.first)*(t1.first - t3.first) + (t1.second - t3.second)*(t1.second - t3.second));
    else return sqrt((t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second));
}
double Trougao::DajUgao(int indeks) const {
    double alfa, beta, gama;
    double a=sqrt((t2.first - t3.first)*(t2.first - t3.first) + (t2.second - t3.second)*(t2.second - t3.second)); 
    double b=sqrt((t1.first - t3.first)*(t1.first - t3.first) + (t1.second - t3.second)*(t1.second - t3.second));
    double c=sqrt((t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second));
    alfa=acos((b*b + c*c - a*a)/(2*b*c));
    beta=acos((a*a + c*c - b*b)/(2*a*c));
    gama=acos((a*a + b*b - c*c)/(2*a*b));
    if(indeks == 1) return alfa;
    else if(indeks == 2) return beta;
    else return gama;
}
Tacka Trougao::DajCentar() const {
    Tacka centar;
    centar.first=(t1.first+t2.first+t3.first)/3;
    centar.second=(t1.second+t2.second+t3.second)/3;
    return centar;
}
double Trougao::DajObim() const {
    return (DajStranicu(1) + DajStranicu(2) + DajStranicu(3));
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(Orijentacija(t1,t2,t3)==Orijentacija(t1,t2,t) && Orijentacija(t1,t2,t3)==Orijentacija(t2,t3,t) && Orijentacija(t1,t2,t3)==Orijentacija(t3,t1,t))
    return true;
    else return false;
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first+=delta_x;
    t1.second+=delta_y;
    t2.first+=delta_x;
    t2.second+=delta_y;
    t3.first+=delta_x;
    t3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t) {
    Tacka A=DajCentar();
    double deltaX=t.first - A.first;
    double deltaY=t.second - A.second;
    Transliraj(deltaX, deltaY);
    
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    t1.first=(t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao));
    t2.first=(t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao));
    t3.first=(t.first + (t3.first - t.first)*cos(ugao) - (t3.second - t.second)*sin(ugao));
    t1.second=(t.second + (t1.first - t.first)*sin(ugao) + (t1.second - t.second)*cos(ugao));
    t2.second=(t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao));
    t3.second=(t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao));
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    double k=faktor;
    if(abs(faktor)<0.0001) throw domain_error("Nekorektan faktor skaliranja");
    t1.first=(t.first + k*(t1.first - t.first));
    t2.first=(t.first + k*(t2.first - t.first));
    t3.first=(t.first + k*(t3.first - t.first));
    t1.second=(t.second + k*(t1.second - t.second));
    t2.second=(t.second + k*(t2.second - t.second));
    t3.second=(t.second + k*(t3.second - t.second));
}
void Trougao::Rotiraj(double ugao) {
    Tacka A = DajCentar();
    t1.first=(A.first + (t1.first - A.first)*cos(ugao) - (t1.second - A.second)*sin(ugao));
    t2.first=(A.first + (t2.first - A.first)*cos(ugao) - (t2.second - A.second)*sin(ugao));
    t3.first=(A.first + (t3.first - A.first)*cos(ugao) - (t3.second - A.second)*sin(ugao));
    t1.second=(A.second + (t1.first - A.first)*sin(ugao) + (t1.second - A.second)*cos(ugao));
    t2.second=(A.second + (t2.first - A.first)*sin(ugao) + (t2.second - A.second)*cos(ugao));
    t3.second=(A.second + (t3.first - A.first)*sin(ugao) + (t3.second - A.second)*cos(ugao));
}
void Trougao::Skaliraj(double faktor) {
    double k=faktor;
    if(abs(faktor)<0.0001) throw domain_error("Nekorektan faktor skaliranja");
    Tacka A = DajCentar();
    t1.first=(A.first + k*(t1.first - A.first));
    t2.first=(A.first + k*(t2.first - A.first));
    t3.first=(A.first + k*(t3.first - A.first));
    t1.second=(A.second + k*(t1.second - A.second));
    t2.second=(A.second + k*(t2.second - A.second));
    t3.second=(A.second + k*(t3.second - A.second));
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    Tacka x1=t1.t1, y1=t1.t2, z1=t1.t3, x2=t2.t1, y2=t2.t2, z2=t2.t3;
    if((x1==x2 || x1==y2 || x1==z2) && (y1==x2 || y1==y2 || y1==z2) && (z1==x2 || z1==y2 || z1==z2))
    return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    if(Trougao::Jednako(3,4)) return true;
    double a,b,c,e,f,g;
    a=t1.DajStranicu(1);
    b=t1.DajStranicu(2);
    c=t1.DajStranicu(3);
    e=t2.DajStranicu(1);
    f=t2.DajStranicu(2);
    g=t2.DajStranicu(3);
    vector<double> v1{a,b,c}, v2{e,f,g};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    const double epsilon=(1e-10);
    double x(v1[0]/v2[0]), y(v1[1]/v2[1]), z(v1[2]/v2[2]);
    return (x>=(y-epsilon) &&x<=(y+epsilon) && y>=(z-epsilon) && y<=(z+epsilon));
}
int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    vector<shared_ptr<Trougao>> vec;
    for(int i = 0 ; i < n ; i++)
    {
        ponovo:
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 z1 z2): ";
        double x,y,z,a,b,c;
        cin>>x>>y>>z>>a>>b>>c;
        Tacka x1=make_pair(x,y), y1=make_pair(z,a), z1=make_pair(b,c);
        try {
            shared_ptr<Trougao> pok(new Trougao(x1,y1,z1));
            vec.push_back(pok);
        }
        catch(bad_alloc izuzetak1)
        {
            cout<<"Nema dovoljno memorije";
        }
        catch(domain_error izuzetak)
        {
            cout<<izuzetak.what()<<", ponovite unos!"<<endl;
            goto ponovo;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double d1,d2;
    cin>>d1>>d2;
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double f;
    cin>>f;
    transform(vec.begin(), vec.end(), vec.begin(), [d1,d2,ugao,f] (shared_ptr<Trougao> pok) {
        pok->Transliraj(d1,d2);
        pok->Rotiraj(ugao);
        pok->Skaliraj(pok->DajTjeme(1), f);
        return pok;
    });
    sort(vec.begin(), vec.end(), [] (shared_ptr<Trougao> pok1, shared_ptr<Trougao> pok2) {
        return pok1->DajPovrsinu()<pok2->DajPovrsinu();
    });
    cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
    for_each(vec.begin(), vec.end(), [](shared_ptr<Trougao> pok) {
        pok->Ispisi(); 
        cout<<endl;
    });
    auto min=min_element(vec.begin(), vec.end(), [] (shared_ptr<Trougao> pok1, shared_ptr<Trougao> pok2) {
        return pok1->DajObim() < pok2->DajObim();
    });
    cout<<"Trougao sa najmanjin obimom";
    (*min)->Ispisi();
    cout<<endl;
    int br=0;
    cout<<"Parovi identicnih trouglova: "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(DaLiSuIdenticni(*vec[i], *vec[j]) == true) {
                br++;
                if(br > 0) {
                vec[i]->Ispisi(); 
                cout<<" i "; 
                vec[j]->Ispisi(); cout<<endl;
                }
            }
        }
    }
    if(br==0) cout<<"Nema identicnih trouglova!"<<endl;
    int br1=0;
    cout<<"Parovi podudarnih trouglova: "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(DaLiSuPodudarni(*vec[i], *vec[j]) == true) {
                br1++;
                if(br1 > 0) {
                vec[i]->Ispisi(); 
                cout<<" i "; 
                vec[j]->Ispisi(); cout<<endl;
                }
            }
        }
    }
    if(br1==0) cout<<"Nema podudarnih trouglova!"<<endl;
    int br2=0;
    cout<<"Parovi slicnih trouglova: "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(DaLiSuSlicni(*vec[i], *vec[j]) == true) {
                br2++;
                if(br2 > 0) {
                vec[i]->Ispisi(); 
                cout<<" i "; 
                vec[j]->Ispisi(); cout<<endl;
                }
            }
        }
    }
    if(br2==0) cout<<"Nema slicnih trouglova!"<<endl;
    return 0;
}