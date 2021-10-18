#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
typedef std::pair<double, double> Tacka;
double Formula(Tacka A, Tacka B, Tacka C){
    double rezultat = A.first * (B.second - C.second) - B.first * (C.second - A.second) + C.first * (A.second - B.second);
    return rezultat;}
double M(Tacka t1, Tacka t2){
    return (t2.second - t1.second)/(t2.first - t1.first);}
double ugao(double m1, double m2){
    double alfa( atan(abs((m2-m1)/(1+m1*m2))));
    if(alfa==0) alfa = 90;
    alfa *= 4*atan(1)/180;
    return alfa;}
double Duzina(Tacka t1, Tacka t2){
    return sqrt((t1.first - t1.second)*(t1.first - t2.second)+(t2.first-t2.second)*(t2.first-t2.second));}
class Trougao{
    Tacka A, B, C;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Formula(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); A=t1; B=t2; C=t3;}
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Formula(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); A=t1; B=t2; C=t3;}
    void Postavi(int indeks, const Tacka &t){ if(indeks == 1) A=t; if( indeks == 2) B=t; if(indeks == 3) C=t; else throw std::range_error("Nekorektan indeks");}
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Formula(t1, t2, t2)>0) return 1; if(Formula(t1, t2, t3)<0) return -1; if(Formula(t1, t2, t3)==0) return 0;}
    Tacka DajTjeme(int indeks) const { if(indeks == 1) return A; else if(indeks == 2) return B; else if(indeks ==3) return C; else throw std::range_error("Nekorektne pozicije tjemena");}
    double DajUgao(int indeks) const {double m1(M(A, B)), m2(M(C, B)), m3(M(A, C));
    if(indeks == 1) return ugao(m1, m3);
    else if(indeks == 2) return ugao(m1, m2);
    else if(indeks == 3) return ugao(m2, m3);
        else throw std::range_error("Nekorektan indeks");}
    Tacka DajCentar(){Tacka t1(std::make_pair((A.first+B.first+C.first)/3, (A.second+B.second+C.second)/3)); return t1;}
    double DajObim() { return Duzina(A, B)+Duzina(B, C)+ Duzina(C, A);}
    double DajPovrsinu() { return abs(Formula(A, B, C));}
    bool DaLiJePozitivnoOrijentiran() { if (Orijentacija(A, B, C) == 1) return true; else return false;}
    bool DaLiJeUnutra(Tacka D) {double alfa=((B.second-C.second)*(D.first-C.first)+(C.first-B.first)*(D.second-C.second))/((B.second-C.second)*(A.first-C.first)+(C.first-B.first)*(A.second-C.second)); 
    double beta=((C.second - A.second)*(D.first - C.first) + (A.first - C.first)*(D.second - C.second))/((B.second - C.second)*(A.first - C.first) + (C.first - B.first)*(A.second - C.second));
    double gama=1.0f - alfa - beta;
        if(alfa>0 && beta>0 && gama>0) return true; else return false;}
    
    void Ispisi() const {std::cout<<"\n(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";}
    void Transliraj(double delta_x, double delta_y){A.first+=delta_x; B.first+=delta_x; C.first+=delta_x; A.second+=delta_y; B.second+=delta_y; C.second+=delta_y;}
    
    void Rotiraj(const Tacka &t, double ugao){
    A.first=(t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao));
    B.first=(t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao));
    C.first=(t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao));
    A.second=(t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao));
    B.second=(t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao));
    C.second=(t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao));
    }
    void Rotiraj(double ugao){
        Tacka t=DajCentar();
     A.first=(t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao));
    B.first=(t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao));
    C.first=(t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao));
    A.second=(t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao));
    B.second=(t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao));
    C.second=(t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double k){ 
    if(k==0)throw std::domain_error("Nekorektan faktor skaliranja");
        if(k<0) Rotiraj(180);
        A.first=t.first+k*(A.first-t.first); 
        A.second=t.second+k*(A.second-t.second);
        B.first=t.first+k*(B.first-t.first); 
        B.second=t.second+k*(B.second-t.second);
        C.first=t.first+k*(C.first-t.first); 
        C.second=t.second+k*(C.second-t.second);}
    void Skaliraj(double k){
        Tacka t=DajCentar();
        if(k==0)throw std::domain_error("Nekorektan faktor skaliranja");
        if(k<0) Rotiraj(180);
        A.first=t.first+k*(A.first-t.first); 
        A.second=t.second+(A.second-t.second)*k;
        B.first=t.first+k*(B.first-t.first); 
        B.second=t.second+(B.second-t.second)*k;
        C.first=t.first+k*(C.first-t.first); 
        C.second=t.second+(C.second-t.second)*k;}
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){ 
            if(Orijentacija(t1.A, t1.B, t1.C)==Orijentacija(t2.A, t2.B, t2.C) && Duzina(t1.A, t1.B)==Duzina(t2.A,t2.B) && Duzina(t1.B, t1.C)==Duzina(t2.B,t2.C) && Duzina(t1.C, t1.A)==Duzina(t2.C,t2.A)) return true; else return false;}
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        if(Duzina(t1.A, t1.B)==Duzina(t2.A,t2.B) && Duzina(t1.B, t1.C)==Duzina(t2.B,t2.C) && Duzina(t1.C, t1.A)==Duzina(t2.C,t2.A)) return true; else return false;}
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    if(Duzina(t1.A, t1.B)/Duzina(t2.A,t2.B) == Duzina(t1.B, t1.C)/Duzina(t2.B,t2.C) && Duzina(t1.B, t1.C)/Duzina(t2.B,t2.C)==Duzina(t1.A, t1.C)/Duzina(t2.A, t2.C)) return true; else return false;}
    };  
int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> T(n);
    for( int i = 0; i < n; i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
       double x1, x2, x3, y1, y2, y3;
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka t1=std::make_pair(x1, y1), t2=std::make_pair(x2, y2), t3=std::make_pair(x3, y3);
        try{
            std::shared_ptr<Trougao> t(new Trougao(t1, t2, t3));
            T[i]=t;
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos.";
            i--;
          
        }
    }
    
    std::cout<<"Unesite vektor translacije: ";
    double x, y;
    std::cin>>x>>y;
    std::transform(T.begin(), T.end(), T.begin(), [x, y](std::shared_ptr<Trougao> p){(*p.get()).Transliraj(x, y); return p; });
    
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::transform(T.begin(), T.end(), T.begin(), [ugao](std::shared_ptr<Trougao>p){(*p.get()).Rotiraj(ugao); return p; });
    std::cout<<"Unesite faktor skaliranja: ";
    double k;
    std::cin>>k;
        try{
       std::transform(T.begin(), T.end(), T.begin(), [k](std::shared_ptr<Trougao> p){(*p.get()).Skaliraj(k); return p; });
        }
        catch(std::range_error e){
            std::cout<<e.what();
        }
    
    std::sort(T.begin(), T.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){ return (*t1.get()).DajPovrsinu()>(*t2.get()).DajPovrsinu();});
    
    std::cout<<"Trouglovi nakon obavljenih transformacija: ";
   std::for_each(T.begin(), T.end(),  [](std::shared_ptr<Trougao> p){(*p.get()).Ispisi(); });
    
    std::cout<<"\nTrougao s najmanjim obimom: ";
    auto t=std::min_element(T.begin(), T.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){ if(t1->DajObim()<t2->DajObim()) return t1; else return t2;});
    for( int i = 0; i < T.size(); i++){
        if(*t==T[i]){ T[i]->Ispisi(); break;}
    }
	return 0;
}