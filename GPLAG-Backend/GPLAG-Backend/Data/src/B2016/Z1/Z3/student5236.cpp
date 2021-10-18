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

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<double> v2;
	std::vector<std::vector<double>> matrica;
	int brojac(0);
	for(int i=0;i<v.size();i++){
		brojac+=1;
		if(i==(v.size()-1) && (v[i]>=v[i-1] || v[i]<=v[i-1])){
			if(v[i]>v[i-1])break;
			v2.push_back(v[i]);
			matrica.push_back(v2);
			break;
		}
		if(v[i]>=v[i+1]){
			v2.push_back(v[i]);
		}
			else if( brojac>=2 && v[i]<=v[i+1] && v[i]<=v[i-1] ){
			v2.push_back(v[i]);
			matrica.push_back(v2);
			v2.clear();
		}
		else{
			continue;
		}
	}
	return matrica;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<double> v2;
	std::vector<std::vector<double>> matrica;
	int brojac(0);
	for(int i=0;i<v.size();i++){
		brojac+=1;
		if(i==(v.size()-1) && (v[i]>=v[i-1] || v[i]<=v[i-1])){
			if(v[i]<v[i-1])break;
         v2.push_back(v[i]);
         matrica.push_back(v2);
         break;
		}
		if(v[i]<=v[i+1]){
			v2.push_back(v[i]);
		}else if(v[i]>=v[i+1] && v[i]>=v[i-1] && brojac>=2){
			v2.push_back(v[i]);
			matrica.push_back(v2);
			v2.clear();
		}
		else {
			continue;
		}
	}
	return matrica;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	double broj;
	std::vector<double>v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>broj;
		v.push_back(broj);
	}
	std::vector<std::vector<double>> v1;
	v1=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	for(auto i: v1){
		for(auto j:i){
			std::cout<<std::setprecision(12)<<j<<" ";
		}
		std::cout<<std::endl;
	}
	std::vector<std::vector<double>> v2;
	v2=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	for(auto i: v2){
		for(auto j: i){
			std::cout<<std::setprecision(12)<<j<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}