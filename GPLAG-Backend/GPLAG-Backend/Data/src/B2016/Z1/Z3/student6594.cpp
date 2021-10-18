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

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> Niz){
	std::vector<std::vector<double>> Rastuci;
	int l =0;
	Rastuci.push_back(std::vector<double> ());
	for(int i=0, j=i+1, k=j+1; i<Niz.size() && j<Niz.size() && k<Niz.size(); i++, j++, k++){
	if(k==Niz.size()-1 && Niz[j]<=Niz[k]) {
{
	Rastuci[l].push_back(Niz[j]);
	Rastuci[l].push_back(Niz[k]);
		break;
			}
		}
	
	
		if(Niz[i]<=Niz[j]){
			
			
			
			if(i==0 && Niz[i]<=Niz[j])
			Rastuci[l].push_back(Niz[0]);
			Rastuci[l].push_back(Niz[j]);
			
		}
		else if(Niz[i] >= Niz[j] && Niz[j] <= Niz[k] && k!=Niz.size()) {
			if(Rastuci[l].size()!=0){
				l++;
				Rastuci.push_back(std::vector<double> ());
			}
			Rastuci[l].push_back(Niz[j]);
			}
		 
		else {
			if(Rastuci[l].size()!=0){
			l++;
			Rastuci.push_back(std::vector<double> ());
		}
		}
		}
	return Rastuci;
}



std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> Niz){
	std::vector<std::vector<double>> Opadajuci;
	int m =0;
	Opadajuci.push_back(std::vector<double> ());
	for(int i=0, j=i+1, k=j+1; i<Niz.size() && j<Niz.size() && k<Niz.size(); i++, j++, k++){
	if(k==Niz.size()-1 && Niz[j]>=Niz[k]) {
			{
				Opadajuci[m].push_back(Niz[j]);
				
				Opadajuci[m].push_back(Niz[k]);
				break;
			}
		}
	
		if(Niz[i]>=Niz[j]){
			if(i==0 && Niz[i]>=Niz[j])
			Opadajuci[m].push_back(Niz[i]);
			Opadajuci[m].push_back(Niz[j]);
			
		}
		else if(Niz[i] <= Niz[j] && Niz[j] >= Niz[k] && k!=Niz.size()) {
			if(Opadajuci[m].size()!=0){
				m++;
				Opadajuci.push_back(std::vector<double> ());
			}
			Opadajuci[m].push_back(Niz[j]);
			}

	
		else {
			if(Opadajuci[m].size()!=0){
			m++;
			Opadajuci.push_back(std::vector<double> ());
		}
		}
			
		
		
	}
	return Opadajuci;
}
int main ()
{
	int n;
	double broj;
	std::vector<double> Niz;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>broj;
		Niz.push_back(broj);
	}
	
		std::cout<<"Maksimalni rastuci podnizovi: ";
				std::cout<<std::endl;
	for(auto m : RastuciPodnizovi(Niz)) {
		for(auto n : m) 
			std::cout << std::setprecision(12)<< n << " ";
			std::cout<<std::endl;}
	
std::cout<<"Maksimalni opadajuci podnizovi: ";
std::cout<<std::endl;
	for(auto x : OpadajuciPodnizovi(Niz)){
		for(auto y : x) 
			std::cout <<std::setprecision(12)<< y << " ";
		
std::cout<<std::endl;}
	

	

	
	return 0;
}