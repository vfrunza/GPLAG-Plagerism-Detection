/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#define eps 0.000001
const double PI (4*atan(1));

typedef std::pair<double,double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    static bool f(Tacka x, Tacka y){
        if(fabs(x.first- y.first)<=eps*(fabs(x.first)+fabs(y.first)) && fabs(x.second- y.second)<=eps*(fabs(x.second)+fabs(y.second)))
            return true;
        return false;
    }
    static bool f(double x, double y){
        if(fabs(x-y)<=eps*(fabs(x)+fabs(y)))
            return true;
        return false;
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        //Ako je povrsina trougla = 0, znaci da te tri tacke leze na jednom pravcu, odnosno one su kolinearne :)
        double PovrsinaTrougla;
        PovrsinaTrougla=(1./2)*(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        if(PovrsinaTrougla==0)  throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        //Ako je povrsina trougla = 0, znaci da te tri tacke leze na jednom pravcu, odnosno one su kolinearne :)
        double PovrsinaTrougla;
        PovrsinaTrougla=(1./2)*(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        if(PovrsinaTrougla==0)  throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(!(indeks>=1 && indeks<=3))   throw std::range_error("Nekorektan indeks");
        else if(indeks==1)  t1=t;
        else if(indeks==2)  t2=t;
        else if(indeks==3)  t3=t;
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double provjera(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        if(provjera>0)  return 1;
        else if(provjera<0) return -1;
        else if(provjera==0)    return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(!(indeks>=1 && indeks<=3))   throw std::range_error("Nekorektan indeks");
        else if(indeks==1)  return t1;
        else if(indeks==2)  return t2;
        else if(indeks==3)  return t3;
    }
    double DajStranicu(int indeks) const{
        if(!(indeks>=1 && indeks<=3))   throw std::range_error("Nekorektan indeks");
        else if(indeks==1)  return sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
        else if(indeks==2)  return sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
        else if(indeks==3)  return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    double DajUgao(int indeks) const{
        if(!(indeks>=1 && indeks<=3))   throw std::range_error("Nekorektan indeks");
        double a, b, c;
        a=sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
        b=sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
        c=sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
        if(indeks==1){
            double A((c*c+b*b-a*a)/(2*c*b));
            return cos(A)*(PI/180);
        }
        else if(indeks==2){
            double B((a*a+c*c-b*b)/(2*a*c));
            return cos(B)*(PI/180);
        }
        else if(indeks==3){
            double C((a*a+b*b-c*c)/(2*a*b));
            return cos(C)*(PI/180);
        }
    }
    Tacka DajCentar() const{
        Tacka t;
        t.first=(t1.first+t2.first+t3.first)/3;
        t.second=(t1.second+t2.second+t3.second)/3;
        return t;
    }
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
        return (1/2)*(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
    }
    bool DaLiJePozitivnoOrijentiran() const{
        double provjera(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        if(provjera>0)  return true;
        else if(provjera<=0) return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        double provjera(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        if(provjera>0){
            if(Orijentacija(t1,t2,t)==1 && Orijentacija(t2,t3,t)==1 && Orijentacija(t3,t1,t)==1)
                return true;
            else    
                return false;
        }
        else if(provjera<0){
            if(Orijentacija(t1,t2,t)==-1 && Orijentacija(t2,t3,t)==-1 && Orijentacija(t3,t1,t)==-1)
                return true;
            else 
                return false;
        }
    }
    void Ispisi() const{
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y){
        t1.first+=delta_x;
        t2.first+=delta_x;
        t3.first+=delta_x;
        t1.second+=delta_y;
        t2.second+=delta_y;
        t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka centar(DajCentar());
        int x(t.first-centar.first), y(t.second-centar.second);
        t1.first+=x;
        t2.first+=x;
        t3.first+=x;
        t1.second+=y;
        t2.second+=y;
        t3.second+=y;
    }
    void Rotiraj(const Tacka &t, double ugao){
        t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
        t1.second=(t1.first-t.first)*sin(ugao)+t.second-(t1.second-t.second)*cos(ugao);
        t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
        t2.second=(t2.first-t.first)*sin(ugao)+t.second-(t2.second-t.second)*cos(ugao);
        t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
        t3.second=(t3.first-t.first)*sin(ugao)+t.second-(t3.second-t.second)*cos(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor==0)   throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first=t.first+faktor*(t1.first-t.first);
        t1.second=t.second+faktor*(t1.second-t.second);
        t2.first=t.first+faktor*(t2.first-t.first);
        t2.second=t.second+faktor*(t2.second-t.second);
        t3.first=t.first+faktor*(t3.first-t.first);
        t3.second=t.second+faktor*(t3.second-t.second);
    }
    void Rotiraj(double ugao){
        Tacka t(DajCentar());
        t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
        t1.second=(t1.first-t.first)*sin(ugao)+t.second-(t1.second-t.second)*cos(ugao);
        t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
        t2.second=(t2.first-t.first)*sin(ugao)+t.second-(t2.second-t.second)*cos(ugao);
        t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
        t3.second=(t3.first-t.first)*sin(ugao)+t.second-(t3.second-t.second)*cos(ugao);
    }
    void Skaliraj(double faktor){
        if(faktor==0)   throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t(DajCentar());
        t1.first=t.first+faktor*(t1.first-t.first);
        t1.second=t.second+faktor*(t1.second-t.second);
        t2.first=t.first+faktor*(t2.first-t.first);
        t2.second=t.second+faktor*(t2.second-t.second);
        t3.first=t.first+faktor*(t3.first-t.first);
        t3.second=t.second+faktor*(t3.second-t.second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
   if(
    (Trougao::f(t1.DajTjeme(1), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(2), t2.DajTjeme(2)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(3))) || 
    (Trougao::f(t1.DajTjeme(1), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(2), t2.DajTjeme(3)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(2))) ||
    (Trougao::f(t1.DajTjeme(2), t2.DajTjeme(2)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(1), t2.DajTjeme(3))) ||
    (Trougao::f(t1.DajTjeme(2), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(1), t2.DajTjeme(2)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(3))) || 
    (Trougao::f(t1.DajTjeme(1), t2.DajTjeme(2)) && Trougao::f(t1.DajTjeme(2), t2.DajTjeme(3)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(1))) ||
    (Trougao::f(t1.DajTjeme(1), t2.DajTjeme(3)) && Trougao::f(t1.DajTjeme(2), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(2))) ||
    (Trougao::f(t1.DajTjeme(2), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(1), t2.DajTjeme(3)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(2))) || 
    (Trougao::f(t1.DajTjeme(2), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(1), t2.DajTjeme(3)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(2))) ||
    (Trougao::f(t1.DajTjeme(2), t2.DajTjeme(3)) && Trougao::f(t1.DajTjeme(3), t2.DajTjeme(1)) && Trougao::f(t1.DajTjeme(1), t2.DajTjeme(2))) )
    return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(!(
    (Trougao::f(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(2), t2.DajStranicu(2)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(3))) || 
    (Trougao::f(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(2), t2.DajStranicu(3)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(2))) ||
    (Trougao::f(t1.DajStranicu(2), t2.DajStranicu(2)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(1), t2.DajStranicu(3))) ||
    (Trougao::f(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(3))) || 
    (Trougao::f(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::f(t1.DajStranicu(2), t2.DajStranicu(3)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(1))) ||
    (Trougao::f(t1.DajStranicu(1), t2.DajStranicu(3)) && Trougao::f(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(2))) ||
    (Trougao::f(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(1), t2.DajStranicu(3)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(2))) || 
    (Trougao::f(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(1), t2.DajStranicu(3)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(2))) ||
    (Trougao::f(t1.DajStranicu(2), t2.DajStranicu(3)) && Trougao::f(t1.DajStranicu(3), t2.DajStranicu(1)) && Trougao::f(t1.DajStranicu(1), t2.DajStranicu(2)))) )
    return false;
    else {
        Trougao pom1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3));
        Tacka c(t2.DajCentar());
        pom1.Centriraj(c);
        pom1.Ispisi();
        double najmanja1(t1.DajStranicu(1)), najmanja2(t2.DajStranicu(1));
        int zapamti1=1, zapamti2=1;
        
        for(int i=1; i<4; i++){
            if(najmanja1<t1.DajStranicu(i)){
                najmanja1=t1.DajStranicu(i);
                zapamti1=i;
            }
            if(najmanja2<t2.DajStranicu(i)){
                najmanja2=t2.DajStranicu(i);
                zapamti2=i;
            }
        }//problem oko fje rotiraj, pogledaj sliku i skiciraj
        int br(0);
        while(Trougao::f(pom1.DajTjeme(zapamti1), t2.DajTjeme(zapamti2)) && br!=361){
            pom1.Rotiraj(1);
            br++;
            pom1.Ispisi();
        }
        if(Trougao::f(pom1.DajTjeme(zapamti1), t2.DajTjeme(zapamti2)))
            return true;
        else   return false;
       
    }
}

//bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    
int main (){   
    try{ 
    int n;
	std::cout<<"Unesite prirodan broj n:";
	std::cin>>n;
	
    }
    catch(std::domain_error i){
        std::cout<<i.what()<<std::endl;
    }
    catch(std::range_error a){
        std::cout << a.what() << std::endl;
    }
    return 0;
}
