/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include <stdexcept>

double f (double x) {
    return x * x + std::sin(x); 
}

int MaxElement(int a, int b) {
    if(a==b) {
        return a;
    }
    else if(a<b) {
        return b;
    }
    else if(a>b) {
        return a;
    }
}

int MinElement(int a, int b) {
    if(a==b) {
        return a;
    }
    else if(a<b) {
        return a;
    }
    else {
        return b;
    }
}
double TezinskiKoeficijenti(int i,int d,int n,std::vector<std::pair<double,double>>v) {
    double rezultat(0);
    int  kraj=MinElement(i,v.size()-d);
    //std::cout<<"Kraj je: "<<kraj<<std::endl;
    int pocetak=MaxElement(1,(i-d));
    //std::cout<<"Pocetak je: "<<pocetak<<std::endl;
    for(int k=pocetak;k<=kraj;k++) {
        double rezultat1(1);
    for(int j=k;j<=k+d;j++) {
        if(i!=j) 
        rezultat1*=(1/(v[i-1].first-v[j-1].first));
    }
    rezultat+=std::pow(-1,k-1)*rezultat1;
    }
    return rezultat;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>>v,int d) {
    if(d<0 || d>v.size()) {
        throw std::domain_error("Nedozvoljen red");
    }
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<i;j++) {
            if(v[i].first==v[j].first) {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    
    return [v,d] (double x) {
        for(int i=1;i<=v.size()-1;i++) {
            if(x==v[i-1].first)
            return v[i-1].second;
        }
        double rez1(0);
        double rez2(0);
        double rez;
   
   for(int i=1;i<=v.size();i++) {
        rez1+=((TezinskiKoeficijenti(i,d,v.size(),v)*v[i-1].second)/(x-v[i-1].first));
    
    }
    for(int i=1;i<=v.size();i++) {
        rez2+=(TezinskiKoeficijenti(i,d,v.size(),v)/(x-v[i-1].first));
    
    }
    rez=rez1/rez2;
    return rez;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double fun(double),double xmin, double xmax, double deltax,int d) {
    if(xmin>xmax || deltax<=0) {
        throw std::domain_error("Nekorektni parametri");
    }
    std::vector<std::pair<double,double>> v;
        for(double i=xmin;i<=xmax;i+=deltax) {
            std::pair<double,double> cvor;
            cvor.first=i;
            cvor.second=fun(cvor.first);
            v.push_back(cvor);
        }
    return [v,d] (double x) {
         for(int i=1;i<=v.size()-1;i++) {
            if(x==v[i-1].first)
            return v[i-1].second;
        }
        double rez1(0);
        double rez2(0);
        double rez;
        for(int j=1;j<=v.size();j++) {
        rez1+=((TezinskiKoeficijenti(j,d,v.size(),v)*v[j-1].second)/(x-v[j-1].first));
    
    }
    for(int j=1;j<=v.size();j++) {
        rez2+=(TezinskiKoeficijenti(j,d,v.size(),v)/(x-v[j-1].first));
    
    }
    rez=rez1/rez2;
    return rez;
    };
    
}


int main ()
{
   std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
   int opcija;
   std::cin>>opcija;
   if(opcija==1) {
   //auto fun1 = BaricentricnaInterpolacija(f, 0, 1, 0.1, 2);
    //std::cout << "fun (0.3) = " << fun1 (.3);
    int n;
    std::cout<<"Unesite broj cvorova: ";
    std::cin>>n;
    std::cout<<"Unesite cvorove kao parove x y: ";
    std::vector<std::pair<double,double>> v;
    for(int i=0;i<n;i++) {
        double x,y;
        std::cin>>x>>y;
        v.push_back(std::make_pair(x,y));
    }
    int d;
    std::cout<<"Unesite red interpolacije: ";
    std::cin>>d;
    std::string s("kraj");
    double x=1;
    while(x!=0) {
    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    std::cin>>x;
    if(x==0) {
        return 0;
    }
    std::function<double(double)> fun(BaricentricnaInterpolacija(v,d));
    std::cout<<"f"<<"("<<x<<")"<<" ="<<" "<<fun(x)<<std::endl;
    }
   }
   else {
       std::cout<<"Unesite krajeve intervala i korak: ";
       double prvi,drugi;
       double korak;
       std::cin>>prvi>>drugi>>korak;
       std::cout<<"Unesite red interpolacije: ";
       int d;
       std::cin>>d;
       std::string s;
       double x=1;
       while(x!=0) {
           std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
           std::cin>>x;
           if(x==0) {
               return 0;
           }
           //std::function<double(double)> fun(BaricentricnaInterpolacija(v,d));
           std::cout<<"f("<<x<<") "<<"= "<<f(x)<<" ";
           std::function<double(double)> fun2(BaricentricnaInterpolacija(f,prvi,drugi,korak,d));
           std::cout<<"fapprox("<<x<<") "<<"= "<<fun2(x)<<std::endl;
           
       }
       
       
   }
	return 0;
}