/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <exception>
#include <vector>
#include <algorithm>
#include <memory>
#define epsilon 0.00001

typedef std::pair<double, double> Tacka;
const double pi = 4*atan(1);

class Trougao
{
    Tacka t[3];
    static  bool JesuLiJednaki(const double &x,const double &y, const double Eps = 1E-10) {
        if((x < 0 and y > 0) or (x > 0 and y < 0)) return false;
        return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
    }
    static  bool JesuLiJednaki(const Tacka &x, const Tacka &y, const double Eps = 1E-10) {
        if (JesuLiJednaki(x.first,y.first) and JesuLiJednaki(x.second,y.second)) return true;
        return false;
    }
    static int index (int indeks) {
        if (indeks < 1 or indeks > 3) throw std::range_error ("Nekorektan indeks");
        if (indeks == 1) return 0;
        else if (indeks == 2) return 1;
        else return 2;
    }
    static double Duz_str (const Tacka &t1, const Tacka &t2) {
        return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    static double Izraz (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    static void Rot_t (Tacka &t1,const Tacka &t,double ugao) {
        t1 = std::make_pair((t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao)),(t.second+(t1.first-t.first)*sin(ugao) + (t1.second-t.second)*cos(ugao)));
    }
public:
    // KONSTRUKTOR
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {

        Postavi(t1,t2,t3);
    }
    // POSTAVI
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Orijentacija(t1,t2,t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t[0] = t1;
        Trougao::t[1] = t2;
        Trougao::t[2] = t3;
    }
    // Postavi (jednu tacku)
    void Postavi(int indeks, const Tacka &t) {
        int i(index(indeks));
        if (i == 0) Postavi(t,Trougao::t[1],Trougao::t[2]);
        else if (i == 1) Postavi(Trougao::t[0],t,Trougao::t[2]);
        else if (i == 2) Postavi(Trougao::t[0],Trougao::t[1],t);

    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double t(Izraz(t1,t2,t3));
        if (t > 0. and !JesuLiJednaki(t,0.)) return 1;
        else if (t < 0. and !JesuLiJednaki(t,0.)) return -1;
        else return 0;
    }

    Tacka DajTjeme(int indeks) const {
        int i = index(indeks);
        return t[i];
    }
    double DajStranicu(int indeks) const {
        int i(index(indeks));
        if (i == 0) return Duz_str(t[1],t[2]);
        else if (i == 1) return Duz_str(t[0],t[2]);
        else return Duz_str(t[0],t[1]);
    }
    double DajUgao(int indeks) const {
        int i(index(indeks));
        if (i == 0) {
            double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
            return acos((a*a+b*b-c*c)/(2*(a*b)));
        } else if (i == 1) {
            double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
            return acos((b*b+c*c-a*a)/(2*(b*c)));
        } else {
            double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
            return acos((c*c+a*a-b*b)/(2*(c*a)));
        }
    }
    Tacka DajCentar() const {
        return std::make_pair((t[0].first+t[1].first+t[2].first)/3.,(t[0].second+t[1].second+t[2].second)/3);
    }
    double DajObim() const {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const {
        return std::fabs(Izraz(t[0],t[1],t[2])*0.5);
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if (Orijentacija(t[0],t[1],t[2])) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if (Orijentacija(Trougao::Trougao::t[0],Trougao::t[1],Trougao::t[2]) == Orijentacija(Trougao::Trougao::t[0],Trougao::t[1],t) and Orijentacija(Trougao::t[0],Trougao::t[1],Trougao::t[2]) == Orijentacija(Trougao::t[1],Trougao::t[2],t) and Orijentacija(Trougao::t[0],Trougao::t[1],Trougao::t[2]) == Orijentacija(Trougao::t[2],Trougao::t[0],t))
            return true;
        return false;
    }
    void Ispisi() const {
        std::cout << "(("<< t[0].first<< ","<<t[0].second<< "),("<<t[1].first<< ","<<t[1].second<< "),("<<t[2].first<< ","<<t[2].second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        Postavi(std::make_pair(t[0].first+delta_x,t[0].second+delta_y),std::make_pair(t[1].first+delta_x,t[1].second+delta_y),std::make_pair(t[2].first+delta_x,t[2].second+delta_y));
    }
    void Centriraj(const Tacka &t) {
        auto t1(DajCentar());
        Transliraj(t.first-t1.first,t.second-t1.second);
    }
    void Rotiraj(const Tacka &t, double ugao) {
        Rot_t(Trougao::t[0],t,ugao);
        Rot_t(Trougao::t[1],t,ugao);
        Rot_t(Trougao::t[2],t,ugao);
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if ((faktor) < 0. and !JesuLiJednaki(faktor,0.)) throw std::domain_error ("Nekorektan faktor skaliranja");
        Trougao::t[0].first = t.first + faktor*(Trougao::t[0].first-t.first);
        Trougao::t[0].second = t.second + faktor*(Trougao::t[0].second-t.second);
        Trougao::t[1].first = t.first + faktor*(Trougao::t[1].first-t.first);
        Trougao::t[1].second = t.second + faktor*(Trougao::t[1].second-t.second);
        Trougao::t[2].first = t.first + faktor*(Trougao::t[2].first-t.first);
        Trougao::t[2].second = t.second + faktor*(Trougao::t[2].second-t.second);
    }
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if ((Trougao::JesuLiJednaki(t1.t[0],t2.t[0]) and Trougao::JesuLiJednaki(t1.t[1],t2.t[1]) and Trougao::JesuLiJednaki(t1.t[2],t2.t[2]))
            or (Trougao::JesuLiJednaki(t1.t[0],t2.t[0]) and Trougao::JesuLiJednaki(t1.t[1],t2.t[2]) and Trougao::JesuLiJednaki(t1.t[2],t2.t[1]))
            or (Trougao::JesuLiJednaki(t1.t[0],t2.t[1]) and Trougao::JesuLiJednaki(t1.t[1],t2.t[0]) and Trougao::JesuLiJednaki(t1.t[2],t2.t[2]))
            or (Trougao::JesuLiJednaki(t1.t[0],t2.t[1]) and Trougao::JesuLiJednaki(t1.t[1],t2.t[2]) and Trougao::JesuLiJednaki(t1.t[2],t2.t[0]))
            or (Trougao::JesuLiJednaki(t1.t[0],t2.t[2]) and Trougao::JesuLiJednaki(t1.t[1],t2.t[0]) and Trougao::JesuLiJednaki(t1.t[2],t2.t[1]))
            or (Trougao::JesuLiJednaki(t1.t[0],t2.t[2]) and Trougao::JesuLiJednaki(t1.t[1],t2.t[1]) and Trougao::JesuLiJednaki(t1.t[2],t2.t[0]))) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if ((Trougao::JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(1)) and Trougao::JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(2)) and Trougao::JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(3)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[0],t2.t[1],t2.t[2]))
            or (Trougao::JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(1)) and Trougao::JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(3)) and Trougao::JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(2)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[0],t2.t[2],t2.t[1]))
            or (Trougao::JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(2)) and Trougao::JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(1)) and Trougao::JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(3)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[1],t2.t[0],t2.t[2]))
            or (Trougao::JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(2)) and Trougao::JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(3)) and Trougao::JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(1)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[1],t2.t[2],t2.t[0]))
            or (Trougao::JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(3)) and Trougao::JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(1)) and Trougao::JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(2)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[2],t2.t[0],t2.t[1]))
            or (Trougao::JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(3)) and Trougao::JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(2)) and Trougao::JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(1)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[2],t2.t[1],t2.t[0])))
        return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if ((Trougao::JesuLiJednaki(t1.DajUgao(1),t2.DajUgao(1)) and Trougao::JesuLiJednaki(t1.DajUgao(2),t2.DajUgao(2)) and Trougao::JesuLiJednaki(t1.DajUgao(3),t2.DajUgao(3)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[0],t2.t[1],t2.t[2]))
            or (Trougao::JesuLiJednaki(t1.DajUgao(1),t2.DajUgao(1)) and Trougao::JesuLiJednaki(t1.DajUgao(2),t2.DajUgao(3)) and Trougao::JesuLiJednaki(t1.DajUgao(3),t2.DajUgao(2)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[0],t2.t[2],t2.t[1]))
            or (Trougao::JesuLiJednaki(t1.DajUgao(1),t2.DajUgao(2)) and Trougao::JesuLiJednaki(t1.DajUgao(2),t2.DajUgao(1)) and Trougao::JesuLiJednaki(t1.DajUgao(3),t2.DajUgao(3)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[1],t2.t[0],t2.t[2]))
            or (Trougao::JesuLiJednaki(t1.DajUgao(1),t2.DajUgao(2)) and Trougao::JesuLiJednaki(t1.DajUgao(2),t2.DajUgao(3)) and Trougao::JesuLiJednaki(t1.DajUgao(3),t2.DajUgao(1))  and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[1],t2.t[2],t2.t[0]))
            or (Trougao::JesuLiJednaki(t1.DajUgao(1),t2.DajUgao(3)) and Trougao::JesuLiJednaki(t1.DajUgao(2),t2.DajUgao(1)) and Trougao::JesuLiJednaki(t1.DajUgao(3),t2.DajUgao(2)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[2],t2.t[0],t2.t[1]))
            or (Trougao::JesuLiJednaki(t1.DajUgao(1),t2.DajUgao(3)) and Trougao::JesuLiJednaki(t1.DajUgao(2),t2.DajUgao(2)) and Trougao::JesuLiJednaki(t1.DajUgao(3),t2.DajUgao(1)) and Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2]) == Trougao::Orijentacija(t2.t[2],t2.t[1],t2.t[0])))
        return true;
    return false;
}
int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v;
    Tacka t1,t2,t3;
    for (int i = 0; i < n; i++) {
        std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> t1.first >> t1.second;
        std::cin >> t2.first >> t2.second;
        std::cin >> t3.first >> t3.second;
        try {
            v.push_back(std::make_shared<Trougao>(t1,t2,t3));
        } catch (std::domain_error e) {
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    double x1,y1,x2,y2;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> x1 >> y1;
    std::cout << "Unesite ugao rotacije: Unesite faktor skaliranja: ";
    std::cin >> x2 >> y2;
    std::transform(v.begin(),v.end(),v.begin(),[=](std::shared_ptr<Trougao> r) {
        r->Transliraj(x1,y1);
        return r;
    });
    std::transform(v.begin(),v.end(),v.begin(),[=](std::shared_ptr<Trougao> r) {

        r->Rotiraj(x2);
        return r;
    });
    std::transform(v.begin(),v.end(),v.begin(),[=](std::shared_ptr<Trougao> r) {

        r->Skaliraj(r->DajTjeme(1),y2);
        return r;
    });
    
    std::sort (v.begin(), v.end(), [](const std::shared_ptr<Trougao> &t1, const std::shared_ptr<Trougao> &t2) {
        return t1->DajPovrsinu() < t2->DajPovrsinu();
    });
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    for (auto &i : v) {
        i->Ispisi();
        std::cout  << std::endl;
    }
    std::cout << "Trougao sa najmanjim obimom: ";
    (*min_element(v.begin(), v.end(), [](const std::shared_ptr<Trougao> &t1, const std::shared_ptr<Trougao> &t2) {
        return t1->DajObim() < t2->DajObim();
    }))->Ispisi();
    std::cout  << std::endl;
    bool flag(true);
    if (v.empty()) std::cout << "Nema identicnih trouglova!" << std::endl;
    else {
        for (int i = 0; i < v.size()-1; i++) {
            for (int j = i+1; j <v.size() ; j++) {
                if (DaLiSuIdenticni(*v[i],*v[j])) {
                    if (flag) {
                        std::cout << "Parovi identicnih trouglova:" << std::endl;
                        flag = false;
                    }
                    v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi(); std::cout  << std::endl;
                }
            }
        }
        if (flag) std::cout << "Nema identicnih trouglova!" << std::endl;
    }
    flag = true;
    
    if (v.empty()) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else {
        for (int i = 0; i < v.size()-1; i++) {
            for (int j = i+1; j <v.size() ; j++) {
                if (DaLiSuPodudarni(*v[i],*v[j])) {
                    if (flag) {
                        std::cout << "Parovi podudarnih trouglova:" << std::endl;
                        flag = false;
                    }
                    v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi(); std::cout  << std::endl;
                }
            }
        }
        if (flag) std::cout << "Nema podudarnih trouglova!" << std::endl;
    }
    flag = true;
    if (v.empty()) std::cout << "Nema slicnih trouglova!" << std::endl;
    else {
        for (int i = 0; i < v.size()-1; i++) {
            for (int j = i+1; j <v.size() ; j++) {
                if (DaLiSuSlicni(*v[i],*v[j])) {
                    if (flag) {
                        std::cout << "Parovi slicnih trouglova:" << std::endl;
                        flag = false;
                    }
                    v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi(); std::cout  << std::endl;
                }
            }
        }
        if (flag) std::cout << "Nema slicnih trouglova!" << std::endl;
    }
    return 0;
}