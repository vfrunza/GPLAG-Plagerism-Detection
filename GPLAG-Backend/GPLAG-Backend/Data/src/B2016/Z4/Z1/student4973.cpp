/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

using namespace std;

typedef pair<double, double> Tacka;
const double eps = 1e-4;
const double PI= 4 * atan(1);


class Trougao
{

    Tacka t1;
    Tacka t2;
    Tacka t3;

public:
    Trougao(const Tacka &T1, const Tacka &T2, const Tacka &T3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const {
        if(indeks<=0 || indeks>=4) throw range_error("Nekorektan indeks");
        if(indeks==1) {
            return t1;
        }
        if(indeks==2) {
            return t2;
        } else {
            return t3;
        }
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const {
        Tacka pom;
        double x=((t1.first+t2.first+t3.first)/3);
        double y=((t1.second+t2.second+t3.second)/3);
        pom.first=x;
        pom.second=y;
        return pom;
    }
    double DajObim() const ;
    double DajPovrsinu() const ;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &tr1, const Trougao &tr2);
    friend bool DaLiSuPodudarni(const Trougao &tr1, const Trougao &tr2);
    friend bool DaLiSuSlicni(const Trougao &tr1, const Trougao &tr2);
};

Trougao::Trougao(const Tacka &T1, const Tacka &T2, const Tacka &T3)
{
    Trougao::t1.first=T1.first;
    Trougao::t1.second=T1.second;
    Trougao::t2.first=T2.first;
    Trougao::t2.second=T2.second;
    Trougao::t3.first=T3.first;
    Trougao::t3.second=T3.second;

    if(abs((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))) <eps) throw domain_error("Nekorektne pozicije tjemena");

}

void Trougao::Postavi(const Tacka &T1, const Tacka &T2, const Tacka &T3)
{
    Trougao::t1.first=T1.first;
    Trougao::t1.second=T1.second;
    Trougao::t2.first=T2.first;
    Trougao::t2.second=T2.second;
    Trougao::t3.first=T3.first;
    Trougao::t3.second=T3.second;

    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<eps) throw domain_error("Nekorektne pozicije tjemena");
}
void Trougao::Postavi(int indeks,const Tacka &t)
{
    if(indeks<=0 || indeks>=4) throw range_error("Nekorektan indeks");
    if(indeks==1) {
        Trougao::t1.first=t.first;
        Trougao::t1.second=t.second;
    }
    if(indeks==2) {
        Trougao::t2.first=t.first;
        Trougao::t2.second=t.second;
    }
    if(indeks==3) {
        Trougao::t3.first=t.first;
        Trougao::t3.second=t.second;
    }
}

void Trougao::Ispisi() const
{
    cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}



static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0) return 1;
    else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0) return-1;
    else return 0;
}



double Trougao::DajStranicu(int indeks) const
{
    if(indeks<=0 || indeks>=4) throw range_error("Nekorektan indeks");
    if(indeks==1) {
        return sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
    }
    if(indeks==2) {
        return sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
    } else {
        return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    }
}

double Trougao::DajUgao(int indeks) const
{
    if(indeks<=0 || indeks>=4) throw range_error("Nekorektan indeks");
    double a=sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
    double b=sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
    double c=sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));

    double ugao=0;

    if(indeks==1) {
        ugao=((b*b+c*c-a*a)/(2*b*c));
    }
    if(indeks==2) {
        ugao=((a*a+c*c-b*b)/(2*a*c));
    } else {
        ugao=((a*a+b*b-c*c)/(2*a*b));
    }

    return acos(ugao);
}

double Trougao::DajObim() const
{
    double O=0;
    double a=sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
    double b=sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
    double c=sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    O=a+b+c;
    return O;
}

double Trougao::DajPovrsinu() const
{
    double P=0;
    P=fabs((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))/2);
    return P;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0) return true;
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    bool b1,b2,b3;
    b1=((t.first-t2.first)*(t1.second-t2.second)-(t1.first-t2.second)*(t.second-t2.second))<0.0f;
    b2=((t.first-t3.first)*(t2.second-t3.second)-(t2.first-t3.second)*(t.second-t3.second))<0.0f;
    b3=((t.first-t1.first)*(t3.second-t1.second)-(t3.first-t1.second)*(t.second-t1.second))<0.0f;

    return ((b1==b2) && (b2==b3));


}

void Trougao::Transliraj(double delta_x,double delta_y)
{


    t1.first = t1.first + delta_x;
    t1.second = t1.second + delta_y;

    t2.first = t2.first + delta_x;
    t2.second = t2.second + delta_y;

    t3.first = t3.first + delta_x;
    t3.second = t3.second + delta_y;

}

void Trougao::Centriraj(const Tacka &t)
{
    Tacka pom;
    double x=((t1.first+t2.first+t3.first)/3);
    double y=((t1.second+t2.second+t3.second)/3);
    pom.first=x;
    pom.second=y;
    Transliraj(x,y);

}

