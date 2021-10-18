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
typedef std::vector<std::vector<double>>matrica;
typedef std::vector<double>vektor;
using std::cout;
using std::cin;
using std::endl;

matrica RastuciPodnizovi(vektor v){
	matrica a;
	vektor v1(0);
	for(int i=0; i<v.size()-1; i++){ v1.resize(0);
		int brojac(0);
		while(i<v.size()-1 && v.at(i)<=v.at(i+1)){
			v1.push_back(v.at(i));
			i++;
			brojac++;
		}
		if(brojac>0){
		v1.push_back(v.at(i));
		a.push_back(v1);}
	}
	
	return a;
}

matrica OpadajuciPodnizovi(vektor v){
	matrica a;
	vektor v1;
	for(int i=0; i<=v.size()-1; i++){ v1.resize(0);
		int brojac(0);
		while(i<v.size()-1 && v.at(i)>=v.at(i+1)){
			v1.push_back(v.at(i));
			i++;
			brojac++;
		}
		if(brojac>0)
		{v1.push_back(v.at(i));
		a.push_back(v1);}
	}
	
	return a;
}

int main ()
{	
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vektor v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		double a1;
		cin>>a1;
		v.push_back(a1);
	}
	matrica a=RastuciPodnizovi(v);
	matrica b=OpadajuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: " << endl; 
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			cout << std::setprecision(12) << a[i][j] << " ";
		}
		cout << endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: " << endl;
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			cout <<std::setprecision(12) << b[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}