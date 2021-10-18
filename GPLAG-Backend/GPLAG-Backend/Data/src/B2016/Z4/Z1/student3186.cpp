//B 2016/2017, Zadaća 4, Zadatak 1
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <cmath>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    static double RotacijaIzraz     (const Tacka &t1, const Tacka &t2, const Tacka &t3);            // [vol 0]
    static double RazlikaDvijeTacke (const Tacka &t1, const Tacka &t2);                             // [vol I]
    double UgaoTacke                (const double &a, const double &b, const double &c) const;      // [vol II]
    double RazlikaDvaBroja          (double x, double y) const { return std::fabs(x - y); }         // [vol III]
    Tacka RotirajOkoTacke           (const Tacka &t, const Tacka &tc, double ugao) const;           // [vol IV]
    Tacka SkalirajTacku             (const Tacka &t, const Tacka &tc, double faktor_skal) const;    // [vol V]
    static bool JesuLiJednaki       (double x, double y, double Eps = 1e-10) {                      // [vol VI]
                                    return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y)); }
    static bool JesuTackeJednake    (const Tacka &x, const Tacka &y);                               // [vol VII]
    static double Maksimalna_strana (const double &x, const double &y, const double &z);            // [vol VIII]
public:
// Konstruktor i postavljacke funkcije clanice..
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1,t2,t3); }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (int indeks, const Tacka &t);
// Orijentacija 1 za anti-clockwise -1 za clockwise i 0 ako je kolinearna..
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (RotacijaIzraz(t1, t2, t3) > 0)   return 1;   else if (RotacijaIzraz(t1,t2,t3) < 0)  return -1;  else return 0;
    }
// Povratne funkcije clanice..   
    Tacka DajTjeme (int indeks) const { 
        if (indeks == 1) return t1; else if (indeks == 2) return t2; else if (indeks == 3) return t3; 
        else throw std::range_error ("Nekorektan indeks");
    }
    double DajStranicu (int indeks) const {
        if      (indeks == 1)   return RazlikaDvijeTacke(t2, t3);
        else if (indeks == 2)   return RazlikaDvijeTacke(t1, t3);
        else if (indeks == 3)   return RazlikaDvijeTacke(t1, t2);
        else throw std::range_error ("Nekorektan indeks");
    }
    double DajUgao (int indeks) const {
        double a{0}, b{0}, c{0};    // c -> je nasuprot trazenog tjemena koji mora biti "-" unutar [vol II]
        if      (indeks == 1)   c = RazlikaDvijeTacke(t2, t3), a = RazlikaDvijeTacke(t1, t2), b = RazlikaDvijeTacke(t1, t3);
        else if (indeks == 2)   c = RazlikaDvijeTacke(t1, t3), a = RazlikaDvijeTacke(t1, t2), b = RazlikaDvijeTacke(t2, t3);
        else if (indeks == 3)   c = RazlikaDvijeTacke(t1, t2), a = RazlikaDvijeTacke(t1, t3), b = RazlikaDvijeTacke(t2, t3);
        else throw std::range_error ("Nekorektan indeks");  return UgaoTacke(a,b,c);
    }
    Tacka DajCentar()    const { return { {(t1.first + t2.first + t3.first)/3}, {(t1.second + t2.second + t3.second)/3} };  }
    double DajObim()     const { return RazlikaDvijeTacke(t1, t2) + RazlikaDvijeTacke(t2, t3) + RazlikaDvijeTacke(t1, t3);  }
    double DajPovrsinu() const { return (std::fabs(RotacijaIzraz(t1, t2, t3)) * 1./2);                                      }
// Buleana dva..
    bool DaLiJePozitivnoOrijentiran() const {   if (Orijentacija(t1, t2, t3) == 1) return true;     else return false;      }
    bool DaLiJeUnutra(const Tacka &t) const;
// Output (std::cout) funkcija..
    void Ispisi() const { // x1                 y1                    x2                 y2                    x3                 y3
        std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
        std::cout << std::endl; // Novi red ..
    }
