/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <algorithm>
#include <memory>

typedef std::pair<double, double> Tacka;

class Trougao
{
    std::vector<Tacka> tacke;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) : tacke(3) 
    {
        if(Orijentacija(t1, t2, t3) == 0)
            throw std::domain_error ("Nekorektne pozicije tjemena");
        tacke[0] = t1; 
        tacke[1] = t2; 
        tacke[2] = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) 
    {
        if (Orijentacija(t1, t2, t3) == 0)
            throw std::domain_error ("Nekorektne pozicije tjemena, ponovite unos");
        tacke[0] = t1; tacke[1] = t2; tacke[2] = t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks < 1 || indeks > 3)
            throw std::range_error ("Nekorektan indeks");
        if(indeks == 1)
            if(Orijentacija(t, tacke[1], tacke[2]) == 0)
                throw std::domain_error ("Nekorektne pozicije tjemena, ponovite unos");
        if(indeks == 2)
            if(Orijentacija(tacke[0], t , tacke[2]) == 0)
                throw std::domain_error ("Nekorektne pozicije tjemena, ponovite unos");
        if(indeks == 3)
            if(Orijentacija(tacke[0], tacke[1], t) == 0)
                throw std::domain_error ("Nekorektne pozicije tjemena, ponovite unos");
        tacke[indeks-1] = t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        int suma;
        suma = t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
        if(suma > 0)
            return 1;
        else if(suma < 0)
            return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const 
    {
        if(indeks < 1 || indeks > 3)
            throw std::range_error ("Nekorektan indeks");
        return tacke[indeks-1];
    }
    double DajStranicu(int indeks) const
    {
        if(indeks < 1 || indeks > 3)
            throw std::range_error ("Nekorektan indeks");
        if(indeks == 1)
            return sqrt(pow((tacke[2].first - tacke[1].first),2) + pow((tacke[2].second - tacke[1].second),2));
        else if(indeks == 2)
            return sqrt(pow((tacke[2].first - tacke[0].first),2) + pow((tacke[2].second - tacke[0].second),2));
        else
            return sqrt(pow((tacke[1].first - tacke[0].first),2) + pow((tacke[1].second - tacke[0].second),2));
    }
    double DajUgao(int indeks) const
    {
        if(indeks < 1 || indeks > 3)
            throw std::range_error ("Nekorektan indeks");
        double ugao;
        if(indeks == 1)
            ugao = std::acos((pow(DajStranicu(2), 2) + pow(DajStranicu(3), 2) - pow(DajStranicu(1), 2))/2*DajStranicu(2)*DajStranicu(3)) * (4*std::atan(1))/180;
        if(indeks == 2)
            ugao = std::acos((pow(DajStranicu(1), 2) + pow(DajStranicu(3), 2) - pow(DajStranicu(2), 2))/2*DajStranicu(1)*DajStranicu(3)) * (4*std::atan(1))/180;    
        if(indeks == 1)
            ugao = std::acos((pow(DajStranicu(1), 2) + pow(DajStranicu(2), 2) - pow(DajStranicu(3), 2))/2*DajStranicu(1)*DajStranicu(2)) * (4*std::atan(1))/180;
        return ugao;
    }
    Tacka DajCentar() const
    {
        Tacka z;
        z.first = (tacke[0].first+tacke[1].first+tacke[2].first)/3;
        z.second = (tacke[0].second+tacke[1].second+tacke[2].second)/3;
        return z;
    }
    double DajObim() const
    {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        return tacke[0].first*(tacke[1].second - tacke[2].second) - tacke[1].first*(tacke[0].second - tacke[2].second) + tacke[2].first*(tacke[0].second - tacke[1].second);
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        if(Orijentacija(tacke[0], tacke[1], tacke[2]) == 1)
            return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        if(Orijentacija(tacke[0], tacke[1], tacke[2]) == 1)
            if(Orijentacija(tacke[0], tacke[1], t) == 1 && Orijentacija(tacke[1], tacke[2], t) == 1 && Orijentacija(tacke[2], tacke[0], t) == 1)
                return true;
        if(Orijentacija(tacke[0], tacke[1], tacke[2]) == -1)
            if(Orijentacija(tacke[0], tacke[1], t) == -1 && Orijentacija(tacke[1], tacke[2], t) == -1 && Orijentacija(tacke[2], tacke[0], t) == -1)
                return true;
        return false;
    }
    void Ispisi() const
    {
        std::cout<<"(("<<tacke[0].first<<","<<tacke[0].second<<"),("<<tacke[1].first<<","<<tacke[1].second<<"),("<<tacke[2].first<<","<<tacke[2].second<<"))"<<std::endl;
    }
    void Transliraj(double   delta_x, double delta_y)
    {
        for(int i = 0; i < 3; i++)
        {
            tacke[i].first += delta_x;
            tacke[i].second += delta_y;
        }
    }
    void Centriraj(const Tacka &t)
    {
        double delta_x(t.first - DajCentar().first), delta_y(t.second - DajCentar().second);
        for(int i = 0; i < 3; i++)
        {
            tacke[i].first += delta_x;
            tacke[i].second += delta_y;      
        }
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        tacke[0].first = t.first + (tacke[0].first - t.first)*cos(ugao) - (tacke[0].second - t.second)*sin(ugao);
        tacke[0].second = t.second + (tacke[0].first - t.first)*sin(ugao) + (tacke[0].second - t.second)*cos(ugao);
        tacke[1].first = t.first + (tacke[1].first - t.first)*cos(ugao) - (tacke[1].second - t.second)*sin(ugao);
        tacke[1].second = t.second + (tacke[1].first - t.first)*sin(ugao) + (tacke[1].second - t.second)*cos(ugao);
        tacke[2].first = t.first + (tacke[2].first - t.first)*cos(ugao) - (tacke[2].second - t.second)*sin(ugao);
        tacke[2].second = t.second + (tacke[2].first - t.first)*sin(ugao) + (tacke[2].second - t.second)*cos(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(faktor == 0)
            throw std::domain_error("Nekorektan faktor skaliranja");
        tacke[0].first = t.first + faktor*(tacke[0].first - t.first);
        tacke[0].second = t.second + faktor*(tacke[0].second - t.second);
        tacke[1].first = t.first + faktor*(tacke[1].first - t.first);
        tacke[1].second = t.second + faktor*(tacke[1].second - t.second);
        tacke[2].first = t.first + faktor*(tacke[2].first - t.first);
        tacke[2].second = t.second + faktor*(tacke[2].second - t.second);
        if(faktor < 0)
            Rotiraj(DajCentar(), 180);
    }
    void Rotiraj(double ugao)
    {
        Tacka t = DajCentar();
        tacke[0].first = t.first + (tacke[0].first - t.first)*cos(ugao) - (tacke[0].second - t.second)*sin(ugao);
        tacke[0].second = t.second + (tacke[0].first - t.first)*sin(ugao) + (tacke[0].second - t.second)*cos(ugao);
        tacke[1].first = t.first + (tacke[1].first - t.first)*cos(ugao) - (tacke[1].second - t.second)*sin(ugao);
        tacke[1].second = t.second + (tacke[1].first - t.first)*sin(ugao) + (tacke[1].second - t.second)*cos(ugao);
        tacke[2].first = t.first + (tacke[2].first - t.first)*cos(ugao) - (tacke[2].second - t.second)*sin(ugao);
        tacke[2].second = t.second + (tacke[2].first - t.first)*sin(ugao) + (tacke[2].second - t.second)*cos(ugao);
    }
    void Skaliraj(double faktor)
    {
        Tacka t = DajCentar();
        if(faktor == 0)
            throw std::domain_error("Nekorektan faktor skaliranja");
        tacke[0].first = t.first + faktor*(tacke[0].first - t.first);
        tacke[0].second = t.second + faktor*(tacke[0].second - t.second);
        tacke[1].first = t.first + faktor*(tacke[1].first - t.first);
        tacke[1].second = t.second + faktor*(tacke[1].second - t.second);
        tacke[2].first = t.first + faktor*(tacke[2].first - t.first);
        tacke[2].second = t.second + faktor*(tacke[2].second - t.second);
        if(faktor < 0)
            Rotiraj(DajCentar(), 180);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    int j = 1;
    while(j != 4)
    {
        bool postoji = false;
        for(int i = 1; i <= 3; i++)
            if(t1.DajTjeme(j) == t2.DajTjeme(i))
                postoji = true;
        if(postoji == false)
            return false;
        j++;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    int j = 1;
    while(j != 4)
    {
        bool postoji = false;
        for(int i = 1; i <= 3; i++)
            if(t1.DajStranicu(j) == t2.DajStranicu(i))
                if(t1.DajUgao(j) == t2.DajUgao(i))
                    postoji = true;
        if(postoji == false)
            return false;
        j++;
    }
    if(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)) != Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)))
        return false;
    return true;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    std::vector<double> vek1(3), vek2(3);
    vek1[0] = t1.DajStranicu(1);
    vek1[1] = t1.DajStranicu(2);
    vek1[2] = t1.DajStranicu(3);
    vek2[0] = t2.DajStranicu(1);
    vek2[1] = t2.DajStranicu(2);
    vek2[2] = t2.DajStranicu(3);
    std::sort(vek1.begin(), vek1.end());
    std::sort(vek2.begin(), vek2.end());
    if(vek1[0]/vek2[0] != vek1[1]/vek2[1] || vek1[0]/vek2[0] != vek1[2]/vek2[2])
        return false;
    return true;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> trouglovi;
    double x1, x2, x3, y1, y2, y3;
    for(int i = 0; i < n; i++)
    {
        try{
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka t1, t2, t3;
        t1.first = x1;
        t1.second = y1;
        t2.first = x2;
        t2.second = y2;
        t3.first = x3;
        t3.second = y3;
        auto pok = std::make_shared<Trougao> (t1, t2, t3);
        trouglovi.push_back(pok);
        }
        catch(std::domain_error x)
        {
            std::cout<<x.what();
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx, dy): ";
    double dx, dy;
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::vector<std::shared_ptr<Trougao>> trouglovi2(n);
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi2.begin(), [dx, dy, ugao, faktor](std::shared_ptr<Trougao> p){p->Transliraj(dx, dy); p->Rotiraj(ugao); p->Skaliraj(faktor); return p;});
    std::for_each(trouglovi2.begin(), trouglovi2.end(), [](std::shared_ptr<Trougao> p1) {p1->Ispisi();});
	return 0;
}
