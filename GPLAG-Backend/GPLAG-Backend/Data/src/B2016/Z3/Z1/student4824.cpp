#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::endl;

double fu(double x){
    return x * x + std::sin(x);
    
}
    
std::function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> v,int d){
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    auto it(v.begin()),it1(v.begin()+1);
    while(it!=v.end()){
        while(it1!=v.end()){
            if((*it).first==(*it1).first) throw std::domain_error("Neispravni cvorovi");
            it1++;
        }
        it++;
        it1=it;
        it1++;
    }
    std::function<double(double)> f;
    return [f,v,d] (double x){
        double suma1(0),suma2(0);
        for(int i=0;i<v.size();i++){
           if(x==v[i].first)
            return v[i].second;
        }
        for(int i=0;i<v.size();i++){
            double wi(0);
            int min(i+1),max(1);
            if(min>v.size()-d) min=v.size()-d;
            if(max<i+1-d) max=i+1-d;
            for(int k=max-1;k<min;k++){
                double proizvod(1);
                for(int j=k;j<=k+d;j++){
                    if(v[i].first==v[j].first) continue;
                    proizvod*=1/(v[i].first-v[j].first);
                }
                wi+=(pow(-1,k-1))*proizvod;
            }
            if(x!=v[i].first){
            suma1+=(wi*v[i].second)/(x-v[i].first);
            suma2+=(wi)/(x-v[i].first);
            }
        }
        return (suma1/suma2);
    };
} 

std::function<double(double)> BaricentricnaInterpolacija(double f(double),double Xmin,double Xmax,double deltaX,int d){
    if(Xmin>Xmax || deltaX<0) throw std::domain_error("Nekorektni parametri");
    vector<pair<double,double>> cvorovi;
    double temp(Xmin);
    int i(1);
    while(Xmax>=temp){
        cvorovi.push_back(std::make_pair(temp,f(temp)));
        temp+=i*deltaX;
        i++;
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}

int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    vector<pair<double,double>> v;
    if(opcija==1){
        cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        cin>>br_cvorova;
        cout<<"Unesite cvorove kao parove x y: ";
        v.resize(br_cvorova);
        for(int i=0;i<br_cvorova;i++){
            cin>>v[i].first;
            cin>>v[i].second;
        }
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        double arg(0);
        try{
        auto f(BaricentricnaInterpolacija(v,d));
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cin.clear();
        cin.ignore(10000,'\n');
        while(cin>>arg){
        cout<<"f("<<arg<<") = "<<f(arg);
        cout<<endl<<"Unesite argument (ili \"kraj\" za kraj): ";
        }
        }catch(std::domain_error greska){
            cout<<greska.what();
        }
    }
    if(opcija==2){
        cout<<"Unesite krajeve intervala i korak: ";
        int Xmin,Xmax,deltaX;
        cin>>Xmin>>Xmax>>deltaX;
        cout<<"Unesite red interpolacije: ";
        double d;
        cin>>d;
        double arg(0);
        try{
        auto f(BaricentricnaInterpolacija(v,d));
        cin.clear();
        cin.ignore(10000,'\n');
        while(cin>>arg){
        cout<<"Unesite argument (ili \"kraj\" za kraj): "<<endl;
        cout<<"f("<<arg<<") = "<<f(arg);
        try{
        auto y(BaricentricnaInterpolacija(fu,Xmin,Xmax,deltaX,d));
        cout<<"fapprox("<<arg<<")"<<y(arg);
        }catch(std::domain_error greska){
            cout<<greska.what();
            return 0;
        }
        }
        }catch(std::domain_error greska){
            cout<<greska.what();
        }
    }
	return 0;
}