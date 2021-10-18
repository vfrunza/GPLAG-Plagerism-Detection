/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double>Tacka;

double str1(double x2, double y2, double x3, double y3)
{
    return sqrt(pow((x2-x3), 2) + pow((y2-y3), 2));
}

double str2(double x1, double y1, double x3, double y3)
{
    return sqrt(pow((x1-x3), 2) + pow((y1-y3), 2));
}

double str3(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}

double rotacija_x(double x, double y, double xc, double yc, double ugao)
{
    return xc + (x-xc)*cos(ugao) - (y-yc)*sin(ugao);
}

double rotacija_y(double x, double y, double xc, double yc, double ugao)
{
    return yc + (x-xc)*sin(ugao) + (y-yc)*cos(ugao);
}

class Trougao
{
    Tacka tac1,tac2,tac3;
    static double Obim(const Trougao &t)
    {
       return str1(t.tac2.first,t.tac2.second,t.tac3.first,t.tac3.second) + str2(t.tac1.first,t.tac1.second,t.tac3.first,t.tac3.second) + str3(t.tac1.first,t.tac1.second,t.tac2.first,t.tac2.second); 
    }
    static bool Jednako(double x, double y, double eps = 1e-10)
    {
        return std::fabs(x - y) <= eps * (std::fabs(x) + std::fabs(y));
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1,t2,t3) == 0)
        {
            throw std::domain_error("Nekorektne pozicije tjemena");
        }
        tac1 = t1;
        tac2 = t2;
        tac3 = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1,t2,t3) == 0)
            throw std::domain_error("Nekorektne pozicije tjemena");
        tac1 = t1;
        tac2 = t2;
        tac3 = t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks == 1)
        {
            if(Orijentacija(t, tac2, tac3) == 0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            tac1.first = t.first;
            tac1.second = t.second;
        }
        if(indeks == 2)
        {
            if(Orijentacija(tac1, t, tac3) == 0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            tac2.first = t.first;
            tac2.second = t.second;
        }
        if(indeks == 3)
        {
            if(Orijentacija(tac1, tac2, t) == 0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            tac3.first = t.first;
            tac3.second = t.second;
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double a;
        a = t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
        if(a > 0)
            return 1;
        if(a < 0)
            return -1;
        if(a == 0)
            return 0;
    }
    Tacka DajTjeme(int indeks) const
    {
        if(indeks == 1)
            return tac1;
        if(indeks == 2)
            return tac2;
        if(indeks == 3)
            return tac3;
    }
    double DajStranicu(int indeks) const
    {
        double d;
        if(indeks == 1)
            d = sqrt((tac2.first - tac3.first)*(tac2.first - tac3.first) + (tac2.second - tac3.second)*(tac2.second - tac3.second));
        if(indeks == 2)
            d = sqrt((tac1.first - tac3.first)*(tac1.first - tac3.first) + (tac1.second - tac3.second)*(tac1.second - tac3.second));
        if(indeks == 3)
            d = sqrt((tac1.first - tac2.first)*(tac1.first - tac2.first) + (tac1.second - tac2.second)*(tac1.second - tac2.second));
        return d;
    }
    double DajUgao(int indeks) const
    {
        double ugao;
        if(indeks == 1)
            ugao = acos((pow(str2(tac1.first, tac1.second, tac3.first, tac3.second), 2) + pow(str3(tac1.first,tac1.second,tac2.first,tac2.second), 2) - pow(str1(tac2.first,tac2.second,tac3.first,tac3.second), 2)) / (2 * str2(tac1.first,tac1.second,tac3.first,tac3.second) * str3(tac1.first,tac1.second,tac2.first,tac2.second)));
        if(indeks == 2)
            ugao = acos((pow(str1(tac2.first,tac2.second,tac3.first,tac3.second), 2) + pow(str3(tac1.first,tac1.second,tac2.first,tac2.second), 2) - pow(str2(tac1.first,tac1.second,tac3.first,tac3.second), 2)) / (2 * str1(tac2.first,tac2.second,tac3.first,tac3.second) * str3(tac1.first,tac1.second,tac2.first,tac2.second)));
        if(indeks == 3)
            ugao = acos((pow(str1(tac2.first,tac2.second,tac3.first,tac3.second), 2) + pow(str2(tac1.first,tac1.second,tac3.first,tac3.second), 2) - pow(str3(tac1.first,tac1.second,tac2.first,tac2.second), 2)) / (2 * str1(tac2.first,tac2.second,tac3.first,tac3.second) * str2(tac1.first,tac1.second,tac3.first,tac3.second)));
        //ugao = ugao * 180 / (4 * atan(1));
        return ugao;
    }
    Tacka DajCentar() const
    {
        Tacka tt;
        tt.first = (tac1.first + tac2.first + tac3.first) / 3;
        tt.second = (tac1.second + tac2.second + tac3.second) / 3;
        return tt;
    }
    double DajObim() const
    {
        return str1(tac2.first,tac2.second,tac3.first,tac3.second) + str2(tac1.first,tac1.second,tac3.first,tac3.second) + str3(tac1.first,tac1.second,tac2.first,tac2.second);
    }
    double DajPovrsinu() const
    {
        return (0.5 * fabs(tac1.first*(tac2.second - tac3.second) - tac2.first*(tac1.second - tac3.second) + tac3.first*(tac1.second - tac2.second)));    
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        if(Orijentacija(tac1,tac2,tac3) == 1)
            return true;
        if(Orijentacija(tac1,tac2,tac3) == -1)
            return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        int a = Orijentacija(tac1, tac2, tac3);
        if(Orijentacija(tac1, tac2, t) == a && Orijentacija(tac2, tac3, t) == a && Orijentacija(tac3, tac1, t) == a)
            return true;
        return false;
    }
    void Ispisi() const
    {
        std::cout<<"(("<<tac1.first<<","<<tac1.second<<"),("<<tac2.first<<","<<tac2.second<<"),("<<tac3.first<<","<<tac3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y)
    {
        tac1.first += delta_x;
        tac2.first += delta_x;
        tac3.first += delta_x;
        tac1.second += delta_y;
        tac2.second += delta_y;
        tac3.second += delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Tacka cen = DajCentar();
        double razlika1 = abs(cen.first - t.first);
        double razlika2 = abs(cen.second - t.second);
        if(cen.first < t.first)
        {
            tac1.first += razlika1;
            tac2.first += razlika1;
            tac3.first += razlika1;
        }
        if(cen.second < t.second)
        {
            tac1.second += razlika2;
            tac2.second += razlika2;
            tac3.second += razlika2;
        }
        if(cen.first > t.first)
        {
            tac1.first -= razlika1;
            tac2.first -= razlika1;
            tac3.first -= razlika1;
        }
        if(cen.second > t.second)
        {
            tac1.second -= razlika2;
            tac2.second -= razlika2;
            tac3.second -= razlika2;
        }
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        tac1.first = rotacija_x(tac1.first, tac1.second, t.first, t.second, ugao);
        tac1.second = rotacija_y(tac1.first, tac1.second, t.first, t.second, ugao);
        tac2.first = rotacija_x(tac2.first, tac2.second, t.first, t.second, ugao);
        tac2.second = rotacija_y(tac2.first, tac2.second, t.first, t.second, ugao);
        tac3.first = rotacija_x(tac3.first, tac3.second, t.first, t.second, ugao);
        tac3.second = rotacija_y(tac3.first, tac3.second, t.first, t.second, ugao);
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(faktor == 0)
            throw std::domain_error("Nekorektan faktor skaliranja");
        tac1.first = t.first + faktor*(tac1.first - t.first);
        tac1.second = t.second + faktor*(tac1.second - t.second);
        tac2.first = t.first + faktor*(tac2.first - t.first);
        tac2.second = t.second + faktor*(tac2.second - t.second);
        tac3.first = t.first + faktor*(tac3.first - t.first);
        tac3.second = t.second + faktor*(tac3.second - t.second);
    }
    void Rotiraj(double ugao)
    {
        tac1.first = rotacija_x(tac1.first, tac1.second, DajCentar().first, DajCentar().second, ugao);
        tac1.second = rotacija_y(tac1.first, tac1.second, DajCentar().first, DajCentar().second, ugao);
        tac2.first = rotacija_x(tac2.first, tac2.second, DajCentar().first, DajCentar().second, ugao);
        tac2.second = rotacija_y(tac2.first, tac2.second, DajCentar().first, DajCentar().second, ugao);
        tac3.first = rotacija_x(tac3.first, tac3.second, DajCentar().first, DajCentar().second, ugao);
        tac3.second = rotacija_y(tac3.first, tac3.second, DajCentar().first, DajCentar().second, ugao);
    }
    void Skaliraj(double faktor)
    {
        if(faktor == 0)
            throw std::domain_error("Nekorektan faktor skaliranja");
        tac1.first = DajCentar().first + faktor*(tac1.first - DajCentar().first);
        tac1.second = DajCentar().second + faktor*(tac1.second - DajCentar().second);
        tac2.first = DajCentar().first + faktor*(tac2.first - DajCentar().first);
        tac2.second = DajCentar().second + faktor*(tac2.second - DajCentar().second);
        tac3.first = DajCentar().first + faktor*(tac3.first - DajCentar().first);
        tac3.second = DajCentar().second + faktor*(tac3.second - DajCentar().second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
    {
        bool prva(false), druga(false), treca(false);
        if((Jednako(t1.tac1.first, t2.tac1.first) || Jednako(t1.tac1.first, t2.tac2.first) || Jednako(t1.tac1.first, t2.tac3.first)) && (Jednako(t1.tac1.second, t2.tac1.second) || Jednako(t1.tac1.second, t2.tac2.second) || Jednako(t1.tac1.second, t2.tac3.second)))
            prva = true;
        if((Jednako(t1.tac2.first, t2.tac1.first) || Jednako(t1.tac2.first, t2.tac2.first) || Jednako(t1.tac2.first, t2.tac3.first)) && (Jednako(t1.tac2.second, t2.tac1.second) || Jednako(t1.tac2.second, t2.tac2.second) || Jednako(t1.tac2.second, t2.tac3.second)))
            druga = true;
        if((Jednako(t1.tac3.first, t2.tac1.first) || Jednako(t1.tac3.first, t2.tac2.first) || Jednako(t1.tac3.first, t2.tac3.first)) && (Jednako(t1.tac3.second, t2.tac1.second) || Jednako(t1.tac3.second, t2.tac2.second) || Jednako(t1.tac3.second, t2.tac3.second)))
            treca = true;
        if(prva == true && druga == true && treca == true)
            return true;
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
    {
        bool prva(false),druga(false),treca(false),cetvrta(false),peta(false),sesta(false);
        /*if(Jednako(Obim(t1), Obim(t2)))
        {
            if(Jednako(str1(t1.tac2.first,t1.tac2.second,t1.tac3.first,t1.tac3.second), str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second)))
             {   prva = true;
             std::cout<<"valja";
             }
            if(Jednako(str2(t1.tac1.first,t1.tac1.second,t1.tac3.first,t1.tac3.second), str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second)))
               { druga = true;
               std::cout<<"valja";
               }
            if(Jednako(str3(t1.tac1.first,t1.tac1.second,t1.tac2.first,t1.tac2.second), str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second)))
            {    treca = true;
                std::cout<<"valja";
            }
            if(prva == true && druga == true && treca == true)
                return true;
        }
        return false;*/
        double alfa1, beta1, alfa2, beta2, gama2;
        /*alfa1 = acos((pow(str2(t1.tac1.first,t1.tac1.second,t1.tac3.first,t1.tac3.second), 2) + pow(str3(t1.tac1.first,t1.tac1.second,t1.tac2.first,t1.tac2.second), 2) - pow(str1(t1.tac2.first,t1.tac2.second,t1.tac3.first,t1.tac3.second), 2)) / (2 * str2(t1.tac1.first,t1.tac1.second,t1.tac3.first,t1.tac3.second) * str3(t1.tac1.first,t1.tac1.second,t1.tac2.first,t1.tac2.second)));
        beta1 = acos((pow(str1(t1.tac1.first,t1.tac1.second,t1.tac3.first,t1.tac3.second), 2) + pow(str3(t1.tac1.first,t1.tac1.second,t1.tac2.first,t1.tac2.second), 2) - pow(str2(t1.tac1.first,t1.tac1.second,t1.tac3.first,t1.tac3.second), 2)) / (2 * str1(t1.tac2.first,t1.tac2.second,t1.tac3.first,t1.tac3.second) * str3(t1.tac1.first,t1.tac1.second,t1.tac2.first,t1.tac2.second)));*/
        double a1 = str1(t1.tac2.first,t1.tac2.second,t1.tac3.first,t1.tac3.second);
        double b1 = str2(t1.tac1.first,t1.tac1.second,t1.tac3.first,t1.tac3.second);
        double c1 = str3(t1.tac1.first,t1.tac1.second,t1.tac2.first,t1.tac2.second);
        /*alfa2 = acos((pow(str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second), 2) + pow(str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second), 2) - pow(str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second), 2)) / (2 * str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second) * str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second)));
        beta2 = acos((pow(str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second), 2) + pow(str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second), 2) - pow(str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second), 2)) / (2 * str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second) * str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second)));
        gama2 = acos((pow(str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second), 2) + pow(str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second), 2) - pow(str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second), 2)) / (2 * str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second) * str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second)));*/
        double a2 = str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second);
        double b2 = str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second);
        double c2 = str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second);
        alfa1 = t1.DajUgao(1);
        beta1 = t1.DajUgao(2);
        alfa2 = t2.DajUgao(1);
        beta2 = t2.DajUgao(2);
        gama2 = t2.DajUgao(3);
        std::vector<double>v1{a1,b1,c1};
        std::vector<double>v2{a2,b2,c2};
        
        if(Jednako(alfa1, alfa2))
            //if((Jednako(b1/a2, c1/a2) || Jednako(b1/b2,c1/a2) || Jednako(b1/c2,c1/a2) && Jednako()) || (Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2)))
            if((Jednako(b1,a2) || Jednako(b1,b2) || Jednako(b1,c2)) && (Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2)))    
                prva = true;
        if(Jednako(alfa1,beta2))
            if((Jednako(b1,a2) || Jednako(b1,b2) || Jednako(b1,c2)) && (Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2)))
                druga = true;
        if(Jednako(alfa1,gama2))
            if((Jednako(b1,a2) || Jednako(b1,b2) || Jednako(b1,c2)) && (Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2)))
                treca = true;
        if(Jednako(beta1,alfa2))
            if((Jednako(a1,a2) || Jednako(a1,b2) || Jednako(a1,c2)) && (Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2)))
                cetvrta = true;
        if(Jednako(beta1,beta2))
            if((Jednako(a1,a2) || Jednako(a1,b2) || Jednako(a1,c2)) && (Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2)))
                peta = true;
        if(Jednako(beta1,gama2))
            if((Jednako(a1,a2) || Jednako(a1,b2) || Jednako(a1,c2)) && (Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2)))
                sesta = true;
        //std::cout<<alfa1<<" "<<beta1<<" "<<alfa2<<" "<<beta2<<" "<<gama2<<" ";
        if(prva == true || druga == true || treca == true && cetvrta == true || peta == true || sesta == true)
            return true;
        return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
    {
        double alfa1, beta1, alfa2, beta2, gama2;
        alfa1 = t1.DajUgao(1);
        beta1 = t1.DajUgao(2);
        alfa2 = t2.DajUgao(1);
        beta2 = t2.DajUgao(2);
        gama2 = t2.DajUgao(3);
        double a1 = str1(t1.tac2.first,t1.tac2.second,t1.tac3.first,t1.tac3.second);
        double b1 = str2(t1.tac1.first,t1.tac1.second,t1.tac3.first,t1.tac3.second);
        double c1 = str3(t1.tac1.first,t1.tac1.second,t1.tac2.first,t1.tac2.second);
        
        double a2 = str1(t2.tac2.first,t2.tac2.second,t2.tac3.first,t2.tac3.second);
        double b2 = str2(t2.tac1.first,t2.tac1.second,t2.tac3.first,t2.tac3.second);
        double c2 = str3(t2.tac1.first,t2.tac1.second,t2.tac2.first,t2.tac2.second);
        bool prva(false), druga(false);
        if(Jednako(alfa1,alfa2) || Jednako(alfa1,beta2) || Jednako(alfa1,gama2))
            if(Jednako(b1,a2) || Jednako(b1,b2) || Jednako(b1,c2) && Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2))
                prva = true;
        if(Jednako(beta1,alfa2) || Jednako(beta1,beta2) || Jednako(beta1,gama2))
            if(Jednako(a1,a2) || Jednako(a1,b2) || Jednako(a1,c2) && Jednako(c1,a2) || Jednako(c1,b2) || Jednako(c1,c2))
                druga = true;
        double pom = a1 / a2;
        if(prva == true && druga == true)
            return true;
        return false;
    }
};
int main ()
{
	/*Trougao t1({3,6},{3,14},{9,6});
	Trougao t2({3,6},{9,6},{9,14});
	std::cout<<DaLiSuIdenticni(t1,t2)<<" ";*/
	/*Trougao t1({3,6},{9,6},{3,14});
	Trougao t2({3,6},{3,14},{9,6});
	Trougao t3({4,4},{12,4},{12,10});
	Trougao t4({7,5},{-1,7},{5,9});
	std::cout<<DaLiSuPodudarni(t1,t2)<<" "<<DaLiSuPodudarni(t1,t3)<<" "<<DaLiSuPodudarni(t2,t3)<<" "<<DaLiSuPodudarni(t3,t4);
	std::cout<<t.DajCentar().first<<" "<<t.DajCentar().second<<std::endl;
	t.Transliraj(2,3);
	t.Ispisi();
	t.Rotiraj(0);
	t.Ispisi();
	t.Skaliraj({1,2},2);
	t.Ispisi();*/
	std::cout<<"Koliko zelite kreirati trouglova: ";
	int n;
	std::cin>>n;
	std::vector<std::shared_ptr<Trougao>>v;
	for(int i = 1; i <= n; i++)
	{
	    double x1,y1,x2,y2,x3,y3;
	    std::cout<<"Unesite podatke za "<<i<<". trougao (x1 y1 x2 y2 x3 y3): ";
	    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
	    try
	    {
	    Trougao t({x1,y1},{x2,y2},{x3,y3});
	    std::shared_ptr<Trougao>p(new Trougao(t));
	    v.push_back(p);
	    //p->Ispisi();
	    }
	    catch(std::domain_error e)
	    {
	        std::cout<<e.what()<<", ponovite unos!"<<std::endl;
	        i--;
	        continue;
	    }
	 }
	 std::cout<<"Unesite vektor translacije (dx dy): ";
	 double dx, dy;
	 std::cin>>dx>>dy;
	 std::cout<<"Unesite ugao rotacije: ";
	 double ugao;
	 std::cin>>ugao;
	 std::cout<<"Unesite faktor skaliranja: ";
	 double faktor;
	 std::cin>>faktor;
	 std::vector<std::shared_ptr<Trougao>>novi1(n);
	 /*for(int i = 0; i < n; i++)
	 {
	 Trougao t({0,0},{0,0},{0,0});
	 std::shared_ptr<Trougao>p1(new Trougao(t));
	 novi1.push_back(p1);
	 }*/
	 transform(v.begin(), v.end(), novi1.begin(), [dx,dy,ugao,faktor](std::shared_ptr<Trougao>p)
	 {
	      //p->Ispisi();
	      p->Transliraj(dx,dy);
	      p->Rotiraj(ugao);
	      Tacka tt = p->DajTjeme(1);
	      p->Skaliraj({tt.first,tt.second},faktor);
	      //p->Ispisi();
	      return p;
	 });
	 sort(novi1.begin(), novi1.end(), [](std::shared_ptr<Trougao>p1,std::shared_ptr<Trougao>p2)
	 {
	     //std::cout<<p1->DajPovrsinu()<<" "<<p2->DajPovrsinu()<<"*";
	     return p1->DajPovrsinu() < p2->DajPovrsinu();
	 });
	 std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
	 for_each(novi1.begin(), novi1.end(), [](std::shared_ptr<Trougao>p)
	 {
	     p->Ispisi();
	     std::cout<<std::endl;
	 });
	 std::cout<<"Trougao sa najmanjim obimom: ";
	 std::shared_ptr<Trougao>p1 = *min_element(novi1.begin(), novi1.end(), [](std::shared_ptr<Trougao>p1,std::shared_ptr<Trougao>p2)
	 {
	     return p1->DajObim() < p2->DajObim();
	 });
	 p1->Ispisi();
	 std::cout<<std::endl;
	 std::vector<std::shared_ptr<Trougao>>pomocni1;
	 std::vector<std::shared_ptr<Trougao>>pomocni2;
	 std::vector<std::shared_ptr<Trougao>>pomocni3;
	 for(int i = 0; i < novi1.size(); i++)
	 {
	     for(int j = 0; j < novi1.size(); j++)
	     {
	         if(DaLiSuIdenticni(*(novi1[i]), *(novi1[j])) == 1 && i != j)
	         {
	             pomocni1.push_back(novi1[i]);
	             pomocni1.push_back(novi1[j]);
	         }
	     }
	 }
	 if(pomocni1.size() == 0)
	    std::cout<<"Nema identicnih trouglova!"<<std::endl;
	 else
	 {
	   std::cout<<"Parovi identicnih trouglova: "<<std::endl; 
	 
     }
	 
	 for(int i = 0; i < novi1.size(); i++)
	 {
	     for(int j = 0; j < novi1.size(); j++)
	     {
	         if(DaLiSuPodudarni(*(novi1[i]), *(novi1[j])) == 1 && i != j)
	         {
	             pomocni2.push_back(novi1[i]);
	             pomocni2.push_back(novi1[j]);
	         }
	     }
	 }
	 if(pomocni2.size() == 0)
	    std::cout<<"Nema podudarnih trouglova!";
	  else
	  {
	      std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
	      int i(0);
	      for_each(pomocni2.begin(), pomocni2.end(), [i] (std::shared_ptr<Trougao>p)
	      {
	          p->Ispisi();
	          i++;
	          if(i % 2 != 0)
	          std::cout<<" i ";
	          else
	          std::cout<<std::endl;
	      });
	  }
	  /* std::cout<<pomocni.size();
	 else
	 {
	     for(int i = 0; i < pomocni.size(); i+2)
	     {
	         pomocni[i]->Ispisi();
	         std::cout<<" i ";
	         pomocni[i+1]->Ispisi();
	     }
	 }*/
	
	/*Trougao h({3,6},{11,4},{9,8});
    Trougao g({7,5},{-1,7},{5,9});
	std::cout<<DaLiSuSlicni(h,g)<<std::endl;
	std::cout<<h.DajUgao(1)<<" "<<h.DajUgao(2)<<" "<<h.DajUgao(3)<<std::endl;
	std::cout<<g.DajUgao(1)<<" "<<g.DajUgao(2)<<" "<<g.DajUgao(3)<<std::endl;
	Trougao t1({1.5,4}, {2,1.5}, {1,1});
	t1.Postavi(2, {1,1});
	t1.Ispisi();
	Trougao t({1,1},{2,1.5},{1.5,4});
	Trougao tt({1,3},{5,2},{4,4});
	Trougao ttt({5,2},{1,3},{4,4});
	std::cout<<DaLiSuIdenticni(tt, ttt);
	t.Ispisi();
	std::cout<<std::endl;
	Trougao t1({1,1},{2,2},{3,1});
	t1.Postavi({1,1}, {2,1.5}, {1.5,4});
	t1.Ispisi();
	std::cout<<std::endl;
	std::cout<<t.Orijentacija({1,1},{2,1.5},{1.5,4})<<std::endl;
	std::cout<<t1.Orijentacija({1,1},{2,2}, {1.5,3.5})<<std::endl;
	Tacka t11;
	t11 = t.DajTjeme(3);
	std::cout<<t11.first<<" "<<t11.second<<std::endl;
	std::cout<<t.DajStranicu(2)<<std::endl;
	std::cout<<t.DajUgao(1)<<" "<<t.DajUgao(2)<<" "<<t.DajUgao(3)<<std::endl;
	Tacka tit = t.DajTjeme(2);
	std::cout<<tit.first<<" "<<tit.second<<std::endl;
	Trougao t12({2,4}, {3,-1}, {-3,3});
	Tacka u(0,1);
	Tacka ttt = t12.DajCentar();
	std::cout<<ttt.first<<" "<<ttt.second;
	std::cout<<t.DajPovrsinu()<<std::endl;
	std::cout<<t.DajObim()<<std::endl;
	std::cout<<t12.DaLiJeUnutra(u)<<std::endl;
	std::cout<<t.DaLiJePozitivnoOrijentiran()<<std::endl;
	t.Centriraj(u);
    t.Ispisi();
	t.Transliraj(1,2);
	std::cout<<std::endl;
	t.Ispisi();
	t.Rotiraj(u, (4*atan(1) / 4));
	std::cout<<std::endl;
	t.Ispisi();
	t12.Ispisi();*/
	return 0;
}