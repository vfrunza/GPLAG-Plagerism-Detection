/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include<vector>
#include<string>


int main ()
{
	std::string str;
	std::vector<std::string> v;
	
	std::cout<<"Unesi recenicu: ";
	std::getline(std::cin, str);
	int n;
	std::cout<<"Unesi broj fraza: ";
	std::cin>>n;
	v.resize(n);
	std::cout<<"Unesi vektor fraza: ";
	for(int i=0;i<n;i++){
		std::cin>>std::ws;
		std::cin>>v.at(i);
	}
	
	for(int i=0;i<v.size();i++){
		for(int j=0;j<str.length();j++){
			if(str.substr(j,v.at(i).length())==v.at(i)){
				str.substr(j,v.at(i).length())+=v.at(i);
			}
		}
	}
	
	std::cout<<"recenica sada glasi: ";
	std::cout<<str;
	
	return 0;
}