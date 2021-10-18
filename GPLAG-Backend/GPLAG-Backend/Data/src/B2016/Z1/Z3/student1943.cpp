/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>

std::vector<double> MaxPodniz(std::vector<double> v, int odakle, int dokle){
	std::vector<double> noviVektor;
	if(dokle-odakle<=1) {
		noviVektor.push_back(0);
	return noviVektor;
	}
	noviVektor.push_back(v[odakle]);
	for(int i=odakle+1; i<dokle; i++){
		if(v[i]>=v[i-1])
			noviVektor.push_back(v[i]);
		else
			return noviVektor;
	}
	return noviVektor;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> vektorVektora;
	std::vector<double> pom = MaxPodniz(v, 0, v.size());
	int brojac = 0;
	//std::cout<<brojac << " ";
	while(brojac != v.size()){
		if(pom.size()!=1){
			vektorVektora.push_back(pom);
			int brojac1 = pom.size();
			pom = MaxPodniz(v, pom.size()+brojac, v.size());
		//vektorVektora.push_back(pom);
			brojac += brojac1;
		//std::cout<<brojac << " ";
		}else{

			pom = MaxPodniz(v, pom.size()+brojac, v.size());
			brojac++;

		}
	}

	return vektorVektora;
}

std::vector<double> MinPodniz(std::vector<double> v, int odakle, int dokle){
	std::vector<double> noviVektor;
	if(dokle-odakle<=1) {
		noviVektor.push_back(0);
	return noviVektor;
	}
	noviVektor.push_back(v[odakle]);
	for(int i=odakle+1; i<dokle; i++){
		if(v[i]<=v[i-1])
			noviVektor.push_back(v[i]);
		else
			return noviVektor;
	}
	return noviVektor;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> vektorVektora;
	std::vector<double> pom = MinPodniz(v, 0, v.size());
	int brojac = 0;
	//std::cout<<brojac << " ";
	while(brojac != v.size()){
		if(pom.size()!=1){
			vektorVektora.push_back(pom);
			int brojac1 = pom.size();
			pom = MinPodniz(v, pom.size()+brojac, v.size());
		//vektorVektora.push_back(pom);
			brojac += brojac1;
		//std::cout<<brojac << " ";
		}else{

			pom = MinPodniz(v, pom.size()+brojac, v.size());
			brojac++;

		}
	}

	return vektorVektora;
}


int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double>v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++) {
		double broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	std::vector<std::vector<double>>r = RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<r.size();i++){
		for(int j=0; j<r[i].size(); j++)
			std::cout << r[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>>r1 = OpadajuciPodnizovi(v);
	for(int i=0; i<r1.size();i++){
		for(int j=0; j<r1[i].size(); j++)
			std::cout << r1[i][j] << " ";
		std::cout << std::endl;
	}

	return 0;
}