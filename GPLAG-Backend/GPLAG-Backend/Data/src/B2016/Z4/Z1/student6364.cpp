/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
const double Eps(1e-10);
typedef std::pair<double, double> Tacka;
bool epsilon(double x, double y);
class Trougao {
    Tacka t1, t2, t3;
    static void PozicijaTjemena(Tacka t1, Tacka t2, Tacka t3) {
        if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    }
    void KakavJeIndeks(int indeks) const {
        if(indeks != 1 && indeks && 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
    }
    static double DuzinaStranice(Tacka t1, Tacka t2)  {
        int a = std::sqrt(std::pow((t1.first - t2.first), 2) + std::pow((t1.second - t2.second), 2));
        return a;
    }
    static double Ugao(Tacka trazena, Tacka prva, Tacka druga)  {
        double a = DuzinaStranice(trazena, prva);
        double b = DuzinaStranice(trazena, druga);
        double c = DuzinaStranice(prva, druga);
        return std::acos((a*a + b*b - c*c)/(2*a*b));
    }
    static bool Jednakokraki(const Trougao &t1);
    static double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
    }
    Tacka Teziste() {
        Tacka t;
        t.first = (t1.first + t2.first + t3.first)/3.;
        t.second = (t1.second + t2.second + t3.second)/3.;
        return t;
    }
    Tacka rotacija(Tacka &t, Tacka x, double ugao) {
        Tacka a;
        a.first = x.first + (t.first - x.first)*std::cos(ugao) - (t.second - x.second)*std::sin(ugao);
        a.second = x.second + (t.first - x.first)*std::sin(ugao) + (t.second - x.second)*std::cos(ugao);
        return a;
    }
    void skaliranje(Tacka &t, Tacka T, double k) {
        t.first = T.first + k*(t.first - T.first);
        t.second = T.second + k*(t.second - T.second);
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        PozicijaTjemena(t1, t2, t3);
        this->t1 = t1; this->t2 = t2; this->t3 = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        PozicijaTjemena(t1, t2, t3);
        this->t1 = t1; this->t2 = t2; this->t3 = t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        KakavJeIndeks(indeks);
        switch(indeks) {
            case 1: this->t1 = t; break;
            case 2: this->t2 = t; break;
            case 3: this->t3 = t; break;
        }
        PozicijaTjemena(t1, t2, t3);
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double x = Izraz(t1, t2, t3);
        if(x < -Eps) return -1;
        if(x > Eps) return 1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const {
        KakavJeIndeks(indeks);
        switch(indeks) {
            case 1: return t1; 
            case 2: return t2; 
            case 3: return t3;
        }
    }
    double DajStranicu(int indeks) const {
        KakavJeIndeks(indeks);
        switch(indeks) {
            case 1: return DuzinaStranice(t2, t3);
            case 2: return DuzinaStranice(t1, t3);
            case 3: return DuzinaStranice(t1, t2);
        }
    }
    double DajUgao(int indeks) const {
        KakavJeIndeks(indeks);
        switch(indeks) {
            case 1: return Ugao(t1, t2, t3); 
            case 2: return Ugao(t2, t1, t3);
            case 3: return Ugao(t3, t1, t2);
        }
    }
    Tacka DajCentar() const {
        return { (t1.first + t2.first + t3.first) / 3., (t1.second + t2.second + t3.second)/3. };
    }
    double DajObim() const {
        return DuzinaStranice(t1, t2) + DuzinaStranice(t1, t3) + DuzinaStranice(t2, t3);
    }
    double DajPovrsinu() const {
        return std::abs(Izraz(t1, t2, t3))/2.;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        return Orijentacija(t1, t2, t3);
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(t1, t2, t3) == Orijentacija(t1, t2, t) == Orijentacija(t2, t3, t) == Orijentacija(t3, t1, t)) return true;
        return false;
    }
    void Ispisi() const {
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        t1.first += delta_x; t1.second += delta_y;
        t2.first += delta_x; t2.second += delta_y;
        t3.first += delta_x; t3.second += delta_y;
    }
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};
void Trougao::Centriraj(const Tacka &t)
{
    Tacka staroT(this->Teziste());
    double x, y;
    x = t.first - staroT.first; y = t.second - staroT.second;
    t1.first += x; t1.second += y;
    t2.first += x; t2.second += y;
    t3.first += x; t3.second += y;
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    t1 = rotacija(t1, t, ugao);
    t2 = rotacija(t2, t, ugao);
    t3 = rotacija(t3, t, ugao);
}
void Trougao::Skaliraj(const Tacka&t, double faktor)
{
    if(epsilon(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    skaliranje(t1, t, faktor);
    skaliranje(t2, t, faktor);
    skaliranje(t3, t, faktor);
}
void Trougao::Rotiraj(double ugao)
{
    Tacka t(Teziste());
    Rotiraj(t, ugao);
}
void Trougao::Skaliraj(double faktor)
{
    if(epsilon(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t(this->Teziste());
    skaliranje(t1, t, faktor);
    skaliranje(t2, t, faktor);
    skaliranje(t3, t, faktor);
}
bool Jednakost (std::vector<Tacka> niz, std::vector<Tacka> drugi)
{
    int a(-1), b(-1), c(-1);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == a) continue;
            if(j == b) continue;
            if(j == c) continue;
            if(std::abs(niz[0].first - drugi[j].first) <= Eps && std::abs(niz[0].second - drugi[j].second) <= Eps)  { a = j; continue; }
            else if(std::abs(niz[1].first - drugi[j].first) <= Eps && std::abs(niz[1].second - drugi[j].second) <= Eps) { b = j; continue; }
            else if(std::abs(niz[2].first - drugi[j].first) <= Eps && std::abs(niz[2].second - drugi[j].second) <= Eps) { c = j; continue; }
        }
    }
    if(a >= 0  && b >= 0 && c >= 0) return true;
    return false;
}
template <typename Tip>
bool Jednakost2 (std::vector<Tip> niz, std::vector<Tip>drugi)
{
    int a(-1), b(-1), c(-1);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == a) continue;
            if(j == b) continue;
            if(j == c) continue;
            if(std::abs(niz[0] - drugi[j]) <= Eps) { a = j; continue; }
            else if(std::abs(niz[1] - drugi[j]) <= Eps) { b = j; continue; }
            else if(std::abs(niz[2] - drugi[j]) <= Eps) { c = j; continue; }
        }
    } if(a >= 0 && b >= 0 && c >= 0) return true;
    return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    std::vector<Tacka>prvi { t1.t1, t1.t2, t1.t3 };
    std::vector<Tacka> drugi { t2.t1, t2.t2, t2.t3 };
    return Jednakost(prvi, drugi);
}
bool epsilon(double x, double y)
{
    return std::abs(x - y) < Eps;
}
bool Trougao::Jednakokraki(const Trougao &t1)
{
    std::vector<double>v { t1.DuzinaStranice(t1.t1, t1.t2), t1.DuzinaStranice(t1.t1, t1.t3), t1.DuzinaStranice(t1.t2, t1.t3) };
    bool jednakokrako = false;
    if(epsilon(v[0], v[1]) || epsilon(v[0], v[2]) || epsilon(v[1], v[2])) jednakokrako = true;
    return jednakokrako;
    
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    std::vector<double> prvi { t1.DuzinaStranice(t1.t1, t1.t2), t1.DuzinaStranice(t1.t1, t1.t3), t1.DuzinaStranice(t1.t2, t1.t3) };
    std::vector<double> drugi { t2.DuzinaStranice(t2.t1, t2.t2), t2.DuzinaStranice(t2.t1, t2.t3), t2.DuzinaStranice(t2.t2, t2.t3) };
    if(!Jednakost2(prvi, drugi)) return false;
    if(epsilon(prvi[0], prvi[1]) && epsilon(prvi[1], prvi[2]) && epsilon(prvi[2], drugi[0]) && epsilon(drugi[0], drugi[1]) && epsilon(drugi[1], drugi[2])) return true;
    if(Trougao::Jednakokraki(t1)) return true;
    auto pok = max_element(prvi.begin(), prvi.end());
    double stranica1 = *pok;
    std::vector<Tacka> najnoviji;
    std::vector<Tacka> korektor;
    if(epsilon(Trougao::DuzinaStranice(t1.t1, t1.t2), stranica1)) najnoviji.push_back(t1.t3);
    else if(epsilon(Trougao::DuzinaStranice(t1.t2, t1.t3), stranica1)) najnoviji.push_back(t1.t1);
    else  najnoviji.push_back(t1.t2);
    if(epsilon(Trougao::DuzinaStranice(t2.t1, t2.t2), stranica1)) korektor.push_back(t2.t3);
    else if(epsilon(Trougao::DuzinaStranice(t2.t2, t2.t3), stranica1)) korektor.push_back(t2.t1);
    else korektor.push_back(t2.t2);
    prvi.erase(pok);
    pok = max_element(prvi.begin(), prvi.end());
    stranica1 = *pok;
    if(epsilon(Trougao::DuzinaStranice(t1.t1, t1.t2), stranica1)) najnoviji.push_back(t1.t3);
    else if(epsilon(Trougao::DuzinaStranice(t1.t2, t1.t3), stranica1)) najnoviji.push_back(t1.t1);
    else najnoviji.push_back(t1.t2);
    if(epsilon(Trougao::DuzinaStranice(t2.t1, t2.t2), stranica1)) korektor.push_back(t2.t3);
    else if(epsilon(Trougao::DuzinaStranice(t2.t2, t2.t3), stranica1)) korektor.push_back(t2.t1);
    else korektor.push_back(t2.t2);
    prvi.erase(pok);
    stranica1 = prvi[0];
    if(epsilon(Trougao::DuzinaStranice(t1.t1, t1.t2), stranica1)) najnoviji.push_back(t1.t3);
    else if(epsilon(Trougao::DuzinaStranice(t1.t2, t1.t3), stranica1)) najnoviji.push_back(t1.t1);
    else najnoviji.push_back(t1.t2);
    if(epsilon(Trougao::DuzinaStranice(t2.t1, t2.t2), stranica1)) korektor.push_back(t2.t3);
    else if(epsilon(Trougao::DuzinaStranice(t2.t2, t2.t3), stranica1)) korektor.push_back(t2.t1);
    else korektor.push_back(t2.t2);
    if(Trougao::Orijentacija(najnoviji[0], najnoviji[1], najnoviji[2]) == Trougao::Orijentacija(korektor[0], korektor[1], korektor[2])) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    std::vector<double> prvi { Trougao::Ugao(t1.t1, t1.t2, t1.t3), Trougao::Ugao(t1.t2, t1.t3, t1.t1), Trougao::Ugao(t1.t3, t1.t2, t1.t1) };
    std::vector<double> drugi { Trougao::Ugao(t2.t1, t2.t2, t2.t3), Trougao::Ugao(t2.t2, t2.t3, t2.t1), Trougao::Ugao(t2.t3, t2.t2, t2.t1) };
    Tacka a(t1.t1), b(t1.t2), c(t1.t3), A(t2.t1), B(t2.t2), C(t2.t3);
    if(epsilon(Trougao::DuzinaStranice(a, b), Trougao::DuzinaStranice(b, c)) && epsilon(Trougao::DuzinaStranice(a, c), Trougao::DuzinaStranice(a, b)) && epsilon(Trougao::DuzinaStranice(A, B), Trougao::DuzinaStranice(A, C))
        && epsilon(Trougao::DuzinaStranice(A, B), Trougao::DuzinaStranice(B, C))) return true;
    std::sort(prvi.begin(), prvi.end());
    std::sort(drugi.begin(), drugi.end());
    if((epsilon(prvi[0], prvi[1]) && epsilon(drugi[0], drugi[1]) && epsilon(prvi[0], drugi[0])) || (epsilon(prvi[1], prvi[2]) && epsilon(drugi[1], drugi[2]) && epsilon(prvi[1], drugi[1]))
        || (epsilon(prvi[2], prvi[0]) && epsilon(drugi[2], drugi[0]) && epsilon(prvi[2], drugi[2]))) return true;
    if(!Jednakost2(prvi, drugi)) return false;
    std::vector<Tacka>najnoviji;
    std::vector<Tacka>korektor;
    for(int i = 0; i < 3; i++)
    {
        if(epsilon(Trougao::Ugao(a, b, c), prvi[i])) najnoviji.push_back(a);
        else if(epsilon(Trougao::Ugao(c, a, b), prvi[i])) najnoviji.push_back(c);
        else najnoviji.push_back(b);
    }
    for(int i = 0; i < 3; i++)
    {
        if(epsilon(Trougao::Ugao(A, B, C), drugi[i])) korektor.push_back(A);
        else if(epsilon(Trougao::Ugao(B, C, A), drugi[i])) korektor.push_back(B);
        else korektor.push_back(C);
    }
    if(Trougao::Orijentacija(najnoviji[0], najnoviji[1], najnoviji[2]) == Trougao::Orijentacija(korektor[0], korektor[1], korektor[2])) return true;
    return false;
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> trouglovi(n);
    for(int i = 0; i < n; i++)
    {
        try {
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka t1, t2, t3;
            std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
            trouglovi[i] = std::make_shared<Trougao> (t1, t2, t3);
        }
        catch(std::domain_error e) {
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin.clear(); std::cin.ignore(100000, '\n');
            Tacka t1, t2, t3;
            std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
            trouglovi[i] = std::make_shared<Trougao>(t1, t2, t3);
        }
    }
    double dx, dy;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [dx, dy, ugao, faktor](std::shared_ptr<Trougao> p) { 
        p->Trougao::Transliraj(dx, dy); p->Trougao::Rotiraj(ugao); p->Trougao::Skaliraj(p->DajTjeme(1), faktor); return p; });
    std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> p, std::shared_ptr<Trougao> q) {
        return p->Trougao::DajPovrsinu() < q->Trougao::DajPovrsinu();});
    for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> p) { p->Trougao::Ispisi(); std::cout<<std::endl;});
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*std::min_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> p, std::shared_ptr<Trougao> q){ 
        return p->Trougao::DajObim() < q->Trougao::DajObim();}))->Ispisi();
    std::cout<<std::endl;
    std::vector<std::pair<Trougao, Trougao>> v;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j]))
                v.push_back(std::make_pair(*trouglovi[i], *trouglovi[j]));
        }
    }
    if(v.size() == 0) std::cout<<"Nema identicnih trouglova!\n";
    else {
        std::cout<<"Parovi identicnih trouglova:\n";
        for(int i = 0; i < v.size(); i++)
        {
           v[i].first.Ispisi(); std::cout<<" i "; v[i].second.Ispisi();
           std::cout<<std::endl;
        } 
    }
    std::vector<std::pair<Trougao, Trougao>> podudarni;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j]))
                podudarni.push_back(std::make_pair(*trouglovi[i], *trouglovi[j]));
                
        }
    }
    if(podudarni.size() == 0) std::cout<<"Nema podudarnih trouglova!\n";
    else {
        std::cout<<"Parovi podudarnih trouglova:\n";
        for(int i = 0; i < podudarni.size(); i++)
        {
            podudarni[i].first.Ispisi(); std::cout<<" i "; podudarni[i].second.Ispisi();
            std::cout<<std::endl;
        }
    }
    std::vector<std::pair<Trougao, Trougao>> slicni;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j]))
                slicni.push_back(std::make_pair(*trouglovi[i], *trouglovi[j]));
    }
    if(slicni.size() == 0) std::cout<<"Nema slicnih trouglova!\n";
    else {
        std::cout<<"Parovi slicnih trouglova:\n";
        for(int i = 0; i < slicni.size(); i++)
        {
            slicni[i].first.Ispisi(); std::cout<<" i "; slicni[i].second.Ispisi();
            std::cout<<std::endl;
        }
    }
	return 0;
}