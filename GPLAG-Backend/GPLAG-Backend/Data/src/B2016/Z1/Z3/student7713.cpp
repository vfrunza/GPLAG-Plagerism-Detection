/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<double> Vector;
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova, int broj_kolona) {
	return Matrica(broj_redova, std::vector<double>(broj_kolona));
}
void IspisiMatricu(Matrica mat) {
	for(int i(0); i<mat.size(); i++) {
		for(int j(0); j<mat[i].size(); j++) 
			std::cout<<mat[i][j]<<" ";
		std::cout<<std::endl;
	}
}

Matrica OpadajuciPodnizovi(Vector v) {
	int brredova(0);
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]>=v[i+1]) {
			brredova++;
			while (v[i]>=v[i+1]) {
				i++;
				if(i==v.size()-1) break;
			}
		}
	}
	
	Matrica mat;
	mat.resize(brredova);
	int j(0);
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]>=v[i+1]) {
			while (v[i]>=v[i+1]) {
				mat[j].push_back(v[i]);
				i++;
				if(i==v.size()-1) break;
			}
			if(v[i]<=v[i-1]) mat[j].push_back(v[i]);
			j++;
		}
	}
	return mat;
}

Matrica RastuciPodnizovi(Vector v) {
	int brredova(0);
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]<=v[i+1]) {
			brredova++;
			while (v[i]<=v[i+1]) {
				i++;
				if(i==v.size()-1) break;
			}
		}
	} 
	Matrica mat;
	mat.resize(brredova);
	int j(0);
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]<=v[i+1]) {
			while(v[i]<=v[i+1]) {
				mat[j].push_back(v[i]);
				i++;
				if(i==v.size()-1) break;
			}
			if(v[i]>=v[i-1]) mat[j].push_back(v[i]);
			j++;
		}
	}
	return mat;
}

int main ()
{
	int brel;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> brel;
	Vector v;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<brel; i++) {
		int n;
		std::cin>>n;
		v.push_back(n);
	}
	std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica rastuci = RastuciPodnizovi(v);
	IspisiMatricu(rastuci);
	std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica opadajuci = OpadajuciPodnizovi(v);
	IspisiMatricu(opadajuci);
	return 0;
	
}