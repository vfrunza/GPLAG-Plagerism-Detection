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
#include <string>
#include <vector>

std::vector<std::string> NapraviPalindrom(std::<string> s, std::vector<std::string> v){
	std::vector<std::string> nekivektor;
	for(int i=0, i<v.size(); i++){
		string x;
		x=v[i];
		for(int j=0; j<x.lenght(); j++){
			int y;
			y=j;
			int brojac;
			int z;
			for (int w=0; w<s.lenght(); w++){
				if(s[w]==x[y]){
					brojac++;
					y=y+1;
					z=w;
				}
				else break;
				if (brojac==n.lenght()){
					string a;
					for(int b==a.lenght(); b>0; b--){
						a.push_back(b);
					}
					s=s.substr(z)
				}
			}
		}
	}
	return s;
}

int main ()
{
	return 0;
}