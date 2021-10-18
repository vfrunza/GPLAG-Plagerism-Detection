/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

typedef std::pair<double, double> Tacka;

bool DaLiSuKolinaerne(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return ((t1.first*t2.second + t2.first*t3.second + t3.first*t1.second)-(t2.first*t1.second + t3.first*t2.second + t1.first*t3.second))/2;
}

double DajDuzinu(const Tacka &t1, const Tacka &t2) {
    return sqrt((t1.first-t2.first)*(t1.first-t2.first) + (t1.second - t2.second)*(t1.second - t2.second));
}


class Trougao {
Tacka t1, t2, t3;

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

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (DaLiSuKolinaerne(t1, t2, t3)) throw std::domain_error ("Nekorektne pozicije tjemena");
     Trougao::t1.first = t1.first;
     Trougao::t1.second = t1.second;
     Trougao::t2.first = t2.first;
     Trougao::t2.second = t2.second;
     Trougao::t3.first = t3.first;
     Trougao::t3.second = t3.second;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (DaLiSuKolinaerne(t1, t2, t3)) throw std::domain_error ("Nekorektne pozicije tjemena");
     Trougao::t1.first = t1.first;
     Trougao::t1.second = t1.second;
     Trougao::t2.first = t2.first;
     Trougao::t2.second = t2.second;
     Trougao::t3.first = t3.first;
     Trougao::t3.second = t3.second;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks > 3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) {   Trougao::t1.first = t.first;     Trougao::t1.second = t.second;}
    if(indeks == 2) {   Trougao::t2.first = t.first;     Trougao::t2.second = t.second;}
    if(indeks == 3) {   Trougao::t3.first = t.first;     Trougao::t3.second = t.second;}
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return (t1.first*(t1.second - t2.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second - t2.second));
}

Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks > 3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) return t1;
    if(indeks == 2) return t2;
    if(indeks == 3) return t3;
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks > 3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) return (sqrt((t3.first-t2.first)*(t3.first-t2.first) + (t3.second-t2.second)*(t3.second-t2.second)));
    if(indeks == 2) return (sqrt((t3.first-t1.first)*(t3.first-t1.first) + (t3.second-t1.second)*(t3.second-t1.second)));
    if(indeks == 3) return (sqrt((t2.first-t1.first)*(t2.first-t1.first) + (t2.second-t1.second)*(t2.second-t1.second)));
}

double Trougao::DajUgao(int indeks) const {
    if(indeks > 3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) return acos((DajDuzinu(t1, t3)*DajDuzinu(t1, t3)+DajDuzinu(t1, t2)*DajDuzinu(t1, t2)-DajDuzinu(t2, t3)*DajDuzinu(t2, t3))/2*(DajDuzinu(t1, t3)*DajDuzinu(t1, t2)));
    if(indeks == 2) return acos((DajDuzinu(t2, t3)*DajDuzinu(t2, t3)+DajDuzinu(t1, t2)*DajDuzinu(t1, t2)-DajDuzinu(t1, t3)*DajDuzinu(t1, t3))/2*(DajDuzinu(t2, t3)*DajDuzinu(t1, t2)));
    if(indeks == 3) return acos((DajDuzinu(t2, t3)*DajDuzinu(t2, t3)+DajDuzinu(t1, t3)*DajDuzinu(t1, t3)-DajDuzinu(t1, t2)*DajDuzinu(t1, t2))/2*(DajDuzinu(t2, t3)*DajDuzinu(t1, t3)));
}

Tacka Trougao::DajCentar() const {
    return std::make_pair((t1.first + t2.first + t3.first)/3, (t1.second + t2.second + t3.second)/3);
}

double Trougao::DajObim() const {
    return (DajDuzinu(t1, t2) + DajDuzinu(t2, t3) + DajDuzinu(t3, t1));
}

