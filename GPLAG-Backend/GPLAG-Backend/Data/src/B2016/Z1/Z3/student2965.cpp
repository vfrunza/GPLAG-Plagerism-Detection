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
typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(vektor a) {
	Matrica A;
	vektor rastuci;
	for(int i=0;i<a.size();i++) {
		if(i!=a.size()-1 && a.at(i)<=a.at(i+1)) {
			rastuci.push_back(a.at(i));
			continue;
		}
		else if(i!=a.size()-1 && a.at(i)>=a.at(i+1)) {
			if(rastuci.size()!=0) rastuci.push_back(a.at(i));
		}
		if(i==a.size()-1 && a.at(i-1)<=a.at(i)) rastuci.push_back(a.at(i));
		A.push_back(rastuci);
		rastuci.clear();
	}
	return A;
}
Matrica OpadajuciPodnizovi(vektor a) {
	Matrica B;
	vektor opadajuci;
	for(int i=0;i<a.size();i++) {
		if(i!=a.size()-1 && a.at(i)>=a.at(i+1)) {
			opadajuci.push_back(a.at(i));
			continue;
		}
		else if(i!=a.size()-1 && a.at(i)<=a.at(i+1)) {
			if(opadajuci.size()!=0) opadajuci.push_back(a.at(i));
		}
		if(i==a.size()-1 && a.at(i-1)>=a.at(i)) opadajuci.push_back(a.at(i));
		B.push_back(opadajuci);
		opadajuci.clear();
	}
	return B;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	double broj;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	vektor a;
	for(int i=0;i<n;i++) {
		std::cin>>broj;
		a.push_back(broj);
	}
	Matrica A(RastuciPodnizovi(a));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<A.size();i++) {
		for(int j=0;j<A.at(i).size();j++) {
			std::cout<<std::setprecision(12)<<A.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	Matrica B(OpadajuciPodnizovi(a));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<B.size();i++) {
		for(int j=0;j<B.at(i).size();j++) {
			std::cout<<std::setprecision(12)<<B.at(i).at(j)<<" ";
		}	
	}
	return 0;
}