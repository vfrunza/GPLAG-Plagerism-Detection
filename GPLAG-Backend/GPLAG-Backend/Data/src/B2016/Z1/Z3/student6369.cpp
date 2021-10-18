/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

typedef std::vector<std::vector<double>> vv;

vv RastuciPodnizovi(std::vector<double> v)
{
	vv niz;
	int br = 0,temp=0;
	for(int i(0); i < v.size()-1; i++)
	{//1 2 3 4 3 2 1 2 3 4
	temp=0;
		if(v[i] < v[i+1])
			for(int j(i); j<(v.size()-1); j++){
			//	if(j+1==v.size())break;	
			if(j+1<v.size()) {
				if(v[j] < v[j+1])temp++;
				else break;
					
				
			}
			}
			std::vector<double> x;
					niz.push_back(x);
					for(int k(i); k < i+temp+1; k++) niz[br].push_back(v[k]);
					i +=temp;
					br++;
			
	}
	if(br == 0) niz.resize(br);
	return niz;
}

vv OpadajuciPodnizovi(std::vector<double> v){
	vv niz;
	int br = 0;
	for(int i(0); i < v.size()-1; i++){
		if(v[i] > v[i+1])
		for(int j(i) ; j < v.size()-1 ; j++){
			if(j+1<v.size()){
			if(v[j] > v[j+1]) continue;
				
			
			else
			{
				std::vector<double> x;
				niz.push_back(x);
				for(int k(i); k < j+1; k++) niz[br].push_back(v[k]);
				i = j+1; 
				br++;
				break;
			}
			}
		}
	}
	if(br == 0 ) niz.resize(br);
	return niz;
	
}

int main ()
{
	int broj_elemenata;
	std::vector<double>v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	double broj;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i < broj_elemenata; i++)
	{
		std::cin>>broj;
		v.push_back(broj);
	}
	vv opadajuci = OpadajuciPodnizovi(v);
	vv rastuci = RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	for(auto x : rastuci){
		for(auto temp : x){
			std::cout<<temp<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	for(auto x : opadajuci)
	{
		for(auto temp : x)
		{
			std::cout<<temp<<" ";
		}
		
	}
	return 0;
}