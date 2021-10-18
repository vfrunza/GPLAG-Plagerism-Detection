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
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v) {
	
	for(int i(0); i<v.size(); i++) {
		std::string pomocni=v[i];
		for(int j(0); j<s.length(); j++) {
			int k(0),index(0);
			if(pomocni[k]==s[j]) index=j;
			while(pomocni[k]==s[j] && j<s.length()) {
				k++;
				j++;
			}
			if(k==pomocni.length()) {
				int duzina=index+k-1;
				while(index<duzina) {
					char temp=s[index];
					s[index]=s[duzina];
					s[duzina]=temp;
					duzina--;
					index++;
				}
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v) {
		
		for(int i(0); i<v.size(); i++) {
			std::string n=v[i];
			for(int j(0); j<n.length(); j++) {
				if(!((n[j]>='A' && n[j]<='Z') || (n[j]>='a' && n[j]<='z'))) throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
		
		if(v.empty()) {
			for(int i(0); i<s.length(); i++) {
				while(s[i]==' ') i++;
				int prvi=i;
				while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) i++;
				int zadnji=i;
				s.insert(s.begin() + zadnji, s[prvi]);
				s.erase(s.begin() + prvi);
				s.insert(s.begin() + zadnji,'a');
				s.insert(s.begin() + zadnji + 1,'y');
				i+=2;
			}
		}
		
		for(int i(0); i<v.size(); i++) {
			std::string pomocni = v[i];
			for(int j(0); j<s.length(); j++) {
				int k(0),index(0);
				if(pomocni[k]==s[j]) index=j;
				while (pomocni[k]==s[j] && j<s.length()) {
					k++;
					j++;
				}
				if(k==pomocni.length()) {
					if((s[index]==s[0] || s[index-1]==' ') && (s[index+k]==' ' || s[index+k-1]==s[s.length()-1])) {
					s.insert(s.begin()+index+pomocni.length(),s[index]);
					s.erase(s.begin()+index);
					s.insert(s.begin()+index+pomocni.length(),'a');
					s.insert(s.begin()+index+pomocni.length()+1,'y');
					}
				}
			}
		}
		return s;
}

int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	while (1) {
		std::string pomocni;
		std::getline(std::cin, pomocni);
		if(pomocni.empty()) break;
		v.push_back(pomocni);
	}
	try {
	std::string s1=IzmijeniUPigLatin(s,v);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<s1;
	std::string s2=ObrniFraze(s,v);	
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<s2;
	}
	catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
		std::string s2=ObrniFraze(s,v);	
		std::cout<<"Recenica nakon obrtanja fraza: "<<s2;
	}

	return 0;
}