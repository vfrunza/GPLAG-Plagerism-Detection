/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <cmath>
#include <vector>

int obrni (int broj){
	int obrnut=0, pomocni=broj;
	while (pomocni != 0){
		obrnut *= 10;
		obrnut += pomocni % 10;
		pomocni /= 10;
	}
	return obrnut;
}


int PretvoriBrojUTernarni (int broj){
	int br(0);
	while(broj != 0){
		int cifra = broj % 3;
		br = br*10 + cifra;
		broj /= 3;
	}
	return br;
}

bool Simetrican(int broj){
	broj = PretvoriBrojUTernarni(broj);
	if(broj == obrni(broj)) return true ;
	return false;
}
bool Prost (int broj){
	if(broj<0) broj *= -1;
	bool jest_prost(true);
	for(int i=2; i <= std::sqrt(broj); i++){
		if(broj%i == 0){
			jest_prost = false;
			break;
		}
	}
	return jest_prost;
}

std::vector<int> IzbaciIste(std::vector<int> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++){
			if(v.at(i) == v.at(j) && i!=j){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool tacno) {
	std::vector<int> prosti, neki_vektor, slozeni;
	neki_vektor = v;
	for(int i=0; i<v.size(); i++){
		
		if(Prost(v.at(i)) == true && Simetrican(neki_vektor.at(i)) == true && tacno == true) prosti.push_back(v.at(i));
		else if(Prost(v.at(i))== false && Simetrican(neki_vektor.at(i)) == true && tacno == false ) slozeni.push_back(v.at(i));
	}
	
	
	/*for(int i=0; i<prosti.size(); i++){
		for (int j=0; j<prosti.size(); j++){
			if(prosti.at(i) == prosti.at(j) && i != j){
					prosti.erase(prosti.begin()+j);
					j--;
			}
		}
	}
	
	for(int i=0; i<slozeni.size(); i++){
		for(int j=0; j<slozeni.size(); j++){
			if(slozeni.at(i) == slozeni.at(j) && i!=j){
				slozeni.erase(slozeni.begin()+j);
				j--;
			}
		}
	}*/
	std::vector<int> gotovi_prosti (IzbaciIste(prosti));
	std::vector<int> gotovi_slozeni(IzbaciIste(slozeni));
	if(tacno) return gotovi_prosti;
	return gotovi_slozeni;
}
int main ()
{	
	std::vector<int> v;
	int broj(0);
	std::cout << "Unesite elemente vektora (-1 za kraj): "; 
	do{
		std::cin >> broj; 
		if(broj != -1) v.push_back(broj);
	} while (broj != -1) ;
	
	int jedannula;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> jedannula;
	if(jedannula != 0 && jedannula != 1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> jedannula;
	}
/*	while(1) {
	     std::cin >> jedannula;
	     if(jedannula == 0 || jedannula == 1) break;
		 std::cout << "Neispravan unos! Unesite ponovo: ";
		 std::cin.clear();
		 std::cin.ignore(10000,'\n');
		 //std::cin >> jedannula;
	} */
	
	if(jedannula == 1){
		std::vector<int> y = IzdvojiSimetricneTernarne(v, jedannula);
		if(y.size() == 0) { std::cout << "Nema prostih simetricnih brojeva u vektoru.";  return 0;}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";


		int i(0); int n=y.size();
		for( i=0; i<n-1; i++) {
		std::cout << y.at(i) << ", ";
		}
		std::cout << y.at(n-1) << "."<< std::endl;
	
	}
	
	else {
		std::vector<int> y=IzdvojiSimetricneTernarne(v, jedannula) ;
		int n=y.size();
		if(n==0) {  std::cout << "Nema slozenih simetricnih brojeva u vektoru."; return 0; }
		
		std::cout << "Slozeni simetricni brojevi iz vektora su: " ;
		for(int i=0; i <n-1; i++){
			std::cout << y.at(i) << ", ";
		}
		std::cout << y.at(n-1) << "." << std::endl;
		
	}
	
	return 0;
}