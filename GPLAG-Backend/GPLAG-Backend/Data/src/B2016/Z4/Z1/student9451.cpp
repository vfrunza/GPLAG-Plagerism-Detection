/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#define epsilon 0.0000000001
typedef std::pair<double, double> Tacka;

bool IsteTacke(Tacka T1, Tacka T2){
    if(fabs(T1.first-T2.first)<epsilon && fabs(T1.second-T2.second)<epsilon) return true;
    return false;
    
}

class Trougao
{
    Tacka T1, T2, T3;
public:
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int x(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        if(x>0) return 1;
        if(x<0) return -1;

        return 0;
    }
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int s=Orijentacija(t1,t2,t3);
        if(s==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::T1=t1;
        Trougao::T2=t2;
        Trougao::T3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int s=Orijentacija(t1,t2,t3);
        if(s==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::T1=t1;
        Trougao::T2=t2;
        Trougao::T3=t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks <1|| indeks>3) {
            throw std::range_error("Nekorektan indeks");
        }
        if(indeks==1) {
            Trougao::T1=t;
        }
        if(indeks==2) {
            Trougao::T2=t;
        }
        if(indeks==3) {
            Trougao::T3=t;
        }
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks <1|| indeks>3) {
            throw std::range_error("Nekorektan indeks");
        }
        if(indeks==1) {
            return Trougao::T1;
        }
        if(indeks==2) {
            return Trougao::T2;
        }
        return Trougao::T3;

    }
    double DajStranicu(int indeks)const {
        if(indeks <1|| indeks>3) {
            throw std::range_error("Nekorektan indeks");
        }
        if(indeks==1) {
            return sqrt(pow(T3.first-T2.first ,2)+ pow(T3.second-T2.second ,2));
        }
        if(indeks==2) {
            return sqrt(pow(T1.first-T3.first ,2)+ pow(T1.second-T3.second ,2));
        }
        return sqrt(pow(T1.first-T2.first ,2)+ pow(T1.second-T2.second ,2));

    }
    double DajUgao(int indeks)const {
        if(indeks <1|| indeks>3) {
            throw std::range_error("Nekorektan indeks");
        }
        double a=DajStranicu(1);
        double b=DajStranicu(2);
        double c=DajStranicu(3);
        if(indeks == 1) {
            return (acos((b*b+c*c-a*a)/(2*b*c)))*(180/(atan(1)*4));
        }
        if(indeks == 2) {
            return (acos((a*a+c*c-b*b)/(2*a*c)))*(180/(atan(1)*4));
        }
        return (acos((a*a+b*b-c*c)/(2*a*b)))*(180/(atan(1)*4));
    }
    Tacka DajCentar()const {
        return std::make_pair((T1.first+T2.first+T3.first)/3, (T1.second+T2.second+T3.second)/3);
    }

    double DajObim()const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu()const {
        return (0.5*fabs(T1.first*(T2.second-T3.second)+T2.first*(T3.second-T1.second)+T3.first*(T1.second-T2.second)));
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(T1,T2,T3) == 1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t)const{
        if((Orijentacija(T1,T2,T3)==1 && Orijentacija(T1,T2,t)==1 && Orijentacija(T2,T3, t)==1 && Orijentacija(T3,T1,t)==1 )|| (Orijentacija(T1,T2,T3)==-1 && Orijentacija(T1,T2,t)==-1 && Orijentacija(T2,T3, t)==-1 && Orijentacija(T3,T1,t)==-1 ) ) return true;
        return false;
    }
    void Ispisi()const{
        std::cout<<"(("<<T1.first<<","<<T1.second<<"),("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";
    }
    
    void Transliraj(double delta_x, double delta_y){
        T1.first+=delta_x;
        T2.first+=delta_x;
        T3.first+=delta_x;
        
        T1.second+=delta_y;
        T2.second+=delta_y;
        T3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka c=(DajCentar());
        double delta_x(t.first-c.first);
        double delta_y(t.second-c.second);
        
        T1.first+=delta_x;
        T2.first+=delta_x;
        T3.first+=delta_x;
        
        T1.second+=delta_y;
        T2.second+=delta_y;
        T3.second+=delta_y;
    }
    void Rotiraj(const Tacka &t, double ugao){
        T1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
        T1.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
        
        T2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
        T2.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
        
        T3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
        T3.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
    }
    void Rotiraj(double ugao){
        Tacka t(DajCentar());
        T1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
        T1.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
        
        T2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
        T2.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
        
        T3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
        T3.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
    }
    
    void Skaliraj(const Tacka &t, double faktor){
        if(fabs(faktor-0)<epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
        T1.first=t.first+ faktor*(T1.first-t.first);
        T1.second=t.second+ faktor*(T1.second-t.second);
        
        T2.first=t.first+ faktor*(T2.first-t.first);
        T2.second=t.second+ faktor*(T2.second-t.second);
        
        T3.first=t.first+ faktor*(T3.first-t.first);
        T3.second=t.second+ faktor*(T3.second-t.second);
        
    }
    void Skaliraj(double faktor){
        if(fabs(faktor-0)<epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t(DajCentar());
        T1.first=t.first+ faktor*(T1.first-t.first);
        T1.second=t.second+ faktor*(T1.second-t.second);
        
        T2.first=t.first+ faktor*(T2.first-t.first);
        T2.second=t.second+ faktor*(T2.second-t.second);
        
        T3.first=t.first+ faktor*(T3.first-t.first);
        T3.second=t.second+ faktor*(T3.second-t.second);
        
    }
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
    
};
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
        if(((IsteTacke(t1.T1, t2.T1)) && (IsteTacke(t1.T2, t2.T2)) && (IsteTacke(t1.T3, t2.T3))) || ((IsteTacke(t1.T1, t2.T1)) && (IsteTacke(t1.T2, t2.T3)) && (IsteTacke(t1.T3, t2.T2)))) return true;
        
        if(((IsteTacke(t1.T1, t2.T2)) && (IsteTacke(t1.T3, t2.T1)) && (IsteTacke(t1.T2, t2.T3))) || ((IsteTacke(t1.T1, t2.T2)) && (IsteTacke(t1.T3, t2.T3)) && (IsteTacke(t1.T2, t2.T1)))) return true;
        
        if(((IsteTacke(t1.T1, t2.T3)) && (IsteTacke(t1.T3, t2.T1)) && (IsteTacke(t1.T2, t2.T2))) || ((IsteTacke(t1.T1, t2.T3)) && (IsteTacke(t1.T3, t2.T2)) && (IsteTacke(t1.T2, t2.T1)))) return true;
        return false;
    }

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    if((t1.Orijentacija(t1.T1,t1.T2, t1.T3)== t2.Orijentacija(t2.T1, t2.T2, t2.T3)) && (t1.DajPovrsinu()-t2.DajPovrsinu())<epsilon && ((t1.DajObim()-t2.DajObim()))<epsilon) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    if (((t2.DajObim()/t1.DajObim())*(t2.DajObim()/t1.DajObim())-t2.DajPovrsinu()/t1.DajPovrsinu())<epsilon) return true;
    return false;
}
int main ()
{
 /*   try {
        Tacka t1, t2, t3;
        t1=std::make_pair(2, 3);
        t2=std::make_pair(2, 6);
        t3=std::make_pair(4, 3);
        
        Trougao T(t1, t2, t3);
        T.Ispisi();
        std::cout<<T.Orijentacija(T.DajTjeme(1),T.DajTjeme(2), T.DajTjeme(3));
        std::cout<<"\n";
        Tacka t4, t5, t6;
        t4=std::make_pair(1, 5);
        t5=std::make_pair(4, 5);
        t6=std::make_pair(1, 3);
        Trougao T2(t4, t5, t6);
        
        std::cout<<T2.Orijentacija(T2.DajTjeme(1),T2.DajTjeme(2), T2.DajTjeme(3));
        if(DaLiSuPodudarni(T, T2))std::cout<<"jesu majke mi";
        
        //druga minus
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }*/

    return 0;
}