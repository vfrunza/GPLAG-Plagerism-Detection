#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>


typedef std::pair <double, double> Tacka;

class Trougao
{
    Tacka tacka1;
    Tacka tacka2;
    Tacka tacka3;
    int index;
    double faktor; 
    double Ugao;
    
    public: 
    
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if (Orijentacija(t1,t2,t3) == 0)
        {
            throw std::domain_error ("Nekorektne pozicije tjemena");
        }
        
        this -> tacka1 = t1;
        this -> tacka2 = t2;
        this -> tacka3 = t3;
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if (Orijentacija(t1,t2,t3) == 0)
        {
            throw std::domain_error ("Nekorektne pozicije tjemena");
        }
        
        this -> tacka1 = t1;
        this -> tacka2 = t2;
        this -> tacka3 = t3;
    }
    void Postavi (int indeks, const Tacka &t)
    {
        if (indeks != 1 && indeks != 2 && indeks != 3)
        {
            throw std::range_error ("Nekorektan indeks");
        }
        
        this -> tacka1 = t;
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if ((t1.first*(t2.second-t3.second)- t2.first*(t1.second-t3.second) + t3.first*(t1.second - t2.second)) > 0)
        {
            return 1;
        }
        
        if ((t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second)) < 0)
        {
            return -1;
        }
        
        else return 0;
        
    }
    Tacka DajTjeme (int indeks) const
    {
        if (indeks != 1 && indeks != 2 && indeks != 3)
        {
            throw std::range_error ("Nekorektan indeks");
        }
        if (indeks == 1)
        {
            return tacka1;
        }
        
        if (indeks == 2)
        {
            return tacka2;
        }
        
        if (indeks == 3)
        {
            return tacka3;
        }
    }
    
    double DajStranicu (int indeks) const
    {
        if (indeks != 1 && indeks != 2 && indeks != 3)
        {
            throw std::range_error ("Nekorektan indeks");
        }
        double s;
        if (indeks == 1)
        {
            s = sqrt ((tacka3.first - tacka2.first)*(tacka3.first - tacka2.first) + (tacka3.second - tacka2.second)*(tacka3.second-tacka3.second));
        }
        
        if (indeks == 2)
        {
            s = sqrt ((tacka3.first - tacka1.first)*(tacka3.first - tacka1.first) + (tacka3.second - tacka2.second)* (tacka3.second - tacka2.second));
        }
        
        if (indeks == 3)
        {
            s = sqrt ((tacka2.first - tacka1.first)*(tacka2.first - tacka1.first) + (tacka2.second - tacka1.second)*(tacka2.second - tacka1.second));
        }
        
        return s;
    }
    
    double DajUgao (int indeks) const;
    
    Tacka DajCentar () const
    {
        Tacka t3;
        double x_t, y_t;
        
        x_t = ((tacka1.first + tacka2.first + tacka3.first)/3);
        y_t = ((tacka1.second + tacka2.second + tacka3.second)/3);
        
        t3.first = x_t;
        t3.second = y_t;
        return t3;
    }
    
    double DajObim () const
    {
        return ((sqrt((tacka2.first - tacka1.first)*(tacka2.first - tacka1.first) + (tacka2.second - tacka1.second)*(tacka2.second - tacka1.second))) +
                 (sqrt((tacka3.first - tacka2.first)*(tacka3.first - tacka2.first) + (tacka3.second - tacka2.second)* (tacka3.second - tacka2.second))) +
                 (sqrt((tacka3.first - tacka1.first)*(tacka3.first - tacka1.first) + (tacka3.second - tacka1.second)*(tacka3.second - tacka1.second))));
    }
    
    double DajPovrsinu () const 
    {
        return (1/2*(abs(tacka1.first*(tacka2.second - tacka3.second) - tacka2.first*(tacka1.second - tacka3.second) + tacka3.first*(tacka1.second - tacka2.second))));
    }
    
    bool DaLiJePozitivnoOrijentiran () const
    {
        bool t = false;
        if (Orijentacija(tacka1, tacka2, tacka3) == 1)
        {
            t = true;
        }
        return t;
    }
    
    bool DaLiJeUnutra (const Tacka &t) const;
    void Ispisi() const
    {
        std::cout << "(("  <<  tacka1.first  << "," << tacka1.second << "),(" <<
                     tacka2.first << "," << tacka2.second << "),(" <<
                     tacka3.first << "," << tacka3.second  << "))";
    }
    void Transliraj (double delta_x, double delta_y)
    {
        tacka1.first = tacka1.first + delta_x;
        tacka1.second = tacka1.second + delta_y;
        tacka2.first = tacka2.first + delta_x;
        tacka2.second = tacka2.second + delta_y;
        tacka3.first = tacka3.first + delta_x;
        tacka3.second = tacka3.second + delta_y;

    }
    void Centriraj (const Tacka &t)
    {
        Tacka t3;
        double t_x, t_y;
        t_x = ((tacka1.first + tacka2.first + tacka3.first )/3);
        t_y = ((tacka1.second + tacka2.second + tacka3.second)/3);
        
        t3.first = t_x;
        t3.second = t_y; 
        
        t3.first = t3.first + t.first;
        t3.second = t3.second + t.second;
    }
    void Rotiraj (const Tacka &t, double ugao)
    {
        
        tacka1.first = (t.first + (tacka1.first - t.first)*cos(ugao) + (tacka1.second - t.second)*sin(ugao));
        tacka1.second = (t.second + (tacka1.first - t.first)*sin(ugao) + (tacka1.second - t.second)*cos(ugao));
        tacka2.first = (t.first + (tacka2.first - t.first)*cos(ugao) + (tacka2.second - t.second)*sin(ugao));
        tacka2.second = (t.second + (tacka2.first - t.first)*sin(ugao) + (tacka2.second - t.second)*cos(ugao));
        tacka3.first = (t.first + (tacka3.first - t.first)*cos(ugao) + (tacka3.second - t.second)*sin(ugao));
        tacka3.second = (t.second + (tacka3.first - t.first)*sin(ugao) + (tacka3.second - t.second)*cos(ugao));
        
        
    }
    void Skaliraj (const Tacka &t, double faktor);

    void Rotiraj (double ugao);
    
    void Skaliraj (double faktor);

    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
    
};


 void Trougao::Rotiraj (double ugao)
 {
     Tacka neka_tacka;
     double x_t, y_t;
     
     x_t = ((tacka1.first + tacka2.first + tacka3.first)/3);
     y_t = ((tacka1.second + tacka2.second + tacka3.second)/3);
     
     neka_tacka.first = x_t;
     neka_tacka.second = y_t;
     
     tacka1.first = (neka_tacka.first + (tacka1.first - neka_tacka.first)*cos(ugao) - (tacka1.second - neka_tacka.second)*sin(ugao));
     tacka1.second = (neka_tacka.second + (tacka1.first - neka_tacka.first)*sin(ugao) + (tacka1.second - neka_tacka.second)*cos(ugao));
     tacka2.first = (neka_tacka.first + (tacka2.first - neka_tacka.first)*cos(ugao) - (tacka2.second - neka_tacka.second)*sin(ugao));
     tacka2.second = (neka_tacka.second + (tacka2.first - neka_tacka.first)*sin(ugao) + (tacka2.second - neka_tacka.second)*cos(ugao));
     tacka3.first = (neka_tacka.first + (tacka3.first - neka_tacka.first)*cos(ugao) - (tacka3.second - neka_tacka.second)*sin(ugao));
     tacka3.second = (neka_tacka.second + (tacka3.first - neka_tacka.first)*sin(ugao) + (tacka3.second - neka_tacka.second)*cos(ugao));
 }

