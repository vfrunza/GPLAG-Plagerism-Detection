/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>

typedef std::pair<double,double> Tacka;

double Povrsina (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
}

double DuzinaStranice (const Tacka &t1, const Tacka &t2){
    return (std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t2.second)*(t2.second-t1.second)));
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
    int brojac(0);
    for (int i=0,i<3;i++){
        for (int j=0;j<3;j++){
            if (tacke[i]==tacke[j]){
                brojac++;
                break;
            }
        }
    }
    if (brojac==3) return true;
    return false;
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2){
    int a[3],b[3];
    a[0]=DuzinaStranice(tacke[1],tacke[2]);
    a[1]=DuzinaStranice(tacke[0],tacke[2]);
    a[2]=DuzinaStranice(tacke[0],tacke[1]);
    b[0]=DuzinaStranice(tacke[1],tacke[2]);
    b[1]=DuzinaStranice(tacke[0],tacke[2]);
    b[2]=DuzinaStranice(tacke[0],tacke[1]);
    int brojac(0);
    for (int i=0,i<3;i++){
        for (int j=0;j<3;j++){
            if (tacke[i]==tacke[j]){
                brojac++;
                break;
            }
        }
    }
    if (brojac==3) return true;
    return false;
}
    
bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2){
    int a1,b1,c1,a2,b2,c2;
    a1=DuzinaStranice(tacke[1],tacke[2]);
    b1=DuzinaStranice(tacke[0],tacke[2]);
    c1=DuzinaStranice(tacke[0],tacke[1]);
    a2=DuzinaStranice(tacke[1],tacke[2]);
    b2=DuzinaStranice(tacke[0],tacke[2]);
    c2=DuzinaStranice(tacke[0],tacke[1]);
    int s1(a1/a2),s2(b1/b2),s3(c1/c2);
    if (s1==s2 && s2==s3) return true;
    return false;
}

class Trougao {
    Tacka tacke[3];
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Povrsina(t1,t2,t3)==0)
            throw std::domain_error ("Nekorektne pozicije tjemena");
        tacke[0]=t1; tacke[1]=t2; tacke[2]=t3; 
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (int indeks, const Tacka &t);
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme (int indeks) const { return tacke[indeks-1]; } ;
    double DajStranicu (int indeks) const;
    double DajUgao (int indeks ) const;
    Tacka DajCentar () const ;
    double DajObim () const;
    double DajPovrsinu () const { return Povrsina(tacke[0],tacke[1],tacke[2]); };
    bool DaLiJePozitivnoOrijentiran () const { return Povrsina(tacke[0],tacke[1],tacke[2])>0; };
    bool DaLiJeUnutra (const Tacka &t);
    void Ispisi () const;
    void Transliraj (double delta_x, double delta_y);
    void Centriraj (const Tacka &t);
    void Rotiraj (const Tacka &t, double ugao);
    void Skaliraj (const Tacka &t, double faktor);
    void Rotiraj (double ugao);
    void Skaliraj (double faktor);
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
    friend double Povrsina (const Tacka &t1, const Tacka &t2, const Tacka &t3 );
    friend double DuzinaStranice (const Tacka &t1, const Tacka &t2);
};

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    return 0;
}

void Trougao::Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if (Povrsina(t1,t2,t3)==0)
        throw std::domain_error ("Nekorektne pozicije tjemena");
        tacke[0]=t1; tacke[1]=t2; tacke[2]=t3;
}

void Trougao::Postavi (int indeks, const Tacka &t){
    if (indeks<0 || indeks>3)
        throw std::range_error ("Nekorektan indeks");
    tacke[indeks-1]=t;
    if (Povrsina(tacke[0],tacke[1],tacke[2])==0)
        throw std::domain_error ("Nekorektne pozicije tjemena");
}

int Trougao::Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if (Povrsina(t1,t2,t3)==0) return 0;
    if (Povrsina(t1,t2,t3)>0) return 1;
    if (Povrsina(t1,t2,t3)<0) return -1;
}

double Trougao::DajUgao (int indeks) const {
    double a,b,c;
    a=DuzinaStranice(tacke[1],tacke[2]);
    b=DuzinaStranice(tacke[0],tacke[2]);
    c=DuzinaStranice(tacke[0],tacke[1]);
    if (indeks==1) return std::acos(((b*b+c*c-a*a)/(2*b*c)));
    if (indeks==2) return std::acos(((a*a+c*c-b*b)/(2*a*c)));
    if (indeks==3) return std::acos(((a*a+b*b-c*c)/(2*a*b)));
}

Tacka Trougao::DajCentar() const {
    Tacka t;
    t.first=(tacke[0].first+tacke[1].first+tacke[2].first)/3;
    t.second=(tacke[0].second+tacke[1].second+tacke[2].second)/3;
    return t;
}

