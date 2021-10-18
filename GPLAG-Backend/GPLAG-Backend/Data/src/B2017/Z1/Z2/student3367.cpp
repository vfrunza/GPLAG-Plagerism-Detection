/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector> 
#include <stdexcept>
#include <iomanip>

int x;
int y;
double SaberiRubne(std::vector<std::vector<double>> v, int poc_i, int poc_j, int kraj_i, int kraj_j){
	double suma = 0;
	for(int i = poc_i; i <= kraj_i; i++){
		for(int j = poc_j; j<= kraj_j; j++){
			
			if(i == poc_i || i == kraj_i || j == kraj_j || j == poc_j){
				suma+= v.at(i).at(j);
			}
		}
	}
	return suma;
}

bool ProvjeriJeLiVrh(std::vector<std::vector<double>> v, int prva_koord, int druga_koord){
	double eps = 0.0001;
	if(v.at(prva_koord).at(druga_koord) - SaberiRubne(v,prva_koord-1,druga_koord-1,prva_koord+1,druga_koord+1) < -eps) return false;
	return true;
}

int KolikoKoncentricnih(std::vector<std::vector<double>> v, int prva_koord, int druga_koord){
	double eps = 0.00001;
	int k = 1;
	double sum = SaberiRubne(v, prva_koord-1, druga_koord-1, prva_koord+1, druga_koord+1);
	while(prva_koord-1-k >= 0 && druga_koord-1-k >= 0  && prva_koord+1+k < x && druga_koord+1+k <y && SaberiRubne(v,prva_koord-1-k,druga_koord-1-k,prva_koord+1+k,druga_koord+1+k) - sum < -eps){
		sum = SaberiRubne(v,prva_koord-1-k, druga_koord-1-k, prva_koord+1+k,druga_koord+1+k);
		k++;
	}
	return k;
}

std::vector<std::vector<double>> NapraviMatricu(std::vector<std::vector<double>> v, int poc_i, int poc_j, int kraj_i, int kraj_j){
	std::vector<std::vector<double>> novi;
	for(int i = poc_i; i <= kraj_j; i++){
		std::vector<double> tmp;
		for(int j = poc_j; j <= kraj_j; j++){
			tmp.push_back(v.at(i).at(j));
		}
		novi.push_back(tmp);
	}
	return novi;
}
void ProvjeriJeLiGrbava(std::vector<std::vector<double>> v){
	for(int i = 0; i < v.size(); i++){
		if(v.at(i).size() != v.at(0).size()) throw std::domain_error("Matrica nije korektna");
	}
}
std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> v){
	ProvjeriJeLiGrbava(v);
	double eps = 0.00001;
	int prva_koord = 0;
	int druga_koord = 0;
	int max_broj_konc = 0;
	if(v.size() == 0) return v;
	if(v.size() <=2 || v.at(0).size() <=2){
		double max=0;
		for(int i = 0; i < v.size(); i++){
			for(int j = 0; j < v.at(i).size(); j++){
				if(v.at(i).at(j)-max >eps) {
					max = v.at(i).at(j); 
				}
			}
		}
		return std::vector<std::vector<double>> {{max}};
		
	}
	for(int i = 1; i < v.size()-1; i++){
		for(int j = 1; j < v.at(i).size() -1; j++){
			if(ProvjeriJeLiVrh(v,i,j)){
				int k = KolikoKoncentricnih(v,i,j);
				if(k > max_broj_konc){
					max_broj_konc = k;
					prva_koord = i;
					druga_koord = j;
				}
				else if(k == max_broj_konc){
					if(v.at(i).at(j) - v.at(prva_koord).at(druga_koord) > eps){
						prva_koord = i;
						druga_koord = j;
					}
				}
			}
		}
	}
	
	auto nova = NapraviMatricu(v, prva_koord-max_broj_konc, druga_koord - max_broj_konc, prva_koord+max_broj_konc, druga_koord + max_broj_konc);
	return nova;
}
int main ()
{
	int m,n;
	
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n< 0) {
	std::cout << "Dimenzije matrice moraju biti nenegativne!";
	return 0;
	}
	x=m;
	y =n;
	std::cout << "Unesite elemente matrice:";
	std::vector<std::vector<double>> v;
	for(int i = 0; i < m; i++){
		std::vector<double> tmp;
		for(int j = 0; j < n; j++){
			double k;
			std::cin>>k;
			tmp.push_back(k);
		}
		v.push_back(tmp);
	}
	
	std::cout<<std::endl;
	std::cout << "Najveca planina unesene matrice je:" <<std::endl;
	auto nova = NajvecaPlaninaMatrice(v);
	
	for(int i = 0; i < nova.size(); i++){
		for(int j = 0; j < nova.at(i).size(); j++){
			std::cout << std::setw(6) << nova.at(i).at(j);
		}
		std::cout << std::endl;
	}
	

	return 0;
}