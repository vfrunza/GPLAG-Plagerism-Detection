#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <utility>

typedef std::pair<double, double> Tacka;
const double eps = 1E-10;

class Trougao {
    Tacka vrhovi[3];
    static void TestIndeksa(int indeks){
        if(indeks == 1 || indeks == 2 || indeks == 3)return ;
        throw std::range_error("Nekorektan indeks");
    }
    
    static double Pomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    
    static bool SuprotnaOrijentacija(const Trougao &t1, const Trougao &t2);
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Orijentacija(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena"); vrhovi[0]=t1; vrhovi[1]=t2; vrhovi[2]=t3;   }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Orijentacija(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena"); vrhovi[0] = t1; vrhovi[1] = t2; vrhovi[2] = t3; }
    void Postavi(int indeks, const Tacka &t){ TestIndeksa(indeks); vrhovi[indeks-1] = t; if(Orijentacija(vrhovi[0], vrhovi[1], vrhovi[2]) == 0) throw std::domain_error("Nekorektne pozicije tjemena"); }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Pomocna(t1,t2,t3) > 0) return 1; if(Pomocna(t1,t2,t3)<0)return -1; return 0; }
    Tacka DajTjeme(int indeks){ TestIndeksa(indeks); return vrhovi[indeks-1]; }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar()const{ return {(vrhovi[0].first+vrhovi[1].first+vrhovi[2].first)/3, (vrhovi[0].second+vrhovi[1].second+vrhovi[2].second)/3}; }
    double DajObim() const{ return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
    double DajPovrsinu() const{ double s = Pomocna(vrhovi[0], vrhovi[1], vrhovi[2]); s = std::fabs(s); return s*0.5; }
    bool DaLiJePozitivnoOrijentiran() const{ if(Orijentacija(vrhovi[0], vrhovi[1], vrhovi[2]) > 0)return true; return false; }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const { std::cout<< "((" << vrhovi[0].first << "," << vrhovi[0].second << "),(" << vrhovi[1].first << "," << vrhovi[1].second << "),(" << vrhovi[2].first << "," << vrhovi[2].second<<"))"; }
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao&t2);
};

bool Trougao::SuprotnaOrijentacija(const Trougao &t1, const Trougao &t2){
    double a(Trougao::Pomocna(t1.vrhovi[0], t1.vrhovi[1], t1.vrhovi[2]));
    double b(Trougao::Pomocna(t2.vrhovi[0], t2.vrhovi[1], t2.vrhovi[2]));
    
    if(std::fabs(a + b) < eps)return true;
    
    return false;
}
double Trougao::DajStranicu(int indeks) const{
    TestIndeksa(indeks);
    if(indeks == 1)
        return std::sqrt((vrhovi[1].first-vrhovi[2].first)*(vrhovi[1].first-vrhovi[2].first) + (vrhovi[1].second-vrhovi[2].second)*(vrhovi[1].second-vrhovi[2].second));
    else if(indeks == 2)
        return std::sqrt((vrhovi[0].first-vrhovi[2].first)*(vrhovi[0].first-vrhovi[2].first) + (vrhovi[0].second-vrhovi[2].second)*(vrhovi[0].second-vrhovi[2].second));
    
    else if(indeks == 3) return std::sqrt((vrhovi[0].first-vrhovi[1].first)*(vrhovi[0].first-vrhovi[1].first) + (vrhovi[0].second-vrhovi[1].second)*(vrhovi[0].second-vrhovi[1].second));
return 0;
}

double Trougao::DajUgao(int indeks) const{
    TestIndeksa(indeks);
    double a,b,c;
    if(indeks == 1){  a = DajStranicu(1);  b = DajStranicu(2);  c = DajStranicu(3);}
    else if(indeks == 2){  a = DajStranicu(2);  b = DajStranicu(3);  c = DajStranicu(1); }
    else{ a = DajStranicu(3);  b = DajStranicu(1); c = DajStranicu(2); }
    
    return acos((a*a-b*b-c*c)/(-2*b*c));
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if(DaLiJePozitivnoOrijentiran())
        if(Trougao(vrhovi[0], vrhovi[1], t).DaLiJePozitivnoOrijentiran())
            if(Trougao(vrhovi[1], vrhovi[2], t).DaLiJePozitivnoOrijentiran())
                if(Trougao(vrhovi[2], vrhovi[0], t).DaLiJePozitivnoOrijentiran())
                    return true;
    if(!DaLiJePozitivnoOrijentiran())
        if(!Trougao(vrhovi[0], vrhovi[1], t).DaLiJePozitivnoOrijentiran())
            if(!Trougao(vrhovi[1], vrhovi[2], t).DaLiJePozitivnoOrijentiran())
                if(!Trougao(vrhovi[2], vrhovi[0], t).DaLiJePozitivnoOrijentiran())
                    return true;
    return false;
}