// Translacije, rotacije i skalirancije (potrebno patentirati rijec)..
    void Transliraj (double delta_x, double delta_y) {
        Trougao::t1.first += delta_x;   Trougao::t2.first += delta_x;   Trougao::t3.first += delta_x;
        Trougao::t1.second += delta_y;  Trougao::t2.second += delta_y;  Trougao::t3.second += delta_y;
    }
    void Centriraj (const Tacka &t) {
        double delta_x { RazlikaDvaBroja (t.first, DajCentar().first) };
        double delta_y { RazlikaDvaBroja (t.second, DajCentar().second) };
        Transliraj (delta_x, delta_y);
    }
    void Rotiraj (const Tacka &t, double ugao) {
        Trougao::t1 = RotirajOkoTacke (Trougao::t1, t, ugao);
        Trougao::t2 = RotirajOkoTacke (Trougao::t2, t, ugao);
        Trougao::t3 = RotirajOkoTacke (Trougao::t3, t, ugao);
    }
    void Skaliraj (const Tacka &t, double faktor) {
        if (JesuLiJednaki(faktor, 0)) throw std::domain_error ("Nekorektan faktor skaliranja");
        Trougao::t1 = SkalirajTacku (Trougao::t1, t, faktor);
        Trougao::t2 = SkalirajTacku (Trougao::t2, t, faktor);
        Trougao::t3 = SkalirajTacku (Trougao::t3, t, faktor);
    }
    void Rotiraj (double ugao) {
        Tacka Pocetno_Teziste {DajCentar()};
        Trougao::t1 = RotirajOkoTacke (Trougao::t1, Pocetno_Teziste, ugao);
        Trougao::t2 = RotirajOkoTacke (Trougao::t2, Pocetno_Teziste, ugao);
        Trougao::t3 = RotirajOkoTacke (Trougao::t3, Pocetno_Teziste, ugao);
    }
    void Skaliraj (double faktor) {
        if (JesuLiJednaki(faktor, 0)) throw std::domain_error ("Nekorektan faktor skaliranja");
        Tacka Pocetno_Teziste {DajCentar()};
        Trougao::t1 = SkalirajTacku (Trougao::t1, Pocetno_Teziste, faktor);
        Trougao::t2 = SkalirajTacku (Trougao::t2, Pocetno_Teziste, faktor);
        Trougao::t3 = SkalirajTacku (Trougao::t3, Pocetno_Teziste, faktor);
    }
// Frendovske funkcijice !!
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni    (const Trougao &t1, const Trougao &t2);
};                                                      /*** END KLASE ***/

// Privatna pomocna funkcija vol 0, izraz za rotaciju [vol 0]..
double Trougao::RotacijaIzraz (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return {t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second)};
}

// Privatna pomocna funkcija vol I, bez prespore "pow" funkcije..
double Trougao::RazlikaDvijeTacke (const Tacka &t1, const Tacka &t2) {
    return std::sqrt( ((t2.first - t1.first)*(t2.first - t1.first)) + ((t2.second - t1.second)*(t2.second - t1.second)) );
}

// Privatna pomocna funkcija vol II, za racunanje ugla tjemena na osnovu stranica ili (kosinusne teoreme)..
double Trougao::UgaoTacke (const double &a, const double &b, const double &c) const {
    return std::acos((a*a + b*b - c*c)/(2*a*b));
}

// Privatna pomocna funkcija vol IV, za izraz rotacije okolo neke nove tacke ..
Tacka Trougao::RotirajOkoTacke (const Tacka &t, const Tacka &tc, double ugao) const {
    return {(tc.first+(t.first-tc.first)*std::cos(ugao)-(t.second-tc.second)*std::sin(ugao))
    , (tc.second+(t.first-tc.first)*std::sin(ugao)+(t.second-tc.second)*std::cos(ugao))};
}   // xc + (x - xc) * cos(alfa) - (y - yc) * sin(alfa) <----> y + (x - xc) * sin(alfa) + (y - yc) * cos(alfa) Provjera..

// Privatna pomocna funkcija vol V
Tacka Trougao::SkalirajTacku (const Tacka &t, const Tacka &tc, double faktor_skal) const {
    return {{tc.first + faktor_skal*(t.first-tc.first)}, {tc.second + faktor_skal*(t.second-tc.second)}};
}   // xc + k*(x-xc) , yc + k*(y-yc) .. Provjera..

