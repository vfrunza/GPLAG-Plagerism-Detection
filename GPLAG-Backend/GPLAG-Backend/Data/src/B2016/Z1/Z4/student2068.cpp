/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	.
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

typedef std::vector<std::string> StringVek;

std::string ProvjeriIObrni(std::string s, std::string rijec) {
	if(rijec.length()==0 || s.length()==0) return s;
	for(int i=0; ; ) {
		while(i<s.length() && s[i]!=rijec[0]) i++;
		if(i==s.length()) break; 
		
		int temp(i);
		while(i<s.length() && (i-temp)<rijec.length() && s[i]==rijec[i-temp]) i++;
		if(i-temp==rijec.length()) {
			i=temp;
			while(i-temp<rijec.length()) {
				s[i]=rijec[rijec.length()+temp-i-1]; 
				i++;
			}
			if(temp+rijec.length()<s.length()) i=temp+rijec.length();
			else break;
		}
		else if(temp+1<s.length()) {
			i=temp+1;
		//	while(i<s.length() && !(s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))) i++;
		}
		else break;
	}
	return s;
}

std::string ObrniFraze(std::string s, StringVek v) {
	for(int i=0; i<v.size(); i++) {
		s=ProvjeriIObrni(s, v[i]);
	}
	return s;
}

std::string PromijeniSvaku(std::string s) {
	if(s.length()==0) return s;
	for(int i=0; ; ) {
		char z;
		while(i<s.length() && (s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))) i++;
		if(i==s.length()) break;
		z=s[i]; s.erase(s.begin()+i);
		while(i<s.length() && !(s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))) i++;
		s.insert(s.begin()+i, z);
		s.insert(s.begin()+i+1, 'a'); s.insert(s.begin()+i+2, 'y');
		i+=3;
	}
	return s;
}

std::string ProvjeriIPromijeni(std::string s, std::string rijec) {
	if(s.length()==0 || rijec.length()==0) return s;
	int temp;
	for(int i=0; ; ) {
		char z;
		while(i<s.length() && (s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))) i++;
		if(i==s.length()) break;
		temp=i;
		for(; i<s.length() && i-temp<rijec.length() && s[i]==rijec[i-temp]; i++);
		if(i-temp==rijec.length() && (i==s.length() || s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))) {
			
			z=s[temp]; s.erase(s.begin()+temp);
			s.insert(s.begin()+i-1, z);
			s.insert(s.begin()+i, 'a'); s.insert(s.begin()+i+1, 'y');
			i+=3;
		}
		else if(temp+1<s.length()) {
			i=temp+1;
			while(i<s.length() && !(s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))) i++;
		}
		else break;
	}
	return s;
}

bool daLiJeValidno(StringVek v) {
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v[i].size(); j++) if(v[i][j]<'A' || v[i][j]>'z' || (v[i][j]>'Z' && v[i][j]<'a')) return false;
	}
	return true;
}

std::string IzmijeniUPigLatin(std::string s, StringVek v) {
	if(!daLiJeValidno(v)) throw std::domain_error("Nekorektan izbor rijeci");
	if(v.size()==0) {
		s=PromijeniSvaku(s);
	}
	else for(int i=0; i<v.size(); i++) {
		s=ProvjeriIPromijeni(s, v[i]);
	}
	return s;
}


int main () {
	std::string s; StringVek v;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	for(;;) {
		std::string str;
		std::getline(std::cin, str);
		if(str.size()) v.push_back(str);
		else break;
	}
	try{
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s, v) << std::endl;
	}
	catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, v);
	return 0;
}