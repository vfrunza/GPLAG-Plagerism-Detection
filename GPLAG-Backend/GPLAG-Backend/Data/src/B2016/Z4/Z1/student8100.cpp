/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <vector>

const double eps=std::numeric_limits<double>::epsilon();
const double pi=std::atan(1)*4;

typedef std::pair<double, double> Tacka;

double UdaljenostTacaka(const Tacka &t1, const Tacka &t2) {
    return std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
}

double S(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}

class Trougao{
    private:
        Tacka t1,t2,t3;
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(int indeks, const Tacka &t);
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            if(S(t1,t2,t3)>0) return 1;
            else if(S(t1,t2,t3)<0) return -1;
            else return 0;
        }
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const;
        double DajObim() const;
        double DajPovrsinu() const;
        bool DaLiJePozitivnoOrijentiran() const { return Orijentacija(t1,t2,t3)==1; }
        bool DaLiJeUnutra(const Tacka &t) const;
        void Ispisi() const;
        void Transliraj(double delta_x, double delta_y);
        void Centriraj(const Tacka &t);
        void Rotiraj(const Tacka &t, double ugao);
        void Skaliraj(const Tacka &t, double faktor);
        void Rotiraj(double ugao);
        void Skaliraj(double faktor);
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if((t1.t1==t2.t1) || (t1.t1==t1.t2) || (t1.t1==t2.t3))
        if((t1.t2==t2.t1) || (t1.t2==t2.t2) || (t1.t2==t2.t3))
            if((t1.t3==t2.t1) || (t1.t3==t2.t2) || (t1.t3==t2.t3))
                return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    double pstr1(t1.DajStranicu(1)), pstr2(t1.DajStranicu(2)), pstr3(t1.DajStranicu(3)), dstr1(t2.DajStranicu(1)), dstr2(t2.DajStranicu(2)), dstr3(t2.DajStranicu(3));
    double pomp1, pomd1, pomt1, pomp2, pomd2, pomt2;
    if(pstr1>pstr2 && pstr1>pstr3){
        pomp1 = pstr1;
        if(pstr2>pstr3){
            pomd1= pstr2;
            pomt1 = pstr3;
        }
        else{
            pomd1 = pstr3;
            pomt1 = pstr2;
        }
    }
    else if(pstr2>pstr1 && pstr2>pstr3){
        pomp1 = pstr2;
        if(pstr1>pstr3){
            pomd1= pstr1;
            pomt1 = pstr3;
        }
        else{
            pomd1 = pstr3;
            pomt1 = pstr1;
        }
    }
    else if(pstr3>pstr2 && pstr3>pstr1){
        pomp1 = pstr3;
        if(pstr1>pstr2){
            pomd1= pstr1;
            pomt1 = pstr2;
        }
        else{
            pomd1 = pstr2;
            pomt1 = pstr1;
        }
    }
    else if(pstr1==pstr2 && pstr3>pstr1){
        pomp1 = pstr3;
        pomd1 = pstr1;
        pomt1 = pstr2;
    }
    else if(pstr1==pstr2 && pstr1>pstr3){
        pomp1 = pstr2;
        pomd1 = pstr1;
        pomt1 = pstr3;
    }
    else if(pstr1==pstr3 && pstr1>pstr2){
        pomp1 = pstr3;
        pomd1 = pstr1;
        pomt1 = pstr2;
    }
    else if(pstr1==pstr3 && pstr2>pstr1){
        pomp1 = pstr2;
        pomd1 = pstr1;
        pomt1 = pstr3;
    }
    else if(pstr2==pstr3 && pstr1>pstr3){
        pomp1 = pstr1;
        pomd1 = pstr2;
        pomt1 = pstr3;
    }
    else if(pstr2==pstr3 && pstr3>pstr1){
        pomp1 = pstr3;
        pomd1 = pstr2;
        pomt1 = pstr1;
    }
    else{
        pomp1 = pstr3;
        pomd1 = pstr1;
        pomt1 = pstr2;
    }
    
    
    if(dstr1>dstr2 && dstr1>dstr3){
        pomp2 = dstr1;
        if(dstr2>dstr3){
            pomd2= dstr2;
            pomt2 = dstr3;
        }
        else{
            pomd2 = dstr3;
            pomt2 = dstr2;
        }
    }
    else if(dstr2>dstr1 && dstr2>dstr3){
        pomp2 = dstr2;
        if(dstr1>dstr3){
            pomd2= dstr1;
            pomt2 = dstr3;
        }
        else{
            pomd2 = dstr3;
            pomt2 = dstr1;
        }
    }
    else if(dstr3>dstr2 && dstr3>dstr1){
        pomp2 = dstr3;
        if(dstr1>dstr2){
            pomd2 = dstr1;
            pomt2 = dstr2;
        }
        else{
            pomd2 = dstr2;
            pomt2 = dstr1;
        }
    }
    else if(dstr1==dstr2 && dstr3>dstr1){
        pomp2 = dstr3;
        pomd2 = dstr1;
        pomt2 = dstr2;
    }
    else if(dstr1==dstr2 && dstr1>dstr3){
        pomp2 = dstr2;
        pomd2 = dstr1;
        pomt2 = dstr3;
    }
    else if(dstr1==dstr3 && dstr1>dstr2){
        pomp2 = dstr3;
        pomd2 = dstr1;
        pomt2 = dstr2;
    }
    else if(dstr1==dstr3 && dstr2>dstr1){
        pomp2 = dstr2;
        pomd2 = dstr1;
        pomt2 = dstr3;
    }
    else if(dstr2==dstr3 && dstr1>dstr3){
        pomp2 = dstr1;
        pomd2 = dstr2;
        pomt2 = dstr3;
    }
    else if(dstr2==dstr3 && dstr3>dstr1){
        pomp2 = dstr3;
        pomd2 = dstr2;
        pomt2 = dstr1;
    }
    else{
        pomp2 = dstr3;
        pomd2 = dstr1;
        pomt2 = dstr2;
    }
    
    Tacka a1, b1, c1, a2, b2, c2;
    
    if(t1.DajStranicu(1) == pomp1) a1=t1.DajTjeme(1);
    if(t1.DajStranicu(2) == pomp1) a1=t1.DajTjeme(2);
    if(t1.DajStranicu(3) == pomp1) a1=t1.DajTjeme(3);
    if(t1.DajStranicu(1) == pomd1) b1=t1.DajTjeme(1);
    if(t1.DajStranicu(2) == pomd1) b1=t1.DajTjeme(2);
    if(t1.DajStranicu(3) == pomd1) b1=t1.DajTjeme(3);
    if(t1.DajStranicu(1) == pomt1) c1=t1.DajTjeme(1);
    if(t1.DajStranicu(2) == pomt1) c1=t1.DajTjeme(2);
    if(t1.DajStranicu(3) == pomt1) c1=t1.DajTjeme(3);
    
    if(t2.DajStranicu(1) == pomp2) a2=t2.DajTjeme(1);
    if(t2.DajStranicu(2) == pomp2) a2=t2.DajTjeme(2);
    if(t2.DajStranicu(3) == pomp2) a2=t2.DajTjeme(3);
    if(t2.DajStranicu(1) == pomd2) b2=t2.DajTjeme(1);
    if(t2.DajStranicu(2) == pomd2) b2=t2.DajTjeme(2);
    if(t2.DajStranicu(3) == pomd2) b2=t2.DajTjeme(3);
    if(t2.DajStranicu(1) == pomt2) c2=t2.DajTjeme(1);
    if(t2.DajStranicu(2) == pomt2) c2=t2.DajTjeme(2);
    if(t2.DajStranicu(3) == pomt2) c2=t2.DajTjeme(3);
    
    if(pomp1 == pomp2 && pomd1 == pomd2 && pomt1==pomt2 && t1.Orijentacija(a1,b1,c1)==t2.Orijentacija(a2,b2,c2)) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    double pstr1(t1.DajStranicu(1)), pstr2(t1.DajStranicu(2)), pstr3(t1.DajStranicu(3)), dstr1(t2.DajStranicu(1)), dstr2(t2.DajStranicu(2)), dstr3(t2.DajStranicu(3));
    double pomp1, pomd1, pomt1, pomp2, pomd2, pomt2;
    if(pstr1>pstr2 && pstr1>pstr3){
        pomp1 = pstr1;
        if(pstr2>pstr3){
            pomd1= pstr2;
            pomt1 = pstr3;
        }
        else{
            pomd1 = pstr3;
            pomt1 = pstr2;
        }
    }
    else if(pstr2>pstr1 && pstr2>pstr3){
        pomp1 = pstr2;
        if(pstr1>pstr3){
            pomd1= pstr1;
            pomt1 = pstr3;
        }
        else{
            pomd1 = pstr3;
            pomt1 = pstr1;
        }
    }
    else if(pstr3>pstr2 && pstr3>pstr1){
        pomp1 = pstr3;
        if(pstr1>pstr2){
            pomd1= pstr1;
            pomt1 = pstr2;
        }
        else{
            pomd1 = pstr2;
            pomt1 = pstr1;
        }
    }
    else if(pstr1==pstr2 && pstr3>pstr1){
        pomp1 = pstr3;
        pomd1 = pstr1;
        pomt1 = pstr2;
    }
    else if(pstr1==pstr2 && pstr1>pstr3){
        pomp1 = pstr2;
        pomd1 = pstr1;
        pomt1 = pstr3;
    }
    else if(pstr1==pstr3 && pstr1>pstr2){
        pomp1 = pstr3;
        pomd1 = pstr1;
        pomt1 = pstr2;
    }
    else if(pstr1==pstr3 && pstr2>pstr1){
        pomp1 = pstr2;
        pomd1 = pstr1;
        pomt1 = pstr3;
    }
    else if(pstr2==pstr3 && pstr1>pstr3){
        pomp1 = pstr1;
        pomd1 = pstr2;
        pomt1 = pstr3;
    }
    else if(pstr2==pstr3 && pstr3>pstr1){
        pomp1 = pstr3;
        pomd1 = pstr2;
        pomt1 = pstr1;
    }
    else{
        pomp1 = pstr3;
        pomd1 = pstr1;
        pomt1 = pstr2;
    }
    
    
    if(dstr1>dstr2 && dstr1>dstr3){
        pomp2 = dstr1;
        if(dstr2>dstr3){
            pomd2= dstr2;
            pomt2 = dstr3;
        }
        else{
            pomd2 = dstr3;
            pomt2 = dstr2;
        }
    }
    else if(dstr2>dstr1 && dstr2>dstr3){
        pomp2 = dstr2;
        if(dstr1>dstr3){
            pomd2= dstr1;
            pomt2 = dstr3;
        }
        else{
            pomd2 = dstr3;
            pomt2 = dstr1;
        }
    }
    else if(dstr3>dstr2 && dstr3>dstr1){
        pomp2 = dstr3;
        if(dstr1>dstr2){
            pomd2 = dstr1;
            pomt2 = dstr2;
        }
        else{
            pomd2 = dstr2;
            pomt2 = dstr1;
        }
    }
    else if(dstr1==dstr2 && dstr3>dstr1){
        pomp2 = dstr3;
        pomd2 = dstr1;
        pomt2 = dstr2;
    }
    else if(dstr1==dstr2 && dstr1>dstr3){
        pomp2 = dstr2;
        pomd2 = dstr1;
        pomt2 = dstr3;
    }
    else if(dstr1==dstr3 && dstr1>dstr2){
        pomp2 = dstr3;
        pomd2 = dstr1;
        pomt2 = dstr2;
    }
    else if(dstr1==dstr3 && dstr2>dstr1){
        pomp2 = dstr2;
        pomd2 = dstr1;
        pomt2 = dstr3;
    }
    else if(dstr2==dstr3 && dstr1>dstr3){
        pomp2 = dstr1;
        pomd2 = dstr2;
        pomt2 = dstr3;
    }
    else if(dstr2==dstr3 && dstr3>dstr1){
        pomp2 = dstr3;
        pomd2 = dstr2;
        pomt2 = dstr1;
    }
    else{
        pomp2 = dstr3;
        pomd2 = dstr1;
        pomt2 = dstr2;
    }
    
    Tacka a1, b1, c1, a2, b2, c2;
    
    if(t1.DajStranicu(1) == pomp1) a1=t1.DajTjeme(1);
    if(t1.DajStranicu(2) == pomp1) a1=t1.DajTjeme(2);
    if(t1.DajStranicu(3) == pomp1) a1=t1.DajTjeme(3);
    if(t1.DajStranicu(1) == pomd1) b1=t1.DajTjeme(1);
    if(t1.DajStranicu(2) == pomd1) b1=t1.DajTjeme(2);
    if(t1.DajStranicu(3) == pomd1) b1=t1.DajTjeme(3);
    if(t1.DajStranicu(1) == pomt1) c1=t1.DajTjeme(1);
    if(t1.DajStranicu(2) == pomt1) c1=t1.DajTjeme(2);
    if(t1.DajStranicu(3) == pomt1) c1=t1.DajTjeme(3);
    
    if(t2.DajStranicu(1) == pomp2) a2=t2.DajTjeme(1);
    if(t2.DajStranicu(2) == pomp2) a2=t2.DajTjeme(2);
    if(t2.DajStranicu(3) == pomp2) a2=t2.DajTjeme(3);
    if(t2.DajStranicu(1) == pomd2) b2=t2.DajTjeme(1);
    if(t2.DajStranicu(2) == pomd2) b2=t2.DajTjeme(2);
    if(t2.DajStranicu(3) == pomd2) b2=t2.DajTjeme(3);
    if(t2.DajStranicu(1) == pomt2) c2=t2.DajTjeme(1);
    if(t2.DajStranicu(2) == pomt2) c2=t2.DajTjeme(2);
    if(t2.DajStranicu(3) == pomt2) c2=t2.DajTjeme(3);
    
    double temp = std::fabs(pomp1 - pomp2);
    if(std::fabs(pomd1 - pomd2) == temp && std::fabs(pomt1 - pomt2)==temp && t1.Orijentacija(a1,b1,c1) == t2.Orijentacija(a2,b2,c2)) return true;
    return false;
}

