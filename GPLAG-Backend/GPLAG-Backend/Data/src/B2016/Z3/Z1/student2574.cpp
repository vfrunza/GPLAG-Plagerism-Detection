#include <vector>
#include <iostream>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>

const double EPSILON(1e-10);

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> pars, int red_int_d) {
    if (red_int_d < 0 || red_int_d > pars.size())
        throw std::domain_error ("Nedozvoljen red");
    for (int a(0); a < pars.size(); a++) {
        for (int b(0); b < pars.size(); b++) {
            if (std::abs(pars.at(a).first - pars.at(b).first) < EPSILON && b!=a)
                throw std::domain_error ("Neispravni cvorovi");
        }
    }
    std::vector<double> W;
    int N (pars.size());
    double product (1);
    double sum (0);
    for (int a(1); a <= N ; a++) {
        sum=0;
        for (int b (std::max(1, a-red_int_d)); b <= std::min(a, N-red_int_d); b++) {
            product=1;
            for (int c(b); c <= b+red_int_d; c++) {
                if (c==a)           continue;
                product *= 1/(pars.at(a-1).first - pars.at(c-1).first);
            }
            if ((b-1)%2!=0)        product*= -1;
            sum = sum + product;
        }
        W.push_back(sum);
    }
    return [W,N,pars] (double koef) { 
                                        double x(0), y(0);
                                        for (int a(0); a < N; ++a) {
                                            if (std::abs(koef - pars.at(a).first)>0) {
                                                x = x + (W.at(a) / (koef - pars.at(a).first) * pars.at(a).second);
                                                y = y + (W.at(a) / ( koef - pars.at(a).first));
                                            }
                                            else 
                                                return pars.at(a).second;
                                        }
                                        return (x/y);
                                    };
    }

int main () {
    int x(0);
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>x;
    if (x==1) {
        int br_cv(0);
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br_cv;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x, y;
        std::vector<std::pair<double,double>> main_parovi;
        auto pamti(br_cv);
        while(pamti!=0) {
            std::pair <double,double> temp;
            std::cin>>x;
            std::cin>>y;
            temp = std::make_pair(x,y);
            main_parovi.push_back(temp);
            pamti--;
        }
        int red_interpolacije(0);
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red_interpolacije;
        for (;;) {
            double arg(0);
            std::cout << "Unesite argument (ili "<<std::string(1,'"')<<"kraj"<<std::string(1,'"')<<" za kraj): ";
            std::cin>>arg;
            if (!std::cin)
                break; 
            try {
            auto fj(BaricentricnaInterpolacija(main_parovi,red_interpolacije));
            std::cout<<"f("<<arg<<") = "<<fj(arg)<<std::endl;
            }
            catch (std::domain_error iz) {
                std::cout<<iz.what();
                return 0;
            }
        }
    }
	return 0;
}   