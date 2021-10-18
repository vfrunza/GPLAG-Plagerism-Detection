/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


vector<vector<double>> RastuciPodnizovi (vector<double> v){
	int brojac=0;
	if (!v.size() || v.size()==1) return {};
	if(v.size()>0){
		if(v.at(0)<=v.at(1)) brojac++;
	}
	for(int i=1; i<v.size()-1; i++){
		if(v.at(i)<v.at(i-1) && v.at(i)<=v.at(i+1)) brojac++;
	}
	vector<vector<double>>Matrica(brojac,vector<double>(0));
	int j(0);
	
	for(int i=0; i<Matrica.size(); i++){
		int k=j;
		if(v.at(k)<=v.at(k+1)) Matrica[i].push_back(v.at(k));
		k++;
		int pomocni_brojac(0);
		for(j=k; j<v.size(); j++){
			if(v.at(j)>=v.at(j-1)){
			 	Matrica[i].push_back(v.at(j));
			 	pomocni_brojac++;
			}
			else{
				if(pomocni_brojac==0) i--;
				break;
			}
		}
	}
	return Matrica;
}

vector<vector<double>> OpadajuciPodnizovi (vector<double> v){
	if(!v.size() || v.size()==1) return{};
	int brojac=0;
	if(v.size()>0){
		if(v.at(0)>=v.at(1) ) brojac++;
	}
	for(int i=1; i<v.size()-1; i++){
		if(v.at(i)>v.at(i-1) && v.at(i)>=v.at(i+1)) brojac++;
	}
	
	vector<vector<double>>Matrica(brojac,vector<double>(0));
	int j(0);
	
	for(int i=0; i<Matrica.size(); i++){
		int k=j;
		if(v.at(k)>=v.at(k+1) ) Matrica[i].push_back(v.at(k));
		k++;
		int pomocni_brojac(0);
		for(j=k; j<v.size(); j++){
			if(v.at(j)<=v.at(j-1)){
			 	Matrica[i].push_back(v.at(j));
			 	pomocni_brojac++;
			}
			else{
				if(pomocni_brojac==0) i--;
				break;
			}
		}
	}
	return Matrica;
}

int main ()
{
	int brel;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>brel;
	vector<double> v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<brel; i++){
		double element;
		cin>>element;
		v.push_back(element);
	}
	vector<vector<double>>Matrica1, Matrica2;
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	Matrica1=RastuciPodnizovi(v);
	for(int i=0; i<Matrica1.size(); i++){
		for(int j=0; j<Matrica1[i].size(); j++){
			cout<<Matrica1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	
	Matrica2=OpadajuciPodnizovi(v);
	for(int i=0; i<Matrica2.size(); i++){
		for(int j=0; j<Matrica2[i].size(); j++){
			cout<<Matrica2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}