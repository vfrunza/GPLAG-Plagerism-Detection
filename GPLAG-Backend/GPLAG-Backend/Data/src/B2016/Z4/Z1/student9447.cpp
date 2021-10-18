/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <new>
#include <initializer_list>

typedef std::pair<double, double> Tacka;

const double PI(4 * std::atan(1));
const double eps(1e-10);

class Trougao {
    Tacka a, b, c;  // tjemena trougla
    Tacka centar;
    static double Pomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3) {   // pomocna f-ja
        double temp = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
        return temp;
    }
    static bool Uporedi(double pom1, double pom2) {   // samo ako poredimo po jednakosti
        return std::fabs(pom1 - pom2) <= eps * (std::fabs(pom1) + std::fabs(pom2));
    }
    static bool UporediTjeme(const Tacka &t1, const Tacka &t2) {
        return (Trougao::Uporedi(t1.first, t2.first) && Trougao::Uporedi(t1.second, t2.second));
    }
public: 
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(int indeks, const Tacka &t);
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {   // vraca 1 ako je orijentacija pozitivna
    if(Pomocna(t1, t2, t3) > 0) return 1;
    else if(Pomocna(t1, t2, t3) < 0) return -1;
    else return 0;
}
Tacka  DajTjeme(int indeks) const;
double DajStranicu(int indeks) const;
double DajUgao(int indeks) const;
Tacka DajCentar() const {
    return centar;
}
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
    
};                                                                                 // t.first -- x koordinata tacke, t.second -- y koo. tacke t

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(std::fabs(Orijentacija(t1, t2, t3)) <= eps) throw std::domain_error("Nekorektne pozicije tjemena");   // sva tri tjemena se nalaze na istom pravcu
    
    a.first = t1.first; a.second = t1.second;   // a, b, c tacke atributi klase
    b.first = t2.first; b.second = t2.second;
    c.first = t3.first; c.second = t3.second;
    centar.first = (t1.first + t2.first + t3.first) / 3;
    centar.second = (t1.second + t2.second + t3.second) / 3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(std::fabs(Orijentacija(t1, t2, t3)) <= eps) throw std::domain_error("Nekorektne pozicije tjemena");
    
    a.first = t1.first; a.second = t1.second;
    b.first = t2.first; b.second = t2.second;
    c.first = t3.first; c.second = t3.second;
    centar.first = (t1.first + t2.first + t3.first) / 3;
    centar.second = (t1.second + t2.second + t3.second) / 3;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
    
    if(indeks == 1) {
        a.first = t.first; a.second = t.second;
    }
    else if(indeks == 2) {
        b.first = t.first; b.second = t.second;
    }
    else if(indeks == 3) {
        c.first = t.first; c.second = t.second;
    }
    if(std::fabs(Orijentacija(this->a, this->b, this->c)) <= eps) throw std::domain_error("Nekorektne pozicije tjemena");
}

Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
    
    Tacka tjeme;
    
    if(indeks == 1) {
        tjeme.first = a.first;
        tjeme.second = a.second;
    }
    else if(indeks == 2) {
        tjeme.first = b.first;
        tjeme.second = b.second;
    }
    else if(indeks == 3) {
        tjeme.first = c.first;
        tjeme.second = c.second;
    }
    return tjeme;
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
    
    double duzina(0);
    if(indeks == 1) {
        duzina = std::sqrt((b.first - c.first) * (b.first - c.first) + (b.second - c.second) * (b.second - c.second));
    }
    else if(indeks == 2) {
        duzina = std::sqrt((a.first - c.first) * (a.first - c.first) + (a.second - c.second) * (a.second - c.second));
    }
    else if(indeks == 3) {
        duzina = std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    }
    return duzina;
}

double Trougao::DajUgao(int indeks) const {
    if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
    double ugao(0);
    if(indeks == 1) {
        ugao = std::acos((DajStranicu(2) * DajStranicu(2) + DajStranicu(3) * DajStranicu(3) - DajStranicu(1) * DajStranicu(1)) / (2 * DajStranicu(2) * DajStranicu(3)));
    }
    else if(indeks == 2) {
        ugao = std::acos((DajStranicu(3) * DajStranicu(3) + DajStranicu(1) * DajStranicu(1) - DajStranicu(2) * DajStranicu(2)) / (2 * DajStranicu(3) * DajStranicu(1)));
    }
    else if(indeks == 3) {
        ugao = std::acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(2) * DajStranicu(2) - DajStranicu(3) * DajStranicu(3)) / (2 * DajStranicu(1) * DajStranicu(2)));
    }
    return ugao;
}

