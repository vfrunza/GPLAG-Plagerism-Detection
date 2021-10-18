/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>

double Testna_funkcija (double x)
{
    return x*x + std::sin(x);
}


std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double,double>> parovi)
{
    return [parovi] (double x)
    {

        if (parovi.size() == 0)                                                   ///Slucaj da nema parova.
            return x;

        double najmanji = parovi[0].first;
        int indeks = 0;
        double najveci = parovi[0].first;
        for (int i {}; i<parovi.size(); i++)                                      ///Sortiranje vektora parova u novi vektor.
        {
            if (parovi[i].first < najmanji)
            {
                najmanji = parovi[i].first;
                indeks = i;
            }

            if (parovi[i].first>najveci)
                najveci = parovi[i].first;
        }

        std::vector<std::pair<double,double>> v;
        v.push_back(parovi[indeks]);
        int k = 0;

        int n;
        for (int i {}; i<parovi.size(); i++)
        {
            if (i != indeks)
            {
                if (parovi[i].first == v[0].first)
                    throw std::domain_error ("Neispravni cvorovi");

                najmanji = najveci;
                for (int j {}; j<parovi.size(); j++)
                {
                    if (parovi[j].first <= najmanji && parovi[j].first>v[k].first)
                    {
                        najmanji = parovi[j].first;
                        n = j;
                    }
                }

                v.push_back(parovi[n]);
                k++;
            }
        }


        for (int i {1}; i<v.size(); i++)                                          ///Provjera da li ima istih cvorova.
        {
            if (v[i].first == v[i-1].first)
                throw std::domain_error ("Neispravni cvorovi");
        }

        if (x < v[0].first || x>v[v.size()-1].first)                              ///Provjera opsega.
            throw std::range_error ("Argument izvan opsega");

        for (int i {}; i<v.size(); i++)                                           ///Slucaj da x ima cvornu vrijednost.
        {
            if (x == v[i].first)
                return v[i].second;
        }


        for (int i {}; i<v.size()-1; i++)                                         ///Proracun interpolacije.
        {
            if (x>v[i].first && x<v[i+1].first)
                return v[i].second + (v[i+1].second-v[i].second)*(x-v[i].first)/(v[i+1].first-v[i].first);
        }
    };
}


std::function<double(double)> LinearnaInterpolacija(double f (double), double x_min, double x_max, double delta_x)
{
    if (x_min > x_max)
        throw std::domain_error ("Nekorektni parametri");

    if (delta_x<0)
        throw std::domain_error ("Nekorektni parametri");

    if (x_min == x_max && delta_x == 0)
        return f;


    return [f, x_min, x_max, delta_x] (double x)
    {

        if (x < x_min || x>x_max)                                                   ///Provjera opsega.
            throw std::range_error ("Argument izvan opsega");

        std::vector<double> rez_x;
        std::vector<double> rez_y;

        double suma = x_min;

        while (suma<=x_max)
        {
            rez_x.push_back(suma);
            rez_y.push_back(f(suma));

            suma+=delta_x;
        }

        auto veca_x = std::lower_bound(rez_x.begin(), rez_x.end(), x);
        int razlika = veca_x-rez_x.begin();
        auto veca_y = rez_y.begin();
        for (int i {}; i<razlika; i++)
            veca_y++;

        if (*veca_x == x)
            return *veca_y;


        auto manja_x = std::lower_bound(rez_x.begin(), rez_x.end(), x);
        manja_x--;
        razlika = manja_x-rez_x.begin();
        auto manja_y = rez_y.begin();
        for (int i {}; i<razlika; i++)
            manja_y++;


        return *manja_y + (*veca_y-*manja_y)*(x-*manja_x)/(*veca_x-*manja_x);
    };
}




int main ()
{
    try
    {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;

        if (opcija == 1)
        {
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;

            std::vector<std::pair<double,double>> v;

            std::cout<<"Unesite cvorove kao parove x y: ";
            for (int i {}; i<n; i++)
            {
                double a,b;
                std::cin>>a>>b;
                v.push_back(std::make_pair(a,b));
            }


            while (true)
            {
                auto f = LinearnaInterpolacija(v);
                if (v.size() != 0)                                              ///Test za ispravnost cvorova.
                    f(v[0].first);
                char znak = '"';
                std::cout<<"Unesite argument (ili "<<znak<<"kraj"<<znak<<" za kraj): ";
                double x;
                std::cin>>x;
                try
                {
                    if (!std::cin)
                        break;

                    std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                }
                catch (std::range_error e)
                {
                    std::cout<<e.what()<<std::endl;
                }
            }
        }

        else if (opcija == 2)
        {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x_min, x_max, delta_x;
            std::cin>>x_min>>x_max>>delta_x;


            while (true)
            {
                auto f = LinearnaInterpolacija(Testna_funkcija,x_min,x_max,delta_x);
                f(x_min);                                                       ///Test za ispravnost parametara.
                char znak = '"';
                std::cout<<"Unesite argument (ili "<<znak<<"kraj"<<znak<<" za kraj): ";
                double x;
                std::cin>>x;
                
                try
                {
                    if (!std::cin)
                        break;

                    std::cout<<"f("<<x<<") = "<<Testna_funkcija(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
                }
                catch (std::range_error e)
                {
                    std::cout<<e.what()<<std::endl;
                }
            }
        }
    }
    catch (std::domain_error e)
    {
        std::cout<<e.what();
    }
    return 0;
}
