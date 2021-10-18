/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {
	
	std::vector<std::vector<double>> Rezultat;
	int pozicija (0);
	
	for (int i=pozicija; i<v.size(); i++) {
		i=pozicija;
		std::vector<double> Podniz {v[i]};
		
		int brojac(i);
		for (int j=brojac+1; j<v.size(); j++) {
			if (brojac<v.size() && v[j]>=v[brojac]) {
				Podniz.push_back (v[j]);
				brojac ++;
			}
			else break;
		}
		if (Podniz.size()>=2) {
			Rezultat.push_back(Podniz);
			pozicija=brojac;
		}
		else 
		pozicija++;
	}
	return Rezultat;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v) {
	
	std::vector<std::vector<double>> Rezultat;
	int pozicija (0);
	
	for (int i=pozicija; i<v.size(); i++) {
		i=pozicija;
		std::vector<double> Podniz {v[i]};
		
		int brojac(i);
		for (int j=brojac+1; j<v.size(); j++) {
			if (brojac<v.size() && v[j]<=v[brojac]) {
				Podniz.push_back (v[j]);
				brojac ++;
			}
			else break;
		}
		if (Podniz.size()>=2) {
			Rezultat.push_back(Podniz);
			pozicija=brojac;
		}
		else 
		pozicija++;
	}
	return Rezultat;
}


int main () {
	
	double m;
	int n=0;
	std::vector<double> v(n);
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		std::cin>> m;
	     v.push_back(m);
	}
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;;
		auto Rez2 (RastuciPodnizovi (v));
    for (int i=0; i<Rez2.size(); i++) {
    	for (int j=0; j<Rez2[i].size(); j++) {
    		std::cout<<Rez2[i][j]<<" ";
    	
    	}
    	std::cout<<std::endl;
    }
    
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	auto Rez1 (OpadajuciPodnizovi (v));
    for (int i=0; i<Rez1.size(); i++) {
    	for (int j=0; j<Rez1[i].size(); j++) {
    		std::cout<<Rez1[i][j]<<" ";
    	
    	}
    	std::cout<<std::endl;
    }
	
	
	return 0;
}