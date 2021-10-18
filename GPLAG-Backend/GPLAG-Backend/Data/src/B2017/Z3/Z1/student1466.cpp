/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
#include <stdexcept>
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi){
    std::sort(cvorovi.begin(), cvorovi.end(), []  (std::pair<double,double> x, std::pair<double,double> y) ->bool  { return x.first<y.first; });
   	bool provjera=false;
    for(int i=0; i<cvorovi.size(); i++){
    	for(int j=i+1; j<cvorovi.size(); j++){
    		if(cvorovi.at(j).first==cvorovi.at(i).first) provjera=true;
    	}
    	if(provjera) throw std::domain_error ("Neispravni cvorovi!");
    }
    return [cvorovi] (double x) { 
    							if(!(x>=cvorovi.at(0).first && x<=cvorovi.at(cvorovi.size()-1).first)) throw std::range_error("Argument izvan opsega!");
    							auto it=std::binary_search(cvorovi.begin(), cvorovi.end(), [x] (std::pair<double,double> xi)->bool {if(fabs(x-xi.first)<0) return true;
    																															return false;});
    							if(it) return;
    							else{
    							auto manji=cvorovi.at(0); 
    							for(int i=0; i<cvorovi.size(); i++){
									   if(cvorovi.at(i).first>x) break;
									   manji=cvorovi.at(i);
    							} 
    							auto veci=cvorovi.at(cvorovi.size()-1);
    							for(int i=cvorovi.size()-1; i>=0; i--){
    								if(cvorovi.at(i).first<x) break;
    								veci=cvorovi.at(i);
    							}
    								return manji.second+((veci.second-manji.second)/(veci.first-manji.first))*(x-manji.first);
    																							}
    };																
}
int main ()
{
	std::vector<std::pair<double, double>> parovi;
	parovi.resize(4);
	std::cout << "Unesite parove: " << std::endl;
	for(int i=0; i<parovi.size(); i++){
	    int a,b;
	    std::cin>>a>>b;
	    parovi.at(i)=std::make_pair(a,b);
	}
	auto f=LinearnaInterpolacija(parovi);
	std::cout<<std::endl<<f(2.5);
	return 0;
}
 /*bool provjera=false;
    for(int i=0; i<cvorovi.size(); i++){
    	for(int j=i+1; j<cvorovi.size(); j++){
    		if(cvorovi.at(j).first==cvorovi.at(i).first) provjera=true;
    	}
    	if(provjera) throw std::domain_error ("Neispravni cvorovi!");
    }*/