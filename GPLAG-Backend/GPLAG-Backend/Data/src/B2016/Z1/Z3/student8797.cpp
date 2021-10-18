/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <climits>


std::vector<std::vector<double>> KreirajMatricu(int broj_redova,int broj_kolona) {
   return std::vector<std::vector<double>>(broj_redova, std::vector<double>(broj_kolona));
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> a(KreirajMatricu(0,0));
	if(v.size()==0 || v.size()==1)
		return a;
	int n(-1);
	for(unsigned int j=0; j<v.size()-1; j++){
		if(v.at(j)<=v.at(j+1)){
			a.push_back(std::vector<double>{});
            n++;		
			while(j<v.size()-1 && v.at(j)<=v.at(j+1)){
				a.at(n).push_back(v.at(j));
				j++;
			}
			a.at(n).push_back(v[j]);
		}
	}
	return a;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> a;
	if(v.size()==0 || v.size()==1)
		return a;
	int n(-1);
	for(unsigned int j=1; j<v.size(); j++){
		if(v.at(j-1)>=v.at(j)){
				a.push_back(std::vector<double>{});
                n++;		
				while(j<v.size() && v.at(j-1)>=v.at(j)){
						a.at(n).push_back(v.at(j-1));
						j++;
				}
				a[n].push_back(v[j-1]);
			}
		}
	return a;
}


int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	while (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> n;}
	
	std::vector<double> v;
	int x;
	std::cout << "Unesite elemente vektora: ";
	for(unsigned int i=0; i<n; i++){
		std::cin >> x;
		while (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> x;}
        v.push_back(x);    
	}
	
	std::vector<std::vector<double>> rez=RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi:  \n" << std::endl;
	for(unsigned int i =0; i<rez.size(); i++){
	    	for(unsigned int j=0; j<rez[i].size(); j++){
	    		if (j==rez[i].size()-1)
	    			std::cout << rez[i][j];
	    		else 	
	    			std::cout<<rez[i][j]<<" ";
	    	}
	    	std::cout <<std::endl;
	    }
	std::cout << "Maksimalni opadajuci podnizovi: \n";    
	std::vector<std::vector<double>> rezz=OpadajuciPodnizovi(v);
	for(unsigned int i =0; i<rezz.size(); i++){
	    	for(unsigned int j=0; j<rezz[i].size(); j++){
	    		if (j==rezz[i].size()-1)
	    			std::cout <<rezz[i][j];
	    		else 	
	    			std::cout<<rezz[i][j]<<" ";
	    	}
	    	std::cout << "\n";
	    }   
	return 0;
}