#include <iostream>
#include<vector> 
#include<cmath>
#include<stdexcept>
#include<sstream>
#include<functional>
#include<string>



std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d ){
    if(d<0 || d>cvorovi.size()) throw std::domain_error("Nezadovoljen red");
    return[cvorovi, &d](double x){
        double suma1(0), suma2(0), E(1e-10);
        for(unsigned int i(1); i<= cvorovi.size(); i++){
            if(std::fabs(x-cvorovi[i-1].first)<=E) return cvorovi[i-1].second;
            double w(0);
            unsigned int gornjaGranica = (i<cvorovi.size() - d)? i:cvorovi.size() - d;
            for(unsigned int k = (1>(int)i-d) ? 1 : i-d; k<= gornjaGranica; k++){
                double temp (1);
                for(unsigned int j(k); j<= k+d; j++){
                    if((std::fabs(cvorovi[i-1].first - cvorovi[j-1].first)<=E) && i!=j) throw std::domain_error("Neispravni cvorovi");
                    temp = (j == i)? temp : temp*(1/(cvorovi[i-1].first - cvorovi[j-1].first));
                }
                w+=std::pow(-1.0, k-1) * temp;
            }
            suma1+=cvorovi[i-1].second*w/(x-cvorovi[i-1].first);
            suma2+=w/(x-cvorovi[i-1].first);
        }
        return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double xdelta, int d){
    if(xmin>xmax || xdelta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi ;
    for(; xmin<=xmax; xmin+=xdelta) cvorovi.push_back(std::make_pair(xmin, f(xmin)));
    return BaricentricnaInterpolacija(cvorovi, d);
}



int main (){
    int opcija;
    double E(1e-10);
    std::cout<<"1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija; 
    if(opcija==1)
    {
            int brojCvorova, d;
            std::vector<std::pair<double,double>> cvorovi;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>brojCvorova;
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(unsigned int i(0); i<brojCvorova; i++){
                double x, y;
                std::cin>>x>>y;
                cvorovi.push_back(std::make_pair(x,y));
            }
            std::cout<<"Unesite red interpolacije: ";
            std::cin>>d;
        
            bool validanUnos;
            validanUnos = true;
            while (validanUnos){
                try{
                    std::string unos;
                    std::cout<<"Unesite argument (ili ""kraj"" za kraj): " ;
                    std::cin>>unos;
                    std::stringstream ss;
                    ss<<unos; double broj(0);
                    ss>>broj;
                    if(ss.good()) validanUnos = false;
                    else if( std::fabs(broj - 0)<=E && unos[0] != '0' && validanUnos) validanUnos = false;
                    if(!validanUnos) break;
                    auto f(BaricentricnaInterpolacija(cvorovi, d));
                    std::cout<<"f("<<broj<<") = "<<f(broj)<< std::endl;
                }
                catch(const std::exception &e){
                    std::cout<<e.what();
                    validanUnos = false;
                }
                
            }
        
    }
            else if(opcija==2)
            {
                double xmin, xmax, xdelta;
                
                std::cout<<"Unesite krajeve intervala i korak: ";
                std::cin>>xmin >> xmax >> xdelta;
                int d;
                std::cout<<"Unesire red interpolacije: ";
                std::cin>>d;
                
                bool validanUnos = true;
                while(validanUnos){
                    try{
                        std::cout << "Unesite argument (ili ""kraj"" za kraj): ";
                        std::string unos;
                        std::cin>>unos;
                        std::stringstream ss;
                        ss<<unos;
                        double broj(0);
                        ss>>broj;
                        if(ss.good()) validanUnos = false;
                        else if(std::fabs(broj - 0)<=E && unos[0] != '0' && validanUnos) validanUnos = false;
                        if(!validanUnos) break;
                        auto f(BaricentricnaInterpolacija([](double x){ return x*x +std::sin(x);}, xmin, xmax, xdelta,d));
                        std::cout <<"f("<<broj<<") = "<<f(broj);
                        std::cout<<" fapprox("<<broj<<") = "<<broj*broj + std::sin(broj)<<std::endl;
                    }
                    catch(const std::exception &e){
                        std::cout<<e.what();
                        validanUnos = false;
                    }
                }
                
            }
	return 0;
}