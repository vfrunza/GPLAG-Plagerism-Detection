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

std::string Izvrni(std::string s) {
	for(int i(0);i<s.size()/2;i++) {
		char c(s[i]);
		s[i]=s[s.size()-1-i];
		s[s.size()-1-i]=c;
	}
	return s;
}

std::string PigLatin(std::string s) {
	char c(s[0]);
	int i;
	for(i=0;i<(s.size()-1);i++) {
		s[i]=s[i+1];
	}
	s[i]=c;
	//s.resize(s.size()+1);
	s+="ay";
	return s;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze) {
	for(int i(0);i<fraze.size();i++) {
		std::string temp;
		for(int j(0);j<recenica.size();j++) {
			if(recenica[j]==fraze[i][0]) {
				// pronalazak stringa
				int k(j);
				std::string temp2;
				while(k<recenica.size() && ((k-j)<fraze[i].size()) && (recenica[k]==fraze[i][k-j])) {
					temp2.push_back(recenica[k]);
					k++;
				}
				if(temp2==fraze[i]) {
					temp+=(Izvrni(temp2));
					j=k-1;
				}
				else {
					temp+=temp2;
					j=k-1;
				}
			}
			else temp.push_back(recenica[j]);
		}
		recenica=temp;
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> fraze) {
	
	//bacanje izuzetka
		
	for(int i(0);i<fraze.size();i++) {
		for(int j(0);j<fraze[i].size();j++) {
			if((fraze[i][j]<'A' || (fraze[i][j]>'Z' && fraze[i][j]<'a') || fraze[i][j]>'z')) throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	if(fraze.size()==0) {
		std::string nova;
		for(int i(0);i<recenica.size();i++) {
			if((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')) {
				int j(i);
				std::string temp;
				while(j<recenica.size() && ((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z'))) {
					temp.push_back(recenica[j]);
					j++;
				}
				temp=PigLatin(temp);
				nova+=temp;
				if(recenica[j]<'A' || (recenica[j]>'Z' && recenica[j]<'a') || recenica[j]>'z') {
					nova.push_back(recenica[j]);
				}
				i=j;
			}
		}
		recenica=nova;
	}
	else {
		for(int i(0);i<fraze.size();i++) {
			std::string temp;
			for(int j(0);j<recenica.size();j++) {
				if(recenica[j]==fraze[i][0]) {
					int k(j);
					std::string temp2;
					while(k<recenica.size() && (k-j)<fraze[i].size() && recenica[k]==fraze[i][k-j]) {
						temp2.push_back(recenica[k]);
						k++;
					}
					if(temp2==fraze[i]) {
						temp+=PigLatin(temp2);
						j=k-1;
					}
					else {
						temp+=temp2;
						j=k-1;
					}
				}
				else temp.push_back(recenica[j]);
			}
			recenica=temp;
		}
	}
	return recenica;
}
int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	for(;;) {
		std::string temp;
		std::getline(std::cin,temp);
		if(temp.size()!=0) fraze.push_back(temp);
		else break;
	}
	try {
		std::string pig(IzmijeniUPigLatin(recenica,fraze));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<pig<<std::endl;
	}
	catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::string obrni(ObrniFraze(recenica,fraze));
	std::cout<<"Recenica nakon obrtanja fraza: "<<obrni<<std::endl;
	return 0;
}