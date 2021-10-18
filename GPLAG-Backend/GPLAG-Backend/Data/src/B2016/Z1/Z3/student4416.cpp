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
#include <cmath>
typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi (Vektor a){
	const double epsilon(1e-10);
	Matrica b;
	int brojac(0);
	for(int i=0;i<a.size()-1;i++){
			if(a[i]<=a[i+1] || std::fabs(a[i+1]-a[i])<=epsilon){
				b.resize(b.size()+1);
				while(i<a.size()-1){
					if(a[i]<=a[i+1] || std::fabs(a[i+1]-a[i])<=epsilon){
					b[brojac].push_back(a[i]);
					i++;
					}
					else break;
				}
				b[brojac].push_back(a[i]);
				brojac++;
			}
	}
	return b;
}
Matrica OpadajuciPodnizovi(Vektor a){
	const double epsilon(1e-10);
	Matrica b;
	int brojac(0);
	for(int i=0;i<a.size()-1;i++){
		if(a[i]>=a[i+1] || fabs(a[i]-a[i+1])<=epsilon){
			b.resize(b.size()+1);
			while(i<a.size()-1){
				if(a[i]>=a[i+1] || fabs(a[i]-a[i+1])<=epsilon){
				b[brojac].push_back(a[i]);
				i++;
				}
				else break;
			}
			b[brojac].push_back(a[i]);
			brojac++;
		}
	}
	return b;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	if(n<=0){
		std::cout<<"Broj elemenata mora biti pozitivan!";
		return 0;
	}
	Vektor a(n);
	std::cout<<"Unesite elemente vektora: ";
	for (auto &x:a) std::cin>>x;
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	auto b=RastuciPodnizovi(a);
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[i].size();j++){
			std::cout<<std::setprecision(12)<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	b=OpadajuciPodnizovi(a);
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[i].size();j++){
			std::cout<<std::setprecision(12)<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}