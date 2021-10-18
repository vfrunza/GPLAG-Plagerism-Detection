/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector>

void IzvrniRijec (std::string &s1)
{
	int kt,pt;
	kt = 0;
	pt = s1.size()-1;
	char pom;
	while (kt>pt)
	{
		pom = s1[pt];
		s1[pt] = s1[kt];
		s1[kt] = pom;
		kt--;
		pt++;
	}
}
std::string ObrniFraze(std::string s,std::vector<string> v)
{
	for(int i = 0; i<s.size();i++){
		for(int j = 0; j<v.size(); j++){
			if (s[i] == v[j]) IzvrniRijec(s);
		}
	}
	return s;
}


int main ()
{
	return 0;
}