/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>>mat;
	if(v.size()==0) return mat;
	for(int i=0; i<(v.size()-1); i++){
		if(v[i]<=v[i+1]){
			int j=i;
			while(j<(v.size()-1) && v[j]<=v[j+1])
				j++;
			if((j-i)==0) continue;
			else{
				std::vector<double>v1;
				for(int k=i; k<=j; k++)
					v1.push_back(v[k]);
				mat.push_back(v1);
			}
			i=j;
		}
	}
	return mat;
}
std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>>mat;
	if(v.size()==0) return mat;
	for(int i=0; i<v.size()-1; i++){
		if(v[i]>=v[i+1]){
			int j=i;
			while(j<(v.size()-1) && v[j]>=v[j+1])
				j++;
			if((j-i)==0) continue;
			else{
				std::vector<double>v1;
				for(int k=i; k<=j; k++)
					v1.push_back(v[k]);
				mat.push_back(v1);
			}
			i=j;
		}
	}
	return mat;
}
int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	double broj;
	std::vector<double>vektor;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		cin>>broj;
		vektor.push_back(broj);
	}
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	std::vector<std::vector<double>>matrica=RastuciPodnizovi(vektor);
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++)
			cout<<matrica[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	std::vector<std::vector<double>>matrica1=OpadajuciPodnizovi(vektor);
	for(int i=0; i<matrica1.size(); i++){
		for(int j=0; j<matrica1[i].size(); j++)
			cout<<matrica1[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}