double Trougao::DajPovrsinu() const {
    double s=DajObim()/2;
    return sqrt(s*(s-DajDuzinu(t2,t3))*(s-DajDuzinu(t3,t1))*(s-DajDuzinu(t1,t2)));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    return (Orijentacija(t1, t2, t3));
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    return (t.first == t1.first && t.second==t1.second);
    return (t.first == t2.first && t.second==t2.second);
    return (t.first == t3.first && t.second==t3.second);
    return (!Orijentacija(t,t2,t3));
    return (!Orijentacija(t1,t,t3));
    return (!Orijentacija(t1,t2,t));
}

void Trougao::Ispisi() const {
    std::cout <<"((" <<t1.first <<"," <<t1.second <<"),("<<t2.first<<"," <<t2.second <<"),(" <<t3.first <<"," <<t3.second <<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first +=delta_x; t1.second +=delta_y;
    t2.first +=delta_x; t2.second +=delta_y;
    t3.first +=delta_x; t3.second +=delta_y;
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    t1.first = t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao);
    t1.second = t.second + (t1.first - t.first)*sin(ugao) + (t1.second - t.second)*cos(ugao);
    t2.first = t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao);
    t2.second = t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao);
    t3.first = t.first + (t3.first - t.first)*cos(ugao) - (t3.second - t.second)*sin(ugao);
    t3.second = t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(faktor == 0) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first = t.first + faktor*(t1.first - t.first);
    t1.second = t.second + faktor*(t1.second - t.second);
    t2.first = t.first + faktor*(t2.first - t.first);
    t2.second = t.second + faktor*(t2.second - t.second);
    t3.first = t.first + faktor*(t3.first - t.first);
    t3.second = t.second + faktor*(t3.second - t.second);
}

// DODATi Funkciju SKALIRAJ S JEDNIM PARAMETROM
void Trougao::Rotiraj(double ugao) {
    auto t (DajCentar());
    t1.first = t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao);
    t1.second = t.second + (t1.first - t.first)*sin(ugao) + (t1.second - t.second)*cos(ugao);
    t2.first = t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao);
    t2.second = t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao);
    t3.first = t.first + (t3.first - t.first)*cos(ugao) - (t3.second - t.second)*sin(ugao);
    t3.second = t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao);
}
// DODATi Funkciju ROTIRAJ S JEDNIM PARAMETROM
void Trougao::Skaliraj(double faktor) {
    auto t (DajCentar());
    if(faktor == 0) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first = t.first + faktor*(t1.first - t.first);
    t1.second = t.second + faktor*(t1.second - t.second);
    t2.first = t.first + faktor*(t2.first - t.first);
    t2.second = t.second + faktor*(t2.second - t.second);
    t3.first = t.first + faktor*(t3.first - t.first);
    t3.second = t.second + faktor*(t3.second - t.second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if(((t1.DajTjeme(1).first == t2.DajTjeme(1).first && t1.DajTjeme(1).second == t2.DajTjeme(1).second)||(t1.DajTjeme(1).first == t2.DajTjeme(2).first && t1.DajTjeme(1).second == t2.DajTjeme(2).second)||(t1.DajTjeme(1).first == t2.DajTjeme(3).first && t1.DajTjeme(1).second == t2.DajTjeme(3).second))&&((t1.DajTjeme(2).first == t2.DajTjeme(1).first && t1.DajTjeme(2).second == t2.DajTjeme(1).second)||(t1.DajTjeme(2).first == t2.DajTjeme(2).first && t1.DajTjeme(2).second == t2.DajTjeme(2).second)||(t1.DajTjeme(2).first == t2.DajTjeme(3).first && t1.DajTjeme(2).second == t2.DajTjeme(3).second))&&((t1.DajTjeme(3).first == t2.DajTjeme(1).first && t1.DajTjeme(3).second == t2.DajTjeme(1).second)||(t1.DajTjeme(3).first == t2.DajTjeme(2).first && t1.DajTjeme(3).second == t2.DajTjeme(2).second)||(t1.DajTjeme(3).first == t2.DajTjeme(3).first && t1.DajTjeme(3).second == t2.DajTjeme(3).second))) return true;
}

//bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) 

int main ()
{
    std::cout << "RADI";
	return 0;
}