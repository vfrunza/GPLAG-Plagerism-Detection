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

std::string ObrniFraze (std::string s, std::vector<std::string> v){
	std::string pomocni,pamti, pamti1;
	for(int i=0; i<s.lenght(); i++){
		while((s[i]>='a'&& s[i]<='z'|| s[i]>='A' && s<='Z') && i<s.lenght()){
			pomocni.push_back(s[i]);
			i++;
		}
		for(int j=0; j<v.size(); j++){
			if(v[j]==pomocni){
				int brojac=pomocni.lenght();
				while(brojac!=0){
					pamti.push_back(s[pomocni.lenght()-i]);
					pamti1.push_back(s[i-1]);
					s.erase(i-1,1);
					s.insert(i-1,pamti);	
					s.erase(0,1);
					s.insert(0,pamti1);
					brojac--;
				}
				i=pomocni.size()-1;
				pomocni.resize(0);
			}
		}
	}
	return 
}