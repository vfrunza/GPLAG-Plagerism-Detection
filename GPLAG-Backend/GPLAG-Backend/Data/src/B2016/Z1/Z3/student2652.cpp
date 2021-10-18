/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 
#include <cmath>
#include <iomanip>
#define EPSILON 0.000000000001
typedef std::vector <double> vektor; 
typedef std::vector <std::vector<double>> Matrica;
Matrica max (Matrica ukupno){ 
	Matrica konacna;
		for (int i=0; i<ukupno.size(); i++){
		int c(1);
		for (int j=0; j<ukupno.size(); j++){
		if (ukupno[i].size() <ukupno[j].size()) c=0; }
		if (c==1) konacna.push_back(ukupno[i]);
	} 
	return konacna;
}
	
Matrica RastuciPodnizovi(vektor k){
	int vel= k.size();
	int q(0),velicina;
	Matrica ukupno,konacna;
	vektor l, brojevi;
	for (int i=0; i<vel; i++){
		if (i==vel-1) break;
		if (k.at(i)-k.at(i+1)<=EPSILON) {
			for (int j=i; j<vel; j++){
				if (j==vel-1) {
					l.push_back(k[j]); i=j; ukupno.push_back(l);  
				velicina = l.size(); 
				 
				for (int n=0; n<velicina; n++){
					l.erase(l.begin());
				}
				break;
				}
				if (k.at(j)-k.at(j+1)<=EPSILON) l.push_back(k[j]);
				else {l.push_back(k[j]); i=j; ukupno.push_back(l);  
				 velicina = l.size(); 
				//std::cout<<velicina; 
				for (int n=0; n<velicina; n++){
					l.erase(l.begin());
				}
				break;}
			}
		}
		
	}
	for (int i=0; i<ukupno.size(); i++){
		int c(1);
		for (int j=0; j<ukupno.size(); j++){
		if (ukupno[i].size() <ukupno[j].size()) c=0; }
		if (c==1) konacna.push_back(ukupno[i]);
	}
//	return konacna; 
return ukupno;
}
Matrica OpadajuciPodnizovi(vektor k){
	int vel= k.size();
	int q(0),velicina;
	Matrica ukupno,konacna;
	vektor l, brojevi;
	for (int i=0; i<vel; i++){
		if (i==vel-1) break;
		if (k.at(i)-k.at(i+1)>=-EPSILON) {
			for (int j=i; j<vel; j++){
				if (j==vel-1) {
					l.push_back(k[j]); i=j; ukupno.push_back(l);  
				velicina = l.size(); 
				 
				for (int n=0; n<velicina; n++){
					l.erase(l.begin());
				}
				break;
				}
				if (k.at(j)-k.at(j+1)>=-EPSILON) l.push_back(k[j]);
				else {l.push_back(k[j]); i=j; ukupno.push_back(l);  
				 velicina = l.size(); 
				//std::cout<<velicina; 
				for (int n=0; n<velicina; n++){
					l.erase(l.begin());
				}
				break;}
			}
		}
		
	}
	for (int i=0; i<ukupno.size(); i++){
		int c(1);
		for (int j=0; j<ukupno.size(); j++){
		if (ukupno[i].size() <ukupno[j].size()) c=0; }
		if (c==1) konacna.push_back(ukupno[i]);
	}
	//return konacna;
	return ukupno;
}

int main ()
{  
	std::cout<<"Unesite broj elemenata vektora: "; 
	int n;
	double y;
	std::cin>>n;
	vektor brojevi;
	std::cout<<"Unesite elemente vektora: "; 
	for (int i=0; i<n; i++){
		std::cin>>y; brojevi.push_back(y);
	}
	Matrica rastuci= RastuciPodnizovi(brojevi);
	Matrica opadajuci= OpadajuciPodnizovi(brojevi);
	Matrica maxr = max(rastuci);
	Matrica maxo = max(opadajuci);
	std::cout<<"Maksimalni rastuci podnizovi:"; std::cout<<std::endl;
	for (vektor red: maxr) {
	for (double x: red) {std::cout<< x<<" ";}
	std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi:"; std::cout<<std::endl;
	for (vektor red: maxo) {
	for (double x: red) {std::cout<< x<<" ";}
	std::cout<<std::endl;
	} 
	/*
	
std::vector<double> brojevi {0.1, 0.1, 0.9, 0.9, -0.1, 0.1, -0.9, 0.9, -0.1, 0.1, 0.9, 0.9, 0.1, -0.1, 0.9, -0.9};
    std::vector<std::vector<double>> rastuci {RastuciPodnizovi(brojevi)}, opadajuci {OpadajuciPodnizovi(brojevi)};

    for (auto niz : rastuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    }

	std::cout << "_" << std::endl;
    for (auto niz : opadajuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    } */
	return 0;
}