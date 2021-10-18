/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>


using namespace std;


function<double(double)>LinearnaInterpolacija(vector<pair<double,double>> parovi){
    for(int i=0; i<parovi.size()-1; i++){
        for(int j=i+1; j<parovi.size(); j++){
            if(fabs(parovi.at(i).first-parovi.at(j).first)<0.00000001) throw domain_error ("Neispravni cvorovi");
        }
    }
    sort(parovi.begin(), parovi.end());
    
    return[parovi](double x){
        double temp;
        double suma;
        if(x>parovi.at(parovi.size()-1).first || x<parovi[0].first) throw range_error ("Argument izvan opsega");
        for(int i=0; i<parovi.size(); i++){
            if(fabs(x-parovi.at(i).first)<0.00000001) return parovi.at(i).second;
        }
        int a=0, temp2, temp3=0;
        for(int i=0;i<parovi.size()-1; i++){
            if(x>=parovi.at(i).first && x<=parovi.at(i+1).first){
             temp2=i;
             temp3=i+1;
             break;
            }
        }
        if(temp3==0) throw range_error("Argument izvan opsega");
        a=temp3;
        temp=((parovi.at(a).second-parovi.at(temp2).second) * (x-parovi.at(temp2).first))/(parovi.at(a).first-parovi.at(temp2).first);
        suma=parovi.at(temp2).second+temp;
        return suma;
    };
}

function<double(double)>LinearnaInterpolacija(function<double(double)> fun, double min, double max, double korak){
    if(min>max || korak<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double, double>> parovi;
    int br=0;
    while(1){
        double temp=min+korak*br;
        if(temp>max)break;
        parovi.push_back(make_pair(temp, fun(temp)));
        br++;
    }
    return LinearnaInterpolacija(parovi);
}


int main (){
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int temp;
    cin>>temp;
    char s='"';
    if(temp==1){
        int cvorovi;
        vector<pair<double, double>> parovi;
        cout<<"Unesite broj cvorova: ";
        cin>>cvorovi;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<cvorovi; i++){
            double x, y;
            cin>>x>>y;
            parovi.push_back(make_pair(x, y));
        }
        while(1){
            try{
                auto fun=LinearnaInterpolacija(parovi);
                cout<<"Unesite argument (ili "<<s<<"kraj"<<s<<" za kraj): ";
                double arg;
                cin>>arg;
                if(!cin)break;
                cout<<"f("<<arg<<") = "<<fun(arg)<<endl;
            }
            catch(domain_error izuzetak){
                cout<<izuzetak.what();
                return 1;
            }
            catch(range_error izuzetak1){
                cout<<izuzetak1.what()<<endl;
            }
        }
        
    }
    
    if(temp==2){
        cout<<"Unesite krajeve intervala i korak: ";
        double x, y, korak;
        cin>>x>>y>>korak;
        while(1){
            try{
                auto fun=LinearnaInterpolacija([](double x){return x*x+sin(x);}, x, y, korak);
                cout<<"Unesite argument (ili "<<s<<"kraj"<<s<<" za kraj): ";
                double arg;
                cin>>arg;
                if(!cin)break;
                cout<<"f("<<arg<< ") = "<<arg*arg+sin(arg)<<" fapprox(" <<arg<<") = "<<fun(arg)<<endl;
            }
            catch(domain_error izuzetak){
                cout<<izuzetak.what();
                return 1;
            }
            catch(range_error izuzetak1){
                cout<<izuzetak1.what()<<endl;
            }
        }
        
    }
    
	return 0;
}
