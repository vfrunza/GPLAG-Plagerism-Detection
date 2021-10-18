#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;

Matrica RastuciPodnizovi(Vektor v){
	Matrica rastuci;
	int br(0);
	int velicina(1);
	for(int i = 0; i < velicina; i++){
		bool uvecaj(true);
		for(; br < int(v.size()); br++){
			if((br == int(v.size()) - 1 || v[br] > v[br+1]) && uvecaj == false){
				rastuci[i].push_back(v[br]);
				break;
			}
			if(br < v.size() - 1 && v[br] <= v[br+1]){
				if(uvecaj){
					rastuci.resize(velicina++);
					uvecaj = false;
				}
				rastuci[i].push_back(v[br]);
			}
		}
		if(br == int(v.size()) - 1)
			break;
	}
	return rastuci;
}

Matrica OpadajuciPodnizovi(Vektor v){
	Matrica opadajuci;
	int br(0);
	int velicina(1);
	for(int i = 0; i < int(v.size())/2 + 1; i++){
		bool uvecaj(true);
		for(; br < int(v.size()); br++){
			if((br == int(v.size()) - 1 || v[br] < v[br+1]) && uvecaj == false){
				opadajuci[i].push_back(v[br]);
				break;
			}
			if(br < v.size() - 1 && v[br] >= v[br+1]){
				if(uvecaj){
					opadajuci.resize(velicina++);
					uvecaj = false;
				}
				opadajuci[i].push_back(v[br]);
			}
		}
		if(br == int(v.size()) - 1)
			break;
	}
	return opadajuci;
}

int Najveci(Matrica mat){
	int max(0);
	for(int i = 0; i < int(mat.size()); i++){
		if(int(mat[i].size()) > max) max = int(mat[i].size());
	}
	return max;
}
int main ()
{
	Vektor brojevi;
	int brEl;
	cout << "Unesite broj elemenata vektora: ";
	cin >> brEl;
	if(brEl <= 1){
		cout << "Neispravan unos!";
		return 0;
	}
	cout << "Unesite elemente vektora: ";
	double broj;
	for(int i = 0; i < brEl; i++){
		cin >> broj;
		brojevi.push_back(broj);
	}
	Matrica rastuci(RastuciPodnizovi(brojevi));
	cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(Vektor i : rastuci){
		if(int(i.size()) == Najveci(rastuci)){
			for(double j : i)
				cout << std::setprecision(12) << j << " ";
			cout << std::endl;
		}
	}
	Matrica opadajuci(OpadajuciPodnizovi(brojevi));
	cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(Vektor i : opadajuci){
		if(int(i.size()) == Najveci(opadajuci)){
			for(double j : i)
				cout << std::setprecision(12) << j << " ";
			cout << std::endl;
		}
	}	
	
	return 0;
}