/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
//Treba eps napraviti u slucaju pada nekog at



std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> vrati;
	std::vector<double> p;
	for(int i=0; i<(int)v.size(); i++)
		for(int j=i+1; j<(int)v.size(); j++){
			if(v[i]<=v[j] && j==i+1){
				p.push_back(v[i]);
				p.push_back(v[j]);
				if(j+1==(int)v.size()){
					i=j-1;
					vrati.push_back(p);
					p.resize(0);
					break;
				}
			}
			else if(v[i]>v[j] && j==i+1)
				break;
			else if(v[j-1]<=v[j]){
				p.push_back(v[j]);
				if(j+1==(int)v.size()){
					i=j-1;
					vrati.push_back(p);
					p.resize(0);
					break;
				}
			}
			else{
				i=j-1;
				vrati.push_back(p);
				p.resize(0);
				break;
			}
		}

	return vrati;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> vrati;
	std::vector<double> p;
	for(int i=0; i<(int)v.size(); i++)
		for(int j=i+1; j<(int)v.size(); j++){
			if(v[i]>=v[j] && j==i+1){
				p.push_back(v[i]);
				p.push_back(v[j]);
				if(j+1==(int)v.size()){
					i=j-1;
					vrati.push_back(p);
					p.resize(0);
					break;
				}
			}
			else if(v[i]<v[j] && j==i+1)
				break;
			else if(v[j-1]>=v[j]){
				p.push_back(v[j]);
				if(j+1==(int)v.size()){
					i=j-1;
					vrati.push_back(p);
					p.resize(0);
					break;
				}
			}
			else{
				i=j-1;
				vrati.push_back(p);
				p.resize(0);
				break;
			}
		}

	
	
	return vrati;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> p;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		double m;
		std::cin>>m;
		p.push_back(m);
	}
	std::vector<std::vector<double>> vrati=RastuciPodnizovi(p);
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i=0; i<vrati.size(); i++){
		for(int j=0; j<vrati[i].size(); j++)
			std::cout<<vrati[i][j]<<" ";
		std::cout<<"\n";
	}
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	vrati=OpadajuciPodnizovi(p);
	for(int i=0; i<vrati.size(); i++){
		for(int j=0; j<vrati[i].size(); j++)
			std::cout<<vrati[i][j]<<" ";
		std::cout<<"\n";
	}
	return 0;
}