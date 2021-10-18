/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> a){
	std::vector<double> pomocni[100];
	
	int brojac=0;
	int r(0);
	for(int i=0; i<=a.size(); i++){
		while(i<=a.size()-2 && a[i]<=a[i+1] ){
			pomocni[r].push_back(a[i]);
			i++;
		}
		if(i==a.size()-1&&a[i]>a[i+1]){
			pomocni[r].push_back(a[i]);
		}
		r++;
	}
	matrica m(r);
	int k=0;
	for(int i=0; i<r; i++){
		if(pomocni[i].size()>1){
			m[k]=pomocni[i];
			k++;
		}
	}
	return m;
}

matrica OpadajuciPodnizovi(std::vector<double> a){
	
	std::vector<double> pomocni[100];
	int brojac=0;
	int r(0);
	for(int i=0; i<=a.size(); i++){
		while( i<=a.size()-2&&a[i]>=a[i+1] ){
			pomocni[r].push_back(a[i]);
			i++;
		}
		if(i==a.size()-1&&a[i]<a[i+1]){
			pomocni[r].push_back(a[i]);
		}
		r++;
	}
	matrica m(r);
	int k=0;
	for(int i=0; i<r; i++){
		if(pomocni[i].size()>1){
			m[k]=pomocni[i];
			k++;
		}
	}
	return m;
}
int main ()
{
	int n;
	std::vector<double> a;
	
	std::cout<<"Unesite niz brojeva (0 za kraj): ";
	for(;;){
		std::cin>>n;
		if(n==0) break;
		
		a.push_back(n);
	}
	
	matrica k(RastuciPodnizovi(a));
	std::cout<<"Rastuci: "<<std::endl;
	
	for(int i=0; i<k.size(); i++){
		for(int j=0; j<k[i].size(); j++){
			std::cout<<k[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
		matrica o(OpadajuciPodnizovi(a));
	std::cout<<"Opadajuci: "<<std::endl;
	
	for(int i=0; i<o.size(); i++){
		for(int j=0; j<o[i].size(); j++){
			std::cout<<o[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}