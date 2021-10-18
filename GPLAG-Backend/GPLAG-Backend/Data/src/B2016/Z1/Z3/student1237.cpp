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


/*void IpisiMatricu(std::vector<std::vector<double>> m){
	for(int i=0;i<1;i++){
		for(int j=0;j<m.size();j++){
			m.resize(10);
			std::cout<<m[i][j];
			std::cout<<std::endl;
		}
	}
}
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<double> pomocni;
	std::vector<std::vector<double>> rastuci;
	double x=v[0];
	for (int i=0;i<v.size()-1;i++){
		
		if(x==(x+1)) { 
		for(int j=0;j<1;j++){
			for(int k=0;k<v.size();k++){
				rastuci[j].push_back(x);
			}
		}
			
		}
	}

	return rastuci;
}*/
std::vector<double> Rastuci(std::vector<double> v){
	std::vector<double> pomocni;

	for(int i=0;i<v.size();i++){
		while(v[i]==(v[i])+1) pomocni.push_back(v[i]);
	}
	return pomocni;
}
int main ()
{
std::vector<double>  rastuci;
	double n,broj;
	std::vector<double> v;
	std::cout<<"Unesite koliko brojeva cete unijeti: ";
	std::cin>>n;
	std::cout<<"Unesite brojeve : ";
	while(n>0){
		std::cin>>broj;
		v.push_back(broj);
		n--;
	}
rastuci=Rastuci(v);
for(int i=0;i<rastuci.size();i++)
std::cout<<rastuci[i]<<" ";

	return 0;
}