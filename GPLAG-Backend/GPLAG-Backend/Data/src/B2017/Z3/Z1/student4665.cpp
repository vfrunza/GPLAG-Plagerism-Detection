#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <functional>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>

//pripaziti ako se prislijedi prazan vektor

using namespace std;

bool uporediDouble(double x, double y)
{
    if (fabs(x-y) < 0.0000000001) return true; 
    return false; 
}

void imaLiIstih(vector<pair<double, double>> cvorovi){
    for(int i=0; i<cvorovi.size()-1; i++){
        for(int j=i+1; j<cvorovi.size(); j++){
            if(uporediDouble(cvorovi[i].first,cvorovi[j].first) )
                throw domain_error("Neispravni cvorovi");
        }
    }

}

bool daLiJeSortiran(vector<pair<double, double>> cvorovi){
    for(int i=0; i<cvorovi.size()-1; i++){
        if(cvorovi[i].first <cvorovi[i+1].first)
                return false;
    }

    return true;
}

bool uporediPar(pair<double,double> prvi, pair<double, double> drugi)
{
    return prvi.first<drugi.first;
}

void printaj(vector<pair<double, double>> cvorovi)
{
    for(int i=0; i<cvorovi.size(); i++)
        cout<<cvorovi[i].first<<" "<<cvorovi[i].second<<endl;
}

int pronadjiInterval (vector<pair<double, double> > cvorovi, double x)
{
    if(x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first)
        throw range_error("Argument izvan opsega");

    //treba uraditi kao binarnu pretragu
    for(int i=0; i< cvorovi.size()-1; i++){
        if(x>=cvorovi[i].first && x<cvorovi[i+1].first){
            return i;
        }
    }
    if(uporediDouble(cvorovi[cvorovi.size()-1].first, x)) return cvorovi.size()-1;
    return -1;
}

function<double(double)> LinearnaInterpolacija(vector<pair<double, double>> cvorovi){
    imaLiIstih(cvorovi);

    if(!daLiJeSortiran(cvorovi)){
        sort(cvorovi.begin(), cvorovi.end(),uporediPar );
        
    }

    return [cvorovi](double x) {
        int i = pronadjiInterval(cvorovi, x);
        if(uporediDouble(cvorovi[i].first, x ) ) return cvorovi[i].second;
        return cvorovi[i].second+((cvorovi[i+1].second-cvorovi[i].second)*(x-cvorovi[i].first))/(cvorovi[i+1].first-cvorovi[i].first);
    };

}

function<double(double)> LinearnaInterpolacija(function<double(double)> f,double Xmin, double Xmax, double DeltaX){
    vector<pair<double,double>>cvorovi={};
    
    if(Xmin>Xmax || DeltaX<=0 ) throw domain_error("Nekorektni parametri");
        
    for(double i=Xmin; i<=Xmax; i+=DeltaX){
        
        pair<double, double> clan = {i, f(i)};
        cvorovi.push_back( clan );
    }

    return [cvorovi](double x) {
        int i = pronadjiInterval(cvorovi, x);
        if(uporediDouble(cvorovi[i].first, x ) ) return cvorovi[i].second;
        return cvorovi[i].second+((cvorovi[i+1].second-cvorovi[i].second)*(x-cvorovi[i].first))/(cvorovi[i+1].first-cvorovi[i].first);
    };
}

function<double(double)> fun(){
    return [](double x){
        return x*x+sin(x);
    };
}

int main(){
   /* vector<pair<double, double>> nesto  ={{2,2},{1,1},{3,3}};
   auto neki = LinearnaInterpolacija(nesto);
   
 
   cout<<neki(2.3);*/
   vector<pair<double, double>> cvorovi = {};
   
   int unos;
   cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
   cin >> unos; 
   try{
       if(unos == 1 ) {
        cout<<"Unesite broj cvorova: ";
        cin>>unos;
        cvorovi={};
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<unos; i++){
            double prvi, drugi;
            cin>> prvi >> drugi;
            cvorovi.push_back(pair<double, double>(prvi,drugi));
            
        }
        imaLiIstih(cvorovi);
        string unos2;
        while(1) {
            cout<<"Unesite argument (ili \"kraj\" za kraj): "; 
            cin>>unos2; 
            if(unos2 == "kraj") break; 
            int duzina=unos2.length(); 
            const char *cstr;
            double broj = atof(unos2.c_str());
            try{
                cout<<"f("<<broj<<") = "<<LinearnaInterpolacija(cvorovi)(broj)<<endl;
            } 
            catch(exception& e){
                cout<<e.what();
            }
            
        }
       } else if(unos == 2)
       {
           string unos2;
           auto f = fun(); 
           cout<<"Unesite krajeve intervala i korak: ";
           double pocetak, kraj, korak; 
           cin>>pocetak>>kraj>>korak;
           
           while(1) {
            cout<<"Unesite argument (ili \"kraj\" za kraj): "; 
            cin>>unos2; 
            if(unos2 == "kraj") break; 
            int duzina=unos2.length(); 
            const char *cstr;
            double broj = atof(unos2.c_str());
            try{
                cout<<"f("<<broj<<") = "<<f(broj)<<" "<<"fapprox("<<broj<<") = "<<LinearnaInterpolacija(f,pocetak, kraj, korak)(broj)<<endl;
            }
            catch(exception& e){
                cout<<e.what()<<endl;
            }
            
            
        }
      }
   }
   catch(exception& e){
            cout<<e.what()<<endl;
    }
   

       

   return 0;
}
