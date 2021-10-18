/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!


#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <vector>
#include <string>
#include <cmath>

typedef std::pair<double, double> Tacka;


class Trougao
{
    private:
    Tacka tac[3];
    static double izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
    }
    static double udaljenost(const Tacka &t1, const Tacka &t2)
    {
        return std::sqrt(std::pow(t1.first + t2.first, 2) + std::pow(t1.second + t2.second, 2));
    }
    static bool Jednaki(double x, double y, double eps = 1e-10)
    {
        return std::fabs(x-y) <= eps*(std::fabs(x) + std::fabs(y));
    }
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        Postavi(t1,t2,t3);   
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        int ori = Orijentacija(t1,t2,t3);
        if(ori == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        tac[0] = t1;
        tac[1] = t2;
        tac[2] = t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) Postavi(t,tac[1],tac[2]);
        if(indeks == 2) Postavi(tac[0],t,tac[2]);
        if(indeks == 3) Postavi(tac[0],tac[1],t);
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double vrijednost = izraz(t1,t2,t3);
        if(vrijednost < 0 && !Jednaki(vrijednost, 0)) return -1;
        if(vrijednost > 0 && !Jednaki(vrijednost, 0)) return 1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const
    {
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        return tac[indeks-1];
    }
    double DajStranicu(int indeks) const
    {
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1)
        {
            return std::sqrt((tac[1].first-tac[2].first)*(tac[1].first-tac[2].first) + (tac[1].second-tac[2].second)*(tac[1].second-tac[2].second));
        }
        if(indeks == 2)
        {
            return std::sqrt(std::pow(tac[0].first-tac[2].first,2) + std::pow(tac[0].second - tac[2].second,2));
        }
        if(indeks == 3)
        {
            return std::sqrt(std::pow(tac[0].first - tac[1].first,2) + std::pow(tac[0].second - tac[1].second, 2));
        }
        return 0;
    }
    double DajUgao(int indeks) const
    {
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        double a = DajStranicu(1);
        double b = DajStranicu(2);
        double c = DajStranicu(3);
        if(indeks == 1)
        {
            return std::acos((b*b+c*c-a*a)/(2*b*c));
        }
        if(indeks == 2)
        {
            return std::acos((a*a+c*c-b*b)/(2*a*c));
        }
        if(indeks == 3)
        {
            return std::acos((a*a+b*b-c*c)/(2*a*b));
        }
        return 0;
    }
    Tacka DajCentar() const
    {
        Tacka centar;
        centar.first = (tac[0].first + tac[1].first + tac[2].first)/3;
        centar.second = (tac[0].second + tac[1].second + tac[2].second)/3;
        return centar;
    }
    double DajObim() const
    {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        return std::abs(izraz(tac[0], tac[1], tac[2]))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        return Orijentacija(tac[0], tac[1], tac[2]) > 0;
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        double orijentacije[4];
        orijentacije[0] = Orijentacija(tac[0], tac[1], tac[2]);
        orijentacije[1] = Orijentacija(tac[0], tac[1], t);
        orijentacije[2] = Orijentacija(tac[1], tac[2], t);
        orijentacije[3] = Orijentacija(tac[2], tac[0], t);
        int ima = 0;
        for(int i=0; i<4; i++)
        {
            if(Jednaki(orijentacije[i], 0)) ima = 1;
        }
        if(ima == 1) return false;
        int isti = 1;
        for(int i=0; i<3; i++)
        {
            if(!Jednaki(orijentacije[i], orijentacije[i+1])) isti = 0;
        }
        if(isti == 1) return true;
        return false;
    }
    void Ispisi() const
    {
        std::cout << "((" << tac[0].first << "," << tac[0].second << "),(";
        std::cout << tac[1].first << "," << tac[1].second << "),(";
        std::cout << tac[2].first << "," << tac[2].second << "))";
    }
    void Transliraj(double delta_x, double delta_y)
    {
        for(int i=0; i<3; i++) tac[i].first += delta_x;
        for(int i=0; i<3; i++) tac[i].second += delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Tacka centar = DajCentar();
        double dx;
        double dy;
        dx = t.first - centar.first;
        dy = t.second - centar.second;
        Transliraj(dx,dy);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        for(int i=0; i<3; i++)
        {
            Tacka stara = tac[i];
            tac[i].first = t.first + (stara.first - t.first)*std::cos(ugao) - (stara.second - t.second)*std::sin(ugao);
            tac[i].second = t.second + (stara.first - t.first)*std::sin(ugao) + (stara.second - t.second)*std::cos(ugao);
        }
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(Jednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
        for(int i=0; i<3; i++)
        {
            Tacka stara = tac[i];
            tac[i].first = t.first + faktor*(stara.first - t.first);
            tac[i].second = t.second + faktor*(stara.second - t.second);
        }
    }
    void Rotiraj(double ugao)
    {
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor)
    {
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
    {
        int br = 0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                Tacka tacka1, tacka2;
                tacka1 = t1.DajTjeme(i+1);
                tacka2 = t2.DajTjeme(j+1);
                if(Jednaki(tacka1.first, tacka2.first) && Jednaki(tacka1.second, tacka2.second))
                {
                    br++;
                }
            }
        }
        if(br == 3) return true;
        return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
    {
        if(!Jednaki(t1.DajObim(), t2.DajObim()))
        {
            return false;
        }
        if(!Jednaki(t1.DajPovrsinu(), t2.DajPovrsinu()))
        {
            return false;
        }
        double stranice1[3];
        double stranice2[3];
        stranice1[0] = udaljenost(t1.DajTjeme(2),t1.DajTjeme(3));
        stranice1[1] = udaljenost(t1.DajTjeme(1),t1.DajTjeme(3));
        stranice1[2] = udaljenost(t1.DajTjeme(1),t1.DajTjeme(2));
        stranice2[0] = udaljenost(t2.DajTjeme(2),t2.DajTjeme(3));
        stranice2[1] = udaljenost(t2.DajTjeme(1),t2.DajTjeme(3));
        stranice2[2] = udaljenost(t1.DajTjeme(1),t2.DajTjeme(2));
        std::sort(stranice1, stranice1 + 3);
        std::sort(stranice2, stranice2 + 3);
        for(int i=0; i<3; i++)
        {
            if(!Jednaki(stranice1[i], stranice2[i])) return false;
        }
        
        return true;
        
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
    {
        
        return false;
    }
};



int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> vektor(0);
    for(int i=0; i<n; i++)
    {
        try
        {
            Tacka t1,t2,t3;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1.first >> t1.second;
            std::cin >> t2.first >> t2.second;
            std::cin >> t3.first >> t3.second;
            auto troug = std::make_shared<Trougao>(t1,t2,t3);
            vektor.push_back(troug);
        }
        catch(std::domain_error e)
        {
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx >> dy;
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), 
    [=](std::shared_ptr<Trougao> p){
        p->Transliraj(dx,dy);
        p->Rotiraj(ugao);
        p->Skaliraj(p->DajTjeme(1), faktor);
        return p;
    });
    std::sort(vektor.begin(), vektor.end(), 
    [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
           return p1->DajPovrsinu() < p2->DajPovrsinu();
    });
    std::cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(vektor.begin(), vektor.end(), 
    [](std::shared_ptr<Trougao> p)
    {
        p->Ispisi();
        std::cout << std::endl;
    });
    auto pok = std::min_element(vektor.begin(), vektor.end(), 
    [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
        return p1->DajObim() < p2->DajObim();
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*pok)->Ispisi();
    std::cout << std::endl;
    auto p1 = vektor.begin();
    int ima = 0;
    for(p1 = vektor.begin(); p1 != vektor.end() - 1; p1++)
    {
        for(auto p2 = p1 + 1; p2 != vektor.end(); p2++)
        {
            if(DaLiSuIdenticni(**p1, **p2))
            {
                if(ima==0)
                {
                    ima = 1;
                    std::cout << "Parovi identicnih trouglova:\n";
                }
                (*p1)->Ispisi();
                std::cout << " i ";
                (*p2)->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if(ima==0) std::cout << "Nema identicnih trouglova!";
    
    
	return 0;
}