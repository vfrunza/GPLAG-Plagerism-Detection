#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
typedef std::pair<double, double> Tacka;
const double PI = 4*atan(1);
const double epsilon = 0.00000000001;

// rijeci napisano su mi sluzile kao zabiljeske dokle sam dosao
bool porediTjemena(const Tacka &t1, const Tacka &t2){
    if(std::fabs(t1.first - t2.first) <= epsilon && std::fabs(t1.second - t2.second) <= epsilon) return true;
    return false;
}
bool porediDuzine(const double &a, const double &b){
    if(std::fabs(a-b) <= epsilon) return true;
    return false;
}
double provjera(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
} // vraca vrijednost povrsine
double duzina(Tacka t1, Tacka t2){
    return sqrt( pow(t1.first - t2.first, 2) + pow(t1.second - t2.second, 2) );
} // duzina sranice
double ugao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double a(duzina(t2, t3)), b(duzina(t1, t3)), c(duzina(t1, t2));
    return ( acos((pow( b, 2) + pow(c, 2) - pow(a, 2) ) / (2 * b * c)));
} // ugao odabranog tjemena
class Trougao{
    Tacka tjeme1, tjeme2, tjeme3;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ Postavi(t1,t2,t3); } // napisano
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){ // napisano
        if(!(Orijentacija(t1,t2,t3))) throw std::domain_error("Nekorektne pozicije tjemena");
        tjeme1 = t1; tjeme2 = t2; tjeme3 = t3;
    }
    void Postavi(int indeks, const Tacka &t); // napisano
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double tmp(provjera(t1, t2, t3));
        if(tmp > 0) return 1;
        if(tmp < 0) return -1;
        return 0;
    } // napisano
    Tacka DajTjeme(int indeks) const{ // napisano
        if (indeks == 1) return tjeme1;
        if(indeks == 2) return tjeme2;
        if(indeks == 3) return tjeme3;
        throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const; // napisano
    double DajUgao(int indeks) const; // napisano
    Tacka DajCentar() const{ return std::make_pair((tjeme1.first + tjeme2.first + tjeme3.first) / 3, (tjeme1.second + tjeme2.second + tjeme3.second) / 3); } //napisano
    double DajObim() const{ return duzina(tjeme1, tjeme2) + duzina(tjeme1, tjeme3) + duzina(tjeme2, tjeme3); } // napisano
    double DajPovrsinu() const{ return std::fabs(provjera(tjeme1, tjeme2, tjeme3)); } // napisano
    bool DaLiJePozitivnoOrijentiran() const{ return (Orijentacija(tjeme1, tjeme2, tjeme3) == 1); } // napisano
    bool DaLiJeUnutra(const Tacka &t) const; // napisano
    void Ispisi() const; // napisano
    void Transliraj(double delta_x, double delta_y){
        tjeme1.first += delta_x; tjeme1.second += delta_y;
        tjeme2.first += delta_x; tjeme2.second += delta_y;
        tjeme3.first += delta_x; tjeme3.second += delta_y;
    } // napisano
    void Centriraj(const Tacka &t); // napisano
    void Rotiraj(const Tacka &t, double ugao);// napisano
    void Skaliraj(const Tacka &t, double faktor); // napisano
    void Rotiraj(double ugao){ Rotiraj(DajCentar(), ugao); } // napisano
    void Skaliraj(double faktor){ Skaliraj(DajCentar(), faktor); } // napisano
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2); // napisano
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2); // napisano
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};
void Trougao::Postavi(int indeks, const Tacka &t){
        switch(indeks){
            case 1:
                Postavi(t,tjeme2,tjeme3);
                return;
            case 2:
                Postavi(tjeme1,t,tjeme3);
                return;
            case 3:
                Postavi(tjeme1,tjeme2,t);
                return;
        }
        throw std::range_error("Nekorektan indeks");
}
double Trougao::DajStranicu(int indeks)const{
    if(indeks == 1) return duzina(tjeme2, tjeme3);
    if(indeks == 2) return duzina(tjeme1, tjeme3);
    if(indeks == 3) return duzina(tjeme1, tjeme2);
    throw std::range_error("Nekorektan indeks");
}
double Trougao::DajUgao(int indeks)const{
    if(indeks == 1) return ugao(tjeme1, tjeme2, tjeme3);
    if(indeks == 2) return ugao(tjeme2, tjeme1, tjeme3);
    if(indeks == 3) return ugao(tjeme3, tjeme1, tjeme2);
    throw std::range_error("Nekorektan indeks");
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    double tmp = provjera(tjeme1, tjeme2, tjeme3);
    if(tmp > 0 && provjera(tjeme1, tjeme2,t) > 0 && provjera(tjeme2, tjeme3, t) > 0 && provjera(tjeme3, tjeme1, t) > 0) return true;
    else if(tmp < 0 && provjera(tjeme1, tjeme2,t) < 0 && provjera(tjeme2, tjeme3, t) < 0 && provjera(tjeme3, tjeme1, t) < 0) return true;
    return false;
}
void Trougao::Ispisi() const{
    std::cout << "((" << tjeme1.first << "," << tjeme1.second << "),"
              << "(" << tjeme2.first << "," << tjeme2.second << "),"
              << "(" << tjeme1.first << "," << tjeme1.second << "))";
}
void Trougao::Centriraj(const Tacka &t){
    Tacka T = DajCentar();
    double delta_x = t.first - T.first, delta_y = t.second - T.second;
    Transliraj(delta_x, delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    tjeme1 = std::make_pair(t.first + (tjeme1.first - t.first)*cos(ugao) - (tjeme1.second - t.second)*sin(ugao), t.second + (tjeme1.first - t.first)*sin(ugao) + (tjeme1.second - t.second)*cos(ugao));
    tjeme2 = std::make_pair(t.first + (tjeme2.first - t.first)*cos(ugao) - (tjeme2.second - t.second)*sin(ugao), t.second + (tjeme2.first - t.first)*sin(ugao) + (tjeme2.second - t.second)*cos(ugao));
    tjeme3 = std::make_pair(t.first + (tjeme3.first - t.first)*cos(ugao) - (tjeme3.second - t.second)*sin(ugao), t.second + (tjeme3.first - t.first)*sin(ugao) + (tjeme3.second - t.second)*cos(ugao));
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    tjeme1 = std::make_pair(t.first + faktor*(tjeme1.first - t.first), t.second + faktor*(tjeme1.second - t.second));
    tjeme2 = std::make_pair(t.first + faktor*(tjeme2.first - t.first), t.second + faktor*(tjeme2.second - t.second));
    tjeme3 = std::make_pair(t.first + faktor*(tjeme3.first - t.first), t.second + faktor*(tjeme3.second - t.second));
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(t1.DajCentar() != t2.DajCentar()) return false;
    if(porediTjemena(t1.tjeme1, t2.tjeme1)){
        if((porediTjemena(t1.tjeme2, t2.tjeme2) && porediTjemena(t1.tjeme3, t2.tjeme3)) || (porediTjemena(t1.tjeme3, t2.tjeme2) && porediTjemena(t1.tjeme2, t2.tjeme3))) return true;
    }
    else if(porediTjemena(t1.tjeme1, t2.tjeme2)){
        if((porediTjemena(t1.tjeme2, t2.tjeme1) && porediTjemena(t1.tjeme3, t2.tjeme3)) || (porediTjemena(t1.tjeme2, t2.tjeme3) && porediTjemena(t1.tjeme2, t2.tjeme3))) return true;
    }
    else if(porediTjemena(t1.tjeme1, t2.tjeme3)){
        if((porediTjemena(t1.tjeme2, t2.tjeme1) && porediTjemena(t1.tjeme3, t2.tjeme2)) || (porediTjemena(t1.tjeme2, t2.tjeme2) && porediTjemena(t1.tjeme3, t2.tjeme1))) return true;
    }
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(Trougao::Orijentacija(t1.tjeme1, t1.tjeme2, t1.tjeme3) != Trougao::Orijentacija(t2.tjeme1, t2.tjeme2, t2.tjeme3)) return false;
    double a1, b1, c1, a2, b2, c2;
    a1 = duzina(t1.tjeme1, t1.tjeme2); b1 = duzina(t1.tjeme1, t1.tjeme3); c1 = duzina(t1.tjeme2, t1.tjeme3);
    a2 = duzina(t2.tjeme1, t2.tjeme2); b2 = duzina(t2.tjeme1, t2.tjeme3); c2 = duzina(t2.tjeme2, t2.tjeme3);
    if(porediDuzine(a1, a2)){
        if((porediDuzine(b1, b2) && porediDuzine(c1, c2)) || (porediDuzine(b1, c2) && porediDuzine(c1, b2))) return true;
    }
    else if(porediDuzine(a1, b2)){
        if((porediDuzine(b1, a2) && porediDuzine(c1, c2)) || (porediDuzine(b1, c2) && porediDuzine(c1, a2))) return true;
    }
    else if(porediDuzine(a1, c2)){
        if((porediDuzine(b1, a2) && porediDuzine(c1, b2)) || (porediDuzine(b1, b2) && porediDuzine(c1, a2))) return true;
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    if(DaLiSuPodudarni(t1, t2)) return true;
    if(Trougao::Orijentacija(t1.tjeme1, t1.tjeme2, t1.tjeme3) != Trougao::Orijentacija(t2.tjeme1, t2.tjeme2, t2.tjeme3)) return false;
    double a1, b1, c1, a2, b2, c2;
    a1 = duzina(t1.tjeme1, t1.tjeme2); b1 = duzina(t1.tjeme1, t1.tjeme3); c1 = duzina(t1.tjeme2, t1.tjeme3);
    a2 = duzina(t2.tjeme1, t2.tjeme2); b2 = duzina(t2.tjeme1, t2.tjeme3); c2 = duzina(t2.tjeme2, t2.tjeme3);
    if((porediDuzine(a1/a2, b1/b2) && porediDuzine(a1/a2, c1/c2)) || (porediDuzine(a1/a2, b1/c2) && porediDuzine(a1/a2, c1/b2))) return true;
    else if((porediDuzine(a1/b2, b1/a2) && porediDuzine(a1/b2, c1/c2)) || (porediDuzine(a1/b2, b1/c2) && porediDuzine(a1/b2, c1/a2))) return true;
    else if((porediDuzine(a1/c2, b1/a2) && porediDuzine(a1/c2, b1/a2)) || (porediDuzine(a1/c2, b1/b2) && porediDuzine(a1/c2, c1/a2))) return true;
    return false;
}


void unosTacke(Tacka &t){
    std::cin >> t.first >> t.second;
}
typedef std::vector<std::shared_ptr<Trougao>> Trouglovi;
typedef std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> ParoviTrouglova;

int main (){
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n; std::cin >> n;
    Trouglovi trouglovi(n);
    for(int i(0); i < n; i++){
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1, t2, t3;
        unosTacke(t1);
        unosTacke(t2);
        unosTacke(t3);
        if(!(Trougao::Orijentacija(t1, t2, t3))) {
            std::cout << "Nekorektne pozicije tjemena, ponovite unos!" << std::endl;
            i--; continue;
        }
        auto tmp = std::shared_ptr<Trougao>(new Trougao(t1,t2,t3));
        trouglovi[i] = tmp;
        std::cout << std::endl;
    }
    double delta_x, delta_y;
    std::cout << "Unesite vektor translacije (dx dy): "; std::cin >> delta_x >> delta_y;
    double ugao, faktor;
    std::cout << "Unesite ugao rotacije: "; std::cin >> ugao; std::cout << "Unesite faktor skaliranja: "; std::cin >> faktor;
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [delta_x, delta_y, ugao, faktor](std::shared_ptr<Trougao> T){ 
        (*T).Transliraj(delta_x, delta_y);
        (*T).Rotiraj(ugao);
        (*T).Skaliraj((*T).DajTjeme(1), faktor); return T;
    });
    std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> T1, std::shared_ptr<Trougao> T2){ return (*T1).DajPovrsinu() < (*T2).DajPovrsinu(); });
    std::cout << std::endl;
    std::for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> T){
        (*T).Ispisi();
        std::cout << std::endl;
    });
    auto T = std::max_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> T1, std::shared_ptr<Trougao> T2){
        return (*T1).DajObim() < (*T2).DajObim();
    });
    std::cout << std::endl;
    std::cout << "Trougao s najmanjim obimom je: ";
    (**T).Ispisi();
    ParoviTrouglova identicni, podudarni, slicni;
    for(int i(0); i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuIdenticni(*(trouglovi[i]), *(trouglovi[j]))) {
                identicni.push_back(std::make_pair((trouglovi[i]), (trouglovi[j])));
                podudarni.push_back(std::make_pair((trouglovi[i]), (trouglovi[j])));
                slicni.push_back(std::make_pair((trouglovi[i]), (trouglovi[j])));
            }
            else if(DaLiSuPodudarni(*(trouglovi[i]), *(trouglovi[j]))){
                podudarni.push_back(std::make_pair((trouglovi[i]), (trouglovi[j])));
                slicni.push_back(std::make_pair((trouglovi[i]), (trouglovi[j])));
            }
            else if(DaLiSuSlicni(*(trouglovi[i]), *(trouglovi[j]))) slicni.push_back(std::make_pair((trouglovi[i]), (trouglovi[j])));
        }
    }
    std::cout << "Identicni su: "; std::for_each(identicni.begin(), identicni.end(), [](std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>> par){
        (*(par.first)).Ispisi(); std::cout << " i "; (*(par.second)).Ispisi();
        std::cout << std::endl;
    });
    std::cout << "Podudarni su: "; std::for_each(podudarni.begin(), podudarni.end(), [](std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>> par){
        (*(par.first)).Ispisi(); std::cout << " i "; (*(par.second)).Ispisi();
        std::cout << std::endl;
    });
    std::cout << "Slicni su: "; std::for_each(slicni.begin(), slicni.end(), [](std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>> par){
        (*(par.first)).Ispisi(); std::cout << " i "; (*(par.second)).Ispisi();
        std::cout << std::endl;
    });
	return 0;
}









