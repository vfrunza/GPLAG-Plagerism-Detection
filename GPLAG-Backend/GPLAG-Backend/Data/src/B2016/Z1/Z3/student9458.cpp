/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
typedef std::vector<std::vector<double>> Matrica;

Matrica OpadajuciPodnizovi(std::vector<double>a){
	std::vector<double>b ;
	Matrica c;
	for(int i=0; i<a.size(); i++){
		b.clear();
		int j;
		for(j=i; j<a.size(); j++){
			if(j==a.size()-1)break;
			if(a[j]>=a[j+1])b.push_back(a[j]);
			else break;
		}
		if(j==0)continue;
		if(a[j]<=a[j-1])b.push_back(a[j]);
		if(b.size()>1){c.push_back(b);i=j;}
	}
	return c;
}
Matrica RastuciPodnizovi(std::vector<double>a){
	std::vector<double>b ;
	Matrica c;
	for(int i=0; i<a.size(); i++){
		b.clear();
		int j;
		for(j=i; j<a.size(); j++){
			if(j==a.size()-1)break;
			if(a[j]<=a[j+1])b.push_back(a[j]);
			else break;
		}
		if(j==0)continue;
		if(a[j]>=a[j-1])b.push_back(a[j]);
		if(b.size()>1){c.push_back(b);i=j;}
	}
	return c;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int b;
	std::cin>>b;
	std::vector<double>a(b);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<b; i++){
		std::cin>>a[i];
	}
	Matrica n;
	n=RastuciPodnizovi(a);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<n.size(); i++){
		for(int j=0; j<n[i].size(); j++){
			std::cout<<n[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica m;
	m=OpadajuciPodnizovi(a);
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}