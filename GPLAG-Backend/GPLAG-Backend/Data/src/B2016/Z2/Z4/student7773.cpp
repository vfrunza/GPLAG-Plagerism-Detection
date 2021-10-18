/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <vector>

int PotencijalniKrivci(char **&pocetak, std::vector<std::string> imena) {
	int br_aloc(0);
	try {
		pocetak=(new char *[imena.size()]);
		for(int i(0);i<imena.size();i++) pocetak[i]=nullptr;
		try {
			for(int i(0);i<imena.size();i++) pocetak[i]=(new char [imena[i].size()+1]);
		}
		catch(...) {
			for(int i(0);i<imena.size();i++) delete [] p[i];
			delete [] p;
			throw;
		}
	}
	catch(...) {
		throw;
	}
	return br_aloc;
}

int OdbaciOptuzbu(char **&pocetak, char **&velicina, std::string ime) {
	
	for(int i(0);i<(**velicina);i++) {
		int j(0);
		std::string temp;
		while(p[i]!='\0') {
			if(p[i][j]==ime[j]) temp.push_back(ime[j]);
			j++;
		}
		if(temp==ime) {
			delete [] p[i];
			p[i]=nullptr;
		}
	}
	int br(0);
	for(int i(0);i<(**velicina);i++) {
		if(p[i]==nullptr) br++;
	}
	if(br>10) {
		char **novi=(new char *[(**velicina)-br]);
		for(int i(0);i<(**velicina)-br;i++) {
			
		}
	}
}

int DodajOptuzbu(char **&pocetak, char **&velicina, std::string ime) {
	
}

void IzlistajOptuzbu(char **pocetak, char **&velicina) {
	for(int i(0);i<(**velicina);i++) {
		if(p[i]!=nullptr) std::cout<<p[i]<<std::endl;
	}
}

int main ()
{
	return 0;
}