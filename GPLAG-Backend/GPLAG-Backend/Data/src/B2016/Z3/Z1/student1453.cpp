/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <stdexcept>

double xsinx (double x){return x*x+sin(x);}
double min(double x, double y){
    if(x<y) return x;
    else return y;
} 

double max(double x, double y){
    if(x>y) return x;
    else return y;
} 

double w(int n, int d, int index, double xi,const std::vector<std::pair<double,double>> &x){   //radi li bez const ref
    double suma(0);
    index++;
    for(int k=max(1,index-d);k<=min(index,n-d);k++){
        double proizvod(1);
        for(int j=k-1;j<k+d;j++){ 
            if(index-1==j) continue;       //j!=i
            proizvod*=(1/(xi-x[j].first));
        }            
        proizvod*=pow(-1,k-1);
        suma+=proizvod;
    }
    return suma;
}



std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    if(d<0||d>v.size()) throw std::domain_error("Nedozvoljen red");
    return [v,d](double x) { 
        for(int i=0;i<v.size();i++){
            if(x==v[i].first) return v[i].second;
        }
        int n=v.size();
        int i=0;
        auto f1(double((w(n,d,i,v[i].first,v)*(v[i].second))/(x-v[i].first)));
        auto f2((w(n,d,i,v[i].first,v))/(x-v[i].first));
        for(i=1;i<n;i++){       //<=
            f1=f1+(w(n,d,i,v[i].first,v)*(v[i].second))/(x-v[i].first);
            f2=f2+(w(n,d,i,v[i].first,v))/(x-v[i].first);
        }
        return f1/f2;};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double x_min,double x_max,double dx, int d){ //mozda double kod min i max
    if(x_min>x_max || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    v.push_back(std::make_pair(x_min,f(x_min)));
    x_min+=dx;
    for(;;){
        if(x_min>x_max) break;
        v.push_back(std::make_pair(x_min,f(x_min)));
        x_min+=dx;
    }
    return BaricentricnaInterpolacija(v,d);
    
}


int main (){
    try{
    int d;
    double x_min,x_max,dx;
    std::vector<std::pair<double,double>> v;
    do{
        bool dobro(true);
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int unos;
        std::cin>> unos;
        if(!unos) break;
        if(unos==1){
            std::cout << "Unesite broj cvorova: ";
            int n; std::cin>>n;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0;i<n;i++){
                double x,y;
                std::cin >> x>>y;
                v.push_back(std::make_pair(x,y));
            }
            std::cout << "Unesite red interpolacije: ";
            std::cin>> d;
            
            do{
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double a; std::cin >> a;
                if(!std::cin){ dobro=false; break;}
                std::cout << "f(" <<a<<") = "<<BaricentricnaInterpolacija(v,d)(a)<< std::endl;
            }while(1);
            
            
        }
        if(!dobro) break;
        bool dobro2(true);
        if(unos==2){
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin>>x_min>>x_max>>dx;
            std::cout << "Unesite red interpolacije: ";
            std::cin>> d;
            double x_min2(x_min);
            v.push_back(std::make_pair(x_min2,xsinx(x_min2)));
            x_min2+=dx;
            for(;;){
                if(x_min2>x_max) break;
                v.push_back(std::make_pair(x_min2,xsinx(x_min2)));
                x_min2+=dx;
            }
            do{
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double a; std::cin >> a;
                if(!std::cin){ dobro2=false; break;}
                std::cout << "f("<<a<<") = "<<xsinx(a)<< " ";
                std::cout << "fapprox("<<a<<") = "<<BaricentricnaInterpolacija(xsinx,x_min,x_max,dx,d)(a)<< std::endl;
            }while(1);
            
        }
        if(!dobro2) break;
        
        
    }while(1);
    }catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}