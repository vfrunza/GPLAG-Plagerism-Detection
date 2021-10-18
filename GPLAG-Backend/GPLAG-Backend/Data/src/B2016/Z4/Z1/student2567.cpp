/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;
const double eps = 1E-10;
class Trougao
{
    Tacka a, b, c;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1, t2, t3) == 0)
            throw std::domain_error("Nekorektne pozicije tjemena");
            
        a = t1;
        b = t2;
        c = t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks == 1) 
        {
            if(Orijentacija(t, b, c) == 0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            a = t;
        }
        else if(indeks == 2)
        {
            if(Orijentacija(a, t, c) == 0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            b = t;
        }
        else if(indeks == 3)
        {
            if(Orijentacija(a, b, t) == 0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            c = t;
        }
        else
            throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double s = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) - t3.first * (t1.second - t2.second);
        
        if(s > 0) 
            return 1;
            
        if(s < 0)
            return -1;
            
        if(s == 0)
            return 0;
    }
    Tacka DajTjeme(int indeks) const
    {
        if(indeks == 1) return a;
        else if(indeks == 2) return b;
        else if(indeks == 3) return c;
        else
            throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const
    {
        if(indeks == 1)
            return std::sqrt((b.first - c.first) * (b.first - c.first) + (b.second - c.second) * (b.second - c.second));
            
        else if(indeks == 2)
            return std::sqrt((a.first - c.first) * (a.first - c.first) + (a.second - c.second) * (a.second - c.second));
            
        else if(indeks == 3)
            return std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
            
 
        else    
            throw std::range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const
    {
        if(indeks == 1)
            return std::acos((DajStranicu(2) * DajStranicu(2) + DajStranicu(3) * DajStranicu(3) - DajStranicu(1) * DajStranicu(1)) / 2 * DajStranicu(2) * DajStranicu(3));
            
        else if(indeks == 2)
            return std::acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(3) * DajStranicu(3) - DajStranicu(2) * DajStranicu(2)) / 2 * DajStranicu(1) * DajStranicu(3));
            
        else if(indeks == 3)
            return std::acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(2) * DajStranicu(2) - DajStranicu(3) * DajStranicu(3)) / 2 * DajStranicu(1) * DajStranicu(2));
            
        else
            throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const
    {
        Tacka t;
        t.first = (a.first + b.first + c.first) / 3;
        t.second = (a.second + b.second + c.second) / 3;
        return t;
    }
    double DajObim() const
    {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        return std::fabs(a.first * (b.second - c.second) - b.first * (a.second - c.second) - c.first * (a.second - b.second)) / 2;
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        if(Orijentacija(a, b, c) == 1) return true;
        else if(Orijentacija(a, b, c) == -1) return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        if(Orijentacija(a, b, c) == 1 && Orijentacija(a, b, t) == 1 && Orijentacija(a, t, c) == 1 && Orijentacija(t, b, c) == 1)
            return true;
            
        if(Orijentacija(a, b, c) == -1 && Orijentacija(a, b, t) == -1 && Orijentacija(a, t, c) == -1 && Orijentacija(t, b, c) == -1)
            return true;
            
        return false;
    }
    void Ispisi() const
    {
        std::cout << "((" << a.first << "," << a.second << "),(" << b.first << "," << b.second
                  << "),(" << c.first << "," << c.second << "))\n";
    }
    void Transliraj(double delta_x, double delta_y)
    {
        a.first += delta_x;
        a.second += delta_y;
        b.first += delta_x;
        b.second += delta_y;
        c.first += delta_x;
        c.second += delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Tacka s = DajCentar();
        double dx = std::fabs(t.first - s.first);
        double dy = std::fabs(t.second - s.second);
        Transliraj(dx, dy);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        a.first = t.first + (a.first - t.first) * std::cos(ugao) - (a.second - t.second) * std::sin(ugao);
        b.first = t.first + (b.first - t.first) * std::cos(ugao) - (b.second - t.second) * std::sin(ugao);
        c.first = t.first + (c.first - t.first) * std::cos(ugao) - (c.second - t.second) * std::sin(ugao);
        a.second = t.second + (a.first - t.first) * std::sin(ugao) + (a.second - t.second) * std::cos(ugao);
        b.second = t.second + (b.first - t.first) * std::sin(ugao) + (b.second - t.second) * std::cos(ugao);
        c.second = t.second + (c.first - t.first) * std::sin(ugao) + (c.second - t.second) * std::cos(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(faktor == 0)
            throw std::domain_error("Nekorektan faktor skaliranja");
            
        a.first = t.first + faktor * (a.first - t.first);
        b.first = t.first + faktor * (b.first - t.first);
        c.first = t.first + faktor * (c.first - t.first);
        a.second = t.second + faktor * (a.second - t.second);
        b.second = t.second + faktor * (b.second - t.second);
        c.second = t.second + faktor * (c.second - t.second);
    }
    void Rotiraj(double ugao)
    {
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor)
    {
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((t1.DajTjeme(1) == t2.DajTjeme(1) || t1.DajTjeme(1) == t2.DajTjeme(2) || t1.DajTjeme(1) == t2.DajTjeme(3)) &&
        (t1.DajTjeme(2) == t2.DajTjeme(1) || t1.DajTjeme(2) == t2.DajTjeme(2) || t1.DajTjeme(2) == t2.DajTjeme(3)) &&
        (t1.DajTjeme(3) == t2.DajTjeme(1) || t1.DajTjeme(3) == t2.DajTjeme(2) || t1.DajTjeme(3) == t2.DajTjeme(3)))
            return true;
            
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    double a1 = t1.DajStranicu(1);
    double a2 = t1.DajStranicu(2);
    double a3 = t1.DajStranicu(3);
    double b1 = t2.DajStranicu(1);
    double b2 = t2.DajStranicu(2);
    double b3 = t2.DajStranicu(3);
    double alfa1 = t1.DajUgao(1);
    double alfa2 = t1.DajUgao(2);
    double alfa3 = t1.DajUgao(3);
    double beta1 = t2.DajUgao(1);
    double beta2 = t2.DajUgao(2);
    double beta3 = t2.DajUgao(3);
    
    //SSU 
    if(std::fabs(a1 - b1) < eps && std::fabs(a2 - b2) < eps && std::fabs(alfa1 - beta1) < eps)
        return true;
        
    else if(std::fabs(a2 - b2) < eps && std::fabs(a3 - b3) < eps && std::fabs(alfa2 - beta2) < eps)
        return true;
        
    else if(std::fabs(a1 - b1) < eps && std::fabs(a3 - b3) < eps && std::fabs(alfa1 - beta1) < eps)
        return true;
    //USU
    else if(std::fabs(alfa1 - beta1) < eps && std::fabs(alfa2 - beta2) < eps && std::fabs(a3 - b3) < eps)
        return true;
        
    else if(std::fabs(alfa1 - beta1) < eps && std::fabs(a2 - b2) < eps && std::fabs(alfa3 - beta3) < eps)
        return true;
        
    else if(std::fabs(alfa3 - beta3) < eps && std::fabs(a1 - b1) < eps && std::fabs(alfa2 - beta2) < eps)
        return true;
    //SUS
    else if(std::fabs(alfa1 - beta1) < eps && std::fabs(a2 - b2) < eps && std::fabs(a3 - b3) < eps)
        return true;
        
    else if(std::fabs(alfa2 - beta2) < eps && std::fabs(a1 - b1) < eps && std::fabs(a3 - b3) < eps)
        return true;
        
    else if(std::fabs(alfa3 - beta3) < eps && std::fabs(a1 - b1) < eps && std::fabs(a2 - b2) < eps)
        return true;
    //SSS
    else if(std::fabs(a1 - b1) < eps && std::fabs(a2 - b2) < eps && std::fabs(a3 - b3) < eps)
        return true;
        
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    double a1 = t1.DajStranicu(1);
    double b1 = t1.DajStranicu(2);
    double c1 = t1.DajStranicu(3);
    double a2 = t2.DajStranicu(1);
    double b2 = t2.DajStranicu(2);
    double c2 = t2.DajStranicu(3);
    double alfa1 = t1.DajUgao(1);
    double beta1 = t1.DajUgao(2);
    double gama1 = t1.DajUgao(3);
    double alfa2 = t2.DajUgao(1);
    double beta2 = t2.DajUgao(2);
    double gama2 = t2.DajUgao(3);
    //odnosi stranica:
    double o1 = a1 / a2;
    double o2 = b1 / b2;
    double o3 = c1 / c2;
    //ugao and ugao
    if((std::fabs(alfa1 - alfa2) < eps && std::fabs(beta1 - beta2) < eps) || 
        (std::fabs(alfa1 - alfa2) < eps && std::fabs(gama1 - gama2) < eps) ||
        (std::fabs(beta1 - beta2) < eps && std::fabs(gama1 - gama2) < eps))
            return true;
    //odnosi str i ugao
    else if((std::fabs(o1 - o2) < eps && std::fabs(gama1 - gama2) < eps) ||
            (std::fabs(o1 - o3) < eps && std::fabs(beta1 - beta2) < eps) ||
            (std::fabs(o2 - o3) < eps && std::fabs(alfa1 - alfa2) < eps))
                return true;
    //stranice
    else if(std::fabs(o1 - o2) < eps && std::fabs(o1 - o3) < eps)
        return true;
        
    return false;
}
int main_()
{
    Trougao t();
}
int main()
{
    int a;
    std::vector<std::shared_ptr<Trougao>> v;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> a;
    v.resize(a);
    for(int i = 0; i < v.size(); i++)
    {
        Tacka A, B, C;
        std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
        try
        {
            Trougao t(A, B, C);
            v.at(i) = std::make_shared<Trougao>(t);
        }
        catch(std::domain_error e)
        {
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            i--;
        }
        catch(std::bad_alloc e)
        {
            std::cout << "Problem sa memorijom!";
        }
    }

    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx >> dy;
    //auto p = v.begin();
    std::transform(v.begin(), v.end(), v.begin(), [dx, dy](std::shared_ptr<Trougao> t)
                                                    {
                                                        (*t).Transliraj(dx, dy);
                                                        return t;
                                                    });
    std::cout << "Unesite ugao rotacije: ";
    double u;
    std::cin >> u;
    std::transform(v.begin(), v.end(), v.begin(), [u](std::shared_ptr<Trougao> t)
                                                    {
                                                        (*t).Rotiraj((*t).DajCentar(), u);
                                                        return t;
                                                    });
    std::cout << "Unesite faktor skaliranja: ";
    double s;
    std::cin >> s;
    std::transform(v.begin(), v.end(), v.begin(), [s](std::shared_ptr<Trougao> t)
                                                    {
                                                        (*t).Skaliraj(t->DajTjeme(1), s);
                                                        return t;
                                                    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t, std::shared_ptr<Trougao> t2)
                                    {
                                        return t->DajPovrsinu() > t2->DajPovrsinu();
                                    });
    std::cout << "Trouglovi nakon obavljenih transformacija: \n";
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) {(*t).Ispisi();});
    
    auto pok(std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t, std::shared_ptr<Trougao> t2)
                                                    {
                                                        return (*t).DajObim() > (*t2).DajObim();
                                                    }));
    std::cout << "Trougao s najmanjim obimom: ";
    (*pok)->Ispisi();
    std::cout << std::endl;
    bool slicni = false, identicni = false, podudarni = false;
    std::vector<bool> v1, v2, v3;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size() - 1; j++)
        {
            bool id = DaLiSuIdenticni(*v.at(i), *v.at(j));
            if(id)
            {
                identicni = true;
                if(identicni && i == 0 && j == 1)
                    std::cout << "Parovi identicnih trouglova: \n";
                (*v.at(i)).Ispisi();
                std::cout << " i ";
                (*v.at(j)).Ispisi();
                std::cout << std::endl;
            }
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size() - 1; j++)
        {
            bool sl = DaLiSuSlicni(*v.at(i), *v.at(j));
            if(sl)
            {
                slicni = true;
                if(slicni && i == 0 && j == 1)
                    std::cout << "Parovi slicnih trouglova: \n";
                (*v.at(i)).Ispisi();
                std::cout << " i ";
                (*v.at(j)).Ispisi();
                std::cout << std::endl;
            }
            
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size() - 1; j++)
        {
            bool po = DaLiSuPodudarni(*v.at(i), *v.at(j));
            if(po)
            {
                podudarni = true;
                if(podudarni && i == 0 && j == 1)
                    std::cout << "\nParovi podudarnih trouglova: \n";
                (*v.at(i)).Ispisi();
                std::cout << " i ";
                (*v.at(j)).Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if(identicni == false)
        std::cout << "Nema identicnih trouglova!\n";
    if(podudarni == false)
        std::cout << "Nema podudarnih trouglova!\n";
    if(slicni == false)
        std::cout << "Nema slicnih trouglova!\n";
	return 0;
}