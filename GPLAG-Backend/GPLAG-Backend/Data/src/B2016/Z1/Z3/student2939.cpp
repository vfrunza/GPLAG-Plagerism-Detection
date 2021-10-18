/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<double> vektor;
typedef std::vector<vektor> matrica;

void IspisiMatricu(matrica m){
	std::cout<<std::endl;
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
matrica RastuciPodnizovi(vektor v){
	matrica m; 
	int j=0;
	int k=1;
	for(int i=0; i<v.size()-1; i++){
		if(v[i+1]>=v[i] && i<v.size()){
			m.resize(k);
			while(i<v.size()-1 && v[i+1]>=v[i]){
				m[j].push_back(v[i]);
				i++;
			}
			m[j].push_back(v[i]);
			if(m[j].size()==1){
				m.resize(k-1);
				j--;
				k--;
			} 
			j++;
			k++;
		}
	}
	return m;
}

matrica OpadajuciPodnizovi(vektor v){
	matrica m;
	int j=0;
	int k=1;
	for(int i=0; i<v.size()-1; i++){
		if(v[i+1]<=v[i] && i<v.size()-1){
			m.resize(k);
			while(i<v.size()-1 && v[i+1]<=v[i]){
				m[j].push_back(v[i]);
				i++;
			}
			m[j].push_back(v[i]);
			if(m[j].size()==1){
				m.resize(k-1);
				j--;
				k--;
			} 
			j++;
			k++;
		}
	}
	return m;
}

int main ()
{	
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	vektor v(n);
	for(int i=0; i<n; i++){
		std::cin>>v[i];
	}
	matrica m1(RastuciPodnizovi(v));
	matrica m2(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: ";
	IspisiMatricu(m1);
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	IspisiMatricu(m2);
	return 0;
}