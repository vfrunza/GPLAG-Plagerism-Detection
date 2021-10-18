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
	Matrica m;
	int j=0;
	m.resize(1);
	for (int i=0; i<v.size()-1; i++) {
		if (v[i]<=v[i+1]) {
			while (v[i]<=v[i+1]) {
				m[j].push_back(v[i]);
				if (i<v.size()-2)
				    i++;
				else break;
			}
			if (i<v.size()-2)
			    m[j].push_back(v[i]);
			else if (i==v.size()-2)
			    m[j].push_back(v[i+1]);
			j++;
			m.resize(j+1);
		}
	}
	return m;
}

Matrica OpadajuciPodnizovi (std::vector<double> v) {
	Matrica m;
	int j=0;
	m.resize(1);
	for (int i=0; i<v.size()-1; i++) {
		if (v[i]>=v[i+1]) {
			while (v[i]>=v[i+1]) {
				m[j].push_back(v[i]);
				if (i<v.size()-2) 
					i++;
				else break;
			}
			if (i<v.size()-2)
			    m[j].push_back(v[i]);
			else if (i==v.size()-2)
			    m[j].push_back(v[i+1]);
			j++;
			m.resize(j+1);
		}
	}
	return m;
}
int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<n; i++) 
	   std::cin >> v[i];
	Matrica mrp=RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i=0; i<mrp.size(); i++) {
		for (int j=0; j<mrp[i].size(); j++) 
			std::cout << mrp[i][j] << " ";
	    std::cout << std::endl;
	}
	Matrica mop=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i=0; i<mop.size(); i++) {
		for (int j=0; j<mop[i].size(); j++)
		    std::cout << mop[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}