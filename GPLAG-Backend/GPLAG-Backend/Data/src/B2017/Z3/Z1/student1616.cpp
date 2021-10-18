/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <stdexcept>
#include <math.h>



std::function <double (double)> LinearnaInterpolacija (std::vector<std::pair <double, double>> cvorovi)
{
          try 
        {
        for (int i=0; i<cvorovi.size(); i++)
        {
            for (int j=i+1; j<cvorovi.size(); j++)
            {
                if (cvorovi[i].first==cvorovi[j].first) throw std::domain_error ("Neispravni cvorovi");
            }
        }
        }
                    catch (std::domain_error)
            {
                std::cout<<"Neispravni cvorovi";
            }

    
     for (int i=0; i<cvorovi.size(); i++)
    {
        for (int j=i+1; j<cvorovi.size(); j++)
        {
            if (cvorovi[i]>cvorovi[j]) cvorovi[i].swap (cvorovi[j]);
        }
    }
    
    return ( [cvorovi] (double x) 
    {
        

        if (x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error ("Argument izvan opsega");
        
        
        if (x==cvorovi[cvorovi.size()-1].first) return cvorovi[cvorovi.size()-1].second;
        int index;
        for (int i=0; i<cvorovi.size(); i++)
        {
            if (cvorovi[i].first<=x && cvorovi[i+1].first>x)  index=i;
        }
        
        
        double rezultat=cvorovi[index].second+ ((cvorovi[index+1].second-cvorovi[index].second)/(cvorovi[index+1].first-cvorovi[index].first))*(x-cvorovi[index].first);
        return rezultat;
        
    });
    
}


std::function <double (double)> LinearnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double dx)

{
    std::vector<std::pair<double,double>> cvorovi ;
    if (x_min>x_max) throw std::domain_error ("Nekorektni parametri");
    
    double y= f(x_min);
    std::pair<double, double> novi;
    novi= std::make_pair (x_min, y);
    cvorovi.push_back(novi);

    double x_uk=x_min+dx;
    while ( x_uk<x_max )
    {
        double y= f(x_uk);
        std::pair<double, double> novi;
        novi= std::make_pair (x_uk, y);
        cvorovi.push_back(novi);
        x_uk+=dx;
    }
    y= f(x_max);
    novi= std::make_pair (x_max, y);
    cvorovi.push_back(novi);
    

        for (int i=0; i<cvorovi.size(); i++)
        {
            for (int j=i+1; j<cvorovi.size(); j++)
            {
                if (cvorovi[i].first==cvorovi[j].first) throw std::domain_error ("Neispravni cvorovi");
            }
        }

    
     for (int i=0; i<cvorovi.size(); i++)
    {
        for (int j=i+1; j<cvorovi.size(); j++)
        {
            if (cvorovi[i]>cvorovi[j]) cvorovi[i].swap (cvorovi[j]);
        }
    }
    
    return ( [cvorovi] (double x) 
    {
        

            if (x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error ("Argument izvan opsega");
            

        
        if (x==cvorovi[cvorovi.size()-1].first) return cvorovi[cvorovi.size()-1].second;
        int index;
        for (int i=0; i<cvorovi.size(); i++)
        {
            if (cvorovi[i].first<=x && cvorovi[i+1].first>x)  index=i;
        }
        
        
        double rezultat=cvorovi[index].second+ ((cvorovi[index+1].second-cvorovi[index].second)/(cvorovi[index+1].first-cvorovi[index].first))*(x-cvorovi[index].first);
        return rezultat;
        
    });

}

double funkcija (double x)
{ 
    double y=x*x+sin(x);
    return y;
}

int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    
    if (opcija==1)
    {   
        std::vector<std::pair <double, double>> cvorovi;
        std::cout<<"Unesite broj cvorova: ";
        int broj;
        std::cin>>broj;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x,y;
        int i=0;
        while (i<broj)
        {
            std::cin.clear();
            std::cin>>x>>y;
           // std::cout<<std::endl;
            cvorovi.push_back(std::make_pair(x,y));
            i++;
        }
try{
        while (std::cin)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin.clear();
            std::cin>>argument;   
            if (!std::cin) break;

                std::function<double(double)> f= LinearnaInterpolacija(cvorovi);
                double rez=f(argument);
                std::cout<<"f("<<argument<<") = "<<rez<<std::endl;

        }
    
            }catch (std::domain_error)
            {
                std::cout<<"Neispravni cvorovi";
            }
            catch (std::range_error)
            {
                std::cout<<"Argument izvan opsega";
            } 
}
    
    
    if (opcija==2)
    {
        std::cout<<"Unesite krajeve intervala i korak: ";
        int p,k;
        double korak;
      
        std::cin.clear();
        std::cin>>p>>k>>korak;
       
        for (; ;)
        {
         
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin.clear();
            std::cin>>argument;   
            if (!std::cin) break;
        try 
             {
                std::function<double(double)> f= LinearnaInterpolacija (funkcija, p, k, korak);
                double rez=f(argument);
                std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<" fapprox("<<argument<<") = "<<rez<<std::endl;
            }
            catch (std::domain_error const &x)
            {
                std::cout<<&x; 
            }  
            catch (std::range_error)
            {
                std::cout<<"Argument izvan opsega";
            } 
        }
            
        

    }
    
	return 0;
}
