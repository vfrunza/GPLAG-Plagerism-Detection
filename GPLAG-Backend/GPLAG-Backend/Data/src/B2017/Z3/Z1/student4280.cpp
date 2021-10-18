#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <functional>

std::function<double(double)> PrvaSuma(double x1, double x2, double k) {
    return[x1,x2,k](double y) {
        if(y==x1) return x2;
    };
}

std::function<double(double)>DrugaSuma(double x1, double x2, double k) {
    return[x1,x2,k](double y) {
        return k/(y-x1);
    };
}

std::function<double(double)>F() {
    return[](double x) {
        return x*x+sin(x);
    };
}

std::function<float(float)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> par, int d) {

    if(d<0 || d>par.size()) throw std::domain_error("Nedozvoljen red");

    for(int i=0; i<par.size()-1; i++) {
        for(int j=i+1; i<par.size(); j++) {
            if(par[i].first==par[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    return[par,d](double x) {
        double zbir1=0, zbir2=0,proz=1,wi=0;
        int pocetak=1,kraj=1;

        for(int i=1; i<=par.size(); i++) {
            pocetak=1, kraj=i, wi=0;
            if(i-d>pocetak) pocetak=i-d;
            if(par.size()-d<kraj) kraj=par.size()-d;

            for(int j=pocetak; j<=kraj; j++) {
                proz=1;

                for(int k=j; k<=j+d; k++) {
                    if(i==k) continue;
                    proz*=1./(par[i-1].first-par[k-1].first);
                }
                wi+=pow(-1, j-1)*proz;
            }
            if(x==par[i-1].first) return par[i-1].second;

            zbir1+=PrvaSuma(par[i-1].first, par[i-1].second, wi)(x);
            zbir2+=DrugaSuma(par[i-1].first, par[i-1].second, wi)(x);
        }
        return zbir1/zbir2;
    };
}

std::function <double(double)>BaricentricnaInterpolacija(std::function<double(double)>F, double xmin, double xmax, double dx,int d) {

    if(xmin < xmax || dx<0) throw std::domain_error("Nekorektni parametri");

    return[F, xmin, xmax, dx, d](double x) {

        std::vector <double> vtackica;
        for(double i=xmin; i<=xmax; i+=dx) {
            vtackica.push_back(i);
        }

        std::vector<std::pair<double,double>> par(vtackica.size()) ;
        for(int i=0; i<par.size(); i++) {
            par[i].first=vtackica[i];
            par[i].second=F(vtackica[i]);
        }

        double zbir1=0, zbir2=0,wi=0,proz=1;
        int pocetak=1, kraj=1;

        for(int i=1; i<=par.size(); i++) {
            pocetak=1;
            kraj=i;
            wi=0;

            if(i-d>pocetak) pocetak=i-d;
            if(par.size()-d<kraj) kraj=par.size()-d;

            for(int j=pocetak; j<=kraj; j++) {
                proz=1;

                for(int k=j; k<=j+d; k++) {
                    if(i=k) continue;
                    proz*=1./(par[i-1].first-par[k-1].first);
                }
                wi+=pow(-1,j-1)*proz;
            }
            if(x==par[i-1].first)
                return par[i-1].second;

            zbir1+=PrvaSuma(par[i-1].first, par[i-1].second, wi)(x);
            zbir2+=DrugaSuma(par[i-1].first, par[i-1].second, wi)(x);
        }

        return zbir1/zbir2;
    };
}

int main() {

try {
    int opc=0, br=0;
    double x,y, red,unos=0;

    for(;;) {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opc;

        if(opc==1) {
            std::cout << "Unesite broj cvorova: ";
            std::cin >> br;

            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> par(br);

            for(int i=0; i<br; i++) {
                std::cin>>x;
                std::cin>>y;
                par[i].first=x;
                par[i].second=y;
            }

            std::cout << "Unesite red interpolacije: ";
            std::cin >> red;

            while(1) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> unos;

                if(std::cin.fail()) {
                    return 0;
                }

                double R1=BaricentricnaInterpolacija(par,red)(unos);
                std::cout <<"f("<<unos<<") = " << R1 << std::endl;
            }
        } else if(opc==2) {
            std::function<double(double)>helpf(F());

            std::cout << "Unesite krajeve intervala i korak: ";


            double korak,pocetak, kraj;
            std::cin >> pocetak;
            std::cin >> kraj;
            std::cin >> korak;

            std::cout << "Unesite red interpolacije: ";
            std::cin >> red;
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            while(1) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>unos;

                if(std::cin.fail()) {
                    return 0;
                }

                double R2=BaricentricnaInterpolacija(helpf,pocetak,kraj,korak,red)(unos);
                std::cout << "f("<<unos<<") = " << R2 << std::endl;
            }
        }
        break;
    }
    return 0;
} catch(std::domain_error greska) {
    std::cout << greska.what();
}
}
