#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <stdexcept>
#include <cmath>

using std::cin;
using std::cout;

int Manje(int x,int y){
    if(x<=y)
    return x;
    return y;
}
int Vece(int x,int y){
    if(x>=y)
    return x;
    return y;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi,int d){
    if(d<0 || d>=cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<cvorovi.size();i++){
        for(int j=i+1;j<cvorovi.size();j++){
            if(cvorovi[i].first==cvorovi[j].first)
            throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> tezkoef;
    for(int i=1;i<=cvorovi.size();i++){
        double w(0);
        for(int k=Vece(1,i-d);k<=Manje(i,cvorovi.size()-d);k++){
            double proizvod(1);
            for(int j=k;j<=k+d;j++)
            if(i!=j)
            proizvod*=1./(cvorovi[i-1].first-cvorovi[j-1].first);
            w+=std::pow(-1,k-1)*proizvod;
        }
        tezkoef.push_back(w);
    }
    return [cvorovi,tezkoef,d](double x){
        for(int i=0;i<cvorovi.size();i++){
            if(cvorovi[i].first==x)
            return cvorovi[i].second;
        }
        double suma1(0);
        double suma2(0);
      for(int i=1;i<=cvorovi.size();i++){
          suma1+=(tezkoef[i-1]/(x-cvorovi[i-1].first))*cvorovi[i-1].second;
          suma2+=tezkoef[i-1]/(x-cvorovi[i-1].first);
      }
      return suma1/suma2;
    };
}
template<typename Tip>
std::function<double(double)> BaricentricnaInterpolacija(Tip f,double xmin,double xmax,double deltax,int d){
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    while(xmin<=xmax){
        cvorovi.push_back(std::make_pair(xmin,f(xmin)));
        xmin+=deltax;
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}

int main ()
{
    
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    if(opcija==1){
        cout<<"Unesite broj cvorova: ";
        int brcv;
        cin>>brcv;
        std::vector<std::pair<double,double>> cvorovi(brcv);
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<brcv;i++){
            double x,y;
            cin>>x>>y;
            cvorovi[i]=std::make_pair(x,y);
        }
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        for(;;){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(!cin)
            break;
            else
            try{
            cout<<"f("<<x<<") = "<<BaricentricnaInterpolacija(cvorovi,d)(x)<<std::endl;
            }catch(std::domain_error izuzetak){
                cout<<izuzetak.what()<<std::endl;
                return 0;
            }
        }
    }
    else if(opcija==2){
        cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        cin>>xmin>>xmax>>deltax;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        for(;;){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(!cin)
            break;
            else
            try{
            cout<<"f("<<x<<") = "<<x*x+std::sin(x)<<" fapprox("<<x<<") = "<<BaricentricnaInterpolacija([](double y){return y*y+std::sin(y);},xmin,xmax,deltax,d)(x)<<std::endl;
            }catch(std::domain_error izuzetak){
                cout<<izuzetak.what()<<std::endl;
                return 0;
            }
        }
    }
	return 0;
}