#include <iostream>
#include <functional>
#include <utility>
#include <cmath>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;

int max(int a, int b){
    if (a >= b)
        return a;
    else
        return b;
}

int min(int a, int b){
    if (a <= b)
        return a;
    else
        return b;
}

double DajWi (std::vector<std::pair<double, double>> vc, int n, int d, int i ) {
    
    double wi(0.0);
    
    for (int k = max(1, i-d); k <= min(i, n-d); k++) {
        
        double proizvod = 1.0;
        for (int j = k; j <= k+d; j++) {
            if (j == i) 
                continue;
            //cout << "i=" << i << "; j=" << j << endl;
            proizvod *= 1./(vc[i-1].first - vc[j-1].first);
        }
        if (k % 2 == 0)
            proizvod = -proizvod;
            
        wi += proizvod;
    }
    return wi;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> vc, int d) {
    int n(vc.size());
    
    if (d < 0 || d > n)
        throw std::domain_error("Nedozvoljen red");
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (vc[i] == vc[j]) {
                throw std::domain_error ("Neispravni cvorovi");
            }        
        }
    }    
    
    std::vector<double> xv, yv, wiv;
    
    for (int i = 0; i < n; i++) {
        xv.push_back(vc[i].first);
        yv.push_back(vc[i].second);
        wiv.push_back(DajWi(vc, n, d, i+1));
    }
    
    return [xv, yv, wiv, n] (double x) {
        double suma1(0), suma2(0);
        
        
        for (int i = 0; i < n; i++) {
            if(x == xv[i])
                return yv[i];
            
            suma1 += (wiv[i] * yv[i]) / (x - xv[i]);
            suma2 += (wiv[i]) / (x - xv[i]);
        }
        return suma1 / suma2;
    };
}

template<typename T>
std::function<double(double)> BaricentricnaInterpolacija (T f, double xmin, double xmax, double dx, int d){
    std::vector<std::pair<double, double>> v;
    
    if(xmin > xmax || dx <= 0)
        throw std::domain_error("Nekorektni parametri");
    
    for(double x = xmin; x <= xmax; x += dx){
        v.push_back(std::pair<double, double>(x, f(x)));
    }
    
    return BaricentricnaInterpolacija(v, d);
}


int main ()
{
    try{
        int opcija;
        cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin >> opcija;
        if (opcija == 1) {
            int br_cvorova;
            cout << "Unesite broj cvorova: ";
            cin >> br_cvorova;
            
            cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> vc;
            std::pair<double, double> cvorovi;
            double a, b;
            
            for (int i = 0; i < br_cvorova; i++) {
                cin >> a >> b;
                cvorovi = std::make_pair(a, b);
                vc.push_back(cvorovi);
            }
            
            int d;
            cout << "Unesite red interpolacije: ";
            cin >> d;
            
            auto f = BaricentricnaInterpolacija(vc, d);
                
            while(true){
                double argument;
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> argument;
                
                if(!std::cin)
                    return 0;
                    
                cout << "f(" << argument << ") = " << f(argument) << endl;
            }        
        } else if(opcija == 2){
            double xmin, xmax, dx;
            cout << "Unesite krajeve intervala i korak: ";
            cin >> xmin >> xmax >> dx;
            
            int d;
            cout << "Unesite red interpolacije: ";
            cin >> d;
            
            auto x2sinx = [](double x){ return x*x + sin(x); };
            auto f = BaricentricnaInterpolacija(x2sinx, xmin, xmax, dx, d);
            
            while(true){
                double argument;
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> argument;
                
                if(!std::cin)
                    return 0;
                    
                
                cout << "f(" << argument << ") = " << x2sinx(argument) << " ";
                cout << "fapprox(" << argument << ") = " << f(argument) << endl;
            }
        } else {
            throw std::domain_error("Nekorektna opcija");
        }
    }
    catch(std::domain_error err){
        cout << err.what();
    }
	return 0;
}