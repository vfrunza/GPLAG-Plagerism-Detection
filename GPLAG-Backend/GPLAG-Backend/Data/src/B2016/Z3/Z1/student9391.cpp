/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <utility>
#include <stdexcept>

#define PI 3.14159
void ProvjeraIspravnosti(std::vector < std::pair < double, double >> cvorovi, int red) {
  if (red < 0 || red > cvorovi.size()) throw std::domain_error("Nedozvoljen red");
  for (int i = 0; i < cvorovi.size(); i++) {
    for (int j = 0; j < cvorovi.size(); j++) {
      if (i != j) {
        if (cvorovi[i].first == cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
      }
    }
  }
}

std:: function < double(double) > BaricentricnaInterpolacija(std::vector < std::pair < double, double >> cvorovi, int red) {
  ProvjeraIspravnosti(cvorovi, red);
  return [cvorovi, red](double x) {
    for (int i = 0; i < cvorovi.size(); i++)
      if (x == cvorovi[i].first) return cvorovi[i].second;
    double rezultat = 0, brojnik = 0, nazivnik = 0;
    for (int i = 0; i < cvorovi.size(); i++) {
      double wi = 0;
      int pocetak = 0, kraj = i;
      if (pocetak < (i - red))
        pocetak = i - red;
      if (kraj > (cvorovi.size() - red - 1))
        kraj = cvorovi.size() - red - 1;
      for (int k = pocetak; k <= kraj; k++) {
        double koef = 1.0;
        double pom = 1.0;
        if (k % 2 == 1) koef = -1.0;
        for (int j = k; j <= (k + red); j++) {
          if (j == i) continue;
          pom = pom / (cvorovi[i].first - cvorovi[j].first);

        }
        wi = wi + koef * pom;
      }

      brojnik = brojnik + wi * cvorovi[i].second / (x - cvorovi[i].first);
      nazivnik = nazivnik + wi / (x - cvorovi[i].first);
    }
    rezultat = brojnik / nazivnik;
    return rezultat;
  };

}


std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> funkcija, double xmin, double xmax, double deltax,int korak)
{
    if(xmin > xmax) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    while(xmin<=xmax)
    {
        cvorovi.push_back(std::make_pair(xmin+deltax,funkcija(xmin)));
    }
    return BaricentricnaInterpolacija(cvorovi,korak);
}
int main ()
{

    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin>>n;
    std::vector<std::pair<double,double>> cvorovi;
    if(n==1)
    {

        std::cout<<"Unesite broj cvorova: ";
        int m;
        std::cin>>m;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<m; i++)
        {
            double x,y;
            std::cin>>x;
            std::cin>>y;
            std::pair<double,double> pom(x,y);
            cvorovi.push_back(pom);
        }
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        auto f=BaricentricnaInterpolacija(cvorovi,red);
        while(true)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(std::cin.fail()) break;
            std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
        }
    }
    else if(n==2)
    {

        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin>>xmin >> xmax >> deltax;
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        auto f=BaricentricnaInterpolacija([](double x)->double{return x*x+sin(x*PI/180);},xmin,xmax,deltax,red);
        while(true)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg, rez;
            std::cin>>arg;
            if(std::cin.fail()) break;
            rez=arg*arg+sin(arg);
            std::cout << "f("<<arg<<") = " << rez << " ";
            std::cout << "fapprox("<<arg<<") = " << f(arg) << std::endl;
        }
    }
    return 0;
}