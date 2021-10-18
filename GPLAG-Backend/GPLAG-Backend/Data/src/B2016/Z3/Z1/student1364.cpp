/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <utility> //za pair
#define EPSILON 0.00000001

using std::cin; using std::cout; using std::endl;

double f (double x) {
    return x*x+sin(x);
}

bool IspravniCvorovi (std::vector<std::pair<double, double>> v) {
    //Ne smiju biti iste x koordinate
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (fabs(v[i].first-v[j].first)<EPSILON) return false;
        }
    }
    return true;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> vek_p, int d) {
    //d - red interpolacije
    if (d<0 || d>=vek_p.size()) throw std::domain_error ("Nedozvoljen red"); 
    //Provjerimo ispravnost cvorova
    if (!IspravniCvorovi(vek_p)) throw std::domain_error ("Neispravni cvorovi");
    //Izracunajmo tezinske koeficijente
    //i=1, 2, ...n
    int n(vek_p.size()), min, max;
    std::vector<double> w(n); //Vektor tezinskih koeficijenata
    for (int i=1; i<=n; i++) {
        if (i<(n-d)) min=i;
        else min=n-d;
        max=1;
        if ((i-d)>max) max=i-d;
        double suma(0); 
        for (int k=max; k<=min; k++) {
            //Izracunajmo proizvod
            double proizvod(1);
            for (int j=k; j<=(k+d); j++) {
                if (i!=j)
                proizvod*=1./(vek_p[i-1].first-vek_p[j-1].first);
            }
            if ((k-1)%2==0) //ako j k-1 paran
            suma+=proizvod;
            else 
            suma+=-1*proizvod; //ako je k-1 neparan
        }
        w[i-1]=suma; 
    }
    //Izracunajmo f(x)
    return [w, n, vek_p](double x) {
        //Izracunajmo brojnik
        double suma_b(0);
        for (int i=1; i<=n; i++) {
            if (fabs(x-vek_p[i-1].first)<EPSILON) { //Za x=x_i vracamo y_i
                return vek_p[i-1].second;
            }
            suma_b+=(w[i-1]/(x-vek_p[i-1].first))*vek_p[i-1].second;
        }
        //Izracunajmo nazivnik
        double suma_n(0);
        for (int i=1; i<=n; i++) {
            if (fabs(x-vek_p[i-1].first)<EPSILON) {
                return vek_p[i-1].second;
            }
            suma_n+=w[i-1]/(x-vek_p[i-1].first);
        }
        auto rez=suma_b/suma_n;
        return rez;};
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> funkcija, double x_min, double x_max, double d_x, int d) {
    if (x_min>x_max || d_x<=0) throw std::domain_error ("Nekorektni parametri");
    //Kreirajmo cvorove interpolacije na intervalu x_min do x_max
    std::vector<std::pair<double, double>> cvorovi_interpolacije;
    for (double i=x_min; i<=x_max; i+=d_x) { //PAZI! i mora biti double, inace beskonacna petlja
        auto par=std::make_pair(i, funkcija(i));
        cvorovi_interpolacije.push_back(par); //Ubacujemo cvor u vektor
    }
    try {
        auto r=BaricentricnaInterpolacija(cvorovi_interpolacije, d);
        return r;
    }
    catch (...) {
        throw;
    }
}

int main ()
{
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    cin >> opcija;
    if (opcija==1) {
        cout << "Unesite broj cvorova: ";
        int broj_c(0);
        cin >> broj_c;
        cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v(broj_c);
        for (int i=0; i<broj_c; i++) {
            double x,y;
            cin >> x >> y;
            v[i].first=x; v[i].second=y;
        }
        cout << "Unesite red interpolacije: ";
        int red_i(0);
        cin >> red_i;
        while (cin) {
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            cin >> arg;
            if (cin)
            try {
                BaricentricnaInterpolacija(v, red_i)(arg);
                cout << "f("<< arg << ") = " << BaricentricnaInterpolacija(v, red_i)(arg) << endl; 
            }
            catch (std::domain_error izuzetak) {
                cout << izuzetak.what() << endl;
                return 0;
            }
        }
    }
    if (opcija==2) {
        cout << "Unesite krajeve intervala i korak: ";
        // (a,b) i korak k
        double a, b, k;
        cin >> a >> b >> k;
        cout << "Unesite red interpolacije: ";
        int d;
        cin >> d;
        while (cin) {
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            cin >> arg;
            if (cin)
            try {
                BaricentricnaInterpolacija(f, a, b, k, d)(arg);
                cout << "f("<< arg << ") = " << f(arg) << " fapprox(" << arg << ") = " << BaricentricnaInterpolacija(f, a, b, k, d)(arg) << endl; 
            }
            catch (std::domain_error izuzetak) {
                cout << izuzetak.what() << endl;
                return 0;
            }
        }
        return 0;
    }
}