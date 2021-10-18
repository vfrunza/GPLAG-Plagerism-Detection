/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;
const double PI = 3.141592653;
const double eps = 0.0000000001;

class Trougao 
{
private:
    Tacka t1;
    Tacka t2;
    Tacka t3;
    
    static bool sadrziVrijednost(std::vector<int> vektor, int vrijednost);  
    static bool jednakiRealniBrojevi(double r1, double r2);
    static bool jednakeTacke(const Tacka &t1, const Tacka &t2);
    
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

bool Trougao::sadrziVrijednost(std::vector<int> vektor, int vrijednost)
{
    bool sndrzi = false;
    
    for (int i = 0; i < vektor.size(); i++)
        if (vektor[i] == vrijednost)
        {
            sndrzi = true;
            break;
        }
            
    return sndrzi;
}

bool Trougao::jednakiRealniBrojevi(double r1, double r2)
{
    if (std::abs(r1 - r2) < eps)
        return true;
        
    return false;
}

bool Trougao::jednakeTacke(const Tacka &t1, const Tacka &t2)
{
    if (Trougao::jednakiRealniBrojevi(t1.first, t2.first) && Trougao::jednakiRealniBrojevi(t1.second, t2.second))
        return true;
    
    return false;
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double oijentir(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second));

    if (oijentir > eps)
         return 1;
    else if (Trougao::jednakiRealniBrojevi(oijentir, 0))
        return 0;
    else
        return -1;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    /*if (Orijentacija(t1, t2, t3) == 0)
        throw std::domain_error("Nekorektne pozicije tjemena");*/
        
    this->t1 = t1;
    this->t2 = t2;
    this->t3 = t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if (Orijentacija(t1, t2, t3) == 0)
        throw std::domain_error("Nekorektne pozicije tjemena");
        
