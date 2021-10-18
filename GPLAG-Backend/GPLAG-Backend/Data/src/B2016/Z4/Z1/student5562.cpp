/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <memory>

typedef std::pair<double, double> Tacka; 

class Trougao{
    Tacka tacke[3];
    static double TestOrijentacije(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
    }
    static void TestIndeksa(int indeks){
        if (indeks < 1 || indeks > 3)
            throw std::range_error("Nekorektan indeks");
    }
    static double Udaljenost(const Tacka &t1, const Tacka &t2){
        return std::sqrt(std::pow(t1.first - t2.first, 2) + std::pow(t1.second - t2.second, 2));
    }
    void DajOstaleTacke(int indeks, Tacka &t1, Tacka &t2)const;
    static bool Jednaki(double a, double b){
        return std::abs(a - b) <= std::pow(10,-8)*(std::abs(a) + std::abs(b));
    }
    static bool TackeJednake(const Tacka &p1, const Tacka &p2){
        return (Jednaki(p1.first, p2.first) && Jednaki(p1.second, p2.second));
    }
    static double Kosinusna(double a, double b, double c){
        return std::acos((b*b + c*c - a*a)/(2*b*c));
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Postavi(t1, t2, t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const{ TestIndeksa(indeks); return tacke[indeks - 1];}
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const{
        return {(tacke[0].first + tacke[1].first + tacke[2].first)/3, (tacke[0].second + tacke[1].second + tacke[2].second)/3};
    }
    double DajObim() const{ return Udaljenost(tacke[0], tacke[1]) + Udaljenost(tacke[1], tacke[2]) + Udaljenost(tacke[2], tacke[0]);}
    double DajPovrsinu() const{ return std::abs(TestOrijentacije(tacke[0], tacke[1], tacke[2]))/2;}
    bool DaLiJePozitivnoOrijentiran() const{ if (Orijentacija(tacke[0], tacke[1], tacke[2]) == 1) return true; return false;};
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const{ std::cout << "((" << tacke[0].first << "," << tacke[0].second << "),(" << tacke[1].first << "," << tacke[1].second << "),(" << tacke[2].first << "," << tacke[2].second << "))";}
    void Transliraj(double delta_x, double delta_y){for(int i = 0; i < 3; i++){tacke[i].first += delta_x; tacke[i].second += delta_y;}};
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::set<Tacka> s1, s2;
    std::copy(t1.tacke, t1.tacke + 3, std::inserter(s1, s1.begin()));
    std::copy(t2.tacke, t2.tacke + 3, std::inserter(s2, s2.begin()));
    return std::equal(s1.begin(), s1.end(), s2.begin(), Trougao::TackeJednake);
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::set<double> str1{Trougao::Udaljenost(t1.tacke[0], t1.tacke[1]), Trougao::Udaljenost(t1.tacke[1], t1.tacke[2]), Trougao::Udaljenost(t1.tacke[2], t1.tacke[0])};
    std::set<double> str2{Trougao::Udaljenost(t2.tacke[0], t2.tacke[1]), Trougao::Udaljenost(t2.tacke[1], t2.tacke[2]), Trougao::Udaljenost(t2.tacke[2], t2.tacke[0])};
    if (str1 != str2) return false;
    std::vector<Tacka>tacke1, tacke2;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (Trougao::Jednaki(t1.DajUgao(i), t2.DajUgao(j)))
            {
                tacke1.push_back(t1.DajTjeme(i)); 
                tacke2.push_back(t2.DajTjeme(j));
            }
    return Trougao::Orijentacija(tacke1[0], tacke1[1], tacke1[2]) == Trougao::Orijentacija(tacke2[0], tacke2[1], tacke2[2]);
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::set<double>stranice_1, stranice_2;
    stranice_1.insert(Trougao::Udaljenost(t1.tacke[0], t1.tacke[1])); stranice_1.insert(Trougao::Udaljenost(t1.tacke[1], t1.tacke[2])); stranice_1.insert(Trougao::Udaljenost(t1.tacke[0], t1.tacke[2]));
    stranice_2.insert(Trougao::Udaljenost(t2.tacke[0], t2.tacke[1])); stranice_2.insert(Trougao::Udaljenost(t2.tacke[1], t2.tacke[2])); stranice_2.insert(Trougao::Udaljenost(t2.tacke[2], t2.tacke[0]));
    Trougao t(t1); t.Skaliraj(*stranice_1.begin()/ *stranice_2.begin());
    return DaLiSuPodudarni(t, t2);
}

void Trougao::DajOstaleTacke(int indeks, Tacka &t1, Tacka & t2)const{
    if (indeks == 1){ t1 = tacke[1]; t2 = tacke[2];}
    else if (indeks == 2){ t1 = tacke[0]; t2 = tacke[2];}
    else {t1 = tacke[0]; t2 = tacke[1];}
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if (!Orijentacija(t1, t2, t3))
        throw std::domain_error("Nekorektne pozicije tjemena");
    tacke[0] = t1; tacke[1] = t2, tacke[2] = t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    Tacka t1, t2; DajOstaleTacke(indeks, t1, t2);
    if (!Orijentacija(t, t1, t2))
        throw std::domain_error("Nekorektne pozicije tjemena");
    TestIndeksa(indeks); tacke[indeks - 1] = t;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double test(TestOrijentacije(t1, t2, t3));
    if (test > 0) return 1;
    if (test < 0) return -1;
    return 0;
}
double Trougao::DajStranicu(int indeks)const{
    TestIndeksa(indeks);
    Tacka t1, t2;
    DajOstaleTacke(indeks, t1, t2);
    return Udaljenost(t1, t2);
}
double Trougao::DajUgao(int indeks)const{
    TestIndeksa(indeks);
    Tacka t1, t2; DajOstaleTacke(indeks, t1, t2); 
    double a(Udaljenost(t1, t2)), b(Udaljenost(tacke[indeks - 1], t1)), c(Udaljenost(tacke[indeks - 1], t2));
    return Kosinusna(a, b, c);
}
bool Trougao::DaLiJeUnutra(const Tacka &t)const{
    double o(Orijentacija(tacke[0], tacke[1], tacke[2]));
    if (!Jednaki(Orijentacija(tacke[0], tacke[1], t), o) || !Jednaki(Orijentacija(tacke[1], tacke[2], t), o) || !Jednaki(Orijentacija(tacke[2], tacke[0], t), o))
        return false;
    return true;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka c(DajCentar());
    double delta_x = t.first - c.first, delta_y = t.second - c.second;
    Transliraj(delta_x, delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    for (int i = 0; i < 3; i++)
        tacke[i] = {t.first + (tacke[i].first - t.first)*std::cos(ugao) - (tacke[i].second - t.second)*std::sin(ugao), t.second + (tacke[i].first - t.first)*std::sin(ugao) + (tacke[i].second - t.second)*std::cos(ugao)};
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if (Jednaki(faktor, 0))
        throw std::domain_error("Nekorektan faktor skaliranja");
    for (int i = 0; i < 3; i++)
        tacke[i] = {t.first + faktor*(tacke[i].first - t.first), t.second + faktor*(tacke[i].second - t.second)};
}

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: "; 
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> trouglovi(n);
    for (int i = 0; i < n; i++)
    {   double x1, x2, x3, y1, y2, y3;
        for(;;)
        {
            std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            try
            {
                trouglovi[i] = std::make_shared<Trougao>(Trougao({x1, y1}, {x2,y2}, {x3, y3}));
                break;
            }
            catch (std::domain_error)
            {
                std::cout << "Nekorektne pozicije tjemena, ponovite unos!\n";
            }
        }
    }
    int dx, dy;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> dx >> dy;
    double ugao;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    double faktor_skaliranja;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor_skaliranja;
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [dx, dy, ugao, faktor_skaliranja](std::shared_ptr<Trougao> t){
        t->Transliraj(dx, dy);
        t->Rotiraj(t->DajCentar(), ugao);
        t->Skaliraj(t->DajTjeme(1), faktor_skaliranja);
        return t;
    });
    std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<const Trougao> t1, std::shared_ptr<const Trougao> t2){
        return t1->DajPovrsinu() < t2->DajPovrsinu();
    });
    std::cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<const Trougao> t){
        t->Ispisi(); std::cout << std::endl;
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*std::max_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<const Trougao> t1, std::shared_ptr<const Trougao> t2){
        return t1->DajObim() > t2->DajObim();
    }))->Ispisi(); 
    std::cout << std::endl;
    
    int parova(0);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (DaLiSuIdenticni(*trouglovi[i], *trouglovi[j]))
            {   
                if (!parova) std::cout << "Parovi identicnih trouglova:\n";
                trouglovi[i]->Ispisi(); std::cout << " i "; trouglovi[j]->Ispisi(); std::cout << std::endl;
                parova++;
            }
    if (!parova) std::cout << "Nema identicnih trouglova!";
    std::cout << std::endl;
    parova = 0;
    
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (DaLiSuPodudarni(*trouglovi[i], *trouglovi[j]))
            { if (!parova) std::cout << "Parovi podudarnih trouglova:\n";
                trouglovi[i]->Ispisi(); std::cout << " i "; trouglovi[j]->Ispisi(); std::cout << std::endl;
                parova++;
            }
    if (!parova) std::cout << "Nema podudarnih trouglova!";
    std::cout << std::endl;
    
    parova = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (DaLiSuSlicni(*trouglovi[i], *trouglovi[j]))
            {   if (!parova) std::cout << "Parovi slicnih trouglova:\n";
                trouglovi[i]->Ispisi(); std::cout << " i "; trouglovi[j]->Ispisi(); std::cout << std::endl;
                parova++;
            }
    if (!parova) std::cout << "Nema slicnih trouglova!";
	return 0;
}