/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include<vector>
#include<utility>
#include<functional>
#include<exception>
#include<algorithm>
#include<cmath>
double f(double x)
{
    return (pow(x,2)+sin(x));
}
std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> a)
{
    //provjeriti jesul sve prve koordinate razlicite ako jesu super..sortirati u rastuci poredak
    for(int j=0;j<a.size();j++)
    {
        for(int k=j+1;k<a.size();k++)
        {
            if(a[j].first==a[k].first){ throw std::domain_error("Neispravni cvorovi");}
        }
        
    }
    std::sort(a.begin(),a.end(),[] (std::pair<double,double> a,std::pair<double,double> b) {return a.first<b.first;});
    
    return [a] (double x) {
        double s=0;
        if(x<a[0].first || x>a[a.size()-1].first) throw std::range_error("Argument izvan opsega");
        //trazi i-par kod kojeg je prva koordinata jednaka ili manja od x, a da je (i+1)par takav da je prva koordinata veca od x
        //UMJESTO DONJE PETLJE TREBA LOWER BOUND
        //for(int i=0;i<a.size()-1;i++)
       // {
            int i=std::lower_bound(a.begin(),a.end(),std::make_pair(x,0.))-a.begin();
            i--;
            /*if(a[i].first<=x && a[i+1].first>=x)*/ return (a[i].second+((a[i+1].second-a[i].second)/(a[i+1].first-a[i].first))*(x-a[i].first));
       // }
        /*std::binary_search(a.begin(),a.end(),x,[] (std::pair<double,double> c,int x){return c.first==x;});*/
        return s;
    };
}
std::function<double(double)> LinearnaInterpolacija(double f(double),double xmin,double xmax,double deltax)
{
    if(xmin>xmax or deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> a;
    for(int i=0;(xmin+i*deltax)<=xmax;i++)
    {
        a.resize(i+1);
        a[i].first=xmin+i*deltax; a[i].second=f(xmin+i*deltax);
        
    }
    
    
    return [a,xmin,xmax] (double x) {
        double s=0;
        if(x<xmin || x>xmax) throw std::range_error("Argument izvan opsega\n");
        //trazi i-par kod kojeg je prva koordinata jednaka ili manja od x, a da je (i+1)par takav da je prva koordinata veca od x
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i].first<=x && a[i+1].first>=x) return (a[i].second+((a[i+1].second-a[i].second)/(a[i+1].first-a[i].first))*(x-a[i].first));
        }
        /*std::binary_search(a.begin(),a.end(),x,[] (std::pair<double,double> c,int x){return c.first==x;});*/
        return s;
    };
    
    
}

int main ()
{
   
    int a;
    do{
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>a;
    }while(a!=1 && a!=2);
    switch(a){
        case 1:
        {
        std::cout<<"Unesite broj cvorova: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> v(n);
        for(int i=0;i<n;i++)
        {
            int x,y;
            std::cin>>x;
            std::cin>>y;
            v[i].first=x;
            v[i].second=y;
        }
        try{
        LinearnaInterpolacija(v);
        }catch(std::exception& e)
        {
            std::cout<<e.what();
            return 0;
        }
        do{
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg=0;
        std::cin>>arg;
        if(arg==0) break;
        try{
        std::cout<<"f("<<arg<<") = "<<LinearnaInterpolacija(v)(arg)<<std::endl;
        }catch(std::exception& e)
        {
            std::cout<<e.what();
        }
        }while(1==1);
        break;
        }
        
        case 2:{
        std::cout<<"Unesite krajeve intervala i korak: ";
        double min,max,delta;
        std::cin>>min;
        std::cin>>max;
        std::cin>>delta;
        double arg=0;
        do{
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): " ;
        
        std::cin>>arg;
        if(arg==0) break;
        try{
        std::cout<<"f("<<arg<<") = "<<f(arg)<<" fapprox("<<arg<<") = "<<LinearnaInterpolacija(f,min,max,delta)(arg)<<std::endl;
        }
        catch(std::exception& b)
        {
            std::cout<<b.what();
        }
        }while(arg!=0);
        break;
        }
    }
  
	return 0;
}