void Trougao::Rotiraj(const Tacka &t,double ugao)
{

    t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);

    t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);

    t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);

}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(abs(faktor)<eps) throw domain_error("Nekorektan faktor skaliranja");

    t1.first=(t.first+faktor*(t1.first-t.first));
    t1.second=(t.second+faktor*(t1.second-t.second));

    t2.first=(t.first+faktor*(t2.first-t.first));
    t2.second=(t.second+faktor*(t2.second-t.second));

    t3.first=(t.first+faktor*(t3.first-t.first));
    t3.second=(t.second+faktor*(t3.second-t.second));

    if(faktor<0) this->Rotiraj(180);

}


void Trougao::Rotiraj(double ugao)
{

    Tacka pom;
    double x=((t1.first+t2.first+t3.first)/3);
    double y=((t1.second+t2.second+t3.second)/3);
    pom.first=x;
    pom.second=y;

    t1.first=pom.first+(t1.first-pom.first)*cos(ugao)-(t1.second-pom.second)*sin(ugao);
    t1.second=pom.second+(t1.first-pom.first)*sin(ugao)+(t1.second-pom.second)*cos(ugao);

    t2.first=pom.first+(t2.first-pom.first)*cos(ugao)-(t2.second-pom.second)*sin(ugao);
    t2.second=pom.second+(t2.first-pom.first)*sin(ugao)+(t2.second-pom.second)*cos(ugao);

    t3.first=pom.first+(t3.first-pom.first)*cos(ugao)-(t3.second-pom.second)*sin(ugao);
    t3.second=pom.second+(t3.first-pom.first)*sin(ugao)+(t3.second-pom.second)*cos(ugao);


}


void Trougao::Skaliraj(double faktor)
{
    if(abs(faktor)<eps) throw domain_error("Nekorektan faktor skaliranja");
    Tacka pom;
    double x=((t1.first+t2.first+t3.first)/3);
    double y=((t1.second+t2.second+t3.second)/3);
    pom.first=x;
    pom.second=y;

    t1.first=(pom.first+faktor*(t1.first-pom.first));
    t1.second=(pom.second+faktor*(t1.second-pom.second));

    t2.first=(pom.first+faktor*(t2.first-pom.first));
    t2.second=(pom.second+faktor*(t2.second-pom.second));

    t3.first=(pom.first+faktor*(t3.first-pom.first));
    t3.second=(pom.second+faktor*(t3.second-pom.second));
}


bool DaLiSuIdenticni(const Trougao &tr1,const Trougao &tr2)
{
    vector<Tacka> tacke1,tacke2;
    for(int i(1); i < 4; i++) {
        tacke1.push_back(tr1.DajTjeme(i));
        tacke2.push_back(tr2.DajTjeme(i));
    }
    for(int t(0); t < 3; t++) {


        for(int i(0); i < tacke1.size(); i++) {
            for(int j(0); j < tacke2.size(); j++) {
                if(abs(tacke1[i].first - tacke2[j].first) < eps && abs(tacke1[i].second - tacke2[j].second) < eps) {
                    tacke1.erase(tacke1.begin() + i);
                    tacke2.erase(tacke2.begin() + j);
                    j--;
                    i--;
                }
            }
        }
    }
    return tacke1.empty() && tacke2.empty();
}
bool DaLiSuPodudarni(const Trougao &tr1, const Trougao &tr2)
{

    if((abs(tr1.DajStranicu(1) - tr2.DajStranicu(1)) < eps && abs(tr1.DajStranicu(2) - tr2.DajStranicu(2)) < eps && abs(tr1.DajStranicu(3) -tr2.DajStranicu(3)) < eps) || (abs(tr1.DajUgao(2) - tr2.DajUgao(2)) < eps && abs(tr1.DajUgao(3) - tr2.DajUgao(3)) < eps && abs(tr1.DajStranicu(2) - tr2.DajStranicu(2)) < eps && abs(tr1.DajStranicu(3) -tr2.DajStranicu(3)) < eps))
        return true;
    if((abs(tr1.DajStranicu(1) - tr2.DajStranicu(2)) < eps && abs(tr1.DajStranicu(2) - tr2.DajStranicu(3)) < eps && abs(tr1.DajStranicu(3) -tr2.DajStranicu(1)) < eps) || (abs(tr1.DajUgao(2) - tr2.DajUgao(3)) < eps && abs(tr1.DajUgao(3) - tr2.DajUgao(1)) < eps && abs(tr1.DajStranicu(2) - tr2.DajStranicu(3)) < eps && abs(tr1.DajStranicu(3) -tr2.DajStranicu(1)) < eps))
        return true;
    if((abs(tr1.DajStranicu(1) - tr2.DajStranicu(3)) < eps && abs(tr1.DajStranicu(2) - tr2.DajStranicu(1)) < eps && abs(tr1.DajStranicu(3) -tr2.DajStranicu(2)) < eps) || (abs(tr1.DajUgao(2) - tr2.DajUgao(1)) < eps && abs(tr1.DajUgao(3) - tr2.DajUgao(2)) < eps && abs(tr1.DajStranicu(2) - tr2.DajStranicu(1)) < eps && abs(tr1.DajStranicu(3) -tr2.DajStranicu(2)) < eps))
            return true;


            return false;
        }
