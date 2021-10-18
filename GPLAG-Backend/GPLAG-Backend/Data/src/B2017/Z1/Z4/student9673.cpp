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

std::string NapraviPalindrom(std::string s,std::vector<std::string> v){
std::string rezultat;

	for(int i(0);i<v.size();i++){
		std::string podstring=v[i];
	  int j(0);
	  
	  while(podstring[j]==s[j]) 
	     j++;
for(int k=j;k>0;k--)
    s[k]==podstring[k];
		}
	rezultat=s;
	
return rezultat;
		
	}






int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin ,recenica);
	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";

    while(true){
    	std::string pomocni;
    	std::getline(std::cin,pomocni);
    	if(pomocni.length()==0) break;
    	else
    	fraze.push_back(pomocni);
    }

	
	

	std::string rezultat=NapraviPalindrom(recenica,fraze);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<rezultat<<std::endl;
	
	return 0;
}



