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

std::string ObrniFraze(std::string recenica, std::vector<std::string> frazeObrni)
{
	for(int i=0; i<frazeObrni.size(); i++) {
		for(int j=0; j<recenica.length(); j++)
			if(recenica.substr(j,frazeObrni[i].length())==frazeObrni[i]) {
				int duzina=j+frazeObrni[i].length()-1;

				while(j<duzina) {
					char pomocni=recenica[j];
					recenica[j]=recenica[duzina];
					recenica[duzina]=pomocni;
					j++;
					duzina--;
				}
			}
	}
	return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> rijeciZaIzmjenu)
{
	int i=0;
	for(; i<rijeciZaIzmjenu.size(); i++) {
		for(int j=0; j<rijeciZaIzmjenu[i].length(); j++) {
			if(!((rijeciZaIzmjenu[i][j]>='A' && rijeciZaIzmjenu[i][j]<='Z') || (rijeciZaIzmjenu[i][j]>='a' && rijeciZaIzmjenu[i][j]<='z')))
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci\n");
		}
		for(int k=0; k<recenica.length(); k++) {
			if(recenica.substr(k,rijeciZaIzmjenu[i].length())==rijeciZaIzmjenu[i] && (k==0 || !((recenica[k-1]>='A' && recenica[k-1]<='Z') || (recenica[k-1]>='a' && recenica[k-1]<='z'))) && (k + rijeciZaIzmjenu[i].length()==recenica.length() || !((recenica[k+rijeciZaIzmjenu[i].length()]>='A' && recenica[k+rijeciZaIzmjenu[i].length()]<='Z') || (recenica[k+rijeciZaIzmjenu[i].length()]>='a' && recenica[k+rijeciZaIzmjenu[i].length()]<='z')))) {
				recenica.insert(recenica.begin()+k+rijeciZaIzmjenu[i].length(), recenica[k]);
				recenica.insert(recenica.begin()+k+1+rijeciZaIzmjenu[i].length(), 'a');
				recenica.insert(recenica.begin()+k+2+rijeciZaIzmjenu[i].length(),'y');
				recenica.erase(recenica.begin()+k);
			}
		}
	}

	if(i==0) {
		bool neslovo=true;
		for(int k=0; k<recenica.length(); k++) {
			if(!((recenica[k]>='A' && recenica[k]<='Z') || (recenica[k]>='a' && recenica[k]<='z'))) neslovo=true;
			else if(neslovo) {
				neslovo=false;
				int j=k;
				do {
					j++;
				} while(j<recenica.length() && ((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' &&  recenica[j]<='z')));

				recenica.insert(recenica.begin()+j, recenica[k]);
				recenica.insert(recenica.begin()+j+1,'a');
				recenica.insert(recenica.begin()+j+2,'y');
				recenica.erase(recenica.begin()+k);
				k=j;
			}
		}
	}
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);

	std::vector<std::string>frazeObrni;
	std::cout<<"Unesite fraze: ";

	for(;;) {
		std::string rijeciZaIzmjenu;
		std::getline(std::cin, rijeciZaIzmjenu);

		if(rijeciZaIzmjenu.length()==0) break;
		frazeObrni.push_back(rijeciZaIzmjenu);
	}
	try {
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,frazeObrni)<<"\n";
	} catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}

	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,frazeObrni);
	return 0;
}