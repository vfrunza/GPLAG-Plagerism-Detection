#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx)
{
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for(double i=xmin; i<xmax;)
    {
        std::pair<double, double> par;
        par=std::make_pair(i, f(i));
        cvorovi.push_back(par);
        i+=dx;
    }
    /*std::cout << "Vektor cvorova glasi: ";
    for(int i=xmin; i<cvorovi.size(); i++)
    {
        std::cout << cvorovi[i].first << " " << cvorovi[i].second << std::endl;
    }*/
    return([cvorovi](double x)
            {
                double x1;
                double x2;
                double y1;
                double y2;
                if(x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error("Argument izvan opsega");
                int i;
                int j=cvorovi.size()-1;
                for(i=0; i<=j;)
                {
                    double k((i+j)/2);
                    //std::cout << i << " " << j << " " << cvorovi[k].first << std::endl;
                    if(x>=cvorovi[k].first && x<cvorovi[k+1].first)
                    {
                        i=k;
                        break;
                    }
                    else if(x>cvorovi[k].first) i=k;
                    else if(x<cvorovi[k].first) j=k;
                }
                x1=cvorovi[i].first; y1=cvorovi[i].second;
                x2=cvorovi[i+1].first; y2=cvorovi[i+1].second;
                double rez;
                rez=y1+((y2-y1)/(x2-x1))*(x-x1);
                return rez;
            });
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi)
{
    for(int i=0; i<cvorovi.size()-1; i++)
    {
        for(int j=i+1; j<cvorovi.size(); j++)
        {
            if(cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
            else if(cvorovi[i].first>cvorovi[j].first)
            {
                int pomocna_x(cvorovi[i].first);
                int pomocna_y(cvorovi[i].second);
                cvorovi[i].first=cvorovi[j].first;
                cvorovi[i].second=cvorovi[j].second;
                cvorovi[j].first=pomocna_x;
                cvorovi[j].second=pomocna_y;
            }
        }
    }
    return([cvorovi](double x)
            {
                double x1;
                double x2;
                double y1;
                double y2;
                if(x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error("Argument izvan opsega");
                if(x==cvorovi[cvorovi.size()-1].first) return cvorovi[cvorovi.size()-1].second;
                for(int i=0; i<cvorovi.size()-1; i++)
                {
                    if(x>=cvorovi[i].first && x<cvorovi[i+1].first)
                    {
                        x1=cvorovi[i].first; y1=cvorovi[i].second;
                        x2=cvorovi[i+1].first; y2=cvorovi[i+1].second;
                        break;
                    }
                }
                double rez;
                rez=y1+((y2-y1)/(x2-x1))*(x-x1);
                return rez;
            });
}

int main()
{
    try
    {
        int unos;
        do
        {
            std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            std::cin >> unos;
            if(unos!=1 && unos!=2) std::cout << "Unos mora biti 1 ili 2!!!" << std::endl;
        }while(unos!=1 && unos!=2);

            if(unos==1)
            {
                int br_cvorova;
                std::cout << "Unesite broj cvorova: ";
                std::cin >> br_cvorova;
                std::cout << "Unesite cvorove kao parove x y: ";
                std::vector<std::pair<double,double>> v_parova;
                for(int i=0; i<br_cvorova; i++)
                {
                    double x;
                    double y;
                    std::cin >> x >> y;
                    std::pair<double, double> par=std::make_pair(x,y);
                    v_parova.push_back(par);
                }
                for(;;)
                {
                    auto f(LinearnaInterpolacija(v_parova));
                    std::string s="";
                    std::cin.clear();
                    std::cin.ignore(100000, '\n');
                    double argument;
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    if(std::cin.peek()<'0' || std::cin .peek()>'9') break;
                    else
                    {
                        std::cin >> argument;
                        std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
                    }
                }
            }

            else if(unos==2)
            {
                double xmin, xmax, dx;
                std::cout << "Unesite krajeve intervala i korak: ";
                std::cin >> xmin >> xmax >> dx;
                for(;;)
                {
                    std::string s="";
                    std::cin.clear();
                    std::cin.ignore(100000, '\n');
                    double argument;
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    if(std::cin.peek()<'0' || std::cin .peek()>'9') break;
                    else
                    {
                        try
                        {
                            std::cin >> argument;
                            auto f(LinearnaInterpolacija([](double x){ return (x*x + sin(x)); }, xmin, xmax, dx));
                            std::cout << "f(" << argument << ") = " << (argument*argument+sin(argument)) << " fapprox(" 
                                << argument << ") = " << f(argument) << std::endl;
                        }
                        catch(std::range_error e)
                        {
                            std::cout << e.what() << std::endl;
                        }
                    }
                }
            }
    }
    catch(std::domain_error e)
    {
        std::cout << e.what();
    }
    catch(std::range_error e)
    {
        std::cout << e.what();
    }
    return 0;
}