void Trougao::Rotiraj(double ugao) {
    this->Rotiraj(this->DajCentar(), ugao);
}

void Trougao::Skaliraj(double faktor) {
    this->Skaliraj(this->DajCentar(), faktor);
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);
}

void Trougao::Centriraj(const Tacka &t) {
    Tacka temp=this->DajCentar();
    this->Transliraj(t.first-temp.first, t.second-temp.second);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    double pom1(t1.first), pom2(t2.first), pom3(t3.first);
    
    t1.first=t.first+(pom1-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
    t2.first=t.first+(pom2-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
    t3.first=t.first+(pom3-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
    
    t1.second=t.second+(pom1-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao);
    t2.second=t.second+(pom2-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao);
    t3.second=t.second+(pom3-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao);
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first+=delta_x;
    t2.first+=delta_x;
    t3.first+=delta_x;
    t1.second+=delta_y;
    t2.second+=delta_y;
    t3.second+=delta_y;
}

void Trougao::Ispisi() const {
    std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
     if(std::fabs(std::fabs(S(t1,t2,t))/2 + std::fabs(S(t2,t3,t))/2 + std::fabs(S(t3,t1,t))/2 - this->DajPovrsinu())<eps) return true;
     return false;
}

double Trougao::DajPovrsinu() const {
    return std::fabs(S(t1,t2,t3))/2;
}

double Trougao::DajObim() const {
    return UdaljenostTacaka(t1,t2)+UdaljenostTacaka(t2,t3)+UdaljenostTacaka(t1,t3);
}

Tacka Trougao::DajCentar() const {
    return {(t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3};
}

double Trougao::DajUgao(int indeks) const {
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double a=UdaljenostTacaka(t2,t3),b=UdaljenostTacaka(t1,t3),c=UdaljenostTacaka(t1,t2);
    if(indeks==1) return (std::acos((b*b+c*c-a*a)/(2*b*c)))*(pi/180);
    else if(indeks==2) return (std::acos((a*a+c*c-b*b)/(2*a*c)))*(pi/180);
    else return (std::acos((a*a+b*b-c*c)/(2*a*b)))*(pi/180);
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); 
    if(indeks==1) return UdaljenostTacaka(t2,t3);
    else if(indeks==2) return UdaljenostTacaka(t1,t3);
    else return UdaljenostTacaka(t1,t2);
}

Tacka Trougao::DajTjeme(int indeks) const { 
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); 
    if(indeks==1) return t1; 
    else if(indeks==2) return t2; 
    else return t3; 
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) t1=t;
    else if(indeks==2) t2=t;
    else t3=t;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!\n");
    this->t1=t1;
    this->t2=t2; 
    this->t3=t3;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!\n");
    this->t1=t1;
    this->t2=t2; 
    this->t3=t3;
}

int main (){
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    try{
        std::vector<std::shared_ptr<Trougao>> niz(n);
        for(int i(0); i<n; i++){
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka t1,t2,t3;
            double a, b, c, d, e, f;
            std::cin >> a >> b >> c >> d >> e >> f;
            t1.first = a;
            t1.second = b;
            t2.first = c;
            t2.second = d;
            t3.first = e;
            t3.second = f;
            try{
                Trougao temp(t1, t2, t3);
                niz[i] = std::make_shared<Trougao>(temp);
            }
            catch(std::domain_error belaj){
                std::cout << belaj.what();
                i--;
            }
        }
        double x, y;
        std::cout << "Unesite vektor translacije (dx dy): ";
        std::cin >> x >> y;
        std::transform(niz.begin(), niz.end(), niz.begin(), [x,y](std::shared_ptr<Trougao> t){ t->Transliraj(x,y); return t;});
        double ugao;
        std::cout << "Unesite ugao rotacije: ";
        std::cin >> ugao;
        std::transform(niz.begin(), niz.end(), niz.begin(), [ugao](std::shared_ptr<Trougao> t){ t->Rotiraj(ugao); return t;});
        double scal;
        std::cout << "Unesite faktor skaliranja: ";
        std::cin >> scal;
        std::transform(niz.begin(), niz.end(), niz.begin(), [scal](std::shared_ptr<Trougao> t){ t->Skaliraj(t->DajTjeme(1), scal); return t;});
        std::sort(niz.begin(), niz.end(), [](std::shared_ptr<Trougao> tr1, std::shared_ptr<Trougao> tr2){ return tr1->DajPovrsinu()<tr2->DajPovrsinu();});
        std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
        std::for_each(niz.begin(), niz.end(), [](std::shared_ptr<Trougao> t){ t->Ispisi(); std::cout << std::endl; });
        
        auto min = *(std::min_element(niz.begin(), niz.end(), [](std::shared_ptr<Trougao> tr1, std::shared_ptr<Trougao> tr2){ return tr1->DajObim() < tr2->DajObim();}));
        std::cout << "Trougao sa najmanjim obimom: "; min->Ispisi(); std::cout << std::endl;
        
        bool iden(false), podud(false), slicni(false);
        for(int i(0); i<n; i++){
            Trougao temp1(niz[i]->DajTjeme(1), niz[i]->DajTjeme(2), niz[i]->DajTjeme(3));
            for(int j(i+1); j<n; j++){
                Trougao temp2(niz[j]->DajTjeme(1), niz[j]->DajTjeme(2), niz[j]->DajTjeme(3));
                if(DaLiSuPodudarni(temp1,temp2)) podud = true;
            }
        }
        for(int i(0); i<n; i++){
            Trougao temp1(niz[i]->DajTjeme(1), niz[i]->DajTjeme(2), niz[i]->DajTjeme(3));
            for(int j(i+1); j<n; j++){
                Trougao temp2(niz[j]->DajTjeme(1), niz[j]->DajTjeme(2), niz[j]->DajTjeme(3));
                if(DaLiSuIdenticni(temp1,temp2)) iden = true;
            }
        }
        for(int i(0); i<n; i++){
            Trougao temp1(niz[i]->DajTjeme(1), niz[i]->DajTjeme(2), niz[i]->DajTjeme(3));
            for(int j(i+1); j<n; j++){
                Trougao temp2(niz[j]->DajTjeme(1), niz[j]->DajTjeme(2), niz[j]->DajTjeme(3));
                if(DaLiSuSlicni(temp1,temp2)) slicni = true;
            }
        }
        if(iden){
            std::cout << "Parovi identicnih trouglova:" << std::endl;
            for(int i(0); i<n; i++){
                Trougao temp1(niz[i]->DajTjeme(1), niz[i]->DajTjeme(2), niz[i]->DajTjeme(3));
                for(int j(i+1); j<n; j++){
                    Trougao temp2(niz[j]->DajTjeme(1), niz[j]->DajTjeme(2), niz[j]->DajTjeme(3));
                    if(DaLiSuIdenticni(temp1,temp2)){
                        temp1.Ispisi(); std::cout << " i "; temp2.Ispisi(); std::cout << std::endl;
                    }
                }
            }
        }
        else std::cout << "Nema identicnih trouglova!" << std::endl;
        if(podud){
            std::cout << "Parovi podudarnih trouglova:" << std::endl;
            for(int i(0); i<n; i++){
                Trougao temp1(niz[i]->DajTjeme(1), niz[i]->DajTjeme(2), niz[i]->DajTjeme(3));
                for(int j(i+1); j<n; j++){
                    Trougao temp2(niz[j]->DajTjeme(1), niz[j]->DajTjeme(2), niz[j]->DajTjeme(3));
                    if(DaLiSuPodudarni(temp1,temp2)){
                        temp1.Ispisi(); std::cout << " i "; temp2.Ispisi(); std::cout << std::endl;
                    }
                }
            }
        }
        else std::cout << "Nema podudarnih trouglova!" << std::endl;
        if(slicni){
            std::cout << "Parovi slicnih trouglova:" << std::endl;
            for(int i(0); i<n; i++){
                Trougao temp1(niz[i]->DajTjeme(1), niz[i]->DajTjeme(2), niz[i]->DajTjeme(3));
                for(int j(i+1); j<n; j++){
                    Trougao temp2(niz[j]->DajTjeme(1), niz[j]->DajTjeme(2), niz[j]->DajTjeme(3));
                    if(DaLiSuSlicni(temp1,temp2)){
                        temp1.Ispisi(); std::cout << " i "; temp2.Ispisi(); std::cout << std::endl;
                    }
                }
            }
        }
        else std::cout << "Nema slicnih trouglova!" << std::endl;
        
    }
    catch(std::domain_error belaj1){
        std::cout << belaj1.what();
    }
    catch(std::range_error belaj2){
        std::cout << belaj2.what();
    }
	return 0;
}