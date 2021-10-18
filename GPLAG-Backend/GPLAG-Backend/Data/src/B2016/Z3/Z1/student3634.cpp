/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <utility> //zbog std::pair
#include <cmath>

 int Min( int a,  int b){
    if (a < b) return a;
    return b;
}

 int Max( int a,  int b){
    if (a > b) return a;
    return b;
}

typedef std::vector<std::pair<double, double>> Tip;
using std::cout; using std::cin;


double f(double arg){    return arg*arg + std::sin(arg); }

double TezinskiKoef_W(int i, const int d, Tip cvorovi){
    int n(int(cvorovi.size()));
    double suma{0};
    for(int k(Max(1, i - d));  k <= Min(i, n-d); k++) {                     
        double proizvod{1};                                                              
        for(int j(k); j <= k + d; j++){
            if (j == i) j++;
            if (j > k+d ) break;                                                        //uslov petlje ponovo provjeravam
            proizvod *= 1/(cvorovi[i-1].first - cvorovi[j-1].first);                        //oduzimam x koordinate iz vektora parova double-ova
        } 
        suma += pow(-1, k-1) * proizvod;
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(Tip cvorovi, int d){
    int n(int(cvorovi.size()));                                                                             //n je broj čvorova
    
    if (d < 0 || d > n) throw std::domain_error("Nedozvoljen red");                                        //za error
    for(int i{}; i < n-1; i++){                                                                             //petlja: pronalazak error-a
        for(int j(i+1); j < n; j++)
            if (cvorovi[i].first == cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");        //ako postoje čvorovi sa identičnim x-koordinatama
    }
    
    return [cvorovi, d](double arg){
        double brojnik{}, nazivnik{};
        int n(int(cvorovi.size()));
        for(int i{}; i < n; i++) if(cvorovi[i].first == arg) return cvorovi[i].second;                      //ima smisla f(xi) = yi
        for(int i{1}, drugo_i{0}; i <= n && drugo_i < n; i++, drugo_i++){
           brojnik += (TezinskiKoef_W(i, d, cvorovi) * cvorovi[drugo_i].second)/(arg - cvorovi[drugo_i].first);
           nazivnik += TezinskiKoef_W(i, d, cvorovi)/(arg - cvorovi[drugo_i].first);
            
        } 
        return brojnik/nazivnik;};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d){
    if(xmin > xmax || deltax <= 0) throw std::domain_error("Nekorektni parametri");
    
    Tip cvorovi;
    //kreirajmo čvorove interpolacije na intervalu[xmin, xmax] sa korakom + deltax
    while(xmax >= xmin){
        cvorovi.push_back({xmin, f(xmin)});
        xmin += deltax;
    }
    return BaricentricnaInterpolacija(cvorovi, d);
}

int main (){ 
        Tip* pok(nullptr);
        double niz[3]; 
        cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija; 
        cin >> opcija;
        Tip cvorovi;                                                   
        if(opcija == 1){
            int br_cvorova;
            cout << "Unesite broj cvorova: "; 
            cin >> br_cvorova;
            cvorovi.resize(br_cvorova);
            cout << "Unesite cvorove kao parove x y: "; 
            for(int i{}; i < br_cvorova; i++) cin >> cvorovi[i].first >> cvorovi[i].second;     // petlja za unos čvorova
            pok = &cvorovi;                                                                      //obavezno uzmi adresu i dodijeli je pokazivaču
        }
        else if(opcija == 2){
            cout << "Unesite krajeve intervala i korak: "; 
            cin >> niz[0] >> niz[1] >> niz[2];
        }
        else return 0;
        
        cout << "Unesite red interpolacije: "; 
        int d; 
        cin >> d;
        while(true){
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg; 
            cin >> arg;
            if(!cin) break;  //nešto što nije broj
            if(opcija == 1){
                try {cout << "f(" << arg << ") = " << BaricentricnaInterpolacija(*pok, d)(arg) << "\n"; }
                catch(std::domain_error er){cout << er.what(); }
            }
            else if(opcija == 2){
                try {cout << "f(" << arg << ") = " << f(arg) << " fapprox(" << arg << ") = " << BaricentricnaInterpolacija(f, niz[0], niz[1], niz[2], d)(arg) << std::endl; } 
                catch(std::domain_error er) {cout << er.what(); }
            }
        }
   
	return 0;
}   