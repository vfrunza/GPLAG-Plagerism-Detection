/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

typedef std::pair<double, double> Tacka;
    
class Trougao {
    
    Tacka x,y,z;
    static bool JesuLiJednaki(double a, double b, double Eps = 1e-10){
        return (std::fabs(a-b) <= Eps * (std::fabs(a) + std::fabs(b)));
    }
    static double NeZoviMamaDoktora(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
    }
    static bool NeZoviMamaDoktora2(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double rez(0);
        rez = NeZoviMamaDoktora(t1, t2, t3);
        if(JesuLiJednaki(rez, 0)) return false;
        return true;
    }
    static bool NeZoviMamaDoktora3(const Tacka &t1, const Tacka &t2){
        if(JesuLiJednaki(t1.first, t2.first) && JesuLiJednaki(t1.second, t2.second)) return true;
        return false;
    }
    void Malopomalo(Tacka &rot, const Tacka &t, double ugao){
        rot = Tacka(t.first+(rot.first - t.first)*std::cos(ugao)-(rot.second-t.second)*std::sin(ugao),t.second+(rot.first-t.first)*std::sin(ugao)+(rot.second-t.second)*std::cos(ugao));
    }
    void Malopomalo2(Tacka &s,const Tacka &t, double faktor) {
        s = Tacka(t.first + faktor*(s.first - t.first),t.second + (s.second - t.second)*faktor);
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(!NeZoviMamaDoktora2(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        x = t1; y = t2; z = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(!NeZoviMamaDoktora2(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        x = t1; y = t2; z = t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        switch(indeks){
            case 1: if(!NeZoviMamaDoktora2(t,y,z)) throw std::domain_error("Nekorektne pozicije tjemena"); x = t; break;
            case 2: if(!NeZoviMamaDoktora2(x,t,z)) throw std::domain_error("Nekorektne pozicije tjemena"); y = t; break;
            case 3: if(!NeZoviMamaDoktora2(x,y,t)) throw std::domain_error("Nekorektne pozicije tjemena"); z = t; break;
            default: break;
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double rez(NeZoviMamaDoktora(t1,t2,t3));
        if(rez > 0) return 1;
        else if(rez < 0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks == 1) return x;
        else if(indeks == 2) return y;
        else return z;
    }
    double DajStranicu(int indeks) const {
        if(indeks == 1) return std::sqrt(std::pow(y.first - z.first, 2) + std::pow(y.second - z.second, 2));
        else if(indeks == 2) return std::sqrt(std::pow(x.first - z.first, 2) + std::pow(x.second - z.second, 2));
        else return std::sqrt(std::pow(x.first - y.first, 2) + std::pow(x.second - y.second, 2));
    }
    double DajUgao(int indeks) const { 
        double str1(DajStranicu(1));
        double str2(DajStranicu(2));
        double str3(DajStranicu(3));
        if(indeks == 1) return acos((str2*str2 + str3*str3 - str1*str1) /(2*str2*str3));
        else if(indeks == 2) return acos((str1*str1 + str3*str3 - str2*str2) / (2*str1*str3));
        else return acos((str1*str1 + str2*str2 - str3*str3) / (2*str1*str2));
    }
    Tacka DajCentar() const { return Tacka((x.first+y.first+z.first)/3, (x.second+y.second+z.second)/3); }
    double DajObim() const { return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3)); }
    double DajPovrsinu() const { double pomocna(0.5 * NeZoviMamaDoktora(x,y,z));  if(pomocna<0) pomocna*=-1; return pomocna;}
    bool DaLiJePozitivnoOrijentiran() const { return (NeZoviMamaDoktora(x,y,z) > 0); }
    bool DaLiJeUnutra(const Tacka &t) const {
        int a(Orijentacija(x,y,z)), b(Orijentacija(x,y,t)), c(Orijentacija(y,z,t)), d(Orijentacija(z,x,t));
        if(a == 1 && b == 1 && c == 1 && d == 1) return true;
        if(a == -1 && b == -1 && c == -1 && d == -1) return true;
    return false;    
    }
    void Ispisi() const {
        std::cout << "((" << x.first << "," << x.second << "),(" << y.first << "," << y.second << "),(" << z.first << "," << z.second << "))";
    }
    void Transliraj(double delta_x, double delta_y) {
        x.first += delta_x; y.first += delta_x; z.first += delta_x;
        x.second += delta_y; y.second += delta_y; z.second += delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka C(DajCentar());
        double poX(t.first - C.first);
        double poY(t.second - C.second);
        Transliraj(poX, poY);
    }
    void Rotiraj(const Tacka &t, double ugao){
        Malopomalo(x,t,ugao);
        Malopomalo(y,t,ugao);
        Malopomalo(z,t,ugao);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
        Malopomalo2(x,t,faktor);
        Malopomalo2(y,t,faktor);
        Malopomalo2(z,t,faktor);
    }
    void Rotiraj(double ugao){ Tacka t(DajCentar()); Rotiraj(t, ugao); }
    void Skaliraj(double ugao) { Tacka t(DajCentar()); Skaliraj(t, ugao); }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};  

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int brojac(0);
    if(Trougao::NeZoviMamaDoktora3(t1.x, t2.x) || Trougao::NeZoviMamaDoktora3(t1.x, t2.y) || Trougao::NeZoviMamaDoktora3(t1.x, t2.z)) brojac++;
    if(Trougao::NeZoviMamaDoktora3(t1.y, t2.x) || Trougao::NeZoviMamaDoktora3(t1.y, t2.y) || Trougao::NeZoviMamaDoktora3(t1.y, t2.z)) brojac++;
    if(Trougao::NeZoviMamaDoktora3(t1.z, t2.x) || Trougao::NeZoviMamaDoktora3(t1.z, t2.y) || Trougao::NeZoviMamaDoktora3(t1.z, t2.z)) brojac++;
    if(brojac == 3) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<std::pair<Tacka, double>> Vektorprvog{{t1.x, t1.DajStranicu(1)},{t1.y, t1.DajStranicu(2)},{t1.z, t1.DajStranicu(3)}};
    std::vector<std::pair<Tacka, double>> Vektordrugog{{t2.x, t2.DajStranicu(1)},{t2.y, t2.DajStranicu(2)},{t2.z, t2.DajStranicu(3)}};

    std::sort(Vektorprvog.begin(), Vektorprvog.end(), [](std::pair<Tacka, double> a, std::pair<Tacka, double> b){
        return a.second > b.second;
    });
    std::sort(Vektordrugog.begin(), Vektordrugog.end(), [](std::pair<Tacka, double> a, std::pair<Tacka, double> b){
        return a.second > b.second;
    });
    std::vector<double> StranicePrvog{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
    std::vector<double> StraniceDrugog{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    std::sort(StranicePrvog.begin(), StranicePrvog.end());
    std::sort(StraniceDrugog.begin(), StraniceDrugog.end());
    
    bool halo(false);
    bool halo2(Trougao::NeZoviMamaDoktora(Vektorprvog[0].first, Vektorprvog[1].first, Vektorprvog[2].first) >0);
    bool halo3(Trougao::NeZoviMamaDoktora(Vektordrugog[0].first, Vektordrugog[1].first, Vektordrugog[2].first) >0);
    if(StranicePrvog == StraniceDrugog) halo = true;
    if(halo && ((halo2 && halo3) || (!halo2 && !halo3))) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double> StranicePrvog{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
    std::vector<double> StraniceDrugog{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    std::sort(StranicePrvog.begin(), StranicePrvog.end());
    std::sort(StraniceDrugog.begin(), StraniceDrugog.end());
    double Prop(StranicePrvog[0]/StraniceDrugog[0]);
    Trougao p1(t1), p2(t2);
    p1.Skaliraj(Prop); p2.Skaliraj(Prop);
    if(DaLiSuPodudarni(p1, p2)) return true;
    return false;  
}


int main ()
{
    try {
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> vektor;
    Tacka t1, t2, t3;
    for(int i=0; i < n; i++){
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> t1.first >> t1.second;
        std::cin >> t2.first >> t2.second;
        std::cin >> t3.first >> t3.second;
        try {
            vektor.push_back(std::make_shared<Trougao>(t1,t2,t3));
        }catch(std::domain_error exec){
            std::cout << exec.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    double cm1, cm2, cm3, cm4;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> cm1 >> cm2;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> cm3;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> cm4;
    
    // transformisanje..
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [&](std::shared_ptr<Trougao> h){
        h->Transliraj(cm1,cm2);
        h->Rotiraj(cm3);
        h->Skaliraj(h->DajTjeme(1),cm4);
        return h;
    });

    std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
       return t1->DajPovrsinu() < t2->DajPovrsinu(); 
    });
    
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t){
       t->Ispisi(); std::cout << std::endl;
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*std::min_element(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        return t1->DajObim() < t2->DajObim(); 
    }))->Ispisi();
    
    std::cout << std::endl;
    
    bool ImaLLajne(true);
    if(vektor.empty()) std::cout << "Nema identicnih trouglova!" << std::endl;
    else {
        
        for(int i=0; i < vektor.size(); i++){
            for(int j = i+1; j < vektor.size(); j++){
                if(DaLiSuIdenticni(*vektor[i], *vektor[j])){
                    if(ImaLLajne){
                        std::cout << "Parovi identicnih trouglova:" << std::endl;
                        ImaLLajne = false;
                    }
                    vektor[i]->Ispisi(); std::cout << " i "; vektor[j]->Ispisi(); std::cout << std::endl;
                }
            }
        }
        if(ImaLLajne) std::cout << "Nema identicnih trouglova!" << std::endl;
    }
    
    ImaLLajne = true;
    
    if(vektor.empty()) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else {
        
        for(int i=0; i < vektor.size(); i++){
            for(int j = i+1; j < vektor.size(); j++){
                if(DaLiSuPodudarni(*vektor[i], *vektor[j])){
                    if(ImaLLajne){
                        std::cout << "Parovi podudarnih trouglova:" << std::endl;
                        ImaLLajne = false;
                    }
                    vektor[i]->Ispisi(); std::cout << " i "; vektor[j]->Ispisi(); std::cout << std::endl;
                }
            }
        }
        if(ImaLLajne) std::cout << "Nema podudarnih trouglova!" << std::endl;
    }
    
    ImaLLajne = true;
    
    if(vektor.empty()) std::cout << "Nema slicnih trouglova!" << std::endl;
    else {
        
        for(int i=0; i < vektor.size(); i++){
            for(int j = i+1; j < vektor.size(); j++){
                if(DaLiSuSlicni(*vektor[i], *vektor[j])){
                    if(ImaLLajne){
                        std::cout << "Parovi slicnih trouglova:" << std::endl;
                        ImaLLajne = false;
                    }
                    vektor[i]->Ispisi(); std::cout << " i "; vektor[j]->Ispisi(); std::cout << std::endl;
                }
            }
        }
        if(ImaLLajne) std::cout << "Nema slicnih trouglova!" << std::endl;
    }
    
    ImaLLajne = true;
    }catch(...){
        return 0;
    }
	return 0;
}
