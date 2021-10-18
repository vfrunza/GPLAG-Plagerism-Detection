/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.0
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
std::vector<std::vector<double>> rez;
	int brojac = 0;
	for(int i = 0; i < v.size()-1; i++){
		bool ind = false;
		int j = i+1;
		int temp = i;
		while(j < v.size() && v[j] <= v[temp]){ j++; temp++; ind = true; }
		if(ind == true){
			brojac++;
			rez.resize(brojac);
			for(int k = i, pom = 0; k < j; k++, pom++){
				rez[brojac-1].push_back(v[k]);
			}
		}
		i = j-1;
	}
	return rez;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
std::vector<std::vector<double>> rez;
	int brojac = 0;
	for(int i = 0; i < v.size()-1; i++){
		bool ind = false;
		int j = i+1;
		int temp = i;
		while(j < v.size() && v[j] >= v[temp]){ j++; temp++; ind = true; }
		if(ind == true){
			brojac++;
			rez.resize(brojac);
			for(int k = i, pom = 0; k < j; k++, pom++){
				rez[brojac-1].push_back(v[k]);
			}
		}
		i = j-1;
	}
	return rez;
}
int main (){
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::vector<double> a(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i++) std::cin >> a[i];
	std::cout << "Maksimalni rastuci podnizovi: \n";
	std::vector<std::vector<double>> rp=RastuciPodnizovi(a);
	for(int i = 0; i < rp.size(); i++){
		for(int j = 0; j < rp[i].size(); j++) std::cout << rp[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	std::vector<std::vector<double>> op=OpadajuciPodnizovi(a);
	for(int i = 0; i < op.size(); i++){
		for(int j = 0; j < op[i].size(); j++) std::cout << op[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}