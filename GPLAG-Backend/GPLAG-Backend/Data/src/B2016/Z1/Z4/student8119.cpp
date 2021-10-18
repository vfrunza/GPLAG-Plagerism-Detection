/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>

std::string ObrniFaze(std::string s, std::vector<std::string> v) {
	std::string pomocni;
	std::string s2;
	
		for(int i=0; i<s.length(); i++) {
		if(s[i]!=' ') s2.push_back(s[i]);
		else break;
			
		}
	pomocni=v[0];
	if(s2==pomocni) {
		int i=0;
		int j=s2.length()-1;
		while(i<=s2.length()) {
			s[i]=s2[j];
			i++;
			j--; }
		
	
	
	}
		
	return s2;
}

int main ()
{
	std::string string,s;
	std::vector<std::string> v;
	std:: cout<<"Unesi string ";
	std::getline(std::cin,s);
	std::cout<<"Unesi fraze ";
	for(int i=0; i>-1; i++) {
		std::getline(std::cin,string);
		v.push_back(string);
		if(v[i].size()==0) break;
	}
	std::string s2;
	s2=ObrniFaze(s,v);
	std::cout<<s2;
	return 0;
}