/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;



std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> matrica;
	std::vector<double> novi;
	for(int i=0; i<v.size()-1; i++){
		while(i<v.size()-1 && v[i]<v[i+1]){
			novi.push_back(v[i]);
			i++;
		}
		matrica.push_back(std::vector<double>(novi.size()));
		int j(0);
		for(int k=0; k<novi.size(); k++)
			matrica[j][k]=novi[k];
		j++;
		i--;
		std::vector<double> novi(0);
	}
	return matrica;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> matrica;
	std::vector<double> novi;
	for(int i=0; i<v.size()-1; i++){
		while(i<v.size()-1 && v[i]>v[i+1]){
			novi.push_back(v[i]);
			i++;
		}
		matrica.push_back(std::vector<double>(novi.size()));
		int j(0);
		for(int k=0; k<novi.size(); k++)
			matrica[j][k]=novi[k];
		j++;
		i--;
		std::vector<double> novi(0);
	}
	return matrica;
}



int main ()
{
	int vel;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>vel;
	std::vector<double> v(vel);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++){
		cin>>v.at(i);
	}
	std::vector<std::vector<double>> matrica1=RastuciPodnizovi(v);
	std::vector<std::vector<double>> matrica2=OpadajuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<matrica1.size(); i++){
		for(int j=0; j<matrica1[i].size();j++){
			cout<<matrica1[i][j];
		}
		cout<<std::endl;
	}
	cout<<std::endl<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<matrica2.size(); i++){
		for(int j=0; j<matrica2[i].size(); j++){
			cout<<matrica2[i][j];
		}
		cout<<std::endl;
	}
	return 0;
}