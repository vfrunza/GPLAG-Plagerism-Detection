/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#define Eps 1E-10
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka A, B, C;
    void Provjera(int indeks) const{
        if(!(indeks==1 || indeks==2 || indeks==3)) throw std::range_error("Nekorektan indeks");
    }
    static const double PI;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
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

const double Trougao::PI(4*std::atan(1));

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    A=t1; B=t2; C=t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    A=t1; B=t2; C=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t){
    Trougao::Provjera(indeks);
    if(indeks==1) Trougao::Postavi(t,B,C);
    else if(indeks==2) Trougao::Postavi(A,t,C);
    else Trougao::Postavi(A,B,t);
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    auto rez(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
    if(rez>0) return 1;
    if(rez<0) return -1;
    return 0;
}

Tacka Trougao::DajTjeme(int indeks) const{
    Trougao::Provjera(indeks);
    if(indeks==1) return A;
    else if(indeks==2) return B;
    return C;
}

double Trougao::DajStranicu(int indeks) const{
    Trougao::Provjera(indeks);
    if(indeks==1) return std::sqrt(std::pow(B.first-C.first,2) + std::pow(B.second-C.second,2));
    else if(indeks==2) return std::sqrt(std::pow(A.first-C.first,2) + std::pow(A.second-C.second,2));
    return std::sqrt(std::pow(A.first-B.first,2) + std::pow(A.second-B.second,2));
}

double Trougao::DajUgao(int indeks) const{
    Trougao::Provjera(indeks);
    auto a(DajStranicu(1));
    auto b(DajStranicu(2));
    auto c(DajStranicu(3));
    auto alfa(std::acos((a*a+c*c-b*b)/(2*b*c)));
    auto beta(std::acos((a*a+c*c-b*b)/(2*a*c)));
    auto gama(std::acos((a*a+c*c-b*b)/(2*a*b)));
    if(indeks==1) return alfa;
    else if(indeks==2) return beta;
    return gama;
}

Tacka Trougao::DajCentar() const{
    Tacka centar;
    centar.first = (A.first+B.first+C.first)/3;
    centar.second = (A.second+B.second+C.second)/3;
    return centar;
}

double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double Trougao::DajPovrsinu() const{
    return (0.5*std::fabs(A.first*(B.second-C.second) + B.first*(C.second-A.second) + C.first*(A.second-B.second)));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(A,B,C)==1) return true;
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    try{
        Trougao ABC(A,B,C), ABt(A,B,t), BCt(B,C,t), CAt(C,A,t);
        if(std::fabs(ABC.DajPovrsinu()-(ABt.DajPovrsinu()+BCt.DajPovrsinu()+CAt.DajPovrsinu())) <= Eps ) return true;
    }
    catch(...){
        return false;
    }
    return false;
}

void Trougao::Ispisi() const{
    std::cout << "((" << A.first << "," << A.second << "),(" << B.first << "," << 
    B.second << "),(" << C.first << "," << C.second << "))" ; 
}

