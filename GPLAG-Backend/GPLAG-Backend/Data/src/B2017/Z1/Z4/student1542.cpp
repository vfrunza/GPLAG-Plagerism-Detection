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

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> v)
{
	int pocetak(0),brojac(0),nvl(0),br(0);
	std::string palind;
	bool pronadjen(0);
	if(v.size()==0)return recenica;
	std::vector<int>indeksi;
	for(int i=0; i<v.size(); i++) {
		brojac=0;
		for(int j=0; j<recenica.size(); j++) {
			for(int j=0; j<v.at(i).size(); j++) {
				while(brojac<recenica.size()) {
					if(brojac<recenica.size() && v.at(i).at(j)!=recenica.at(brojac) && j<v.at(i).size())
						brojac++;
					while(brojac<recenica.size()-1 && v.at(i).at(j)==recenica.at(brojac) && j<v.at(i).size()) {
						brojac++;
						j++;
						if( brojac+1<=recenica.size() && !(recenica.at(brojac+1)>='A' ||  recenica.at(brojac+1)<='Z' ||  recenica.at(brojac+1)>='a' || recenica.at(brojac+1)<='z' || brojac==recenica.size()-1) && v.at(i).at(j)==recenica.at(brojac) && j<v.at(i).size()) {
							pronadjen=1;
							nvl=v.at(i).size();
							recenica.resize(recenica.size()+nvl);
							for(int k=recenica.size()-1; k>brojac; k--){
								recenica.at(k)=recenica.at(k-nvl);
							}
							br=brojac+1;
							while(br<brojac+1+nvl) {
								for(int c=nvl-1; c>=0; c--) {
									recenica.at(br)=v.at(i).at(c);
									br++;
								}
							}
						}
						if(pronadjen) {
							j=0;
							brojac+=nvl;
							pronadjen=0;
							break;
						}
					}
					brojac++;
					j=0;
				}
			}
			brojac=0;
		}
	}
	palind=recenica;
	std::cout<<recenica;
	return palind;

}

int main ()
{
	std::string s1,p;
	std::vector<std::string>v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s1);
	std::cout<<"Unesite fraze: ";
	while(std::getline(std::cin,s1),int(s1.size()!=0))v.push_back(s1);
	for(int i=0;i<v.size();i++) std::cout<<v.at(i);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	p=NapraviPalindrom(s1,v);
	std::cout<<p<<std::endl;
	return 0;
}