double Trougao::DajObim() const {
    return (DajStranicu(1) + DajStranicu(2) + DajStranicu(3));
}

double Trougao::DajPovrsinu() const {
    double s = DajObim() / 2;
    return (std::sqrt(s * (s - DajStranicu(1)) * (s - DajStranicu(2)) * (s - DajStranicu(3))));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if(Pomocna(this->a, this->b, this->c) > 0) return true;
    return false;
}
/*
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    
} */

void Trougao::Ispisi() const {
    std::cout << "((" << a.first << "," << a.second << "),(" << b.first << "," << b.second << "),(" << c.first << "," << c.second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    a.first += delta_x;
    a.second += delta_y;
    b.first += delta_x;
    b.second += delta_y;
    c.first += delta_x;
    c.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
    centar.first = t.first;
    centar.second = t.second;
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    double temp1, temp2;
    temp1 = t.first + (a.first - t.first) * std::cos(ugao) - (a.second - t.second) * std::sin(ugao);
    temp2  = t.second + (a.first - t.first) * std::sin(ugao) + (a.second - t.second) * std::cos(ugao);
    a.first = temp1;
    a.second = temp2;
    temp1 = t.first + (b.first - t.first) * std::cos(ugao) - (b.second - t.second) * std::sin(ugao);
    temp2 = t.second + (b.first - t.first) * std::sin(ugao) + (b.second - t.second) * std::cos(ugao);
    b.first = temp1;
    b.second = temp2;
    temp1 = t.first + (c.first - t.first) * std::cos(ugao) - (c.second - t.second) * std::sin(ugao);
    temp2 = t.second + (c.first - t.first) * std::sin(ugao) + (c.second - t.second) * std::cos(ugao);
    c.first = temp1;
    c.second = temp2;
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(std::fabs(faktor) <= eps) throw std::domain_error("Nekorektan faktor skaliranja");
    
    a.first = t.first + faktor * (a.first - t.first);
    a.second = t.second + faktor * (a.second - t.second);
    b.first = t.first + faktor * (b.first - t.first);
    b.second = t.second + faktor * (b.second - t.second);
    c.first = t.first + faktor * (c.first - t.first);
    c.second = t.second + faktor * (c.second - t.second);
    
    if(faktor < 0) this->Rotiraj(t, 180);
    
}

void Trougao::Rotiraj(double ugao) {
    double temp1, temp2;
    temp1 = centar.first + (a.first - centar.first) * std::cos(ugao) - (a.second - centar.second) * std::sin(ugao);
    temp2 = centar.second + (a.first - centar.first) * std::sin(ugao) + (a.second - centar.second) * std::cos(ugao);
    a.first = temp1;
    a.second = temp2;
    temp1 = centar.first + (b.first - centar.first) * std::cos(ugao) - (b.second - centar.second) * std::sin(ugao);
    temp2 = centar.second + (b.first - centar.first) * std::sin(ugao) + (b.second - centar.second) * std::cos(ugao);
    b.first = temp1;
    b.second = temp2;
    temp1 = centar.first + (c.first - centar.first) * std::cos(ugao) - (c.second - centar.second) * std::sin(ugao);
    temp2 = centar.second + (c.first - centar.first) * std::sin(ugao) + (c.second - centar.second) * std::cos(ugao);
    c.first = temp1;
    c.second = temp2;
}

