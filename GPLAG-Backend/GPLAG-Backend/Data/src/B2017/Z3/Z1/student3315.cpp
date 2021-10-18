/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

const double epsilon = 1e-15;
double fun(double x){
    return x*x+sin(x);
}
int binary_search(const vector<pair<double, double>>& points, double x)
{
    int firstPoint = 0, secondPoint = points.size() - 1;
    while(secondPoint - firstPoint > 1)
    {
        if(x <= points[(firstPoint + secondPoint) / 2].first)
        {
            secondPoint = (firstPoint + secondPoint) / 2;
        }
        else
        {
            firstPoint = (firstPoint + secondPoint) / 2;
        }
    }
    return firstPoint;
}

function<double(double)> LinearnaInterpolacija(vector<pair<double, double>> points)
{
    if(!is_sorted(points.begin(), points.end()))
    {
        sort(points.begin(), points.end(),[](pair<double, double> p1, pair<double, double> p2) { return p1.first < p2.first; });
    }
    auto it = std::unique (points.begin(), points.end(), [](pair<double, double> p1, pair<double, double> p2) { return abs(p1.first - p2.first) < epsilon; });
    if(it != points.end())
    {
        throw domain_error("Neispravni cvorovi");
    }
    return [points](double x)
    {
        double result;
        vector<pair<double, double>> points_ = move(points);
        double xmin = points_.front().first, xmax = points_.back().first;
        if(x < xmin || x > xmax)
        {
            throw range_error("Argument izvan opsega");
        }
        if(abs(x - points.back().first) < epsilon)
        {
            result = points.back().second;
        }
        else
        {
            int firstPoint = binary_search(points_, x);
            result = points[firstPoint].second + ((points[firstPoint + 1].second - points[firstPoint].second)*(x - points[firstPoint].first))/(points[firstPoint + 1].first - points[firstPoint].first);
        }
        return result;
    };
}

function<double(double)> LinearnaInterpolacija(double (*f)(double), double xmin, double xmax, double dx)
{
    if(xmin > xmax || dx <= 0)
    {
        throw domain_error("Nekorektni parametri");
    }
    vector<pair<double, double>> points;
    points.reserve((xmax - xmin) / dx + 2);
    for(double i = xmin; i < xmax; i += dx)
    {
        points.push_back(make_pair(i, f(i)));
    }
    if(abs(xmax - points.back().first) > epsilon)
    {
        points.push_back(make_pair(xmax, f(xmax)));
    }
    return LinearnaInterpolacija(points);
}

int main ()
{
    try{
            int n;
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            std::cin>>n;
            if(n==1){
                std::vector<std::pair<double,double>> parovi;
                int broj_cvorova;
                std::cout<<"Unesite broj cvorova: ";
                std::cin>>broj_cvorova;
                
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(int i=0;i<broj_cvorova;i++){
                    double x,y;
                    std::cin >>x;
                    std::cin >>y;
                    parovi.push_back(std::make_pair(x,y));
                }
                auto f = LinearnaInterpolacija(parovi);
                while(1){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    try{
                        std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                    }catch(std::range_error r){
                        std::cout<<r.what()<<std::endl;
                    }
                    catch(std::domain_error r)
                    {
                        std::cout<<r.what()<<std::endl;
                    }
                }
            }
            else if(n==2){
                double niz[3];
                std::cout<<"Unesite krajeve intervala i korak: ";
                std::cin>>niz[0]>>niz[1]>>niz[2];
                while(1){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    try{
                        std::cout<<"f("<<argument<<") = "<<fun(argument)<<" "<<"fapprox("<<argument<<") = "<<LinearnaInterpolacija(fun,niz[0],niz[1],niz[2])(argument)<<std::endl;
                    }catch(std::domain_error r){
                         std::cout<<r.what()<<std::endl;
                    }
                    catch(std::range_error r){
                         std::cout<<r.what()<<std::endl;
                    }
                }
            }
        
        
    }catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(std::range_error e){
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
