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
std::string ObrniFraze(std::string recenica,std::vector<std::string>popis)
{

	//Bacanje izuzetka

	for(int i=0; i<popis.size(); i++) {
		std::string s=popis[i];
		for(int j=0; j<s.length(); j++) {
			if(s[j]!=' ') {
				if(!((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z')))
					throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
			}
		}
	}

	int cuvaj;
	int t(0);
	while( t<popis.size()) {
		int r(0);
		std::string p=popis[t];
		while(r<recenica.length()) {

			if(recenica[r]!=' ') {

				bool pronadjena(false);
				int broj(0);
				int k(0);
				if(recenica[r]==p[k]) {
					cuvaj=r;
					broj++;
					r++;
					k++;
					while(p[k]==recenica[r] && k<p.size()) {
						r++;
						k++;
						broj++;
					}
					if(broj==p.length() ) {
						pronadjena=true;
					}



					if(pronadjena==true) {
						for(int l=p.size()-1; l>=0; l--) {
							recenica[cuvaj]=p[l];
							cuvaj++;
						}

					}

				}

			}
			r++;
		}
		t++;
	}

	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string>popis)
{

	for(int i=0; i<popis.size(); i++) {
		std::string s=popis[i];
		for(int j=0; j<s.length(); j++) {
			if(s[j]==' ')
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		}
	}



	for(int i=0; i<popis.size(); i++) {
		std::string s=popis[i];
		for(int j=0; j<s.length(); j++) {
			if(s[j]!=' ') {
				if(!((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z')))
					throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
			}
		}
	}




	//Prazan string
	if(popis.size()==0) {
		int r(0);
		while(r<recenica.length()) {
			int duzina;
			if(((recenica[r]>='a' && recenica[r]<='z') || (recenica[r]>='A' && recenica[r]<='Z')) && ((r==0  || ((!(recenica[r-1]>='A' && recenica[r-1]<='Z') && (!(recenica[r-1]>='a' && recenica[r-1]<='z'))))))) {
				int cuvaj=r;
				duzina=0;
				int l(r);
				while((recenica[r]>='A' && recenica[r]<='Z') || (recenica[r]>='a' && recenica[r]<='z')) {
					
					duzina++;
					l++;
					r++;
				}
				duzina=duzina-1;
				int n=recenica.size()-cuvaj-duzina;
				int f=cuvaj+duzina+1;
				recenica=recenica.substr(0,cuvaj)+recenica.substr(cuvaj+1,duzina)+char(recenica[cuvaj])+"ay"+recenica.substr(f,n);
			}
			r++;
		}
		return recenica;
	}



	int i(0);
	int broj;
	int cuvaj;
	bool pronadjena=false;
	while(i<popis.size()) {
		std::string p=popis[i];
		int r(0);
		while(r<recenica.length()) {

			if(recenica[r]!=' ') {
				broj=0;
				int k(0);
				if(recenica[r]==p[k] && (r==0 || (!((recenica[r-1]>='A' && recenica[r-1]<='Z') || (recenica[r-1]>='a'&& recenica[r-1]<='z'))))) {
					cuvaj=r;
					broj++;
					r++;
					k++;

					while(recenica[r]==p[k] && k<p.size()) {
						r++;
						k++;
						broj++;

					}

					if(broj==p.length() && (r==recenica.size() || (!((recenica[r]>='A' && recenica[r]<='Z') || (recenica[r]>='a' && recenica[r]<='z')))) ) {
						pronadjena=true;

					}

					if(pronadjena) {
						int l=p.size()-1;
						int n=recenica.size()-cuvaj-l;
						int f=cuvaj+l+1;
						recenica=recenica.substr(0,cuvaj)+p.substr(1,l)+p[0]+"ay"+recenica.substr(f,n);
						pronadjena=false;

					}
				}

			}


			r++;
		}
		i++;
	}

	return recenica;
}


int main()
{
	std::string recenica;
	std::string fraza;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string>popis;
	std::cout<<"Unesite fraze: ";

	for(;;) {

		std::getline(std::cin,fraza);
		popis.push_back(fraza);
		if(std::cin.peek()=='\n') {
			break;

		}

		popis.push_back(fraza);


	}

	try {

		std::string pig;
		pig=IzmijeniUPigLatin(recenica,popis);
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<pig;
	}

	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	try {
		std::cout<<std::endl;
			std::string nova=ObrniFraze(recenica,popis);
		std::cout<<"Recenica nakon obrtanja fraza: ";
		std::cout<<nova;
		std::cout<<std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	return 0;

}