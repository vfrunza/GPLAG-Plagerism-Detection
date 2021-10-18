/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica m;
	int pocetak, kraj, br_redova=0;
	for(int i=1; i<v.size(); i++){
		if(v[i-1] <= v[i]){
			pocetak = i-1;
			br_redova++;
			m.resize(br_redova);
			int j;
			for(j=i+1; j<v.size(); j++){
				if(v[j-1] <= v[j]){
					continue;
				}else{
					break;
				}
			}
			kraj = j;
			for(j=pocetak; j<kraj; j++){
				m[br_redova-1].push_back(v[j]);
			}
			i= kraj-1;
		}
	}
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica m;
	int pocetak, kraj, br_redova=0;
	for(int i=1; i<v.size(); i++){
		if(v[i-1] >= v[i]){
			br_redova++;
			m.resize(br_redova);
			pocetak = i-1;
			int j;
			for(j=i+1; j<v.size(); j++){
				if(v[j-1] >= v[j]){
					continue;
				}else{
					break;
				}
			}
			kraj = j;
			for(j = pocetak; j<kraj; j++){
				m[br_redova-1].push_back(v[j]);
			}
			i = kraj-1;
		}
	}
	return m;
}

void IspisiMatricu(Matrica m){
	int br_redova(m.size());
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> v;
	double broj;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin >> broj;
		v.push_back(broj);
	}
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	IspisiMatricu(RastuciPodnizovi(v));
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	IspisiMatricu(OpadajuciPodnizovi(v));
	
	return 0;
}