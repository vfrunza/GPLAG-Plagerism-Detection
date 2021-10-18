/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz){
	std::vector<std::vector<double>> vrati;
	int duz{0}, k;
		for(int i{0}; i<niz.size(); i++){
			k=i;
			for(int j{i+1}; j<niz.size(); j++){
				if(niz.at(j) >= niz.at(i) && niz.at(j) >= niz.at(j-1)){
					k=j;
				}else break;
			}
			if(k > i){
				k++;
				vrati.push_back(std::vector<double> (k-i));
				std::vector<double> pomoc;
				for(int h{i}; h<k; h++){
					pomoc.push_back(niz.at(h));
				}
				vrati.at(duz)=pomoc;
				duz++;
				i=k-1;
			}
		}
	return vrati;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz){
	std::vector<std::vector<double>> vrati;
	int duz{0}, k;
	for(int i{0}; i<niz.size(); i++){
		k=i;
		for(int j{i+1}; j<niz.size(); j++){
			if(niz.at(j) <= niz.at(i) && niz.at(j) <= niz.at(j-1)){
				k=j;
			}else break;
		}
		if(k > i){
			k++;
			vrati.push_back(std::vector<double> (k-i));
			std::vector<double> pomoc;
			for(int h{i}; h<k; h++){
				pomoc.push_back(niz.at(h));
			}
			vrati.at(duz)=pomoc;
			duz++;
			i=k-1;
		}
	}
	return vrati;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> brojevi(n);
	for(double &i:brojevi) std::cin >> i;
	auto rastuci (RastuciPodnizovi(brojevi));
	std::cout << "Maksimalni rastuci podnizovi: \n";
	for(std::vector<double> i:rastuci){
		for(double j:i){
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	auto opadajuci (OpadajuciPodnizovi(brojevi));
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	for(std::vector<double> i:opadajuci){
		for(double j:i){
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}