double Trougao::DajUgao(int indeks) const 
{
    if (indeks != 1 && indeks !=2 && indeks !=3)
    {
        throw std::range_error ("Nekorektan indeks");
    }
    double a,b,c;
    
    a = sqrt((tacka2.first - tacka1.first)*(tacka2.first - tacka1.first) + (tacka2.second - tacka1.second)*(tacka2.second - tacka1.second));
    b = sqrt((tacka3.first - tacka2.first)*(tacka3.first - tacka2.first) + (tacka3.second - tacka2.second)*(tacka3.second - tacka2.second));
    c = sqrt((tacka3.first - tacka1.first)*(tacka3.first - tacka1.first) + (tacka3.second - tacka1.second)*(tacka3.second - tacka1.second));
    
    double alfa;
    
    if (indeks == 1)
    {
        alfa = acos((b*b+c*c-a*a)/(2*b*c));
    }
    
    if (indeks == 2)
    {
        alfa = acos((a*a+c*c-b*b)/(2*a*c));
    }
    
    if (indeks == 3)
    {
        alfa = acos((a*a+b*b-c*c)/(2*a*b));
    }
    
    return alfa;
}

bool Trougao::DaLiJeUnutra (const Tacka &t1) const
{
    double P1,P2,P3,P4,P;
    bool t = true;
    
    P1 = (1/2*abs(tacka1.first*(tacka2.second-tacka3.second) + tacka2.first*(tacka3.second-tacka1.second) + tacka3.first*(tacka1.second-tacka2.second)));
    P2 = (1/2*abs(tacka1.first*(tacka2.second-t1.first) + tacka2.first*(t1.second - tacka1.second) + t1.first*(tacka1.second - tacka2.second)));
    P3 = (1/2*abs(tacka1.first*(t1.second - tacka3.second) + t1.first*(tacka3.second - tacka1.second) + tacka3.first*(tacka1.second - t1.second)));
    P4 = (1/2*abs(tacka2.first*(tacka3.second - t1.second) + tacka3.first*(t1.second - tacka2.second) + t1.first*(tacka2.second-tacka3.second)));
    
    P = P1+P2+P3;
    
    if (P > P4)
    {
        t = false;
    }
    
    return t;
}


