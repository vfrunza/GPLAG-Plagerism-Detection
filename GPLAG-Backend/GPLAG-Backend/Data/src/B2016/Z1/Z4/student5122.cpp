/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	for(int i=0; i<s.length(); i++){
		int temp=i;
		for(int j=0; j<v.size(); j++){
			for(int k=0; k<=v[j].size(); k++){
				int t=temp;
				while(s[temp]==v[j][k] && k<v[j].size()){
					temp++;
				}
				if(k==v[j].size()){
					for(int l=t; l<s.size(); l++){
						s[t]=s[temp];
						temp--;
					}
					
				}
			}
		}
		return s;
	}
return s;
}
int main ()
{
	std::string s;
	std::string f;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string>v;
	std::cout<<"Unesite fraze: ";
	do{
		std::getline(std::cin,f);
		if(f.length()!=0)
		v.push_back(f);
	} while(f.length()!=0);
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string s2;
	s2=ObrniFraze(s,v);
	std::cout<<s2;
	
	return 0;
}