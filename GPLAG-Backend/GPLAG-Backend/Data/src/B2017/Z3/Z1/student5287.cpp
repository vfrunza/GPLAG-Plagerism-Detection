#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

using std::vector;
using std::pair;

typedef pair<double, double> ddpair;

std::function<double(double)> LinearnaInterpolacija(const vector<ddpair> &vars){
    vector<ddpair> nconst = vars;
    std::sort(nconst.begin(), nconst.end());
    
    //Posto je nconst sortiran, uklonice se jednaki cvorovi,
    //pa ako je velicina nconst-a razlicita od vars-a
    //onda je bilo uklonjenih elemenata te treba baciti izuzetak
    std::unique(nconst.begin(), nconst.end(), [](ddpair a, ddpair b){
        return a.first == b.first;
    });
    
    if(nconst != vars)
        throw std::domain_error("Neispravni cvorovi");
    
    //U suprotnom, unique nece nikako izmijeniti nconst, pa se
    //moze nastaviti rad s njim
    
    return [nconst](double x){
        if(x < nconst[0].first || x > nconst[nconst.size()-1].first)
            throw std::range_error("Argument izvan opsega");
        
        if(x == nconst[0].first)
            return nconst[0].second;
        
        const pair<double, double> xPair = std::make_pair<double&,double>(x, 0.0);
        auto it = std::upper_bound(nconst.begin(), nconst.end(), xPair);
        
        return (it-1)->second + ((it->second - (it-1)->second)/(it->first - (it-1)->first))*(x - (it-1)->first);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx){
    if(xmin > xmax || dx <= 0)
        throw std::domain_error("Nekorektni parametri");
    
    vector<ddpair> vars;
    
    //Kreiraj cvorove
    int i = 0;
    double v;
    while(v = xmin + i * dx, v <= xmax){
        vars.push_back({v, f(v)});
        i++;
    }
    
    return [vars](double x){
        if(x < vars[0].first || x > vars[vars.size()-1].first)
            throw std::range_error("Argument izvan opsega");
        
        if(x == vars[0].first)
            return vars[0].second;
        
        const pair<double, double> xPair = std::make_pair<double&,double>(x, 0.0);
        auto it = std::upper_bound(vars.begin(), vars.end(), xPair);
        
        return (it-1)->second + ((it->second - (it-1)->second)/(it->first - (it-1)->first))*(x - (it-1)->first);
    };
}

int main () {
    int opt;
	std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	std::cin >> opt;
	
	if(opt == 1){
	    int n;
	    
	    std::cout << "Unesite broj cvorova: ";
	    std::cin >> n;
	    
	    vector<ddpair> vars(n);
	    std::cout << "Unesite cvorove kao parove x y: ";
	    for(int i = 0; i < n; i++){
	        std::cin >> vars[i].first >> vars[i].second;
	    }
	    
	    try{
	        auto f = LinearnaInterpolacija(vars);
	        double x;
    	    while(true){
    	        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
    	        std::cin >> x;
    	        if(!std::cin){
    	            std::cin.clear();
    	            break;
    	        }
    	        try{
    	            std::cout << "f(" << x << ") = " << f(x);
    	        }catch(std::range_error &err){
    	            std::cout << err.what();
    	        }
    	        std::cout << std::endl;
    	    }
	    }catch(std::domain_error &err){
	        std::cout << err.what();
	    }
	}else if(opt == 2){
	    double xmin, xmax, dx;
	    
	    std::cout << "Unesite krajeve intervala i korak: ";
	    std::cin >> xmin >> xmax >> dx;
	    
	    auto funk = [](double x){
	        return x*x + std::sin(x);
	    };
	    
	    try{
	        auto f = LinearnaInterpolacija(funk, xmin, xmax, dx);
	        double x;
    	    while(true){
    	        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
    	        std::cin >> x;
    	        if(!std::cin){
    	            std::cin.clear();
    	            break;
    	        }
    	        try{
    	            std::cout << "f(" << x << ") = " << funk(x)
    	                << " fapprox(" << x << ") = " << f(x);
    	        }catch(std::range_error &err){
    	            std::cout << err.what();
    	        }
    	        std::cout << std::endl;
    	    }
	    }catch(std::domain_error &err){
	        std::cout << err.what();
	    }
	}
	
	return 0;
}
