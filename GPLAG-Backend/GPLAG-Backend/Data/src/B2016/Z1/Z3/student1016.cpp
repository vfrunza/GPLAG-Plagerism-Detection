/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>

typedef std::vector<double> vektor;

using std::cout;
using std::cin;


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> mat;
	if(v.size()==0) return mat;
	for(int i=0; i<v.size(); i++){
		vektor temp;
		while(i<v.size()-1 and (v.at(i)<v.at(i+1) or v.at(i)-v.at(i+1)<0.0000000001)){
			temp.push_back(v.at(i));
			i++;
		} 
		temp.push_back(v.at(i));
		if(temp.size()<2) continue;
		mat.push_back(temp);
	}
	return mat;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> mat;
	if(v.size()==0) return mat;
	for(int i=0; i<v.size()-1; i++){
		vektor temp;
		while(i<v.size()-1 and (v.at(i)>v.at(i+1) or v.at(i+1)-v.at(i)<0.0000000001)){
			temp.push_back(v.at(i));
			i++;
		}
		temp.push_back(v.at(i));
		if(temp.size()<2) continue;
		mat.push_back(temp);
	}
	return mat;
}

int main ()
{
	vektor v;
	cout << "Unesite broj elemenata vektora: ";
	int n;
	cin >> n;
	cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		double a;
		cin >> a;
		v.push_back(a);
	}
	cout << "Maksimalni rastuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> matrica(RastuciPodnizovi(v));
	for(int i=0; i<matrica.size(); i++){
		for(int j=0;j<matrica.at(i).size(); j++){
			cout<< matrica[i][j]<<" ";
		}
		cout << std::endl;
	}
	
	cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	matrica=OpadajuciPodnizovi(v);
	for(int i=0; i<matrica.size(); i++){
		for(int j=0;j<matrica.at(i).size(); j++){
			cout<< matrica[i][j]<<" ";
		}
		cout << std::endl;
	}

	return 0;
}