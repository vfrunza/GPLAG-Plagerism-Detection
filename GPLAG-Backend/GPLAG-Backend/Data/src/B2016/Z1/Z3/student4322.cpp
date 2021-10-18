/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector> 
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;

std::vector<std::vector<double>>
RastuciPodnizovi(std::vector<double>v)
{
	std::vector<std::vector<double>>Matrica1;
	Matrica1.resize(1);
	int j=0;
	for(int i=0;i<v.size()-1;i++){
		if(v[i]<=v[i+1]){
		while((i+1)!=v.size() && (v[i]<=v[i+1])){
			Matrica1[j].push_back(v[i]);
			i++;
		}
		if((i+1==v.size()) || v[i-1]<=v[i])Matrica1[j].push_back(v[i]);
		Matrica1.resize(Matrica1.size()+1);
		j++;
	}
	}
	return Matrica1;	
	}
	


std::vector<std::vector<double>>
OpadajuciPodnizovi(std::vector<double>v)
{
	std::vector<std::vector<double>>Matrica1;
	Matrica1.resize(1);
	int j=0;
	for(int i=0;i<v.size()-1;i++){
		if(v[i]>=v[i+1]){
		while((i+1)!=v.size() && (v[i]>=v[i+1])) {
			Matrica1[j].push_back(v[i]);
			i++;
			
		}
		if((i+1==v.size()) || v[i-1]>=v[i])Matrica1[j].push_back(v[i]);
		Matrica1.resize(Matrica1.size()+1);
		j++;
	}
	}
	return Matrica1;
}

int main ()
{  
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	double a;
	std::vector<double>v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	std::vector<std::vector<double>>rasmat;
	std::vector<std::vector<double>>opadmat;
	rasmat=RastuciPodnizovi(v);
	opadmat=OpadajuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0;i<rasmat.size();i++){
		for(int j=0;j<rasmat[i].size();j++){
			cout<<std::setprecision(12)<<rasmat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0;i<opadmat.size();i++){
		for(int j=0;j<opadmat[i].size();j++){
			cout<<std::setprecision(12)<<opadmat[i][j]<<" ";
		}
		cout<<endl;
		
	}

	return 0;
}