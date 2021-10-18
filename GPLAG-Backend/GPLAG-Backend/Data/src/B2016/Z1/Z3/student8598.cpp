/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	int i,k=0,a=5;
	std::vector<std::vector<double>> Rastuci(1);
	for(i=0;i<v.size();i++){
		if(i==v.size()-1) goto L1;
		if(v[i]<=v[i+1]){
			Rastuci[k].push_back(v[i]);
			a=1;
			continue;
		}
		L1:
		if(a==1){
			Rastuci[k].push_back(v[i]);
			k++;
			Rastuci.resize(k+1);
		}
		a=5;
	}
	return Rastuci;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	int i,k=0,a=5;
	std::vector<std::vector<double>> Rastuci(1);
	for(i=0;i<v.size();i++){
		if(i==v.size()-1) goto L1;
		if(v[i]>=v[i+1]){
			Rastuci[k].push_back(v[i]);
			a=1;
			continue;
		}
		L1:
		if(a==1){
			Rastuci[k].push_back(v[i]);
			k++;
			Rastuci.resize(k+1);
		}
		a=5;
	}
	return Rastuci;
}
int main ()
{
	int i,n,m;
	std::vector<double> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(i=0;i<n;i++){
		std::cin>>m;
		v.push_back(m);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double> > Rastuci(RastuciPodnizovi(v));
	for(int x=0;x<Rastuci.size();x++){
		for(int y=0; y<Rastuci[x].size();y++){
			std::cout<<Rastuci[x][y]<<" ";
		}
		if(x!=Rastuci.size()-1) std::cout<<std::endl;
	}
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double> > Opadajuci(OpadajuciPodnizovi(v));
	for(auto x: Opadajuci){
		for(double y: x){
			std::cout<<y<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}