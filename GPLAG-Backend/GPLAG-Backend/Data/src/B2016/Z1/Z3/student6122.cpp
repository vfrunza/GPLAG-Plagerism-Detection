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

Matrica RastuciPodnizovi (std::vector<double> v) {
	Matrica m1;
	std::vector<double> v1;
	int p;
	for (int i(0) ; i<v.size(); i++) {
		int j=i+1;
		if (j>=v.size()) break;
		if (v[i] <= v[j]) {
			p = i;
		
		while (p < v.size()) {
			
		if ((p+1)>=v.size()) {
		break;
		}
		else if (v[p] <= v[p+1]){
				v1.push_back(v[p]);
				p++;
			}
		else if	(v[p] >v[p+1]) {
			v1.push_back(v[p]);
			break;
		}
			}
		}
		
		
		if (v1.size()==0) {
			continue;
		}
		m1.push_back(v1);
		v1.clear();
		if(p-(v.size()-1)==0) {
			break;

	}
	}

	
	return m1;
}


/*	while (i<brojevi.size()){
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
		} */

		/*
	for (i=j; i< v.size()-1; i++) {
		std::cout << "*";
			if (v[i] <= v[i+1]) {
				v1.push_back (v[i]);
				std::cout <<"5";
				if(i-v.size()-1==0) v1.push_back(v[i+1]);
			}
			else {
				if (v1.size()==0) 
				{
					i++;
					j=i;
				}
				else {
				v1.push_back(v[i]);
				
				j=i;
				m1.push_back(v1);
				v1.clear();
				}
				
			}
	}
	m1.push_back(v1);
	v1.clear();
	j=i+1;
	}
			
			*/

		

	


int main ()
{
	Matrica m1;
	int n, elementi;
	std::vector<double> v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	for (int i(0); i < n; i++) {
		std::cin >> elementi;
		v.push_back(elementi);
	}
	std::cout << "Maksimalni rastuci podnizovi: ";
	m1=RastuciPodnizovi(v);
	for (int i(0); i<m1.size(); i++){
		for(int j(0); m1[i].size(); j++) {
			std::cout << m1[i][j] << " ";
		}
		std::cout << std::endl;
		
	}
	
	return 0;
}