void Trougao::Transliraj(double delta_x, double delta_y){
    A.first += delta_x; A.second += delta_y;
    B.first += delta_x; B.second += delta_y;
    C.first += delta_x; C.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    double pomak_po_x(std::fabs(DajCentar().first) + std::fabs(t.first));
    double pomak_po_y(std::fabs(DajCentar().second) + std::fabs(t.second));
    if(std::fabs(DajCentar().first - t.first) <= Eps) pomak_po_x=0;
    if(std::fabs(DajCentar().second - t.second) <= Eps) pomak_po_y=0;
    if(t.first>=DajCentar().first && t.second>=DajCentar().second){
        A.first += pomak_po_x; A.second += pomak_po_y;
        B.first += pomak_po_x; B.second += pomak_po_y;
        C.first += pomak_po_x; C.second += pomak_po_y;
    }
    else if(t.first<DajCentar().first && t.second<DajCentar().second){
        A.first -= pomak_po_x; A.second -= pomak_po_y;
        B.first -= pomak_po_x; B.second -= pomak_po_y;
        C.first -= pomak_po_x; C.second -= pomak_po_y;
    }
    else if(t.first>DajCentar().first && t.second<DajCentar().second){
        A.first += pomak_po_x; A.second -= pomak_po_y;
        B.first += pomak_po_x; B.second -= pomak_po_y;
        C.first += pomak_po_x; C.second -= pomak_po_y;
    }
    else if(t.first<DajCentar().first && t.second>DajCentar().second){
        A.first -= pomak_po_x; A.second += pomak_po_y;
        B.first -= pomak_po_x; B.second += pomak_po_y;
        C.first -= pomak_po_x; C.second += pomak_po_y;
    }
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka a,b,c;
    a.first = t.first + (A.first - t.first)*std::cos(ugao) - (A.second - t.second)*std::sin(ugao); 
    a.second = t.second + (A.first - t.first)*std::sin(ugao) + (A.second - t.second)*std::cos(ugao);
    b.first = t.first + (B.first - t.first)*std::cos(ugao) - (B.second - t.second)*std::sin(ugao); 
    b.second = t.second + (B.first - t.first)*std::sin(ugao) + (B.second - t.second)*std::cos(ugao);
    c.first = t.first + (C.first - t.first)*std::cos(ugao) - (C.second - t.second)*std::sin(ugao); 
    c.second = t.second + (C.first - t.first)*std::sin(ugao) + (C.second - t.second)*std::cos(ugao);
    A=a; B=b; C=c;
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(std::fabs(faktor-0) <= Eps ) throw std::domain_error("Nekorektan faktor skaliranja");
    else if(faktor>0){
        A.first = t.first + faktor*(A.first-t.first); A.second = t.second + faktor*(A.second-t.second);
        B.first = t.first + faktor*(B.first-t.first); B.second = t.second + faktor*(B.second-t.second);
        C.first = t.first + faktor*(C.first-t.first); C.second = t.second + faktor*(C.second-t.second);
    }
    else{
        A.first = t.first + faktor*(A.first-t.first); A.second = t.second + faktor*(A.second-t.second);
        B.first = t.first + faktor*(B.first-t.first); B.second = t.second + faktor*(B.second-t.second);
        C.first = t.first + faktor*(C.first-t.first); C.second = t.second + faktor*(C.second-t.second);
        Rotiraj(DajCentar(),PI);
    }
}

void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(), ugao);
}


void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(), faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    //return((t1.A==t2.A || t1.A==t2.B || t1.A==t2.C) && (t1.B==t2.A || t1.B==t2.B || t1.B==t2.C) && (t1.C==t2.A || t1.C==t2.B || t1.C==t2.C));
    return ((t1.A==t2.A && ((t1.B==t2.B && t1.C==t2.C) || (t1.B==t2.C && t1.C==t2.B))) ||
            (t1.A==t2.B && ((t1.B==t2.C && t1.C==t2.A) || (t1.B==t2.A && t1.C==t2.C))) ||
            (t1.A==t2.C && ((t1.B==t2.A && t1.C==t2.B) || (t1.B==t2.B && t1.C==t2.A))));
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    auto c1(t1.DajStranicu(3)); auto b1(t1.DajStranicu(2)); auto a1(t1.DajStranicu(1));
    auto c2(t2.DajStranicu(3)); auto b2(t2.DajStranicu(2)); auto a2(t2.DajStranicu(1));
    return (std::fabs((a1+b1+c1) - (a2+b2+c2)) <= Eps && std::fabs(a1*b1*c1 - a2*b2*c2) <= Eps) &&
            //(std::fabs(Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) - Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))<=Eps);
            (t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) &&
            (!(t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == 0 || t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)) == 0)) ;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    auto c1(t1.DajStranicu(3)); auto b1(t1.DajStranicu(2)); auto a1(t1.DajStranicu(1));
    auto c2(t2.DajStranicu(3)); auto b2(t2.DajStranicu(2)); auto a2(t2.DajStranicu(1));
    return ((std::fabs(a1*b1*c1)/(a2*b2*c2) - std::pow((a1+b1+c1)/(a2+b2+c2),3)) <= Eps ) && 
            //(std::fabs(Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) - Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))<=Eps);
            (t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) ;
}

