/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <set>

const double pi=4*std::atan(1);

typedef std::pair<double, double> Tacka;

class Trougao {
  Tacka x,y,z;
  static bool JesuLiDvaBrojaJednaka(double x, double y, double Eps=1e-10) {
      if ((x<0 && y>0) || (x>0 && y<0)) return false;
      return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
  }
  static bool JesuLiDvijeTackeJednake(const Tacka &t1, const Tacka &t2) {
      if (JesuLiDvaBrojaJednaka(t1.first,t2.first) && JesuLiDvaBrojaJednaka(t1.second,t2.second)) return true;
      return false;
  }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1,t2,t3); }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        x.first=t1.first; x.second=t1.second;
        y.first=t2.first; y.second=t2.second;
        z.first=t3.first; z.second=t3.second;
    }
    void Postavi(int indeks, const Tacka &t) {
        switch(indeks) {
            case 1:
                if (!Orijentacija(t,y,z)) throw std::domain_error("Nekorektne pozicije tjemena");
                x.first=t.first; x.second=t.second;
            case 2:
                if (!Orijentacija(x,t,z)) throw std::domain_error("Nekorektne pozicije tjemena");
                y.first=t.first; y.second=t.second;
            case 3:
                if (!Orijentacija(x,y,t)) throw std::domain_error("Nekorektne pozicije tjemena");
                z.first=t.first; z.second=t.second;
            default:
                throw std::range_error("Nekorektan indeks");
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double orijentacija=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if (orijentacija>0) return 1;
        else if (orijentacija<0) return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const {
        switch(indeks) {
            case 1: return x;
            case 2: return y;
            case 3: return z;
            default: throw std::range_error("Nekorektan indeks");
        }
    }
    double DajStranicu(int indeks) const {
        switch(indeks) {
            case 1: return std::sqrt((y.first-z.first)*(y.first-z.first)+(y.second-z.second)*(y.second-z.second));
            case 2: return std::sqrt((x.first-z.first)*(x.first-z.first)+(x.second-z.second)*(x.second-z.second));
            case 3: return std::sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
            default: throw std::range_error("Nekorektan indeks");
        }
    }
    double DajUgao(int indeks) const {
        switch(indeks) {
            case 1: return std::acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
            case 2: return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
            case 3: return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
            default: throw std::range_error("Nekorektan indeks");
        }
    }
    Tacka DajCentar() const { return {(x.first+y.first+z.first)/3., (x.second+y.second+z.second)/3.}; }
    double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
    double DajPovrsinu() const { return std::abs(x.first*(y.second-z.second)-y.first*(x.second-z.second)+z.first*(x.second-y.second))/2.; }
    bool DaLiJePozitivnoOrijentiran() const {
        if (Orijentacija(x,y,z)==1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if (Orijentacija(x,y,z)==Orijentacija(x,y,t) && Orijentacija(x,y,z)==Orijentacija(y,z,t) && Orijentacija(x,y,z)==Orijentacija(z,x,t)) return true;
        return false;
    }
    void Ispisi() const {
        std::cout << "((" << x.first << "," << x.second << "),(" << y.first << "," << y.second << "),(" << z.first << "," << z.second << "))";
    }
    void Transliraj(double delta_x, double delta_y) {
        x.first+=delta_x; y.first+=delta_x; z.first+=delta_x;
        x.second+=delta_y; y.second+=delta_y; z.second+=delta_y;
    }
    void Centriraj(const Tacka &t) { Transliraj(t.first-DajCentar().first,t.second-DajCentar().second); }
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double ugao);
    void Rotiraj(double ugao) { Rotiraj(DajCentar(),ugao); }
    void Skaliraj(double ugao) { Skaliraj(DajCentar(),ugao); }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
    
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    Tacka t1,t2,t3;
    t1.first=t.first+(x.first-t.first)*std::cos(ugao)-(x.second-t.second)*std::sin(ugao);
    t1.second=t.second+(x.first-t.first)*std::sin(ugao)+(x.second-t.second)*std::cos(ugao);
    t2.first=t.first+(y.first-t.first)*std::cos(ugao)-(y.second-t.second)*std::sin(ugao);
    t2.second=t.second+(y.first-t.first)*std::sin(ugao)+(y.second-t.second)*std::cos(ugao);
    t3.first=t.first+(z.first-t.first)*std::cos(ugao)-(z.second-t.second)*std::sin(ugao);
    t3.second=t.second+(z.first-t.first)*std::sin(ugao)+(z.second-t.second)*std::cos(ugao);
    Postavi(t1,t2,t3);
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if (JesuLiDvaBrojaJednaka(faktor, 0.)) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t1,t2,t3;
    t1.first=t.first+faktor*(x.first-t.first); t1.second=t.second+faktor*(x.second-t.second);
    t2.first=t.first+faktor*(y.first-t.first); t2.second=t.second+faktor*(y.second-t.second);
    t3.first=t.first+faktor*(z.first-t.first); t3.second=t.second+faktor*(z.second-t.second);
    Postavi(t1,t2,t3);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if ((Trougao::JesuLiDvijeTackeJednake(t1.x,t2.x) || Trougao::JesuLiDvijeTackeJednake(t1.x,t2.y) || Trougao::JesuLiDvijeTackeJednake(t1.x,t2.z)) &&
    (Trougao::JesuLiDvijeTackeJednake(t1.y,t2.x) || Trougao::JesuLiDvijeTackeJednake(t1.y,t2.y) || Trougao::JesuLiDvijeTackeJednake(t1.y,t2.z)) &&
    (Trougao::JesuLiDvijeTackeJednake(t1.z,t2.x) || Trougao::JesuLiDvijeTackeJednake(t1.z,t2.y) || Trougao::JesuLiDvijeTackeJednake(t1.z,t2.z))) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    int brojac_jednakih_stranica=0;
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            if (Trougao::JesuLiDvaBrojaJednaka(t1.DajStranicu(i),t2.DajStranicu(j))) {
                brojac_jednakih_stranica++;
                break;
            }
        }
    }
    if (brojac_jednakih_stranica!=3) return false;
    std::vector<std::pair<int,Tacka>> vektor_parova_stranica_i_tacaka_za_t1;
    std::vector<std::pair<int,Tacka>> vektor_parova_stranica_i_tacaka_za_t2;
    for (int i=1; i<=3; i++) {
        vektor_parova_stranica_i_tacaka_za_t1.push_back(std::make_pair(i,t1.DajTjeme(i)));
        vektor_parova_stranica_i_tacaka_za_t2.push_back(std::make_pair(i,t2.DajTjeme(i)));
    }
    std::sort(vektor_parova_stranica_i_tacaka_za_t1.begin(),vektor_parova_stranica_i_tacaka_za_t1.end(),
    [t1,t2](std::pair<int,Tacka> par1, std::pair<int,Tacka> par2){ return t1.DajStranicu(par1.first)<t1.DajStranicu(par2.first); });
    std::sort(vektor_parova_stranica_i_tacaka_za_t2.begin(),vektor_parova_stranica_i_tacaka_za_t2.end(),
    [t1,t2](std::pair<int,Tacka> par1, std::pair<int,Tacka> par2){ return t2.DajStranicu(par1.first)<t2.DajStranicu(par2.first); });
    for (int i=0; i<3; i++)
        if (!(Trougao::JesuLiDvaBrojaJednaka(t1.DajStranicu(vektor_parova_stranica_i_tacaka_za_t1[i].first),t2.DajStranicu(vektor_parova_stranica_i_tacaka_za_t2[i].first))))
            return false;
    if (t1.Orijentacija(vektor_parova_stranica_i_tacaka_za_t1[0].second, vektor_parova_stranica_i_tacaka_za_t1[1].second,
        vektor_parova_stranica_i_tacaka_za_t1[2].second)==t2.Orijentacija(vektor_parova_stranica_i_tacaka_za_t2[0].second,
        vektor_parova_stranica_i_tacaka_za_t2[1].second,vektor_parova_stranica_i_tacaka_za_t2[2].second)) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    int brojac_jednakih_ili_skaliranih_stranica=0;
    double faktor_skaliranja=t1.DajObim()/t2.DajObim();
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++)
            if (Trougao::JesuLiDvaBrojaJednaka(t1.DajStranicu(i),t2.DajStranicu(j)) || 
            Trougao::JesuLiDvaBrojaJednaka(t1.DajStranicu(i)/t2.DajStranicu(j),faktor_skaliranja)) {
                brojac_jednakih_ili_skaliranih_stranica++;
                break;
            }
    }
    if (brojac_jednakih_ili_skaliranih_stranica==3 && DaLiSuPodudarni(t1,t2)) return true;
    return false;
}

