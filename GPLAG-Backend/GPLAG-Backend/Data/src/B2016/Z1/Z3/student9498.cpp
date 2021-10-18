/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> niz){
	std::vector<double> pomocni ;
	std::vector<std::vector<double>>  rezultat;
	for(int t(0);t<niz.size()-1;t++){
		for(int k(t+1);k<niz.size();k++){
			while(k<niz.size() && niz[t]<=niz[k]){
				pomocni.push_back(niz[t]);
				k++;
				t++;
			}
			if(pomocni.size()!=0){
				pomocni.push_back(niz[t]);
				rezultat.push_back(pomocni);
			}
			break;
		}
		pomocni.resize(0);
	}
	return rezultat;
}
std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> niz){
	std::vector<double> pomocni;
	std::vector<std::vector<double>> rezultat;
	for(int t(0);t<niz.size()-1;t++){
		for(int k(t+1);k<niz.size();k++){
			while(k<niz.size() && niz[t]>=niz[k]){
				pomocni.push_back(niz[t]);
				t++;
				k++;
			}
			if(pomocni.size()!=0){
				pomocni.push_back((niz[t]));
				rezultat.push_back(pomocni);
			}
			break;
		}
		pomocni.resize(0);
	}
	return rezultat;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int broj;
	std::cin>>broj;
	std::vector<double> vektor(broj);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<vektor.size();i++)
		std::cin>>vektor[i];
	
	std::vector<std::vector<double>> rezultat1;
	std::vector<std::vector<double>> rezultat2;
	rezultat1=RastuciPodnizovi(vektor);
	rezultat2=OpadajuciPodnizovi(vektor);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i(0);i<rezultat1.size();i++){
		for(int j(0);j<rezultat1[i].size();j++){
			std::cout<<std::setprecision(12)<<rezultat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i(0);i<rezultat2.size();i++){
		for(int j(0);j<rezultat2[i].size();j++){
			std::cout<<std::setprecision(12)<<rezultat2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}













