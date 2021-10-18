#include <iostream>  
#include <stdexcept> 
#include <cmath>  
#include <algorithm> 
#include <vector> 
#include <memory> 
double epsilon(0.0000000001); 
const double PI(4*std::atan(1));
typedef std::pair<double, double> Tacka; 
class Trougao{
    Tacka a, b, c;  
    static bool Poredi(double x, double y){
        if(fabs(x-y)<epsilon) return true; 
        return false;
    }
    public:  
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ 
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); 
        a=t1;
        b=t2;
        c=t3;
    } 
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); 
        a=t1;
        b=t2;
        c=t3;
    } 
    void Postavi(int indeks, const Tacka &t){
        if(indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) a=t;
        if(indeks==2) b=t;
        if(indeks==3) c=t;
    } 
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double znak(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)); 
        if(znak>0) return 1;
        if(znak<0) return -1;
        if(znak==0) return 0;
    } 
    Tacka DajTjeme(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); 
        if(indeks==1) return a;
        if(indeks==2) return b;
        if(indeks==3) return c;
    } 
    double DajStranicu(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); 
        double a1=std::sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second));
        double b1=std::sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        double c1=std::sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
        if(indeks==1) return a1; 
        if(indeks==2) return b1;  
        if(indeks==3) return c1; 
    } 
    double DajUgao(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); 
        double a1=std::sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second)); 
        double b1=std::sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        double c1=std::sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));  
        double alpha=std::acos((b1*b1+c1*c1-a1*a1)/(2*b1*c1));
        double beta=std::acos((c1*c1+a1*a1-b1*b1)/(2*c1*a1));
        double gamma=std::acos((a1*a1+b1*b1-c1*c1)/(2*a1*b1));
        if(indeks==1) return alpha;
        if(indeks==2) return beta;
        if(indeks==3) return gamma;
    } 
    Tacka DajCentar() const{
        Tacka centar;
        centar.first=(a.first+b.first+c.first)/3;
        centar.second=(a.second+b.second+c.second)/3;
        return centar;
    } 
    double DajObim() const{
        double a1=std::sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second)); 
        double b1=std::sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        double c1=std::sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));  
        double O=a1+b1+c1; 
        return O;
    } 
    double DajPovrsinu()const{
        double P=std::abs((a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second))/2);
        return P;
    } 
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(a,b,c)==1) return true;
        if(Orijentacija(a,b,c)==-1) return false;
        if(Orijentacija(a,b,c)==0) return false;
    } 
    bool DaLiJeUnutra(const Tacka &t) const{
        if(Orijentacija(a,b,c)==Orijentacija(a,b,t) && Orijentacija(a,b,c)==Orijentacija(b,c,t) && Orijentacija(a,b,c)==Orijentacija(c,a,t)) return true;
        return false;
    } 
    void Ispisi() const{
        std::cout << "((" << a.first << "," << a.second << "),(" << b.first << "," << b.second << "),(" << c.first << "," << c.second << "))";
        std::cout << std::endl;
    } 
    void Transliraj(double delta_x, double delta_y) {
        a.first+=delta_x; 
        b.first+=delta_x;
        c.first+=delta_x;
        a.second+=delta_y;
        b.second+=delta_y;
        c.second+=delta_y;
    }  
    void Centriraj(const Tacka &t){
        Tacka centar(DajCentar()); 
        Tacka delta_a(std::make_pair(a.first-centar.first, a.second-centar.second)); 
        Tacka delta_b(std::make_pair(b.first-centar.first, b.second-centar.second));
        Tacka delta_c(std::make_pair(c.first-centar.first, c.second-centar.second)); 
        a.first=delta_a.first+t.first; 
        a.second=delta_a.second+t.second;
        b.first=delta_b.first+t.first;
        b.second=delta_b.second+t.second;
        c.first=delta_c.first+t.first;
        c.second=delta_c.second+t.second;
    } 
    void Rotiraj(const Tacka &t, double ugao){
        a.first=t.first+(a.first-t.first)*std::cos(ugao)-(a.second-t.second)*std::sin(ugao); 
        b.first=t.first+(b.first-t.first)*std::cos(ugao)-(b.second-t.second)*std::sin(ugao);
        c.first=t.first+(c.first-t.first)*std::cos(ugao)-(c.second-t.second)*std::sin(ugao); 
        a.second=t.second+(a.first-t.first)*std::sin(ugao)+(a.second-t.second)*std::cos(ugao); 
        b.second=t.second+(b.first-t.first)*std::sin(ugao)+(b.second-t.second)*std::cos(ugao);
        c.second=t.second+(c.first-t.first)*std::sin(ugao)+(c.second-t.second)*std::cos(ugao);
    } 
    void Skaliraj(const Tacka &t, double faktor){ 
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
        double a1=std::sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second)); 
        double b1=std::sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        double c1=std::sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));  
        a1*=faktor;
        b1*=faktor;
        c1*=faktor; 
        a.first=t.first+faktor*(a.first-t.first);
        a.second=t.second+faktor*(a.second-t.second); 
        b.first=t.first+faktor*(b.first-t.first); 
        b.second=t.second+faktor*(b.second-b.second);  
        c.first=t.first+faktor*(c.first-t.first);
        c.second=t.second+faktor*(c.second-t.second); 
    } 
    void Rotiraj(double ugao){
        Tacka t(DajCentar()); 
        a.first=t.first+(a.first-t.first)*std::cos(ugao)-(a.second-t.second)*std::sin(ugao); 
        b.first=t.first+(b.first-t.first)*std::cos(ugao)-(b.second-t.second)*std::sin(ugao);
        c.first=t.first+(c.first-t.first)*std::cos(ugao)-(c.second-t.second)*std::sin(ugao); 
        a.second=t.second+(a.first-t.first)*std::sin(ugao)+(a.second-t.second)*std::cos(ugao); 
        b.second=t.second+(b.first-t.first)*std::sin(ugao)+(b.second-t.second)*std::cos(ugao);
        c.second=t.second+(c.first-t.first)*std::sin(ugao)+(c.second-t.second)*std::cos(ugao);
    } 
    void Skaliraj(double faktor){
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja"); 
        Tacka t(DajCentar()); 
        double a1=std::sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second)); 
        double b1=std::sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        double c1=std::sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));  
        a1*=faktor;
        b1*=faktor;
        c1*=faktor; 
        a.first=t.first+faktor*(a.first-t.first);
        a.second=t.second+faktor*(a.second-t.second); 
        b.first=t.first+faktor*(b.first-t.first); 
        b.second=t.second+faktor*(b.second-b.second);  
        c.first=t.first+faktor*(c.first-t.first);
        c.second=t.second+faktor*(c.second-t.second); 
    } 
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if((t1.a==t2.a || t1.a==t2.b || t1.a==t2.c) && (t1.b==t2.a || t1.b==t2.b || t1.b==t2.c) && (t1.c==t2.a || t1.c==t2.b ||t1.c==t2.c)) return true;
        return false;
    }  
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        double a1(t1.DajStranicu(1));
        double b1(t1.DajStranicu(2));
        double c1(t1.DajStranicu(3));  
        double a2(t2.DajStranicu(1));
        double b2(t2.DajStranicu(2));
        double c2(t2.DajStranicu(3)); 
        double alpha1(t1.DajUgao(1));
        double beta1(t1.DajUgao(2));
        double gamma1(t1.DajUgao(3)); 
        double alpha2(t1.DajUgao(1));
        double beta2(t2.DajUgao(2));
        double gamma2(t2.DajUgao(3)); 
        if((Poredi(b1,b2) && Poredi(c1,c2) && Poredi(alpha1,alpha2)) || (Poredi(b1,b2) && Poredi(a1,a2) && Poredi(gamma1,gamma2)) || (Poredi(a1,a2) && Poredi(c1,c2) && Poredi(beta1,beta2))) return true;
        if((Poredi(alpha1,alpha2) && Poredi(beta1,beta2) && Poredi(c1,c2)) || (Poredi(beta1,beta2) && Poredi(gamma1,gamma2) && Poredi(a1,a2)) || (Poredi(alpha1,alpha2) && Poredi(gamma1,gamma2) && Poredi(b1,b2))) return true;
        if((Poredi(a1,a2) && Poredi(b1,b2) && Poredi(c1,c2)) || (Poredi(a1,b2) && Poredi(b1,a2) && Poredi(c1,c2)) || (Poredi(a1,a2) && Poredi(b1,c2) && Poredi(c1,b2)) || (Poredi(a1,c2) && Poredi(c1,a2) && Poredi(b1,b2))) return true; 
        if((Poredi(a1,b2) && Poredi(b1,c2) && Poredi(c1, a2)) || (Poredi(a1,c2) && Poredi(b1,a2) && Poredi(c1, b2)))return true;
        if((Poredi(b1,b2) && Poredi(c1,c2) && Poredi(beta1,beta2) && b1>c1) || (Poredi(b1,b2) && Poredi(c1,c2) && Poredi(gamma1,gamma2) && c1>b1) || (Poredi(a1,a2) && Poredi(b1,b2) && Poredi(alpha1,alpha2) && a1>b1) || (Poredi(a1,a2) && Poredi(b1,b2) && Poredi(beta1,beta2) && b1>a1) || (Poredi(a1,a2) && Poredi(c1,c2) && Poredi(gamma1,gamma2) && c1>a1) || (Poredi(a1,a2) && Poredi(c1,c2) && Poredi(alpha1,alpha2) && a1>c1)) return true;
        return false;
    } 
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        double a1(t1.DajStranicu(1)); 
        double b1(t1.DajStranicu(2));
        double c1(t1.DajStranicu(3));
        double a2(t2.DajStranicu(1));
        double b2(t2.DajStranicu(2));
        double c2(t2.DajStranicu(3));
        double v1[3]{a1,b1,c1};
        double v2[3]{a2,b2,c2}; 
        std::sort(v1, v1+3);
        std::sort(v2, v2+3);  
        double k(v1[0]/v2[0]);
        for(int i(1); i<3; i++){
            if(!Poredi(v1[i],v2[i]*k)) return false;
        }  
        return true; 
    }
};
int main ()
{  
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> trokutovi(n); 
    for(int i(0); i<n; ++i){ 
        Tacka a, b, c;
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): "; 
        std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
        trokutovi.push_back(Trougao(a,b,c));
    }
    return 0;
}