void Trougao::Transliraj(double delta_x, double delta_y){
    for(int i(0); i < 3; i++){
        vrhovi[i].first+=delta_x; vrhovi[i].second+=delta_y;
    }
}

void Trougao::Centriraj(const Tacka &t){
    double delta_x = t.first - this->DajCentar().first;
    double delta_y = t.second - this->DajCentar().second;
    for(int i(0); i < 3; i++){
        vrhovi[i].first+=delta_x; vrhovi[i].second+=delta_y;
    }
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    double prva, druga;
    for(int i(0); i < 3; i++){
        prva = t.first + (vrhovi[i].first - t.first)*std::cos(ugao) - (vrhovi[i].second - t.second)*std::sin(ugao);
        druga = t.second + (vrhovi[i].first - t.first)*std::sin(ugao) + (vrhovi[i].second - t.second)*std::cos(ugao);
        Trougao::vrhovi[i] = {prva, druga};
    }
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(std::fabs(faktor - 0) < eps)throw std::domain_error("Nekorektan faktor skaliranja");
    
    for(int i(0); i < 3; i++){
        vrhovi[i].first = t.first + faktor*(vrhovi[i].first - t.first);
        vrhovi[i].second = t.second + faktor*(vrhovi[i].second - t.second);
    }
    
    if(faktor < 0) Rotiraj({0,0}, 4*atan(1));
}

void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(), faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int brojac{};
    for(int i(0); i < 3; i++)
        for(int j(0); j < 3; j++)
            if((t1.vrhovi[i] == t2.vrhovi[j])) ++brojac;
    
    if(brojac == 3)return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<double> stranice1, stranice2;
    
    for(int i(0); i < 3; i++){
        stranice1.push_back(t1.DajStranicu(i+1));
        stranice2.push_back(t2.DajStranicu(i+1));
    }
    std::sort(stranice1.begin(), stranice1.end());
    std::sort(stranice2.begin(), stranice2.end());
    
    int brojac{};
    
    for(int i(0); i < 3; i++)
        if(std::fabs(stranice1[i] - stranice2[i]) < eps) ++brojac;
        
        if(brojac != 3)return false;
        
    std::pair<double, Tacka> prvi[3], drugi[3];
    
    for(int i(0); i < 3; i++){
        prvi[i].second = t1.vrhovi[i]; prvi[i].first = t1.DajStranicu(i+1);
        drugi[i].second = t2.vrhovi[i]; drugi[i].first = t2.DajStranicu(i+1);
    }
    
    std::sort(prvi, prvi + 3);
    std::sort(drugi, drugi + 3);
    
    if(std::fabs(Trougao::Orijentacija(prvi[0].second, prvi[1].second, prvi[2].second) - Trougao::Orijentacija(drugi[0].second, drugi[1].second, drugi[2].second)) > eps)return false;
    return true;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double Uglovi1[3], Uglovi2[3];
    
    for(int i(0); i < 3; i++){
        Uglovi1[i] = t1.DajUgao(i+1);
        Uglovi2[i] = t2.DajUgao(i+1);
    }
    std::sort(Uglovi1, Uglovi1 + 3);
    std::sort(Uglovi2, Uglovi2 + 3);
    
    int brojac{};
    
    for(int i(0); i < 3; i++)
        if(std::fabs(Uglovi1[i] - Uglovi2[i]) < eps)++brojac;
        
        if(brojac != 3) return false;
        
        std::pair<double, Tacka> prvi[3], drugi[3];
        for(int i(0); i < 3; i++){
            prvi[i].second = t1.vrhovi[i]; prvi[i].first = t1.DajUgao(i+1);
            drugi[i].second = t2.vrhovi[i]; drugi[i].first = t2.DajUgao(i+1);
        }
        
        std::sort(prvi, prvi + 3);
        std::sort(drugi, drugi + 3);
        
        if(std::fabs(Trougao::Orijentacija(prvi[0].second, prvi[1].second, prvi[2].second) - Trougao::Orijentacija(drugi[0].second, drugi[1].second, drugi[2].second)) > eps) return false;
        return true;
}

