#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include<stdexcept>
#include<utility>
double fapprox(double x){
    return x*x+std::sin(x); 
}
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d)
{
    if(d<0 || d>=v.size())throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
   
    int  n=v.size();
    std::vector<double> w(n);
    for(int i=1; i<=n; i++) {
       int k=0, l=0;
        std::pair<int, int> par;
        par=(std::make_pair(1, (i-d)));
        if(par.first>par.second) k=par.first;
        else {k=par.second;}
        std::pair<int, int> par1;
        par1=(std::make_pair(i, (n-d)));
        if(par1.first<par1.second) l=par1.first;
        else {l=par1.second;}
        double sum=0;
        for(int p=k; p<=l; p++) {
            double iz1=1, iz; 
            for(int j=p; j<=p+d; j++) {if(j!=i) iz1*= (1./(v[i-1].first-v[j-1].first));}
             iz=std::pow(-1, p-1)*iz1;
         sum+=iz;
    
        }
        w[i-1]=sum;
    }
    return[v,w,d](double x) {
        double suma1=0, suma2=0;
        for(int i=1; i<=v.size(); i++) {
            if(x==v[i-1].first) return v[i-1].second;
        }
        for(int i=1; i<=v.size(); i++) {
            suma1+= (w[i-1]/(x-v[i-1].first))*v[i-1].second;
        }
        for(int i=1; i<=v.size(); i++) {
            suma2+= (w[i-1]/(x-v[i-1].first));
        }
        double h=suma1/suma2;
        return h;
    };
}
std::function<double(double)>BaricentricnaInterpolacija(double f(double), double xmin, double xmax,double  deltax, int d)
{
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>>v;
    for( double i=xmin; i<xmax; i=i+deltax) {
            v.push_back(std::make_pair(i, f(i)));
        
    }
    return BaricentricnaInterpolacija(v,d);
}

int main()
{
    try {
        std::string s;
        s.push_back('"');
        s.push_back('k');
        s.push_back('r');
        s.push_back('a');
        s.push_back('j');
        s.push_back('"');
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int n;
        std::cin>>n;
        if(n==1) {
            std::cout<<"Unesite broj cvorova: ";
            int br;
            std::cin>>br;
            std::cout<<"Unesite cvorove kao parove x y: ";
            double x, y;
            std::vector<std::pair<double,double>> v(br);
            for(int i=0; i<br; i++) {
                std::cin>>x>>y;
                v[i].first=x;
                v[i].second=y;
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            std::cin.ignore(1000, '\n');
            for(;;) {
                std::cout<<"Unesite argument (ili "<<s<<" za kraj): ";
                         double f;
                std::cin>>f;
                if(!std::cin || std::cin.get()!='\n') break;
                auto a=BaricentricnaInterpolacija(v, d);
                std::cout<<"f("<<f<<") = "<<a(f)<<"\n";
            }
        }
        if(n==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin, xmax, deltax;
            std::cin>>xmin>>xmax>>deltax;
            std::cout<<"Unesite red interpolacije: ";
            int br1;
            std::cin>>br1;
            std::cin.ignore(1000, '\n');
            for(;;) {
                std::cout<<"Unesite argument (ili "<<s<<" za kraj): ";
                double f;
                std::cin>>f;
                if(!std::cin || std::cin.get()!='\n') break;
                auto a=BaricentricnaInterpolacija(fapprox, xmin, xmax, deltax, br1);
                std::cout<<"f("<<f<<") = "<<fapprox(f)<<" fapprox("<<f<<") = "<<a(f)<<"\n";
            }
        }
    }
    catch(std::domain_error iz){
        std::cout<<iz.what(); 
    }
    return 0;
}