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
#include <vector>
#include <string>
std::string NapraviPalindrom (std::string s,std::vector<std::string> v){
	std::string pom;
	for(int i=0;i<s.length();i++){
		
		for(int j=0;j<v.size();j++)
			int k=i;
			while(s.at(i)!=' '&&s.at(i)!='\n'&& s.at(i)!='\t') i++;
			if(v.at(j)==s.substr(k,i-k-1)){
				pom=s.substr(k,i-k-1);
				for(int l=0;l<v[j].length()/2;l++){
				char temp;
				int duz=v[i].length()/2;
				temp=v[i][l];
				v[i][l]=v[i][duz -1-l];
				v[i][duz-1-l]=temp;
				}
				//kako da resize string i ubacim ono sto mi treba
				pom=pom+v.at(i);
				
				
			}
			j--;
		}
		
	}
	
}


int main ()
{
	
	return 0;
}