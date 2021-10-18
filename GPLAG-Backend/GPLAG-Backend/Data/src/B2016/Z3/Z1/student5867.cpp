/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <algorithm>
#include <stdexcept>

/*double xxsinx ( double x)
{
    return x * x + std::sin(x);
}*/

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>>v, int d)
{
    int n = v.size();
    if(d < 0 || d >= n)
        throw std::domain_error("Nedozvoljen red");
    std::vector<double>hai;
    for(int i = 0; i < v.size(); i++)
        hai.push_back(v[i].first);
    for(int i = 0; i < hai.size(); i++)
    {
        for(int j = 0; j < hai.size(); j++)
            if(hai[i] == hai[j] && i != j)
                throw std::domain_error("Neispravni cvorovi");
    }
    //std::cout<<n<<std::endl;
    std::vector<double>pomocni(n);
    auto a = std::make_pair(17,3);
    v.insert(v.begin(), a);
    auto b = 2016;
    pomocni.insert(pomocni.begin(), 2016);
    if(d == 0)
    {
        for(int i = 1; i <= n; i++)
            pomocni[i] = std::pow(-1, i-1);
    }
    else 
    {
    for(int i = 1; i <= n; i++)  //prolazim kroz w
    {
        pomocni[i] = 0;
        for(int k = std::max(1, i-d); k <= std::min(i, n-d); k++)
        {
            //std::cout<<k<<std::endl;
            double proizvod = std::pow(-1, k-1);
            //proizvod = 1;
            //std::cout<<suma<<std::endl;
            for(int j = k; j <= k + d; j++)
            {
               if(j != i)
                    proizvod = proizvod * (1 / (v[i].first - v[j].first));
            }
            pomocni[i] += proizvod;
        }
    }
    }
    
    //for(auto x : pomocni)
      // std::cout<<x<<" ";
  
    return [d, pomocni, n, v](double x) 
    {
        double prva_suma = 0;
        for(int i = 1; i <= n; i++)
        {
            if(x == v[i].first)
                return v[i].second;
            prva_suma += ((pomocni[i] * v[i].second) / (x - v[i].first));
        }
       // std::cout<<prva_suma<<std::endl;
        double druga_suma = 0;
        for(int i = 1; i <= n; i++)
        {
            if(x == v[i].first)
                return v[i].second;
            druga_suma += (pomocni[i] / (x - v[i].first));
        }
        double vrati = prva_suma / druga_suma;
        return vrati;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)>fun, double xmin, double xmax, double delta, int d)
{

    std::vector<std::pair<double, double>>v;
    if(xmin > xmax || delta <= 0)
        throw std::domain_error("Nekorektni parametri");
    for(double i = xmin; i <= xmax; i += delta)
    {
        double x1 = i;
        double y1 = fun(i);
        v.push_back(std::make_pair(x1,y1));
    }
    return [d, v] (double x) 
    {
        auto funi = BaricentricnaInterpolacija(v, d);
        return funi(x);
    };    
}

int main ()
{
	//auto fun = BaricentricnaInterpolacija({{1,3},{2,5},{4,4},{5,2}, {7,1}}, 2);
	//std::cout<<std::endl<<fun(5);
	std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	int n;
	std::cin>>n;
	std::vector<std::pair<double, double>>v;
	if(n == 1)
	{
	  int cvorovi;
	  std::cout<<"Unesite broj cvorova: ";
	  std::cin>>cvorovi;
	  std::cout<<"Unesite cvorove kao parove x y: ";
	  for(int i = 0; i < cvorovi; i++)
	  {
	      double x, y;
	      std::cin>>x>>y;
	      v.push_back(std::make_pair(x,y));
	  }
	  std::cout<<"Unesite red interpolacije: ";
	  int d;
	  std::cin>>d;
	  while(17)
	  {
	      std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	      double argi;
    	  if(!(std::cin >> argi))
    	    break;
    	    try
    	    {
	            auto fun = BaricentricnaInterpolacija(v, d);
	            std::cout<<"f("<<argi<<") = "<<fun(argi)<<std::endl;
    	    }
    	    catch(std::domain_error er1)
    	    {
    	        std::cout<<er1.what();
    	        return 0;
    	    }
	            //std::cout<<"f("<<argi<<") = "<<fun(argi)<<std::endl;
	  }
	}
	//auto funi = BaricentricnaInterpolacija(xxsinx, 0, 1, 0.1, 2);
	//std::cout<<funi(0.3);
	if(n == 2)
	{
	    double xmin, xmax, delta;
	    std::cout<<"Unesite krajeve intervala i korak: ";
	    std::cin>>xmin>>xmax>>delta;
	    std::cout<<"Unesite red interpolacije: ";
	    int d;
	    std::cin>>d;
	    while(3)
	    {
	        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	        double argi;
	        if(!(std::cin >> argi))
	            break;
	        //auto fun = BaricentricnaInterpolacija(v, d);
	 try {
	            auto funi = BaricentricnaInterpolacija([](double x){ return x * x + sin(x);}, xmin, xmax, delta, d);
	            std::cout<<"f("<<argi<<") = "<<argi * argi + sin(argi)<<" "<<"fapprox("<<argi<<") = "<<funi(argi)<<std::endl;
	 }
	 catch(std::domain_error er2)
	 {
	     std::cout<<er2.what();
	     return 0;
	 }
	  
	    }
	}
	
	return 0;
}