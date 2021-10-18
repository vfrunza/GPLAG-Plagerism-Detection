/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <set>
#include <vector>
#include <new>
#include <algorithm>
#include <utility>

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka t1, t2, t3;
    static double Izraz (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Indeks(int indeks) const;
    void orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka VratiTacku(double x, double y, double xc, double yc, double ugao, double k);
public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao (int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra (const Tacka &t) const;
    void Ispisi() const;
    void Transliraj (double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);

    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};

void Trougao::orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1, t2, t3)== 0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
}
void Trougao::Indeks(int indeks) const {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
}
double  Trougao::Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
}
double Izraz1(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
}
int Orijentacija1 (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    const double Eps =  1E-10;
    double pomocna(Izraz1(t1, t2, t3));
    if(pomocna > 0) return 1;
    if(fabs(pomocna - 0.) <= Eps*(fabs(pomocna) + fabs(0.))) return 0;
    return -1;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    const double Eps = 1E-10;
    double pomocna(Trougao::Izraz(t1, t2, t3));
    if(pomocna > 0) return 1;
    if(fabs(pomocna - 0.) <= Eps*(fabs(pomocna) + fabs(0.))) return 0;
    return -1;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    orijentacija(t1, t2, t3);
    Trougao::t1.first = t1.first; Trougao::t1.second = t1.second; Trougao::t2.first = t2.first; Trougao::t2.second = t2.second;
    Trougao::t3.first = t3.first; Trougao::t3.second = t3.second;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    Indeks(indeks);
    if(indeks == 1) t1 = t;
    if(indeks == 2) t2 = t;
    t3 = t;
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Postavi(t1, t2, t3);
}
Tacka Trougao::DajTjeme(int indeks) const {
    Trougao::Indeks(indeks);
    if(indeks == 1) return t1;
    else if(indeks == 2) return t2;
    return t3;
}
double Trougao::DajStranicu(int indeks) const {
    Trougao::Indeks(indeks);
    if(indeks == 1)
        return std::sqrt((t3.first - t2.first)*(t3.first - t2.first) + (t3.second - t2.second)*(t3.second - t2.second));
     if(indeks == 2)
        return std::sqrt((t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second));
    return std::sqrt((t3.first - t1.first)*(t3.first - t1.first) + (t3.second - t1.second)*(t3.second - t1.second));
}
double Trougao::DajUgao(int indeks) const {
    Trougao::Indeks(indeks);
    double a(DajStranicu(3)), b(DajStranicu(2)), c(DajStranicu(1));
    if(indeks == 1) return std::acos((b*b + c*c - a*a)/(2*b*c));
    if(indeks == 2) return std::acos((a*a + c*c - b*b)/(2*a*c));
    return std::acos((b*b + a*a - c*c)/(2*b*a));
}
Tacka Trougao::DajCentar() const {
    return std::make_pair((t1.first + t2.first + t3.first)/3. , (t1.second + t2.second + t3.second)/3.);
}
double Trougao::DajObim() const {
    return DajStranicu(3) + DajStranicu(2) + DajStranicu(1);
}
double Trougao::DajPovrsinu() const {
    return fabs(Trougao::Izraz(t1, t2, t3))/2;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if(Orijentacija(t1, t2, t3)==1) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    int O1(Orijentacija(t1, t2, t3)), O2(Orijentacija(t1, t2, t));
    int O3(Orijentacija(t3, t1, t)), O4(Orijentacija(t2, t3, t));
    if(O1 < 0)
    {
        if(O2 > 0 || O3 > 0 || O4 > 0) return false;
        return true;
    }
    if(O2 < 0 || O3 < 0 || O4 < 0) return false;
    return true;
}
void Trougao::Ispisi() const {
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}
void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first+=delta_x; t1.second+=delta_y;
    t2.first+=delta_x; t2.second+=delta_y;
    t3.first+=delta_x; t3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    double delta_x(DajCentar().first - t.first), delta_y(DajCentar().second - t.second);
        Transliraj(delta_x, delta_y);
}
Tacka Trougao::VratiTacku(double x, double y, double xc, double yc, double ugao, double k){
    return std::make_pair(xc + k*(x - xc)*std::cos(ugao) - k*(y - yc)*std::sin(ugao), yc + k*(x - xc)*std::sin(ugao) + k*(y - yc)*std::cos(ugao));
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    ugao = (ugao*3.14159265359)/180;
    t1 = VratiTacku(t1.first, t1.second, t.first, t.second, ugao, 1);
    t2 = VratiTacku(t2.first, t2.second, t.first, t.second, ugao, 1);
    t3 = VratiTacku(t3.first, t3.second, t.first, t.second, ugao, 1);
}
void Trougao::Rotiraj(double ugao){
    Tacka t(DajCentar());
    Rotiraj(t, ugao);
}
void Trougao::Skaliraj(double faktor){
    Tacka t(DajCentar());
    if(faktor < 0) Rotiraj(t, 180);
    t1 = VratiTacku(t1.first, t1.second, t.first, t.second, 0, faktor);
    t2 = VratiTacku(t2.first, t2.second, t.first, t.second, 0, faktor);
    t3 = VratiTacku(t3.first, t3.second, t.first, t.second, 0, faktor);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    Centriraj(t);
    Skaliraj(faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::multiset<double> s1, s2, s3, s4;
    const double Eps( 1E-10);
    for(int i=1 ; i<4 ; i++){
        s1.insert(t1.DajTjeme(i).first);
        s2.insert(t1.DajTjeme(i).second);
        s3.insert(t2.DajTjeme(i).first);
        s4.insert(t2.DajTjeme(i).second);
    }
    for(auto i = s1.begin(), j = s3.begin() ; i!=s1.end() ; i++,j++){

            if(fabs(*i - *j) > Eps*(fabs(*i) + fabs(*j))) return false;
        }
    for(auto i=s2.begin(), j = s4.begin() ; i!=s2.end() ; i++,j++){

                if(fabs(*i - *j) > Eps*(fabs(*i) + fabs(*j))) return false;

            }
                return true;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    Trougao t11(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)), t22(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3));
    t11.Centriraj(t22.DajCentar());
    const double Eps(1E-10);
    for(int i(1) ; i< 4 ; i++){
        if(fabs(t11.DajUgao(1) - t22.DajUgao(i)) <= Eps*(fabs(t11.DajUgao(1)) + fabs(t22.DajUgao(i))))
        {
            Trougao pomocni(t11.DajCentar(), t11.DajTjeme(1), t22.DajTjeme(i));
            t22.Rotiraj(pomocni.DajUgao(1));
            if(DaLiSuIdenticni(t11, t22)) return true;
            t22.Rotiraj(2*(3.14159265359 - pomocni.DajUgao(1)));
        }
        if(DaLiSuIdenticni(t11, t22)) return true;
    }
        return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double k;
    Trougao t11(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)), t22(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3));
    const double Eps(1E-10);
    for(int i(1) ; i<4 ; i++){
        if(fabs(t11.DajUgao(1) - t22.DajUgao(i)) <= Eps*(fabs(t11.DajUgao(1)) + fabs(t22.DajUgao(i)))){
            if(t11.DajStranicu(1) > t22.DajStranicu(i)){
                k = t11.DajStranicu(1)/t22.DajStranicu(i);
                t22.Skaliraj(k);
            }
                k = t22.DajStranicu(i)/t22.DajStranicu(1);
                t11.Skaliraj(k);
    }
}
if(DaLiSuPodudarni(t11, t22)) return true;
return false;
}

