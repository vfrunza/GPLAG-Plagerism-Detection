/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> v){
	//for(auto x:v)
	//	std::cout<<x<<" ";
	matrica glavna;
	if(v.size()==0) return glavna;
	int k=0;
	for (int i=0;i<v.size()-1;i++){
		glavna.resize(k+1);
		if (v.at(i)<=v.at(i+1)){
			glavna.at(k).push_back(v.at(i));
		}
		if(i>0 and v.at(i)>=v.at(i+1) and v.at(i-1)<=v.at(i)){ 
			glavna[k].push_back(v.at(i));
			k++;
		}
		if(i==(v.size()-2) and v.at(i+1)>v.at(i))
			glavna[k].push_back(v.at(i+1));
	}
	return glavna;
}
matrica OpadajuciPodnizovi(std::vector<double> v){
	matrica glavna;
	if(v.size()==0) return glavna;
	int k=0;
	for(int i=0;i<v.size()-1;i++){
		glavna.resize(k+1);
		if(v.at(i)>=v.at(i+1)) 
			glavna.at(k).push_back(v.at(i));
		if(i>0 and v.at(i)<=v.at(i+1) and v.at(i-1)>=v.at(i)){
			glavna.at(k).push_back(v.at(i));
			k++;
		}
		if(i==(v.size()-2) and v.at(i+1)<v.at(i))
		glavna.at(k).push_back(v.at(i+1));
	}
	return glavna;
}

int main ()
{	std::vector<double> a;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		double b;
		std::cin>>b;
		a.push_back(b);
	}
	matrica moja(RastuciPodnizovi(a));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(auto red:moja){
		for(auto x:red)
		std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	matrica tvoja(OpadajuciPodnizovi(a));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(auto red:tvoja){
		for(auto x:red)
			std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
}