int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: " ;
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v;
    v.resize(n);
    for(int i=0; i<v.size(); i++){
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): " ;
        Tacka A, B, C;
        std::cin >> A.first >> A.second;
        std::cin >> B.first >> B.second;
        std::cin >> C.first >> C.second;
        try{
            Trougao t(A,B,C);
            v[i]=std::make_shared<Trougao>(t);
        }
        catch(std::domain_error e){
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            i--;
        }
        catch(std::bad_alloc e){
            std::cout << "Problem sa memorijom" << std::endl;
        }
    }
    double delta_x, delta_y, ugao, faktor_skaliranja;
    std::cout << "Unesite vektor translacije (dx dy): " ;
    std::cin >> delta_x >> delta_y ;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao ;
    std::cout << "Unesite faktor skaliranja: " ;
    std::cin >> faktor_skaliranja;
    /*for(int i=0; i<v.size(); i++){
        auto centar=v[i]->DajCentar();
        std::cout << "Centar: " << centar.first << ", " << centar.second << std::endl;
        //v[i]->Transliraj(delta_x,delta_y);
        //v[i]->Rotiraj(v[i]->DajCentar(),ugao);
        v[i]->Skaliraj(v[i]->DajCentar(),faktor_skaliranja);
    }
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){t->Ispisi(); std::cout << std::endl;});
    */
    std::transform(v.begin(), v.end(), v.begin(), [delta_x,delta_y](std::shared_ptr<Trougao> t){ 
        t->Transliraj(delta_x,delta_y);
        return t;
    });
    std::transform(v.begin(), v.end(), v.begin(), [ugao](std::shared_ptr<Trougao> t){ 
        t->Rotiraj(t->DajCentar(),ugao);
        return t;
    });
    std::transform(v.begin(), v.end(), v.begin(), [faktor_skaliranja](std::shared_ptr<Trougao> t){ 
        t->Skaliraj(t->DajTjeme(1),faktor_skaliranja);
        return t;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        if(t1->DajPovrsinu()>=t2->DajPovrsinu()) return false;
        return true;
    });
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){t->Ispisi(); std::cout << std::endl;});
    auto pok(std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        if(t1->DajObim()<=t2->DajObim()) return true;
        return false;
    }));
    
    std::cout << "Trougao sa najmanjim obimom: " ; (*pok)->Ispisi(); std::cout << std::endl;
    bool postoje_slicni(false); bool postoje_podudarni(false); bool postoje_identicni(false);
    
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
                if(!postoje_identicni) std::cout << "Parovi identicnih trouglova: " << std::endl;
                (*v[i]).Ispisi(); std::cout << " i "; (*v[j]).Ispisi(); std::cout << std::endl;
                postoje_identicni=true;
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
                if(!postoje_podudarni) std::cout << "Parovi podudarnih trouglova: " << std::endl;
                (*v[i]).Ispisi(); std::cout << " i "; (*v[j]).Ispisi(); std::cout << std::endl;
                postoje_podudarni=true;
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
                if(!postoje_slicni) std::cout << "Parovi slicnih trouglova: " << std::endl;
                (*v[i]).Ispisi(); std::cout << " i "; (*v[j]).Ispisi(); std::cout << std::endl;
                postoje_slicni=true;
            }
        }
    }
    if(!postoje_identicni) std::cout << "Nema identicnih trouglova!" << std::endl;
    if(!postoje_podudarni) std::cout << "Nema podudarnih trouglova!" << std::endl;
    if(!postoje_slicni) std::cout << "Nema slicnih trouglova!" << std::endl;

  	return 0;
}