    this->t1 = t1;
    this->t2 = t2;
    this->t3 = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{
    if (indeks < 1 || indeks > 3)
        throw std::range_error("Nekorektan indeks");
        
    switch (indeks)
    {
        case 1:
            this->t1 = t;
            break;
        case 2:
            this->t2 = t;
            break;
        case 3:
            this->t3 = t;
            break;
    }
}

Tacka Trougao::DajTjeme(int indeks) const
{
    if (indeks < 1 || indeks > 3)
        throw std::range_error("Nekorektan indeks");
        
    switch (indeks)
    {
        case 1:
            return this->t1;
            break;
        case 2:
            return this->t2;
            break;
        case 3:
            return this->t3;
            break;
    }   
    
}

double Trougao::DajStranicu(int indeks) const
{
    if (indeks < 1 || indeks > 3)
        throw std::range_error("Nekorektan indeks");
    
    switch (indeks)
    {
        case 1:
            return std::sqrt((t2.first - t3.first) * (t2.first - t3.first) + (t2.second - t3.second) * (t2.second - t3.second));
            break;
        case 2:
            return std::sqrt((t1.first - t3.first) * (t1.first - t3.first) + (t1.second - t3.second) * (t1.second - t3.second));
            break;
        case 3:
            return std::sqrt((t2.first - t1.first) * (t2.first - t1.first) + (t2.second - t1.second) * (t2.second - t1.second));
            break;
    }
}

double Trougao::DajUgao(int indeks) const
{
    if (indeks < 1 || indeks > 3)
        throw std::range_error("Nekorektan indeks");
        
    switch (indeks)
    {
        case 1:
            return std::acos(((-1.0) * DajStranicu(1) * DajStranicu(1) + DajStranicu(2) * DajStranicu(2) + DajStranicu(3) * DajStranicu(3)) / (2 * DajStranicu(2) * DajStranicu(3)));
            break;
        case 2:
            return std::acos(((-1.0) * DajStranicu(2) * DajStranicu(2) + DajStranicu(1) * DajStranicu(1) + DajStranicu(3) * DajStranicu(3)) / (2 * DajStranicu(1) * DajStranicu(3)));
            break;
        case 3:
            return std::acos(((-1.0) * DajStranicu(3) * DajStranicu(3) + DajStranicu(1) * DajStranicu(1) + DajStranicu(2) * DajStranicu(2)) / (2 * DajStranicu(1) * DajStranicu(2)));
            break;
    }
}

Tacka Trougao::DajCentar() const
{
    return std::make_pair((t1.first + t2.first + t3.first) / 3, (t1.second + t2.second + t3.second) / 3);
}

double Trougao::DajObim() const
{
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const
{
    return 0.5 * std::abs(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    if (Orijentacija(t1, t2, t3) > 0)
        return true;
    
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    if (Orijentacija(t1, t2, t3) > 0 && Orijentacija(t1, t2, t) > 0 && Orijentacija(t2, t3, t) > 0 && Orijentacija(t3, t1, t) > 0)
        return true;
    else if (Orijentacija(t1, t2, t3) < 0 && Orijentacija(t1, t2, t) < 0 && Orijentacija(t2, t3, t) < 0 && Orijentacija(t3, t1, t) < 0)
        return true;
    else
        return false;
}

void Trougao::Ispisi() const
{
    std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first += delta_x;
    t2.first += delta_x;
    t3.first += delta_x;
    
    t1.second += delta_y;
    t2.second += delta_y;
    t3.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    Tacka tsnutniCentar = DajCentar();
    
    Transliraj(t.first - tsnutniCentar.first, t.second - tsnutniCentar.second);
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    t1.first = t.first + (t1.first - t.first) * std::cos(ugao) - (t1.second - t.second) * std::sin(ugao);
    t1.second = t.second + (t1.first - t.first) * std::sin(ugao) + (t1.second - t.second) * std::cos(ugao);
    
    t2.first = t.first + (t2.first - t.first) * std::cos(ugao) - (t2.second - t.second) * std::sin(ugao);
    t2.second = t.second + (t2.first - t.first) * std::sin(ugao) + (t2.second - t.second) * std::cos(ugao);
    
    t3.first = t.first + (t3.first - t.first) * std::cos(ugao) - (t3.second - t.second) * std::sin(ugao);
    t3.second = t.second + (t3.first - t.first) * std::sin(ugao) + (t3.second - t.second) * std::cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if (Trougao::jednakiRealniBrojevi(faktor, 0))
        throw std::domain_error("Nekorektan faktor skaliranja");
        
    t1.first = t.first + faktor * (t1.first - t.first);
    t1.second = t.second + faktor * (t1.second - t.second);
    
    t2.first = t.first + faktor * (t2.first - t.first);
    t2.second = t.second + faktor * (t2.second - t.second);
    
    t3.first = t.first + faktor * (t3.first - t.first);
    t3.second = t.second + faktor * (t3.second - t.second);
    
    if (faktor < 0)
        Rotiraj(t, PI);
}

void Trougao::Rotiraj(double ugao)
{
    Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj(double faktor)
{
    Skaliraj(DajCentar(), faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if (Trougao::jednakeTacke(t1.t1, t2.t1))
    {   
        if (Trougao::jednakeTacke(t1.t2, t2.t2))
        {
            if (Trougao::jednakeTacke(t1.t3, t2.t3))
                return true;
        }
        else if (Trougao::jednakeTacke(t1.t2, t2.t3))
        {
            if (Trougao::jednakeTacke(t1.t3, t2.t2))
                return true;
        }
    }
    else if (Trougao::jednakeTacke(t1.t1, t2.t2))
    {
        if (Trougao::jednakeTacke(t1.t2, t2.t1))
        {
            if (Trougao::jednakeTacke(t1.t3, t2.t3))
                return true;
        }
        else if (Trougao::jednakeTacke(t1.t2, t2.t3))
        {
            if (Trougao::jednakeTacke(t1.t3, t2.t1))
                return true;
        }
    }
    else if (Trougao::jednakeTacke(t1.t1, t2.t3))
    {
        if (Trougao::jednakeTacke(t1.t2, t2.t1))
        {
            if (Trougao::jednakeTacke(t1.t3, t2.t1))
                return true;
        }
        else if (Trougao::jednakeTacke(t1.t2, t2.t3))
        {
            if (Trougao::jednakeTacke(t1.t3, t2.t1))
                return true;
        }
    }
    
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    std::vector<int> taPrvog;
    std::vector<int> tmDrugog;
    
    taPrvog.push_back(1);
    taPrvog.push_back(2);
    taPrvog.push_back(3);
    
    std::vector<int> indePronadjenih;
    
    for (int j = 1; j < 4; j++)
    {
        for (int i = 1; i < 4; i++)
        {
            if (!(Trougao::sadrziVrijednost(indePronadjenih, i)) && Trougao::jednakiRealniBrojevi(t2.DajUgao(i), t1.DajUgao(j)))
            {
                indePronadjenih.push_back(i);
                tmDrugog.push_back(i);
                
                break;
            }
        }
    }
    
    if (tmDrugog.size() == 3)
    {
        if (Trougao::jednakiRealniBrojevi(t1.DajStranicu(1), t2.DajStranicu(tmDrugog[0])))
        {
            if (Trougao::jednakiRealniBrojevi(t1.DajStranicu(2), t2.DajStranicu(tmDrugog[1])))
            {
                if (Trougao::jednakiRealniBrojevi(t1.DajStranicu(3), t2.DajStranicu(tmDrugog[2])))
                {
                    if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)) == Trougao::Orijentacija(t2.DajTjeme(tmDrugog[0]), t2.DajTjeme(tmDrugog[1]), t2.DajTjeme(tmDrugog[2])))
                        return true;
                }
            }
        }
    }
    
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    std::vector<int> tjePl;
    std::vector<int> tjmNa;
    
    tjePl.push_back(1);
    tjePl.push_back(2);
    tjePl.push_back(3);
    
    std::vector<int> indatPronadj;
    
    for (int j = 1; j < 4; j++)
    {  
        for (int i = 1; i < 4; i++)
        {
            if (!(Trougao::sadrziVrijednost(indatPronadj, i)) && Trougao::jednakiRealniBrojevi(t2.DajUgao(i), t1.DajUgao(j)))
            {
                indatPronadj.push_back(i);
                tjmNa.push_back(i);
                
                break;
            }
        }
    }
    
    if (tjmNa.size() == 3)
        return true;
        
    return false;
}

int main ()
{   
    /*Trougao trou1(Tacka(3, 6), Tacka(3, 14), Tacka(9, 6));
    Trougao trou2(Tacka(3, 6), Tacka(9, 6), Tacka(3, 14));
    
    trou1.Ispisi();
    trou2.Ispisi();
    
    if (DaLiSuIdenticni(trou1, trou2))
        std::cout << "JESU";
    else
        std::cout << "NISU";
    std::cout << std::endl;*/
        
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    
    
    std::vector<std::shared_ptr<Trougao>> trouglovi(n);
    
    for (int i = 0; i < n; i++)
    {
        std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1;
        std::cin >> x1;
        double y1;
        std::cin >> y1;
    
        double x2;
        std::cin >> x2;
        double y2;
        std::cin >> y2;

        double x3;
        std::cin >> x3;
        double y3;
        std::cin >> y3;
        
        
            trouglovi[i] = std::make_shared<Trougao>(std::make_pair(x1, y1), std::make_pair(x2, y2), std::make_pair(x3, y3));
        
    }

    double delta_x;
    double delta_y;
    
    double ugaoRotacije;
    double faktorSkaliranja;
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> delta_x;
    std::cin >> delta_y;
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [delta_x, delta_y](std::shared_ptr<Trougao> tro) {tro->Transliraj(delta_x, delta_y); return tro; });
    
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugaoRotacije;
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [ugaoRotacije](std::shared_ptr<Trougao> tro) {tro->Rotiraj(tro->DajCentar(), ugaoRotacije); return tro; });
    
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktorSkaliranja;
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [faktorSkaliranja](std::shared_ptr<Trougao> tro) {tro->Skaliraj(tro->DajTjeme(1), faktorSkaliranja); return tro; });
    
    std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> tro1, std::shared_ptr<Trougao> tro2) {return tro1->DajPovrsinu() < tro2->DajPovrsinu();})    ;
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;   
    std::for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> shrptr){
       shrptr->Ispisi();
       std::cout << std::endl;
    });
    
    std::cout << "Trougao sa najmanjim obimom: ";
    
    (*std::min_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> tro1, std::shared_ptr<Trougao> tro2) {return tro1->DajObim() < tro2->DajObim(); }))->Ispisi();
    
    std::cout << std::endl;
    std::cout << "Parovi identicnih trouglova:" << std::endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i != j)
                if (DaLiSuIdenticni(*trouglovi[i], *trouglovi[j]))
                {
                    trouglovi[i]->Ispisi();
                    std::cout << " i ";
                    trouglovi[j]->Ispisi();
                    std::cout << std::endl;
                }
        }
    }
    
    std::cout << "Parovi podudarnih trouglova:" << std::endl;

	for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i != j)
                if (DaLiSuPodudarni(*trouglovi[i], *trouglovi[j]))
                {
                    trouglovi[i]->Ispisi();
                    std::cout << " i ";
                    trouglovi[j]->Ispisi();
                    std::cout << std::endl;
                }
        }
    }
    
    std::cout << "Parovi slicnih trouglova:" << std::endl;

	for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i != j)
                if (DaLiSuSlicni(*trouglovi[i], *trouglovi[j]))
                {
                    trouglovi[i]->Ispisi();
                    std::cout << " i ";
                    trouglovi[j]->Ispisi();
                    std::cout << std::endl;
                }
        }
    }
    
	return 0;
}