bool DaLiSuSlicni(const Trougao &tr1, const Trougao &tr2)
{
    double k1,k2,k3;


    k1 = tr1.DajStranicu(1) / tr2.DajStranicu(1);
    if(abs(tr1.DajStranicu(2)/tr2.DajStranicu(2) - k1) < eps && abs(tr1.DajStranicu(3)/tr2.DajStranicu(3) - k1) < eps)
        return true;
    k2 = tr1.DajStranicu(1) / tr2.DajStranicu(2);
    if(abs(tr1.DajStranicu(2)/tr2.DajStranicu(3) - k2) < eps && abs(tr1.DajStranicu(3)/tr2.DajStranicu(1) - k2) < eps)
        return true;
    k3 = tr1.DajStranicu(1) / tr2.DajStranicu(3);
    if(abs(tr1.DajStranicu(2)/tr2.DajStranicu(1) - k3) < eps && abs(tr1.DajStranicu(3)/tr2.DajStranicu(2) - k3) < eps)
        return true;

    return false;
}

bool Kriterij1(const shared_ptr<Trougao> &c,shared_ptr<Trougao> &d)
{
    return c->DajObim() > d->DajObim();
}


int main ()
{

    int n;
    double a,b,ugao,faktor;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<shared_ptr<Trougao>>v(n);
    Tacka t1, t2, t3;
    for(int i(0) ; i < n; i++) {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>t1.first;
        cin>>t1.second;
        cin>>t2.first;
        cin>>t2.second;
        cin>>t3.first;
        cin>>t3.second;

        try {
            v[i] = make_shared<Trougao>(t1, t2, t3);
        } catch(domain_error tekst ) {
            cout<<tekst.what()<<", ponovite unos!"<<endl;
            i--;

        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    cin>>a>>b;
    cout<<"Unesite ugao rotacije: ";
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    cin>>faktor;
    cout<<"Trouglovi nakon obavljenih transformacija:";
    transform (v.begin(),v.end(),v.begin(),[a,b,ugao,faktor] (shared_ptr<Trougao> &c) {
        c->Transliraj(a,b);
        c->Rotiraj(ugao);
        c->Skaliraj(c->DajTjeme(1),faktor);
        return c;
    });
    sort(v.begin(),v.end(),[](const shared_ptr<Trougao> &a, const shared_ptr<Trougao> &b) {
        return a->DajPovrsinu() < b->DajPovrsinu();
    });
    for_each(v.begin(),v.end(),[](const shared_ptr<Trougao> &x) {
        x->Ispisi();
        cout << endl;
    });


    cout<<"Trougao sa najmanjim obimom: ";
    (*max_element (v.begin(),v.end(),Kriterij1))->Ispisi();
    cout << endl;
    bool Identicni=false;
    for(int i(0); i < v.size(); i++) {
        for(int j(i+1); j < v.size(); j++) {
            if(DaLiSuIdenticni(*v[i],*v[j])) {
                if(Identicni == false)
                    cout << "Parovi identicnih trouglova:" << endl;
                v[i]->Ispisi();
                cout << " i ";
                v[j]->Ispisi();
                cout << endl;
                Identicni=true;
            }
        }
    }
    if(Identicni==false) cout<<"Nema identicnih trouglova!"<<endl;
    bool Podudarni = false;
    for(int i(0); i < v.size(); i++) {
        for(int j(i+1); j < v.size(); j++) {
            if(DaLiSuPodudarni(*v[i],*v[j])) {
                if(Podudarni == false)
                    cout<<"Parovi podudarnih trouglova: "<<endl;
                v[i]->Ispisi();
                cout << " i ";
                v[j]->Ispisi();
                cout << endl;
                Podudarni=true;
            }
        }
    }
    if(Podudarni==false) cout<<"Nema podudarnih trouglova!"<<endl;
    bool Slicni = false;
    for(int i(0); i < v.size(); i++) {
        for(int j(i+1); j < v.size(); j++) {
            if(DaLiSuSlicni(*v[i],*v[j])) {
                if(Slicni == false)
                    cout<<"Parovi slicnih trouglova:"<<endl;
                v[i]->Ispisi();
                cout << " i ";
                v[j]->Ispisi();
                cout << endl;
                Slicni=true;
            }
        }
    }
    if(Slicni==false) cout<<"Nema slicnih trouglova!"<<endl;

    return 0;
}
