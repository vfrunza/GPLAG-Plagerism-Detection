/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> a){
	std::vector<std::vector<double>> b;
	//std::cout << "a.size=" << a.size() << " a.size()-1= " << a.size()-1 << " .. int(a.size())-1= "<< int(a.size())-1 << "\n";
	for(int i=0; i<int(a.size())-1; i++){//mora int(a.size() jer a.size vraca po tipe unsigned int koji ne moze biti negativan pa kad je 0-1 dobije se neki ogroman broj tj maximum unsigned inta
		std::vector<double> c;
		while(a[i]<=a[i+1]){
			if(c.size()==0)c.push_back(a[i]);
			c.push_back(a[i+1]);
			i++;
			if(i==a.size()-1)break;
		}
		if(c.size()!=0)b.push_back(c);
	}
	return b;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> a){
	std::vector<std::vector<double>> b;
	for(int i=0; i<int(a.size()-1); i++){
		std::vector<double> c;
		while(a[i]>=a[i+1]){
			if(c.size()==0)c.push_back(a[i]);
			c.push_back(a[i+1]);
			i++;
			if(i==a.size()-1)break;
		}
		if(c.size()!=0)b.push_back(c);
	}
	return b;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> a(n);
	for(int i=0; i<n; i++){
		std::cin >> a[i];
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> b(RastuciPodnizovi(a));
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			std::cout << b[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	b=OpadajuciPodnizovi(a);
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			std::cout << b[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}