void Trougao::Skaliraj(double faktor) {
    if(std::fabs(faktor) <= eps) throw std::domain_error("Nekorektan faktor skaliranja");
    
    a.first = centar.first + faktor * (a.first - centar.first);
    a.second = centar.second + faktor * (a.second - centar.second);
    b.first = centar.first + faktor * (b.first - centar.first);
    b.second = centar.second + faktor * (b.second - centar.second);
    c.first = centar.first + faktor * (c.first - centar.first);
    c.second = centar.second + faktor * (c.second - centar.second);
    
    if(faktor < 0) this->Rotiraj(180);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    return (Trougao::UporediTjeme(t1.DajTjeme(1), t2.DajTjeme(1)) && Trougao::UporediTjeme(t1.DajTjeme(2), t2.DajTjeme(2)) && Trougao::UporediTjeme(t1.DajTjeme(3), t2.DajTjeme(3))) || (Trougao::UporediTjeme(t1.DajTjeme(1), t2.DajTjeme(1)) && Trougao::UporediTjeme(t1.DajTjeme(2), t2.DajTjeme(3)) && Trougao::UporediTjeme(t1.DajTjeme(3), t2.DajTjeme(2))) || (Trougao::UporediTjeme(t1.DajTjeme(1), t2.DajTjeme(2)) && Trougao::UporediTjeme(t1.DajTjeme(2), t2.DajTjeme(3)) && Trougao::UporediTjeme(t1.DajTjeme(3), t2.DajTjeme(1))) || (Trougao::UporediTjeme(t1.DajTjeme(1), t2.DajTjeme(2)) && Trougao::UporediTjeme(t1.DajTjeme(2), t2.DajTjeme(1)) && Trougao::UporediTjeme(t1.DajTjeme(3), t2.DajTjeme(3))) || (Trougao::UporediTjeme(t1.DajTjeme(1), t2.DajTjeme(3)) && Trougao::UporediTjeme(t1.DajTjeme(2), t2.DajTjeme(2)) && Trougao::UporediTjeme(t1.DajTjeme(3), t2.DajTjeme(1))) || (Trougao::UporediTjeme(t1.DajTjeme(1), t2.DajTjeme(3)) && Trougao::UporediTjeme(t1.DajTjeme(2), t2.DajTjeme(1)) && Trougao::UporediTjeme(t1.DajTjeme(3), t2.DajTjeme(2)));
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
   return (Trougao::Uporedi(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::Uporedi(t1.DajStranicu(2), t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(3), t2.DajStranicu(3))) || (Trougao::Uporedi(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::Uporedi(t1.DajStranicu(3), t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(2), t2.DajStranicu(3))) || (Trougao::Uporedi(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::Uporedi(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(3), t2.DajStranicu(3))) || (Trougao::Uporedi(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::Uporedi(t1.DajStranicu(3), t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(1), t2.DajStranicu(3))) || (Trougao::Uporedi(t1.DajStranicu(3), t2.DajStranicu(1)) && Trougao::Uporedi(t1.DajStranicu(2), t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(1), t2.DajStranicu(3))) || (Trougao::Uporedi(t1.DajStranicu(3), t2.DajStranicu(1)) && Trougao::Uporedi(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(2), t2.DajStranicu(3)));
   
   /*
   std::vector<double> v1{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)}, v2{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
   std::sort(v1.begin(), v1.end());
   std::sort(v2.begin(), v2.end());
   return v1 == v2;   */
    
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    return (Trougao::Uporedi(t1.DajStranicu(1)/t2.DajStranicu(1), t1.DajStranicu(2)/t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(2)/t2.DajStranicu(2), t1.DajStranicu(3)/t2.DajStranicu(3)) && Trougao::Uporedi(t1.DajStranicu(3)/t2.DajStranicu(3), t1.DajStranicu(1)/t2.DajStranicu(1))) || (Trougao::Uporedi(t1.DajStranicu(2)/t2.DajStranicu(1), t1.DajStranicu(3)/t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(3)/t2.DajStranicu(2), t1.DajStranicu(1)/t2.DajStranicu(3)) && Trougao::Uporedi(t1.DajStranicu(1)/t2.DajStranicu(3), t1.DajStranicu(2)/t2.DajStranicu(1))) || (Trougao::Uporedi(t1.DajStranicu(3)/t2.DajStranicu(1), t1.DajStranicu(1)/t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(1)/t2.DajStranicu(2), t1.DajStranicu(2)/t2.DajStranicu(3)) && Trougao::Uporedi(t1.DajStranicu(2)/t2.DajStranicu(3), t1.DajStranicu(3)/t2.DajStranicu(1))) || (Trougao::Uporedi(t1.DajStranicu(2)/t2.DajStranicu(1), t1.DajStranicu(1)/t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(1)/t2.DajStranicu(2), t1.DajStranicu(3)/t2.DajStranicu(3)) && Trougao::Uporedi(t1.DajStranicu(3)/t2.DajStranicu(3), t1.DajStranicu(2)/t2.DajStranicu(1))) || (Trougao::Uporedi(t1.DajStranicu(1)/t2.DajStranicu(1), t1.DajStranicu(3)/t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(3)/t2.DajStranicu(2), t1.DajStranicu(2)/t2.DajStranicu(3)) && Trougao::Uporedi(t1.DajStranicu(2)/t2.DajStranicu(3), t1.DajStranicu(1)/t2.DajStranicu(1))) || (Trougao::Uporedi(t1.DajStranicu(3)/t2.DajStranicu(1), t1.DajStranicu(2)/t2.DajStranicu(2)) && Trougao::Uporedi(t1.DajStranicu(2)/t2.DajStranicu(2), t1.DajStranicu(1)/t2.DajStranicu(3)) && Trougao::Uporedi(t1.DajStranicu(1)/t2.DajStranicu(3), t1.DajStranicu(3)/t2.DajStranicu(1)));                                                                                                            
}


int main ()
{
    try {
    int n;
    Tacka t1, t2, t3;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> trouglovi(n);
    for(int i = 0; i < n; i++) {
        while(true) {
        std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second;
        try {
        trouglovi[i] = std::make_shared<Trougao> (t1,t2,t3);
        break;
        }
        catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
        }
        catch(std::range_error izuzetak) {
            std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
        }
        }
    } 
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx >> dy;
    
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    
    std::cout << "Unesite faktor skaliranja: ";
    double faktorSk;
    std::cin >> faktorSk;
    
    std::vector<std::shared_ptr<Trougao>> nTrouglovi(n);
    std::transform(trouglovi.begin(), trouglovi.end(), nTrouglovi.begin(), [dx,dy,ugao,faktorSk] ( std::shared_ptr<Trougao> t) {
        t->Transliraj(dx, dy);
        t->Rotiraj(t->DajCentar(), ugao);
        t->Skaliraj(t->DajTjeme(1), faktorSk);
        return t;
    });
    
    
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::sort(nTrouglovi.begin(), nTrouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajPovrsinu() < t2->DajPovrsinu();
    });
    
    
    std::for_each(nTrouglovi.begin(), nTrouglovi.end(), [] (std::shared_ptr<Trougao> t) {
        t->Ispisi();
        std::cout << std::endl;
    });
    
    std::cout << "Trougao sa najmanjim obimom: ";
    (*std::min_element(nTrouglovi.begin(), nTrouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajObim() < t2->DajObim();
    }))->Ispisi();
    
    int brojac(1);
    std::cout << std::endl;
    bool imaPodudarnih(false), imaIdenticnih(false), imaSlicnih(false);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
          if(DaLiSuIdenticni(*nTrouglovi[i], *nTrouglovi[j])) {
            if(brojac == 1) {
                std::cout << "Parovi identicnih trouglova: " << std::endl;
                brojac++;
            }
              nTrouglovi[i]->Ispisi();
              std::cout << " i ";
              nTrouglovi[j]->Ispisi();
              std::cout << std::endl;
              imaIdenticnih = true;
          }
    }
    }
    brojac = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
          if(DaLiSuPodudarni(*nTrouglovi[i], *nTrouglovi[j])) {
             if(brojac == 1) {
                 std::cout << "Parovi podudarnih trouglova: " << std::endl;
                 brojac++;
             }
              nTrouglovi[i]->Ispisi();
              std::cout << " i " ;
              nTrouglovi[j]->Ispisi();
              std::cout << std::endl;
          
              imaPodudarnih = true;
          }
        }
    }
    
    brojac = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
          if(DaLiSuSlicni(*nTrouglovi[i], *nTrouglovi[j])) {
            if(brojac == 1)  {
                std::cout << "Parovi slicnih trouglova: " << std::endl;
                brojac++;
            }
              nTrouglovi[i]->Ispisi();
              std::cout << " i ";
              nTrouglovi[j]->Ispisi();
              std::cout << std::endl;
              imaSlicnih = true;
          }
        }
         
    }
    if(!imaIdenticnih) std::cout << "Nema identicnih trouglova!" << std::endl;
    if(!imaPodudarnih) std::cout << "Nema podudarnih trouglova!" << std::endl;
    if(!imaSlicnih) std::cout << "Nema slicnih trouglova!" << std::endl;
    
    } 
    catch(std::range_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}