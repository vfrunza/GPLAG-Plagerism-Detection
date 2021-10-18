//B 2016/2017, Zadaća 1, Zadatak 3

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(Matrica m) {
	std::cout << std::endl;
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++)
		std::cout << m[i][j] << " ";
		std::cout << std::endl;
	}
}
int BrojRedovaMatrice(std::vector<double> v, bool a){
	// kad je a tacno, vraca broj redova Matrice sa Rastucim podnizovima
	int br_kolona;										// kad je a netacno, vraca broj redova Matrice sa opadajucim podnizovima
	int br_redova(0);

	for(int i=0; i<v.size(); i++){
		br_kolona=1;
		if(a){
		for(int j=i+1; j<v.size(); j++){
			if(v[j]>=v[j-1])
			br_kolona++;
			else break;
		}
		
	}
		else if(a==0){
			for(int j=i+1; j<v.size(); j++){
				if(v[j]<=v[j-1])
				br_kolona++;
				else break;
			}
			}
			if(br_kolona>=2){
			br_redova++;
			i+=br_kolona-1;
		}
}
return br_redova;
}

Matrica RastuciPodnizovi(std::vector<double> v){
	
	int br_kolona;
	Matrica m(BrojRedovaMatrice(v, 1)); 
	int red_matrice(0); //  red matrice
	for(int i=0; i<v.size(); i++){
		br_kolona=1;
		for(int j=i+1; j<v.size(); j++){
			if(v[j]>=v[j-1])
			br_kolona++;
			else break;
		}
		if(br_kolona>=2){
			red_matrice++;
			for(int k=i; k<i+br_kolona; k++)
				m[red_matrice-1].push_back(v[k]);
			i+=br_kolona-1;
		}
	}
	return m;
	
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
			int br_kolona;
	Matrica m(BrojRedovaMatrice(v, 0)); 
	int red_matrice(0); //  red matrice
	for(int i=0; i<v.size(); i++){
		br_kolona=1;
		for(int j=i+1; j<v.size(); j++){
			if(v[j]<=v[j-1])
			br_kolona++;
			else break;
		}
		if(br_kolona>=2){
			red_matrice++;
			for(int k=i; k<i+br_kolona; k++)
				m[red_matrice-1].push_back(v[k]);
			i+=br_kolona-1;
		}
	}
	return m;
	
}

int main ()
{
	int x;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> x;
	std::vector<double> v(x);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<x; i++){
		std::cin >> v[i];
	}
	std::cout << "Maksimalni rastuci podnizovi: ";
	IspisiMatricu(RastuciPodnizovi(v));
	std::cout << "Maksimalni opadajuci podnizovi: ";
	IspisiMatricu(OpadajuciPodnizovi(v));

	return 0;
}