#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <list>
#include <deque>

const double PI=4*(atan(1));

typedef std::pair<double,double>Tacka;




class Trougao {
std::vector<Tacka>T(3);
public:
Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    else {
            T[0]=t1; 
            T[1]=t2;
            T[2]=t3;
        }
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        else {
            T[0]=t1;
            T[1]=t2;
            T[2]=t3;
        }
    }
    void Postavi(int indeks,const Tacka &t) {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        else {
            if(indeks==1) T[0]=t;
            if(indeks==2) T[1]=t;
            if(indeks==3) T[2]=t;
            if(Orijentacija(T[0],T[1],T[2])==0) throw std::domain_error("Nekorektan pozicije tjemena");
        }
    }
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
        if ( (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))==0 ) return 0;
        else if ( (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0 ) return 1;
        else return -1;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        else {
            if(indeks==1) return T[0];
            if(indeks==2) return T[1];
            if(indeks==3) return T[2];
        }
    }
    double DajStranicu(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::domain_error("Nekorektan interval");
        double duzina_stranice(0);
        if(indeks==1) {
            duzina_stranice=std::sqrt((T[1].first-T[2].first)*(T[1].first-T[2].first)+(T[1].second-T[2].second)*(T[1].second-T[2].second));
            return duzina_stranice;
        }
        if(indeks==2) {
            duzina_stranice=std::sqrt((T[0].first-T[2].first)*(T[0].first-T[2].first)+(T[0].second-T[2].second)*(T[0].second-T[2].second));
            return duzina_stranice;
        }
        if(indeks==3) {
            duzina_stranice=std::sqrt((T[0].first-T[1].first)*(T[0].first-T[1].first)+(T[0].second-T[1].second)*(T[0].second-T[1].second));
            return duzina_stranice;
        }
    }
    double DajUgao(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::domain_error("Nekorektan interval");
        double stranica_1=std::sqrt((T[1].first-T[2].first)*(T[1].first-T[2].first)+(T[1].second-T[2].second)*(T[1].second-T[2].second));
        double stranica_2=std::sqrt((T[0].first-T[2].first)*(T[0].first-T[2].first)+(T[0].second-T[2].second)*(T[0].second-T[2].second));
        double stranica_3=std::sqrt((T[0].first-T[1].first)*(T[0].first-T[1].first)+(T[0].second-T[1].second)*(T[0].second-T[1].second));
        double ugao;
        if(indeks==1) {
            ugao=acos((stranica_2*stranica_2+stranica_3*stranica_3-stranica_1*stranica_1)/(2*stranica_2*stranica_3));
            ugao=ugao*(PI/180)
        }
        else if(ugao==2) {
            ugao=acos((stranica_1*stranica_1+stranica_3*stranica_3-stranica_2*stranica_2)/(2*stranica_1*stranica_3));
            ugao=ugao*(PI/180);
        }
        else if(ugao==3) {
           ugao=acos((stranica_1*stranica_1+stranica_2*stranica_2-stranica_2*stranica_2)/(2*stranica_1*stranica_2));
           ugao=ugao*(PI/180);
        }
        return ugao;
    }
    Tacka DajCentar() const {
     Tacka centar_trougla;
     double prva_koordinata=(T[0].first+T[1].first+T[2].first)/3;
     double druga_koordinata=(T[0].second+T[1].second+T[2].second)/3;
     centar_trougla=std::make_pair(prva_koordinata,druga_koordinata);
     return centar_trougla;
    }
    double DajObim() const {
        double obim(0);
        obim+=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
        return obim;
    } 
    double DajPovrsinu() const {
        double povrsina=std::fabs(T[0].first*(T[1].second-T[2].second)-T[1].first*(T[0].second-T[2].second)+T[2].first*(T[0].second-T[1].second))/2;
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(T[0],T[1],T[2])>0) return true;
        else {
            return false;
        }
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        int x=(T[2].second-T[0].second)*(T[1].first-T[0].first)-(T[1].second-T[0].second)*(T[2].first-T[0].first);
        int y=(t.second-T[0].second)*(T[1].first-T[0].first)-(T[1].second-T[0].second)*(t.first-T[0].first);
        return (x*y>0);
    }
    void Ispisi() const {
        std::cout<<"( "<<T[0]<<", "<<T[1]<<", "<<T[2]<<" )"<<std::endl;
    }
    void Transliraj(double delta_x,double delta_y) {
        T[0].first=T[0].first+delta_x; T[0].second=T[0].second+delta_y;
        T[1].first=T[1].first+delta_x; T[1].second=T[1].second+delta_y;
        T[2].first=T[1].first+delta_x; T[2].second=T[2].second+delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka centar=DajCentar();
        double udaljenost_centara=std::sqrt((t.first-centar.first)*(t.first-centar.first)+(t.second-centar.second)*(t.second-centar.second));
        T[0].first+=udaljenost_centara; T[0].second+=udaljenost_centara;
        T[1].first+=udaljenost_centara; T[1].second+=udaljenost_centara;
        T[2].first+=udaljenost_centara; T[2].secon=udaljenost_centara;
    }
    void Rotiraj(const Tacka &t,double ugao) {
        T[0].first=(t.first+(T[0].first-t.first)*std::cos(ugao)-(T[0].second-t.second)*std::sin(ugao));
        T[0].second=(t.second+(T[0].first-t.first)*std::sin(ugao)-(T[0].second-t.second)*std::cos(ugao));
        T[1].first=(t.first+(T[0].first-t.first)*std::cos(ugao)-(T[0].second-t.second)*std::sin(ugao));
        T[1].second=(t.second+(T[0].first-t.first)*std::sin(ugao)-(T[0].second-t.second)*std::cos(ugao));
        T[2].first=(t.first+(T[0].first-t.first)*std::cos(ugao)-(T[0].second-t.second)*std::sin(ugao));
        T[2].second=(t.second+(T[0].first-t.first)*std::sin(ugao)-(T[0].second-t.second)*std::cos(ugao));
    }
    void Skaliraj(const Tacka &t,double faktor) {
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
        T[0].first=t.first+faktor*(T[0].first-t.first);
        T[0].second=t.second+faktor*(T[0].second-t.first);
        T[1].first=t.first+faktor*(T[1].first-t.first);
        T[1].second=t.second+faktor*(T[1].second-t.first);
        T[2].first=t.first+faktor*(T[2].first-t.first);
        T[2].second=t.second+faktor*(T[2].second-t.first);
    }
    void Rotiraj(double ugao) {
        Tacka centar=DajCentar();
        T[0].first=(centar.first+(T[0].first-t.first)*std::cos(ugao)-(T[0].second-centar.second)*std::sin(ugao));
        T[0].second=(centar.second+(T[0].first-t.first)*std::sin(ugao)-(T[0].second-centar.second)*std::cos(ugao));
        T[1].first=(centar.first+(T[0].first-t.first)*std::cos(ugao)-(T[0].second-centar.second)*std::sin(ugao));
        T[1].second=(centar.second+(T[0].first-t.first)*std::sin(ugao)-(T[0].second-centar.second)*std::cos(ugao));
        T[2].first=(centar.first+(T[0].first-t.first)*std::cos(ugao)-(T[0].second-centar.second)*std::sin(ugao));
        T[2].second=(centar.second+(T[0].first-t.first)*std::sin(ugao)-(T[0].second-centar.second)*std::cos(ugao));
    }
    void Skaliraj(double faktor) {
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka centar=DajCentar();
        T[0].first=centar.first+faktor*(T[0].first-centar.first);
        T[0].second=centar.second+faktor*(T[0].second-centar.first);
        T[1].first=centar.first+faktor*(T[1].first-centar.first);
        T[1].second=centar.second+faktor*(T[1].second-centar.first);
        T[2].first=centar.first+faktor*(T[2].first-centar.first);
        T[2].second=t.second+faktor*(T[2].second-t.first);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};






int main ()  {
    return 0;
}



































































int main () {
    
	return 0;
}