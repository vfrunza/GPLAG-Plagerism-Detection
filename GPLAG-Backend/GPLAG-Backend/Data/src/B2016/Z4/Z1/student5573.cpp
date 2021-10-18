/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
#include <limits>

typedef std::pair<double, double> Tacka;
const double PI{4 * std::atan(1)};
const double EPS{0.0000001};

class Trougao {
    Tacka a, b, c; //tri tacke
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int n = t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);
        if(n > 0) return 1;
        if(n < 0) return -1;
        if(n == 0) return 0;
        return 2; 
    }
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

    void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        
        a.first=t1.first;
        a.second=t1.second;
        
        b.first=t2.first;
        b.second=t2.second;
        
        c.first=t3.first;
        c.second=t3.second;
    }
    void Trougao::Postavi(int indeks, const Tacka &t){
        if(indeks==1){
            if(Orijentacija(t, b, c) ==0) throw std::domain_error("Nekorektne pozicije tjemena");
            a.first=t.first;
            a.second=t.second;
        }
        else if(indeks==2){
            if(Orijentacija(a, t, c)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            b.first=t.first;
            b.second=t.second;
        }
        else if(indeks==3){
            if(Orijentacija(a, b, t)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            c.first=t.first;
            c.second=t.second;
        }
        else throw std::range_error("Nekorektan indeks");
    }
    Tacka Trougao::DajTjeme(int indeks) const{
        if(indeks==1) return a;
        if(indeks==2) return b;
        if(indeks==3) return c;
        
        throw std::range_error("Nekorektan indeks");
    }
    double Trougao::DajStranicu(int indeks) const{
        if(indeks==1){
            return std::sqrt((c.first-b.first)*(c.first-b.first) + (c.second-b.second)*(c.second-b.second));
        }
        else if (indeks==2){
            return std::sqrt((a.first-c.first)*(a.first-c.first) + (a.second-c.second)*(a.second-c.second));
        }
        else if (indeks==3){
            return std::sqrt((b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second));
        }
        throw std::range_error("Nekorektan indeks");
    }
    double Trougao::DajUgao(int indeks) const{
        double str_a=DajStranicu(1);
        double str_b=DajStranicu(2);
        double str_c=DajStranicu(3);
        if(indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1){
            double cosA= (double)(str_b*str_b + str_c*str_c - str_a*str_a) / (2*str_b*str_c);
            return acos(cosA);
        }
        if(indeks==2){
            double cosB= (double)(str_c*str_c + str_a*str_a - str_b*str_b) / (2*str_c*str_a);
            return acos(cosB);
        }
        if(indeks==3){
            double cosC=(double)(str_a*str_a + str_b*str_b - str_c*str_c) / (2*str_a*str_b);
            return acos(cosC);
        }
        
        return 0;
    }
    Tacka Trougao::DajCentar() const{
        double x, y;
        x=(double)((a.first+b.first+c.first)/3);
        y=(double)((a.second+b.second+c.second)/3);
        Tacka t(x,y);
        return t;
    }
    double Trougao::DajObim() const{
        double str_a=DajStranicu(1);
        double str_b=DajStranicu(2);
        double str_c=DajStranicu(3);
        return str_a+str_b+str_c;
    }
    void Trougao::Ispisi() const{
        std::cout << "((" << a.first << "," << a.second << "),(" << b.first << "," << b.second << "),(" << c.first << "," << c.second << "))";
        //std::cout << std::endl << DajPovrsinu();
    }
    double Trougao::DajPovrsinu() const{
        return 0.5*(abs(a.first*(b.second-c.second) - b.first*(a.second-c.second) + c.first*(a.second-b.second)));
    }
    bool Trougao::DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(a, b, c)==1) return true;
        return false;
    }
    bool Trougao::DaLiJeUnutra(const Tacka &t) const{
        
        if(t==a) return true;
        if(t==b) return true;
        if(t==c) return true;
        // baricentricne koordinate
        double prva=((b.second - c.second)*(t.first - c.first) + (c.first- b.first)*(t.second - c.second)) / ((b.second - c.second)*(a.first - c.first) + (c.first - b.first)*(a.second - c.second));
        double druga=((c.second - a.second)*(t.first -c.first) + (a.first - c.first)*(t.second - c.second)) / ((b.second - c.second)*(a.first - c.first) + (c.first - b.first)*(a.second - c.second));
        double treca=1.0-prva-druga;
        
        if(prva>0 && druga>0 && treca>0) return true;
        return false;
        
    }
    void Trougao::Transliraj(double delta_x, double delta_y){
        Tacka a1(a.first+delta_x, a.second+delta_y);
        Tacka b1(b.first+delta_x, b.second+delta_y);
        Tacka c1(c.first+delta_x, c.second+delta_y);
        Postavi(a1, b1, c1);
    }
    void Trougao::Centriraj(const Tacka &t){
        Tacka centar=DajCentar();
        double x, y;
        x=t.first-centar.first;
        y=t.second-centar.second;
        Transliraj(x,y);
    }
    void Trougao::Rotiraj(const Tacka &t, double ugao){
        double ax, ay;
        long double cosA(cos(ugao));
        long double sinA(sin(ugao));

        ax = t.first + (a.first-t.first)*cosA - (a.second-t.second)*sinA;
        ay = t.second + (a.first-t.first)*sinA + (a.second-t.second)*cosA;
        Tacka a_prim(ax,ay);
                        
        double bx, by;
        bx = t.first + (b.first-t.first)*cosA - (b.second-t.second)*sinA;
        by = t.second + (b.first - t.first)*sinA + (b.second-t.second)*cosA;
        Tacka b_prim(bx,by);
                        
        double cx, cy;
        cx = t.first + (c.first-t.first)*cosA - (c.second-t.second)*sinA;
        cy = t.second + (c.first-t.first)*sinA + (c.second-t.second)*cosA;
        Tacka c_prim(cx,cy);
        
        Postavi(a_prim, b_prim, c_prim);
    }
    void Trougao::Skaliraj(const Tacka &t, double faktor){
        if(faktor<=0) throw std::domain_error("Nekorektan faktor skaliranja");
        double ax, ay;
        ax=t.first+faktor*(a.first-t.first);
        ay=t.second+faktor*(a.second-t.second);
        Tacka a_prim(ax,ay);
        
        double bx, by;
        bx=t.first+faktor*(b.first-t.first);
        by=t.second+faktor*(b.second-t.second);
        Tacka b_prim(bx,by);
        
        double cx, cy;
        cx=t.first+faktor*(c.first-t.first);
        cy=t.second+faktor*(c.second-t.second);
        Tacka c_prim(cx,cy);
        
        Postavi(a_prim, b_prim, c_prim);
        
    }
    void Trougao::Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); }
    void Trougao::Skaliraj(double faktor){
        if(faktor<=0) throw std::domain_error("Nekorektan faktor skaliranja");
        Skaliraj(DajCentar(), faktor);
    }
    bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if((abs(t1.a.first-t2.a.first)<=EPS && abs(t1.a.second-t2.a.second)<=EPS) && (abs(t1.b.first-t2.b.first)<=EPS && abs(t1.b.second-t2.b.second)<=EPS) && (abs(t1.c.first-t2.c.first)<=EPS && abs(t1.c.second-t2.c.second)<=EPS)) return true;
        if((abs(t1.a.first-t2.a.first)<=EPS && abs(t1.a.second-t2.a.second)<=EPS) && (abs(t1.b.first-t2.c.first)<=EPS && abs(t1.b.second-t2.c.second)<=EPS) && (abs(t1.c.first-t2.b.first)<=EPS && abs(t1.c.second-t2.b.second)<=EPS)) return true;
        if((abs(t1.a.first-t2.c.first)<=EPS && abs(t1.a.second-t2.c.second)<=EPS) && (abs(t1.b.first-t2.b.first)<=EPS && abs(t1.b.second-t2.b.second)<=EPS) && (abs(t1.c.first-t2.a.first)<=EPS && abs(t1.c.second-t2.a.second)<=EPS)) return true;
        if((abs(t1.a.first-t2.b.first)<=EPS && abs(t1.a.second-t2.b.second)<=EPS) && (abs(t1.b.first-t2.a.first)<=EPS && abs(t1.b.second-t2.a.second)<=EPS) && (abs(t1.c.first-t2.c.first)<=EPS && abs(t1.c.second-t2.c.second)<=EPS)) return true;
        if((abs(t1.a.first-t2.b.first)<=EPS && abs(t1.a.second-t2.b.second)<=EPS) && (abs(t1.b.first-t2.c.first)<=EPS && abs(t1.b.second-t2.c.second)<=EPS) && (abs(t1.c.first-t2.a.first)<=EPS && abs(t1.c.second-t2.a.second)<=EPS)) return true;
        if((abs(t1.a.first-t2.b.first)<=EPS && abs(t1.a.second-t2.b.second)<=EPS) && (abs(t1.b.first-t2.a.first)<=EPS && abs(t1.b.second-t2.a.second)<=EPS) && (abs(t1.c.first-t2.b.first)<=EPS && abs(t1.c.second-t2.b.second)<=EPS)) return true;
        return false;
    }
    bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        // Dva trougla su slicna ukoliko su im sva tri ugla jednaka
        
        double alfa_1 = t1.DajUgao(1);
        double str_b1 = t1.DajStranicu(2);
        double str_c1 = t1.DajStranicu(3);
        
        double alfa_2 = t2.DajUgao(1);
        double beta_2 = t2.DajUgao(2);
        double gama_2 = t2.DajUgao(3);
        double str_a2 = t2.DajStranicu(1);
        double str_b2 = t2.DajStranicu(2);
        double str_c2 = t2.DajStranicu(3);
        
        //odnosi b:c moraju biti jednaki
        if(fabs(alfa_1-alfa_2)<std::numeric_limits<double>::epsilon()){ 
            if(fabs(str_b1/str_b2 - str_c1/str_c2)<std::numeric_limits<double>::epsilon()) return true;
            if(fabs(str_b1/str_c2 - str_c1/str_b2)<std::numeric_limits<double>::epsilon()) return true;
        }
        
        if(fabs(alfa_1-beta_2)<std::numeric_limits<double>::epsilon()){ 
            if(fabs(str_b1/str_a2 - str_c1/str_c2)<std::numeric_limits<double>::epsilon()) return true;
            if(fabs(str_b1/str_c2 - str_c1/str_a2)<std::numeric_limits<double>::epsilon()) return true;
        }
        
         if(fabs(alfa_1-gama_2) < std::numeric_limits<double>::epsilon()){ 
            if(fabs(str_b1/str_a2 - str_c1/str_b2)<std::numeric_limits<double>::epsilon()) return true;
            if(fabs(str_b1/str_b2 - str_c1/str_a2)<std::numeric_limits<double>::epsilon()) return true;
        }
        
        return false;
    }
    bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        // Dva trougla su slicna ukoliko su im sva tri ugla jednaka
        
        double alfa_1 = t1.DajUgao(1);
        double beta_1 = t1.DajUgao(2);
        double gama_1 = t1.DajUgao(3);
        double str_a1 = t2.DajStranicu(1);
        double str_b1 = t1.DajStranicu(2);
        double str_c1 = t1.DajStranicu(3);
        
        double alfa_2 = t2.DajUgao(1);
        double beta_2 = t2.DajUgao(2);
        double gama_2 = t2.DajUgao(3);
        double str_a2 = t2.DajStranicu(1);
        double str_b2 = t2.DajStranicu(2);
        double str_c2 = t2.DajStranicu(3);
        
        if(fabs(alfa_1-alfa_2)<std::numeric_limits<double>::epsilon()){ //b i c moraju biti jednaki b i c
            if(fabs(str_b1-str_b2)<std::numeric_limits<double>::epsilon() && fabs(str_c1-str_c2)<std::numeric_limits<double>::epsilon()) return true;
            if(fabs(str_b1-str_c2)<std::numeric_limits<double>::epsilon() && fabs(str_c1-str_b2)<std::numeric_limits<double>::epsilon()) return true;
        }
        
        if(fabs(beta_1-beta_2)<std::numeric_limits<double>::epsilon()){ //a i c
            if(fabs(str_a1-str_c2)<std::numeric_limits<double>::epsilon() && fabs(str_c1-str_c2)<std::numeric_limits<double>::epsilon()) return true;
            if(fabs(str_c1-str_a2)<std::numeric_limits<double>::epsilon() && fabs(str_c1-str_b2)<std::numeric_limits<double>::epsilon()) return true;
        }
        
        if(fabs(gama_1-gama_2)<std::numeric_limits<double>::epsilon()){ // 
            if(fabs(str_b1-str_b2)<std::numeric_limits<double>::epsilon() && fabs(str_c1-str_c2)<std::numeric_limits<double>::epsilon()) return true;
            if(fabs(str_b1-str_c2)<std::numeric_limits<double>::epsilon() && fabs(str_c1-str_b2)<std::numeric_limits<double>::epsilon()) return true;
        }
        return false;
    }
    
