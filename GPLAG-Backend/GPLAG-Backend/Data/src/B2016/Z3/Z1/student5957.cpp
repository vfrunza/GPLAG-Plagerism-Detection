/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include<iostream>
#include<functional>
#include<utility>
#include<vector>
using std::cout;
using std::cin;
using std::vector;
using std::function;
using std::pair;

int min1(int i,int d){
    if(i<=d) return i;
    return d;
}
int max1(int d){
    if(1>=d) return 1;
    return d;
}
double Proizvod(int prvi,vector<pair<int,int>> v,int k,int d,int c){
    double suma(1);
    for(int i(k);i<=k+d;i++){
        if(i!=c){
        double clan(0);
        clan=1./(prvi-v[i-1].first);
        suma=suma*clan;
        }
    }
    return suma;
}
double wi(vector<pair<int,int>> v,int d,int c){
    int n=v.size(),predznak(1);
    double wi(0);
    int k(max1(c-d));
    if((k-1)%2==0) predznak=1;
    for(int i(k);i<=min1(c,n-d);i++){
        wi=wi+predznak*Proizvod(v[c-1].first,v,k,d,c);
        predznak=-predznak;
    }
    return wi;
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<int,int>> v,int d){
    return [v,d](double x){
        double prvi(0),drugi(0);
        for(int i(1);i<=v.size();i++){
            double g(0);
            g=wi(v,d,i);
            prvi=prvi+(g*v[i-1].second)/(x-v[i-1].first);
            drugi=drugi+g/(x-v[i-1].first);
        }
        return prvi/drugi;
    };
}

int main ()
{
    auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2));
    cout<<f(2.5)<<"\n";
    
    
    
    
	return 0;
}