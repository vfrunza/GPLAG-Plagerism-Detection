/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

int PotencijalniKrivci (char **&ref, std::vector<std::string> imena) {
	int duz=imena.size();
	char **pok(new char*[duz]);
	for(int i=0; i<duz; i++) {
		pok[i]=new char[imena[i].size()+1];
		for(int j=0; j<imena[i].size(); j++){
			pok[i][j]=imena[i][j];
		}
		pok[i][imena[i].size()]='\0';
	}
	ref=pok;

	return duz;
}

int OdbaciOptuzbu(char **&ref, int n, std::string ime) {
	int br=n;
	int p=0;
	for(int i=0; i<n; i++) {
		if(ref[i]==nullptr) p++;}
		if(p>=10) {
			int k=0;
			char **pok(new char*[n-p]);
			for(int i=0; i<n; i++) {
				if(ref[i]!=nullptr){
		pok[k]=new char[10];////////////////////////////////
			k++;}
		}
		}
	for(int i=0; i<n; i++) {
		int j=0;
		while(*ref[i]==ime[j]) {
			ref[i]++;
			j++;
			if(j==ime.size()) break;
		}
		if(*ref[i]=='\n') {
			br--;
			delete ref[i];
			ref[i]=nullptr;
		}
	}
	if (br==n) {
		std::string s="Osoba sa imenom "+ime+" nije bila optuzena";
		throw std::domain_error(s);
	}
	return br;
}

int main ()
{
  char **nizPotencijalnih;
  std::vector<std::string> imena = {"Fudo", "Pero", "Meho", "Fata", "Bajro", "Luca", "Jovo"};
  int n = PotencijalniKrivci( nizPotencijalnih, imena);
  int m = OdbaciOptuzbu(nizPotencijalnih, n, "Fata");
  std::cout << m<< std::endl;
  return 0;
  
}