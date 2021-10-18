/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>

typedef std::vector<double> DoubleVektor;
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(DoubleVektor v){
	
	Matrica mat;
	if(v.size()==0 || v.size()==1){
		return mat;
	}
	
	DoubleVektor podniz;
	
	 for(int i=0;i<v.size();i++){
	 	podniz.push_back(v[i]);
	 	while(i+1<v.size() && v[i+1]>=podniz[podniz.size()-1]){
	 		podniz.push_back(v[i+1]);
	 		i++;
	 	}
	 	if(podniz.size()>=2){
	 		mat.push_back(podniz);
	 	}
	 	podniz.resize(0);
	 	
	 }
	return mat;
}

Matrica OpadajuciPodnizovi(DoubleVektor v){
	
	Matrica mat;
	if(v.size()==0 || v.size()==1){
		return mat;
	}
	
	DoubleVektor podniz;
	
	for(int i=0;i<v.size();i++){
		podniz.push_back(v[i]);
		while(i+1<v.size() && v[i+1] <= podniz[podniz.size()-1]){
			podniz.push_back(v[i+1]);
			i++;
		}
		if(podniz.size()>=2){
			mat.push_back(podniz);
		}
		podniz.resize(0);
	}
	
	return mat;
}

int main ()
{
	DoubleVektor vektor;
	int n;
	double x;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	if(n<0){
		std::cout<<"Broj elemenata mora biti veci od 0!";
		return 0;
	}
	std::cout<<"Unesite elemente vektora: ";
	
	for(int i=0;i<n;i++){
		std::cin>>x;
		vektor.push_back(x);
	}
	
	Matrica opadajuci(OpadajuciPodnizovi(vektor)), rastuci(RastuciPodnizovi(vektor));
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<rastuci.size();i++){
		for(int j=0; j<rastuci[i].size();j++){
			std::cout<<rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<opadajuci.size();i++){
		for(int j=0; j<opadajuci[i].size();j++){
			std::cout<<opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}