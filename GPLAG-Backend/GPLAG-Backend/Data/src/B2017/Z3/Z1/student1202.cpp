#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include<stdexcept>
#include <iomanip>
using std::function;
using std::vector;
using std::cout;
using std::cin;
bool Provjeri(vector<std::pair<double,double>>&vektor)
{
    auto it(std::unique(vektor.begin(),vektor.end(),
    []( std::pair<double,double> prvi, std::pair<double,double>drugi) {
        return (prvi.first==drugi.first);
    }));
    if(it==vektor.end())//kraj,dakle nema istih->true svi su razliciti
        return true;
    return false; //false postoji isti element
}
void Poredaj (vector<std::pair<double,double>> &vektor)
{
    std::sort(vektor.begin(),vektor.end(),[] ( std::pair<double,double> prvi, std::pair<double,double> drugi) {
        return prvi.first<drugi.first;
    });
}

function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> vektorparova)
{
    
    Poredaj(vektorparova);
    
    if(!Provjeri(vektorparova)) throw std::domain_error ("Neispravni cvorovi");
    //NAPOMENA :u funkciji koja se vraca treba se baciti izuzetak za argument!!!
    return [vektorparova](double arg) {
         if(vektorparova.size()==0) throw std::range_error("Argument izvan opsega");
        if(arg < vektorparova[0].first || arg>vektorparova[(int(vektorparova.size())-1)].first)
            throw std::range_error("Argument izvan opsega");
        if(arg==vektorparova[(int(vektorparova.size())-1)].first) {
            return vektorparova[(int(vektorparova.size())-1)].second;
        } else {
            auto iter( std::lower_bound(vektorparova.begin(),vektorparova.end(),arg,
            []( std::pair<double,double> x,double arg) {

                return  x.first<arg ;
            }));
            //ako je arg jednak prvom clanu vektora,iteer ce pokazivati na prvi cl
            if((iter-vektorparova.begin())==0) {
                auto iterSlj(iter+1);
                return (iter->second+(((iterSlj->second-iter->second)/(iterSlj->first-iter->first))*(arg-iter->first)));
            } else if(iter->first==arg) {
                auto iterSlj(iter+1);
                return (iter->second+(((iterSlj->second-iter->second)/(iterSlj->first-iter->first))*(arg-iter->first)));
            } else {
                auto iterPrethodni(iter-1);
                return (iterPrethodni->second+(((iter->second-iterPrethodni->second)/(iter->first-iterPrethodni->first))*(arg-iterPrethodni->first)));
            }

        }

    };

}

function<double(double)>LinearnaInterpolacija(std::function<double(double)> funkcija,double min,double max,double delta)
{
    if(min>max) throw std::domain_error("Nekorektni parametri");
    if(delta<=0) throw std::domain_error("Nekorektni parametri");
    vector<std::pair<double,double>> vektor;
    for(auto i=min; i<=max; i+=delta) {
       
        vektor.push_back(std::make_pair(i,funkcija(i)));
        if(i == max) break;
    }

    return [vektor](double arg) {
       if(vektor.size()==0)  throw std::range_error("Argument izvan opsega");
 if(arg < vektor[0].first || arg>vektor[(int(vektor.size())-1)].first+1e-10)
  throw std::range_error("Argument izvan opsega");
          
        if(arg==vektor[(int(vektor.size())-1)].first) {
            return vektor[(int(vektor.size())-1)].second;
        } else {
            

            auto iter( std::lower_bound(vektor.begin(),vektor.end(),arg,
            []( std::pair<double,double> x,double arg) {
                return  x.first<arg ;
            }));
            //ako je arg jednak prvom clanu vektora,iteer ce pokazivati na prvi cl
            if((iter-vektor.begin())==0) {
                auto iterSlj(iter+1);
                return (iter->second+(((iterSlj->second-iter->second)/(iterSlj->first-iter->first))*(arg-iter->first)));
            } else if(iter->first==arg) {
                auto iterSlj(iter+1);
                return (iter->second+(((iterSlj->second-iter->second)/(iterSlj->first-iter->first))*(arg-iter->first)));
            } else {
                auto iterPrethodni(iter-1);
                return (iterPrethodni->second+(((iter->second-iterPrethodni->second)/(iter->first-iterPrethodni->first))*(arg-iterPrethodni->first)));
            }

        }

    };


}

int main ()
{
    
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    cin>>n;
    if(n==1) {
        cout<<"Unesite broj cvorova: ";
        int br;
        cin>>br;
        vector<std::pair<double,double>> vektor;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<br; i++) {
            double x,y;
            cin>>x>>y;
            vektor.push_back(std::make_pair(x,y));
        }

        double arg;
        
           try{
               auto f(LinearnaInterpolacija(vektor));
            do {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>arg;
                if(!cin) break;
             try{
                cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                }catch(std::range_error izuzetak) {
            cout<<izuzetak.what()<<std::endl;
        }
                
   } while(cin);
    } catch(std::domain_error izuzetak) {
            cout<<izuzetak.what()<<std::endl;
        }
    } else {
        
        double arg;
        cout<<"Unesite krajeve intervala i korak: ";
        double min,max,korak;
        cin>>min>>max>>korak;
        try{
 auto f(LinearnaInterpolacija([](double x) {
                    return x*x+sin(x);
                },min,max,korak));
            
        do {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            cin>>arg;
            if(!cin) break;
                try{
                cout<<"f("<<arg<<") = "<<arg*arg+sin(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
                }catch(std::range_error izuzetak) {
                cout<<izuzetak.what() << std::endl; } 
         
   }while(cin);
        }  catch(std::domain_error e) {
                cout<<e.what() << std::endl;
            }
    }
    return 0;
}