int main ()
{
    try{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    if(n < 0) throw std::domain_error("");
    std::vector<std::shared_ptr<Trougao>> VektorTrouglova(n);
    double x1,y1,x2,y2,x3,y3;
    
    for(int i(0); i < n; i++){
        try{
        std::cout<< "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x1 >> y1 >> x2 >>y2 >> x3 >> y3;
        std::shared_ptr<Trougao> t(std::make_shared<Trougao> (Trougao({x1,y1},{x2,y2},{x3,y3})));
        VektorTrouglova[i] = t;
        t = nullptr;
        }catch(std::domain_error iz){
            std::cout << iz.what() << ", ponovite unos!" << std::endl;
            i--;
        
    }
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
        double dx, dy;
        std::cin >> dx >> dy;
    
    std::cout << "Unesite ugao rotacije: ";
        double u;
        std::cin >> u;
        
    std::cout << "Unesite faktor skaliranja: ";
        double faktor;
        std::cin >> faktor;
        
    std::transform(VektorTrouglova.begin(), VektorTrouglova.end(), VektorTrouglova.begin(),[=](const std::shared_ptr<Trougao> &t){
        t->Transliraj(dx, dy);
        t->Rotiraj(u);
        t->Skaliraj(t->DajTjeme(1), faktor);
        return t;
    });
    
    std::sort(VektorTrouglova.begin(), VektorTrouglova.end(), [](const std::shared_ptr<Trougao> &t1, const std::shared_ptr<Trougao> &t2){
        return t1->DajPovrsinu() < t2->DajPovrsinu();
    });
    
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::for_each(VektorTrouglova.begin(), VektorTrouglova.end(), [](const std::shared_ptr<Trougao> &t){
        t->Ispisi();
        std::cout << std::endl;
    });
    
    std::cout << "Trougao sa najmanjim obimom: ";
    if(VektorTrouglova.size() >= 1){
    auto k = std::min_element(VektorTrouglova.begin(), VektorTrouglova.end(), [](const std::shared_ptr<Trougao> &t1, const std::shared_ptr<Trougao> &t2){
        return t1->DajObim() < t2->DajObim();
        });
        (**k).Ispisi();
    }
        std::cout << std::endl;
    std::vector<std::pair<Trougao, Trougao>> identicni, podudarni, slicni;
    
    if(VektorTrouglova.size()>= 2){
    for(int i(0); i < VektorTrouglova.size()-1; i++)
        for(int j(i+1); j< VektorTrouglova.size(); j++){
            if(i == j)continue;
            if(DaLiSuIdenticni(*VektorTrouglova[i], *VektorTrouglova[j]))
                identicni.emplace_back(*VektorTrouglova[i], *VektorTrouglova[j]);
        }
    }
    
    if(identicni.size() == 0)std::cout << "Nema identicnih trouglova!" << std::endl;
    else{
    std::cout << "Parovi identicnih trouglova:" << std::endl;
    std::for_each(identicni.begin(), identicni.end(), [](const std::pair<Trougao, Trougao> &t){
        t.first.Ispisi(); std::cout << " i "; t.second.Ispisi(); std::cout << std::endl;
    });
    }
    if(VektorTrouglova.size()>=2) {
    for(int i(0); i < VektorTrouglova.size()-1; i++)
        for(int j(i+1); j < VektorTrouglova.size(); j++){
            if(i == j)continue;
            if(DaLiSuPodudarni(*VektorTrouglova[i], *VektorTrouglova[j]))
                podudarni.emplace_back(*VektorTrouglova[i], *VektorTrouglova[j]);
        }
    }
    if(podudarni.size() == 0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else{
    std::cout << "Parovi podudarnih trouglova:" << std::endl;
    std::for_each(podudarni.begin(), podudarni.end(), [](const std::pair<Trougao, Trougao> &t){
        t.first.Ispisi(); std::cout << " i "; t.second.Ispisi(); std::cout << std::endl;
    });
    }
    if(VektorTrouglova.size() >=2){
    for(int i(0); i < VektorTrouglova.size()-1; i++)
        for(int j(i+1); j < VektorTrouglova.size(); j++){
            if(i == j)continue;
            if(DaLiSuSlicni(*VektorTrouglova[i], *VektorTrouglova[j]))
                slicni.emplace_back(*VektorTrouglova[i], *VektorTrouglova[j]);
        }
    }
    if(slicni.size() == 0)std::cout << "Nema slicnih trouglova!"<< std::endl;
    else{
    std::cout << "Parovi slicnih trouglova:" << std::endl;
    std::for_each(slicni.begin(), slicni.end(), [](const std::pair<Trougao, Trougao> &t){
        t.first.Ispisi(); std::cout << " i "; t.second.Ispisi(); std::cout << std::endl;
    });
    }
    }catch(std::domain_error iz){
        std::cout << iz.what() << std::endl;
    }catch(std::range_error iz){
        std::cout << iz.what() << std::endl;
    }
	return 0;
}