void Trougao::Skaliraj (const Tacka &t, double faktor)
{
    if (faktor == 0.)
    {
        throw std::domain_error ("Nekorektan faktor skaliranja");
    }
    
    tacka1.first = (t.first + faktor*(tacka1.first - t.first));
    tacka1.second = (t.second + faktor*(tacka1.second - t.second));
    tacka2.first = (t.first + faktor*(tacka2.first - t.first));
    tacka2.second = (t.second + faktor*(tacka2.second - t.second));
    tacka3.first = (t.first + faktor*(tacka3.first - t.first));
    tacka3.second = (t.second + faktor*(tacka3.second - t.second));
}

void Trougao::Skaliraj (double faktor)
{
    if (faktor == 0)
    {
        std::domain_error ("Nekorektan faktor skaliranja");
    }
    
    Tacka neka_tacka;
    double x_t, y_t;
    
    x_t = ((tacka1.first + tacka2.first + tacka3.first)/3);
    y_t = ((tacka1.second + tacka2.second + tacka3.second)/3);
    
    neka_tacka.first = x_t;
    neka_tacka.second = y_t;
    
    tacka1.first = (neka_tacka.first + faktor*(tacka1.first - neka_tacka.first));
    tacka1.second = (neka_tacka.second + faktor*(tacka1.second - neka_tacka.second));
    tacka2.first = (neka_tacka.first + faktor*(tacka2.first - neka_tacka.first));
    tacka2.second = (neka_tacka.second + faktor*(tacka2.second - neka_tacka.second));
    tacka3.first = (neka_tacka.first + faktor*(tacka3.first - neka_tacka.first));
    tacka3.second = (neka_tacka.second + faktor*(tacka3.second - neka_tacka.second));
}

int main()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;

    std::vector<std::shared_ptr<Trougao>> v(n);
    std::vector<std::shared_ptr<Trougao>> novi(n);
 
    Tacka tacka1;
    Tacka tacka2;
    Tacka tacka3;
   
    for (int i = 0; i < n; i++)
    {
        
        
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> tacka1.first >> tacka1.second;
        std::cin >> tacka2.first >> tacka2.second;
        std::cin >> tacka3.first >> tacka3.second;
        try
        {
          v[i] = std::make_shared<Trougao> (Trougao(tacka1,tacka2,tacka3));
        }
        
        catch (std::domain_error izuzetak)
        {
            std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
            i--;
        }
        
        
    }

    Trougao trougao(tacka1,tacka2,tacka3);
    trougao.Postavi(tacka1,tacka2,tacka3);
    
    
    int x,y;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> x;
    std::cin >> y;
    std::cout << std::endl;
   /* std::transform (&v[0], &v[v.size()-1], [](double x, double y)
    {
        Trougao::Transliraj(x,y);
    });
    */
    
    double u;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> u;
    std::cout << std::endl;
    
    double z;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> z;
    std::cout << std::endl;
    /*std::transform (v.begin(), v.end(), v.begin(), [](std::shared_ptr<Trougao> pok1, double z)
    {
        pok1 -> Skaliraj(z);
        return pok1;
    });*/

    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl; 
    
    std::sort (&v[0], &v[v.size()-1], [] (std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2)
    {
       return (pok1 -> DajPovrsinu() < pok2 -> DajPovrsinu()); 
    });
    
    
    std::for_each(&v[0], &v[v.size()-1], [] (std::shared_ptr<Trougao> &pok1)
    {
        pok1 -> Ispisi();
        std::cout << std::endl;
    });
 
    
    std::cout << "Trougao sa najmanjim obimom: ";
    
    auto it = min_element (v.begin(), v.end(), [] (std::shared_ptr<Trougao> &pok1, std::shared_ptr<Trougao> &pok2)
    {
        return pok1 -> DajObim() < pok2 -> DajObim();
    });
    
    (*it)->Ispisi();
    std::cout << std::endl;

  

   

    return 0;
    
}