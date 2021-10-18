/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <memory>
static const double epsilon(1e-10); 

typedef std::pair<double, double> Tacka;


bool Uporedi(double a, double b)
    {
        if(fabs(a-b) < epsilon) return true;
        return false;
    }


class Trougao 
{
    private:
    Tacka t1, t2, t3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double alfa = atan(t1.second / t1.first);
        double beta = atan(t2.second / t2.first);
        double gama = atan(t3.second / t3.first);
        if(Uporedi(alfa, beta) && Uporedi(beta, gama))
            throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1 = t1; Trougao::t2 = t2; Trougao::t3 = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        *this = Trougao(t1, t2, t3);
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks < 0 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) *this = Trougao(t, t2, t3);
        if(indeks == 2) *this = Trougao(t1, t, t3);
        if(indeks == 3) *this = Trougao(t1, t2, t);
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double orijent(t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.first-t2.first));
        if(orijent < 0) return -1;
        if(orijent > 0) return 1;
        if(std::fabs(orijent) < epsilon)
        return 0;
    }
    Tacka DajTjeme(int indeks) const
    {
        if(indeks < 0 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return t1;
        if(indeks == 2) return t2;
        if(indeks == 3) return t3;
    }
    double DajStranicu(int indeks) const
    {
        if(indeks < 0 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) 
            return std::sqrt((t2.first-t3.first)*(t2.first-t3.first) + (t2.second-t3.second)*(t2.second-t3.second));
        if(indeks == 2)
            return std::sqrt((t1.first-t3.first)*(t1.first-t3.first) + (t1.second-t3.second)*(t1.second-t3.second));
        if(indeks == 3)
            return std::sqrt((t1.first-t2.first)*(t1.first-t2.first) + (t1.second-t2.second)*(t1.second-t2.second));
    }
    double DajUgao(int indeks) const
    {
        if(indeks < 0 || indeks > 3) throw std::range_error("Nekorektan indeks");
        double alfa = acos((DajStranicu(2)*DajStranicu(2) + DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1))/2*DajStranicu(2)*DajStranicu(3));
        double beta = acos((DajStranicu(3)*DajStranicu(3) + DajStranicu(1)*DajStranicu(1) - DajStranicu(2)*DajStranicu(2))/2*DajStranicu(3)*DajStranicu(1));
        double gama = acos((DajStranicu(1)*DajStranicu(1) + DajStranicu(2)*DajStranicu(2) - DajStranicu(3)*DajStranicu(3))/2*DajStranicu(1)*DajStranicu(2));
        if(indeks == 1) return alfa;
        if(indeks == 2) return beta;
        if(indeks == 3) return gama;
    }
    Tacka DajCentar() const
    {
        return Tacka((t1.first + t2.first + t3.first)/3, (t1.second + t2.second + t3.second)/3);
    }
    double DajObim() const
    {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        double s(DajObim()/2);
        return sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)));
    }
    bool DaLiJePozitvinoOrijentiran() const
    {
         if(Orijentacija(t1, t2, t3) > 0) return true;
         return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const 
    {
        if(DaLiJePozitvinoOrijentiran())
        {
            if(Orijentacija(t1, t2, t) < 0 && Orijentacija(t2, t3, t) > 0 && Orijentacija(t3, t1, t) > 0)
                return true;
            return false;
        }
        if(!DaLiJePozitvinoOrijentiran())
        {
            if(Orijentacija(t1, t2, t) < 0 && Orijentacija(t2, t3, t) < 0 && Orijentacija(t3, t1, t) < 0)
                return true;
            return false;
        }
    }
    void Ispisi() const
    {
        std::cout << "((" << t1.first << "," << t2.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y)
    {
        t1.first = t1.first + delta_x;  t1.second = t1.second + delta_y;
        t2.first = t2.first + delta_x;  t2.second = t2.second + delta_y;
        t3.first = t3.first + delta_x;  t3.second = t3.second + delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Tacka a = DajCentar();
        double delta_x = t.first - a.first;
        double delta_y = t.second - a.second;
        Transliraj(delta_x, delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        t1.first = t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao);
        t1.second = t.second + (t1.first - t.first)*sin(ugao) + (t1.second -t.second)*cos(ugao);
        t2.first = t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao);
        t2.second = t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao);
        t3.first = t.first + (t3.first - t.first)*cos(ugao) + (t3.second - t.second)*sin(ugao);
        t3.second = t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(std::fabs(faktor) < epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first = t.first + faktor*(t1.first - t.first);
        t1.second = t.second + faktor*(t1.second - t.second);
        t2.first = t.first + faktor*(t2.first - t.first);
        t2.second = t.second + faktor*(t2.second - t.second);
        t3.first = t.first + faktor*(t3.first - t.first);
        t3.second = t.second + faktor*(t3.second - t.second);
    }
    void Rotiraj(double ugao)
    {
        Tacka t = DajCentar();
        t1.first = t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao);
        t1.second = t.second + (t1.first - t.first)*sin(ugao) + (t1.second -t.second)*cos(ugao);
        t2.first = t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao);
        t2.second = t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao);
        t3.first = t.first + (t3.first - t.first)*cos(ugao) + (t3.second - t.second)*sin(ugao);
        t3.second = t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao);
    }
    void Skaliraj(double faktor)
    {
        if(std::fabs(faktor) < epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t = DajCentar();
        t1.first = t.first + faktor*(t1.first - t.first);
        t1.second = t.second + faktor*(t1.second - t.second);
        t2.first = t.first + faktor*(t2.first - t.first);
        t2.second = t.second + faktor*(t2.second - t.second);
        t3.first = t.first + faktor*(t3.first - t.first);
        t3.second = t.second + faktor*(t3.second - t.second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    //if((t1.DajStranicu(1) == t2.DajStranicu(1) || t1.DajStranicu(1) == t2.DajStranicu(2) || t1.DajStranicu(1) == t2.DajStranicu(3))
     //   && (t1.DajStranicu(2) == t2.DajStranicu(1) || t1.DajStranicu(2) == t2.DajStranicu(2) || t1.DajStranicu(2) == t2.DajStranicu(3))
      //  && (t1.DajStranicu(3) == t2.DajStranicu(1) || t1.DajStranicu(3) == t2.DajStranicu(2) || t1.DajStranicu(3) == t2.DajStranicu(3)))
      if((Uporedi(t1.DajStranicu(1), t2.DajStranicu(1)) || Uporedi(t1.DajStranicu(1), t2.DajStranicu(2)) || Uporedi(t1.DajStranicu(1), t2.DajStranicu(3)))
      && (Uporedi(t1.DajStranicu(2), t2.DajStranicu(1)) || Uporedi(t1.DajStranicu(2), t2.DajStranicu(2)) || Uporedi(t1.DajStranicu(2), t2.DajStranicu(3)))
      && (Uporedi(t1.DajStranicu(3), t2.DajStranicu(1)) || Uporedi(t1.DajStranicu(3), t2.DajStranicu(2)) || Uporedi(t1.DajStranicu(3), t2.DajStranicu(3))))
      return true;
      else return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if((Uporedi(t1.DajUgao(1), t2.DajUgao(1)) || Uporedi(t1.DajUgao(1), t2.DajUgao(2)) || Uporedi(t1.DajUgao(1), t2.DajUgao(3)))
        && (Uporedi(t1.DajUgao(2), t2.DajUgao(1)) || Uporedi(t1.DajUgao(2), t2.DajUgao(2)) || Uporedi(t1.DajUgao(2), t2.DajUgao(3)))
        && (Uporedi(t1.DajUgao(3), t2.DajUgao(1)) || Uporedi(t1.DajUgao(3), t2.DajUgao(2)) || Uporedi(t1.DajUgao(3), t2.DajUgao(3))))
        return true;
        else return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((t1.DajTjeme(1) == t2.DajTjeme(1) || t1.DajTjeme(1) == t2.DajTjeme(2) || t1.DajTjeme(1) == t2.DajTjeme(3))
       && (t1.DajTjeme(2) == t2.DajTjeme(1) || t1.DajTjeme(2) == t2.DajTjeme(2) || t1.DajTjeme(2) == t2.DajTjeme(3))
       && (t1.DajTjeme(3) == t2.DajTjeme(1) || t1.DajTjeme(3) == t2.DajTjeme(2) || t1.DajTjeme(3) == t2.DajTjeme(3)))
    //if((Uporedi(t1.DajTjeme(1), t2.DajTjeme(2)) || Uporedi(t1.DajTjeme(1), t2.DajTjeme(2)) || Uporedi(t1.DajTjeme(1), t2.DajTjeme(3)))
      //  && (Uporedi(t1.DajTjeme(2), t2.DajTjeme(2)) || Uporedi(t1.DajTjeme(2), t2.DajTjeme(2)) || Uporedi(t1.DajTjeme(2), t2.DajTjeme(3)))
        //&& (Uporedi(t1.DajTjeme(3), t2.DajTjeme(2)) || Uporedi(t1.DajTjeme(3), t2.DajTjeme(2)) || Uporedi(t1.DajTjeme(3), t2.DajTjeme(3))))
        return true;
        else return false;
}

int main ()
{
   try
    {
        int n;
        std::cout << "Koliko zelite kreirati trouglova: ";
        std::cin >> n;
        std::vector<std::shared_ptr<Trougao>> vector(n);
        for(int i=1; i<=n; i++)
        {
            //Tacka a, b, c;
            std::cout << "Unesite podatke za " << i << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::vector<double> v;
            for(int j=0; j<3; j++)
            {
                double x, y;
                std::cin >> x >> y;
                v.push_back(x);
                v.push_back(y);
            }
            Tacka a, b, c;
            a.first = v[0]; 
            a.second = v[1];
            b.first = v[2];
            b.second = v[3];
            c.first = v[4];
            c.second = v[5];
            try
            {
                auto pomocni = std::make_shared<Trougao> (a, b, c);
                vector[i-1] = pomocni;
            }
            catch(std::domain_error e)
            {
                std::cout << e.what() << ", ponovite unos!" << std::endl;
                i--;
            }
            catch(...)
            {
                throw;
            }
        }
        std::cout << "Unesite vektor translacije (dx dy): ";
        double dx, dy;
        std::cin >> dx >> dy;
        double ugao;
        std::cout << "Unesite ugao rotacije: ";
        std::cin >> ugao;
        double faktor;
        std::cout << "Unesite faktor skaliranja: ";
        std::cin >> faktor;
        std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
        std::transform(vector.begin(), vector.end(), vector.begin(), [=] (std::shared_ptr<Trougao> k){
            (*k).Transliraj(dx, dy);
            (*k).Rotiraj(ugao);
            (*k).Skaliraj((*k).DajTjeme(1), faktor);
            return k;
        });
        std::sort(vector.begin(), vector.end(), [] (std::shared_ptr<Trougao> jedan, std::shared_ptr<Trougao> dva) {
            return ((*jedan).DajPovrsinu() < (*dva).DajPovrsinu());
        });
        auto minimalni = (std::min_element(vector.begin(), vector.end(), [] (std::shared_ptr<Trougao> jedan, std::shared_ptr<Trougao> dva) {
            return ((*jedan).DajObim() < (*dva).DajObim());
        }));
        std::for_each(vector.begin(), vector.end(), [] (std::shared_ptr<Trougao> jedan) {
             (*jedan).Ispisi();
        });
        std::cout << "Trougao sa najmanjim obimom: ";
        (*(*minimalni)).Ispisi();
        //std::cout << std::endl;
        int da = 0;
        for(int i=0; i<vector.size()-1; i++)
        {
            for(int j=i+1; j<vector.size(); j++)
            {
                if(DaLiSuIdenticni(*vector[i], *vector[j]))
                {
                    if(da == 0)
                    {
                        std::cout << "Parovi identicnih trouglova:" << std::endl;
                        da = 1;
                    }
                    (*vector[i]).Ispisi();
                    std::cout << " i ";
                    (*vector[j]).Ispisi();
                    std::cout << std::endl;
                }
            }
        }
         if(da == 0)
                std::cout << "Nema identicnih trouglova!" << std::endl;
            da = 0;
            for(int i=0; i<vector.size()-1; i++)
            {
                for(int j=i+1; i<vector.size(); j++)
                {
                    if(DaLiSuPodudarni(*vector[i], *vector[j]))
                    {
                        if(da == 0)
                            std::cout << "Parovi podudarnih trouglova:" << std::endl;
                            da = 1;
                        (*vector[i]).Ispisi();
                        std::cout << " i ";
                        (*vector[j]).Ispisi();
                        std::cout << std::endl;
                    }
                }
            }
             if(da == 0) 
                    std::cout << "Nema podudarnih trouglova!" << std::endl;
                da = 0;
            for(int i=0; i<vector.size()-1; i++)
            {
                for(int j=i+1; j<vector.size(); j++)
                {
                    if(DaLiSuSlicni(*vector[i], *vector[j]))
                    {
                        if(da == 0)
                            std::cout << "Parovi slicnih trouglova:" << std::endl;
                        da = 1;
                        (*vector[i]).Ispisi();
                        std::cout << " i ";
                        (*vector[j]).Ispisi();
                        std::cout << std::endl;
                    }
                }
            }
            if(da == 0) 
                std::cout << "Nema slicnih trouglova!" << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(std::range_error e)
    {
        std::cout << e.what() << std::endl;
    }
   // catch(...)
   // {
   //     std::cout << "Nema memorije!";
    //}
        
    return 0;
}

    