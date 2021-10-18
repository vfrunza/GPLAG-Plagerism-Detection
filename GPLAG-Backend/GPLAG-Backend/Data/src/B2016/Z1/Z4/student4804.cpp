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
std::string ObrniFraze(std::string recenica,std::vector<std::string> vektor_stringova) {
	for(int i=0;i<vektor_stringova.size();i++) {
		for(int j=0;j<recenica.length();j++) {
			if(recenica[j]==vektor_stringova[i][0]) {
				int p(j);
				int r(0);
				while(recenica[p]==vektor_stringova[i][r] && p<recenica.length() && r!=vektor_stringova[i].length()) {
					p++;
					r++;
				}
				if(r==vektor_stringova[i].length()) {
					p--;
					while(j<p) {
						auto temp(recenica[j]);
						recenica[j]=recenica[p];
						recenica[p]=temp;
						j++;
						p--;
					}
				}
			}
		}
	}
	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string> vektor_stringova) {
	std::string novi;
	for(int j=0;j<recenica.length();j++) {
		for(int i=0;i<vektor_stringova.size();i++) {
			if(recenica[j]==vektor_stringova[i][0] && (j==0 || !((recenica[j-1]>='a' && recenica[j-1]<='z') || (recenica[j-1]>='A' && recenica[j-1]<='Z')))) {
				int p(j);
				int r(0);
				while(recenica[p]==vektor_stringova[i][r] && p<recenica.length()) {
					if(!((vektor_stringova[i][r]>='A' && vektor_stringova[i][r]<='Z') || (vektor_stringova[i][r]>='a' && vektor_stringova[i][r]<='z'))) throw std::domain_error ("Nekorektan izbor rijeci");
					p++;
					r++;
				}
				if(r==vektor_stringova[i].length() && (p==recenica.length() || (!((recenica[p]>='a' && recenica[p]<='z') || (recenica[p]>='A' && recenica[p]<='Z'))))) {
					auto prvo(recenica[j]);
					j++;
					while(j<p) {
						novi.push_back(recenica[j]);
						j++;
					}
					novi.push_back(prvo);
					novi.push_back('a');
					novi.push_back('y');
				}
			}
		}
		novi.push_back(recenica[j]);
			
	}
	return novi;
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> vektor_stringova;
	for(int i=0;;i++) {
		std::string rijec;
		std::getline(std::cin,rijec);
		if(rijec.length()==0) break;
		vektor_stringova.push_back(rijec);
	}
	try{
		std::string pig(IzmijeniUPigLatin(recenica,vektor_stringova));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<pig;
	}
	catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::string nova(ObrniFraze(recenica,vektor_stringova));
	std::cout<<"\nRecenica nakon obrtanja fraza: "<<nova<<std::endl;
	return 0;
}