double Trougao::DajObim() const {
    double a,b,c;
    a=DuzinaStranice(tacke[1],tacke[2]);
    b=DuzinaStranice(tacke[0],tacke[2]);
    c=DuzinaStranice(tacke[0],tacke[1]);
    return a+b+c;
}

bool Trougao::DaLiJeUnutra (const Tacka &t){
    double p(Povrsina(tacke[0],tacke[1],tacke[2]));
    double p1(Povrsina(t,tacke[1],tacke[2]));
    double p2(Povrsina(tacke[0],t,tacke[2]));
    double p3(Povrsina(tacke[0],tacke[1],t));
    if (p<p1+p2+p3) return true;
    return false;
}

void Trougao::Transliraj (double delta_x, double delta_y){
    tacke[0].first+=delta_x;tacke[0].second+=delta_y;
    tacke[1].first+=delta_x;tacke[1].second+=delta_y;
    tacke[2].first+=delta_x;tacke[2].second+=delta_y;
}

void Trougao::Centriraj (const Tacka &t){
    double xt((tacke[0].first+tacke[1].first+tacke[2].first)/3);
    double yt((tacke[0].second+tacke[1].second+tacke[2].second)/3);
    Tacka te;
    te=std::make_pair(xt,yt);
    double d(DuzinaStranice(te,t));
    Transliraj(d,d);
}
 
void Trougao::Rotiraj (const Tacka &t, double ugao){
    tacke[0].first=t.first+(tacke[0].first-t.first)*std::cos(ugao)-(tacke[0].second-t.second)*std::sin(ugao);
    tacke[0].second=t.second+(tacke[0].first-t.first)*std::sin(ugao)+(tacke[0].second-t.second)*std::cos(ugao);
    tacke[1].first=t.first+(tacke[1].first-t.first)*std::cos(ugao)-(tacke[1].second-t.second)*std::sin(ugao);
    tacke[1].second=t.second+(tacke[1].first-t.first)*std::sin(ugao)+(tacke[1].second-t.second)*std::cos(ugao);
    tacke[2].first=t.first+(tacke[2].first-t.first)*std::cos(ugao)-(tacke[2].second-t.second)*std::sin(ugao);
    tacke[2].second=t.second+(tacke[2].first-t.first)*std::sin(ugao)+(tacke[2].second-t.second)*std::cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if (faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
    tacke[0].first=t.first+faktor*(tacke[0].first-t.first);
    tacke[0].second=t.second+faktor*(tacke[0].second-t.second);
    tacke[1].first=t.first+faktor*(tacke[1].first-t.first);
    tacke[1].second=t.second+faktor*(tacke[1].second-t.second);
    tacke[2].first=t.first+faktor*(tacke[2].first-t.first);
    tacke[2].second=t.second+faktor*(tacke[2].second-t.second);
    
    if (faktor<0){
        Rotiraj(t,180);
    }
}

void Trougao::Rotiraj (double ugao){
    double xt((tacke[0].first+tacke[1].first+tacke[2].first)/3);
    double yt((tacke[0].second+tacke[1].second+tacke[2].second)/3);
    Tacka t;
    t=std::make_pair(xt,yt);
    tacke[0].first=t.first+(tacke[0].first-t.first)*std::cos(ugao)-(tacke[0].second-t.second)*std::sin(ugao);
    tacke[0].second=t.second+(tacke[0].first-t.first)*std::sin(ugao)+(tacke[0].second-t.second)*std::cos(ugao);
    tacke[1].first=t.first+(tacke[1].first-t.first)*std::cos(ugao)-(tacke[1].second-t.second)*std::sin(ugao);
    tacke[1].second=t.second+(tacke[1].first-t.first)*std::sin(ugao)+(tacke[1].second-t.second)*std::cos(ugao);
    tacke[2].first=t.first+(tacke[2].first-t.first)*std::cos(ugao)-(tacke[2].second-t.second)*std::sin(ugao);
    tacke[2].second=t.second+(tacke[2].first-t.first)*std::sin(ugao)+(tacke[2].second-t.second)*std::cos(ugao);
}

void Trougao::Skaliraj(double faktor){
    if (faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
    double xt((tacke[0].first+tacke[1].first+tacke[2].first)/3);
    double yt((tacke[0].second+tacke[1].second+tacke[2].second)/3);
    Tacka t;
    tacke[0].first=t.first+faktor*(tacke[0].first-t.first);
    tacke[0].second=t.second+faktor*(tacke[0].second-t.second);
    tacke[1].first=t.first+faktor*(tacke[1].first-t.first);
    tacke[1].second=t.second+faktor*(tacke[1].second-t.second);
    tacke[2].first=t.first+faktor*(tacke[2].first-t.first);
    tacke[2].second=t.second+faktor*(tacke[2].second-t.second);
    
    if (faktor<0){
        Rotiraj(t,180);
    }
}