void Unos_tjemena (Tacka &t) {
    double x,y;
    std::cin>>x>>y;
    t.first=x; t.second=y;
}
int main ()
{
   int n;
    std::vector<std::shared_ptr<Trougao>> v;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    for(int i=0 ; i<n ; i++);
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka tjeme1, tjeme2, tjeme3;
        Unos_tjemena(tjeme1);
        Unos_tjemena(tjeme2);
        Unos_tjemena(tjeme3);
        try{
            std::shared_ptr<Trougao> pom (new Trougao(tjeme1, tjeme2, tjeme3));
            if(Orijentacija1(tjeme1, tjeme2, tjeme3) == 0)
            { 
                i--; std::cout<<"Nekorektne pozicije tjemena, ponovite unos!";
                std::cout<<std::endl; continue;}
            v.push_back(std::make_shared<Trougao>(pom));
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
    }
    double dx, dy;
    std::cout<<"Unesite vektor translacije (dx, dy): ";
    std::cin>>dx>>dy;
    double ugao, faktor;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::transform(v.begin(), v.end(), v.begin(),
                   [dx, dy](std::shared_ptr<Trougao> p)
              {
                  p->Transliraj(dx, dy); return p; });
    std::transform(v.begin(), v.end(), v.begin(),
                [ugao](std::shared_ptr<Trougao> p){
                    p->Rotiraj(ugao);
                    return p; });
    std::transform(v.begin(), v.end(), v.begin(),
                [faktor](std::shared_ptr<Trougao> p){
                    Tacka a = p->DajTjeme(1);
                    p->Skaliraj(a, faktor);
                    return p; });
        std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2)
         {
             return p1->DajPovrsinu() < p2->DajPovrsinu();
         });
         std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> p)
                  {
                      p->Ispisi(); std::cout<<std::endl;
                  });
                  std::cout<<"Trougao s najmanjim obimom ";
         auto pok = *min_element(v.begin(), v.end(),[](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2)
                                   {
                                       return p1->DajObim()<p2->DajObim();
                                   });
            pok->Ispisi();
             std::cout<<std::endl;
        int br(0);
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(DaLiSuIdenticni(*v[i], *v[j])){
                    if(br==0){
                        {std::cout<<"Parovi identicnih trouglova:"<<std::endl; 
                        br=1;}
                    }
                    v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi();
                    std::cout<<std::endl; }
                    if(br == 0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
            }
        }
        
        int br1(0);
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(DaLiSuPodudarni(*v[i], *v[j])){
                    if(br1==0){
                        std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
                        br1=1;}
                    }
                    v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi();
                    std::cout<<std::endl; }
                    if(br1==0) std::cout<<"Nema podudarnih trouglova";
            }
        }


        int br2(0);
        for (int i=0 ; i<n ; i++)
            for(int j=i+1 ; j<n ; j++)
                if(DaLiSuSlicni(*v[i], *v[j])){ 
                    if(br2==0){
                         std::cout<<"Parovi slicnih trouglova:"<<std::endl;
                    }
                    v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi();
                    std::cout<<std::endl; 
                    
                }
                    if(br2==0) std::cout<<"Nema slicnih trouglova";
            
        
    
	return 0;
}
    