// Privatna pomocna funkcija vol VII
bool Trougao::JesuTackeJednake (const Tacka &t1, const Tacka &t2) {
    if (JesuLiJednaki(t1.first, t2.first) and JesuLiJednaki(t1.second, t2.second))  return true; else return false;
}

// Privatna pomocna funkcija vol VIII
double Trougao::Maksimalna_strana (const double &x, const double &y, const double &z) {
    if ((x > y or JesuLiJednaki(x,y)) and (x > z or JesuLiJednaki(x,z)))        return x;
    else if ((y > x or JesuLiJednaki(y,x)) and (y > z or JesuLiJednaki(y,z)))   return y;
    else if ((z > x or JesuLiJednaki(z,x)) and (z > y or JesuLiJednaki(z,y)))   return z;   else return x;
}

                                                /*** PROŠIRENE JAVNE FUNKCIJE ***/

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) { // Postavljacka I ..
    if (Orijentacija(t1, t2, t3) == 0)   throw std::domain_error ("Nekorektne pozicije tjemena");
    Trougao::t1 = t1;   Trougao::t2 = t2;   Trougao::t3 = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t) { // Postavljacka II ..
    if (indeks == 1) {
        if (Orijentacija(t, t2, t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");  else Trougao::t1 = t;
    }   else if (indeks == 2) {
        if (Orijentacija(t1, t, t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");  else Trougao::t2 = t;
    }   else if (indeks == 3)   {
        if (Orijentacija(t1, t2 , t)== 0) throw std::domain_error ("Nekorektne pozicije tjemena");  else Trougao::t3 = t;
    }   else throw std::range_error ("Nekorektan indeks");
}

// Bulean drugi..
bool Trougao::DaLiJeUnutra (const Tacka &t) const {
    if (RotacijaIzraz(t1, t2, t)>0 and RotacijaIzraz(t2, t3, t)>0 and RotacijaIzraz(t3, t1, t)>0 and DaLiJePozitivnoOrijentiran())       return true;
    else if (RotacijaIzraz(t1,t2,t)<0 and RotacijaIzraz(t2,t3,t)<0 and RotacijaIzraz(t3,t1,t)<0 and DaLiJePozitivnoOrijentiran()==false) return true;
    else return false;
}
                                                    /*** FRIEND FUNKCIJICE ***/
                                
bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
    // clockwise trouglovi .. 3! = 6 permutacija (ili varijanti za jedan trougao) ..
    if (Trougao::JesuTackeJednake(t1.t1, t2.t1) and Trougao::JesuTackeJednake(t1.t2, t2.t3) and Trougao::JesuTackeJednake(t1.t3, t2.t2)) return true;
    if (Trougao::JesuTackeJednake(t1.t1, t2.t2) and Trougao::JesuTackeJednake(t1.t2, t2.t1) and Trougao::JesuTackeJednake(t1.t3, t2.t3)) return true;
    if (Trougao::JesuTackeJednake(t1.t1, t2.t3) and Trougao::JesuTackeJednake(t1.t2, t2.t2) and Trougao::JesuTackeJednake(t1.t3, t2.t1)) return true;
    // anti-clockwise trouglovi ..
    if (Trougao::JesuTackeJednake(t1.t1, t2.t1) and Trougao::JesuTackeJednake(t1.t2, t2.t2) and Trougao::JesuTackeJednake(t1.t3, t2.t3)) return true;
    if (Trougao::JesuTackeJednake(t1.t1, t2.t2) and Trougao::JesuTackeJednake(t1.t2, t2.t3) and Trougao::JesuTackeJednake(t1.t3, t2.t1)) return true;
    if (Trougao::JesuTackeJednake(t1.t1, t2.t3) and Trougao::JesuTackeJednake(t1.t2, t2.t1) and Trougao::JesuTackeJednake(t1.t3, t2.t2)) return true;
    // else vrati false ..
    return false;
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
    // stranice prvog ugla ..
    double T1stranica1 = {  t1.DajStranicu(1) }, T1stranica2 = {  t1.DajStranicu(2) }, T1stranica3 = {  t1.DajStranicu(3) };
    // stranice drugog ugla ..
    double T2stranica1 = {  t2.DajStranicu(1) }, T2stranica2 = {  t2.DajStranicu(2) }, T2stranica3 = {  t2.DajStranicu(3) };
    // anti-clockwise trouglovi .. 3! = 6 permutacija ..
    if((Trougao::JesuLiJednaki(T1stranica1, T2stranica1) and Trougao::JesuLiJednaki(T1stranica2, T2stranica2) and Trougao::JesuLiJednaki(T1stranica3, T2stranica3))
    or (Trougao::JesuLiJednaki(T1stranica1, T2stranica2) and Trougao::JesuLiJednaki(T1stranica2, T2stranica3) and Trougao::JesuLiJednaki(T1stranica3, T2stranica1))
    or (Trougao::JesuLiJednaki(T1stranica1, T2stranica3) and Trougao::JesuLiJednaki(T1stranica2, T2stranica1) and Trougao::JesuLiJednaki(T1stranica3, T2stranica2))
    or (Trougao::JesuLiJednaki(T1stranica1, T2stranica1) and Trougao::JesuLiJednaki(T1stranica2, T2stranica3) and Trougao::JesuLiJednaki(T1stranica3, T2stranica2))
    or (Trougao::JesuLiJednaki(T1stranica1, T2stranica2) and Trougao::JesuLiJednaki(T1stranica2, T2stranica1) and Trougao::JesuLiJednaki(T1stranica3, T2stranica3))
    or(Trougao::JesuLiJednaki(T1stranica1, T2stranica3) and Trougao::JesuLiJednaki(T1stranica2, T2stranica2) and Trougao::JesuLiJednaki(T1stranica3, T2stranica1)))
    {
        if (DaLiSuIdenticni(t1, t2))   return true;
        Trougao temp{{t1.DajTjeme(1).first, t1.DajTjeme(1).second}, {t1.DajTjeme(2).first, t1.DajTjeme(2).second}, {t1.DajTjeme(3).first, t1.DajTjeme(3).second}};
        double delta_x{t2.DajCentar().first - temp.DajCentar().first}; double delta_y{t2.DajCentar().second - temp.DajCentar().second}; temp.Transliraj(delta_x, delta_y);  
        double max_strana1 { Trougao::Maksimalna_strana(T1stranica1, T1stranica2, T1stranica3) };
        double max_strana2 { Trougao::Maksimalna_strana(T2stranica1, T2stranica2, T2stranica3) };
        // Tacke spojnice max_strane1 od temp-a
        Tacka temp_a; Tacka temp_b;
        if (temp.DaLiJePozitivnoOrijentiran()) {
            if      (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(temp.t1, temp.t2), max_strana1)) temp_a = temp.t1, temp_b = temp.t2;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(temp.t2, temp.t3), max_strana1)) temp_a = temp.t2, temp_b = temp.t3;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(temp.t3, temp.t1), max_strana1)) temp_a = temp.t3, temp_b = temp.t1;
        }   else {
            if      (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(temp.t3, temp.t2), max_strana1)) temp_a = temp.t3, temp_b = temp.t2;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(temp.t2, temp.t1), max_strana1)) temp_a = temp.t2, temp_b = temp.t1;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(temp.t1, temp.t3), max_strana1)) temp_a = temp.t1, temp_b = temp.t3;
        }
        // Tacke spojnice max_strane2 od t2-a
        Tacka t2_a; Tacka t2_b;
        if (t2.DaLiJePozitivnoOrijentiran()) {
            if      (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(t2.t1, t2.t2), max_strana2))     t2_a = t2.t1, t2_b = t2.t2;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(t2.t2, t2.t3), max_strana2))     t2_a = t2.t2, t2_b = t2.t3;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(t2.t3, t2.t1), max_strana2))     t2_a = t2.t3, t2_b = t2.t1;
        }   else {
            if      (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(t2.t3, t2.t2), max_strana2))     t2_a = t2.t3, t2_b = t2.t2;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(t2.t2, t2.t1), max_strana2))     t2_a = t2.t2, t2_b = t2.t1;
            else if (Trougao::JesuLiJednaki(Trougao::RazlikaDvijeTacke(t2.t1, t2.t3), max_strana2))     t2_a = t2.t1, t2_b = t2.t3;
        }
        double k1 {(temp_b.second - temp_a.second)/(temp_b.first - temp_a.first)};
        double k2 {(t2_b.second - t2_a.second)/(t2_b.first - t2_a.first)};
        double alfa { std::atan((k2-k1)/(1+k1*k2)) };   temp.Rotiraj(alfa);
        if (DaLiSuIdenticni(temp, t2))  return true;
    }   return false;
}

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
    if (DaLiSuPodudarni(t1, t2)) return true;
    double max_strana1 { Trougao::Maksimalna_strana(t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)) };
    double max_strana2 { Trougao::Maksimalna_strana(t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)) };
    double omjer { max_strana2/max_strana1 };
    Trougao temp{{t1.DajTjeme(1).first, t1.DajTjeme(1).second}, {t1.DajTjeme(2).first, t1.DajTjeme(2).second}, {t1.DajTjeme(3).first, t1.DajTjeme(3).second}};
    temp.Skaliraj(omjer);   if (DaLiSuPodudarni(temp, t2))  return true;    else return false;
}

