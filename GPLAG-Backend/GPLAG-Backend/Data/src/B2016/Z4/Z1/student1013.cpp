/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>

const double eps=0.0000000001;
const double PI=4*atan(1);
typedef std::pair<double, double> Tacka;

double udaljenost (Tacka prva, Tacka druga) {
    return sqrt(pow(prva.first-druga.first,2) + pow(prva.second-druga.second,2));
}

int kolinearne (Tacka prva, Tacka druga, Tacka treca) {
    int k = prva.first*(druga.second-treca.second) - prva.second*(druga.first-treca.first) + druga.first*treca.second - druga.second*treca.first;
    if(k==0) return 0;
    else if(k>0) return 1;
    else return -1;
}

int Sa_iste_strane_prave(Tacka prva,Tacka druga,Tacka treca,Tacka cetvrta) {
    int hehe=(treca.second-prva.second)*(druga.first-prva.first)-(druga.second-prva.second)*(treca.first-prva.first);
    int haha=(cetvrta.second-prva.second)*(druga.first-prva.first) - (druga.second-prva.second)*(cetvrta.first-prva.first);
    return(haha*hehe>0);
}

class Trougao {
    Tacka tjeme1;
    Tacka tjeme2;
    Tacka tjeme3;
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(kolinearne(t1,t2,t3)==true) throw std::domain_error("Nekorektne pozicije tjemena");
        tjeme1=t1;
        tjeme2=t2;
        tjeme3=t3;
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        tjeme1=t1;
        tjeme2=t2;
        tjeme3=t3;
    }
    void Postavi (int indeks, const Tacka &t) {
        if(indeks!=1 and indeks!=2 and indeks!=3) throw std::range_error ("Nekorektan indeks");
        if(indeks==1) tjeme1=t;
        else if (indeks==2) tjeme2=t;
        else tjeme3=t;
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return kolinearne(t1,t2,t3);
    }
    Tacka DajTjeme (int indeks) const {
        if(indeks==1) return tjeme1;
        else if(indeks==2) return tjeme2;
        else if(indeks==3) return tjeme3;
        else throw std::range_error ("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const {
        if(indeks==1) return sqrt( pow(tjeme2.first-tjeme3.first,2) + pow(tjeme2.second-tjeme3.second,2) );
        else if(indeks==2) return sqrt( pow(tjeme1.first-tjeme3.first,2) + pow(tjeme1.second-tjeme3.second,2));
        else return sqrt(pow(tjeme1.first-tjeme2.first,2) + pow(tjeme1.second-tjeme2.second,2));
    }
    double DajUgao (int indeks) const {
        if(indeks!=1 and indeks!=2 and indeks!=3) throw std::range_error ("Nekorektan indeks");
        double a=udaljenost(tjeme2,tjeme3);
        double b=udaljenost(tjeme1,tjeme3);
        double c=udaljenost(tjeme1,tjeme2);
        if(indeks==1) return acos(PI*(b*b+c*c-a*a)/((2*b*c)*180));
        else if(indeks==2) return acos(PI*(a*a+c*c-b*b)/((2*a*c)*180)) ;
        else return acos(PI*(b*b+a*a-c*c)/((2*b*a)*180));
    }
    Tacka DajCentar() const {
        Tacka centar;
        centar.first=(tjeme1.first+tjeme2.first+tjeme3.first)/3;
        centar.second=(tjeme1.second + tjeme2.second + tjeme3.second)/3;
        return centar;
    }
    double DajObim() const {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const {
        return ( tjeme1.first*(tjeme2.second-tjeme3.second) - tjeme1.second*(tjeme2.first-tjeme3.first) + tjeme2.first*tjeme3.second - tjeme2.second*tjeme3.first)/2;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(kolinearne(tjeme1,tjeme2,tjeme3)<1) return false;
        else return true;
    }
    bool DaLiJeUnutra (const Tacka &t) const {
        if(Sa_iste_strane_prave(tjeme1,tjeme2,tjeme3,t) and Sa_iste_strane_prave(tjeme2,tjeme3,tjeme1,t) and Sa_iste_strane_prave(tjeme1,tjeme3,tjeme2,t)) return true;
        else return false;
    }
    void Ispisi() const {
        std::cout << "(" <<tjeme1.first << "," << tjeme1.second << ")" << " , " << "(" <<tjeme2.first << "," << tjeme2.second << ")" << " , " << "(" <<tjeme3.first << "," << tjeme3.second << ")" << " , "<< std::endl;
    }
    void Transliraj(double delta_x, double delta_y)  {
        tjeme1.first+=delta_x;
        tjeme1.second+=delta_y;
        tjeme2.first+=delta_x;
        tjeme2.second+=delta_y;
        tjeme3.first+=delta_x;
        tjeme3.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka k=DajCentar();
        double delta_x=k.first-t.first;
        double delta_y=k.second-t.second;
        Transliraj(delta_x,delta_y);
    }
    void Rotiraj (const Tacka &t,double ugao) {
        tjeme1.first=t.first + (tjeme1.first-t.first)*cos(ugao) - (tjeme1.second-t.second)*sin(ugao);
        tjeme1.second=t.second+(tjeme1.first-t.first)*sin(ugao) + (tjeme1.second-t.second)*cos(ugao);
        tjeme2.first=t.first + (tjeme2.first-t.first)*cos(ugao) - (tjeme2.second-t.second)*sin(ugao);
        tjeme2.second=t.second+(tjeme2.first-t.first)*sin(ugao) + (tjeme2.second-t.second)*cos(ugao);
        tjeme3.first=t.first + (tjeme3.first-t.first)*cos(ugao) - (tjeme3.second-t.second)*sin(ugao);
        tjeme3.second=t.second+(tjeme3.first-t.first)*sin(ugao) + (tjeme3.second-t.second)*cos(ugao);
    }
    void Skaliraj (const Tacka &t, double faktor) {
        if(fabs(faktor-0)<eps) throw std::domain_error ("Nekorektan faktor skaliranja");
        tjeme1.first=t.first + faktor*(tjeme1.first-t.first);
        tjeme1.second=t.second+faktor*(tjeme1.second-t.second);
        tjeme2.first=t.first + faktor*(tjeme2.first-t.first);
        tjeme2.second=t.second+faktor*(tjeme2.second-t.second);
        tjeme3.first=t.first + faktor*(tjeme3.first-t.first);
        tjeme3.second=t.second+faktor*(tjeme3.second-t.second);
    }
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
        if( (t1.tjeme1==t2.tjeme1) or (t1.tjeme1==t2.tjeme2) or (t1.tjeme1==t2.tjeme3))
            if((t1.tjeme2==t2.tjeme1) or (t1.tjeme2==t2.tjeme2) or (t1.tjeme1==t2.tjeme3))
                if( (t1.tjeme3==t2.tjeme1) or (t1.tjeme3==t2.tjeme2) or (t1.tjeme3==t2.tjeme3))
                    return true;
        return false;
    }
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
        if(t1.DajStranicu(1)==t2.DajStranicu(1))
            if(t1.DajStranicu(2)==t2.DajStranicu(2))
                if(t1.DajStranicu(3)==t2.DajStranicu(3)) return true;
        if(t1.DajStranicu(1)==t2.DajStranicu(2))
            if(t1.DajStranicu(2)==t2.DajStranicu(3))
                if(t1.DajStranicu(3)==t2.DajStranicu(1)) return true;
        if(t1.DajStranicu(1)==t2.DajStranicu(3))
            if(t1.DajStranicu(2)==t2.DajStranicu(1))
                if(t1.DajStranicu(3)==t2.DajStranicu(2)) return true;
        return false;
    }
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
        double a1,a2,b1,b2,c1,c2;
        if(t1.DajStranicu(1)>t1.DajStranicu(2) and t1.DajStranicu(1)>t1.DajStranicu(3)) {
            a1=t1.DajStranicu(1);
            if(t1.DajStranicu(2)>t1.DajStranicu(3)) {
                b1=t1.DajStranicu(2);
                c1=t1.DajStranicu(3);
            }
            else {
                b1=t1.DajStranicu(3);
                c1=t1.DajStranicu(2);
            }
        }
        else if(t1.DajStranicu(2)>t1.DajStranicu(1) and t1.DajStranicu(2)>t1.DajStranicu(3)) {
            a1=t1.DajStranicu(2);
            if(t1.DajStranicu(1)>t1.DajStranicu(3)) {
                b1=t1.DajStranicu(1);
                c1=t1.DajStranicu(3);
            }
            else {
                b1=t1.DajStranicu(3);
                c1=t1.DajStranicu(1);
            }
        }
        else {
            a1=t1.DajStranicu(3);
            if(t1.DajStranicu(1)>t1.DajStranicu(2)) {
                b1=t1.DajStranicu(1);
                c1=t1.DajStranicu(2);
            }
            else {
                b1=t1.DajStranicu(2);
                c1=t1.DajStranicu(1);
            }
        }
        if(t2.DajStranicu(1)>t2.DajStranicu(2) and t2.DajStranicu(1)>t2.DajStranicu(3)) {
            a2=t2.DajStranicu(1);
            if(t2.DajStranicu(2)>t2.DajStranicu(3)) {
                b2=t2.DajStranicu(2);
                c2=t2.DajStranicu(3);
            }
            else {
                b2=t2.DajStranicu(3);
                c2=t2.DajStranicu(2);
            }
        }
        else if(t2.DajStranicu(2)>t2.DajStranicu(1) and t2.DajStranicu(2)>t2.DajStranicu(3)) {
            a2=t2.DajStranicu(2);
            if(t2.DajStranicu(1)>t2.DajStranicu(3)) {
                b2=t2.DajStranicu(1);
                c2=t2.DajStranicu(3);
            }
            else {
                b2=t2.DajStranicu(3);
                c2=t2.DajStranicu(1);
            }
        }
        else {
            a2=t2.DajStranicu(3);
            if(t2.DajStranicu(1)>t2.DajStranicu(2)) {
                b2=t2.DajStranicu(1);
                c2=t2.DajStranicu(2);
            }
            else {
                b2=t2.DajStranicu(2);
                c2=t2.DajStranicu(1);
            }
        }
        if(a1/a2==(int)(a1/a2) and b1/b2==(int)(b1/b2) and c1/c2==(int)(c1/c2)) return true;
        return false;
    }
};

int main ()
{
	return 0;
}