int main ()
{
    
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n; 
    std::cin.ignore(100, '\n');
    std::vector<std::shared_ptr<Trougao>> trouglovi;
    
    for(int i =0; i <n; i++){
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        try{
            double x1,y1, x2, y2, x3, y3;
            std::cin >> x1>> y1>> x2>> y2>> x3>> y3;
            //std::cin.ignore(100, '\n');
            Tacka a(x1,y1), b(x2,y2), c(x3,y3);
            std::shared_ptr<Trougao> trougao = std::make_shared<Trougao>(a,b,c); 
            trouglovi.push_back(trougao);
        } catch(std::domain_error e){
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            i--;
            std::cin.clear();
        }
    }
    
    //Translacija radi
    double dx, dy;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> dx >> dy;
    std::cin.ignore(100, '\n');
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), 
                   [dx, dy] (std::shared_ptr<Trougao> t1) {
                        Tacka a=t1->DajTjeme(1);
                        Tacka b=t1->DajTjeme(2);
                        Tacka c=t1->DajTjeme(3);
                       Tacka a1(a.first + dx, a.second + dy);
                       Tacka b1(b.first + dx, b.second + dy);
                       Tacka c1(c.first + dx, c.second + dy);
                       return std::make_shared<Trougao>(a1,b1,c1);
                       }); 


    //Rotacija radi
    long double ugao;
    std::cout << "Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cin.ignore(100, '\n');
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), 
                  [ugao] (std::shared_ptr<Trougao> t1){
                        double ax, ay;
                        long double cosA(cos(ugao));
                        long double sinA(sin(ugao));
                        
                        Tacka a=t1->DajTjeme(1);
                        Tacka b=t1->DajTjeme(2);
                        Tacka c=t1->DajTjeme(3);
                        Tacka t=t1->DajCentar();
                        
                        
                        ax = t.first + (a.first-t.first)*cosA - (a.second-t.second)*sinA;
                        ay = t.second + (a.first-t.first)*sinA + (a.second-t.second)*cosA;
                        Tacka a_prim(ax,ay);
                        
                        double bx, by;
                        bx = t.first + (b.first-t.first)*cosA - (b.second-t.second)*sinA;
                        by = t.second + (b.first - t.first)*sinA + (b.second-t.second)*cosA;
                        Tacka b_prim(bx,by);
                        
                        double cx, cy;
                        cx = t.first + (c.first-t.first)*cosA - (c.second-t.second)*sinA;
                        cy = t.second + (c.first-t.first)*sinA + (c.second-t.second)*cosA;
                        Tacka c_prim(cx,cy);
                        
                        return std::make_shared<Trougao>(a_prim,b_prim,c_prim);
                  }); 

    //Skalirati uzimajuci prvo tjeme!!!
    double faktor;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::cin.ignore(100, '\n');
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), 
                  [faktor] (std::shared_ptr<Trougao> t1) { 
                    Tacka a=t1->DajTjeme(1);
                    Tacka b=t1->DajTjeme(2);
                    Tacka c=t1->DajTjeme(3);
                    Tacka t=t1->DajTjeme(1);
                    
                    if(faktor <= EPS) throw std::domain_error("Nekorektan faktor skaliranja");
                    
                    double ax, ay;
                    ax = t.first + faktor*(a.first-t.first);
                    ay = t.second + faktor*(a.second-t.second);
                    Tacka a_prim(ax,ay);
                    
                    double bx, by;
                    bx = t.first + faktor*(b.first-t.first);
                    by = t.second + faktor*(b.second-t.second);
                    Tacka b_prim(bx,by);
                    
                    double cx, cy;
                    cx = t.first + faktor*(c.first-t.first);
                    cy = t.second + faktor*(c.second-t.second);
                    Tacka c_prim(cx,cy);
                    return std::make_shared<Trougao>(a_prim,b_prim,c_prim);
                  });
    
    std::sort(trouglovi.begin(), trouglovi.end(),
              [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
                  return t1->DajPovrsinu() < t2->DajPovrsinu();
              });
 
    std::cout << "Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(trouglovi.begin(), trouglovi.end(), 
                  [] (std::shared_ptr<Trougao> t1) { t1->Ispisi(); std::cout << std::endl; });
                  
    std::cout << "Trougao sa najmanjim obimom: ";
    auto najmanjiObim = *(std::min_element(trouglovi.begin(), trouglovi.end(),
                     [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
                         return t1->DajObim() < t2->DajObim();
                     }));
    najmanjiObim->Ispisi();
    std::cout<<std::endl; 
    
    bool biliIdenticni=false;
    bool biliPodudarni=false;
    bool biliSlicni=false;
    
    typedef std::pair<int, int> IdenticniTrouglovi;
     std::vector<IdenticniTrouglovi> paroviIdenticni;
     
    typedef std::pair<int, int> SlicniTrouglovi;
    std::vector<SlicniTrouglovi> paroviSlicni;
    
    typedef std::pair<int, int> PodudarniTrouglovi;
    std::vector<PodudarniTrouglovi> paroviPodudarni;
    
    for(int i=0; i < trouglovi.size()-1; i++){
        for(int j=i+1; j < trouglovi.size(); j++){
            if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j])){
                biliIdenticni=true;
                IdenticniTrouglovi identicni(i, j);
                paroviIdenticni.push_back(identicni);
                continue;
            }
            if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j])){
                biliPodudarni=true;
                PodudarniTrouglovi podudarni(i, j);
                paroviPodudarni.push_back(podudarni);
                continue;
            }
            if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j])){
                biliSlicni=true;
                SlicniTrouglovi slicni(i, j);
                paroviSlicni.push_back(slicni);
                continue;
            }
        }
    }
    
    if(!biliIdenticni) std::cout << "Nema identicnih trouglova!\n";
    else{
        std::cout << "Parovi identicnih trouglova:" << std::endl;
        for(int i=0; i < paroviIdenticni.size(); i++){
            trouglovi[paroviIdenticni[i].first]->Ispisi(); std::cout <<" i "; trouglovi[paroviIdenticni[i].second]->Ispisi();
            std::cout << std::endl;
        }
    }
    if(!biliPodudarni) std::cout << "Nema podudarnih trouglova!\n";
    else{
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for(int i=0; i < paroviPodudarni.size(); i++){
            trouglovi[paroviPodudarni[i].first]->Ispisi(); std::cout <<" i "; trouglovi[paroviPodudarni[i].second]->Ispisi();
            std::cout << std::endl;
        }
    }
    if(!biliSlicni) std::cout << "Nema slicnih trouglova!\n";
        else{
        std::cout << "Parovi slicnih trouglova:" << std::endl;
        for(int i=0; i < paroviSlicni.size(); i++){
            trouglovi[paroviSlicni[i].first]->Ispisi(); std::cout <<" i "; trouglovi[paroviSlicni[i].second]->Ispisi();
            std::cout << std::endl;
        }
    }
    
	return 0;
}