void IspisiMeSuzoIzdajice (const std::pair<Trougao, Trougao> &vek_par) {
    // Prvi trougaocic
    std::cout << "((" << vek_par.first.DajTjeme(1).first << "," << vek_par.first.DajTjeme(1).second << "),(";
    std::cout << vek_par.first.DajTjeme(2).first << "," << vek_par.first.DajTjeme(2).second << "),(";
    std::cout << vek_par.first.DajTjeme(3).first << "," << vek_par.first.DajTjeme(3).second << "))";
    // Drugi trougaocic
    std::cout << " i ((" << vek_par.second.DajTjeme(1).first << "," << vek_par.second.DajTjeme(1).second << "),(";
    std::cout << vek_par.second.DajTjeme(2).first << "," << vek_par.second.DajTjeme(2).second << "),(";
    std::cout << vek_par.second.DajTjeme(3).first << "," << vek_par.second.DajTjeme(3).second << "))" << std::endl;
}

int main ()
{
    try {
        int br_trouglova(0);
        std::cout << "Koliko zelite kreirati trouglova: ";
        std::cin >> br_trouglova;
    
        std::vector<std::shared_ptr<Trougao>> vek_trouglova;
        for (int i=0; i<br_trouglova; ++i) {
            Tacka t1, t2, t3;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second;
            try {
                auto smart_pointer (std::make_shared<Trougao> (t1, t2, t3));
                vek_trouglova.push_back (smart_pointer);
            }   catch (std::domain_error txt) {
                std::cout << txt.what() << ", ponovite unos!" << std::endl;
                --i;    }
        }
    
        double delta_x, delta_y;
        std::cout << "Unesite vektor translacije (dx dy): ";
        std::cin >> delta_x >> delta_y;
        
        double ugao_rotacije;
        std::cout << "Unesite ugao rotacije: ";
        std::cin >> ugao_rotacije;
    
        double faktor_skaliranja;
        std::cout << "Unesite faktor skaliranja: ";
        std::cin >> faktor_skaliranja;
    
        std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
        std::transform (vek_trouglova.begin(), vek_trouglova.end(), vek_trouglova.begin(),
                        [delta_x, delta_y] (std::shared_ptr<Trougao> pametni_pok) {  pametni_pok->Transliraj(delta_x, delta_y); return pametni_pok; });
        std::transform (vek_trouglova.begin(), vek_trouglova.end(), vek_trouglova.begin(),
                        [ugao_rotacije] (std::shared_ptr<Trougao> pametni_pok) {     pametni_pok->Rotiraj(ugao_rotacije);       return pametni_pok; });
        std::transform (vek_trouglova.begin(), vek_trouglova.end(), vek_trouglova.begin(),
                        [faktor_skaliranja] (std::shared_ptr<Trougao> pametni_pok) { 
                                                            pametni_pok->Skaliraj(pametni_pok->DajTjeme(1), faktor_skaliranja); return pametni_pok; });
        std::sort (vek_trouglova.begin(), vek_trouglova.end(), 
                        [] (std::shared_ptr<Trougao> pp1, std::shared_ptr<Trougao> pp2) -> bool { return (pp1->DajPovrsinu() < pp2->DajPovrsinu()); });
        std::for_each (vek_trouglova.begin(), vek_trouglova.end(), [] (std::shared_ptr<Trougao> pametni_pok) {    return pametni_pok->Ispisi();     });
        auto min_obim = *std::min_element (vek_trouglova.begin(), vek_trouglova.end(),
                        [] (std::shared_ptr<Trougao> pp1, std::shared_ptr<Trougao> pp2) -> bool { return (pp1->DajObim() < pp2->DajObim());         });
        std::cout << "Trougao sa najmanjim obimom: "; min_obim->Ispisi();   
    
        {
            std::vector<std::pair<Trougao, Trougao>> parovi_identicnih;
            std::vector<std::pair<Trougao, Trougao>> parovi_podudarnih;
            std::vector<std::pair<Trougao, Trougao>> parovi_slicnih;
            for (int i=0; i < vek_trouglova.size(); ++i) {
                for (int j=i; j < vek_trouglova.size()-1; ++j) {
                    if (DaLiSuIdenticni({vek_trouglova[i]->DajTjeme(1), vek_trouglova[i]->DajTjeme(2), vek_trouglova[i]->DajTjeme(3)}
                    , {vek_trouglova[j+1]->DajTjeme(1), vek_trouglova[j+1]->DajTjeme(2), vek_trouglova[j+1]->DajTjeme(3)})) {
                        parovi_identicnih.push_back({{vek_trouglova[i]->DajTjeme(1), vek_trouglova[i]->DajTjeme(2), vek_trouglova[i]->DajTjeme(3)}
                        , {vek_trouglova[j+1]->DajTjeme(1), vek_trouglova[j+1]->DajTjeme(2), vek_trouglova[j+1]->DajTjeme(3)}});
                    }
                    if (DaLiSuPodudarni({vek_trouglova[i]->DajTjeme(1), vek_trouglova[i]->DajTjeme(2), vek_trouglova[i]->DajTjeme(3)}
                    , {vek_trouglova[j+1]->DajTjeme(1), vek_trouglova[j+1]->DajTjeme(2), vek_trouglova[j+1]->DajTjeme(3)})) {
                        parovi_podudarnih.push_back({{vek_trouglova[i]->DajTjeme(1), vek_trouglova[i]->DajTjeme(2), vek_trouglova[i]->DajTjeme(3)}
                        , {vek_trouglova[j+1]->DajTjeme(1), vek_trouglova[j+1]->DajTjeme(2), vek_trouglova[j+1]->DajTjeme(3)}});
                    }
                    if (DaLiSuSlicni({vek_trouglova[i]->DajTjeme(1), vek_trouglova[i]->DajTjeme(2), vek_trouglova[i]->DajTjeme(3)}
                    , {vek_trouglova[j+1]->DajTjeme(1), vek_trouglova[j+1]->DajTjeme(2), vek_trouglova[j+1]->DajTjeme(3)})) {
                        parovi_slicnih.push_back({{vek_trouglova[i]->DajTjeme(1), vek_trouglova[i]->DajTjeme(2), vek_trouglova[i]->DajTjeme(3)}
                        , {vek_trouglova[j+1]->DajTjeme(1), vek_trouglova[j+1]->DajTjeme(2), vek_trouglova[j+1]->DajTjeme(3)}});
                    }
                }
            }
            if (parovi_identicnih.size() > 0) {
                std::cout << "Parovi identicnih trouglova:" << std::endl;
                for (auto i=0; i<parovi_identicnih.size(); ++i)
                    IspisiMeSuzoIzdajice(parovi_identicnih[i]);
            }   else    std::cout << "Nema identicnih trouglova!" << std::endl;
            if (parovi_identicnih.size() > 0) {
                std::cout << "Parovi podudarnih trouglova:" << std::endl;
                for (auto i=0; i<parovi_podudarnih.size(); ++i)
                    IspisiMeSuzoIzdajice(parovi_podudarnih[i]);
            }   else    std::cout << "Nema podudarnih trouglova!" << std::endl;
            if (parovi_slicnih.size() > 0) {
                std::cout << "Parovi slicnih trouglova:" << std::endl;
                for (auto i=0; i<parovi_slicnih.size(); ++i)
                    IspisiMeSuzoIzdajice(parovi_slicnih[i]);
            }   else    std::cout << "Nema slicnih trouglova!" << std::endl;
        }   //  std::cout << std::boolalpha << DaLiSuIdenticni(neki, drugi) << std::endl;
    }   catch (std::bad_alloc()) {}
}