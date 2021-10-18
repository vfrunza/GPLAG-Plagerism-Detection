/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(vektor v){
	matrica rastuci;
	vektor podniz;

	for(int i=0;i<v.size()-1;i++){
		podniz.resize(0);
		if(v.size()>1 && v[i+1]>=v[i]){
			while((i+1)<v.size() && v[i+1]>=v[i]){
				podniz.push_back(v[i]);
				i++;
			}
			podniz.push_back(v[i]);
			if(podniz.size()>1){
				rastuci.push_back(podniz);
			}
		}
	}
	
	return rastuci;
}

matrica OpadajuciPodnizovi(vektor v){
	matrica opadajuci;
	vektor podniz;

	for(int i=0;i<v.size()-1;i++){
		podniz.resize(0);
		if(v.size()>1 && v[i+1]<=v[i]){
			while((i+1)<v.size() && v[i+1]<=v[i]){
				podniz.push_back(v[i]);
				i++;
			}
			podniz.push_back(v[i]);
			if(podniz.size()>1){
				opadajuci.push_back(podniz);
			}
		}
	}
	
	return opadajuci;
}

int main ()
{
	matrica rastuci;
	matrica opadajuci;
	vektor v;
	int brel;
	using std::cout; using std::cin;
	cout << "Unesite broj elemenata vektora: ";
	cin >> brel;
	if(brel<=0)return 0;
	cout << "Unesite elemente vektora: ";
	double x;
	for(int i=0;i<brel;i++){
		cin >> x;
		v.push_back(x);
	}
	rastuci = RastuciPodnizovi(v);
	cout << "Maksimalni rastuci podnizovi: \n";
	for(auto x : rastuci){
		for(auto y : x){
			cout << y << " ";
		}
		cout << "\n";
	}
	opadajuci = OpadajuciPodnizovi(v);
	cout << "Maksimalni opadajuci podnizovi: \n";
	for(auto x : opadajuci){
		for(auto y : x){
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}