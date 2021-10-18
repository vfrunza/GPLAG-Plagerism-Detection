/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>&v) {
	std::vector<std::vector<double>>rastuci;
	std::vector<double>pomocni;
	int brojacJ(0);
	for(int i=0; i<v.size(); i++) {
		if(i==0) pomocni.push_back(v[i]);
		else{
		if(v[i]>=v[i-1]) pomocni.push_back(v[i]);
		else { 
			if(pomocni.size()>1) { 
				rastuci.resize(brojacJ+1);
				for(int k(0);k<pomocni.size();k++)
					rastuci[brojacJ].push_back(pomocni[k]);
				brojacJ++;
			}
			pomocni.resize(0); 
			pomocni.push_back(v[i]);
		}
	}
	}
	
		if(pomocni.size()>1) { 
				rastuci.resize(brojacJ+1);
				for(int k(0);k<pomocni.size();k++)
					rastuci[brojacJ].push_back(pomocni[k]);
			}
	
	return rastuci;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>&v) {
		std::vector<std::vector<double>>opadajuci;
	std::vector<double>pomocni;
	int brojacJ(0);
	for(int i=0; i<v.size(); i++) {
		if(i==0) pomocni.push_back(v[i]);
		else{
		if(v[i]<=v[i-1]) pomocni.push_back(v[i]);
		else { 
			if(pomocni.size()>1) { 
				opadajuci.resize(brojacJ+1);
				for(int k(0);k<pomocni.size();k++)
					opadajuci[brojacJ].push_back(pomocni[k]);
				brojacJ++;
			}
			pomocni.resize(0); 
			pomocni.push_back(v[i]);
		}
	}
	}
	
		if(pomocni.size()>1) { 
				opadajuci.resize(brojacJ+1);
				for(int k(0);k<pomocni.size();k++)
					opadajuci[brojacJ].push_back(pomocni[k]);
			}
	
	return opadajuci;
}

int main ()
{	

std::cout<<"Unesite broj elemenata vektora: "; 
int n;
std::cin>> n;
std::vector<double> v(n);
std::cout<<"Unesite elemente vektora: ";
for(int i(0);i<n;i++)
std::cin>>v[i];
std::vector<std::vector<double>> rastuci(RastuciPodnizovi(v)); 
std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
for(int i(0);i<rastuci.size();i++){
for(int j(0);j<rastuci[i].size();j++)
std::cout<<rastuci[i][j]<<" ";
std::cout<<std::endl;
}
std::vector<std::vector<double>> opadajuci(OpadajuciPodnizovi(v));

std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
for(int i(0);i<opadajuci.size();i++){
for(int j(0);j<opadajuci[i].size();j++)
std::cout<<opadajuci[i][j]<<" ";
std::cout<<std::endl;
}
return 0;
}