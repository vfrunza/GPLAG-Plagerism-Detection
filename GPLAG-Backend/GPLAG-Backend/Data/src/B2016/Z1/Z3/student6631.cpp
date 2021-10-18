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

int BrojRedova(std::vector<std::vector<double>> m) {
 return m.size();
}

int BrojKolona(std::vector<std::vector<double>> m) {
 return m[0].size();
}

void IspisiMatricu(std::vector<std::vector<double>> m) {
 	for(auto red: m){
 		for(auto x: red) std::cout<<std::right<<x<<" ";
 		std::cout<<std::endl;
 	}
 }


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	int brojac(0), max(0);
	std::vector<std::vector<double>> matrica;
	
	
/*	for(int i(0);(i+1)<v.size();i++){
		if(v[i]<=v[i+1]){
			while((i+1)<v.size() && v[i]<=v[i+1]){
				brojac++;
				i++;
			} 
		if(brojac>max){
			max=brojac;
			brojac=0;
		}
		}
	}
	brojac=0;*/
	int pocetna, krajnja;
	
	for(int i(0);(i+1)<v.size();i++){
		if(v[i]<=v[i+1]){
			pocetna=i;
			while((i+1)<v.size() && v[i]<=v[i+1]){
				brojac++;
				i++;
			} 
			krajnja=i;
//		if(brojac==max){
			std::vector<double> rastuci;
			for(int j=pocetna; j<=krajnja; j++){
				rastuci.push_back(v[j]);
			}
			matrica.push_back(rastuci);
		
		}
			brojac=0;
//		}
		
	}
	return matrica;
}


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
		int brojac(0), max(0);
	std::vector<std::vector<double>> matrica;
	
/*	for(int i(0);(i+1)<v.size();i++){
		if(v[i]>=v[i+1]){
			while((i+1)<v.size() && v[i]>=v[i+1]){
				brojac++;
				i++;
			} 
		if(brojac>max){
			max=brojac;
			brojac=0;
		}
		}
	}
	brojac=0;*/
	int pocetna, krajnja;
	for(int i(0);(i+1)<v.size();i++){
		if(v[i]>=v[i+1]){
			pocetna=i;
			while((i+1)<v.size() && v[i]>=v[i+1]){
				brojac++;
				i++;
			} 
			krajnja=i;
//		if(brojac==max){
			std::vector<double> opadajuci;
			for(int j=pocetna; j<=krajnja; j++){
				opadajuci.push_back(v[j]);
			}
			matrica.push_back(opadajuci);
//	}
		}
		brojac=0;
	}
	return matrica;
}

int main (){
	
/*	std::vector<double> brojevi {0.1, 0.1, 0.9, 0.9, -0.1, 0.1, -0.9, 0.9, -0.1, 0.1, 0.9, 0.9, 0.1, -0.1, 0.9, -0.9};
    std::vector<std::vector<double>> rastuci {RastuciPodnizovi(brojevi)}, opadajuci {OpadajuciPodnizovi(brojevi)};

    for (auto niz : rastuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    }

	std::cout << "_" << std::endl;
    for (auto niz : opadajuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    }*/
	


	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	double element;
	std::vector<double> v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++){
		std::cin>>element;
		v.push_back(element);
	}
	std::vector<std::vector<double>> opadajuci, rastuci;
	
	rastuci=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	IspisiMatricu(rastuci);
	opadajuci=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	IspisiMatricu(opadajuci);

	return 0;
}