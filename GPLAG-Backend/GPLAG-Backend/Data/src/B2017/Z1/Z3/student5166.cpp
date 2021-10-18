//B 2017/2018, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

enum Smjer {Rastuci, Opadajuci};
typedef deque<vector<int>> Matrica;

Matrica MaksimalniPodnizoviStepenaDvojke (vector<int>v, Smjer s){
	Matrica m;
	if (s == Smjer::Rastuci){
		int brojac(1), brojac_matrice(1);
		for (int i=0; i<v.size()-1; i++){
			brojac = i;
			
			while (v.at(brojac) < v.at(brojac+1)){
	
				//Je li stepen dvojke
				bool test(true);
				for (int l=1; l<100; l*=2){
					if (l==v.at(brojac)) break;
					if (l>v.at(brojac)){
						test = false; break;
					}
				}
				for (int l=1; l<100; l*=2){
					if (l==v.at(brojac+1)) break;
					if (l>v.at(brojac+1)){
						test = false; break;
					}
				}
				if (test) brojac++;
				else break;
				if (brojac+1 >= v.size()) break;
			}
			
			if (brojac != i){ //Ubacuje vektor u matricu
				brojac++;
				m.resize(brojac_matrice);
				m.at(brojac_matrice-1).resize(brojac-i);
				for (int j=0; j<brojac-i; j++){
					m.at(brojac_matrice-1).at(j) = v.at(i+j);
				}
				brojac_matrice++;
				i=brojac-2;
			}
		}
	}
	if (s == Smjer::Opadajuci){
		int brojac(1), brojac_matrice(1);
		for (int i=0; i<v.size()-1; i++){
			brojac = i;
			
			while (v.at(brojac) > v.at(brojac+1)){
				//Je li stepen dvojke
				bool test(true);
				for (int l=1; l<100; l*=2){
					if (l==v.at(brojac)) break;
					if (l>v.at(brojac)){
						test = false; break;
					}
				}
				for (int l=1; l<100; l*=2){
					if (l==v.at(brojac+1)) break;
				    if (l > v.at(brojac+1)){
				    	test = false; break;
				    }
				}
				if (test) brojac++;
				else break;
				if (brojac+1 >= v.size()) break;
			}
			
			if (brojac != i){ // Ubacuje vektor u matricu
				brojac++;
				m.resize(brojac_matrice);
				m.at(brojac_matrice-1).resize(brojac-i);
				for (int j=0; j<brojac-i; j++){
					m.at(brojac_matrice-1).at(j) = v.at(i+j);
				}
				brojac_matrice++;
				i=brojac-1;
			} 
		}
	}
	
	return m;
}

int main (){
	
	int n, var;
	vector<int>v;
	cout << "Unesite broj elemenata vektora: ";
	    cin >> n;
	    cout << "Unesite elemente vektora: ";
	    for (int i=0; i<n; i++){
	    	double broj;
	    	cin >> broj;
	    	v.push_back(broj);
	    }
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin >> var;
	
	if (var==1){
		cout << "Maksimalni rastuci podnizovi:\n" << endl;
		Matrica rastuci(MaksimalniPodnizoviStepenaDvojke(v,Smjer::Rastuci));
		for (int i=0; i<rastuci.size(); i++){
			for (int j=0; j<rastuci.at(i).size(); j++){
				cout << rastuci.at(i).at(j) << " ";
			}
			cout << endl;
		}
	}
	if (var == 2){
		cout << "Maksimalni opadajuci podnizovi:\n";
		Matrica opadajuci (MaksimalniPodnizoviStepenaDvojke(v,Smjer::Opadajuci));
		for (int i=0; i<opadajuci.size(); i++){
		    for (int j=0; j<opadajuci.at(i).size(); j++){
			    cout << opadajuci.at(i).at(j) << " ";
		    }
		    cout << endl;
	    }
	}
	
	return 0;
}