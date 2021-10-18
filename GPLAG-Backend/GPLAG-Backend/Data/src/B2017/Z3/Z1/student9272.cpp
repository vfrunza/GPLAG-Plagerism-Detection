/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <stdexcept>
#include <functional>
#include <vector>
#include <cmath>
using namespace std;

void sortiraj(vector<pair<double,double>> &v){
    for(int i=1;i<v.size();i++){
        for(int j=i-1;j>=0;j--){
            if(v[i].first<v[j].first){
                pair<double,double> temp;
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
}

int pronadji (vector<pair<double,double>> v, int p, int k, double x){
    if(k>=1){
        int mid=p+(k-p)/2;
        if(v[mid].first<=x && v[mid+1].first>=x){
            return mid;
        }
        if(v[mid].first>x){
            return pronadji(v,p,mid,x);
        }
        return pronadji(v,mid+1,k,x);
    }
    return -1;
}
bool ProvjeraCvorova(vector<pair<double, double>> v){
    int brojac(0);
    for(int i=0;i<v.size();i++){
        pair<double,double> temp;
        temp=v[i];
        for(int i=0;i<v.size();i++){
            if(temp.first==v[i].first){
                brojac++;
            }
        }
        if(brojac>1){
            return false;
        }
        brojac=0;
    }
    return true;
}

double f(double x){
    return x*x+sin(x);
}

function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> vp){
    sortiraj(vp);
    if(ProvjeraCvorova(vp)==false) throw domain_error("Neispravni cvorovi");
    return [vp](double x){
        if(x<vp[0].first || x>vp[vp.size()-1].first) throw range_error("Argument izvan opsega");
        int i=pronadji(vp, 0, vp.size()-1, x);
        if(i==-1) throw domain_error("Nema trazenog opsega");
        return vp[i].second+((vp[i+1].second-vp[i].second)/(vp[i+1].first-vp[i].first)*(x-vp[i].first));
    };
    
}

 function<double(double)> LinearnaInterpolacija(double fun(double), double Xmin, double Xmax, double dx){
    if(Xmin>Xmax || dx<=0 ) throw domain_error("Nekorektni parametri");
    return [fun,Xmin,Xmax,dx](double x){
        if(x<Xmin || x>Xmax) throw range_error("Argument izvan opsega");
        vector<pair<double,double>> temp;
        int br_cvorova=((Xmax-Xmin)/dx)+1;
        temp.resize(br_cvorova);
        for(int i=0;i<br_cvorova;i++){
            temp[i].first=Xmin+i*dx;
            temp[i].second=fun(Xmin+i*dx);
        }
        int i=pronadji(temp,0,temp.size()-1,x);
        if(i==-1) throw domain_error("Nije pronadjen opseg");
        return temp[i].second+((temp[i+1].second-temp[i].second)/(temp[i+1].first-temp[i].first)*(x-temp[i].first));
    };
}

 int main (){
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    bool provjera;
    cin>>n;
    if(n==1){
    cout<<"Unesite broj cvorova: ";
    int brc;
    cin>>brc;
    cout<<"Unesite cvorove kao parove x y: ";
    vector<pair<double,double>> v;
    for(int i=0;i<brc;i++){
        pair<double,double> p;
        cin>>p.first;
        cin>>p.second;
        v.push_back(p);
    }
    try{
    provjera=ProvjeraCvorova(v);
    
    if(provjera==false) throw domain_error("Neispravni cvorovi");
    }
    catch(domain_error izuzetak){
        cout<<izuzetak.what();
        return 0;
    }
    for(;;){
    cout<<"Unesite argument (ili \"kraj""\" za kraj): ";
    double x;
    cin>>x;
    if(!cin){
        cin.clear();
        cin.ignore(10000,'\n');
        break;
    }
     try{
        auto F(LinearnaInterpolacija(v));
        cout<<"f("<<x<<") = "<<F(x)<<endl;
     }
      catch(domain_error izuzetak){
       cout<<izuzetak.what()<<endl;
       break;
        }
      catch(range_error izuzetak){
       cout<<izuzetak.what()<<endl;
        }
    }
    }
    else
    {
     cout<<"Unesite krajeve intervala i korak: ";
     double a,b,c,x;
     cin>>a>>b>>c;
     for(;;){
     auto H(LinearnaInterpolacija(f,a,b,c));
     cout<<"Unesite argument (ili \"kraj""\" za kraj): ";
     cin>>x;
     if(!cin) break;
     try{
     cout<<"f("<<x<<") = "<<f(x)<<" fapprox("<<x<<") = "<<H(x)<<endl;
      }
       catch(domain_error izuzetak){
        cout<<izuzetak.what()<<endl;
        break;
        }
       catch(range_error izuzetak){
       cout<<izuzetak.what()<<endl;
       
      }
     }
    }
    return 0;
 }