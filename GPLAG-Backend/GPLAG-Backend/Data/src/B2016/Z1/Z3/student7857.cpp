/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector> 

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> brojevi){
	std::vector<double> podniz;
	Matrica rastuca;
	int i=0;
	while (i<brojevi.size()){
		int j=i+1;
		if (j>=brojevi.size()) break;
		if (brojevi[j]>=brojevi[i]){
			podniz.push_back(brojevi[i]);
			podniz.push_back(brojevi[j]);
			i++;
			j++;
			if (j<brojevi.size()){
			while (brojevi[j]>=brojevi[i]){
				podniz.push_back(brojevi[j]);
				i++;
				j++;
				if (j>=brojevi.size()) break;
			}
		}
		}
		if (podniz.size()!=0) {
		rastuca.push_back(podniz);
		podniz.resize(0);
		}
		i++;
	}
	return rastuca;
}

Matrica OpadajuciPodnizovi (std::vector<double>brojevi){
	Matrica opadajuca;
	std::vector<double>podniz;
	int i=0;
	while (i<brojevi.size()){
		int j=i+1;
		if (j>=brojevi.size()) break;
		if (brojevi[j]<=brojevi[i]){
			podniz.push_back(brojevi[i]);
			podniz.push_back(brojevi[j]);
			i++;
			j++;
			if (j<brojevi.size()){
			while (brojevi[j]<=brojevi[i]){
				podniz.push_back(brojevi[j]);
				i++;
				j++;
				if (j>=brojevi.size()) break;
			}
		}
		}
		if (podniz.size()!=0){
			opadajuca.push_back(podniz);
			podniz.resize(0);
		}
		i++;
	}
	return opadajuca;
}


int main ()
{
	std::vector<double> niz;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>> n;
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<n; i++){
		double elementi;
		std::cin>>elementi;
		niz.push_back(elementi);
	}
	Matrica rastuca;
	rastuca=RastuciPodnizovi(niz);
	int max=0;
	for (int i=0; i<rastuca.size(); i++){
		if (rastuca[i].size()>rastuca[max].size()) max=i;
		}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for (int i=0; i<rastuca.size(); i++){
		for (int j=0; j<rastuca[i].size(); j++){
	if (rastuca[i].size()==rastuca[max].size()) std::cout<<rastuca[i][j]<<" ";
	}
	std::cout<<std::endl;
	}
	Matrica opadajuca;
	opadajuca=OpadajuciPodnizovi(niz);
	int maxi=0;
	for (int i=0; i<opadajuca.size(); i++){
		if (opadajuca[i].size()>opadajuca[maxi].size()) maxi=i;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for (int i=0; i<opadajuca.size(); i++){
		for (int j=0; j<opadajuca[i].size(); j++){
		if (opadajuca[i].size()==opadajuca[maxi].size())
		std::cout<<opadajuca[i][j]<<" ";
	}
	std::cout << std::endl;
	}
	return 0;
}