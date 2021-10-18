/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <utility>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

bool ProvjeraCvorova(std::vector<std::pair<double, double>>v){
    bool d(false);
    auto it1(v.begin());
    it1++;
    for(auto it=v.begin(); it!=v.end(); it++){
        it1=it;
        it1++;
        while(it1!=v.end()){
            if((it->first)==(it1->first)) d=true;
            it1++;
        }
    }
    return d;
}

int Stepen(int baza, int stepen){
	int d=1;
	for(int i=0;i<stepen;i++){
		d*=baza;
	}
	return d;
}
double fun(double x){
    return x*x+std::sin(x);
}
std::vector<double> w(std::vector<std::pair<double, double>> v, int d){
    std::vector<double>v1;
    for(int i=1;i<=v.size();i++){
        int n(i-d);
        int m(v.size()-d);
        int max(1);
        if(n>max) max=n;
        int min(i);
        if(m<min) min=m;
        double w(0);
        double p(1);
        for(int k=max; k<=min; k++){
            for(int j=k; j<=k+d; j++){
                if(i==j) continue;
                p*=1./(v[i-1].first-v[j-1].first);
            }
            p*=Stepen(-1,k-1);
            w+=p;
            p=1;
        }
        v1.push_back(w);
        w=0;
    }
    return v1;
}

std::function<double(double)> FBrojnik(std::vector<std::pair<double, double>>v, std::vector<double>v1){
    return [v1,v](double x){
        double s1(0);
        for(int i=1;i<=v.size();i++){
            if(x==v[i-1].first) return v[i-1].second;
            s1+=(v1[i-1]*v[i-1].second)/(x-v[i-1].first);
        }
        return s1;
    };
}

std::function<double(double)> FNazivnik(std::vector<std::pair<double, double>>v, std::vector<double>v1){
    return[v1, v] (double x){
        double s2(0);
        for(int i=1;i<=v.size();i++){
            if(x==v[i-1].first) return v[i-1].second;
            s2+=(v1[i-1]/(x-v[i-1].first));
        }
        return s2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>>v, int d ){
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    if(ProvjeraCvorova(v)) throw std::domain_error("Neispravni cvorovi");
    auto v1(w(v, d));
    auto s1(FBrojnik(v,v1));
    auto s2(FNazivnik(v,v1));
    return [v, s1, s2](double x){
        for(int i=1;i<=v.size();i++){
            if(x==v[i-1].first) return v[i-1].second;
        }
        return s1(x)/s2(x);
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> fun, double xmin, double xmax, double dx, int d){
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>>v;
    int i(0);
    double pom(0), rez(0);
    do{
        pom=xmin+i*dx;
        if(pom>xmax) break;
        rez=fun(pom);
        v.push_back(std::make_pair(pom, rez));
        i++;
    }while(pom!=xmax);
    
     return BaricentricnaInterpolacija(v, d);
}
int main ()
{
    std::vector<std::pair<double, double>>v;
        int d;
        double argument;
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        cin>>opcija;
        try{
            if(opcija==1){
                cout<<"Unesite broj cvorova: ";
                int broj_cvorova;
                cin>>broj_cvorova;
                cout<<"Unesite cvorove kao parove x y: ";
                int br(0);
                do{
                    std::pair<double, double> el;
                    cin>>el.first>>el.second;
                    v.push_back(el);
                    br++;
                }while(br!=broj_cvorova);
                cout<<"Unesite red interpolacije: ";
                cin>>d;
                auto v1(BaricentricnaInterpolacija(v,d));
                do{
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    cin>>argument;
                    if(!cin) {
                        break;
                    }
                    cout<<"f("<<argument<<")"<<" = "<<v1(argument)<<endl;
               
                }while(cin);
            }
            if(opcija==2){
                cout<<"Unesite krajeve intervala i korak: ";
                double k1,k2,ko;
                cin>>k1>>k2>>ko;
                cout<<"Unesite red interpolacije: ";
                cin>>d;
                auto v2(BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);}, k1, k2, ko, d));
                do{
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    cin>>argument;
                    if(!cin) {
                        break;
                    }
                    cout<<"f("<<argument<<")"<<" = "<<fun(argument)<<" ";
                    cout<<"fapprox("<<argument<<")"<<" = "<<v2(argument)<<endl;
                }while(cin);
            
            }
        }
        catch(std::domain_error iz){
            cout<<iz.what();
            return 0;
        }
	return 0;
}
