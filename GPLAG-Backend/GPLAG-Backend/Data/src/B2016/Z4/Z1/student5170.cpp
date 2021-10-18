/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

typedef  std::pair<double, double> Tacka;
const double PI=4*atan(1);

class Trougao
{
    Tacka tac1;
    Tacka tac2;
    Tacka tac3;
public :
    Trougao (const Tacka &t1, const Tacka&t2, const Tacka &t3) {
        if (Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        tac1=t1;
        tac2=t2;
        tac3=t3;
    }
    void Postavi (const Tacka &t1, const Tacka&t2, const Tacka &t3) {
        if (Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        tac1=t1;
        tac2=t2;
        tac3=t3;
    }
    void Postavi (int indeks, const Tacka &t) {
        if (indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) tac1=t;
        else if(indeks==2) tac2=t;
        else tac3=t;
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int rezultat(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        if (rezultat<0) return-1;
        else if (rezultat>0) return 1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if (indeks <1 || indeks>3) throw std::range_error("Nekorektan  indeks");
        if (indeks==1) return tac1;
        else if (indeks==2) return tac2;
        else return tac3;
    }
    double DajStranicu(int indeks) const {
        if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
        if(indeks==1) return sqrt((tac2.first-tac3.first)*(tac2.first-tac3.first)+(tac2.second-tac3.second)*(tac2.second-tac3.second));
        else if(indeks==2) return sqrt((tac1.first-tac3.first)*(tac1.first-tac3.first)+(tac1.second-tac3.second)*(tac1.second-tac3.second));
        else return sqrt((tac2.first-tac1.first)*(tac2.first-tac1.first)+(tac2.second-tac1.second)*(tac2.second-tac1.second));
    }
    //c2=a2+b2-2abcosc
    double DajUgao(int indeks) const {
        if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
        if (indeks==1)
            return acos((-pow(DajStranicu(1),2)+pow(DajStranicu(2),2)+pow(DajStranicu(3),2))/(2*DajStranicu(2)*DajStranicu(3)));
        else if (indeks == 2)
            return acos((-pow(DajStranicu(2),2)+pow(DajStranicu(1),2)+pow(DajStranicu(3),2))/(2*DajStranicu(1)*DajStranicu(3)));
        else return acos((-pow(DajStranicu(3),2)+pow(DajStranicu(1),2)+pow(DajStranicu(2),2))/(2*DajStranicu(1)*DajStranicu(2)));
    }
    Tacka DajCentar() const {
        return {(DajTjeme(1).first+DajTjeme(2).first+DajTjeme(3).first)/3.,(DajTjeme(1).second+DajTjeme(2).second+DajTjeme(3).second)/3.};
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const {
        return fabs(0.5*(tac1.first*(tac2.second-tac3.second)-tac2.first*(tac1.second-tac3.second)+tac3.first*(tac1.second-tac2.second)));
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tac1, tac2, tac3)<=0) return false;
        else return true;
    }
    bool DaLiJeUnutra (const Tacka &t)  const {
        if (DaLiJePozitivnoOrijentiran() && Orijentacija(tac2, tac3, t)>0 && Orijentacija(tac1,tac2, t)>0 && Orijentacija(tac3,tac1,t)>0) return true;
        else if(DaLiJePozitivnoOrijentiran()) return false;
        else if (!DaLiJePozitivnoOrijentiran() && Orijentacija(tac2, tac3, t)>0 && Orijentacija(tac1,tac2, t)<=0 && Orijentacija(tac3,tac1,t)<=0) return true;
        else return false;
    }
    void Ispisi() const {
        std::cout << "((" << tac1.first << "," << tac1.second << "),(" << tac2.first << "," << tac2.second << "),(" << tac3.first << "," << tac3.second << "))"<< std::endl;
    }
    void Transliraj (double delta_x, double delta_y) {
        tac1.first+=delta_x;
        tac2.first+=delta_x;
        tac3.first+=delta_x;
        tac1.second+=delta_y;
        tac2.second+=delta_y;
        tac3.second+=delta_y;
    }
    void Centriraj (const Tacka &t1) {
        double delta_x=-DajCentar().first+t1.first;
        double delta_y=-DajCentar().second+t1.second;
        Transliraj(delta_x, delta_y);
    }
    void Rotiraj (const Tacka &t, double ugao) {
        tac1.first=(t.first+(tac1.first-t.first)*cos(ugao)-(tac1.second-t.second)*sin(ugao));
        tac1.second=(t.second+(tac1.first-t.first)*sin(ugao)+(tac1.second-t.second)*cos(ugao));
        tac2.first=t.first+(tac2.first-t.first)*cos(ugao)-(tac2.second-t.second)*sin(ugao);
        tac2.second=t.second+(tac2.first-t.first)*sin(ugao)+(tac2.second-t.second)*cos(ugao);
        tac3.first=t.first+(tac3.first-t.first)*cos(ugao)-(tac3.second-t.second)*sin(ugao);
        tac3.second=t.second+(tac3.first-t.first)*sin(ugao)+(tac3.second-t.second)*cos(ugao);
    }
    void Skaliraj (const Tacka &t, double faktor) {
        if (faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
        tac1=Pomocnoskaliranje(tac1,t,faktor);
        tac2=Pomocnoskaliranje(tac2,t,faktor);
        tac3=Pomocnoskaliranje(tac3,t,faktor);
    }
    Tacka Pomocnoskaliranje (const Tacka &t1, const Tacka &t2, double faktor) {
        return {t2.first+faktor*(t1.first-t2.first), t2.second+faktor*(t1.second-t2.second)};
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if (t1.tac1!=t2.tac1 && t1.tac1!=t2.tac2 && t1.tac1!=t2.tac3) return false;
    else if(t1.tac1==t2.tac1 || t1.tac1==t2.tac2 || t1.tac1==t2.tac3) {
        if((t1.tac2==t2.tac1 || t1.tac2==t2.tac2 || t1.tac2==t2.tac3)&&(t1.tac3==t2.tac1 || t1.tac3==t2.tac2 || t1.tac3==t2.tac3)) return true;
    }
    else return false;
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
    return (t1.DajObim()==t2.DajObim() && t1.DajPovrsinu()==t2.DajPovrsinu());
}

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
    if(t1.DajUgao(1)==t2.DajUgao(1) && t1.DajUgao(1)==t2.DajUgao(2) && t1.DajUgao(1)!=t2.DajUgao(3)) return false;
    else if(t1.DajUgao(1)==t2.DajUgao(1) || t1.DajUgao(1)==t2.DajUgao(2) || t1.DajUgao(1)==t2.DajUgao(3)) {
        if((t1.DajUgao(2)==t2.DajUgao(1) || t1.DajUgao(2)==t2.DajUgao(2) || t1.DajUgao(2)==t2.DajUgao(3)) && (t1.DajUgao(3)==t2.DajUgao(1) || t1.DajUgao(3)==t2.DajUgao(2)|| t1.DajUgao(3)==t2.DajUgao(3))) return true;
    }
    else return false;
}

int main ()
{
    Trougao a {{0,0},{3,0},{0,4}};
    std::cout << "Orijentacija: " << std::endl;
    std::cout << a.Orijentacija(a.DajTjeme(1), a.DajTjeme(2), a.DajTjeme(3)) << std::endl;
    std::cout << "Tjeme 2: " << std::endl;
    std::cout << a.DajTjeme(2).first << "," << a.DajTjeme(2).second << std::endl;
    std::cout << "Duzina stranica su: " << std::endl;
    std::cout << a.DajStranicu(1) << std::endl;
    std::cout << a.DajStranicu(2) << std::endl;
    std::cout << a.DajStranicu(3) << std::endl;
    std::cout << "Ugao alfa: " << std::endl;
    std::cout << a.DajUgao(1) << std::endl;
    std::cout << "Centar trougla je u tacki: " << std::endl;
    std::cout << a.DajCentar().first << "," << a.DajCentar().second << std::endl;
    std::cout << "Obim trougla je: " << std::endl;
    std::cout << a.DajObim() << std::endl;
    std::cout << "Povrsina trougla je: " << std::endl;
    std::cout << a.DajPovrsinu() << std::endl;
    std::cout << "Da li je trougao orijentisan pozitivno?" << std::endl;
    std::cout << std::boolalpha <<a.DaLiJePozitivnoOrijentiran() << std::endl;
    std::cout << "Da li je tacka (neka) unutra?" << std::endl;
    std::cout << std::boolalpha << a.DaLiJeUnutra({2,1}) << std::endl;
    std::cout << std::boolalpha << a.Orijentacija({3,0}, {0,4}, {4,1}) << std::endl;
    a.Ispisi();
    a.Transliraj(1,2);
    a.Ispisi();
    a.Transliraj(-1,-2);
    a.Centriraj({0,0});
    a.Ispisi();
    std::cout << a.DajCentar().first << "," << a.DajCentar().second << std::endl;
    a.Rotiraj({1,1}, 90);
    a.Ispisi();
    Trougao b{{1,1},{2,3},{3,3}};
    Trougao c{{1,1},{3,3},{2,3}};
    std::cout << std::boolalpha << DaLiSuPodudarni(a,b) << std::endl;
    std::cout << std::boolalpha << DaLiSuPodudarni(b,c) << std::endl;
    return 0;
}