int main () {
    std::cout << "Koliko zelite kreirati trouglova: ";
    int dimenzija;
    std::cin >> dimenzija;
    if (dimenzija<0) return 0;
    std::vector<std::shared_ptr<Trougao>> vektor_trouglova(dimenzija);
    Tacka t1,t2,t3; 
    for (int i=0; i<dimenzija; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second;
        try {
            vektor_trouglova[i]=std::make_shared<Trougao>(t1,t2,t3);
        }
        catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    double dx, dy;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> dx >> dy;
    std::transform(vektor_trouglova.begin(),vektor_trouglova.end(),vektor_trouglova.begin(),[dx,dy](std::shared_ptr<Trougao> pok){ 
        pok->Transliraj(dx,dy);
        return pok;
    });
    double ugao_rotacije;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao_rotacije;
    std::transform(vektor_trouglova.begin(),vektor_trouglova.end(),vektor_trouglova.begin(),[ugao_rotacije](std::shared_ptr<Trougao> pok){ 
        pok->Rotiraj(ugao_rotacije); 
        return pok;
    });
    double faktor_skaliranja;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor_skaliranja;
    try {
        std::transform(vektor_trouglova.begin(),vektor_trouglova.end(),vektor_trouglova.begin(),
        [faktor_skaliranja](std::shared_ptr<Trougao> pok){ 
            pok->Skaliraj(pok->DajTjeme(1),faktor_skaliranja); 
            return pok;
        });
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
    }
    std::sort(vektor_trouglova.begin(),vektor_trouglova.end(),[](std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2){
        return pok1->DajPovrsinu()<pok2->DajPovrsinu();
    });
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::for_each(vektor_trouglova.begin(),vektor_trouglova.end(),[](std::shared_ptr<Trougao> pok){ pok->Ispisi(); std::cout << std::endl; });
    std::cout << "Trougao sa najmanjim obimom: ";
    auto p=std::min_element(vektor_trouglova.begin(),vektor_trouglova.end(),
    [](std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2){ return pok1->DajObim()<=pok2->DajObim(); });
    (*p)->Ispisi(); 
    std::cout << std::endl;
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> vektor_parova_identicnih_trouglova;
    for (int i=0; i<dimenzija; i++) {
        for (int j=i+1; j<dimenzija; j++) 
            if (DaLiSuIdenticni(*vektor_trouglova[i],*vektor_trouglova[j])) 
                vektor_parova_identicnih_trouglova.push_back(std::make_pair(vektor_trouglova[i],vektor_trouglova[j]));
    }
    if (vektor_parova_identicnih_trouglova.size()==0) std::cout << "Nema identicnih trouglova!" << std::endl;
    else {
        std::cout << "Parovi identicnih trouglova:" << std::endl;
        for (auto x:vektor_parova_identicnih_trouglova) {
            x.first->Ispisi(); std::cout << " i "; x.second->Ispisi(); std::cout << std::endl;
        }
    }
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> vektor_parova_podudarnih_trouglova;
    for (int i=0; i<dimenzija; i++) {
        for (int j=i+1; j<dimenzija; j++)
            if (DaLiSuPodudarni(*vektor_trouglova[i],*vektor_trouglova[j]))
                vektor_parova_podudarnih_trouglova.push_back(std::make_pair(vektor_trouglova[i],vektor_trouglova[j]));
    }
    if (vektor_parova_podudarnih_trouglova.size()==0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else {
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for (auto x:vektor_parova_podudarnih_trouglova) {
            x.first->Ispisi(); std::cout << " i "; x.second->Ispisi(); std::cout << std::endl;
        }
    }
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> vektor_parova_slicnih_trouglova;
    for (int i=0; i<dimenzija; i++) {
        for (int j=i+1; j<dimenzija; j++)
            if (DaLiSuSlicni(*vektor_trouglova[i],*vektor_trouglova[j]))
                vektor_parova_slicnih_trouglova.push_back(std::make_pair(vektor_trouglova[i],vektor_trouglova[j]));
    }
    if (vektor_parova_slicnih_trouglova.size()==0) std::cout << "Nema slicnih trouglova!" << std::endl;
    else {
        std::cout << "Parovi slicnih trouglova:" << std::endl;
        for (auto x:vektor_parova_slicnih_trouglova) {
            x.first->Ispisi(); std::cout << " i "; x.second->Ispisi(); std::cout << std::endl;
        }
    }
    return 0;
}