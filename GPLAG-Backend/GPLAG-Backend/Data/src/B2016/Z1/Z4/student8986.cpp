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
#include <stdexcept>

bool SamoSlova(std::string s) {
	for(unsigned int i=0; i<s.length(); i++) {
		if(s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))
			return false;
	}
	return true;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> spisak) {
	
	for(int i=0; i<spisak.size(); i++) {
		std::string fraza(spisak.at(i));

		for(int j=0; j<recenica.length(); j++) {
			int k(0);
			
			while(k<fraza.length() && j<recenica.length() && fraza.at(k)==recenica.at(j) ) {
					k++;
					j++;
			}
			
			if(k==fraza.length()) {
				int poc(j-fraza.length());
				int duzina(j-1);
				for(int pom=poc; pom<fraza.length()/2 + poc; pom++) {
					char znak;
					znak=recenica.at(pom);
					recenica.at(pom)=recenica.at(duzina);
					recenica.at(duzina)=znak;
					duzina--;
				}
				j--;
			}
			
		}
	}
	
	return recenica;
}

std::string PigLatin(std::string recenica) {
	
	
	int brojac(0);
	
	for(int i=0; i<recenica.length(); i++) {
	
		if(((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && (i+1==recenica.length() || recenica[i+1]<'A' || recenica[i+1]>'z' || (recenica[i+1]>'Z' && recenica[i+1]<'a') )) {
			i++;
			brojac++;
			if(i+1==recenica.length() && ((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))) {
				i++;
				brojac++;
			}
		
			recenica.insert(recenica.begin()+i, recenica[i-brojac]);
			recenica.erase(recenica.begin()+i-brojac);
			recenica.insert(recenica.begin()+i, 'y');	
			recenica.insert(recenica.begin()+i, 'a');
			i+=2;
			brojac=0;
		}
		else if(i<recenica.length() && ((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))) {
			brojac++;
			continue;
		}
		
	}
	
	return recenica;
	
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> spisak) {
	
	if(spisak.size()==0)
		return PigLatin(recenica);
	
	for(int i=0; i<spisak.size(); i++) {
		std::string fraza(spisak.at(i));
		if(fraza.length()==0)
			continue;
		if(SamoSlova(fraza)==false) 
			throw std::domain_error ("Nekorektan izbor rijeci");
				

		for(int j=0; j<recenica.length(); j++) {
			int k(0);
			
			while(k<fraza.length() && j<recenica.length() && fraza.at(k)==recenica.at(j) ) {
				k++;
				j++;
			}
			
			if(k==fraza.length() && (j==recenica.length() || j-k-1<0 || recenica[j-k-1]<'A' || recenica[j-k-1]>'z' || (recenica[j-k-1]>'Z' && recenica[j-k-1]<'a')) && (recenica[j]<'A' || recenica[j]>'z' || (recenica[j]>'Z' && recenica[j]<'a')) ) {
				int poc(j-fraza.length());
				recenica.insert(recenica.begin()+j, recenica[poc]);
				recenica.erase(recenica.begin()+poc);
				recenica.insert(recenica.begin()+j, 'y');
				recenica.insert(recenica.begin()+j, 'a');
				j--;
			}
			
		}
	}
	
	return recenica;
}




int main ()
{
	std::string recenica;
	std::vector<std::string> spisak;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	for(;;) {
		std::string s;
		std::getline(std::cin, s);
		if(s.length()==0)
			break;
		spisak.push_back(s);
	}
	
	try {
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica, spisak);
	}
	catch(std::domain_error IZUZETAK) {
		std::cout<<"Izuzetak: "<<IZUZETAK.what();
	}
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, spisak);
	
	return 0;
}