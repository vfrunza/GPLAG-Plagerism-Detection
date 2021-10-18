/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std :: vector<std :: vector<double>> Matrica;
typedef std :: vector<double> vector;

int Red(std :: vector<double> v){
	int red(0);
	
	for (int i(0); i<v.size()-1; i++){
		if(v.at(i)>v.at(i+1)) red++;
	}
	
	return red;
	
}

/*Matrica RastuciPodnizovi(std :: vector<double> v){
	Matrica m;
	int red(0);
	
	for (int i(0); i<v.size(); i++){
		if(v.at(i)<v.(i+1)){
			while(v.at(i)<v.at(i+1)) if(v.at(i)>v.at(i+2)) red++;
		}
	}
	
	
} */
int main ()
{
	vector v;
	int br_el, n;
	std::cout <<"Unesite broj elemenata vektora: ";
	std :: cin >>br_el;
	std :: cout <<"Unesite elemente vektora: ";
	
	for(int i(0);i<br_el; i++){
		std :: cin >> n;
		v.push_back(n);
	}
	
	
		                     //             	while(v[i]<v[i+1]) m.at(i).push_back(v[i]);
		                     

	Matrica m;

	int r=Red(v);
	
	m.resize(r);
	
	
	for(int i(0); i<r ; i++){
		for(int j(0); j<v.size()-1; j++){
			while(v.at(j)<v.at(j+1)){
				m[i][j]=v.at(j);
				std :: cout << m[i][j];
		}
	}
	}
	
	
	/*for(int i(0); i<v.size()-1;i++){
		if(v.at(i)<v.at(i+1)) {
			while(v.at(i)<v.at(i+1) && j<r){
			m[i][j]=v.at(i);
			j++;
		}
}
}
*/
for(int i(0); i<r; i++){
	for(int j(0); j<m[i].size(); j++){
		std :: cout << m[i][j];
	}
}
	
	
	
	return 0;
}